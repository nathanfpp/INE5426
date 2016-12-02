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

#include "arvoreSintatica.h"
extern int yylex();
extern void yyerror(const char* s, ...);

#line 72 "parser.cpp" /* yacc.c:339  */

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
#line 9 "parser.y" /* yacc.c:355  */

    #include "arvoreSintatica.h"


#line 107 "parser.cpp" /* yacc.c:355  */

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
    T_COLON = 272,
    T_PLUS = 273,
    T_MINUS = 274,
    T_TIMES = 275,
    T_DIV = 276,
    T_NOT = 277,
    T_AND = 278,
    T_OR = 279,
    T_EQUAL2 = 280,
    T_DIF = 281,
    T_HIGHER = 282,
    T_HIGH = 283,
    T_LOWER = 284,
    T_LOW = 285,
    T_CAST_INT = 286,
    T_CAST_FLOAT = 287,
    T_CAST_BOOL = 288,
    T_ADDR = 289,
    T_IF = 290,
    T_THEN = 291,
    T_ELSE = 292,
    T_SWITCH = 293,
    T_CASE = 294,
    T_DEFAULT = 295,
    T_FOR = 296,
    T_FUN = 297,
    T_RET = 298,
    T_ATRIB_ASK = 299,
    T_DO = 300,
    T_WHILE = 301,
    T_REF = 302,
    T_CALC = 303,
    UMINUS = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 27 "parser.y" /* yacc.c:355  */

    AST::atributo_nodo valores;
    AST::Nodo *nodo;
    AST::Variavel *variavel;
    AST::Declaracao *declaracao;
    AST::Definicao *definicao;
    AST::DefinicaoDeArranjo *definicaoDeArranjo;
    AST::OperacaoUnaria *opUnaria;
    AST::OperacaoBinaria *opBinaria;
    AST::DeclaracaoDeHash *declaracao_hash;
    AST::Condicao *condicao;
    AST::Switch *selecionador;
    AST::Laco *laco;
    AST::Funcao *funcao;
    AST::Parametro *parametro;
    AST::Bloco *bloco;
    AST::Tipo tipo;
    int num_ref;

#line 189 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "parser.cpp" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 16 "parser.y" /* yacc.c:359  */

    AST::Bloco *arvoreSintatica;
    AST::TabelaDeSimbolos *escopoPrincipal = new AST::TabelaDeSimbolos();
    bool analisador = false;

#line 212 "parser.cpp" /* yacc.c:359  */

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
#define YYFINAL  55
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   692

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  284

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
       0,    98,    98,   108,   109,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   129,   139,
     140,   141,   142,   146,   150,   151,   152,   153,   157,   158,
     159,   163,   168,   170,   172,   174,   180,   182,   187,   189,
     194,   200,   201,   205,   206,   210,   214,   218,   219,   223,
     227,   232,   233,   238,   244,   247,   251,   257,   262,   263,
     267,   272,   277,   278,   282,   284,   286,   288,   293,   296,
     300,   303,   309,   310,   314,   315,   319,   320,   324,   326,
     327,   328,   329,   333,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   363,   364,   365,
     369,   370,   371,   372,   376,   380,   381,   385,   385,   389
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_FLOAT", "T_INT", "T_BOOL", "T_VAR",
  "T_TYPE_INT", "T_TYPE_FLOAT", "T_TYPE_BOOL", "T_NL", "T_OPEN", "T_CLOSE",
  "T_OPEN_KEY", "T_CLOSE_KEY", "T_EQUAL", "T_COMMA", "T_COLON", "T_PLUS",
  "T_MINUS", "T_TIMES", "T_DIV", "T_NOT", "T_AND", "T_OR", "T_EQUAL2",
  "T_DIF", "T_HIGHER", "T_HIGH", "T_LOWER", "T_LOW", "T_CAST_INT",
  "T_CAST_FLOAT", "T_CAST_BOOL", "T_ADDR", "T_IF", "T_THEN", "T_ELSE",
  "T_SWITCH", "T_CASE", "T_DEFAULT", "T_FOR", "T_FUN", "T_RET",
  "T_ATRIB_ASK", "T_DO", "T_WHILE", "T_REF", "T_CALC", "UMINUS", "$accept",
  "programa", "linhas", "linha", "atribuicao", "var_arranjo", "declaracao",
  "variaveis", "variavel", "def_arranjo", "dec_arranjo", "arranjo",
  "arranjo_duplo", "chamada", "arg_null", "argumentos", "argumento",
  "dec_hashes", "hashes", "def_hash", "condicao", "senao", "seleciona",
  "caso", "for_laco", "linhas_null", "do_while_laco", "while_laco",
  "atrib_null", "dec_funcao", "def_funcao", "linhas_funcao", "param_null",
  "parametros", "parametro", "retorno", "expressao", "tipo", "primitiva",
  "var", "hash", "referencia", "interpretacao", YY_NULLPTR
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

