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
    T_IF = 288,
    T_THEN = 289,
    T_ELSE = 290,
    T_FOR = 291,
    T_FUN = 292,
    T_RET = 293,
    T_EQUALS2 = 294,
    UMINUS = 295,
    T_CAST = 296,
    INT = 297
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

#line 188 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 203 "parser.cpp" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 22 "parser.y" /* yacc.c:359  */

    AST::Bloco *arvoreSintatica;
    AST::Tipo ultimoTipo;
    AST::TabelaDeSimbolos *escopoPrincipal = new AST::TabelaDeSimbolos();

#line 211 "parser.cpp" /* yacc.c:359  */

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
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   615

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   108,   109,   113,   114,   115,   116,   117,
     118,   119,   120,   124,   128,   129,   133,   137,   138,   139,
     140,   144,   145,   149,   153,   157,   161,   164,   169,   175,
     178,   181,   184,   187,   190,   196,   199,   202,   205,   208,
     211,   214,   217,   222,   225,   230,   233,   236,   239,   244,
     245,   249,   253,   256,   261,   262,   266,   270,   271,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     299,   300,   301,   305,   306,   307,   308,   312
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
  "T_CAST_BOOL", "T_IF", "T_THEN", "T_ELSE", "T_FOR", "T_FUN", "T_RET",
  "T_EQUALS2", "UMINUS", "T_CAST", "INT", "$accept", "programa", "linhas",
  "linha", "atribuicao", "var_arranjo", "declaracao", "variaveis",
  "variavel", "def_arranjo", "dec_arranjo", "arranjo", "cha_funcao",
  "funcao_arranjo", "condicao", "laco", "dec_funcao", "def_funcao",
  "parametros", "parametro", "argumentos", "argumento", "retorno",
  "expressao", "tipo", "primitiva", "var", YY_NULLPTR
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
     295,   296,   297
};
# endif

#define YYPACT_NINF -126

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-126)))

