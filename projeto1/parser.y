%{
#include <iostream>
#include <map>
#include <string.h>
#include <string>
#include <cstdio>

extern int yylex();
extern void yyerror(const char* s, ...);
%}

%code requires{
    typedef struct {
       char *var;
       double real;
       
    } complex;   
}


%code{

std::map<std::string, complex> ts;


}


%define parse.trace

/* yylval == %union. union informs the different ways we can store data */
%union {
    complex value;
    char signal;
}

/* token defines our terminal symbols (tokens). */
%token <value>  T_VAR
%token <value>  T_REAL
%token <signal> T_PLUS T_MINUS T_TIMES T_DIV 
%token T_NL T_OPEN T_CLOSE T_EQUAL

/* type defines the type of our nonterminal symbols. Types should match the names used in the union. Example: %type<node> expr */
%type <value> program lines line expr atribuicao atribuicao_composta
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
    | expr T_NL {  std::cout << "R: " << $$.real; 
                   std::cout << "\n\nEntrada: ";                                             }
    | atribuicao
    | atribuicao_composta
    ;

expr: T_REAL                     {  $$.real = $1.real;     std::cout << $$.real << "\n"; }
//
// Adição
    | expr T_PLUS expr           {  $$.real = $1.real + $3.real;
                                    std::cout << "( " << $1.real << " + " << $3.real << " )";
                                 }
// Subtração
    | expr T_MINUS expr          { $$.real = $1.real-$3.real;  
                                    std::cout << "( "<< $1.real << " - " << $3.real << " )" << "\n";    
				 }
// Multiplicação por Escalar
    | expr T_TIMES expr        {   $$.real = $1.real*$3.real; 
                                   std::cout << $1.real << " * " << $3.real  << "\n"; 
                                 }

// Divisão por Escalar
    | expr T_DIV T_REAL          { $$.real = $1.real/$3.real; 
                                   std::cout << "( "<<$1.real << " ) / " << $3.real << "\n";
                                 }
// Parênteses
    | T_OPEN expr T_CLOSE        { $$.real = ($2.real);  
                                   std::cout << "( " << $2.real << " )\n"; }
// Número negativo
    | T_MINUS expr                 { $$.real = -1*($2.real);
                                   std::cout << "-( " << $2.real << " )\n"; }                                   
// Fim.
    ;

sinal: T_MINUS | T_PLUS | T_TIMES | T_DIV;

// Atribuição
atribuicao: T_VAR T_EQUAL expr    {$$.var = $1.var;  $$.real = $3.real; std::cout << "R: "<< *$$.var << " = " << $$.real << "\n"; ts[""+*$$.var] = $$;}  
//Fim.
    ;

// Atribuição composta
atribuicao_composta: T_VAR T_EQUAL T_VAR sinal expr  { if (ts.find(""+*$3.var) == ts.end())
                                                             std::cout<<"variavel inexistente\n" << ts.size();
						       else{ 
							     $$.var = $1.var; 
                                                             
							     switch($4)
                                                             {
                                                              case '+': 
                                                              $$.real = $5.real + ts[""+*$3.var].real; 
 							      break;

							      case '-': 
                                                              $$.real =  ts[""+*$3.var].real - $5.real;
 							      break;

 							      case '*': 
                                                              $$.real = $5.real*ts[""+*$3.var].real; 
 							      break;

							      case '/': 
                                                              $$.real = ts[""+*$3.var].real/$5.real; 
 							      break;
                                                             }
				   	               	     ts[""+*$$.var] = $$;
                                                             std::cout << "R: "<< *$$.var << " = " << $$.real << "\n";
							    }
                                                        }
//Fim.
    ;

%%

