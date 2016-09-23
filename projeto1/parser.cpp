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
#include "arvoreSintatica.h"
extern int yylex();
extern void yyerror(const char* s, ...);

#line 78 "parser.cpp" /* yacc.c:339  */

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
#line 14 "parser.y" /* yacc.c:355  */

    #include "arvoreSintatica.h"
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
    T_CAST = 292,
    INT = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 30 "parser.y" /* yacc.c:355  */

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

#line 181 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 196 "parser.cpp" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 20 "parser.y" /* yacc.c:359  */

    AST::Bloco *arvoreSintatica;
    AST::Tipo ultimoTipo;
    std::map<std::string, AST::Variavel*> tabela_simbolos;

#line 204 "parser.cpp" /* yacc.c:359  */

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
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   460

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    90,    90,    96,    97,   101,   107,   111,   114,   117,
     121,   124,   127,   130,   133,   137,   141,   145,   152,   155,
     158,   161,   164,   167,   171,   175,   176,   177,   181,   182,
     186,   189,   193,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   219,   220,   221,   222,   226
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
  "T_CAST_BOOL", "T_IF", "T_THEN", "T_ELSE", "T_FOR", "T_CAST", "INT",
  "$accept", "programa", "linhas", "linha", "laco", "condicao",
  "declaracao", "tipo", "variaveis", "variavel", "atribuicao", "expressao",
  "primitiva", "var", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -75

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-75)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     293,   -75,   -75,   -75,   -75,   -75,   327,    17,     1,   293,
     -75,    -8,    16,    18,    21,    20,   -10,   -75,   -75,   -75,
     327,   327,   327,   327,   327,   327,   343,   -75,   -75,   327,
      13,   -75,   -75,   -75,   -75,   -75,    23,   -75,   -75,   -10,
     -75,   327,   361,   413,   402,   402,   431,   431,   -28,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   375,   327,    21,   402,   -75,    22,   413,   413,   423,
     431,   402,   402,   402,   402,   402,   402,   402,   402,    -2,
     389,   -75,    24,    27,    28,    19,    64,   115,    30,    32,
      43,    25,   124,   -75,   133,   164,   173,    48,    49,    26,
     -75,   -75,   182,   -75,   213,   222,    54,    52,   -75,   -75,
     -75,   231,   262,    56,   -75,   -75,   271,   280,   -75,   -75,
     311,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    56,    25,    26,    27,     9,     0,     0,     0,     2,
       3,     0,     0,     0,     0,     0,     0,    55,    54,    53,
       0,     0,     0,     0,     0,     0,     0,    33,    52,     0,
       0,     1,     4,     8,     7,     6,    24,    28,    30,    31,
       5,     0,     0,    34,    35,    36,    37,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    39,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,    10,     0,     0,     0,     0,     0,    19,
      14,    11,     0,    12,     0,     0,     0,     0,    15,    16,
      13,     0,     0,     0,    17,    20,     0,     0,    21,    22,
       0,    23
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -75,   -75,   -74,    -1,   -75,   -75,   -75,   -75,   -75,     4,
      -4,    -5,   -75,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     8,     9,    10,    11,    12,    13,    14,    36,    37,
      15,    26,    27,    28
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,    31,    33,    30,     1,    41,    66,    16,    32,    16,
      38,    83,    92,    94,    39,    42,    43,    44,    45,    46,
      47,   102,   104,     1,    61,     1,    34,     1,    35,    62,
      40,   111,    89,    29,    86,    82,    64,    87,   116,    63,
      95,    88,    96,   120,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    97,    80,   105,    38,
      98,   107,   106,    39,   112,   113,   117,    81,     0,     0,
       1,     2,     3,     4,     5,    84,     0,     0,    91,    16,
       0,    90,     0,     0,     0,    16,    16,    16,     0,     0,
       0,    32,    16,    32,    16,    16,    16,     6,     0,     0,
       7,    32,    16,    32,    16,    16,     0,     0,     0,     0,
      32,    16,    16,     0,     0,    32,    16,    16,     0,    32,
      16,     1,     2,     3,     4,     5,     0,     0,     0,    93,
       1,     2,     3,     4,     5,     0,     0,     0,    99,     1,
       2,     3,     4,     5,     0,     0,     0,   100,     6,     0,
       0,     7,     0,     0,     0,     0,     0,     6,     0,     0,
       7,     0,     0,     0,     0,     0,     6,     0,     0,     7,
       1,     2,     3,     4,     5,     0,     0,     0,   101,     1,
       2,     3,     4,     5,     0,     0,     0,   103,     1,     2,
       3,     4,     5,     0,     0,     0,   108,     6,     0,     0,
       7,     0,     0,     0,     0,     0,     6,     0,     0,     7,
       0,     0,     0,     0,     0,     6,     0,     0,     7,     1,
       2,     3,     4,     5,     0,     0,     0,   109,     1,     2,
       3,     4,     5,     0,     0,     0,   110,     1,     2,     3,
       4,     5,     0,     0,     0,   114,     6,     0,     0,     7,
       0,     0,     0,     0,     0,     6,     0,     0,     7,     0,
       0,     0,     0,     0,     6,     0,     0,     7,     1,     2,
       3,     4,     5,     0,     0,     0,   115,     1,     2,     3,
       4,     5,     0,     0,     0,   118,     1,     2,     3,     4,
       5,     0,     0,     0,   119,     6,     0,     0,     7,     1,
       2,     3,     4,     5,     6,     0,     0,     7,     0,     0,
       0,     0,     0,     6,     0,     0,     7,     1,     2,     3,
       4,     5,     0,     0,     0,   121,     6,     0,     0,     7,
      17,    18,    19,     1,     0,     0,     0,     0,    20,     0,
       0,     0,     0,     0,     6,    21,     0,     7,    22,     0,
       0,     0,     0,    48,     0,     0,     0,    23,    24,    25,
      49,    50,    51,    52,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    65,     0,     0,     0,     0,    49,    50,
      51,    52,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    79,    49,    50,    51,    52,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    85,    49,    50,    51,    52,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    49,
      50,    51,    52,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    51,    52,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    52,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    53,    54,    55,    56,    57,    58,    59,
      60
};

