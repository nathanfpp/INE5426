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


#line 114 "parser.cpp" /* yacc.c:355  */

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
#line 35 "parser.y" /* yacc.c:355  */

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

#line 198 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 213 "parser.cpp" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 23 "parser.y" /* yacc.c:359  */

    AST::Bloco *arvoreSintatica;
    AST::Tipo ultimoTipo;
    AST::TabelaDeSimbolos *escopoPrincipal = new AST::TabelaDeSimbolos();
    bool analisador = false;

#line 222 "parser.cpp" /* yacc.c:359  */

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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   567

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  285

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   114,   115,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   135,   136,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     154,   164,   165,   169,   173,   174,   175,   176,   180,   181,
     185,   189,   191,   193,   195,   200,   202,   207,   209,   214,
     216,   221,   222,   226,   227,   231,   235,   239,   240,   244,
     248,   253,   254,   258,   263,   264,   268,   273,   278,   279,
     283,   285,   287,   289,   294,   297,   301,   304,   310,   311,
     315,   316,   320,   321,   325,   326,   327,   328,   332,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   362,   363,   364,   368,   369,   370,   371,   375,
     376,   380,   381,   385,   385,   389
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_FLOAT", "T_INT", "T_BOOL", "T_VAR",
  "T_TYPE_INT", "T_TYPE_FLOAT", "T_TYPE_BOOL", "T_NL", "T_OPEN", "T_CLOSE",
  "T_OPEN_KEY", "T_CLOSE_KEY", "T_EQUAL", "T_COMMA", "T_SEMICOLON",
  "T_COLON", "T_PLUS", "T_MINUS", "T_TIMES", "T_DIV", "T_NOT", "T_AND",
  "T_OR", "T_EQUAL2", "T_DIF", "T_HIGHER", "T_HIGH", "T_LOWER", "T_LOW",
  "T_CAST_INT", "T_CAST_FLOAT", "T_CAST_BOOL", "T_ADDR", "T_IF", "T_THEN",
  "T_ELSE", "T_FOR", "T_FUN", "T_RET", "T_ATRIB_ASK", "T_DO", "T_WHILE",
  "T_REF", "T_CALC", "UMINUS", "T_CAST", "INT", "$accept", "programa",
  "linhas_i", "linha_i", "linhas", "linha", "atribuicao", "var_arranjo",
  "declaracao", "variaveis", "variavel", "def_arranjo", "dec_arranjo",
  "arranjo", "arranjo_duplo", "chamada", "arg_null", "argumentos",
  "argumento", "dec_hashes", "hashes", "def_hash", "condicao", "senao",
  "for_laco", "linhas_null", "do_while_laco", "while_laco", "atrib_null",
  "dec_funcao", "def_funcao", "linhas_funcao", "param_null", "parametros",
  "parametro", "retorno", "expressao", "tipo", "primitiva", "var", "hash",
  "referencia", "interpretacao", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -189

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-189)))

