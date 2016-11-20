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
    T_SWITCH = 294,
    T_CASE = 295,
    T_DEFAULT = 296,
    T_FOR = 297,
    T_FUN = 298,
    T_RET = 299,
    T_ATRIB_ASK = 300,
    T_DO = 301,
    T_WHILE = 302,
    T_REF = 303,
    T_CALC = 304,
    UMINUS = 305,
    T_CAST = 306,
    INT = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 28 "parser.y" /* yacc.c:355  */

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
    AST::Switch *selecionador;
    AST::Laco *laco;
    AST::Funcao *funcao;
    AST::Parametro *parametro;
    AST::Bloco *bloco;
    AST::Tipo tipo;
    int num_ref;

#line 195 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 210 "parser.cpp" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 16 "parser.y" /* yacc.c:359  */

    AST::Bloco *arvoreSintatica;
    AST::Tipo ultimoTipo;
    AST::TabelaDeSimbolos *escopoPrincipal = new AST::TabelaDeSimbolos();
    bool analisador = false;

#line 219 "parser.cpp" /* yacc.c:359  */

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
#define YYLAST   645

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  287

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   110,   111,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   131,   141,
     142,   146,   150,   151,   152,   153,   157,   158,   162,   166,
     168,   170,   172,   177,   179,   184,   186,   191,   193,   198,
     199,   203,   204,   208,   212,   216,   217,   221,   225,   230,
     231,   236,   242,   245,   249,   255,   260,   261,   265,   270,
     275,   276,   280,   282,   284,   286,   291,   294,   298,   301,
     307,   308,   312,   313,   317,   318,   322,   323,   324,   325,
     329,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   359,   360,   361,   365,   366,   367,
     368,   372,   373,   377,   378,   382,   382,   386
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
  "T_ELSE", "T_SWITCH", "T_CASE", "T_DEFAULT", "T_FOR", "T_FUN", "T_RET",
  "T_ATRIB_ASK", "T_DO", "T_WHILE", "T_REF", "T_CALC", "UMINUS", "T_CAST",
  "INT", "$accept", "programa", "linhas", "linha", "atribuicao",
  "var_arranjo", "declaracao", "variaveis", "variavel", "def_arranjo",
  "dec_arranjo", "arranjo", "arranjo_duplo", "chamada", "arg_null",
  "argumentos", "argumento", "dec_hashes", "hashes", "def_hash",
  "condicao", "senao", "seleciona", "caso", "for_laco", "linhas_null",
  "do_while_laco", "while_laco", "atrib_null", "dec_funcao", "def_funcao",
  "linhas_funcao", "param_null", "parametros", "parametro", "retorno",
  "expressao", "tipo", "primitiva", "var", "hash", "referencia",
  "interpretacao", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -207

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-207)))