static const yytype_int8 yycheck[] =
{
       0,     0,    10,     7,     6,    15,    34,     7,     9,     9,
      14,    13,    86,    87,    14,    20,    21,    22,    23,    24,
      25,    95,    96,     6,    29,     6,    10,     6,    10,    16,
      10,   105,    13,    16,    10,    13,    41,    10,   112,    16,
      10,    13,    10,   117,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    13,    62,    10,    63,
      35,    35,    13,    63,    10,    13,    10,    63,    -1,    -1,
       6,     7,     8,     9,    10,    79,    -1,    -1,    14,    79,
      -1,    85,    -1,    -1,    -1,    85,    86,    87,    -1,    -1,
      -1,    92,    92,    94,    94,    95,    96,    33,    -1,    -1,
      36,   102,   102,   104,   104,   105,    -1,    -1,    -1,    -1,
     111,   111,   112,    -1,    -1,   116,   116,   117,    -1,   120,
     120,     6,     7,     8,     9,    10,    -1,    -1,    -1,    14,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    14,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    14,    33,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    36,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    14,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    14,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    14,    33,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    36,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    14,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    14,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    14,    33,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    36,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    14,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    14,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    14,    33,    -1,    -1,    36,     6,
       7,     8,     9,    10,    33,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    36,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    14,    33,    -1,    -1,    36,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    33,    18,    -1,    36,    21,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    30,    31,    32,
      17,    18,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    12,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    20,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    22,    23,    24,    25,    26,    27,    28,
      29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    33,    36,    40,    41,
      42,    43,    44,    45,    46,    49,    52,     3,     4,     5,
      11,    18,    21,    30,    31,    32,    50,    51,    52,    16,
      49,     0,    42,    10,    10,    10,    47,    48,    49,    52,
      10,    15,    50,    50,    50,    50,    50,    50,    10,    17,
      18,    19,    20,    22,    23,    24,    25,    26,    27,    28,
      29,    50,    16,    16,    50,    12,    34,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    16,
      50,    48,    13,    13,    49,    16,    10,    10,    13,    13,
      49,    14,    41,    14,    41,    10,    10,    13,    35,    14,
      14,    14,    41,    14,    41,    10,    13,    35,    14,    14,
      14,    41,    10,    13,    14,    14,    41,    10,    14,    14,
      41,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    42,    42,    42,
      43,    43,    43,    43,    43,    43,    43,    43,    44,    44,
      44,    44,    44,    44,    45,    46,    46,    46,    47,    47,
      48,    48,    49,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    51,    51,    51,    51,    52
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     2,     2,     1,
       7,     8,     8,     9,     8,     9,     9,    10,     7,     8,
      11,    12,    12,    13,     2,     1,     1,     1,     1,     3,
       1,     1,     3,     1,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1
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
#line 90 "parser.y" /* yacc.c:1646  */
    { arvoreSintatica = (yyvsp[0].bloco); 
                   //$$->verificarTipo(AST::Tipo::nulo, AST::Tipo::nulo); 
                   (yyval.bloco)->imprimir();}
#line 1430 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 96 "parser.y" /* yacc.c:1646  */
    {  (yyval.bloco) = new AST::Bloco();  if((yyvsp[0].nodobase) != NULL) (yyval.bloco)->novaLinha((yyvsp[0].nodobase)); }
#line 1436 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 97 "parser.y" /* yacc.c:1646  */
    {  (yyval.bloco) = (yyvsp[-1].bloco);                if((yyvsp[0].nodobase) != NULL) (yyvsp[-1].bloco)->novaLinha((yyvsp[0].nodobase)); }
#line 1442 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 101 "parser.y" /* yacc.c:1646  */
    {  
                           (yyval.nodobase) = (yyvsp[-1].opBinaria);
                           (yyvsp[-1].opBinaria)->verificarSimbolos(tabela_simbolos); //Verifica se variável a esq e dir na atribuição já foi declarada  
                           (yyvsp[-1].opBinaria)->verificarTipo(tabela_simbolos[std::string(((AST::Variavel*)(yyvsp[-1].opBinaria)->esquerda)->id)]->tipo,((yyvsp[-1].opBinaria)->direita)->verificarTipo(AST::Tipo::nulo, AST::Tipo::nulo));//Verifica se o tipo da variável e da atribuição são equivalentes
                           //$$->imprimir(); 
                         }
#line 1453 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 107 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodobase) = (yyvsp[-1].declaracao);  
                           (yyvsp[-1].declaracao)->acrescentarSimbolos(tabela_simbolos, ultimoTipo);  
                           //$$->imprimir();  
                         }
