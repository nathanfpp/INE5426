%{
#include <iostream>
#include <map>
#include <string.h>
#include <string>
#include <cstdio>
#include "estruturas.h"
#include "tratadorSemantico.h"

extern int yylex();
extern void yyerror(const char* s, ...);
%}

%code requires{//estrutura complementar ao union

}


%code{//declaração de variaveis globais

std::map<std::string, atributo> tabela_simbolos;
tratadorSemantico tratador_semantico;
}


%define parse.trace

/* yylval == %union. union informs the different ways we can store data */
%union {
    atributo value;
    char signal;
}

/* token defines our terminal symbols (tokens). */
%token <value>  T_TYPE_INT
%token <value>  T_VAR
%token <value>  T_FLOAT T_INT
%token <signal> T_PLUS T_MINUS T_TIMES T_DIV 
%token T_NL T_OPEN T_CLOSE T_EQUAL T_COMMA

/* type defines the type of our nonterminal symbols. Types should match the names used in the union. Example: %type<node> expr */
%type <value> program lines line expr atribuicao atribuicao_composta variavel declaracao tipo
%type <signal> sinal


/* Operator precedence for mathematical operators.The latest it is listed, the highest the precedence. left, right, nonassoc */

%left T_PLUS 
%left T_TIMES T_DIV
%left T_OPEN T_CLOSE

/* Starting rule */
%start program

%%

program: lines  /*$$ = $1 when nothing is said*/
       ;

lines: line        /*$$ = $1 when nothing is said*/
     | lines line
     ;

line: T_NL                                                 
    | atribuicao T_NL  { std::cout << "\n\nEntrada: ";  }  
    | tipo T_NL {std::cout <<"\n\nEntrada: ";}
                                            
    ;

expr: T_INT                     {  $$.integer = $1.integer;}     //std::cout << $$.integer << "\n"; 
//
// Adição
    | expr T_PLUS expr           {  $$.integer = $1.integer + $3.integer;
                                    //std::cout << "( " << $1.integer << " + " << $3.integer << " )";
                                 }
// Subtração
    | expr T_MINUS expr          { $$.integer = $1.integer-$3.integer;  
                                    //std::cout << "( "<< $1.integer << " - " << $3.integer << " )" << "\n";    
				 }
// Multiplicação por Escalar
    | expr T_TIMES expr        {   $$.integer = $1.integer*$3.integer; 
                                   //std::cout << $1.integer << " * " << $3.integer  << "\n"; 
                                 }

// Divisão por Escalar
    | expr T_DIV expr          {   $$.integer = $1.integer/$3.integer; 
                                   //std::cout << "( "<<$1.integer << " ) / " << $3.integer << "\n";
                                 }
// Parênteses
    | T_OPEN expr T_CLOSE        { $$.integer = ($2.integer);  
                                   //std::cout << "( " << $2.integer << " )\n"; 
                                 }
// Número negativo
    | T_MINUS expr                 { $$.integer = -1*($2.integer);
                                   //std::cout << "-( " << $2.integer << " )\n";
                                   }                                   
// Fim.
    ;

sinal: T_MINUS | T_PLUS | T_TIMES | T_DIV;

// Atribuição
atribuicao: T_VAR T_EQUAL atribuicao_composta    {if(tratador_semantico.avaliarDeclaracao(tabela_simbolos,$1))
						{$$.var = $1.var;  $$.integer = $3.integer; $$.type = "int";
 						 tabela_simbolos[std::string($$.var)] = $$;
						 std::cout << "R: int: "<< std::string($$.var) << " = "<< $$.integer << "\n";
						}                                        }          
//Fim.
    ;


//Declaração de variável
tipo: T_TYPE_INT variavel //| T_TYPE_BOOL variaveis...
    ;
variavel: declaracao | declaracao T_COMMA variavel
    ;
declaracao: T_VAR {$$.var = $1.var;  $$.integer = 0; $$.type = "int";
		  if(tratador_semantico.avaliarRepeticaoDeclaracao(tabela_simbolos, $1))
                     tabela_simbolos[std::string($$.var)] = $$; }
  

    | T_VAR T_EQUAL atribuicao_composta {$$.var = $1.var;  $$.integer = $3.integer; $$.type = "int";
				      if(tratador_semantico.avaliarRepeticaoDeclaracao(tabela_simbolos, $1))
                   			    tabela_simbolos[std::string($$.var)] = $$; } 
    ;

// Atribuição simples, variável negativa, parênteses e somente algébrica.
atribuicao_composta: T_VAR  {if(tratador_semantico.avaliarDeclaracao(tabela_simbolos,$1))
				   $$.integer = tabela_simbolos[std::string($1.var)].integer;                                
                            }

    | T_MINUS T_VAR         {if(tratador_semantico.avaliarDeclaracao(tabela_simbolos,$2))
				   $$.integer = -1*tabela_simbolos[std::string($2.var)].integer;
                            }

    | T_OPEN  T_VAR T_CLOSE  { if(tratador_semantico.avaliarDeclaracao(tabela_simbolos,$2))
				   $$.integer = (tabela_simbolos[std::string($2.var)].integer);                             
                            }

    | T_OPEN  atribuicao_composta T_CLOSE  { $$.integer = $2.integer;}
    | expr		                   { $$.integer = $1.integer;}

//Generalizando operações com expressões numéricas e variáveis
    | T_VAR sinal atribuicao_composta { 
                  if(tratador_semantico.avaliarDeclaracao(tabela_simbolos,$1)){ 
							     int op1 = tabela_simbolos[std::string($1.var)].integer;
							     int op2 = $3.integer;
                                                         
							     switch($2)
                                                             {
                                                              case '+': 
                                                              $$.integer = op1 + op2;
 							      break;

							      case '-': 
                                                              $$.integer = op1 - op2;
 							      break;

 							      case '*': 
                                                              $$.integer = op1 * op2; 
 							      break;

							      case '/': 
                                                              $$.integer = op1 / op2; 
 							      break;
                                                             }
					                 }
						    }
    | expr sinal atribuicao_composta {                      int op1 = $1.integer;
							    int op2 = $3.integer;                                
							     switch($2)
                                                             {
                                                              case '+': 
                                                              $$.integer = op1 + op2;
 							      break;

							      case '-': 
                                                              $$.integer = op1 - op2;
 							      break;

 							      case '*': 
                                                              $$.integer = op1 * op2; 
 							      break;

							      case '/': 
                                                              $$.integer = op1 / op2; 
 							      break;
                                                             }
					                 }
						   
						   
//Fim.
    ;

%%