#define YYTABLE_NINF -20

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     329,    37,  -207,  -207,  -207,  -207,   271,    61,    10,    62,
     271,  -207,   271,    79,   329,  -207,    73,    93,   102,   104,
    -207,   116,   118,   120,   122,   125,   127,   128,    -4,  -207,
      14,   131,   271,  -207,  -207,  -207,   271,   271,   271,   271,
     271,   271,   271,   389,  -207,   419,  -207,  -207,   271,  -207,
    -207,   126,   137,   558,   601,  -207,  -207,  -207,   271,  -207,
    -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,   144,   136,
     143,   150,  -207,   142,  -207,  -207,  -207,   145,    16,   148,
    -207,  -207,   151,  -207,   146,   601,   360,  -207,  -207,   601,
    -207,  -207,  -207,  -207,   129,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   479,   271,   329,
     154,   601,   271,    35,     6,   156,    18,   163,   271,  -207,
     271,  -207,   271,   168,    29,    29,  -207,   161,   614,   614,
     158,   158,   158,   158,   158,   158,   170,   574,    97,   329,
      47,   172,   179,  -207,   182,   173,  -207,  -207,    22,   143,
    -207,  -207,   271,   180,  -207,   588,   181,   183,    10,   149,
     315,  -207,     5,   157,   186,   190,    32,  -207,   191,  -207,
     188,     7,    53,  -207,   271,   329,    81,   189,   271,  -207,
    -207,   193,    34,   201,   143,   143,  -207,   195,   143,   198,
     143,  -207,  -207,  -207,    39,  -207,     5,   499,   329,   196,
     271,   202,   204,   206,   601,  -207,  -207,   200,   205,   207,
     211,  -207,   271,    32,   212,   213,  -207,   192,   406,   329,
     210,   329,   143,   214,   215,   329,   439,  -207,   271,  -207,
     218,  -207,    81,   329,   219,  -207,   224,   220,   229,   231,
     329,   199,  -207,   271,   459,   232,  -207,   230,  -207,  -207,
     233,   329,   329,   271,   519,  -207,   271,   329,   235,   239,
     216,   217,   241,   601,  -207,   539,   240,    81,   329,   271,
     271,   242,  -207,  -207,  -207,   221,   247,   249,  -207,   271,
     248,   254,   260,  -207,  -207,   257,  -207
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   111,   104,   105,   106,    17,     0,     0,    61,     0,
       0,   115,     0,     0,     2,     3,     0,     0,     0,    20,
       7,     0,     0,     0,     0,     0,     0,     0,     0,    19,
       0,     0,    40,   110,   109,   108,     0,     0,     0,     0,
       0,     0,     0,   115,    82,     0,    81,   107,     0,    60,
      20,     0,     0,     0,   117,     1,     4,     5,     0,     6,
      15,    10,    11,    12,    13,    14,     8,     9,   111,     0,
       0,     0,    26,    21,    22,    24,    28,    27,     0,   112,
     116,    16,     0,    39,    41,    43,     0,    83,    84,    85,
      86,    87,    90,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    40,     0,     0,     0,     0,   112,    40,    37,
       0,    88,     0,     0,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,     0,
      81,     0,     0,   113,     0,    44,    45,    47,     0,    73,
      23,    25,    40,     0,    42,     0,     0,     0,    61,     0,
       0,    31,     0,     0,     0,     0,     0,   114,     0,    72,
      74,     0,    81,    38,     0,    57,     0,     0,     0,    59,
     111,     0,     0,     0,    73,    73,    46,    62,     0,   111,
       0,    77,    78,    76,     0,    32,     0,     0,    56,     0,
       0,     0,     0,     0,    58,    29,   112,     0,     0,     0,
       0,    75,     0,     0,   112,     0,   103,    50,     0,    57,
       0,    57,    73,    63,    65,    71,     0,    79,     0,    30,
       0,    48,     0,    57,     0,    51,     0,     0,     0,     0,
      70,     0,    33,     0,     0,     0,    53,     0,    54,    55,
      64,    71,    71,     0,     0,    34,     0,    57,     0,     0,
       0,     0,     0,    80,    35,     0,     0,     0,    71,     0,
       0,     0,    36,    49,    52,     0,     0,     0,    66,     0,
       0,     0,     0,    67,    69,     0,    68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,  -207,     1,   -11,    13,  -207,  -207,  -207,   162,   164,
    -207,  -207,  -207,    60,   -71,   166,  -207,  -207,  -207,   121,
    -207,  -207,  -207,  -206,  -207,  -148,  -207,  -207,   130,  -207,
    -207,  -134,  -166,    96,  -207,  -193,    -6,   -65,   -95,    15,
      76,    -1,  -207
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,   198,    15,    16,    17,    18,    73,    74,    75,
      76,   191,   192,    44,    82,    83,    84,    20,   145,   146,
      21,   231,    22,   202,    23,   199,    24,    25,    51,    26,
      27,   241,   168,   169,   170,   262,    85,    28,    46,    47,
     147,    30,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    14,    68,    56,    53,   114,    54,    69,    33,    34,
      35,   180,   143,   189,    70,    29,     1,   140,   208,   209,
      79,    49,   117,    29,    68,   190,   246,    78,   167,    29,
      86,    87,    88,    89,    90,    91,    92,    93,   143,    71,
     206,    72,   107,    77,    11,   214,   141,   153,    32,   144,
      97,    98,   111,    11,    11,    11,   237,   172,    11,   161,
      19,   274,    80,   162,    80,   195,    11,   181,    50,   196,
      80,   234,    48,   236,    19,    52,   276,   277,   142,    55,
      11,   153,    80,    57,   171,   247,   282,    80,    50,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   215,   137,     1,     2,     3,     4,     5,    58,   266,
     138,   159,    59,   148,    60,    78,   155,   260,   261,   171,
     171,   200,   201,   171,    29,   213,    61,    56,    62,    72,
      63,    77,    64,     6,   275,    65,     7,    66,    67,     8,
     160,    81,   108,     9,    10,    11,    12,   109,   113,    56,
       2,     3,     4,    29,    29,   112,   115,   171,   116,   118,
     -19,   182,   120,   119,   139,   148,   123,   149,   197,    19,
     194,    49,   204,    29,   152,    29,    50,    95,    96,    97,
      98,   156,    97,   157,   163,   164,   193,    56,   165,   166,
      29,   175,   173,   176,   218,   182,   178,   184,    19,    19,
     183,   185,   203,   187,   188,   205,   226,   207,   210,   212,
     217,   222,   148,    29,   220,   219,   221,   223,    50,   224,
      19,   225,   244,   228,   235,   229,   240,   238,   239,    56,
     230,   245,   250,   248,    29,    19,    29,   254,   249,   251,
      29,   252,   257,   253,   258,   267,   259,   263,    29,   268,
     265,   271,   240,   240,   273,    29,   278,   280,    19,   281,
     269,   270,   283,   263,   263,   279,    29,    29,   284,   240,
     285,   286,    29,   263,    33,    34,    35,     1,   150,    19,
     151,    19,    36,    29,   211,    19,   154,   186,   177,   227,
       0,    37,     0,    19,    38,     0,     0,     0,     0,     0,
      19,     0,     0,    39,    40,    41,    42,     0,     0,     0,
       0,    19,    19,     0,     0,     0,     0,    19,     0,    43,
       0,     1,     2,     3,     4,     5,     0,     0,    19,   179,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     0,     0,     7,     0,     0,     8,     0,     0,
       0,     9,    10,    11,    12,     6,     0,     0,     7,     0,
       0,     8,   121,     0,     0,     9,    10,    11,    12,    95,
      96,    97,    98,     0,    99,   100,   101,   102,   103,   104,
     105,   106,    33,    34,    35,     1,     0,     0,     0,     0,
      36,     0,     0,     0,     0,   122,     0,     0,     0,    37,
       0,     0,    38,     0,     0,     0,   232,     0,     0,   233,
       0,    39,    40,    41,    42,    95,    96,    97,    98,    94,
      99,   100,   101,   102,   103,   104,   105,   106,    95,    96,
      97,    98,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   242,     0,     0,     0,   243,     0,     0,    95,    96,
      97,    98,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   255,     0,     0,     0,   256,     0,     0,    95,    96,
      97,    98,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   136,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   216,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   264,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   272,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   110,     0,     0,     0,     0,     0,    95,    96,    97,
      98,     0,    99,   100,   101,   102,   103,   104,   105,   106,
     158,     0,     0,    95,    96,    97,    98,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   174,    95,    96,    97,
      98,     0,    99,   100,   101,   102,   103,   104,   105,   106,
      95,    96,    97,    98,     0,    99,   100,   101,   102,   103,
     104,   105,   106,    95,    96,    97,    98,     0,     0,     0,
     101,   102,   103,   104,   105,   106
};

