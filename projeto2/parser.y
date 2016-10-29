%{
#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <string>
#include <cstdio>
#include <fstream>

extern int yylex();
extern void yyerror(const char* s, ...);
%}


// Estrutura complementar ao Union
%code requires {
    #include "arvoreSintatica.h"
}


// Declaração de Variáveis Globais
%code {
    AST::Bloco *arvoreSintatica;
    AST::Tipo ultimoTipo;
    AST::TabelaDeSimbolos *escopoPrincipal = new AST::TabelaDeSimbolos();
}


%define parse.trace

// yylval == %union
// A union informa os diferentes modos de armazenar dados, utilizado para definir os tipos de Símbolos Terminais e Não-Terminais
%union {
    const char* valor;
    AST::Nodo *nodo;
    AST::Variavel *variavel;
    //AST::Inteiro *inteiro;
    //AST::Real *real;
    //AST::Boolean *boolean;
    AST::Declaracao *declaracao;
    AST::Definicao *definicao;
    AST::DefinicaoDeArranjo *definicaoDeArranjo;
    AST::OperacaoUnaria *opUnaria;
    AST::OperacaoBinaria *opBinaria;
    AST::DeclaracaoDeHash *declaracao_hash;
    AST::Condicao *condicao;
    AST::Laco *laco;
    AST::Funcao *funcao;
    AST::Parametro *parametro;
    AST::Bloco *bloco;
    AST::Tipo tipo;
    int num_ref;
}


// %token
// Símbolos Terminais (tokens)
%token <valor> T_FLOAT T_INT T_BOOL T_VAR
%token <tipo> T_TYPE_INT T_TYPE_FLOAT T_TYPE_BOOL
%token T_NL T_OPEN T_CLOSE  T_OPEN_KEY T_CLOSE_KEY T_EQUAL T_COMMA T_SEMICOLON T_COLON T_PLUS T_MINUS T_TIMES T_DIV T_NOT T_AND T_OR 
%token T_EQUAL2 T_DIF T_HIGHER T_HIGH T_LOWER T_LOW
%token T_CAST_INT T_CAST_FLOAT T_CAST_BOOL T_ADDR
%token T_IF T_THEN T_ELSE T_FOR T_FUN T_RET T_ATRIB_ASK T_DO T_WHILE
%token <num_ref> T_REF

// %type
// Define o tipo de Símbolos Não-Terminais
%type <nodo> expressao linha primitiva var retorno arranjo var_arranjo arranjo_duplo hash
%type <variavel> dec_arranjo
%type <declaracao> declaracao
%type <definicao> variaveis variavel def_arranjo  hashes def_hash 
%type <opBinaria> atribuicao atrib_null
%type <condicao> condicao
%type <laco> for_laco do_while_laco while_laco
%type <funcao> dec_funcao def_funcao
%type <parametro> parametros parametro argumentos argumento param_null arg_null
%type <bloco> programa linhas linhas_null linhas_funcao senao
%type <tipo> tipo
%type <nodo> chamada
%type <num_ref> referencia
%type <declaracao_hash> dec_hashes

// %left, %right, %nonassoc
// Precedência de operadores matemáticos, os últimos listados possuem maior procedência.
%left T_AND T_OR T_ATRIB_ASK
%left T_EQUAL2 T_DIF T_HIGHER T_HIGH T_LOWER T_LOW
%left T_PLUS T_MINUS
%left T_DIV
%left T_TIMES
%left T_OPEN T_CLOSE
%left T_NOT UMINUS // UMINUS: http://www.gnu.org/software/bison/manual/html_node/Contextual-Precedence.html
%left T_CAST INT T_CAST_FLOAT T_CAST_BOOL T_REF T_ADDR T_COLON


// %start
// Regra Inicial da Gramática
%start programa
%%

// $$ = $1 por padrão
programa: 
          linhas { std::cerr<<"";
                   arvoreSintatica = $1;
                   $$->analisar(escopoPrincipal, 0);
                   $$->imprimir(0, true);
		   std::cout <<"\n";
                  }
        ;

linhas: 
        linha         { $$ = new AST::Bloco( AST::Tipo::bloco );  $$->novaLinha($1); }
      | linhas linha  { $$ = $1;                                  $1->novaLinha($2); }
      ;

linha: 
       atribuicao T_NL      { $$ = $1;   }
     | declaracao T_NL      { $$ = $1;   }
     | dec_hashes           { $$ = $1;   }
     | dec_funcao T_NL      { $$ = $1;   }
     | def_funcao T_NL      { $$ = $1;   }
     | condicao T_NL        { $$ = $1;   }
     | for_laco T_NL        { $$ = $1;   }
     | do_while_laco T_NL   { $$ = $1;   }
     | while_laco T_NL      { $$ = $1;   }
     | chamada T_NL         { $$ = $1;   }
     | T_NL                 { $$ = NULL; }
     ;