#define YYPACT_NINF -239

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-239)))

#define YYTABLE_NINF -22

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     415,   -10,  -239,  -239,  -239,  -239,    42,    27,    10,    -1,
      42,  -239,    42,    20,   415,  -239,    33,     8,    55,    60,
    -239,    62,    72,    78,    92,    94,    97,   100,    -3,  -239,
      11,   114,    42,  -239,  -239,  -239,    42,    42,    42,    42,
      42,    42,    42,    42,  -239,   475,  -239,  -239,    42,  -239,
    -239,   117,   125,   607,   649,  -239,  -239,  -239,    42,  -239,
    -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,   105,   126,
     122,   131,  -239,   128,  -239,  -239,  -239,   133,    12,  -239,
    -239,  -239,  -239,   129,  -239,   130,   649,   414,  -239,  -239,
     662,  -239,   662,  -239,  -239,   113,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,   532,    42,
     415,   140,   649,   280,    39,     9,   141,    13,   143,   142,
    -239,    42,  -239,    42,   147,    65,    65,  -239,   135,   662,
     662,   107,   107,   107,   107,   107,   107,   148,   622,   358,
     415,    67,   144,   156,  -239,   157,   149,  -239,  -239,    15,
     122,  -239,  -239,   315,  -239,   636,   158,   160,    10,   120,
     372,  -239,   168,   132,   162,   164,    16,  -239,   166,  -239,
     163,     7,    68,    42,   415,    82,   169,    42,  -239,   171,
     170,   122,   122,  -239,   172,   122,   175,   122,  -239,  -239,
    -239,    19,  -239,   183,   551,   415,   176,    42,   179,   184,
     185,   649,  -239,   178,   181,   186,   187,  -239,    42,    16,
     189,  -239,   191,  -239,   159,   454,   415,   190,   415,   122,
     192,   193,   415,   494,  -239,    42,  -239,   195,  -239,    82,
     415,   196,  -239,   197,   201,   199,   204,   415,   174,  -239,
      42,   513,   208,  -239,   206,  -239,  -239,   209,   415,   415,
      42,   570,  -239,    42,   415,   211,   215,   188,   194,   216,
     649,  -239,   589,   213,    82,   415,    42,    42,   214,  -239,
    -239,  -239,   198,   219,   223,  -239,    42,   221,   224,   229,
    -239,  -239,   226,  -239
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   114,   107,   108,   109,    17,     0,     0,    63,     0,
       0,   117,     0,     0,     2,     3,     0,     0,     0,    20,
       7,     0,     0,     0,     0,     0,     0,     0,     0,    19,
       0,     0,    42,   113,   112,   111,     0,     0,     0,     0,
       0,     0,     0,     0,    85,     0,    84,   110,     0,    62,
      20,     0,     0,     0,   119,     1,     4,     5,     0,     6,
      15,    10,    11,    12,    13,    14,     8,     9,   114,     0,
       0,     0,    28,    23,    24,    26,    31,    29,     0,   118,
      22,    21,    16,     0,    41,    43,    45,     0,    86,    87,
      88,    89,    90,    93,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    42,     0,     0,     0,     0,   114,    30,
      40,     0,    91,     0,     0,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,     0,     0,     0,
       0,   112,     0,     0,   115,     0,    46,    47,    49,     0,
      75,    25,    27,    42,    44,     0,     0,     0,    63,     0,
       0,    34,     0,     0,     0,     0,     0,   116,     0,    74,
      76,     0,   112,     0,    59,     0,     0,     0,    61,     0,
       0,    75,    75,    48,    64,     0,   114,     0,    80,    81,
      78,     0,    35,     0,     0,    58,     0,     0,     0,     0,
       0,    60,    32,     0,     0,     0,     0,    77,     0,     0,
     114,    79,     0,   106,    52,     0,    59,     0,    59,    75,
      65,    67,    73,     0,    82,     0,    33,     0,    50,     0,
      59,     0,    53,     0,     0,     0,     0,    72,     0,    36,
       0,     0,     0,    55,     0,    56,    57,    66,    73,    73,
       0,     0,    37,     0,    59,     0,     0,     0,     0,     0,
      83,    38,     0,     0,     0,    73,     0,     0,     0,    39,
      51,    54,     0,     0,     0,    68,     0,     0,     0,     0,
      69,    71,     0,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -239,  -239,     2,    -7,     1,  -239,  -239,  -239,   136,   137,
    -239,  -239,  -239,   106,  -239,   121,  -239,  -239,  -239,    77,
    -239,  -239,  -239,  -224,  -239,  -107,  -239,  -239,    90,  -239,
    -239,  -238,  -114,    64,  -239,  -189,    -6,   -42,  -239,    41,
      43,    -2,  -239
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,   195,    15,    16,    17,    18,    73,    74,    75,
      76,   188,   189,    44,    83,    84,    85,    20,   146,   147,
      21,   228,    22,   199,    23,   196,    24,    25,    51,    26,
      27,   238,   168,   169,   170,   259,    86,    28,    46,    47,
     148,    30,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    32,    14,    68,    53,   243,    54,    56,    69,    49,
     257,   258,    52,   186,    70,   144,     1,     1,   118,    68,
      55,   167,   144,    58,   187,   210,    78,   272,   115,    72,
      87,    88,    89,    90,    91,    92,    93,    94,    48,    71,
     271,    29,   108,    57,    11,    33,    34,    35,     1,    29,
     142,   145,   112,    36,    11,    29,    11,    11,    79,    79,
      11,    37,    79,    11,    38,    59,    79,   204,   205,    77,
      60,    81,    61,    39,    40,    41,    42,   273,   274,   161,
     192,   143,    62,   162,   193,    98,    99,   279,    63,    43,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,    64,   138,    65,   234,    19,    66,   171,   231,
      67,   233,   139,   149,    50,    78,   113,   155,    72,   119,
      19,   197,   198,   244,    82,    96,    97,    98,    99,     2,
       3,     4,    56,   109,    50,   110,    80,   116,   114,   171,
     171,   120,   160,   171,   117,   209,   121,   263,   -19,   124,
     140,    29,   150,    56,   153,    98,   163,   -21,    77,    49,
     156,   157,   164,   165,   149,   166,   177,   194,   174,   191,
     175,   201,   179,   181,   180,   182,   203,   171,   184,   185,
      29,    29,   200,   202,    80,   206,   208,   212,    56,   219,
     214,   215,   216,   220,   217,   218,   227,   222,   221,    29,
     225,    29,   223,   226,   232,   235,   236,   149,   242,   248,
     245,   246,   190,   247,   249,    29,    19,   250,   254,   241,
     255,   264,   256,    50,   237,   265,   268,   270,   275,   277,
      56,   266,   211,   278,   251,   280,    29,   267,   281,   282,
     283,   276,   154,   183,   260,    19,    19,   262,   176,   207,
     237,   237,   224,   151,   152,     0,     0,    29,     0,    29,
     260,   260,     0,    29,    50,     0,    19,   237,     0,     0,
     260,    29,     0,     0,     0,     0,     0,     0,    29,     0,
      19,     0,     0,    33,   141,    35,     1,     0,     0,    29,
      29,    36,     0,     0,     0,    29,     0,     0,     0,    37,
       0,    19,    38,     0,     0,     0,    29,     0,     0,     0,
       0,    39,    40,    41,    42,     0,     0,     0,    33,   172,
      35,     1,    19,     0,    19,     0,    36,    43,    19,     0,
       0,     0,     0,     0,    37,     0,    19,    38,     0,     0,
       0,     0,     0,    19,     0,     0,    39,    40,    41,    42,
       0,     0,     0,     0,    19,    19,     0,     0,     0,     0,
      19,     0,    43,     0,     1,     2,     3,     4,     5,     0,
       0,    19,   159,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     0,     0,     0,   178,     0,     0,     0,
       0,     0,     0,     6,     0,     0,     7,     0,     0,     8,
       0,     0,     0,     9,    10,    11,    12,     6,     0,     0,
       7,     0,     0,     8,     0,     0,     0,     9,    10,    11,
      12,     1,     2,     3,     4,     5,   122,     0,     0,     0,
       0,     0,    96,    97,    98,    99,     0,   100,   101,   102,
     103,   104,   105,   106,   107,     0,     0,     0,     0,     0,
       6,     0,     0,     7,     0,     0,     8,     0,   123,     0,
       9,    10,    11,    12,   229,     0,     0,   230,     0,     0,
       0,     0,    96,    97,    98,    99,     0,   100,   101,   102,
     103,   104,   105,   106,   107,    95,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,    99,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   239,     0,     0,     0,
     240,     0,    96,    97,    98,    99,     0,   100,   101,   102,
     103,   104,   105,   106,   107,   252,     0,     0,     0,   253,
       0,    96,    97,    98,    99,     0,   100,   101,   102,   103,
     104,   105,   106,   107,   137,     0,     0,     0,     0,     0,
      96,    97,    98,    99,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   213,     0,     0,     0,     0,     0,    96,
      97,    98,    99,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   261,     0,     0,     0,     0,     0,    96,    97,
      98,    99,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   269,     0,     0,     0,     0,     0,    96,    97,    98,
      99,     0,   100,   101,   102,   103,   104,   105,   106,   107,
     111,     0,     0,     0,     0,    96,    97,    98,    99,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   158,     0,
      96,    97,    98,    99,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   173,    96,    97,    98,    99,     0,   100,
     101,   102,   103,   104,   105,   106,   107,    96,    97,    98,
      99,     0,   100,   101,   102,   103,   104,   105,   106,   107,
      96,    97,    98,    99,     0,     0,     0,   102,   103,   104,
     105,   106,   107
};