static const yytype_int16 yycheck[] =
{
       6,     0,     6,    14,    10,    70,    12,    11,     3,     4,
       5,     6,     6,     6,    18,     0,     6,   112,   184,   185,
       6,     8,     6,     8,     6,    18,   232,    28,     6,    14,
      36,    37,    38,    39,    40,    41,    42,    43,     6,    43,
       6,    28,    48,    28,    48,     6,    11,   118,    11,    43,
      21,    22,    58,    48,    48,    48,   222,   152,    48,    12,
       0,   267,    48,    16,    48,    12,    48,   162,     8,    16,
      48,   219,    11,   221,    14,    13,   269,   270,    43,     0,
      48,   152,    48,    10,   149,   233,   279,    48,    28,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   196,   108,     6,     7,     8,     9,    10,    15,   257,
     109,    14,    10,   114,    10,   116,   122,   251,   252,   184,
     185,    40,    41,   188,   109,   190,    10,   138,    10,   116,
      10,   116,    10,    36,   268,    10,    39,    10,    10,    42,
     139,    10,    16,    46,    47,    48,    49,    10,    12,   160,
       7,     8,     9,   138,   139,    11,     6,   222,    16,    11,
      15,   162,    16,    12,    10,   166,    37,    11,   174,   109,
     171,   158,   178,   158,    11,   160,   116,    19,    20,    21,
      22,    13,    21,    13,    12,     6,   171,   198,     6,    16,
     175,    10,    12,    10,   200,   196,    47,    11,   138,   139,
      43,    11,    13,    12,    16,    12,   212,     6,    13,    11,
      14,    11,   213,   198,    10,    13,    10,    12,   158,    12,
     160,    10,   228,    11,    14,    12,   225,    13,    13,   240,
      38,    13,    12,    14,   219,   175,   221,   243,    14,    10,
     225,    10,    10,    44,    14,    10,    13,   253,   233,    10,
     256,    10,   251,   252,    14,   240,    14,    10,   198,    10,
      44,    44,    14,   269,   270,    44,   251,   252,    14,   268,
      10,    14,   257,   279,     3,     4,     5,     6,   116,   219,
     116,   221,    11,   268,   188,   225,   120,   166,   158,   213,
      -1,    20,    -1,   233,    23,    -1,    -1,    -1,    -1,    -1,
     240,    -1,    -1,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,   251,   252,    -1,    -1,    -1,    -1,   257,    -1,    48,
      -1,     6,     7,     8,     9,    10,    -1,    -1,   268,    14,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    39,    -1,    -1,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    36,    -1,    -1,    39,    -1,
      -1,    42,    12,    -1,    -1,    46,    47,    48,    49,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      11,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    20,
      -1,    -1,    23,    -1,    -1,    -1,    10,    -1,    -1,    13,
      -1,    32,    33,    34,    35,    19,    20,    21,    22,    10,
      24,    25,    26,    27,    28,    29,    30,    31,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    12,    -1,    -1,    -1,    16,    -1,    -1,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    12,    -1,    -1,    -1,    16,    -1,    -1,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    13,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      16,    -1,    -1,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    28,    29,    30,    31,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    19,    20,    21,    22,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    36,    39,    42,    46,
      47,    48,    49,    54,    55,    56,    57,    58,    59,    66,
      70,    73,    75,    77,    79,    80,    82,    83,    90,    92,
      94,    95,    11,     3,     4,     5,    11,    20,    23,    32,
      33,    34,    35,    48,    66,    89,    91,    92,    11,    57,
      66,    81,    13,    89,    89,     0,    56,    10,    15,    10,
      10,    10,    10,    10,    10,    10,    10,    10,     6,    11,
      18,    43,    57,    60,    61,    62,    63,    92,    94,     6,
      48,    10,    67,    68,    69,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    10,    19,    20,    21,    22,    24,
      25,    26,    27,    28,    29,    30,    31,    89,    16,    10,
      13,    89,    11,    12,    90,     6,    16,     6,    11,    12,
      16,    12,    45,    37,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    12,    89,    55,    10,
      91,    11,    43,     6,    43,    71,    72,    93,    94,    11,
      61,    62,    11,    67,    68,    89,    13,    13,    16,    14,
      55,    12,    16,    12,     6,     6,    16,     6,    85,    86,
      87,    90,    91,    12,    18,    10,    10,    81,    47,    14,
       6,    91,    94,    43,    11,    11,    72,    12,    16,     6,
      18,    64,    65,    92,    94,    12,    16,    89,    55,    78,
      40,    41,    76,    13,    89,    12,     6,     6,    85,    85,
      13,    86,    11,    90,     6,    91,    12,    14,    89,    13,
      10,    10,    11,    12,    12,    10,    89,    93,    11,    12,
      38,    74,    10,    13,    78,    14,    78,    85,    13,    13,
      55,    84,    12,    16,    89,    13,    76,    78,    14,    14,
      12,    10,    10,    44,    89,    12,    16,    10,    14,    13,
      84,    84,    88,    89,    12,    89,    78,    10,    10,    44,
      44,    10,    12,    14,    76,    84,    88,    88,    14,    44,
      10,    10,    88,    14,    14,    10,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    58,
      58,    59,    60,    60,    60,    60,    61,    61,    62,    63,
      63,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    70,    71,    71,    72,    73,    74,
      74,    75,    76,    76,    76,    77,    78,    78,    79,    80,
      81,    81,    82,    82,    82,    82,    83,    83,    83,    83,
      84,    84,    85,    85,    86,    86,    87,    87,    87,    87,
      88,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    90,    90,    90,    91,    91,    91,
      91,    92,    92,    93,    93,    94,    94,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     3,     1,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     6,
       7,     4,     5,     4,     5,     6,     7,     4,     5,     1,
       0,     1,     3,     1,     4,     1,     3,     1,     9,     5,
       0,     9,     7,     4,     4,    10,     1,     0,     7,     6,
       1,     0,     6,     8,    10,     8,    13,    15,    17,    15,
       1,     0,     1,     0,     1,     3,     2,     2,     2,     4,
       1,     1,     1,     2,     2,     2,     2,     2,     3,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     7,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     1,     2,     2
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
#line 100 "parser.y" /* yacc.c:1646  */
    { std::cerr<<"";
                   arvoreSintatica = (yyvsp[0].bloco);
                   (yyval.bloco)->analisar(escopoPrincipal, 0, analisador);
                   (yyval.bloco)->imprimir(0, true);
		   std::cout <<"\n";
                  }
#line 1567 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = new AST::Bloco( AST::Tipo::bloco );  (yyval.bloco)->novaLinha((yyvsp[0].nodo)); }
#line 1573 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = (yyvsp[-1].bloco);                                  (yyvsp[-1].bloco)->novaLinha((yyvsp[0].nodo)); }
#line 1579 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].opBinaria);   }
#line 1585 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].declaracao);   }
#line 1591 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].declaracao_hash);   }
#line 1597 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].funcao);   }
#line 1603 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].funcao);   }
#line 1609 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 120 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].condicao);   }
#line 1615 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].selecionador);   }
#line 1621 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].laco);   }
#line 1627 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].laco);   }
#line 1633 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].laco);   }
#line 1639 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 125 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].nodo);   }
#line 1645 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 126 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[-1].nodo);   }
#line 1651 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = NULL; }
#line 1657 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 132 "parser.y" /* yacc.c:1646  */
    { 
                if(((AST::Variavel*)(yyvsp[-2].nodo))->ponteiros > 0) {
                    ((AST::Variavel*)(yyvsp[-2].nodo))->ponteiroEsqAtribuicao = true;
                }
                (yyval.opBinaria) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::atribuicao, (yyvsp[-2].nodo), (yyvsp[0].nodo) ); 
            }
