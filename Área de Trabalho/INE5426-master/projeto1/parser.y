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
    AST::TipoDeNodo ultimoTipo;
    std::map<std::string, AST::Variavel*> tabela_simbolos;
}

%define parse.trace

// yylval == %union
// A union informa os diferentes modos de armazenar dados, utilizado para definir os tipos de Símbolos Terminais e Não-Terminais
%union {
    const char *valor;
    AST::NodoBase *nodobase;
    AST::Nodo *nodo;
    AST::Bloco *bloco;
    AST::Variavel *nodovar;
    AST::TipoDeNodo tipo;
}

// %token
// Símbolos Terminais (tokens)
%token <valor> T_FLOAT T_INT T_BOOL T_VAR
//%token <nodo> T_PLUS T_MINUS T_TIMES T_DIV T_NOT T_AND T_OR T_DIF T_HIGHER T_HIGH T_LOWER T_LOW
%token <tipo> T_TYPE_INT T_TYPE_FLOAT T_TYPE_BOOL
%token T_NL T_OPEN T_CLOSE T_EQUAL T_COMMA T_PLUS T_MINUS T_TIMES T_DIV T_NOT T_AND T_OR 
%token T_EQUAL2 T_DIF T_HIGHER T_HIGH T_LOWER T_LOW

// %type
// Define o tipo de Símbolos Não-Terminais
%type <nodobase> linha expressao declaracao primitiva
%type <bloco> programa linhas
%type <nodovar> var
%type <nodo> atribuicao variavel
%type <tipo> tipo

// %left, %right, %nonassoc
// Precedência de operadores matemáticos, os últimos listados possuem maior procedência.
%left T_PLUS 
%left T_TIMES T_DIV
%left T_OPEN T_CLOSE

// %start
// Regra Inicial da Gramática
%start programa
%%

// $$ = $1 por padrão
programa: linhas { arvoreSintatica = $1; } 
        ;

linhas: 
        linha         {  $$ = new AST::Bloco();  if($1 != NULL) $$->novaLinha($1); }
      | linhas linha  {                          if($2 != NULL) $1->novaLinha($2); }
      ;

linha: 
       atribuicao T_NL  { $$ = $1;
                          $1->verificarSimbolos(tabela_simbolos); //verifica se variável a esq e dir na atribuição já foi declarada  
			  //((AST::Nodo*)$1->direita)->verificarTipo(tabela_simbolos[std::string(((AST::Variavel*)$1->esquerda)->id)]->tipo, AST::TipoDeNodo::x); //verifica se o tipo da variável e da atribuição são equivalentes
                          $1->verificarTipoRaiz(tabela_simbolos[std::string(((AST::Variavel*)$1->esquerda)->id)]->tipo,((AST::Nodo*)($1->direita))->verificarTipo(AST::TipoDeNodo::x, AST::TipoDeNodo::x));
                          $$->imprimir();  
                          std::cout << "\nEntrada: "; }

     | declaracao T_NL  { $$ = $1;  
                          $1->acrescentarSimbolos(tabela_simbolos, ultimoTipo);  
                          $$->imprimir();  
                          std::cout << "\nEntrada: "; }
     ;

declaracao:
            tipo variavel  { $$ = new AST::Nodo( NULL, $2, NULL, AST::ClasseDeNodo::declaracao, $1 ); }
          ;

tipo:
       T_TYPE_INT    { $$ = $1;  ultimoTipo = $1; }
     | T_TYPE_FLOAT  { $$ = $1;  ultimoTipo = $1; }
     | T_TYPE_BOOL   { $$ = $1;  ultimoTipo = $1; }
     ;

variavel:
         atribuicao                  { $1->direita->verificarSimbolos(tabela_simbolos); // Variáveis a direita foram declaradas?
                                       $1->verificarTipoRaiz(ultimoTipo,$1->direita->verificarTipo(AST::TipoDeNodo::x, AST::TipoDeNodo::x));   //
                                       $$ = $1;                                                    }                                 
        | variavel T_COMMA variavel  { $$ = $1;  $1->proximo = $3;                                                          }
        | var                        { $$ = new AST::Nodo( $1, NULL, NULL, AST::ClasseDeNodo::atribuicao, AST::TipoDeNodo::atomica ); }
        ;