atribuicao:
            var_arranjo T_EQUAL expressao  { 
                if(((AST::Variavel*)$1)->ponteiros > 0) ((AST::Variavel*)$1)->ponteiroEsqAtribuicao = true;  $$ = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::atribuicao, $1, $3 ); }
          ;

var_arranjo:
             var            { $$ = $1; }
           | chamada 	    { $$ = $1; }
           ;

declaracao:
            tipo variaveis  { $$ = new AST::Declaracao( AST::Tipo::declaracao , $1, $2 ); }
          ;

variaveis: 
           variavel                        { $$ = $1;                          }
         | variaveis T_COMMA variavel      { $$ = $1;  $1->ajustarProxima($3); } 
         | def_arranjo                     { $$ = $1;                          }
         | variaveis T_COMMA def_arranjo   { $$ = $1;  $1->ajustarProxima($3); }
         ;

variavel:
          atribuicao  { $$ = new AST::Definicao( AST::Tipo::definicao   , ((AST::Variavel*)$1->esquerda) , $1->direita , NULL ); }
        | var         { $$ = new AST::Definicao( AST::Tipo::definicao   , ((AST::Variavel*)$1)           , NULL        , NULL ); }
        ;

def_arranjo:
             dec_arranjo { $$ = new AST::DefinicaoDeArranjo( AST::Tipo::definicao_arranjo, $1, NULL , NULL ); }
           ;

dec_arranjo:
             T_VAR T_OPEN primitiva T_COMMA primitiva T_CLOSE
              { $$ = new AST::ArranjoDuplo( AST::Tipo::arranjo_duplo, AST::Tipo::nulo ,$1, $3, $5, 0 ); }
           | referencia T_VAR T_OPEN primitiva T_COMMA primitiva T_CLOSE  
               { $$ = new AST::ArranjoDuplo( AST::Tipo::arranjo_duplo, AST::Tipo::nulo ,$2, $4, $6, $1 ); }
           |  T_VAR T_OPEN primitiva T_CLOSE  
               { $$ = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo ,$1, $3,0 ); }
           | referencia T_VAR T_OPEN primitiva T_CLOSE  
               { $$ = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo ,$2, $4, $1 ); }           
           ;

arranjo:
         T_VAR T_OPEN expressao T_CLOSE  
           {  $$ = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo, $1, $3, 0  );}
       | referencia T_VAR T_OPEN expressao T_CLOSE
           {  $$ = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo, $2, $4, $1 ); }
       ;

arranjo_duplo:
               T_VAR T_OPEN expressao T_COMMA expressao T_CLOSE
                 {  $$ = new AST::ArranjoDuplo( AST::Tipo::arranjo_duplo, AST::Tipo::nulo , $1, $3, $5, 0 ); }
             | referencia T_VAR T_OPEN expressao T_COMMA expressao T_CLOSE
                 {  $$ = new AST::ArranjoDuplo( AST::Tipo::arranjo_duplo, AST::Tipo::nulo , $2, $4, $6, $1 ); }
             ;

chamada:
          T_VAR T_OPEN arg_null T_CLOSE 
          {  $$ = new AST::Chamada ( AST::Tipo::nulo , AST::Tipo::nulo , $1 , $3 , NULL);}
        | referencia T_VAR T_OPEN arg_null T_CLOSE 
          {  $$ = new AST::Chamada ( AST::Tipo::nulo , AST::Tipo::nulo , $2 , $4 , NULL);}
        ;

arg_null :
           argumentos  { $$ = $1;   }
         |             { $$ = NULL; }
         ;
 
argumentos:
            argumento                     { $$ = $1;                   }
          | argumentos T_COMMA argumento  { $$ = $1; $$->proximo = $3; }
          ;

argumento:
           expressao  { $$ = new AST::Parametro( AST::Tipo::parametro, AST::Tipo::nulo, AST::Tipo::nulo, $1, NULL );  }
         ;

dec_hashes:
            tipo T_COLON tipo hashes  { $$ = new AST::DeclaracaoDeHash( AST::Tipo::declaracao_hash, $1, $3, $4 ); }
          ;

hashes: 
        def_hash                 { $$ = $1;                          }
      | hashes T_COMMA def_hash  { $$ = $1;  $1->ajustarProxima($3); } 
      ;