static const yytype_int16 yycheck[] =
{
       6,    11,     0,     6,    10,   229,    12,    14,    11,     8,
     248,   249,    13,     6,    17,     6,     6,     6,     6,     6,
       0,     6,     6,    15,    17,     6,    28,   265,    70,    28,
      36,    37,    38,    39,    40,    41,    42,    43,    11,    42,
     264,     0,    48,    10,    47,     3,     4,     5,     6,     8,
      11,    42,    58,    11,    47,    14,    47,    47,    47,    47,
      47,    19,    47,    47,    22,    10,    47,   181,   182,    28,
      10,    30,    10,    31,    32,    33,    34,   266,   267,    12,
      12,    42,    10,    16,    16,    20,    21,   276,    10,    47,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,    10,   109,    10,   219,     0,    10,   150,   216,
      10,   218,   110,   115,     8,   117,    11,   123,   117,    78,
      14,    39,    40,   230,    10,    18,    19,    20,    21,     7,
       8,     9,   139,    16,    28,    10,    30,     6,    12,   181,
     182,    12,   140,   185,    16,   187,    16,   254,    15,    36,
      10,   110,    11,   160,    11,    20,    12,    15,   117,   158,
      13,    13,     6,     6,   166,    16,    46,   173,    10,   171,
      10,   177,     4,    11,    42,    11,     6,   219,    12,    16,
     139,   140,    13,    12,    78,    13,    11,     4,   195,    11,
      14,   197,    13,    12,    10,    10,    37,    10,    12,   158,
      11,   160,   208,    12,    14,    13,    13,   209,    13,    10,
      14,    14,   171,    12,    10,   174,   110,    43,    10,   225,
      14,    10,    13,   117,   222,    10,    10,    14,    14,    10,
     237,    43,   191,    10,   240,    14,   195,    43,    14,    10,
      14,    43,   121,   166,   250,   139,   140,   253,   158,   185,
     248,   249,   209,   117,   117,    -1,    -1,   216,    -1,   218,
     266,   267,    -1,   222,   158,    -1,   160,   265,    -1,    -1,
     276,   230,    -1,    -1,    -1,    -1,    -1,    -1,   237,    -1,
     174,    -1,    -1,     3,     4,     5,     6,    -1,    -1,   248,
     249,    11,    -1,    -1,    -1,   254,    -1,    -1,    -1,    19,
      -1,   195,    22,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    -1,    -1,    -1,     3,     4,
       5,     6,   216,    -1,   218,    -1,    11,    47,   222,    -1,
      -1,    -1,    -1,    -1,    19,    -1,   230,    22,    -1,    -1,
      -1,    -1,    -1,   237,    -1,    -1,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    47,    -1,     6,     7,     8,     9,    10,    -1,
      -1,   265,    14,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    -1,    41,
      -1,    -1,    -1,    45,    46,    47,    48,    35,    -1,    -1,
      38,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,    47,
      48,     6,     7,     8,     9,    10,    12,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    38,    -1,    -1,    41,    -1,    44,    -1,
      45,    46,    47,    48,    10,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    12,    -1,    -1,    -1,
      16,    -1,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    12,    -1,    -1,    -1,    16,
      -1,    18,    19,    20,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    12,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    12,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    12,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    12,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      13,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    16,    -1,
      18,    19,    20,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    26,    27,    28,    29,    30,    18,    19,    20,
      21,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      18,    19,    20,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    35,    38,    41,    45,
      46,    47,    48,    51,    52,    53,    54,    55,    56,    63,
      67,    70,    72,    74,    76,    77,    79,    80,    87,    89,
      91,    92,    11,     3,     4,     5,    11,    19,    22,    31,
      32,    33,    34,    47,    63,    86,    88,    89,    11,    54,
      63,    78,    13,    86,    86,     0,    53,    10,    15,    10,
      10,    10,    10,    10,    10,    10,    10,    10,     6,    11,
      17,    42,    54,    57,    58,    59,    60,    89,    91,    47,
      63,    89,    10,    64,    65,    66,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    10,    18,    19,    20,    21,
      23,    24,    25,    26,    27,    28,    29,    30,    86,    16,
      10,    13,    86,    11,    12,    87,     6,    16,     6,    89,
      12,    16,    12,    44,    36,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    12,    86,    52,
      10,     4,    11,    42,     6,    42,    68,    69,    90,    91,
      11,    58,    59,    11,    65,    86,    13,    13,    16,    14,
      52,    12,    16,    12,     6,     6,    16,     6,    82,    83,
      84,    87,     4,    17,    10,    10,    78,    46,    14,     4,
      42,    11,    11,    69,    12,    16,     6,    17,    61,    62,
      89,    91,    12,    16,    86,    52,    75,    39,    40,    73,
      13,    86,    12,     6,    82,    82,    13,    83,    11,    87,
       6,    89,     4,    12,    14,    86,    13,    10,    10,    11,
      12,    12,    10,    86,    90,    11,    12,    37,    71,    10,
      13,    75,    14,    75,    82,    13,    13,    52,    81,    12,
      16,    86,    13,    73,    75,    14,    14,    12,    10,    10,
      43,    86,    12,    16,    10,    14,    13,    81,    81,    85,
      86,    12,    86,    75,    10,    10,    43,    43,    10,    12,
      14,    73,    81,    85,    85,    14,    43,    10,    10,    85,
      14,    14,    10,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    55,
      55,    55,    55,    56,    57,    57,    57,    57,    58,    58,
      58,    59,    60,    60,    60,    60,    61,    61,    62,    62,
      63,    64,    64,    65,    65,    66,    67,    68,    68,    69,
      70,    71,    71,    72,    73,    73,    73,    74,    75,    75,
      76,    77,    78,    78,    79,    79,    79,    79,    80,    80,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      84,    84,    84,    85,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    87,    87,    87,
      88,    88,    88,    88,    89,    90,    90,    91,    91,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     3,     1,
       1,     2,     2,     2,     1,     3,     1,     3,     1,     1,
       2,     1,     6,     7,     4,     5,     4,     5,     6,     7,
       4,     1,     0,     1,     3,     1,     4,     1,     3,     1,
       9,     5,     0,     9,     7,     4,     4,    10,     1,     0,
       7,     6,     1,     0,     6,     8,    10,     8,    13,    15,
      17,    15,     1,     0,     1,     0,     1,     3,     2,     3,
       2,     2,     4,     1,     1,     1,     2,     2,     2,     2,
       2,     3,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     7,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     2
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
#line 98 "parser.y" /* yacc.c:1646  */
    { std::cerr<<"";
                   arvoreSintatica = (yyvsp[0].bloco);
                   (yyval.bloco)->analisar(escopoPrincipal, 0, analisador);
                   (yyval.bloco)->imprimir(0, true);
		   std::cout <<"\n";
                  }
#line 1568 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 108 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = new AST::Bloco( AST::Tipo::bloco );  (yyval.bloco)->novaLinha((yyvsp[0].nodo)); }
#line 1574 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 109 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = (yyvsp[-1].bloco);                                  (yyvsp[-1].bloco)->novaLinha((yyvsp[0].nodo)); }
#line 1580 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 113 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].opBinaria);   }
#line 1586 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].declaracao);   }
#line 1592 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].declaracao_hash);   }
#line 1598 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].funcao);   }
#line 1604 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].funcao);   }
#line 1610 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].condicao);   }
#line 1616 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].selecionador);   }
#line 1622 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].laco);   }
#line 1628 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].laco);   }
#line 1634 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].laco);   }
#line 1640 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].nodo);   }
#line 1646 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].nodo);   }
#line 1652 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 125 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = NULL; }
#line 1658 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 130 "parser.y" /* yacc.c:1646  */
    { 
                if(((AST::Variavel*)(yyvsp[-2].nodo))->ponteiros > 0) {
                    ((AST::Variavel*)(yyvsp[-2].nodo))->ponteiroEsqAtribuicao = true;
                }
                (yyval.opBinaria) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::atribuicao, (yyvsp[-2].nodo), (yyvsp[0].nodo) ); 
            }