#define YYTABLE_NINF -15

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      89,    -5,  -126,  -126,  -126,  -126,   480,     2,    28,    89,
    -126,    36,    52,    58,  -126,    60,    63,    77,    78,    84,
       7,  -126,   458,  -126,  -126,  -126,    91,   480,   480,   480,
     480,   480,   480,  -126,  -126,   238,  -126,  -126,    94,   480,
      95,  -126,  -126,  -126,   480,  -126,  -126,  -126,  -126,  -126,
    -126,    99,   107,  -126,    98,  -126,  -126,  -126,    85,  -126,
      14,  -126,   496,   458,   514,   105,   105,   573,   105,   105,
      96,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   546,   480,   573,   480,   112,   130,
    -126,   480,  -126,   532,  -126,   124,    88,    88,   105,    40,
     586,   586,   573,    62,    62,    62,    62,    62,   496,    25,
     560,   133,     3,  -126,  -126,  -126,   573,  -126,   142,   149,
     147,    49,  -126,   151,    45,  -126,   156,   110,   125,   155,
     161,   153,   162,   160,    83,  -126,  -126,   145,   236,  -126,
     288,   297,   306,   167,    15,   172,  -126,   171,   157,  -126,
    -126,   337,  -126,   346,   355,   144,    27,    33,   180,   182,
    -126,  -126,  -126,   386,   183,  -126,  -126,   144,   144,    68,
     395,   187,  -126,   188,   195,   197,   144,  -126,   404,   435,
    -126,   194,   199,   201,  -126,  -126,   444,  -126,  -126,   204,
    -126,  -126
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    87,    80,    81,    82,    12,     0,     0,     0,     2,
       3,     0,     0,     0,    15,     0,     0,     0,     0,     0,
       0,    14,     0,    86,    85,    84,    87,     0,     0,     0,
       0,     0,     0,    60,    61,     0,    59,    83,    87,     0,
       0,     1,     4,     5,     0,     6,    11,     7,     8,     9,
      10,    87,     0,    21,    16,    17,    19,    23,    22,    26,
       0,    54,    56,     0,     0,    62,    63,    64,    65,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,     0,     0,     0,
      27,     0,    25,    56,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,     0,
       0,    59,     0,    18,    20,    55,    56,    28,     0,     0,
       0,     0,    24,    43,     0,    49,     0,     0,     0,     0,
       0,     0,     0,    44,     0,    87,    51,    29,     0,    35,
       0,     0,     0,     0,     0,     0,    50,     0,    30,    39,
      36,     0,    37,     0,     0,     0,     0,     0,     0,     0,
      40,    41,    38,     0,     0,    57,    58,     0,     0,     0,
       0,     0,    42,     0,     0,     0,     0,    31,     0,     0,
      45,     0,     0,     0,    32,    33,     0,    46,    47,     0,
      34,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -125,    43,    -6,  -126,  -126,  -126,   120,   126,
    -126,  -126,    47,  -126,  -126,  -126,  -126,  -126,  -126,    86,
    -126,   128,  -118,   208,  -107,   -83,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    11,    12,    13,    54,    55,    56,
      57,    14,    33,    34,    16,    17,    18,    19,   124,   125,
      60,    61,   164,   108,    20,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    40,   138,   140,   111,   126,    22,    21,    38,    21,
       2,     3,     4,    51,    53,   123,   151,   153,    39,   156,
      58,     1,     2,     3,     4,     5,    90,   126,    41,   163,
      91,    38,   169,     1,     2,     3,     4,     5,   119,     1,
       2,     3,     4,     5,    52,   178,    43,    15,     6,   174,
     175,     7,    42,   155,   186,    38,    15,   133,   183,    73,
       6,   134,   130,     7,    77,   167,     6,    44,    45,     7,
      46,   168,   165,    47,     1,     2,     3,     4,     5,    71,
      72,    73,    74,    53,   165,   165,    77,    48,    49,    58,
       2,     3,     4,   165,    50,     1,     2,     3,     4,     5,
     -14,     6,    63,   120,     7,    83,   176,    73,    74,    21,
      87,    85,    77,    88,    89,   131,     1,     2,     3,     4,
       5,    21,     6,   112,   137,     7,   136,    21,    21,    77,
      95,     1,     2,     3,     4,     5,    51,   118,    21,   139,
      21,    21,    21,     6,    21,   122,     7,    23,    24,    25,
     135,    21,   127,    21,    21,   166,    21,    21,     6,   128,
     129,     7,   135,    21,   132,   141,   143,   166,   166,    21,
      21,   142,   144,   145,    15,    15,   166,   154,    21,    21,
     147,    42,   157,    42,   158,    15,    21,    15,    15,    15,
     170,    15,   159,   173,    42,   171,    42,   179,    15,    42,
      15,    15,   180,    15,    15,   181,    42,   182,   187,   113,
      15,   189,    42,   188,    35,   114,    15,    15,   191,   115,
     146,    42,     0,     0,     0,    15,    15,     0,     0,    42,
      62,     0,     0,    15,     0,    64,    65,    66,    67,    68,
      69,     0,     1,     2,     3,     4,     5,    84,    70,     0,
     148,     0,    86,     0,     0,    71,    72,    73,    74,     0,
      75,    76,    77,    78,    79,    80,    81,    82,     0,     6,
       0,    93,     7,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,     0,   110,     1,     2,     3,     4,     5,   116,
       0,     0,   149,     1,     2,     3,     4,     5,     0,     0,
       0,   150,     1,     2,     3,     4,     5,     0,     0,     0,
     152,     6,     0,     0,     7,     0,     0,     0,     0,     0,
       6,     0,     0,     7,     0,     0,     0,     0,     0,     6,
       0,     0,     7,     1,     2,     3,     4,     5,     0,     0,
       0,   160,     1,     2,     3,     4,     5,     0,     0,     0,
     161,     1,     2,     3,     4,     5,     0,     0,     0,   162,
       6,     0,     0,     7,     0,     0,     0,     0,     0,     6,
       0,     0,     7,     0,     0,     0,     0,     0,     6,     0,
       0,     7,     1,     2,     3,     4,     5,     0,     0,     0,
     172,     1,     2,     3,     4,     5,     0,     0,     0,   177,
       1,     2,     3,     4,     5,     0,     0,     0,   184,     6,
       0,     0,     7,     0,     0,     0,     0,     0,     6,     0,
       0,     7,     0,     0,     0,     0,     0,     6,     0,     0,
       7,     1,     2,     3,     4,     5,     0,     0,     0,   185,
       1,     2,     3,     4,     5,     0,     0,     0,   190,     0,
       0,    23,    24,    25,    26,     0,     0,     0,     6,    27,
      59,     7,     0,     0,     0,     0,    28,     6,     0,    29,
       7,     0,     0,    23,    24,    25,    26,     0,    30,    31,
      32,    27,     0,     0,     0,     0,     0,     0,    28,     0,
       0,    29,     0,     0,     0,     0,     0,     0,    92,     0,
      30,    31,    32,    71,    72,    73,    74,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    94,     0,     0,     0,
       0,    71,    72,    73,    74,     0,    75,    76,    77,    78,
      79,    80,    81,    82,   117,     0,     0,     0,     0,    71,
      72,    73,    74,     0,    75,    76,    77,    78,    79,    80,
      81,    82,   109,    71,    72,    73,    74,     0,    75,    76,
      77,    78,    79,    80,    81,    82,   121,    71,    72,    73,
      74,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      71,    72,    73,    74,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    71,    72,    73,    74,     0,     0,     0,
      77,    78,    79,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
       0,     7,   127,   128,    87,   112,    11,     7,     6,     9,
       7,     8,     9,     6,    20,    12,   141,   142,    16,   144,
      20,     6,     7,     8,     9,    10,    12,   134,     0,   154,
      16,     6,   157,     6,     7,     8,     9,    10,    13,     6,
       7,     8,     9,    10,    37,   170,    10,     0,    33,   167,
     168,    36,     9,    38,   179,     6,     9,    12,   176,    19,
      33,    16,    13,    36,    24,    38,    33,    15,    10,    36,
      10,    38,   155,    10,     6,     7,     8,     9,    10,    17,
      18,    19,    20,    89,   167,   168,    24,    10,    10,    89,
       7,     8,     9,   176,    10,     6,     7,     8,     9,    10,
      15,    33,    11,   109,    36,    11,    38,    19,    20,   109,
      11,    16,    24,     6,    16,   121,     6,     7,     8,     9,
      10,   121,    33,    11,    14,    36,   126,   127,   128,    24,
      34,     6,     7,     8,     9,    10,     6,    13,   138,    14,
     140,   141,   142,    33,   144,    12,    36,     3,     4,     5,
       6,   151,    10,   153,   154,   155,   156,   157,    33,    10,
      13,    36,     6,   163,    13,    10,    13,   167,   168,   169,
     170,    10,    10,    13,   127,   128,   176,    10,   178,   179,
      35,   138,    10,   140,    13,   138,   186,   140,   141,   142,
      10,   144,    35,    10,   151,    13,   153,    10,   151,   156,
     153,   154,    14,   156,   157,    10,   163,    10,    14,    89,
     163,    10,   169,    14,     6,    89,   169,   170,    14,    91,
     134,   178,    -1,    -1,    -1,   178,   179,    -1,    -1,   186,
      22,    -1,    -1,   186,    -1,    27,    28,    29,    30,    31,
      32,    -1,     6,     7,     8,     9,    10,    39,    10,    -1,
      14,    -1,    44,    -1,    -1,    17,    18,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    33,
      -1,    63,    36,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    -1,    85,     6,     7,     8,     9,    10,    91,
      -1,    -1,    14,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    14,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      14,    33,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    36,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    14,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      14,     6,     7,     8,     9,    10,    -1,    -1,    -1,    14,
      33,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    36,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      14,     6,     7,     8,     9,    10,    -1,    -1,    -1,    14,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    14,    33,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      36,     6,     7,     8,     9,    10,    -1,    -1,    -1,    14,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    14,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    33,    11,
      12,    36,    -1,    -1,    -1,    -1,    18,    33,    -1,    21,
      36,    -1,    -1,     3,     4,     5,     6,    -1,    30,    31,
      32,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      30,    31,    32,    17,    18,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    12,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    12,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    16,    17,    18,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    16,    17,    18,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      17,    18,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    17,    18,    19,    20,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    33,    36,    44,    45,
      46,    47,    48,    49,    54,    55,    57,    58,    59,    60,
      67,    69,    11,     3,     4,     5,     6,    11,    18,    21,
      30,    31,    32,    55,    56,    66,    68,    69,     6,    16,
      47,     0,    46,    10,    15,    10,    10,    10,    10,    10,
      10,     6,    37,    47,    50,    51,    52,    53,    69,    12,
      63,    64,    66,    11,    66,    66,    66,    66,    66,    66,
      10,    17,    18,    19,    20,    22,    23,    24,    25,    26,
      27,    28,    29,    11,    66,    16,    66,    11,     6,    16,
      12,    16,    12,    66,    12,    34,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    16,
      66,    68,    11,    51,    52,    64,    66,    12,    13,    13,
      47,    16,    12,    12,    61,    62,    67,    10,    10,    13,
      13,    47,    13,    12,    16,     6,    69,    14,    45,    14,
      45,    10,    10,    13,    10,    13,    62,    35,    14,    14,
      14,    45,    14,    45,    10,    38,    45,    10,    13,    35,
      14,    14,    14,    45,    65,    68,    69,    38,    38,    45,
      10,    13,    14,    10,    65,    65,    38,    14,    45,    10,
      14,    10,    10,    65,    14,    14,    45,    14,    14,    10,
      14,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    47,    48,    48,    49,    50,    50,    50,
      50,    51,    51,    52,    53,    54,    55,    55,    56,    57,
      57,    57,    57,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    59,    60,    60,    60,    60,    61,
      61,    62,    55,    55,    63,    63,    64,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      67,    67,    67,    68,    68,    68,    68,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     3,     1,     1,     2,     1,     3,     1,
       3,     1,     1,     1,     4,     4,     3,     4,     4,     7,
       8,    11,    12,    12,    13,     7,     8,     8,     9,     8,
       9,     9,    10,     5,     6,    11,    12,    12,    13,     1,
       3,     2,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1
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
#line 101 "parser.y" /* yacc.c:1646  */
    { arvoreSintatica = (yyvsp[0].bloco);
                   (yyval.bloco)->analisar(escopoPrincipal, 0);
                   (yyval.bloco)->imprimir(0, true);
		   std::cout <<"\n";}