#define YYTABLE_NINF -32

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     188,    57,  -189,  -189,  -189,  -189,   250,    12,    71,   250,
    -189,   250,    69,   188,  -189,   119,     1,   125,   127,  -189,
     135,   144,   145,   147,   148,   151,     6,  -189,    19,   152,
     250,  -189,  -189,  -189,   250,   250,   250,   250,   250,   250,
     250,   313,  -189,   361,  -189,  -189,  -189,  -189,   149,   154,
     480,   523,  -189,  -189,  -189,   250,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,   160,   167,   132,   166,  -189,   164,
    -189,  -189,  -189,   169,    30,   170,  -189,  -189,   173,   171,
    -189,   523,   337,  -189,  -189,   523,  -189,  -189,  -189,  -189,
     155,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   284,   172,   523,   250,    42,    16,
     177,    31,   180,   250,  -189,   250,  -189,   250,   189,    93,
      93,  -189,   182,   536,   536,   131,   131,   131,   131,   131,
     131,   496,  -189,   124,  -189,   183,   191,   195,  -189,   196,
     197,   199,   200,   201,   202,   284,    47,   203,   208,  -189,
     210,   205,  -189,  -189,    32,   132,  -189,  -189,   250,   206,
    -189,   510,   209,    12,   178,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,   299,  -189,     3,   185,   212,
     217,    36,  -189,   224,   213,  -189,     5,   104,  -189,   250,
     284,   225,   250,  -189,  -189,   227,    38,   231,   132,   132,
    -189,   229,   132,   233,   132,  -189,  -189,  -189,    56,  -189,
       3,   421,   284,   226,   235,   523,  -189,  -189,   238,   234,
     240,   249,   213,   250,    36,   239,   248,  -189,   230,   284,
     132,   251,   252,   284,   381,  -189,   250,  -189,   256,  -189,
     261,   264,   267,   269,   284,   245,  -189,   250,   401,   270,
    -189,   274,   284,   284,   250,   441,  -189,   250,   284,   278,
     255,   258,   290,   523,  -189,   461,   287,   284,   250,   250,
     288,  -189,  -189,   263,   300,   301,  -189,   250,   307,   308,
     304,  -189,  -189,   311,  -189
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   119,   112,   113,   114,    16,     0,    69,     0,     0,
     123,     0,     0,     2,     3,     0,     0,     0,    32,     7,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     0,
      52,   118,   117,   116,     0,     0,     0,     0,     0,     0,
       0,   123,    90,     0,    89,   115,    68,    32,     0,     0,
       0,   125,     1,     4,     5,     0,     6,    14,    10,    11,
      12,    13,     8,     9,   119,     0,     0,     0,    38,    33,
      34,    36,    40,    39,     0,   120,   124,    15,     0,    51,
      53,    55,     0,    91,    92,    93,    94,    95,    98,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,    52,     0,     0,
       0,     0,   120,    52,    49,     0,    96,     0,     0,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,     0,    29,     0,    17,     0,     0,    32,    21,     0,
       0,     0,     0,     0,     0,     0,    89,     0,     0,   121,
       0,    56,    57,    59,     0,    81,    35,    37,    52,     0,
      54,     0,     0,    69,     0,    18,    19,    20,    28,    24,
      25,    26,    27,    22,    23,     0,    43,     0,     0,     0,
       0,     0,   122,     0,    80,    82,     0,    89,    50,     0,
      65,     0,     0,    67,   119,     0,     0,     0,    81,    81,
      58,    70,     0,   119,     0,    85,    86,    84,     0,    44,
       0,     0,    64,     0,     0,    66,    41,   120,     0,     0,
       0,     0,    83,     0,     0,   120,     0,   111,    62,    65,
      81,    71,    73,    79,     0,    87,     0,    42,     0,    60,
       0,     0,     0,     0,    78,     0,    45,     0,     0,     0,
      63,    72,    79,    79,     0,     0,    46,     0,    65,     0,
       0,     0,     0,    88,    47,     0,     0,    79,     0,     0,
       0,    48,    61,     0,     0,     0,    74,     0,     0,     0,
       0,    75,    77,     0,    76
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -189,  -189,  -189,   302,   -85,  -132,    13,  -189,    54,  -189,
     215,   219,  -189,  -189,  -189,    45,  -111,  -189,   216,    65,
    -189,   153,    66,  -189,   106,  -188,   108,   109,   174,   110,
     113,  -150,  -126,   130,  -189,  -141,    -6,   -56,  -103,    14,
     115,   -11,  -189
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,   244,   134,   135,    16,   136,    69,
      70,    71,    72,   205,   206,    42,    78,    79,    80,   138,
     151,   152,   139,   239,   140,   213,   141,   142,    48,   143,
     144,   245,   183,   184,   185,   262,    81,    26,    44,    45,
     153,    28,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,   165,   159,    50,   146,    51,    31,    32,    33,   194,
     109,   203,    64,    15,    27,    74,    55,    65,     1,   133,
      46,    27,   149,   204,    66,    75,    15,    27,    82,    83,
      84,    85,    86,    87,    88,    89,   112,    64,   182,    68,
      73,   240,   149,   165,   217,    18,    67,   159,    10,   106,
      10,    10,    47,   147,    17,   187,   150,    10,    18,   176,
     175,    10,   225,   177,    76,    19,    20,    17,    30,    52,
     266,    47,   219,   220,   195,    76,    10,    76,    19,    20,
     165,    10,   148,    76,    49,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   154,   186,
      74,    76,   260,   261,   241,   212,    21,   226,    22,    23,
      24,   161,   165,    25,    93,    94,   209,   273,    27,    21,
     210,    22,    23,    24,    68,    73,    25,   274,   275,    54,
       1,     2,     3,     4,   132,    56,   280,    57,   164,     2,
       3,     4,   186,   186,   212,    58,   186,    27,   224,   137,
      91,    92,    93,    94,    59,    60,    47,    61,    62,    27,
       6,    63,    77,     7,   104,   103,   196,     8,     9,    10,
     154,   107,   110,   212,   186,   208,    46,    27,   137,   108,
     111,   113,   145,   211,   -31,   114,   215,   115,   155,    27,
     137,   158,   118,   166,     1,     2,     3,     4,     5,   196,
     207,   167,   162,    93,    27,   168,   169,   170,    47,   171,
     172,   173,   174,   154,   179,   178,   180,   234,   188,   190,
     137,   181,   192,   198,     6,   197,    27,     7,   199,   202,
     248,     8,     9,    10,    11,   137,   201,   218,   214,   216,
     228,   255,   221,    27,   223,   229,   231,    27,   263,   230,
     236,   265,   232,    31,    32,    33,     1,   137,    27,   233,
     237,    34,   263,   263,   242,   243,    27,    27,   238,   249,
      35,   263,    27,    36,   137,   250,   251,   252,   137,   253,
     258,    27,    37,    38,    39,    40,   254,   259,   267,   137,
       1,     2,     3,     4,   132,    41,   268,   137,   137,   269,
     270,   272,   276,   137,   277,     1,     2,     3,     4,   132,
     278,   279,   137,   193,   283,    53,    31,    32,    33,     1,
       6,   281,   282,     7,    34,   284,   156,     8,     9,    10,
     157,   160,   222,    35,   200,     6,    36,   191,     7,   235,
       0,     0,     8,     9,    10,    37,    38,    39,    40,   116,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,    96,    97,    98,    99,   100,   101,   102,     0,
       0,    90,     0,     0,     0,     0,     0,     0,     0,   117,
      91,    92,    93,    94,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   246,     0,     0,     0,   247,     0,     0,
      91,    92,    93,    94,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   256,     0,     0,     0,   257,     0,     0,
      91,    92,    93,    94,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   227,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   264,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   271,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   105,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,    96,    97,    98,    99,   100,
     101,   102,   163,     0,     0,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   189,    91,
      92,    93,    94,     0,    95,    96,    97,    98,    99,   100,
     101,   102,    91,    92,    93,    94,     0,    95,    96,    97,
      98,    99,   100,   101,   102,    91,    92,    93,    94,     0,
       0,     0,    97,    98,    99,   100,   101,   102
};