#line 1669 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1675 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); ((AST::Chamada*)(yyval.nodo))->read_hash = false; }
#line 1681 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); ((AST::Variavel*)(yyval.nodo))->ponteiros = (yyvsp[-1].num_ref);}
#line 1687 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); ((AST::Chamada*)(yyval.nodo))->read_hash = false; ((AST::Chamada*)(yyval.nodo))->ponteiros = (yyvsp[-1].num_ref);}
#line 1693 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.declaracao) = new AST::Declaracao( AST::Tipo::declaracao , (yyvsp[-1].tipo), (yyvsp[0].definicao) ); }
#line 1699 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[0].definicao);                          }
#line 1705 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[-2].definicao);  (yyvsp[-2].definicao)->ajustarProxima((yyvsp[0].definicao)); }
#line 1711 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[0].definicao);                          }
#line 1717 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[-2].definicao);  (yyvsp[-2].definicao)->ajustarProxima((yyvsp[0].definicao)); }
#line 1723 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::Definicao( AST::Tipo::definicao   , ((AST::Variavel*)(yyvsp[0].opBinaria)->esquerda) , (yyvsp[0].opBinaria)->direita , NULL ); }
#line 1729 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::Definicao( AST::Tipo::definicao   , ((AST::Variavel*)(yyvsp[0].nodo))           , NULL        , NULL ); }
#line 1735 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 159 "parser.y" /* yacc.c:1646  */
    { ((AST::Variavel*)(yyvsp[0].nodo))->ponteiros = (yyvsp[-1].num_ref); (yyval.definicao) = new AST::Definicao( AST::Tipo::definicao   , ((AST::Variavel*)(yyvsp[0].nodo))           , NULL        , NULL );}
