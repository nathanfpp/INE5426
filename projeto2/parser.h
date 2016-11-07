/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 9 "parser.y" /* yacc.c:1909  */

    #include "arvoreSintatica.h"


#line 49 "parser.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_FLOAT = 258,
    T_INT = 259,
    T_BOOL = 260,
    T_VAR = 261,
    T_TYPE_INT = 262,
    T_TYPE_FLOAT = 263,
    T_TYPE_BOOL = 264,
    T_NL = 265,
    T_OPEN = 266,
    T_CLOSE = 267,
    T_OPEN_KEY = 268,
    T_CLOSE_KEY = 269,
    T_EQUAL = 270,
    T_COMMA = 271,
    T_SEMICOLON = 272,
    T_COLON = 273,
    T_PLUS = 274,
    T_MINUS = 275,
    T_TIMES = 276,
    T_DIV = 277,
    T_NOT = 278,
    T_AND = 279,
    T_OR = 280,
    T_EQUAL2 = 281,
    T_DIF = 282,
    T_HIGHER = 283,
    T_HIGH = 284,
    T_LOWER = 285,
    T_LOW = 286,
    T_CAST_INT = 287,
    T_CAST_FLOAT = 288,
    T_CAST_BOOL = 289,
    T_ADDR = 290,
    T_IF = 291,
    T_THEN = 292,
    T_ELSE = 293,
    T_FOR = 294,
    T_FUN = 295,
    T_RET = 296,
    T_ATRIB_ASK = 297,
    T_DO = 298,
    T_WHILE = 299,
    T_REF = 300,
    T_CALC = 301,
    UMINUS = 302,
    T_CAST = 303,
    INT = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 28 "parser.y" /* yacc.c:1909  */

    AST::atributo_nodo valores;
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

#line 133 "parser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