#line 1668 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1674 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); ((AST::Chamada*)(yyval.nodo))->read_hash = false; }
#line 1680 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.declaracao) = new AST::Declaracao( AST::Tipo::declaracao , (yyvsp[-1].tipo), (yyvsp[0].definicao) ); }
#line 1686 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[0].definicao);                          }
#line 1692 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[-2].definicao);  (yyvsp[-2].definicao)->ajustarProxima((yyvsp[0].definicao)); }
#line 1698 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[0].definicao);                          }
#line 1704 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[-2].definicao);  (yyvsp[-2].definicao)->ajustarProxima((yyvsp[0].definicao)); }
#line 1710 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::Definicao( AST::Tipo::definicao   , ((AST::Variavel*)(yyvsp[0].opBinaria)->esquerda) , (yyvsp[0].opBinaria)->direita , NULL ); }
#line 1716 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::Definicao( AST::Tipo::definicao   , ((AST::Variavel*)(yyvsp[0].nodo))           , NULL        , NULL ); }
#line 1722 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::DefinicaoDeArranjo( AST::Tipo::definicao_arranjo, (yyvsp[0].variavel), NULL , NULL ); }
#line 1728 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.variavel) = new AST::ArranjoDuplo( AST::Tipo::arranjo_duplo, AST::Tipo::nulo ,(yyvsp[-5].valores), (yyvsp[-3].nodo), (yyvsp[-1].nodo), 0 ); }
#line 1734 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.variavel) = new AST::ArranjoDuplo( AST::Tipo::arranjo_duplo, AST::Tipo::nulo ,(yyvsp[-5].valores), (yyvsp[-3].nodo), (yyvsp[-1].nodo), (yyvsp[-6].num_ref) ); }
#line 1740 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.variavel) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo ,(yyvsp[-3].valores), (yyvsp[-1].nodo),0 ); }
#line 1746 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.variavel) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo ,(yyvsp[-3].valores), (yyvsp[-1].nodo), (yyvsp[-4].num_ref) ); }
#line 1752 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 178 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo, (yyvsp[-3].valores), (yyvsp[-1].nodo), 0  );}
#line 1758 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 180 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::Arranjo( AST::Tipo::arranjo, AST::Tipo::nulo, (yyvsp[-3].valores), (yyvsp[-1].nodo), (yyvsp[-4].num_ref) ); }
#line 1764 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 185 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::ArranjoDuplo( AST::Tipo::arranjo_duplo, AST::Tipo::nulo , (yyvsp[-5].valores), (yyvsp[-3].nodo), (yyvsp[-1].nodo), 0 ); }
#line 1770 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 187 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::ArranjoDuplo( AST::Tipo::arranjo_duplo, AST::Tipo::nulo , (yyvsp[-5].valores), (yyvsp[-3].nodo), (yyvsp[-1].nodo), (yyvsp[-6].num_ref) ); }
#line 1776 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 192 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::Chamada ( AST::Tipo::nulo , AST::Tipo::chamada , (yyvsp[-3].valores) , (yyvsp[-1].parametro) , NULL, 0);}
#line 1782 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 194 "parser.y" /* yacc.c:1646  */
    {  (yyval.nodo) = new AST::Chamada ( AST::Tipo::nulo , AST::Tipo::chamada , (yyvsp[-3].valores) , (yyvsp[-1].parametro) , NULL, (yyvsp[-4].num_ref));}