#line 1462 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 111 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodobase) = (yyvsp[-1].condicao);
                           //$$->imprimir();  
                         }
#line 1470 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 114 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodobase) = (yyvsp[-1].laco);
                           //$$->imprimir(); 
                         }
#line 1478 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 117 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodobase) = NULL;  }
#line 1484 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco(NULL,(yyvsp[-4].nodobase),NULL,NULL); }
#line 1490 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 125 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco(NULL,(yyvsp[-5].nodobase),(yyvsp[-3].opBinaria),NULL); }
#line 1496 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco((yyvsp[-6].opBinaria),(yyvsp[-4].nodobase),NULL,NULL); }
#line 1502 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 131 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco((yyvsp[-7].opBinaria),(yyvsp[-5].nodobase),(yyvsp[-3].opBinaria),NULL); }
#line 1508 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco(NULL,(yyvsp[-5].nodobase),NULL,(yyvsp[-1].bloco)); }
#line 1514 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco((yyvsp[-6].nodobase),(yyvsp[-4].opBinaria),NULL,(yyvsp[-1].bloco)); }
#line 1520 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco((yyvsp[-7].opBinaria),(yyvsp[-5].nodobase),NULL,(yyvsp[-1].bloco)); }
#line 1526 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco((yyvsp[-8].opBinaria),(yyvsp[-6].nodobase),(yyvsp[-1].bloco),NULL); }
#line 1532 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao((yyvsp[-5].nodobase), NULL, NULL); }
#line 1538 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao((yyvsp[-6].nodobase), (yyvsp[-1].bloco), NULL ); }
#line 1544 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao((yyvsp[-9].nodobase), NULL, NULL ); }
#line 1550 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao((yyvsp[-10].nodobase), NULL, (yyvsp[-1].bloco) ); }
#line 1556 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao((yyvsp[-10].nodobase), (yyvsp[-5].bloco), NULL ); }
#line 1562 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao((yyvsp[-11].nodobase), (yyvsp[-6].bloco), (yyvsp[-1].bloco) ); }
#line 1568 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.declaracao) = new AST::Declaracao( (yyvsp[-1].tipo), (yyvsp[0].definicao) ); }
#line 1574 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = (yyvsp[0].tipo);  ultimoTipo = (yyvsp[0].tipo); }
#line 1580 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = (yyvsp[0].tipo);  ultimoTipo = (yyvsp[0].tipo); }
#line 1586 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = (yyvsp[0].tipo);  ultimoTipo = (yyvsp[0].tipo); }
#line 1592 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[0].definicao); }
#line 1598 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[-2].definicao);  (yyvsp[-2].definicao)->ajustarProxima((yyvsp[0].definicao)); }
#line 1604 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 186 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].opBinaria)->direita->verificarSimbolos(tabela_simbolos); // Variáveis a direita foram declaradas?
                        (yyvsp[0].opBinaria)->verificarTipo(ultimoTipo,(yyvsp[0].opBinaria)->direita->verificarTipo(AST::Tipo::nulo, AST::Tipo::nulo));   //
                        (yyval.definicao) = new AST::Definicao(((AST::Variavel*)(yyvsp[0].opBinaria)->esquerda), (yyvsp[0].opBinaria)->direita, NULL ); }