static const yytype_int16 yycheck[] =
{
       6,   133,   113,     9,   107,    11,     3,     4,     5,     6,
      66,     6,     6,     0,     0,    26,    15,    11,     6,   104,
       7,     7,     6,    18,    18,     6,    13,    13,    34,    35,
      36,    37,    38,    39,    40,    41,     6,     6,     6,    26,
      26,   229,     6,   175,     6,     0,    40,   158,    45,    55,
      45,    45,     7,    11,     0,   158,    40,    45,    13,    12,
     145,    45,     6,    16,    45,     0,     0,    13,    11,     0,
     258,    26,   198,   199,   177,    45,    45,    45,    13,    13,
     212,    45,    40,    45,    13,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   109,   155,
     111,    45,   252,   253,   230,   190,     0,   210,     0,     0,
       0,   117,   244,     0,    21,    22,    12,   267,   104,    13,
      16,    13,    13,    13,   111,   111,    13,   268,   269,    10,
       6,     7,     8,     9,    10,    10,   277,    10,    14,     7,
       8,     9,   198,   199,   229,    10,   202,   133,   204,   104,
      19,    20,    21,    22,    10,    10,   111,    10,    10,   145,
      36,    10,    10,    39,    10,    16,   177,    43,    44,    45,
     181,    11,     6,   258,   230,   186,   163,   163,   133,    12,
      16,    11,    10,   189,    15,    12,   192,    16,    11,   175,
     145,    11,    37,    10,     6,     7,     8,     9,    10,   210,
     186,    10,    13,    21,   190,    10,    10,    10,   163,    10,
      10,    10,    10,   224,     6,    12,     6,   223,    12,    10,
     175,    16,    44,    11,    36,    40,   212,    39,    11,    16,
     236,    43,    44,    45,    46,   190,    12,     6,    13,    12,
      14,   247,    13,   229,    11,    10,    12,   233,   254,    11,
      11,   257,    12,     3,     4,     5,     6,   212,   244,    10,
      12,    11,   268,   269,    13,    13,   252,   253,    38,    13,
      20,   277,   258,    23,   229,    14,    12,    10,   233,    10,
      10,   267,    32,    33,    34,    35,    41,    13,    10,   244,
       6,     7,     8,     9,    10,    45,    41,   252,   253,    41,
      10,    14,    14,   258,    41,     6,     7,     8,     9,    10,
      10,    10,   267,    14,    10,    13,     3,     4,     5,     6,
      36,    14,    14,    39,    11,    14,   111,    43,    44,    45,
     111,   115,   202,    20,   181,    36,    23,   163,    39,   224,
      -1,    -1,    43,    44,    45,    32,    33,    34,    35,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    12,    -1,    -1,    -1,    16,    -1,    -1,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    12,    -1,    -1,    -1,    16,    -1,    -1,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    13,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    16,    -1,    -1,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    19,    20,    21,    22,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    36,    39,    43,    44,
      45,    46,    51,    52,    53,    56,    57,    58,    65,    69,
      72,    74,    76,    77,    79,    80,    87,    89,    91,    92,
      11,     3,     4,     5,    11,    20,    23,    32,    33,    34,
      35,    45,    65,    86,    88,    89,    56,    65,    78,    13,
      86,    86,     0,    53,    10,    15,    10,    10,    10,    10,
      10,    10,    10,    10,     6,    11,    18,    40,    56,    59,
      60,    61,    62,    89,    91,     6,    45,    10,    66,    67,
      68,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      10,    19,    20,    21,    22,    24,    25,    26,    27,    28,
      29,    30,    31,    16,    10,    13,    86,    11,    12,    87,
       6,    16,     6,    11,    12,    16,    12,    42,    37,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    10,    54,    55,    56,    58,    65,    69,    72,
      74,    76,    77,    79,    80,    10,    88,    11,    40,     6,
      40,    70,    71,    90,    91,    11,    60,    61,    11,    66,
      68,    86,    13,    16,    14,    55,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    54,    12,    16,    12,     6,
       6,    16,     6,    82,    83,    84,    87,    88,    12,    18,
      10,    78,    44,    14,     6,    88,    91,    40,    11,    11,
      71,    12,    16,     6,    18,    63,    64,    89,    91,    12,
      16,    86,    54,    75,    13,    86,    12,     6,     6,    82,
      82,    13,    83,    11,    87,     6,    88,    12,    14,    10,
      11,    12,    12,    10,    86,    90,    11,    12,    38,    73,
      75,    82,    13,    13,    54,    81,    12,    16,    86,    13,
      14,    12,    10,    10,    41,    86,    12,    16,    10,    13,
      81,    81,    85,    86,    12,    86,    75,    10,    41,    41,
      10,    12,    14,    81,    85,    85,    14,    41,    10,    10,
      85,    14,    14,    10,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    57,    57,    58,    59,    59,    59,    59,    60,    60,
      61,    62,    62,    62,    62,    63,    63,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    69,    70,    70,    71,
      72,    73,    73,    74,    75,    75,    76,    77,    78,    78,
      79,    79,    79,    79,    80,    80,    80,    80,    81,    81,
      82,    82,    83,    83,    84,    84,    84,    84,    85,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    87,    87,    87,    88,    88,    88,    88,    89,
      89,    90,    90,    91,    91,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     2,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     1,
       3,     1,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     6,     7,     4,     5,     4,     5,     6,     7,     4,
       5,     1,     0,     1,     3,     1,     4,     1,     3,     1,
       9,     5,     0,    10,     1,     0,     7,     6,     1,     0,
       6,     8,    10,     8,    13,    15,    17,    15,     1,     0,
       1,     0,     1,     3,     2,     2,     2,     4,     1,     1,
       1,     2,     2,     2,     2,     2,     3,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     7,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     1,     2,     2
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
#line 105 "parser.y" /* yacc.c:1646  */
    { std::cerr<<"";
                   arvoreSintatica = (yyvsp[0].bloco);
                   (yyval.bloco)->analisar(escopoPrincipal, 0, analisador);
                   (yyval.bloco)->imprimir(0, true);
		   std::cout <<"\n";
                  }
#line 1555 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = new AST::Bloco( AST::Tipo::bloco );  (yyval.bloco)->novaLinha((yyvsp[0].nodo)); }
#line 1561 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = (yyvsp[-1].bloco);                                  (yyvsp[-1].bloco)->novaLinha((yyvsp[0].nodo)); }
#line 1567 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].opBinaria);   }
#line 1573 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].declaracao);   }
#line 1579 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].declaracao_hash);   }
#line 1585 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].funcao);   }
#line 1591 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].funcao);   }
#line 1597 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].condicao);   }
#line 1603 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 125 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].laco);   }
#line 1609 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 126 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].laco);   }
#line 1615 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].laco);   }
#line 1621 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].nodo);   }
#line 1627 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].nodo);   }
#line 1633 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 130 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = NULL; }
#line 1639 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = new AST::Bloco( AST::Tipo::bloco );  (yyval.bloco)->novaLinha((yyvsp[0].nodo)); }
#line 1645 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = (yyvsp[-1].bloco);                                  (yyvsp[-1].bloco)->novaLinha((yyvsp[0].nodo)); }
#line 1651 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].opBinaria);   }
#line 1657 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].declaracao);   }
#line 1663 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].declaracao_hash);   }
#line 1669 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].funcao);   }
#line 1675 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].funcao);   }
#line 1681 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].condicao);   }
#line 1687 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].laco);   }
#line 1693 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].laco);   }
#line 1699 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].laco);   }
#line 1705 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].nodo);   }
#line 1711 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = NULL; }
#line 1717 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 155 "parser.y" /* yacc.c:1646  */
    { 
                if(((AST::Variavel*)(yyvsp[-2].nodo))->ponteiros > 0) {
                    ((AST::Variavel*)(yyvsp[-2].nodo))->ponteiroEsqAtribuicao = true;
                }
                (yyval.opBinaria) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::atribuicao, (yyvsp[-2].nodo), (yyvsp[0].nodo) ); 
            }
