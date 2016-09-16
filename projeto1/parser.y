%{
#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <string>
#include <cstdio>
#include "estruturas.h"
#include "tratadorSemantico.h"
#include "tratadorAritmetico.h"
#include "arvoreSintatica.h"
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
    AST::TipoDeVariavel ultimoTipo;
    std::map<std::string, atributo> tabela_simbolos;

    std::vector<atributo> list_values;
    //std::vector<atributo>::iterator it;
    tratadorSemantico tratador_semantico;
    tratadorAritmetico tratador_aritmetico;
}

%define parse.trace

// yylval == %union
// A union informa os diferentes modos de armazenar dados, utilizado para definir os tipos de Símbolos Terminais e Não-Terminais
%union {

    const char *valor;
    AST::Nodo *nodo;
    AST::Bloco *bloco;
    AST::TipoDeVariavel tipo;
    AST::Variavel *nodo_var;
}

// %token
// Símbolos Terminais (tokens)
%token <valor> T_FLOAT T_INT T_BOOL T_VAR
%token <nodo> T_PLUS T_MINUS T_TIMES T_DIV T_NOT T_AND T_OR T_DIF T_HIGHER T_HIGH T_LOWER T_LOW
%token <tipo> T_TYPE_INT T_TYPE_FLOAT T_TYPE_BOOL
%token T_NL T_OPEN T_CLOSE T_EQUAL T_COMMA


// %type
// Define o tipo de Símbolos Não-Terminais
%type <nodo> linha atribuicao expressao declaracao primitiva var variavel
%type <bloco> programa linhas
//%type <nodo_var> variavel
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
       atribuicao T_NL  { $$ = $1;  std::cout << "\nEntrada: "; }
     | declaracao T_NL  { $$ = $1; $$->imprimir(); std::cout << "\nEntrada: "; }
     ;

declaracao:
            tipo variavel  { $$ = new AST::Declaracao ($1, $2 ); }
          ;

tipo:
       T_TYPE_INT    { $$ = $1;  ultimoTipo = $1; }
     | T_TYPE_FLOAT  { $$ = $1;  ultimoTipo = $1; }
     | T_TYPE_BOOL   { $$ = $1;  ultimoTipo = $1; }
     ;

variavel: // Listar variáveis para declaração
         atribuicao                   { //tabela_simbolos.add($1)
                                         $$ = new AST::Atribuicao($1, NULL ); 
                                        }
        | variavel T_COMMA variavel  { $$ = new AST::Atribuicao($1, $3); 
                                        }
        | var                          { //tabela_simbolos.add($1)    
					
                                        }
        ;

atribuicao: // Possivelmente criar lista de variáveis
            var T_EQUAL expressao  { //tabela_simbolos.add($1) 
                                      $$ = new AST::OperacaoBinaria( $1, AST::Operacao::atribuicao, $3   ); }                     
          ;

expressao:
           primitiva
         | expressao T_PLUS    expressao  { $$ = new AST::OperacaoBinaria( $1, AST::Operacao::adicao,        $3 ); }
         | expressao T_MINUS   expressao  { $$ = new AST::OperacaoBinaria( $1, AST::Operacao::subtracao,     $3 ); }
         | expressao T_TIMES   expressao  { $$ = new AST::OperacaoBinaria( $1, AST::Operacao::multiplicacao, $3 ); }
         | expressao T_DIV     expressao  { $$ = new AST::OperacaoBinaria( $1, AST::Operacao::divisao,       $3 ); }
         | expressao T_AND     expressao  { $$ = new AST::OperacaoBinaria( $1, AST::Operacao::e,             $3 ); }
         | expressao T_OR      expressao  { $$ = new AST::OperacaoBinaria( $1, AST::Operacao::ou,            $3 ); }
         |           T_MINUS   expressao  { $$ = new AST::OperacaoUnaria (     AST::Operacao::negacao,       $2 ); }
         |           T_NOT     expressao  { $$ = new AST::OperacaoUnaria (     AST::Operacao::inversao,      $2 ); }
         | T_OPEN    expressao T_CLOSE    { $$ = new AST::OperacaoUnaria (     AST::Operacao::parenteses,    $2 ); }
         ;

primitiva:
           var
         | T_BOOL   { $$ = new AST::Boolean  ( $1       ); }
         | T_INT    { $$ = new AST::Inteiro  ( $1       ); }
         | T_FLOAT  { $$ = new AST::Real     ( $1       ); }
         ;

var:
    T_VAR { $$ = new AST::Variavel ( $1, NULL ); } 

%%