#line 1788 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 198 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[0].parametro);   }
#line 1794 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = NULL; }
#line 1800 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 203 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[0].parametro);                   }
#line 1806 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 204 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[-2].parametro); (yyval.parametro)->proximo = (yyvsp[0].parametro); }
#line 1812 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 208 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, AST::Tipo::nulo, AST::Tipo::nulo, (yyvsp[0].nodo), NULL );  }
#line 1818 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval.declaracao_hash) = new AST::DeclaracaoDeHash( AST::Tipo::declaracao_hash, (yyvsp[-3].tipo), (yyvsp[-1].tipo), (yyvsp[0].definicao) ); }
#line 1824 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 216 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[0].definicao);                          }
#line 1830 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = (yyvsp[-2].definicao);  (yyvsp[-2].definicao)->ajustarProxima((yyvsp[0].definicao)); }
#line 1836 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval.definicao) = new AST::DefinicaoDeHash( AST::Tipo::definicao_hash, ((AST::Variavel*)(yyvsp[0].nodo)), NULL, NULL); }
#line 1842 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao( AST::Tipo::condicao , (yyvsp[-7].nodo), (yyvsp[-2].bloco), (yyvsp[0].bloco) ); }
#line 1848 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 230 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = (yyvsp[-1].bloco);   }
#line 1854 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = NULL; }
#line 1860 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 237 "parser.y" /* yacc.c:1646  */
    {(yyval.selecionador) = new AST::Switch(AST::Tipo::seleciona, (yyvsp[-6].nodo), (yyvsp[-2].condicao)); }