#line 1728 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1734 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1740 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.declaracao) = new AST::Declaracao( AST::Tipo::declaracao , (yyvsp[-1].tipo), (yyvsp[0].definicao) ); }
#line 1746 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[0].definicao);                          }
#line 1752 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[-2].definicao);  (yyvsp[-2].definicao)->ajustarProxima((yyvsp[0].definicao)); }
#line 1758 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[0].definicao);                          }
#line 1764 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[-2].definicao);  (yyvsp[-2].definicao)->ajustarProxima((yyvsp[0].definicao)); }
#line 1770 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::Definicao( AST::Tipo::definicao   , ((AST::Variavel*)(yyvsp[0].opBinaria)->esquerda) , (yyvsp[0].opBinaria)->direita , NULL ); }
#line 1776 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::Definicao( AST::Tipo::definicao   , ((AST::Variavel*)(yyvsp[0].nodo))           , NULL        , NULL ); }
#line 1782 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::DefinicaoDeArranjo( AST::Tipo::definicao_arranjo, (yyvsp[0].variavel), NULL , NULL ); }
#line 1788 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyval.variavel) = new AST::ArranjoDuplo( AST::Tipo::arranjo_duplo, AST::Tipo::nulo ,(yyvsp[-5].valores), (yyvsp[-3].nodo), (yyvsp[-1].nodo), 0 ); }
#line 1794 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.variavel) = new AST::ArranjoDuplo( AST::Tipo::arranjo_duplo, AST::Tipo::nulo ,(yyvsp[-5].valores), (yyvsp[-3].nodo), (yyvsp[-1].nodo), (yyvsp[-6].num_ref) ); }
#line 1800 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.variavel) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo ,(yyvsp[-3].valores), (yyvsp[-1].nodo),0 ); }
#line 1806 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 196 "parser.y" /* yacc.c:1646  */
    { (yyval.variavel) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo ,(yyvsp[-3].valores), (yyvsp[-1].nodo), (yyvsp[-4].num_ref) ); }
