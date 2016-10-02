/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <string>
#include <cstdio>
#include <fstream>

extern int yylex();
extern void yyerror(const char* s, ...);

#line 79 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
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
#line 16 "parser.y" /* yacc.c:355  */

    #include "arvoreSintatica.h"

#line 113 "parser.cpp" /* yacc.c:355  */

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
    T_PLUS = 272,
    T_MINUS = 273,
    T_TIMES = 274,
    T_DIV = 275,
    T_NOT = 276,
    T_AND = 277,
    T_OR = 278,
    T_EQUAL2 = 279,
    T_DIF = 280,
    T_HIGHER = 281,
    T_HIGH = 282,
    T_LOWER = 283,
    T_LOW = 284,
    T_CAST_INT = 285,
    T_CAST_FLOAT = 286,
    T_CAST_BOOL = 287,
    T_ADDR = 288,
    T_IF = 289,
    T_THEN = 290,
    T_ELSE = 291,
    T_FOR = 292,
    T_FUN = 293,
    T_RET = 294,
    T_REF = 295,
    T_EQUALS2 = 296,
    UMINUS = 297,
    T_CAST = 298,
    INT = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 33 "parser.y" /* yacc.c:355  */

    const char* valor;
    AST::Nodo *nodo;
    AST::Variavel *variavel;
    //AST::Inteiro *inteiro;
    //AST::Real *real;
    //AST::Boolean *boolean;
    AST::Declaracao *declaracao;
    AST::Definicao *definicao;
    AST::DefinicaoArranjo *definicaoArranjo;
    AST::OperacaoUnaria *opUnaria;
    AST::OperacaoBinaria *opBinaria;
    AST::Condicao *condicao;
    AST::Laco *laco;
    AST::Funcao *funcao;
    AST::Parametro *parametro;
    AST::Bloco *bloco;
    AST::Tipo tipo;
    int num_ref;

#line 191 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 206 "parser.cpp" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 22 "parser.y" /* yacc.c:359  */

    AST::Bloco *arvoreSintatica;
    AST::Tipo ultimoTipo;
    AST::TabelaDeSimbolos *escopoPrincipal = new AST::TabelaDeSimbolos();

#line 214 "parser.cpp" /* yacc.c:359  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   743

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   109,   110,   114,   115,   116,   117,   118,
     119,   120,   121,   125,   129,   130,   134,   138,   139,   140,
     141,   145,   146,   150,   154,   155,   159,   160,   164,   167,
     172,   178,   181,   184,   187,   190,   193,   199,   202,   205,
     208,   211,   214,   217,   220,   225,   228,   233,   236,   239,
     242,   247,   248,   252,   256,   259,   264,   265,   269,   273,
     274,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   305,   306,   307,   311,   312,   313,
     314,   318,   319,   323,   323
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_FLOAT", "T_INT", "T_BOOL", "T_VAR",
  "T_TYPE_INT", "T_TYPE_FLOAT", "T_TYPE_BOOL", "T_NL", "T_OPEN", "T_CLOSE",
  "T_OPEN_KEY", "T_CLOSE_KEY", "T_EQUAL", "T_COMMA", "T_PLUS", "T_MINUS",
  "T_TIMES", "T_DIV", "T_NOT", "T_AND", "T_OR", "T_EQUAL2", "T_DIF",
  "T_HIGHER", "T_HIGH", "T_LOWER", "T_LOW", "T_CAST_INT", "T_CAST_FLOAT",
  "T_CAST_BOOL", "T_ADDR", "T_IF", "T_THEN", "T_ELSE", "T_FOR", "T_FUN",
  "T_RET", "T_REF", "T_EQUALS2", "UMINUS", "T_CAST", "INT", "$accept",
  "programa", "linhas", "linha", "atribuicao", "var_arranjo", "declaracao",
  "variaveis", "variavel", "def_arranjo", "dec_arranjo", "arranjo",
  "cha_funcao", "funcao_arranjo", "condicao", "laco", "dec_funcao",
  "def_funcao", "parametros", "parametro", "argumentos", "argumento",
  "retorno", "expressao", "tipo", "primitiva", "var", "referencia", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF -133

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-133)))