#line 1866 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 243 "parser.y" /* yacc.c:1646  */
    {(yyval.condicao) = new AST::Condicao(AST::Tipo::caso, (yyvsp[-5].nodo), (yyvsp[-3].bloco), NULL); (yyval.condicao)->proximo = (yyvsp[0].condicao); }
#line 1872 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 246 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao(AST::Tipo::caso, (yyvsp[-2].nodo), (yyvsp[0].condicao)->se, NULL); (yyval.condicao)->proximo = (yyvsp[0].condicao); }
#line 1878 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 250 "parser.y" /* yacc.c:1646  */
    { (yyval.condicao) = new AST::Condicao(AST::Tipo::padrao, NULL, (yyvsp[-1].bloco), NULL); (yyval.condicao)->proximo = NULL;}
#line 1884 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 256 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::for_laco , (yyvsp[-8].opBinaria) , (yyvsp[-6].nodo) , (yyvsp[-4].opBinaria) , (yyvsp[-1].bloco) ); }
#line 1890 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = (yyvsp[0].bloco);   }
#line 1896 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = NULL; }
#line 1902 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 266 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::do_while_laco , NULL , (yyvsp[0].nodo) , NULL , (yyvsp[-3].bloco) ); }
#line 1908 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 271 "parser.y" /* yacc.c:1646  */
    { (yyval.laco) = new AST::Laco( AST::Tipo::while_laco , NULL , (yyvsp[-4].nodo) , NULL , (yyvsp[-1].bloco) ); }
