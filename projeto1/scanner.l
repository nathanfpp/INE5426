%{
#include <string>
#include "parser.h" /* Generated by Bison */
#include "arvoreSintatica.h"

extern int yylineno;
void yyerror(const char* s, ...);

%}

%option noyywrap nodefault yylineno

valor_int       [0-9]+
valor_float     ({valor_int}\.{valor_int})|(\.{valor_int})|({valor_int}\.)
valor_bool      ("true"|"false")
letter          ([a-z]|[A-Z])([a-z]|[A-Z]|"_"|[0-9])*
rejeite         [^0-9a-zA-Z\(\)\,\{\}\_\+\=\/\>\<\*\-\!\&\|\t" "\n]+

%%

[ \t]               ; // Ignora espaços entre tokens
" "                 ;

"int"               { yylval.tipo = AST::Tipo::inteiro;  return T_TYPE_INT;   } // 
"float"             { yylval.tipo = AST::Tipo::real;     return T_TYPE_FLOAT; } // Tipos de Variáveis
"bool"              { yylval.tipo = AST::Tipo::boolean;  return T_TYPE_BOOL;  } // 
"addr"		    { return T_ADDR;   }
"ref"		    { yylval.num_ref = 1;  return T_REF;   }
"if"                { return T_IF;   }
"then"              { return T_THEN; }
"else"              { return T_ELSE; }
"for"               { return T_FOR;  }
"fun"               { return T_FUN;  }
"ret"               { return T_RET;  }

"[int]"             { return T_CAST_INT;   } //
"[float]"           { return T_CAST_FLOAT; } // Conversores de Tipo
"[bool]"            { return T_CAST_BOOL;  } //

{valor_int}         { yylval.valor = strdup(yytext);  return T_INT;   } // Valores de
{valor_float}       { yylval.valor = strdup(yytext);  return T_FLOAT; } //  Variáveis
{valor_bool}        { yylval.valor = strdup(yytext);  return T_BOOL;  } //
{letter}            { yylval.valor = strdup(yytext);  return T_VAR;   } //

"+"                 { return T_PLUS ; } //
"-"                 { return T_MINUS; } // Operadores
\*                  { return T_TIMES; } // Aritméticos
"/"                 { return T_DIV;   } //

"!"                 { return T_NOT; } // 
"&"                 { return T_AND; } // Operadores Lógicos
"|"                 { return T_OR;  } // 

"=="                { return T_EQUAL2; } //
"!="                { return T_DIF;    } //
">"                 { return T_HIGHER; } // Tokens de
">="                { return T_HIGH;   } // Comparadores
"<"                 { return T_LOWER;  } //
"<="                { return T_LOW;    } //

"("                 { return T_OPEN;      }
")"                 { return T_CLOSE;     }
"{"                 { return T_OPEN_KEY;  }
"}"                 { return T_CLOSE_KEY; }
"="                 { return T_EQUAL;     }
","                 { return T_COMMA;     }

\n                  { return T_NL; }

{rejeite}           { yyerror("lexical error: unknown symbol %s\n", strdup(yytext));} 

%%

void yyerror(const char *s, ...){
    va_list ap;
    va_start(ap, s);
    std::fprintf(stderr, "[Line %d] ", yylineno);
    std::vfprintf(stderr, s, ap);
}