#line 1741 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::DefinicaoDeArranjo( AST::Tipo::definicao_arranjo, (yyvsp[0].variavel), NULL , NULL ); }
#line 1747 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.variavel) = new AST::ArranjoDuplo( AST::Tipo::arranjo_duplo, AST::Tipo::nulo ,(yyvsp[-5].valores), new AST::Inteiro((yyvsp[-3].valores)), new AST::Inteiro((yyvsp[-1].valores)), 0 ); }
#line 1753 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.variavel) = new AST::ArranjoDuplo( AST::Tipo::arranjo_duplo, AST::Tipo::nulo ,(yyvsp[-5].valores), new AST::Inteiro((yyvsp[-3].valores)), new AST::Inteiro((yyvsp[-1].valores)), (yyvsp[-6].num_ref) ); }
#line 1759 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.variavel) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo ,(yyvsp[-3].valores), new AST::Inteiro((yyvsp[-1].valores)),0 ); }
#line 1765 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.variavel) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo ,(yyvsp[-3].valores), new AST::Inteiro((yyvsp[-1].valores)), (yyvsp[-4].num_ref) ); }
#line 1771 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 181 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo, (yyvsp[-3].valores), (yyvsp[-1].nodo), 0  );}
#line 1777 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 183 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo, (yyvsp[-3].valores), (yyvsp[-1].nodo), (yyvsp[-4].num_ref) ); }
#line 1783 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 188 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::ArranjoDuplo( AST::Tipo::arranjo_duplo, AST::Tipo::nulo , (yyvsp[-5].valores), (yyvsp[-3].nodo), (yyvsp[-1].nodo), 0 ); }
#line 1789 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 190 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::ArranjoDuplo( AST::Tipo::arranjo_duplo, AST::Tipo::nulo , (yyvsp[-5].valores), (yyvsp[-3].nodo), (yyvsp[-1].nodo), (yyvsp[-6].num_ref) ); }
#line 1795 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 195 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::Chamada ( AST::Tipo::nulo , AST::Tipo::chamada , (yyvsp[-3].valores) , (yyvsp[-1].parametro) , NULL, 0);}
#line 1801 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 200 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[0].parametro);   }
#line 1807 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = NULL; }
#line 1813 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 205 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[0].parametro);                   }
#line 1819 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[-2].parametro); (yyval.parametro)->proximo = (yyvsp[0].parametro); }
#line 1825 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, AST::Tipo::nulo, AST::Tipo::nulo, (yyvsp[0].nodo), NULL );  }
#line 1831 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval.declaracao_hash) = new AST::DeclaracaoDeHash( AST::Tipo::declaracao_hash, (yyvsp[-3].tipo), (yyvsp[-1].tipo), (yyvsp[0].definicao) ); }
#line 1837 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[0].definicao);                          }
#line 1843 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 219 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[-2].definicao);  (yyvsp[-2].definicao)->ajustarProxima((yyvsp[0].definicao)); }
#line 1849 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 223 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::DefinicaoDeHash( AST::Tipo::definicao_hash, ((AST::Variavel*)(yyvsp[0].nodo)), NULL, NULL); }
#line 1855 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 228 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao( AST::Tipo::condicao , (yyvsp[-7].nodo), (yyvsp[-2].bloco), (yyvsp[0].bloco) ); }
#line 1861 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 232 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = (yyvsp[-1].bloco);   }
#line 1867 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = NULL; }
#line 1873 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 239 "parser.y" /* yacc.c:1646  */
    {(yyval.selecionador) = new AST::Switch(AST::Tipo::seleciona, (yyvsp[-6].nodo), (yyvsp[-2].condicao)); }