def_hash:
          hash { $$ = new AST::DefinicaoDeHash( AST::Tipo::definicao_hash, ((AST::Variavel*)$1), NULL, NULL); }
        ;

condicao :
           T_IF expressao T_NL T_THEN T_OPEN_KEY T_NL linhas_null T_CLOSE_KEY senao
           { $$ = new AST::Condicao( AST::Tipo::condicao , $2, $7, $9 ); }
         ;

senao:
       T_ELSE T_OPEN_KEY T_NL linhas_null T_CLOSE_KEY  { $$ = $4;   }
     |                                                 { $$ = NULL; }
     ;

for_laco:
      T_FOR atrib_null T_COMMA expressao T_COMMA atrib_null T_OPEN_KEY T_NL linhas_null T_CLOSE_KEY
      { $$ = new AST::Laco( AST::Tipo::for_laco , $2 , $4 , $6 , $9 ); }
    ;

linhas_null:
             linhas  { $$ = $1;   }
           |         { $$ = NULL; }
           ;

do_while_laco: T_DO T_OPEN_KEY T_NL linhas T_CLOSE_KEY T_WHILE expressao
        { $$ = new AST::Laco( AST::Tipo::do_while_laco , NULL , $7 , NULL , $4 ); }
       ;

while_laco: T_WHILE expressao T_OPEN_KEY T_NL linhas T_CLOSE_KEY
           { $$ = new AST::Laco( AST::Tipo::while_laco , NULL , $2 , NULL , $5 ); }
          ;

atrib_null:
            atribuicao { $$ = $1;   }
          |            { $$ = NULL; }
          ;

dec_funcao:
            tipo T_FUN T_VAR T_OPEN param_null T_CLOSE
              { $$ = new AST::Funcao( AST::Tipo::funcao_dec, $1 , $3 , $5); }
          | tipo T_OPEN T_CLOSE T_FUN T_VAR T_OPEN param_null T_CLOSE
              { $$ = new AST::Funcao( AST::Tipo::funcao_dec, escopoPrincipal->tipoDeArranjo($1) , $5 , $7); }   
          | tipo T_OPEN T_CLOSE T_OPEN T_CLOSE T_FUN T_VAR T_OPEN param_null T_CLOSE
              { $$ = new AST::Funcao( AST::Tipo::funcao_dec, escopoPrincipal->tipoDeArranjoDuplo($1) , $7 , $9); }    
          | tipo T_COLON tipo T_FUN T_VAR T_OPEN param_null T_CLOSE
              { $$ = new AST::Funcao( AST::Tipo::funcao_dec, escopoPrincipal->tipoDeHash($1,$3) , $5 , $7); }
          ;

def_funcao:
            tipo T_FUN T_VAR T_OPEN param_null T_CLOSE T_OPEN_KEY T_NL linhas_funcao T_RET retorno T_NL T_CLOSE_KEY  
              {  $9->novaLinha($11); 
                 $$ = new AST::DefinicaoDeFuncao( AST::Tipo::funcao_def, $1 , $3 , $5 , $9, $11); }
          | tipo T_OPEN T_CLOSE T_FUN T_VAR T_OPEN param_null T_CLOSE T_OPEN_KEY T_NL linhas_funcao T_RET retorno T_NL T_CLOSE_KEY  
              {  $11->novaLinha($13);
                 $$ = new AST::DefinicaoDeFuncao( AST::Tipo::funcao_def, escopoPrincipal->tipoDeArranjo($1) , $5 , $7 , $11, $13 ); }         
          | tipo T_OPEN T_CLOSE T_OPEN T_CLOSE T_FUN T_VAR T_OPEN param_null T_CLOSE T_OPEN_KEY T_NL linhas_funcao T_RET retorno T_NL T_CLOSE_KEY  
              {  $13->novaLinha($15);
                 $$ = new AST::DefinicaoDeFuncao( AST::Tipo::funcao_def, escopoPrincipal->tipoDeArranjoDuplo($1) , $7 , $9 , $13, $15 ); }         
          | tipo T_COLON tipo T_FUN T_VAR T_OPEN param_null T_CLOSE T_OPEN_KEY T_NL linhas_funcao T_RET retorno T_NL T_CLOSE_KEY  
              {  $11->novaLinha($13);
                 $$ = new AST::DefinicaoDeFuncao( AST::Tipo::funcao_def, escopoPrincipal->tipoDeHash($1,$3) , $5 , $7 , $11, $13 );  }               
          ;

linhas_funcao:
             linhas  { $$ = $1;                                 }
           |         { $$ = new AST::Bloco( AST::Tipo::bloco ); }
           ;