#line 1812 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 201 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo, (yyvsp[-3].valores), (yyvsp[-1].nodo), 0  );}
#line 1818 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 203 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo, (yyvsp[-3].valores), (yyvsp[-1].nodo), (yyvsp[-4].num_ref) ); }
#line 1824 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 208 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::ArranjoDuplo( AST::Tipo::arranjo_duplo, AST::Tipo::nulo , (yyvsp[-5].valores), (yyvsp[-3].nodo), (yyvsp[-1].nodo), 0 ); }
#line 1830 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 210 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::ArranjoDuplo( AST::Tipo::arranjo_duplo, AST::Tipo::nulo , (yyvsp[-5].valores), (yyvsp[-3].nodo), (yyvsp[-1].nodo), (yyvsp[-6].num_ref) ); }
#line 1836 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 215 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::Chamada ( AST::Tipo::nulo , AST::Tipo::chamada , (yyvsp[-3].valores) , (yyvsp[-1].parametro) , NULL, 0);}
#line 1842 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 217 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::Chamada ( AST::Tipo::nulo , AST::Tipo::chamada , (yyvsp[-3].valores) , (yyvsp[-1].parametro) , NULL, (yyvsp[-4].num_ref));}
#line 1848 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[0].parametro);   }
#line 1854 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = NULL; }
#line 1860 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[0].parametro);                   }
#line 1866 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 227 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[-2].parametro); (yyval.parametro)->proximo = (yyvsp[0].parametro); }
#line 1872 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, AST::Tipo::nulo, AST::Tipo::nulo, (yyvsp[0].nodo), NULL );  }
#line 1878 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 235 "parser.y" /* yacc.c:1646  */
    { (yyval.declaracao_hash) = new AST::DeclaracaoDeHash( AST::Tipo::declaracao_hash, (yyvsp[-3].tipo), (yyvsp[-1].tipo), (yyvsp[0].definicao) ); }