#line 1879 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 245 "parser.y" /* yacc.c:1646  */
    {(yyval.condicao) = new AST::Condicao(AST::Tipo::caso, (yyvsp[-5].nodo), (yyvsp[-3].bloco), NULL); (yyval.condicao)->proximo = (yyvsp[0].condicao); }
#line 1885 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 248 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao(AST::Tipo::caso, (yyvsp[-2].nodo), (yyvsp[0].condicao)->se, NULL); (yyval.condicao)->proximo = (yyvsp[0].condicao); }
#line 1891 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 252 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao(AST::Tipo::padrao, NULL, (yyvsp[-1].bloco), NULL); (yyval.condicao)->proximo = NULL;}
#line 1897 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 258 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::for_laco , (yyvsp[-8].opBinaria) , (yyvsp[-6].nodo) , (yyvsp[-4].opBinaria) , (yyvsp[-1].bloco) ); }
#line 1903 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 262 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = (yyvsp[0].bloco);   }
#line 1909 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 263 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = NULL; }
#line 1915 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 268 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::do_while_laco , NULL , (yyvsp[0].nodo) , NULL , (yyvsp[-3].bloco) ); }
#line 1921 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 273 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::while_laco , NULL , (yyvsp[-4].nodo) , NULL , (yyvsp[-1].bloco) ); }
#line 1927 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 277 "parser.y" /* yacc.c:1646  */
    { (yyval.opBinaria) = (yyvsp[0].opBinaria);   }