#line 1504 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 108 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = new AST::Bloco( AST::Tipo::bloco );  (yyval.bloco)->novaLinha((yyvsp[0].nodo)); }
#line 1510 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 109 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = (yyvsp[-1].bloco);                                  (yyvsp[-1].bloco)->novaLinha((yyvsp[0].nodo)); }
#line 1516 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 113 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].opBinaria); }
#line 1522 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].declaracao);   }
#line 1528 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].condicao);   }
#line 1534 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].laco);   }
#line 1540 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].funcao);   }
#line 1546 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].funcao);   }
#line 1552 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].funcao);   }
#line 1558 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = NULL; }
#line 1564 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.opBinaria) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::atribuicao, (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 1570 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1576 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1582 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyval.declaracao) = new AST::Declaracao( AST::Tipo::declaracao , (yyvsp[-1].tipo), (yyvsp[0].definicao) ); }
#line 1588 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 137 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[0].definicao); }
#line 1594 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[-2].definicao);  (yyvsp[-2].definicao)->ajustarProxima((yyvsp[0].definicao)); }
#line 1600 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[0].definicao); }
#line 1606 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[-2].definicao);  (yyvsp[-2].definicao)->ajustarProxima((yyvsp[0].definicao)); }
#line 1612 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::Definicao( AST::Tipo::definicao   , ((AST::Variavel*)(yyvsp[0].opBinaria)->esquerda) , (yyvsp[0].opBinaria)->direita , NULL ); }
#line 1618 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::Definicao( AST::Tipo::definicao   , ((AST::Variavel*)(yyvsp[0].nodo))           , NULL        , NULL ); }
#line 1624 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 149 "parser.y" /* yacc.c:1646  */
    {(yyval.definicao) = new AST::DefinicaoArranjo( AST::Tipo::definicao_arranjo, (yyvsp[0].variavel), NULL , NULL ); }
