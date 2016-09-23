%{
#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <string>
#include <cstdio>
#include "arvoreSintatica.h"
extern int yylex();
extern void yyerror(const char* s, ...);
%}

// Estrutura complementar ao Union
%code requires {
    #include "arvoreSintatica.h"
    #include "arvoreSintatica.h"
}

// Declaração de Variáveis Globais
%code {
    AST::Bloco *arvoreSintatica;
    AST::Tipo ultimoTipo;
    std::map<std::string, AST::Variavel*> tabela_simbolos;
}

%define parse.trace

// yylval == %union
// A union informa os diferentes modos de armazenar dados, utilizado para definir os tipos de Símbolos Terminais e Não-Terminais
%union {
    const char* valor;
    AST::NodoBase *nodobase;
    AST::Variavel *variavel;
    //AST::Inteiro *inteiro;
    //AST::Real *real;
    //AST::Boolean *boolean;
    AST::Declaracao *declaracao;
    AST::Definicao *definicao;
    AST::OperacaoUnaria *opUnaria;
    AST::OperacaoBinaria *opBinaria;
    AST::Condicao *condicao;
    AST::Laco *laco;
    AST::Bloco *bloco;
    AST::Tipo tipo;
}

// %token
// Símbolos Terminais (tokens)
%token <valor> T_FLOAT T_INT T_BOOL T_VAR
//%token <nodo> T_PLUS T_MINUS T_TIMES T_DIV T_NOT T_AND T_OR T_DIF T_HIGHER T_HIGH T_LOWER T_LOW
%token <tipo> T_TYPE_INT T_TYPE_FLOAT T_TYPE_BOOL
%token T_NL T_OPEN T_CLOSE  T_OPEN_KEY T_CLOSE_KEY T_EQUAL T_COMMA T_PLUS T_MINUS T_TIMES T_DIV T_NOT T_AND T_OR 
%token T_EQUAL2 T_DIF T_HIGHER T_HIGH T_LOWER T_LOW
%token T_CAST_INT T_CAST_FLOAT T_CAST_BOOL
%token T_IF T_THEN T_ELSE T_FOR

// %type
// Define o tipo de Símbolos Não-Terminais
%type <nodobase> expressao linha primitiva var
//%type <variavel> 
%type <declaracao> declaracao
%type <definicao> variaveis variavel
%type <opBinaria> atribuicao
%type <condicao> condicao
%type <laco> laco
%type <bloco> programa linhas
%type <tipo> tipo

// %left, %right, %nonassoc
// Precedência de operadores matemáticos, os últimos listados possuem maior procedência.
%left T_PLUS T_MINUS
%left T_TIMES
%left T_DIV 
%left T_OPEN T_CLOSE
%left T_CAST INT T_CAST_FLOAT T_CAST_BOOL
/* 
   !!! : Reconhercer Operações Unárias antes das Operações Binárias divisão/multiplicação :
       -> Negação antes de Divisão : v1.0/3.in
       -> Negação antes de Ou      : v2.0/1.in
       -> Negação antes de E       : v2.0/2.in
*/   


// %start
// Regra Inicial da Gramática
%start programa
%%

// $$ = $1 por padrão
programa: linhas { arvoreSintatica = $1; 
                   //$$->verificarTipo(AST::Tipo::nulo, AST::Tipo::nulo); 
                   $$->imprimir();}
        ;

linhas: 
        linha         {  $$ = new AST::Bloco();  if($1 != NULL) $$->novaLinha($1); }
      | linhas linha  {  $$ = $1;                if($2 != NULL) $1->novaLinha($2); }
      ;

linha: 
       atribuicao T_NL  {  
                           $$ = $1;
                           $1->verificarSimbolos(tabela_simbolos); //Verifica se variável a esq e dir na atribuição já foi declarada  
                           $1->verificarTipo(tabela_simbolos[std::string(((AST::Variavel*)$1->esquerda)->id)]->tipo,($1->direita)->verificarTipo(AST::Tipo::nulo, AST::Tipo::nulo));//Verifica se o tipo da variável e da atribuição são equivalentes
                           //$$->imprimir(); 
                         }
     | declaracao T_NL  {  $$ = $1;  
                           $1->acrescentarSimbolos(tabela_simbolos, ultimoTipo);  
                           //$$->imprimir();  
                         }
     | condicao T_NL    {  $$ = $1;
                           //$$->imprimir();  
                         }
     | laco T_NL        {  $$ = $1;
                           //$$->imprimir(); 
                         }
     | T_NL             {  $$ = NULL;  }
     ;