#line 1612 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::Definicao(((AST::Variavel*)(yyvsp[0].nodobase)), NULL, NULL ); }
#line 1618 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyval.opBinaria) = new AST::OperacaoBinaria( AST::Tipo::atribuicao, (yyvsp[-2].nodobase), (yyvsp[0].nodobase) ); }
#line 1624 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = (yyvsp[0].nodobase); }
#line 1630 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 198 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoUnaria( AST::Tipo::negacao         , (yyvsp[0].nodobase) ); }
#line 1636 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoUnaria( AST::Tipo::inversao        , (yyvsp[0].nodobase) ); }
#line 1642 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoUnaria( AST::Tipo::conversao_int   , (yyvsp[0].nodobase) ); }
#line 1648 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoUnaria( AST::Tipo::conversao_float , (yyvsp[0].nodobase) ); }
#line 1654 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoUnaria( AST::Tipo::conversao_bool  , (yyvsp[0].nodobase) ); }
#line 1660 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 203 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoUnaria( AST::Tipo::parenteses      , (yyvsp[-1].nodobase) ); }
#line 1666 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 204 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoBinaria( AST::Tipo::adicao         , (yyvsp[-2].nodobase),  (yyvsp[0].nodobase) ); }
#line 1672 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 205 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoBinaria( AST::Tipo::subtracao      , (yyvsp[-2].nodobase),  (yyvsp[0].nodobase) ); }
#line 1678 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoBinaria( AST::Tipo::multiplicacao  , (yyvsp[-2].nodobase),  (yyvsp[0].nodobase) ); }
#line 1684 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoBinaria( AST::Tipo::divisao        , (yyvsp[-2].nodobase),  (yyvsp[0].nodobase) ); }
#line 1690 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 208 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoBinaria( AST::Tipo::e              , (yyvsp[-2].nodobase),  (yyvsp[0].nodobase) ); }
#line 1696 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoBinaria( AST::Tipo::ou             , (yyvsp[-2].nodobase),  (yyvsp[0].nodobase) ); }
#line 1702 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoBinaria( AST::Tipo::igual          , (yyvsp[-2].nodobase),  (yyvsp[0].nodobase) ); }
#line 1708 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoBinaria( AST::Tipo::diferente      , (yyvsp[-2].nodobase),  (yyvsp[0].nodobase) ); }
#line 1714 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoBinaria( AST::Tipo::maior          , (yyvsp[-2].nodobase) , (yyvsp[0].nodobase) ); }
#line 1720 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoBinaria( AST::Tipo::maior_igual    , (yyvsp[-2].nodobase),  (yyvsp[0].nodobase) ); }
#line 1726 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoBinaria( AST::Tipo::menor          , (yyvsp[-2].nodobase),  (yyvsp[0].nodobase) ); }
#line 1732 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 215 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::OperacaoBinaria( AST::Tipo::menor_igual    , (yyvsp[-2].nodobase),  (yyvsp[0].nodobase) ); }
#line 1738 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 220 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::Boolean  ( AST::Tipo::boolean , (yyvsp[0].valor) ); }
#line 1744 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::Inteiro  ( AST::Tipo::inteiro , (yyvsp[0].valor) ); }
#line 1750 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::Real     ( AST::Tipo::real    , (yyvsp[0].valor) ); }
#line 1756 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.nodobase) = new AST::Variavel ( AST::Tipo::nulo , (yyvsp[0].valor) ); }
#line 1762 "parser.cpp" /* yacc.c:1646  */
    break;


#line 1766 "parser.cpp" /* yacc.c:1646  */
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
#line 228 "parser.y" /* yacc.c:1906  */