#line 1884 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 239 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[0].definicao);                          }
#line 1890 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 240 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[-2].definicao);  (yyvsp[-2].definicao)->ajustarProxima((yyvsp[0].definicao)); }
#line 1896 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 244 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::DefinicaoDeHash( AST::Tipo::definicao_hash, ((AST::Variavel*)(yyvsp[0].nodo)), NULL, NULL); }
#line 1902 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 249 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao( AST::Tipo::condicao , (yyvsp[-7].nodo), (yyvsp[-2].bloco), (yyvsp[0].bloco) ); }
#line 1908 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 253 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = (yyvsp[-1].bloco);   }
#line 1914 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 254 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = NULL; }
#line 1920 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 259 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::for_laco , (yyvsp[-8].opBinaria) , (yyvsp[-6].nodo) , (yyvsp[-4].opBinaria) , (yyvsp[-1].bloco) ); }
#line 1926 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 263 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = (yyvsp[0].bloco);   }
#line 1932 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = NULL; }
#line 1938 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 269 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::do_while_laco , NULL , (yyvsp[0].nodo) , NULL , (yyvsp[-3].bloco) ); }
#line 1944 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::while_laco , NULL , (yyvsp[-4].nodo) , NULL , (yyvsp[-1].bloco) ); }
#line 1950 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 278 "parser.y" /* yacc.c:1646  */
    { (yyval.opBinaria) = (yyvsp[0].opBinaria);   }