param_null: 
            parametros  { $$ = $1;   }
          |             { $$ = NULL; }
          ;

parametros:
            parametro                      { $$ = $1; }
          | parametros T_COMMA parametros  { $$ = $1; $$->proximo = $3; }
          ;

parametro:
           tipo var                { $$ = new AST::Parametro( AST::Tipo::parametro, $1, AST::Tipo::nulo, $2, NULL );  }
	 | tipo arranjo            { $$ = new AST::Parametro( AST::Tipo::parametro, $1, AST::Tipo::nulo, $2, NULL );  }
         | tipo arranjo_duplo      { $$ = new AST::Parametro( AST::Tipo::parametro, $1, AST::Tipo::nulo, $2, NULL );  }
         | tipo T_COLON tipo hash  { $$ = new AST::Parametro( AST::Tipo::parametro, $3, $1             , $4, NULL );  }
         ;

retorno:
         expressao  { $$ = new AST::Retorno( AST::Tipo::retorno, $1); }
       ;

expressao:         
                                  primitiva              { $$ = $1; }
         |                        chamada                { $$ = $1; }
         |           T_MINUS      expressao %prec UMINUS { $$ = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::negacao         , $2 ); }
         |           T_NOT        expressao              { $$ = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::inversao        , $2 ); }
         |           T_CAST_INT   expressao              { $$ = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_int   , $2 ); }
         |           T_CAST_FLOAT expressao              { $$ = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_float , $2 ); }
         |           T_CAST_BOOL  expressao              { $$ = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_bool  , $2 ); }
         | T_OPEN    expressao    T_CLOSE                { $$ = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::parenteses      , $2 ); }
         |           T_REF        expressao              { $$ = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::referencia      , $2 ); }
         |           T_ADDR       expressao              { $$ = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::endereco        , $2 ); }
         | expressao T_PLUS       expressao              { $$ = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::adicao         , $1,  $3 ); }
         | expressao T_MINUS      expressao              { $$ = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::subtracao      , $1,  $3 ); }
         | expressao T_TIMES      expressao              { $$ = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::multiplicacao  , $1,  $3 ); }
         | expressao T_DIV        expressao              { $$ = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::divisao        , $1,  $3 ); }
         | expressao T_AND        expressao              { $$ = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::e              , $1,  $3 ); }
         | expressao T_OR         expressao              { $$ = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::ou             , $1,  $3 ); }
         | expressao T_EQUAL2     expressao              { $$ = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::igual          , $1,  $3 ); }
         | expressao T_DIF        expressao              { $$ = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::diferente      , $1,  $3 ); }
         | expressao T_HIGHER     expressao              { $$ = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::maior          , $1 , $3 ); }
         | expressao T_HIGH       expressao              { $$ = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::maior_igual    , $1,  $3 ); }
         | expressao T_LOWER      expressao              { $$ = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::menor          , $1,  $3 ); }
         | expressao T_LOW        expressao              { $$ = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::menor_igual    , $1,  $3 ); }
         | T_OPEN expressao T_ATRIB_ASK expressao T_COLON expressao T_CLOSE { $$ = new AST::OperacaoTernaria(AST::Tipo::opTernaria, new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::condicao_atribuicao, $2 ),  new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::atribuicao_condicional, $4, $6)); }
         ; 

tipo:
       T_TYPE_INT    { $$ = AST::Tipo::inteiro;  ultimoTipo = $1; }
     | T_TYPE_FLOAT  { $$ = AST::Tipo::real;     ultimoTipo = $1; }
     | T_TYPE_BOOL   { $$ = AST::Tipo::boolean;  ultimoTipo = $1; }
     ;

primitiva:
           var
         | T_BOOL   { $$ = new AST::Boolean  ( $1 ); }
         | T_INT    { $$ = new AST::Inteiro  ( $1 ); }
         | T_FLOAT  { $$ = new AST::Real     ( $1 ); }
         ;

var:
     T_VAR            { $$ = new AST::Variavel( AST::Tipo::variavel, AST::Tipo::nulo , $1, 0 ); }
   | referencia T_VAR { $$ = new AST::Variavel( AST::Tipo::variavel, AST::Tipo::nulo, $2, $1 ); }
   ;

hash:
      T_VAR            { $$ = new AST::Hash( AST::Tipo::hash, AST::Tipo::nulo , $1, 0 ); }
    | referencia T_VAR { $$ = new AST::Hash( AST::Tipo::hash, AST::Tipo::nulo, $2, $1 ); }
    ;

referencia: 
	   T_REF | referencia T_REF {$$ = $$ + 1;}

;
%%