#line 1933 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 278 "parser.y" /* yacc.c:1646  */
    { (yyval.opBinaria) = NULL; }
#line 1939 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 283 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_dec, (yyvsp[-5].tipo) , (yyvsp[-3].valores) , (yyvsp[-1].parametro)); }
#line 1945 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 285 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_dec, escopoPrincipal->tipoDeArranjo((yyvsp[-7].tipo)) , (yyvsp[-3].valores) , (yyvsp[-1].parametro)); }
#line 1951 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 287 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_dec, escopoPrincipal->tipoDeArranjoDuplo((yyvsp[-9].tipo)) , (yyvsp[-3].valores) , (yyvsp[-1].parametro)); }
#line 1957 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 289 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_dec, escopoPrincipal->tipoDeHash((yyvsp[-7].tipo),(yyvsp[-5].tipo)) , (yyvsp[-3].valores) , (yyvsp[-1].parametro)); }
#line 1963 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 294 "parser.y" /* yacc.c:1646  */
    {  (yyvsp[-4].bloco)->novaLinha((yyvsp[-2].nodo)); 
                 (yyval.funcao) = new AST::DefinicaoDeFuncao( AST::Tipo::funcao_def, (yyvsp[-12].tipo) , (yyvsp[-10].valores) , (yyvsp[-8].parametro) , (yyvsp[-4].bloco), (yyvsp[-2].nodo)); }
#line 1970 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 297 "parser.y" /* yacc.c:1646  */
    {  (yyvsp[-4].bloco)->novaLinha((yyvsp[-2].nodo));
                 (yyval.funcao) = new AST::DefinicaoDeFuncao( AST::Tipo::funcao_def, escopoPrincipal->tipoDeArranjo((yyvsp[-14].tipo)) , (yyvsp[-10].valores) , (yyvsp[-8].parametro) , (yyvsp[-4].bloco), (yyvsp[-2].nodo)); 
              }
#line 1978 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 301 "parser.y" /* yacc.c:1646  */
    {  (yyvsp[-4].bloco)->novaLinha((yyvsp[-2].nodo));
                 (yyval.funcao) = new AST::DefinicaoDeFuncao( AST::Tipo::funcao_def, escopoPrincipal->tipoDeArranjoDuplo((yyvsp[-16].tipo)) , (yyvsp[-10].valores) , (yyvsp[-8].parametro) , (yyvsp[-4].bloco), (yyvsp[-2].nodo) ); }