#line 1956 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 279 "parser.y" /* yacc.c:1646  */
    { (yyval.opBinaria) = NULL; }
#line 1962 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 284 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_dec, (yyvsp[-5].tipo) , (yyvsp[-3].valores) , (yyvsp[-1].parametro)); }
#line 1968 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 286 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_dec, escopoPrincipal->tipoDeArranjo((yyvsp[-7].tipo)) , (yyvsp[-3].valores) , (yyvsp[-1].parametro)); }
#line 1974 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 288 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_dec, escopoPrincipal->tipoDeArranjoDuplo((yyvsp[-9].tipo)) , (yyvsp[-3].valores) , (yyvsp[-1].parametro)); }
#line 1980 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 290 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_dec, escopoPrincipal->tipoDeHash((yyvsp[-7].tipo),(yyvsp[-5].tipo)) , (yyvsp[-3].valores) , (yyvsp[-1].parametro)); }
#line 1986 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 295 "parser.y" /* yacc.c:1646  */
    {  (yyvsp[-4].bloco)->novaLinha((yyvsp[-2].nodo)); 
                 (yyval.funcao) = new AST::DefinicaoDeFuncao( AST::Tipo::funcao_def, (yyvsp[-12].tipo) , (yyvsp[-10].valores) , (yyvsp[-8].parametro) , (yyvsp[-4].bloco), (yyvsp[-2].nodo)); }
#line 1993 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 298 "parser.y" /* yacc.c:1646  */
    {  (yyvsp[-4].bloco)->novaLinha((yyvsp[-2].nodo));
                 (yyval.funcao) = new AST::DefinicaoDeFuncao( AST::Tipo::funcao_def, escopoPrincipal->tipoDeArranjo((yyvsp[-14].tipo)) , (yyvsp[-10].valores) , (yyvsp[-8].parametro) , (yyvsp[-4].bloco), (yyvsp[-2].nodo)); 
              }
#line 2001 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 302 "parser.y" /* yacc.c:1646  */
    {  (yyvsp[-4].bloco)->novaLinha((yyvsp[-2].nodo));
                 (yyval.funcao) = new AST::DefinicaoDeFuncao( AST::Tipo::funcao_def, escopoPrincipal->tipoDeArranjoDuplo((yyvsp[-16].tipo)) , (yyvsp[-10].valores) , (yyvsp[-8].parametro) , (yyvsp[-4].bloco), (yyvsp[-2].nodo) ); }
#line 2008 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 305 "parser.y" /* yacc.c:1646  */
    {  (yyvsp[-4].bloco)->novaLinha((yyvsp[-2].nodo));
                 (yyval.funcao) = new AST::DefinicaoDeFuncao( AST::Tipo::funcao_def, escopoPrincipal->tipoDeHash((yyvsp[-14].tipo),(yyvsp[-12].tipo)) , (yyvsp[-10].valores) , (yyvsp[-8].parametro) , (yyvsp[-4].bloco), (yyvsp[-2].nodo) );  }