#line 1914 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 275 "parser.y" /* yacc.c:1646  */
    { (yyval.opBinaria) = (yyvsp[0].opBinaria);   }
#line 1920 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 276 "parser.y" /* yacc.c:1646  */
    { (yyval.opBinaria) = NULL; }
#line 1926 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 281 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_dec, (yyvsp[-5].tipo) , (yyvsp[-3].valores) , (yyvsp[-1].parametro)); }
#line 1932 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 283 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_dec, escopoPrincipal->tipoDeArranjo((yyvsp[-7].tipo)) , (yyvsp[-3].valores) , (yyvsp[-1].parametro)); }
#line 1938 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 285 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_dec, escopoPrincipal->tipoDeArranjoDuplo((yyvsp[-9].tipo)) , (yyvsp[-3].valores) , (yyvsp[-1].parametro)); }
#line 1944 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 287 "parser.y" /* yacc.c:1646  */
    { (yyval.funcao) = new AST::Funcao( AST::Tipo::funcao_dec, escopoPrincipal->tipoDeHash((yyvsp[-7].tipo),(yyvsp[-5].tipo)) , (yyvsp[-3].valores) , (yyvsp[-1].parametro)); }
#line 1950 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 292 "parser.y" /* yacc.c:1646  */
    {  (yyvsp[-4].bloco)->novaLinha((yyvsp[-2].nodo)); 
                 (yyval.funcao) = new AST::DefinicaoDeFuncao( AST::Tipo::funcao_def, (yyvsp[-12].tipo) , (yyvsp[-10].valores) , (yyvsp[-8].parametro) , (yyvsp[-4].bloco), (yyvsp[-2].nodo)); }
#line 1957 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 295 "parser.y" /* yacc.c:1646  */
    {  (yyvsp[-4].bloco)->novaLinha((yyvsp[-2].nodo));
                 (yyval.funcao) = new AST::DefinicaoDeFuncao( AST::Tipo::funcao_def, escopoPrincipal->tipoDeArranjo((yyvsp[-14].tipo)) , (yyvsp[-10].valores) , (yyvsp[-8].parametro) , (yyvsp[-4].bloco), (yyvsp[-2].nodo)); 
              }
#line 1965 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 299 "parser.y" /* yacc.c:1646  */
    {  (yyvsp[-4].bloco)->novaLinha((yyvsp[-2].nodo));
                 (yyval.funcao) = new AST::DefinicaoDeFuncao( AST::Tipo::funcao_def, escopoPrincipal->tipoDeArranjoDuplo((yyvsp[-16].tipo)) , (yyvsp[-10].valores) , (yyvsp[-8].parametro) , (yyvsp[-4].bloco), (yyvsp[-2].nodo) ); }
#line 1972 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 302 "parser.y" /* yacc.c:1646  */
    {  (yyvsp[-4].bloco)->novaLinha((yyvsp[-2].nodo));
                 (yyval.funcao) = new AST::DefinicaoDeFuncao( AST::Tipo::funcao_def, escopoPrincipal->tipoDeHash((yyvsp[-14].tipo),(yyvsp[-12].tipo)) , (yyvsp[-10].valores) , (yyvsp[-8].parametro) , (yyvsp[-4].bloco), (yyvsp[-2].nodo) );  }
#line 1979 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 307 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = (yyvsp[0].bloco);                                 }
#line 1985 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 308 "parser.y" /* yacc.c:1646  */
    { (yyval.bloco) = new AST::Bloco( AST::Tipo::bloco ); }