atribuicao:
            var T_EQUAL expressao  {  $$ = new AST::Nodo( $1, $3, NULL, AST::ClasseDeNodo::atribuicao, AST::TipoDeNodo::x ); }                  
          ;

expressao:
           primitiva	               
         | expressao T_PLUS    expressao  { $$ = new AST::Nodo( $1,  $3, NULL, AST::ClasseDeNodo::operacaoBinaria, AST::TipoDeNodo::adicao        ); }
         | expressao T_MINUS   expressao  { $$ = new AST::Nodo( $1,  $3, NULL, AST::ClasseDeNodo::operacaoBinaria, AST::TipoDeNodo::subtracao     ); }
         | expressao T_TIMES   expressao  { $$ = new AST::Nodo( $1,  $3, NULL, AST::ClasseDeNodo::operacaoBinaria, AST::TipoDeNodo::multiplicacao ); }
         | expressao T_DIV     expressao  { $$ = new AST::Nodo( $1,  $3, NULL, AST::ClasseDeNodo::operacaoBinaria, AST::TipoDeNodo::divisao       ); }
         | expressao T_AND     expressao  { $$ = new AST::Nodo( $1,  $3, NULL, AST::ClasseDeNodo::operacaoBinaria, AST::TipoDeNodo::e             ); }
         | expressao T_OR      expressao  { $$ = new AST::Nodo( $1,  $3, NULL, AST::ClasseDeNodo::operacaoBinaria, AST::TipoDeNodo::ou            ); }
         | expressao T_EQUAL2  expressao  { $$ = new AST::Nodo( $1,  $3, NULL, AST::ClasseDeNodo::operacaoBinaria, AST::TipoDeNodo::igual         );}
         | expressao T_DIF     expressao  { $$ = new AST::Nodo( $1,  $3, NULL, AST::ClasseDeNodo::operacaoBinaria, AST::TipoDeNodo::diferente     );}
         | expressao T_HIGHER  expressao  { $$ = new AST::Nodo( $1,  $3, NULL, AST::ClasseDeNodo::operacaoBinaria, AST::TipoDeNodo::maior         );}
         | expressao T_HIGH    expressao  { $$ = new AST::Nodo( $1,  $3, NULL, AST::ClasseDeNodo::operacaoBinaria, AST::TipoDeNodo::maior_igual   );}
         | expressao T_LOWER   expressao  { $$ = new AST::Nodo( $1,  $3, NULL, AST::ClasseDeNodo::operacaoBinaria, AST::TipoDeNodo::menor         );}
         | expressao T_LOW     expressao  { $$ = new AST::Nodo( $1,  $3, NULL, AST::ClasseDeNodo::operacaoBinaria, AST::TipoDeNodo::menor_igual   );}
         |           T_MINUS   expressao  { $$ = new AST::Nodo(NULL, $2, NULL, AST::ClasseDeNodo::operacaoUnaria,  AST::TipoDeNodo::negacao       ); }
         |           T_NOT     expressao  { $$ = new AST::Nodo(NULL, $2, NULL, AST::ClasseDeNodo::operacaoUnaria,  AST::TipoDeNodo::inversao      ); }
         | T_OPEN    expressao T_CLOSE    { $$ = new AST::Nodo(NULL, $2, NULL, AST::ClasseDeNodo::parenteses,      AST::TipoDeNodo::x             ); }
         ;

primitiva:
           var
         | T_BOOL   { $$ = new AST::Boolean  ( $1, AST::TipoDeNodo::boolean); }
         | T_INT    { $$ = new AST::Inteiro  ( $1, AST::TipoDeNodo::inteiro); }
         | T_FLOAT  { $$ = new AST::Real     ( $1, AST::TipoDeNodo::real   ); }
         ;

var:
    T_VAR { $$ = new AST::Variavel ($1, AST::TipoDeNodo::semTipo); }  

%%