laco :
       T_FOR T_COMMA expressao T_COMMA T_OPEN_KEY T_NL 
       T_CLOSE_KEY    { $$ = new AST::Laco(NULL,$3,NULL,NULL); }

     | T_FOR T_COMMA expressao T_COMMA atribuicao T_OPEN_KEY T_NL 
       T_CLOSE_KEY    { $$ = new AST::Laco(NULL,$3,$5,NULL); }

     | T_FOR atribuicao T_COMMA expressao T_COMMA T_OPEN_KEY T_NL 
       T_CLOSE_KEY    { $$ = new AST::Laco($2,$4,NULL,NULL); }

     | T_FOR atribuicao T_COMMA expressao T_COMMA atribuicao T_OPEN_KEY T_NL 
       T_CLOSE_KEY    { $$ = new AST::Laco($2,$4,$6,NULL); }
  
     | T_FOR T_COMMA expressao T_COMMA T_OPEN_KEY T_NL 
       linhas
       T_CLOSE_KEY    { $$ = new AST::Laco(NULL,$3,NULL,$7); }

     | T_FOR T_COMMA expressao T_COMMA atribuicao T_OPEN_KEY T_NL 
       linhas
       T_CLOSE_KEY    { $$ = new AST::Laco($3,$5,NULL,$8); }

     | T_FOR atribuicao T_COMMA expressao T_COMMA T_OPEN_KEY T_NL 
       linhas
       T_CLOSE_KEY    { $$ = new AST::Laco($2,$4,NULL,$8); }

     | T_FOR atribuicao T_COMMA expressao T_COMMA atribuicao T_OPEN_KEY T_NL 
       linhas 
       T_CLOSE_KEY    { $$ = new AST::Laco($2,$4,$9,NULL); }
     ;

condicao:         
// if ... then { }
          T_IF expressao T_NL T_THEN T_OPEN_KEY T_NL T_CLOSE_KEY  { $$ = new AST::Condicao($2, NULL, NULL); }

// if ... then { ... }
        |  T_IF expressao T_NL T_THEN T_OPEN_KEY T_NL linhas T_CLOSE_KEY  { $$ = new AST::Condicao($2, $7, NULL ); }

// if ... then {  } else { } 
        | T_IF expressao T_NL T_THEN T_OPEN_KEY T_NL T_CLOSE_KEY T_ELSE T_OPEN_KEY T_NL T_CLOSE_KEY  { $$ = new AST::Condicao($2, NULL, NULL ); }

// if ... then { } else {  ... } 
        | T_IF expressao T_NL T_THEN T_OPEN_KEY T_NL T_CLOSE_KEY T_ELSE T_OPEN_KEY T_NL linhas T_CLOSE_KEY  { $$ = new AST::Condicao($2, NULL, $11 ); }

// if ... then { ... } else { }
        | T_IF expressao T_NL T_THEN T_OPEN_KEY T_NL linhas T_CLOSE_KEY T_ELSE T_OPEN_KEY T_NL T_CLOSE_KEY  { $$ = new AST::Condicao($2, $7, NULL ); }

// if ... then { ... } else { ... }
        | T_IF expressao T_NL T_THEN T_OPEN_KEY T_NL linhas T_CLOSE_KEY T_ELSE T_OPEN_KEY T_NL linhas T_CLOSE_KEY  { $$ = new AST::Condicao($2, $7, $12 ); }
        ;

declaracao:
            tipo variaveis  { $$ = new AST::Declaracao( $1, $2 ); }
          ;

tipo:
       T_TYPE_INT    { $$ = $1;  ultimoTipo = $1; }
     | T_TYPE_FLOAT  { $$ = $1;  ultimoTipo = $1; }
     | T_TYPE_BOOL   { $$ = $1;  ultimoTipo = $1; }
     ;