#define YYTABLE_NINF -15

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     582,    -8,  -133,  -133,  -133,  -133,    20,     2,  -133,     6,
     582,  -133,     1,     7,     9,  -133,    34,    45,    57,    58,
      70,    -1,  -133,    23,   107,  -133,  -133,  -133,     3,    20,
      20,    20,    20,    20,    20,    20,   304,  -133,  -133,   576,
    -133,  -133,    51,    71,    20,    67,  -133,  -133,  -133,    20,
    -133,  -133,  -133,  -133,  -133,  -133,    77,    11,  -133,    69,
    -133,  -133,  -133,    84,    52,    96,  -133,  -133,     4,  -133,
     606,   107,   624,    90,    90,   701,    90,    90,    90,    90,
      85,    20,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,  -133,    20,   674,    20,   701,    20,   112,
      66,   113,    20,  -133,    20,  -133,   642,  -133,   114,   187,
     187,    90,   -15,   714,   714,   701,   146,   146,   146,   146,
     146,   606,    53,   688,   119,   193,  -133,  -133,    20,   660,
    -133,   701,  -133,   116,   123,   121,    56,  -133,   129,   105,
    -133,    75,   131,  -133,    95,   143,   136,   138,   142,   151,
     154,   184,  -133,  -133,  -133,   132,   289,  -133,   356,   365,
     374,   168,    39,   169,  -133,   171,   153,  -133,  -133,   409,
    -133,   418,   427,    30,   462,   469,   172,   182,  -133,  -133,
    -133,   476,   198,  -133,  -133,    30,    30,   485,   520,   199,
    -133,   189,   205,   207,    30,  -133,   529,   538,  -133,   206,
     208,   211,  -133,  -133,   573,  -133,  -133,   210,  -133,  -133
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    91,    84,    85,    86,    12,     0,     0,    93,     0,
       2,     3,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,    14,     0,     0,    90,    89,    88,    91,     0,
       0,     0,     0,     0,     0,     0,    93,    62,    63,     0,
      61,    87,     0,    91,     0,     0,     1,     4,     5,     0,
       6,    11,     7,     8,     9,    10,    91,     0,    21,    16,
      17,    19,    23,    22,     0,    92,    94,    28,     0,    56,
      58,     0,     0,    64,    65,    66,    67,    68,    71,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,     0,     0,    13,     0,     0,
       0,    92,     0,    29,     0,    26,    58,    69,     0,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,    61,     0,    18,    20,     0,     0,
      57,    58,    30,     0,     0,     0,     0,    24,    45,     0,
      51,     0,    61,    27,     0,     0,     0,     0,     0,     0,
      46,     0,    91,    53,    25,    31,     0,    37,     0,     0,
       0,     0,     0,     0,    52,     0,    32,    41,    38,     0,
      39,     0,     0,     0,     0,     0,     0,     0,    42,    43,
      40,     0,     0,    59,    60,     0,     0,     0,     0,     0,
      44,     0,     0,     0,     0,    33,     0,     0,    47,     0,
       0,     0,    34,    35,     0,    48,    49,     0,    36,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -132,    98,    -6,  -133,  -133,  -133,   127,   137,
    -133,  -133,    74,  -133,  -133,  -133,  -133,  -133,  -133,    80,
    -133,   134,   -99,   257,   -54,   -96,     0,    54
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    14,    59,    60,    61,
      62,    15,    37,    38,    17,    18,    19,    20,   139,   140,
      68,    69,   182,   121,    21,    40,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    45,   124,    24,    83,    56,    46,    22,    43,    87,
      22,    48,   156,   158,    71,    58,   103,    99,    44,    50,
     104,    63,    49,    25,    26,    27,    28,   169,   171,    65,
     174,    29,   142,    25,    26,    27,   152,    57,    30,     8,
     181,    31,     8,   187,    51,     1,     2,     3,     4,     5,
      32,    33,    34,    35,    23,    52,   196,    93,   101,    43,
      36,    23,    43,    66,    23,   204,   134,    53,    54,   147,
       8,   141,    56,     6,    16,    64,     7,   183,   173,     8,
      55,   152,    94,    96,    16,   100,   192,   193,    98,   183,
     183,    66,    66,     8,    58,   201,     8,   141,   183,   -14,
      63,     1,     2,     3,     4,     5,     8,   102,    47,   155,
      25,    26,    27,    28,    87,     8,   135,   150,    29,    67,
     108,   151,    22,   125,   128,    30,   144,   133,    31,     6,
     148,   137,     7,   145,   146,     8,    22,    32,    33,    34,
      35,   153,   149,   154,    22,    22,   159,    36,   160,     1,
       2,     3,     4,     5,    64,   161,    22,   157,    22,    22,
      22,   162,    22,    81,    82,    83,    84,   163,   165,    22,
      87,    22,    22,   184,    22,    22,    23,     6,   172,   175,
       7,    22,   188,     8,   176,   184,   184,    22,    22,   177,
      23,     2,     3,     4,   184,   189,    22,    22,    23,    23,
       2,     3,     4,   198,    22,   138,    83,    84,   191,   197,
      23,    87,    23,    23,    23,   199,    23,   200,    16,    16,
     205,   207,   206,    23,   209,    23,    23,   126,    23,    23,
      16,   164,    16,    16,    16,    23,    16,   127,   130,     0,
       0,    23,    23,    16,     0,    16,    16,     0,    16,    16,
      23,    23,     0,     0,    47,    16,    47,     0,    23,     0,
       0,    16,    16,    39,     0,     0,     0,    47,     0,    47,
      16,    16,    47,     0,     0,     0,     0,     0,    16,    47,
       0,    70,     0,     0,     0,    47,    72,    73,    74,    75,
      76,    77,    78,    79,    47,     1,     2,     3,     4,     5,
       0,    95,    47,   166,     0,     0,    97,    25,    26,    27,
      28,     0,     0,     0,     0,    29,     0,     0,     0,     0,
       0,     0,    30,     6,     0,    31,     7,     0,   106,     8,
       0,     0,     0,     0,    32,    33,    34,    35,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
       0,     0,     0,   123,     0,     0,     0,     0,     0,   129,
       0,   131,     1,     2,     3,     4,     5,     0,     0,     0,
     167,     1,     2,     3,     4,     5,     0,     0,     0,   168,
       1,     2,     3,     4,     5,   129,     0,     0,   170,     0,
       6,     0,     0,     7,     0,     0,     8,     0,     0,     6,
       0,     0,     7,     0,     0,     8,     0,     0,     6,     0,
       0,     7,     0,     0,     8,     1,     2,     3,     4,     5,
       0,     0,     0,   178,     1,     2,     3,     4,     5,     0,
       0,     0,   179,     1,     2,     3,     4,     5,     0,     0,
       0,   180,     0,     6,     0,     0,     7,     0,     0,     8,
       0,     0,     6,     0,     0,     7,     0,     0,     8,     0,
       0,     6,     0,     0,     7,     0,     0,     8,     1,     2,
       3,     4,     5,     0,     0,     1,     2,     3,     4,     5,
       0,     0,     1,     2,     3,     4,     5,     0,     0,     0,
     190,     1,     2,     3,     4,     5,     6,     0,     0,     7,
       0,   185,     8,     6,     0,     0,     7,     0,   186,     8,
       6,     0,     0,     7,     0,     0,     8,     0,     0,     6,
       0,     0,     7,     0,   194,     8,     1,     2,     3,     4,
       5,     0,     0,     0,   195,     1,     2,     3,     4,     5,
       0,     0,     0,   202,     1,     2,     3,     4,     5,     0,
       0,     0,   203,     0,     6,     0,     0,     7,     0,     0,
       8,     0,     0,     6,     0,     0,     7,     0,     0,     8,
       0,     0,     6,     0,     0,     7,     0,     0,     8,     1,
       2,     3,     4,     5,     0,     0,    80,   208,     1,     2,
       3,     4,     5,    81,    82,    83,    84,     0,    85,    86,
      87,    88,    89,    90,    91,    92,     0,     6,     0,     0,
       7,     0,     0,     8,     0,     0,     6,     0,   105,     7,
       0,     0,     8,    81,    82,    83,    84,     0,    85,    86,
      87,    88,    89,    90,    91,    92,   107,     0,     0,     0,
       0,    81,    82,    83,    84,     0,    85,    86,    87,    88,
      89,    90,    91,    92,   132,     0,     0,     0,     0,    81,
      82,    83,    84,     0,    85,    86,    87,    88,    89,    90,
      91,    92,   143,     0,     0,     0,     0,    81,    82,    83,
      84,     0,    85,    86,    87,    88,    89,    90,    91,    92,
     122,    81,    82,    83,    84,     0,    85,    86,    87,    88,
      89,    90,    91,    92,   136,    81,    82,    83,    84,     0,
      85,    86,    87,    88,    89,    90,    91,    92,    81,    82,
      83,    84,     0,    85,    86,    87,    88,    89,    90,    91,
      92,    81,    82,    83,    84,     0,     0,     0,    87,    88,
      89,    90,    91,    92
};