#line 1991 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 312 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[0].parametro);   }
#line 1997 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 313 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = NULL; }
#line 2003 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 317 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[0].parametro); }
#line 2009 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 318 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = (yyvsp[-2].parametro); (yyval.parametro)->proximo = (yyvsp[0].parametro); }
#line 2015 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 322 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, (yyvsp[-1].tipo), AST::Tipo::nulo, (yyvsp[0].nodo), NULL );  }
#line 2021 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 323 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, (yyvsp[-1].tipo), AST::Tipo::nulo, (yyvsp[0].nodo), NULL );  }
#line 2027 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 324 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, (yyvsp[-1].tipo), AST::Tipo::nulo, (yyvsp[0].nodo), NULL );  }
#line 2033 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 325 "parser.y" /* yacc.c:1646  */
    { (yyval.parametro) = new AST::Parametro( AST::Tipo::parametro, (yyvsp[-1].tipo), (yyvsp[-3].tipo)             , (yyvsp[0].nodo), NULL );  }
#line 2039 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 329 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Retorno( AST::Tipo::retorno, (yyvsp[0].nodo)); }
#line 2045 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 333 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2051 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 334 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 2057 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 335 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::negacao         , (yyvsp[0].nodo) ); }
#line 2063 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 336 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::inversao        , (yyvsp[0].nodo) ); }
#line 2069 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 337 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_int   , (yyvsp[0].nodo) ); }
#line 2075 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 338 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_float , (yyvsp[0].nodo) ); }
#line 2081 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 339 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::conversao_bool  , (yyvsp[0].nodo) ); }
#line 2087 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 340 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::parenteses      , (yyvsp[-1].nodo) ); }
#line 2093 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 341 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::referencia      , (yyvsp[0].nodo) ); }
#line 2099 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 342 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::endereco        , (yyvsp[0].nodo) ); }
#line 2105 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 343 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::adicao        , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2111 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 344 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::subtracao     , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2117 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 345 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::multiplicacao , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2123 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 346 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::divisao       , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2129 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 347 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::e             , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2135 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 348 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::ou            , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2141 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 349 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::igual         , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2147 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 350 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::diferente     , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2153 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 351 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::maior         , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2159 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 352 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::maior_igual   , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2165 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 353 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::menor         , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2171 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 354 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::menor_igual   , (yyvsp[-2].nodo), (yyvsp[0].nodo) ); }
#line 2177 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 355 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::OperacaoTernaria(AST::Tipo::opTernaria, new AST::OperacaoUnaria( AST::Tipo::opUnaria , AST::Tipo::condicao_atribuicao, (yyvsp[-5].nodo) ),  new AST::OperacaoBinaria( AST::Tipo::opBinaria , AST::Tipo::atribuicao_condicional, (yyvsp[-3].nodo), (yyvsp[-1].nodo))); }
#line 2183 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 359 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = AST::Tipo::inteiro;  ultimoTipo = (yyvsp[0].tipo); }
#line 2189 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 360 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = AST::Tipo::real;     ultimoTipo = (yyvsp[0].tipo); }
#line 2195 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 361 "parser.y" /* yacc.c:1646  */
    { (yyval.tipo) = AST::Tipo::boolean;  ultimoTipo = (yyvsp[0].tipo); }
#line 2201 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 366 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Boolean  ( (yyvsp[0].valores) ); }
#line 2207 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 367 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Inteiro  ( (yyvsp[0].valores) ); }
#line 2213 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 368 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Real     ( (yyvsp[0].valores) ); }
#line 2219 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 372 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Variavel( AST::Tipo::variavel, AST::Tipo::nulo , (yyvsp[0].valores), 0 ); }
#line 2225 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 373 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Variavel( AST::Tipo::variavel, AST::Tipo::nulo, (yyvsp[0].valores), (yyvsp[-1].num_ref) ); }
#line 2231 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 377 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Hash( AST::Tipo::hash, AST::Tipo::nulo , (yyvsp[0].valores), 0 ); }
#line 2237 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 378 "parser.y" /* yacc.c:1646  */
    { (yyval.nodo) = new AST::Hash( AST::Tipo::hash, AST::Tipo::nulo, (yyvsp[0].valores), (yyvsp[-1].num_ref) ); }
#line 2243 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 382 "parser.y" /* yacc.c:1646  */
    {(yyval.num_ref) = (yyval.num_ref) + 1;}
#line 2249 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 386 "parser.y" /* yacc.c:1646  */
    { analisador = true; (yyval.nodo) = new AST::Interpretador(AST::Tipo::interpretador, (yyvsp[0].nodo)); }
#line 2255 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2259 "parser.cpp" /* yacc.c:1646  */
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
#line 388 "parser.y" /* yacc.c:1906  */