#line 1985 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 304 "parser.y" /* yacc.c:1646  */
    {  (yyvsp[-4].bloco)->novaLinha((yyvsp[-2].nodo));
                 (yyval.funcao) = new AST::DefinicaoDeFuncao( AST::Tipo::funcao_def, escopoPrincipal->tipoDeHash((yyvsp[-14].tipo),(yyvsp[-12].tipo)) , (yyvsp[-10].valores) , (yyvsp[-8].parametro) , (yyvsp[-4].bloco), (yyvsp[-2].nodo) );  }
#line 1992 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 309 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = (yyvsp[0].bloco);                                 }
#line 1998 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 310 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = new AST::Bloco( AST::Tipo::bloco ); }
#line 2004 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 314 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[0].parametro);   }
#line 2010 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 315 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = NULL; }
#line 2016 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 319 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[0].parametro); }
#line 2022 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 320 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[-2].parametro); (yyval.parametro)->proximo = (yyvsp[0].parametro); }
#line 2028 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 324 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, (yyvsp[-1].tipo), AST::Tipo::nulo, (yyvsp[0].nodo), NULL );  }
#line 2034 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 326 "parser.y" /* yacc.c:1646  */
    { ((AST::Variavel*)(yyvsp[0].nodo))->ponteiros = (yyvsp[-1].num_ref); (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, (yyvsp[-2].tipo), AST::Tipo::nulo, (yyvsp[0].nodo), NULL );  }
#line 2040 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 327 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, (yyvsp[-1].tipo), AST::Tipo::nulo, (yyvsp[0].nodo), NULL );  }
#line 2046 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 328 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, (yyvsp[-1].tipo), AST::Tipo::nulo, (yyvsp[0].nodo), NULL );  }
#line 2052 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 329 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, (yyvsp[-1].tipo), (yyvsp[-3].tipo)             , (yyvsp[0].nodo), NULL );  }
#line 2058 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 333 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Retorno( AST::Tipo::retorno, (yyvsp[0].nodo)); }
#line 2064 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 337 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2070 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 338 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2076 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 339 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::negacao         , (yyvsp[0].nodo) ); }
#line 2082 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 340 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::inversao        , (yyvsp[0].nodo) ); }
#line 2088 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 341 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_int   , (yyvsp[0].nodo) ); }
#line 2094 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 342 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_float , (yyvsp[0].nodo) ); }
#line 2100 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 343 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_bool  , (yyvsp[0].nodo) ); }
#line 2106 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 344 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::parenteses      , (yyvsp[-1].nodo) ); }
#line 2112 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 345 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::referencia      , (yyvsp[0].nodo) ); }
#line 2118 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 346 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::endereco        , (yyvsp[0].nodo) ); }
#line 2124 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 347 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::adicao        , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2130 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 348 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::subtracao     , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2136 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 349 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::multiplicacao , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2142 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 350 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::divisao       , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2148 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 351 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::e             , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2154 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 352 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::ou            , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2160 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 353 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::igual         , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2166 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 354 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::diferente     , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2172 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 355 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::maior         , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2178 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 356 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::maior_igual   , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2184 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 357 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::menor         , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2190 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 358 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::menor_igual   , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2196 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 359 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoTernaria(AST::Tipo::opTernaria, new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::condicao_atribuicao, (yyvsp[-5].nodo) ),  new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::atribuicao_condicional, (yyvsp[-3].nodo), (yyvsp[-1].nodo))); }
#line 2202 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 363 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = AST::Tipo::inteiro;  }
#line 2208 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 364 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = AST::Tipo::real;     }
#line 2214 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 365 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = AST::Tipo::boolean;  }
#line 2220 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 370 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Boolean  ( (yyvsp[0].valores) ); }
#line 2226 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 371 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Inteiro  ( (yyvsp[0].valores) ); }
#line 2232 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 372 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Real     ( (yyvsp[0].valores) ); }
#line 2238 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 376 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Variavel( AST::Tipo::variavel, AST::Tipo::nulo , (yyvsp[0].valores), 0 ); }
#line 2244 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 380 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Hash( AST::Tipo::hash, AST::Tipo::nulo , (yyvsp[0].valores), 0 ); }
#line 2250 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 381 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Hash( AST::Tipo::hash, AST::Tipo::nulo, (yyvsp[0].valores), (yyvsp[-1].num_ref) ); }
#line 2256 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 385 "parser.y" /* yacc.c:1646  */
    {(yyval.num_ref) = (yyval.num_ref) + 1;}
#line 2262 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 389 "parser.y" /* yacc.c:1646  */
    { analisador = true; (yyval.nodo) = new AST::Interpretador(AST::Tipo::interpretador, (yyvsp[0].nodo)); }
#line 2268 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2272 "parser.cpp" /* yacc.c:1646  */
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