#line 1630 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.variavel) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo , (yyvsp[-3].valor), (yyvsp[-1].nodo) ); }
#line 1636 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo , (yyvsp[-3].valor), (yyvsp[-1].nodo) ); }
#line 1642 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_cha, AST::Tipo::nulo , (yyvsp[-2].valor) , NULL , NULL , NULL ); }
#line 1648 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_cha, AST::Tipo::nulo , (yyvsp[-3].valor) , (yyvsp[-1].parametro) , NULL , NULL ); }
#line 1654 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::ChamadaOuArranjo( AST::Tipo::nulo, AST::Tipo::nulo , (yyvsp[-3].valor) , new AST::Parametro( AST::Tipo::parametro, AST::Tipo::nulo, (yyvsp[-1].nodo), NULL ) , NULL , NULL ); }
#line 1660 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao( AST::Tipo::condicao , (yyvsp[-5].nodo), NULL, NULL); }
#line 1666 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao( AST::Tipo::condicao , (yyvsp[-6].nodo), (yyvsp[-1].bloco), NULL ); }
#line 1672 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao( AST::Tipo::condicao , (yyvsp[-9].nodo), NULL, NULL ); }
#line 1678 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao( AST::Tipo::condicao , (yyvsp[-10].nodo), NULL, (yyvsp[-1].bloco) ); }
#line 1684 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 188 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao( AST::Tipo::condicao , (yyvsp[-10].nodo), (yyvsp[-5].bloco), NULL ); }
#line 1690 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao( AST::Tipo::condicao , (yyvsp[-11].nodo), (yyvsp[-6].bloco), (yyvsp[-1].bloco) ); }
#line 1696 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::laco , NULL , (yyvsp[-4].nodo) , NULL , NULL ); }
#line 1702 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::laco , NULL , (yyvsp[-5].nodo) , (yyvsp[-3].opBinaria) , NULL ); }
#line 1708 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 203 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::laco , (yyvsp[-6].opBinaria) , (yyvsp[-4].nodo) , NULL , NULL ); }
#line 1714 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::laco , (yyvsp[-7].opBinaria) , (yyvsp[-5].nodo) , (yyvsp[-3].opBinaria) , NULL ); }
#line 1720 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::laco , NULL , (yyvsp[-5].nodo) , NULL , (yyvsp[-1].bloco) ); }
#line 1726 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::laco , NULL , (yyvsp[-6].nodo) , (yyvsp[-4].opBinaria) , (yyvsp[-1].bloco) ); }
#line 1732 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 215 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::laco , (yyvsp[-7].opBinaria) , (yyvsp[-5].nodo) , NULL , (yyvsp[-1].bloco) ); }
#line 1738 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::laco , (yyvsp[-8].opBinaria) , (yyvsp[-6].nodo) , (yyvsp[-4].opBinaria) , (yyvsp[-1].bloco) ); }
#line 1744 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_dec, (yyvsp[-4].tipo) , (yyvsp[-2].valor) , NULL , NULL , NULL); }
#line 1750 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_dec, (yyvsp[-5].tipo) , (yyvsp[-3].valor) , (yyvsp[-1].parametro)   , NULL , NULL); }
#line 1756 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_def, (yyvsp[-10].tipo) , (yyvsp[-8].valor) , NULL , NULL , (yyvsp[-2].nodo)  ); }
#line 1762 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_def, (yyvsp[-11].tipo) , (yyvsp[-9].valor) , NULL , (yyvsp[-4].bloco)   , (yyvsp[-2].nodo) ); }
#line 1768 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 237 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_def, (yyvsp[-11].tipo) , (yyvsp[-9].valor) , (yyvsp[-7].parametro)   , NULL , (yyvsp[-2].nodo) ); }
#line 1774 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 240 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_def, (yyvsp[-12].tipo) , (yyvsp[-10].valor) , (yyvsp[-8].parametro)   , (yyvsp[-4].bloco)   , (yyvsp[-2].nodo) ); }
#line 1780 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[0].parametro); }
#line 1786 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 245 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[-2].parametro); (yyval.parametro)->proximo = (yyvsp[0].parametro); }
#line 1792 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, (yyvsp[-1].tipo), (yyvsp[0].nodo), NULL );  }
#line 1798 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 254 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_cha, AST::Tipo::nulo , (yyvsp[-2].valor) , NULL , NULL , NULL ); }
#line 1804 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 257 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_cha, AST::Tipo::nulo , (yyvsp[-3].valor) , (yyvsp[-1].parametro)   , NULL , NULL ); }
#line 1810 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[0].parametro);                   }
#line 1816 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 262 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[-2].parametro); (yyval.parametro)->proximo = (yyvsp[0].parametro); }
#line 1822 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 266 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, AST::Tipo::nulo, (yyvsp[0].nodo), NULL );  }
#line 1828 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 270 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1834 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 271 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1840 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 275 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1846 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 276 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].funcao); }
#line 1852 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 277 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1858 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 278 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::negacao         , (yyvsp[0].nodo) ); }
#line 1864 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 279 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::inversao        , (yyvsp[0].nodo) ); }
#line 1870 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 280 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_int   , (yyvsp[0].nodo) ); }
#line 1876 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 281 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_float , (yyvsp[0].nodo) ); }
#line 1882 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 282 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_bool  , (yyvsp[0].nodo) ); }
#line 1888 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 283 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::parenteses      , (yyvsp[-1].nodo) ); }
#line 1894 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 284 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::adicao         , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1900 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 285 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::subtracao      , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1906 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 286 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::multiplicacao  , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1912 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 287 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::divisao        , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1918 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 288 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::e              , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1924 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 289 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::ou             , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1930 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 290 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::igual          , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1936 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 291 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::diferente      , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1942 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 292 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::maior          , (yyvsp[-2].nodo) , (yyvsp[0].nodo) ); }
#line 1948 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 293 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::maior_igual    , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1954 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 294 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::menor          , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1960 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 295 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::menor_igual    , (yyvsp[-2].nodo),  (yyvsp[0].nodo) ); }
#line 1966 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 299 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = AST::Tipo::inteiro;  ultimoTipo = (yyvsp[0].tipo); }
#line 1972 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 300 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = AST::Tipo::real;     ultimoTipo = (yyvsp[0].tipo); }
#line 1978 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 301 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = AST::Tipo::boolean;  ultimoTipo = (yyvsp[0].tipo); }
#line 1984 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 306 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Boolean  ( (yyvsp[0].valor) ); (yyval.nodo)->tipo = AST::Tipo::boolean; }
#line 1990 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 307 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Inteiro  ( (yyvsp[0].valor) ); (yyval.nodo)->tipo = AST::Tipo::inteiro; }
#line 1996 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 308 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Real     ( (yyvsp[0].valor) ); (yyval.nodo)->tipo = AST::Tipo::real;    }
#line 2002 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 312 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Variavel( AST::Tipo::variavel, AST::Tipo::nulo , (yyvsp[0].valor) ); }
#line 2008 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2012 "parser.cpp" /* yacc.c:1646  */
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
#line 314 "parser.y" /* yacc.c:1906  */