#line 2015 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 310 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = (yyvsp[0].bloco);                                 }
#line 2021 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 311 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = new AST::Bloco( AST::Tipo::bloco ); }
#line 2027 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 315 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[0].parametro);   }
#line 2033 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 316 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = NULL; }
#line 2039 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 320 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[0].parametro); }
#line 2045 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 321 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[-2].parametro); (yyval.parametro)->proximo = (yyvsp[0].parametro); }
#line 2051 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 325 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, (yyvsp[-1].tipo), AST::Tipo::nulo, (yyvsp[0].nodo), NULL );  }
#line 2057 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 326 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, (yyvsp[-1].tipo), AST::Tipo::nulo, (yyvsp[0].nodo), NULL );  }
#line 2063 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 327 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, (yyvsp[-1].tipo), AST::Tipo::nulo, (yyvsp[0].nodo), NULL );  }
#line 2069 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 328 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, (yyvsp[-1].tipo), (yyvsp[-3].tipo)             , (yyvsp[0].nodo), NULL );  }
#line 2075 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 332 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Retorno( AST::Tipo::retorno, (yyvsp[0].nodo)); }
#line 2081 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 336 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2087 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 337 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2093 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 338 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::negacao         , (yyvsp[0].nodo) ); }
#line 2099 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 339 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::inversao        , (yyvsp[0].nodo) ); }
#line 2105 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 340 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_int   , (yyvsp[0].nodo) ); }
#line 2111 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 341 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_float , (yyvsp[0].nodo) ); }
#line 2117 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 342 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_bool  , (yyvsp[0].nodo) ); }
#line 2123 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 343 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::parenteses      , (yyvsp[-1].nodo) ); }
#line 2129 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 344 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::referencia      , (yyvsp[0].nodo) ); }
#line 2135 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 345 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::endereco        , (yyvsp[0].nodo) ); }
#line 2141 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 346 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::adicao        , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2147 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 347 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::subtracao     , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2153 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 348 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::multiplicacao , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2159 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 349 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::divisao       , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2165 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 350 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::e             , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2171 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 351 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::ou            , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2177 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 352 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::igual         , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2183 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 353 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::diferente     , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2189 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 354 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::maior         , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2195 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 355 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::maior_igual   , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2201 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 356 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::menor         , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2207 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 357 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::menor_igual   , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2213 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 358 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoTernaria(AST::Tipo::opTernaria, new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::condicao_atribuicao, (yyvsp[-5].nodo) ),  new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::atribuicao_condicional, (yyvsp[-3].nodo), (yyvsp[-1].nodo))); }
#line 2219 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 362 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = AST::Tipo::inteiro;  ultimoTipo = (yyvsp[0].tipo); }
#line 2225 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 363 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = AST::Tipo::real;     ultimoTipo = (yyvsp[0].tipo); }
#line 2231 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 364 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = AST::Tipo::boolean;  ultimoTipo = (yyvsp[0].tipo); }
#line 2237 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 369 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Boolean  ( (yyvsp[0].valores) ); }
#line 2243 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 370 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Inteiro  ( (yyvsp[0].valores) ); }
#line 2249 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 371 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Real     ( (yyvsp[0].valores) ); }
#line 2255 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 375 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Variavel( AST::Tipo::variavel, AST::Tipo::nulo , (yyvsp[0].valores), 0 ); }
#line 2261 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 376 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Variavel( AST::Tipo::variavel, AST::Tipo::nulo, (yyvsp[0].valores), (yyvsp[-1].num_ref) ); }
#line 2267 "parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 380 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Hash( AST::Tipo::hash, AST::Tipo::nulo , (yyvsp[0].valores), 0 ); }
#line 2273 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 381 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Hash( AST::Tipo::hash, AST::Tipo::nulo, (yyvsp[0].valores), (yyvsp[-1].num_ref) ); }
#line 2279 "parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 385 "parser.y" /* yacc.c:1646  */
    {(yyval.num_ref) = (yyval.num_ref) + 1;}
#line 2285 "parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 389 "parser.y" /* yacc.c:1646  */
    { analisador = true; (yyval.nodo) = new AST::Interpretador(AST::Tipo::interpretador, (yyvsp[0].nodo)); }
#line 2291 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2295 "parser.cpp" /* yacc.c:1646  */
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
#line 391 "parser.y" /* yacc.c:1906  */