static const yytype_int16 yycheck[] =
{
       0,     7,    98,    11,    19,     6,     0,     7,     6,    24,
      10,    10,   144,   145,    11,    21,    12,     6,    16,    10,
      16,    21,    15,     3,     4,     5,     6,   159,   160,     6,
     162,    11,   128,     3,     4,     5,     6,    38,    18,    40,
     172,    21,    40,   175,    10,     6,     7,     8,     9,    10,
      30,    31,    32,    33,     0,    10,   188,     6,     6,     6,
      40,     7,     6,    40,    10,   197,    13,    10,    10,    13,
      40,   125,     6,    34,     0,    21,    37,   173,    39,    40,
      10,     6,    11,    16,    10,    16,   185,   186,    11,   185,
     186,    40,    40,    40,   100,   194,    40,   151,   194,    15,
     100,     6,     7,     8,     9,    10,    40,    11,    10,    14,
       3,     4,     5,     6,    24,    40,   122,    12,    11,    12,
      35,    16,   122,    11,    11,    18,    10,    13,    21,    34,
     136,    12,    37,    10,    13,    40,   136,    30,    31,    32,
      33,   141,    13,    12,   144,   145,    10,    40,    10,     6,
       7,     8,     9,    10,   100,    13,   156,    14,   158,   159,
     160,    10,   162,    17,    18,    19,    20,    13,    36,   169,
      24,   171,   172,   173,   174,   175,   122,    34,    10,    10,
      37,   181,    10,    40,    13,   185,   186,   187,   188,    36,
     136,     7,     8,     9,   194,    13,   196,   197,   144,   145,
       7,     8,     9,    14,   204,    12,    19,    20,    10,    10,
     156,    24,   158,   159,   160,    10,   162,    10,   144,   145,
      14,    10,    14,   169,    14,   171,   172,   100,   174,   175,
     156,   151,   158,   159,   160,   181,   162,   100,   104,    -1,
      -1,   187,   188,   169,    -1,   171,   172,    -1,   174,   175,
     196,   197,    -1,    -1,   156,   181,   158,    -1,   204,    -1,
      -1,   187,   188,     6,    -1,    -1,    -1,   169,    -1,   171,
     196,   197,   174,    -1,    -1,    -1,    -1,    -1,   204,   181,
      -1,    24,    -1,    -1,    -1,   187,    29,    30,    31,    32,
      33,    34,    35,    36,   196,     6,     7,     8,     9,    10,
      -1,    44,   204,    14,    -1,    -1,    49,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    34,    -1,    21,    37,    -1,    71,    40,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,   102,
      -1,   104,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      14,     6,     7,     8,     9,    10,    -1,    -1,    -1,    14,
       6,     7,     8,     9,    10,   128,    -1,    -1,    14,    -1,
      34,    -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    34,
      -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    34,    -1,
      -1,    37,    -1,    -1,    40,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    14,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    14,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    14,    -1,    34,    -1,    -1,    37,    -1,    -1,    40,
      -1,    -1,    34,    -1,    -1,    37,    -1,    -1,    40,    -1,
      -1,    34,    -1,    -1,    37,    -1,    -1,    40,     6,     7,
       8,     9,    10,    -1,    -1,     6,     7,     8,     9,    10,
      -1,    -1,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      14,     6,     7,     8,     9,    10,    34,    -1,    -1,    37,
      -1,    39,    40,    34,    -1,    -1,    37,    -1,    39,    40,
      34,    -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    34,
      -1,    -1,    37,    -1,    39,    40,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    14,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    14,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    14,    -1,    34,    -1,    -1,    37,    -1,    -1,
      40,    -1,    -1,    34,    -1,    -1,    37,    -1,    -1,    40,
      -1,    -1,    34,    -1,    -1,    37,    -1,    -1,    40,     6,
       7,     8,     9,    10,    -1,    -1,    10,    14,     6,     7,
       8,     9,    10,    17,    18,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    34,    -1,    -1,
      37,    -1,    -1,    40,    -1,    -1,    34,    -1,    12,    37,
      -1,    -1,    40,    17,    18,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    12,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    12,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    12,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      16,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    16,    17,    18,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    17,    18,    19,    20,    -1,    -1,    -1,    24,    25,
      26,    27,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    34,    37,    40,    46,
      47,    48,    49,    50,    51,    56,    57,    59,    60,    61,
      62,    69,    71,    72,    11,     3,     4,     5,     6,    11,
      18,    21,    30,    31,    32,    33,    40,    57,    58,    68,
      70,    71,    72,     6,    16,    49,     0,    48,    10,    15,
      10,    10,    10,    10,    10,    10,     6,    38,    49,    52,
      53,    54,    55,    71,    72,     6,    40,    12,    65,    66,
      68,    11,    68,    68,    68,    68,    68,    68,    68,    68,
      10,    17,    18,    19,    20,    22,    23,    24,    25,    26,
      27,    28,    29,     6,    11,    68,    16,    68,    11,     6,
      16,     6,    11,    12,    16,    12,    68,    12,    35,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    16,    68,    70,    11,    53,    54,    11,    68,
      66,    68,    12,    13,    13,    49,    16,    12,    12,    63,
      64,    69,    70,    12,    10,    10,    13,    13,    49,    13,
      12,    16,     6,    71,    12,    14,    47,    14,    47,    10,
      10,    13,    10,    13,    64,    36,    14,    14,    14,    47,
      14,    47,    10,    39,    47,    10,    13,    36,    14,    14,
      14,    47,    67,    70,    71,    39,    39,    47,    10,    13,
      14,    10,    67,    67,    39,    14,    47,    10,    14,    10,
      10,    67,    14,    14,    47,    14,    14,    10,    14,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    49,    50,    50,    51,    52,    52,    52,
      52,    53,    53,    54,    55,    55,    56,    56,    57,    57,
      58,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    60,    61,    61,    62,    62,    62,
      62,    63,    63,    64,    57,    57,    65,    65,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    69,    70,    70,    70,
      70,    71,    71,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     3,     1,     1,     2,     1,     3,     1,
       3,     1,     1,     1,     4,     5,     4,     5,     3,     4,
       4,     7,     8,    11,    12,    12,    13,     7,     8,     8,
       9,     8,     9,     9,    10,     5,     6,    11,    12,    12,
      13,     1,     3,     2,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     3,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 102 "parser.y" /* yacc.c:1646  */
    { arvoreSintatica = (yyvsp[0].bloco);
                   (yyval.bloco)->analisar(escopoPrincipal, 0);
                   (yyval.bloco)->imprimir(0, true);
		   std::cout <<"\n";}
#line 1539 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 109 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = new AST::Bloco( AST::Tipo::bloco );  (yyval.bloco)->novaLinha((yyvsp[0].nodo)); }
#line 1545 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = (yyvsp[-1].bloco);                                  (yyvsp[-1].bloco)->novaLinha((yyvsp[0].nodo)); }
#line 1551 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].opBinaria); }
#line 1557 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].declaracao);   }
#line 1563 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].condicao);   }
#line 1569 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].laco);   }
#line 1575 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].funcao);   }
#line 1581 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].funcao);   }
#line 1587 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].funcao);   }
#line 1593 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = NULL; }
#line 1599 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 125 "parser.y" /* yacc.c:1646  */
    {if(((AST::Variavel*)(yyvsp[-2].nodo))->ponteiros > 0) ((AST::Variavel*)(yyvsp[-2].nodo))->ponteiroEsqAtribuicao = true;  (yyval.opBinaria) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::atribuicao, (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 1605 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1611 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 130 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1617 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyval.declaracao) = new AST::Declaracao( AST::Tipo::declaracao , (yyvsp[-1].tipo), (yyvsp[0].definicao) ); }
#line 1623 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[0].definicao); }
#line 1629 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[-2].definicao);  (yyvsp[-2].definicao)->ajustarProxima((yyvsp[0].definicao)); }
#line 1635 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[0].definicao); }
#line 1641 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[-2].definicao);  (yyvsp[-2].definicao)->ajustarProxima((yyvsp[0].definicao)); }
#line 1647 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::Definicao( AST::Tipo::definicao   , ((AST::Variavel*)(yyvsp[0].opBinaria)->esquerda) , (yyvsp[0].opBinaria)->direita , NULL ); }
#line 1653 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::Definicao( AST::Tipo::definicao   , ((AST::Variavel*)(yyvsp[0].nodo))           , NULL        , NULL ); }
#line 1659 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 150 "parser.y" /* yacc.c:1646  */
    {(yyval.definicao) = new AST::DefinicaoArranjo( AST::Tipo::definicao_arranjo, (yyvsp[0].variavel), NULL , NULL ); }
#line 1665 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval.variavel) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo ,(yyvsp[-3].valor), (yyvsp[-1].nodo),0 ); }
#line 1671 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.variavel) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo ,(yyvsp[-3].valor), (yyvsp[-1].nodo), (yyvsp[-4].num_ref) ); }
#line 1677 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo , (yyvsp[-3].valor), (yyvsp[-1].nodo),0 ); }
#line 1683 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo , (yyvsp[-3].valor), (yyvsp[-1].nodo),(yyvsp[-4].num_ref) ); }
#line 1689 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_cha, AST::Tipo::nulo , (yyvsp[-2].valor) , NULL , NULL , NULL ); }
#line 1695 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_cha, AST::Tipo::nulo , (yyvsp[-3].valor) , (yyvsp[-1].parametro) , NULL , NULL ); }
#line 1701 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::ChamadaOuArranjo( AST::Tipo::nulo, AST::Tipo::nulo , (yyvsp[-3].valor) , new AST::Parametro( AST::Tipo::parametro, AST::Tipo::nulo, (yyvsp[-1].nodo), NULL ) , NULL , NULL, (yyvsp[-1].nodo) ); }
#line 1707 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao( AST::Tipo::condicao , (yyvsp[-5].nodo), NULL, NULL); }
#line 1713 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao( AST::Tipo::condicao , (yyvsp[-6].nodo), (yyvsp[-1].bloco), NULL ); }
#line 1719 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao( AST::Tipo::condicao , (yyvsp[-9].nodo), NULL, NULL ); }
#line 1725 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao( AST::Tipo::condicao , (yyvsp[-10].nodo), NULL, (yyvsp[-1].bloco) ); }
#line 1731 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao( AST::Tipo::condicao , (yyvsp[-10].nodo), (yyvsp[-5].bloco), NULL ); }
#line 1737 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao( AST::Tipo::condicao , (yyvsp[-11].nodo), (yyvsp[-6].bloco), (yyvsp[-1].bloco) ); }
#line 1743 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::laco , NULL , (yyvsp[-4].nodo) , NULL , NULL ); }
#line 1749 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 203 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::laco , NULL , (yyvsp[-5].nodo) , (yyvsp[-3].opBinaria) , NULL ); }
#line 1755 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::laco , (yyvsp[-6].opBinaria) , (yyvsp[-4].nodo) , NULL , NULL ); }
#line 1761 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::laco , (yyvsp[-7].opBinaria) , (yyvsp[-5].nodo) , (yyvsp[-3].opBinaria) , NULL ); }
#line 1767 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::laco , NULL , (yyvsp[-5].nodo) , NULL , (yyvsp[-1].bloco) ); }
#line 1773 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 215 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::laco , NULL , (yyvsp[-6].nodo) , (yyvsp[-4].opBinaria) , (yyvsp[-1].bloco) ); }
#line 1779 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::laco , (yyvsp[-7].opBinaria) , (yyvsp[-5].nodo) , NULL , (yyvsp[-1].bloco) ); }
#line 1785 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::laco , (yyvsp[-8].opBinaria) , (yyvsp[-6].nodo) , (yyvsp[-4].opBinaria) , (yyvsp[-1].bloco) ); }
#line 1791 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_dec, (yyvsp[-4].tipo) , (yyvsp[-2].valor) , NULL , NULL , NULL); }
#line 1797 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 229 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_dec, (yyvsp[-5].tipo) , (yyvsp[-3].valor) , (yyvsp[-1].parametro)   , NULL , NULL); }
#line 1803 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_def, (yyvsp[-10].tipo) , (yyvsp[-8].valor) , NULL , NULL , (yyvsp[-2].nodo)  ); }
#line 1809 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 237 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_def, (yyvsp[-11].tipo) , (yyvsp[-9].valor) , NULL , (yyvsp[-4].bloco)   , (yyvsp[-2].nodo) ); }
#line 1815 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 240 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_def, (yyvsp[-11].tipo) , (yyvsp[-9].valor) , (yyvsp[-7].parametro)   , NULL , (yyvsp[-2].nodo) ); }
#line 1821 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 243 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_def, (yyvsp[-12].tipo) , (yyvsp[-10].valor) , (yyvsp[-8].parametro)   , (yyvsp[-4].bloco)   , (yyvsp[-2].nodo) ); }
#line 1827 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 247 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[0].parametro); }
#line 1833 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 248 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[-2].parametro); (yyval.parametro)->proximo = (yyvsp[0].parametro); }
#line 1839 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 252 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, (yyvsp[-1].tipo), (yyvsp[0].nodo), NULL );  }
#line 1845 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 257 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_cha, AST::Tipo::nulo , (yyvsp[-2].valor) , NULL , NULL , NULL ); }
#line 1851 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_cha, AST::Tipo::nulo , (yyvsp[-3].valor) , (yyvsp[-1].parametro)   , NULL , NULL ); }
#line 1857 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[0].parametro);                   }
#line 1863 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 265 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[-2].parametro); (yyval.parametro)->proximo = (yyvsp[0].parametro); }
#line 1869 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 269 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, AST::Tipo::nulo, (yyvsp[0].nodo), NULL );  }
#line 1875 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 273 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1881 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1887 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 278 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1893 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 279 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].funcao); }
#line 1899 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 280 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1905 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 281 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::negacao         , (yyvsp[0].nodo) ); }
#line 1911 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 282 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::inversao        , (yyvsp[0].nodo) ); }
#line 1917 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 283 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_int   , (yyvsp[0].nodo) ); }
#line 1923 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 284 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_float , (yyvsp[0].nodo) ); }
#line 1929 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 285 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_bool  , (yyvsp[0].nodo) ); }
#line 1935 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 286 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::parenteses      , (yyvsp[-1].nodo) ); }
#line 1941 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 287 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::referencia      , (yyvsp[0].nodo) ); }
#line 1947 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 288 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::endereco        , (yyvsp[0].nodo) ); }
#line 1953 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 290 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::adicao         , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1959 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 291 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::subtracao      , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1965 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 292 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::multiplicacao  , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1971 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 293 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::divisao        , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1977 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 294 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::e              , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1983 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 295 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::ou             , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1989 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 296 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::igual          , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1995 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 297 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::diferente      , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 2001 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 298 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::maior          , (yyvsp[-2].nodo) , (yyvsp[0].nodo) ); }
#line 2007 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 299 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::maior_igual    , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 2013 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 300 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::menor          , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 2019 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 301 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::menor_igual    , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 2025 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 305 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = AST::Tipo::inteiro;  ultimoTipo = (yyvsp[0].tipo); }
#line 2031 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 306 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = AST::Tipo::real;     ultimoTipo = (yyvsp[0].tipo); }
#line 2037 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 307 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = AST::Tipo::boolean;  ultimoTipo = (yyvsp[0].tipo); }
#line 2043 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 312 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Boolean  ( (yyvsp[0].valor) ); (yyval.nodo)->tipo = AST::Tipo::boolean; }
#line 2049 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 313 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Inteiro  ( (yyvsp[0].valor) ); (yyval.nodo)->tipo = AST::Tipo::inteiro; }
#line 2055 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 314 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Real     ( (yyvsp[0].valor) ); (yyval.nodo)->tipo = AST::Tipo::real;    }
#line 2061 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 318 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Variavel( AST::Tipo::variavel, AST::Tipo::nulo , (yyvsp[0].valor), 0 );}
#line 2067 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 319 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Variavel( AST::Tipo::variavel, AST::Tipo::nulo, (yyvsp[0].valor), (yyvsp[-1].num_ref) );}
#line 2073 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 323 "parser.y" /* yacc.c:1646  */
    {(yyval.num_ref) = (yyval.num_ref) + 1;}
#line 2079 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2083 "parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 326 "parser.y" /* yacc.c:1906  */