variaveis: 
           variavel                    { $$ = $1; }
         | variaveis T_COMMA variavel  { $$ = $1;  $1->ajustarProxima($3); } 
         ;

variavel:          
          atribuicao  { $1->direita->verificarSimbolos(tabela_simbolos); // Variáveis a direita foram declaradas?
                        $1->verificarTipo(ultimoTipo,$1->direita->verificarTipo(AST::Tipo::nulo, AST::Tipo::nulo));   //
                        $$ = new AST::Definicao(((AST::Variavel*)$1->esquerda), $1->direita, NULL ); }                                 
        | var         { $$ = new AST::Definicao(((AST::Variavel*)$1), NULL, NULL ); }
        ;

atribuicao:
            var T_EQUAL expressao  { $$ = new AST::OperacaoBinaria( AST::Tipo::atribuicao, $1, $3 ); }                 
          ;

expressao:
                                  primitiva  { $$ = $1; }
         |           T_MINUS      expressao  { $$ = new AST::OperacaoUnaria( AST::Tipo::negacao         , $2 ); }
         |           T_NOT        expressao  { $$ = new AST::OperacaoUnaria( AST::Tipo::inversao        , $2 ); }
         |           T_CAST_INT   expressao  { $$ = new AST::OperacaoUnaria( AST::Tipo::conversao_int   , $2 ); }
         |           T_CAST_FLOAT expressao  { $$ = new AST::OperacaoUnaria( AST::Tipo::conversao_float , $2 ); }
         |           T_CAST_BOOL  expressao  { $$ = new AST::OperacaoUnaria( AST::Tipo::conversao_bool  , $2 ); }
         | T_OPEN    expressao    T_CLOSE    { $$ = new AST::OperacaoUnaria( AST::Tipo::parenteses      , $2 ); }
         |  expressao T_PLUS      expressao  { $$ = new AST::OperacaoBinaria( AST::Tipo::adicao         , $1,  $3 ); }
         | expressao T_MINUS      expressao  { $$ = new AST::OperacaoBinaria( AST::Tipo::subtracao      , $1,  $3 ); }
         | expressao T_TIMES      expressao  { $$ = new AST::OperacaoBinaria( AST::Tipo::multiplicacao  , $1,  $3 ); }
         | expressao T_DIV        expressao  { $$ = new AST::OperacaoBinaria( AST::Tipo::divisao        , $1,  $3 ); }
         | expressao T_AND        expressao  { $$ = new AST::OperacaoBinaria( AST::Tipo::e              , $1,  $3 ); }
         | expressao T_OR         expressao  { $$ = new AST::OperacaoBinaria( AST::Tipo::ou             , $1,  $3 ); }
         | expressao T_EQUAL2     expressao  { $$ = new AST::OperacaoBinaria( AST::Tipo::igual          , $1,  $3 ); }
         | expressao T_DIF        expressao  { $$ = new AST::OperacaoBinaria( AST::Tipo::diferente      , $1,  $3 ); }
         | expressao T_HIGHER     expressao  { $$ = new AST::OperacaoBinaria( AST::Tipo::maior          , $1 , $3 ); }
         | expressao T_HIGH       expressao  { $$ = new AST::OperacaoBinaria( AST::Tipo::maior_igual    , $1,  $3 ); }
         | expressao T_LOWER      expressao  { $$ = new AST::OperacaoBinaria( AST::Tipo::menor          , $1,  $3 ); }
         | expressao T_LOW        expressao  { $$ = new AST::OperacaoBinaria( AST::Tipo::menor_igual    , $1,  $3 ); }
         ; 

primitiva:
           var
         | T_BOOL   { $$ = new AST::Boolean  ( AST::Tipo::boolean , $1 ); }
         | T_INT    { $$ = new AST::Inteiro  ( AST::Tipo::inteiro , $1 ); }
         | T_FLOAT  { $$ = new AST::Real     ( AST::Tipo::real    , $1 ); }
         ;

var:
    T_VAR { $$ = new AST::Variavel ( AST::Tipo::nulo , $1 ); }  

%%
