/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "SIL.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	void yyerror(char *);
	int yylex(void);
	//int sym[26];
	int temp, pushcount;
	int regno, count;
	int lable, *a, ty;
	int mem = 0;
	int memL, lcount;
	FILE *fp;
	
	struct argStruct {
		int type;
		char name[25];
		struct argStruct *next;
	};
	
	struct argStruct *arguments;
	struct Gsymbol {
		char name[25];
		int type;               // type = 1 -> Integer, type = 2 -> boolean, type = 0 -> notype
		int size;
		int *binding;
		int bind;
		struct argStruct *argList;
		struct Gsymbol *next;
	};
	struct Gsymbol *table;
	
	struct Lsymbol {
		char name[25];
		int type;
		int bind;
		struct Lsymbol *next;
	};
	struct Lsymbol *Ltable;
	 
	struct node {
		int type;            // Integer Boolean or Void
		int node_type;       // operators or Statement type eg. while etc
		char name[15];
		int value;
		int *binding;
		int bind;
		struct node *argList;
		struct node *l, *m, *r;
		struct node *next, *par;
	};
	typedef struct node* tr;
	#define YYSTYPE tr
	struct node *function, *currFunc;
	
	extern FILE *yyin;
	void print1(struct node*);
	int evaluate(struct node *x);
	struct node *makenode(int, char *, int, struct node*, struct node*, struct node*);
	struct node *update(struct node* a, struct node *l, struct node *m, struct node *r, int);
	int evaluate(struct node *x);
	int getreg();
	void freereg();	
	int codegen(struct node*x);
	int getlable();
	struct Gsymbol* find(char a[26]);
	void printtable();
	void checkTypeError(struct node*, int a, int b, int c);
	void isError(int a, int b);
	void set_type(struct node *a);
	struct node* findnode(struct node* x, char a[20]);
	void addVariable(char a[25], int type, int size);
	void boolcheck(struct node *t);
	void addFunction(char a[25], int type, struct node *l);
	void makeArgList(struct node *a, struct node *b);
	void addType(int type, struct node *t);
	void pushRegisters(int);
	void addToLocalList(struct node *t, int type);
	void addArgListToLtable(struct node *function, struct node *list);
	void pushArguments(struct node* t);
	void popArguments(struct node* t) ;
	void push();
	void popRegisters(int);
	struct Lsymbol * findInLtable(char a[25]);
	void call(char a[30]);
	void pushLocalDecl(int);
	void popLocalDecl(int);
	void fCheckTypeError(struct node *t);
	struct node* makelist(struct node* a, struct node* b);
	struct node* setparametertypes(struct node *t);
	


/* Line 268 of yacc.c  */
#line 165 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     VARIABLE = 259,
     EXIT = 260,
     NUM = 261,
     TYPE = 262,
     DECL = 263,
     ENDDECL = 264,
     LDECL = 265,
     ENDLDECL = 266,
     RETURN = 267,
     INT = 268,
     MAIN = 269,
     WHILE = 270,
     DO = 271,
     ENDWHILE = 272,
     IF = 273,
     THEN = 274,
     ELSE = 275,
     ENDIF = 276,
     READ = 277,
     PRINT = 278,
     BOOLEAN = 279,
     FIRST = 280,
     SECOND = 281,
     WRITE = 282,
     MOD = 283,
     RELOP = 284,
     BOOLOP = 285
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define VARIABLE 259
#define EXIT 260
#define NUM 261
#define TYPE 262
#define DECL 263
#define ENDDECL 264
#define LDECL 265
#define ENDLDECL 266
#define RETURN 267
#define INT 268
#define MAIN 269
#define WHILE 270
#define DO 271
#define ENDWHILE 272
#define IF 273
#define THEN 274
#define ELSE 275
#define ENDIF 276
#define READ 277
#define PRINT 278
#define BOOLEAN 279
#define FIRST 280
#define SECOND 281
#define WRITE 282
#define MOD 283
#define RELOP 284
#define BOOLOP 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 267 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNRULES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,     2,
      37,    39,    31,    29,    38,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,    27,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      25,    26,    28,    33,    34,    35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    14,    18,    21,    23,    29,
      31,    35,    37,    42,    47,    49,    50,    52,    56,    59,
      61,    63,    67,    69,    72,    74,    77,    89,    91,    93,
      96,   100,   103,   105,   109,   111,   114,   116,   120,   131,
     133,   137,   140,   144,   151,   158,   165,   170,   178,   183,
     191,   199,   209,   211,   213,   215,   220,   225,   230,   235,
     239,   243,   247,   251,   255,   259,   263,   267,   269
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    59,    69,    -1,     8,    48,     9,
      -1,    49,    36,    -1,    48,    49,    36,    -1,    50,    51,
      -1,     7,    -1,    37,     7,    38,     7,    39,    -1,    52,
      -1,    51,    38,    52,    -1,     4,    -1,     4,    40,     6,
      41,    -1,    53,    37,    54,    39,    -1,     4,    -1,    -1,
      55,    -1,    54,    36,    55,    -1,    56,    57,    -1,     7,
      -1,    58,    -1,    57,    38,    58,    -1,     4,    -1,    42,
       4,    -1,    60,    -1,    59,    60,    -1,    50,    61,    37,
      62,    39,    43,    10,    63,    11,    67,    44,    -1,     4,
      -1,    54,    -1,    64,    36,    -1,    63,    64,    36,    -1,
      50,    65,    -1,    66,    -1,    65,    38,    66,    -1,     4,
      -1,    71,    68,    -1,    68,    -1,    12,    73,    36,    -1,
      50,    70,    37,    39,    43,    10,    63,    11,    67,    44,
      -1,    14,    -1,    71,    72,    36,    -1,    72,    36,    -1,
       4,    27,    73,    -1,     4,    40,    73,    41,    27,    73,
      -1,    25,    37,     4,    39,    27,    73,    -1,    26,    37,
       4,    39,    27,    73,    -1,    22,    37,     4,    39,    -1,
      22,    37,     4,    40,    73,    41,    39,    -1,    28,    37,
      73,    39,    -1,    15,    37,    73,    39,    16,    71,    17,
      -1,    18,    37,    73,    39,    19,    71,    21,    -1,    18,
      37,    73,    39,    19,    71,    20,    71,    21,    -1,     5,
      -1,     6,    -1,     4,    -1,     4,    40,    73,    41,    -1,
       4,    37,    74,    39,    -1,    25,    37,     4,    39,    -1,
      26,    37,     4,    39,    -1,    73,    29,    73,    -1,    73,
      30,    73,    -1,    73,    31,    73,    -1,    73,    32,    73,
      -1,    73,    33,    73,    -1,    73,    34,    73,    -1,    73,
      35,    73,    -1,    37,    73,    39,    -1,    73,    -1,    74,
      38,    73,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   111,   115,   116,   120,   124,   125,   128,
     129,   133,   139,   140,   143,   146,   147,   148,   151,   154,
     157,   158,   161,   162,   165,   166,   169,   188,   200,   203,
     204,   207,   210,   211,   214,   222,   223,   226,   239,   249,
     260,   262,   266,   268,   273,   278,   283,   284,   285,   286,
     287,   288,   289,   293,   294,   295,   296,   313,   317,   321,
     322,   323,   324,   325,   326,   327,   328,   331,   332
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "VARIABLE", "EXIT", "NUM",
  "TYPE", "DECL", "ENDDECL", "LDECL", "ENDLDECL", "RETURN", "INT", "MAIN",
  "WHILE", "DO", "ENDWHILE", "IF", "THEN", "ELSE", "ENDIF", "READ",
  "PRINT", "BOOLEAN", "FIRST", "SECOND", "'='", "WRITE", "'+'", "'-'",
  "'*'", "'/'", "MOD", "RELOP", "BOOLOP", "';'", "'('", "','", "')'",
  "'['", "']'", "'&'", "'{'", "'}'", "$accept", "program", "declaration",
  "declist", "decl", "type", "varlist", "variable", "funcname", "ArgList",
  "ArgDecl", "ArgType", "ArgVarList", "ArgVar", "fdeflist", "fdef", "fID",
  "ArgDefList", "ldeclist", "ldecl", "lvarlist", "lvar", "body", "retstmt",
  "Mainblock", "main", "slist", "statement", "expr", "parameterList", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    61,   282,    43,
      45,    42,    47,   283,   284,   285,    59,    40,    44,    41,
      91,    93,    38,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    48,    48,    49,    50,    50,    51,
      51,    52,    52,    52,    53,    54,    54,    54,    55,    56,
      57,    57,    58,    58,    59,    59,    60,    61,    62,    63,
      63,    64,    65,    65,    66,    67,    67,    68,    69,    70,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     3,     2,     1,     5,     1,
       3,     1,     4,     4,     1,     0,     1,     3,     2,     1,
       1,     3,     1,     2,     1,     2,    11,     1,     1,     2,
       3,     2,     1,     3,     1,     2,     1,     3,    10,     1,
       3,     2,     3,     6,     6,     6,     4,     7,     4,     7,
       7,     9,     1,     1,     1,     4,     4,     4,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     7,     0,     0,     0,     0,     1,
       0,     0,    24,     0,     3,     0,     4,    11,     6,     9,
       0,    27,     0,     0,    25,     2,     0,     5,     0,     0,
      15,    15,    39,     0,     0,     0,    10,    19,     0,    16,
       0,    28,     0,     0,     8,    12,     0,    13,    22,     0,
      18,    20,     0,     0,    17,    23,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    34,    31,    32,     0,
       0,    29,     0,     0,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,    36,     0,     0,    30,     0,    33,
       0,     0,    54,    53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,    35,     0,    41,    38,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
      40,     0,    67,     0,     0,     0,     0,    66,    59,    60,
      61,    62,    63,    64,    65,     0,     0,    46,     0,     0,
       0,    48,     0,     0,    56,    55,    57,    58,     0,     0,
       0,     0,     0,    43,    68,     0,     0,     0,    44,    45,
      49,     0,    50,    47,     0,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     7,    62,    18,    19,    20,    38,
      39,    40,    50,    51,    11,    12,    22,    42,    63,    64,
      67,    68,    83,    84,    25,    33,    85,    86,    97,   133
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -120
static const yytype_int16 yypact[] =
{
      26,    -2,    36,    -2,  -120,    35,     6,    18,    45,  -120,
      52,    -2,  -120,    29,  -120,    47,  -120,   -19,    33,  -120,
      53,  -120,    54,    43,  -120,  -120,    77,  -120,    87,    45,
      96,    96,  -120,    57,    66,    65,  -120,  -120,    12,  -120,
      -1,    73,    72,    78,  -120,  -120,    96,  -120,  -120,   112,
      83,  -120,    86,    89,  -120,  -120,    -1,   116,   126,  -120,
      -2,    -2,   155,     1,    84,     9,  -120,   122,  -120,    70,
     125,  -120,    70,   155,   -16,  -120,     0,   135,   137,   138,
     139,   148,   150,   118,  -120,    70,   161,  -120,   119,  -120,
       0,     0,    13,  -120,   159,   170,     0,   193,     0,     0,
     169,   194,   204,     0,  -120,  -120,   173,  -120,  -120,   201,
     110,     0,     0,   214,   215,   149,     0,     0,     0,     0,
       0,     0,     0,  -120,   160,   171,    30,   147,   181,   182,
    -120,   210,   201,    38,   123,   199,   200,  -120,   115,   115,
      44,    44,    44,   205,  -120,   225,   223,  -120,     0,   216,
     217,  -120,     0,     0,  -120,  -120,  -120,  -120,   109,   109,
     136,     0,     0,   201,   201,    82,    40,   206,   201,   201,
    -120,   109,  -120,  -120,    97,  -120
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,  -120,  -120,   240,   127,  -120,   218,  -120,   219,
     202,  -120,  -120,   195,  -120,   238,  -120,  -120,   191,   -46,
    -120,   180,   183,   172,  -120,  -120,  -119,   -85,   -89,  -120
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -15
static const yytype_int16 yytable[] =
{
     106,   109,   110,    48,    92,     4,    93,   115,     4,   124,
     125,    90,    69,     4,   129,    14,     4,    70,   -14,    70,
      72,    28,   132,   134,    91,    94,    95,   138,   139,   140,
     141,   142,   143,   144,     1,     5,     9,    96,     5,   165,
     166,    49,    13,     5,    74,    75,     5,    21,    46,    17,
     111,    47,   174,   112,    16,    77,    21,    32,    78,   160,
     171,   172,    79,   163,   164,    80,    81,    26,    82,   147,
     148,    29,   168,   169,    74,    75,   153,   154,   121,   122,
     106,   106,    76,    27,    34,    77,    74,    75,    78,   106,
      30,    31,    79,    35,    43,    80,    81,    77,    82,   170,
      78,    74,    75,    37,    79,    44,    45,    80,    81,    46,
      82,    52,    77,    74,    75,    78,    55,    53,   175,    79,
      71,    56,    80,    81,    77,    82,    60,    78,     8,    57,
      10,    79,    58,     8,    80,    81,    61,    82,    23,   116,
     117,   118,   119,   120,   121,   122,   118,   119,   120,   121,
     122,   131,   116,   117,   118,   119,   120,   121,   122,    66,
      73,    87,   104,   108,   155,   116,   117,   118,   119,   120,
     121,   122,    98,   126,    99,   100,   101,   167,   116,   117,
     118,   119,   120,   121,   122,   102,   149,   103,   137,   116,
     117,   118,   119,   120,   121,   122,   113,   107,   127,   145,
     116,   117,   118,   119,   120,   121,   122,   114,   128,   130,
     146,   116,   117,   118,   119,   120,   121,   122,   135,   136,
     150,   151,   116,   117,   118,   119,   120,   121,   122,   123,
     116,   117,   118,   119,   120,   121,   122,   152,   156,   157,
     122,   158,   159,   161,   162,   173,    15,    36,    54,    24,
      41,    59,    65,    89,     0,    88,     0,   105
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-120))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      85,    90,    91,     4,     4,     7,     6,    96,     7,    98,
      99,    27,    11,     7,   103,     9,     7,    63,    37,    65,
      11,    40,   111,   112,    40,    25,    26,   116,   117,   118,
     119,   120,   121,   122,     8,    37,     0,    37,    37,   158,
     159,    42,     7,    37,     4,     5,    37,     4,    36,     4,
      37,    39,   171,    40,    36,    15,     4,    14,    18,   148,
      20,    21,    22,   152,   153,    25,    26,    38,    28,    39,
      40,    38,   161,   162,     4,     5,    38,    39,    34,    35,
     165,   166,    12,    36,     7,    15,     4,     5,    18,   174,
      37,    37,    22,     6,    37,    25,    26,    15,    28,    17,
      18,     4,     5,     7,    22,    39,    41,    25,    26,    36,
      28,    39,    15,     4,     5,    18,     4,    39,    21,    22,
      36,    38,    25,    26,    15,    28,    10,    18,     1,    43,
       3,    22,    43,     6,    25,    26,    10,    28,    11,    29,
      30,    31,    32,    33,    34,    35,    31,    32,    33,    34,
      35,    41,    29,    30,    31,    32,    33,    34,    35,     4,
      38,    36,    44,    44,    41,    29,    30,    31,    32,    33,
      34,    35,    37,     4,    37,    37,    37,    41,    29,    30,
      31,    32,    33,    34,    35,    37,    39,    37,    39,    29,
      30,    31,    32,    33,    34,    35,    37,    36,     4,    39,
      29,    30,    31,    32,    33,    34,    35,    37,     4,    36,
      39,    29,    30,    31,    32,    33,    34,    35,     4,     4,
      39,    39,    29,    30,    31,    32,    33,    34,    35,    36,
      29,    30,    31,    32,    33,    34,    35,    27,    39,    39,
      35,    16,    19,    27,    27,    39,     6,    29,    46,    11,
      31,    56,    61,    73,    -1,    72,    -1,    85
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    46,    47,     7,    37,    48,    49,    50,     0,
      50,    59,    60,     7,     9,    49,    36,     4,    51,    52,
      53,     4,    61,    50,    60,    69,    38,    36,    40,    38,
      37,    37,    14,    70,     7,     6,    52,     7,    54,    55,
      56,    54,    62,    37,    39,    41,    36,    39,     4,    42,
      57,    58,    39,    39,    55,     4,    38,    43,    43,    58,
      10,    10,    50,    63,    64,    63,     4,    65,    66,    11,
      64,    36,    11,    38,     4,     5,    12,    15,    18,    22,
      25,    26,    28,    67,    68,    71,    72,    36,    67,    66,
      27,    40,     4,     6,    25,    26,    37,    73,    37,    37,
      37,    37,    37,    37,    44,    68,    72,    36,    44,    73,
      73,    37,    40,    37,    37,    73,    29,    30,    31,    32,
      33,    34,    35,    36,    73,    73,     4,     4,     4,    73,
      36,    41,    73,    74,    73,     4,     4,    39,    73,    73,
      73,    73,    73,    73,    73,    39,    39,    39,    40,    39,
      39,    39,    27,    38,    39,    41,    39,    39,    16,    19,
      73,    27,    27,    73,    73,    71,    71,    41,    73,    73,
      17,    20,    21,    39,    71,    21
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 103 "SIL.y"
    { 
												(yyval) = makenode(5, "program", 0, (yyvsp[(2) - (3)]), NULL, NULL);
											 	//print1($$);
											 	// evaluate($$);
											}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 111 "SIL.y"
    {}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 115 "SIL.y"
    {}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 116 "SIL.y"
    {}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 120 "SIL.y"
    {}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 124 "SIL.y"
    {ty = (yyvsp[(1) - (1)]) -> type;}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 125 "SIL.y"
    {ty = (yyvsp[(2) - (5)]) -> type * 100 + (yyvsp[(4) - (5)]) -> type;}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 128 "SIL.y"
    {}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 129 "SIL.y"
    {}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 133 "SIL.y"
    { 
												if(ty >= 100)
													addVariable((yyvsp[(1) - (1)])->name, ty, 2);
												else
													addVariable((yyvsp[(1) - (1)])->name, ty, 1);
											}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 139 "SIL.y"
    { addVariable((yyvsp[(1) - (4)])-> name, ty, (yyvsp[(3) - (4)])->value);}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 140 "SIL.y"
    { addFunction(function -> name, function -> type, (yyvsp[(3) - (4)]));}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 143 "SIL.y"
    {(yyvsp[(1) - (1)]) -> type = ty; function = (yyvsp[(1) - (1)]); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 146 "SIL.y"
    {(yyval) = NULL;}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 147 "SIL.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 148 "SIL.y"
    {makeArgList((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); (yyval) = (yyvsp[(1) - (3)]);}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 151 "SIL.y"
    {(yyval) = (yyvsp[(2) - (2)]);}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 154 "SIL.y"
    {ty = (yyvsp[(1) - (1)]) -> type;}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 157 "SIL.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 158 "SIL.y"
    {makeArgList((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); (yyval) = (yyvsp[(1) - (3)]);}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 161 "SIL.y"
    {addType(ty, (yyvsp[(1) - (1)])); (yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 162 "SIL.y"
    {addType(ty + 10, (yyvsp[(2) - (2)])); (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 165 "SIL.y"
    {}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 166 "SIL.y"
    {}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 169 "SIL.y"
    {	
																				regno = 0; 
																				/*struct Lsymbol *t = Ltable;
																				while(t != NULL) {
																					printf("%s %d %d\n",t -> name, t->type, t->bind);
																					t = t -> next;
																				}*/
																				fprintf(fp, "PUSH BP\n");
																				fprintf(fp, "MOV BP, SP\n");
																				pushLocalDecl(lcount);
																				codegen((yyvsp[(10) - (11)]));
																				popLocalDecl(lcount);
																				fprintf(fp, "POP BP\n");
																				fprintf(fp, "RET\n");
																				lcount = 0;
																				Ltable = NULL;
																			 }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 188 "SIL.y"
    {	memL = 1;
												struct Gsymbol *t = find((yyvsp[(1) - (1)]) -> name);
												if(t == NULL)
													printf("function not defined %d\n", count); 
												(yyvsp[(1) - (1)]) -> type = ty; 
												function = (yyvsp[(1) - (1)]); 
												(yyval) = (yyvsp[(1) - (1)]);
												fprintf(fp, "%s:\n", (yyvsp[(1) - (1)]) -> name);
												//printf("%s\n", $1->name);
											}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 200 "SIL.y"
    {addArgListToLtable(function, (yyvsp[(1) - (1)]));}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 203 "SIL.y"
    {}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 204 "SIL.y"
    {}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 207 "SIL.y"
    {ty = (yyvsp[(1) - (2)]) -> type; }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 210 "SIL.y"
    {}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 211 "SIL.y"
    {}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 214 "SIL.y"
    { 
												addToLocalList((yyvsp[(1) - (1)]), ty); lcount++;
												if(ty >= 100)
													lcount++; 
											}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 222 "SIL.y"
    {(yyval) = makenode(6, "FuncBody", 0, (yyvsp[(1) - (2)]), NULL, (yyvsp[(2) - (2)])); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 223 "SIL.y"
    {(yyval) = makenode(6, "FuncBody", 0, (yyvsp[(1) - (1)]), NULL, NULL); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 226 "SIL.y"
    {
												(yyval) = makenode(6, "return", 0, (yyvsp[(2) - (3)]), NULL, NULL);
												if(strcmp(function -> name, "main") != 0) {
											 		struct Gsymbol *t = find(function -> name);	
											 		//printf("type %d %d\n", t -> type, $2 -> type);
											 		if((yyvsp[(2) - (3)]) -> type%10 != t -> type%10) {
											 			printf("Type Error \n Line no. : %d\n", count);
											 			exit(EXIT_SUCCESS);
											 		}
											 	}
											}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 239 "SIL.y"
    { 
																		pushLocalDecl(lcount);
																		//print1($9);
																		codegen((yyvsp[(9) - (10)]));
																		popLocalDecl(lcount);
																		fprintf(fp, "%s\n", "HALT");
																		Ltable = NULL; 
																		lcount = 0;
																	}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 249 "SIL.y"
    {
																		memL = 1;
																		regno = 1;
																		fprintf(fp, "%s\n", "START");
																		fprintf(fp, "MOV BP, %d\n", mem);
																		fprintf(fp, "MOV SP, BP\n");
																		strcpy(function -> name, "main");
																		function -> type = 1;
																	}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 260 "SIL.y"
    {(yyval) = makenode(4, "slist", 0, (yyvsp[(1) - (3)]), NULL, (yyvsp[(2) - (3)]));}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 262 "SIL.y"
    {(yyval) = makenode(4, "statement", 0, (yyvsp[(1) - (2)]), NULL, NULL);}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 266 "SIL.y"
    { (yyval) = update((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), NULL, (yyvsp[(3) - (3)]), 0); 
															  set_type((yyvsp[(1) - (3)])); boolcheck((yyvsp[(2) - (3)])); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 268 "SIL.y"
    { 
																(yyval) = update((yyvsp[(5) - (6)]), (yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(6) - (6)]), 0); 
															  	isError((yyvsp[(3) - (6)]) -> type, 1); 
															  	set_type((yyvsp[(1) - (6)])); boolcheck((yyvsp[(5) - (6)]));
															}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 273 "SIL.y"
    {	
																set_type((yyvsp[(3) - (6)]));
																(yyvsp[(1) - (6)]) = update((yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]), NULL, NULL, (yyvsp[(3) - (6)])->type/100);
																(yyval) = update((yyvsp[(5) - (6)]), (yyvsp[(1) - (6)]), NULL, (yyvsp[(6) - (6)]), 0);
															}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 278 "SIL.y"
    {
																set_type((yyvsp[(3) - (6)]));
																(yyvsp[(1) - (6)]) = update((yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]), NULL, NULL, (yyvsp[(3) - (6)]) -> type/100);
																(yyval) = update((yyvsp[(5) - (6)]), (yyvsp[(1) - (6)]), NULL, (yyvsp[(6) - (6)]), 0);
															}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 283 "SIL.y"
    {(yyval) = update((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL, 0); set_type((yyvsp[(3) - (4)])); isError((yyvsp[(3) - (4)]) -> type, 1);}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 284 "SIL.y"
    {(yyval) = update((yyvsp[(1) - (7)]) , (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), NULL, 0);  set_type((yyvsp[(3) - (7)]));  isError((yyvsp[(3) - (7)]) -> type, 1);}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 285 "SIL.y"
    {(yyval) = update((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL, 0); isError((yyvsp[(3) - (4)]) -> type, 1);}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 286 "SIL.y"
    {(yyval) = update((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), NULL, (yyvsp[(6) - (7)]), 0); isError((yyvsp[(3) - (7)]) -> type, 2);}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 287 "SIL.y"
    {(yyval) = update((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(6) - (7)]), NULL, 0); isError((yyvsp[(3) - (7)]) -> type, 2);}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 288 "SIL.y"
    {(yyval) = update((yyvsp[(1) - (9)]), (yyvsp[(3) - (9)]), (yyvsp[(6) - (9)]), (yyvsp[(8) - (9)]), 0); isError((yyvsp[(3) - (9)]) -> type, 2);}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 289 "SIL.y"
    {(yyval) = update((yyvsp[(1) - (1)]), NULL, NULL, NULL, 0); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 293 "SIL.y"
    {(yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 294 "SIL.y"
    {(yyval) = (yyvsp[(1) - (1)]); set_type((yyvsp[(1) - (1)]));}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 295 "SIL.y"
    {(yyval) = update((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL, (yyvsp[(1) - (4)]) -> type); set_type((yyvsp[(1) - (4)])); isError((yyvsp[(3) - (4)]) -> type, 1);}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 296 "SIL.y"
    {
													struct Gsymbol *g = find((yyvsp[(1) - (4)]) -> name);
													arguments = g -> argList;
													while(arguments) {
														printf("%s %d\n", arguments -> name, arguments -> type);
														arguments = arguments -> next;
													}
													arguments = g -> argList;
													(yyvsp[(3) - (4)]) = setparametertypes((yyvsp[(3) - (4)]));
													arguments = g -> argList;
													fCheckTypeError((yyvsp[(3) - (4)]));	
													(yyvsp[(1) - (4)]) -> node_type = 7;
													struct node *a = (struct node *) malloc(sizeof(struct node*));
													strcpy(a -> name, "call");
													a -> node_type = 7; 
													(yyval) = update((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), a, NULL, (yyvsp[(1) - (4)]) -> type); set_type((yyvsp[(1) - (4)]));
												}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 313 "SIL.y"
    {
													set_type((yyvsp[(3) - (4)])); 
													(yyval) = update((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL, (yyvsp[(3) - (4)]) -> type/100); 
												}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 317 "SIL.y"
    {	
													set_type((yyvsp[(3) - (4)]));
													(yyval) = update((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL, (yyvsp[(3) - (4)]) -> type%100);
												}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 321 "SIL.y"
    {(yyval) = update((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), NULL, (yyvsp[(3) - (3)]), 1); checkTypeError((yyvsp[(2) - (3)]), 1, 1, 1);}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 322 "SIL.y"
    {(yyval) = update((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), NULL, (yyvsp[(3) - (3)]), 1); checkTypeError((yyvsp[(2) - (3)]), 1, 1, 1);}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 323 "SIL.y"
    {(yyval) = update((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), NULL, (yyvsp[(3) - (3)]), 1); checkTypeError((yyvsp[(2) - (3)]), 1, 1, 1);}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 324 "SIL.y"
    {(yyval) = update((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), NULL, (yyvsp[(3) - (3)]), 1); checkTypeError((yyvsp[(2) - (3)]), 1, 1, 1);}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 325 "SIL.y"
    {(yyval) = update((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), NULL, (yyvsp[(3) - (3)]), 1); checkTypeError((yyvsp[(2) - (3)]), 1, 1, 1);}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 326 "SIL.y"
    {(yyval) = update((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), NULL, (yyvsp[(3) - (3)]), 2); checkTypeError((yyvsp[(2) - (3)]), 2, 1, 1);}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 327 "SIL.y"
    {(yyval) = update((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), NULL, (yyvsp[(3) - (3)]), 2); checkTypeError((yyvsp[(2) - (3)]), 2, 2, 2);}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 328 "SIL.y"
    {(yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 331 "SIL.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 332 "SIL.y"
    {(yyval) = makelist((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;



/* Line 1806 of yacc.c  */
#line 2215 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 335 "SIL.y"


struct node* setparametertypes(struct node *t) {
	struct node *top;
	top = t;
	while(top) {
		printf("%s \n", top ->name);
		addType(arguments -> type, top);
		arguments = arguments -> next;
		top = top -> next;
	}
	return t;
}	
	
struct node* makelist(struct node* a, struct node* b) {
	b -> next = a;
	return b;
}

int codegen(struct node *x) {
	if (x != NULL) {
		int i, m, j, l1, l2, l3, k;
		i = 0;
		
		if(x-> node_type == 0) {      						// INTEGER Value
			i = getreg();
			fprintf(fp, "MOV R%d, %d\n", i, x->value);
			//printf("MOV R%d, %d", i, x->value);
		}	
		
		if(x -> node_type == 2) {     						// Variable  
			i = getreg();
			struct Lsymbol *t;
			t = findInLtable(x -> name);
			//printf("name %s bind %d type %d\n", x->name, x->bind, x->type);	
			if(x -> type >= 100) {
				i = getreg();
				fprintf(fp, "MOV R%d, %d\n", i, x->bind);
				j = getreg();
				fprintf(fp, "MOV R%d, BP\n", j);
				fprintf(fp, "ADD R%d, R%d\n", i, j);
				freereg();
				fprintf(fp, "MOV R%d, [R%d]\n", i, i);
				j = getreg();
				fprintf(fp, "MOV R%d, %d\n", j, x->bind+1);
				k = getreg();
				fprintf(fp, "MOV R%d, BP\n", k);
				fprintf(fp, "ADD R%d, R%d\n", j, k);
				freereg();
				fprintf(fp, "MOV R%d, [R%d]\n", j, j);
				i = j;
			}
			else	
			if(x -> l != NULL) {
				m = x -> bind;
				fprintf(fp, "MOV R%d, %d\n", i, m);
				j = codegen(x -> l);
				fprintf(fp, "ADD R%d, R%d\n", j, i);
				fprintf(fp, "MOV R%d, [R%d]\n", i, j);
				freereg(); 
			}	
			else {
				if(t != NULL) {
					if(t -> type >= 10) {
						//printf("variable\n");
						fprintf(fp, "MOV R%d, %d\n", i, x->bind);
						j = getreg();
						fprintf(fp, "MOV R%d, BP\n", j);
						fprintf(fp, "ADD R%d, R%d\n", i, j);
						fprintf(fp, "MOV R%d, [R%d]\n", i, i);
						fprintf(fp, "MOV R%d, [R%d]\n", i, i);
						freereg();
					}
					else {
						fprintf(fp, "MOV R%d, %d\n", i, t -> bind);
						j = getreg();
						fprintf(fp, "MOV R%d, BP\n", j);
						fprintf(fp, "ADD R%d, R%d\n", i, j);
						freereg();
						fprintf(fp, "MOV R%d, [R%d]\n", i, i);
					}
				}
				else {
					m = x -> bind;
					fprintf(fp, "MOV R%d, [%d]\n", i, m);
				}
		 	}
		}
		
		if(x -> node_type == 1) {					// operators
			if(strcmp("+", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "ADD R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("-", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "SUB R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("*", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "MUL R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("/", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "DIV R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("mod", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "MOD R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp(">", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "GT R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("<", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "LT R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp(">=", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "GE R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("<=", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "LE R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("==", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "EQ R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("!=", x -> name) == 0) {
				i = codegen(x -> l);
				j = codegen(x -> r);
				fprintf(fp, "NE R%d, R%d\n", i, j);
				freereg();
			}
			if(strcmp("=", x -> name) == 0) {
				i = codegen(x -> r);
				struct Lsymbol *t;
				t = findInLtable(x -> l -> name);
				if(strcmp(x->l->name, "first") == 0) {
					t = findInLtable(x -> l -> l -> name);
					j = getreg();
					fprintf(fp, "MOV R%d, %d\n", j, t -> bind);
					k = getreg();
					fprintf(fp, "MOV R%d, BP\n", k);
					fprintf(fp, "ADD R%d, R%d\n", j, k);
					freereg();
					fprintf(fp, "MOV [R%d], R%d\n", j, i);
					freereg();
				}
				else
				if(strcmp(x->l->name, "second") == 0) {
					t = findInLtable(x -> l -> l -> name);
					j = getreg();
					fprintf(fp, "MOV R%d, %d\n", j, t -> bind + 1);
					k = getreg();
					fprintf(fp, "MOV R%d, BP\n", k);
					fprintf(fp, "ADD R%d, R%d\n", j, k);
					freereg();
					fprintf(fp, "MOV [R%d], R%d\n", j, i);
					freereg();
				}
				else
				if(x -> l -> type >= 100) {
					t = findInLtable(x -> l -> name);
					if(t != NULL) {
						j = getreg();
						fprintf(fp, "MOV R%d, %d\n", j, t -> bind);
						k = getreg();
						fprintf(fp, "MOV R%d, BP\n", k);
						fprintf(fp, "ADD R%d, R%d\n", j, k);
						freereg();
						fprintf(fp, "MOV [R%d], R%d\n", j, i-1);
						freereg();
						
						j = getreg();
						fprintf(fp, "MOV R%d, %d\n", j, t -> bind + 1);
						k = getreg();
						fprintf(fp, "MOV R%d, BP\n", k);
						fprintf(fp, "ADD R%d, R%d\n", j, k);
						freereg();
						fprintf(fp, "MOV [R%d], R%d\n", j, i);
						freereg();
					}
				}else	
				if(x -> m != NULL){
					m = x -> l -> bind;
					k = getreg();
					fprintf(fp, "MOV R%d, %d\n", k, m);
					j = codegen(x -> m);
					fprintf(fp, "ADD R%d, R%d\n", k , j);
					freereg();
					fprintf(fp, "MOV [R%d], R%d\n", k, i);
					freereg();
				}
				else {
					m = x -> l -> bind;
					if(t != NULL) {
						if(t -> type >= 10) {
							j = getreg();
							fprintf(fp, "MOV R%d, %d\n", j, x->l->bind);
							k = getreg();
							fprintf(fp, "MOV R%d, BP\n", k);
							fprintf(fp, "ADD R%d, R%d\n", j, k);
							fprintf(fp, "MOV R%d, [R%d]\n", j, j);
							freereg();
							fprintf(fp, "MOV [R%d], R%d\n", j, i);
							freereg();
						}
						else {
							j = getreg();
							fprintf(fp, "MOV R%d, %d\n", j, m);
							k = getreg();
							fprintf(fp, "MOV R%d, BP\n", k);
							fprintf(fp, "ADD R%d, R%d\n", j, k);
							freereg();
							fprintf(fp, "MOV [R%d], R%d\n", j, i);
							freereg();
						}
					}
					else {
						fprintf(fp, "MOV [%d], R%d\n", m, i);
					}
				}	
				freereg();
			}	
		}
		
		if(x -> node_type == 3) {					// Reserved words
			
			if(strcmp("first", x -> name) == 0) {
				struct Lsymbol *t = findInLtable(x -> l -> name);
				if(t != NULL) {
					i = getreg();
					fprintf(fp, "MOV R%d %d\n", i, t -> bind);
					j = getreg();
					fprintf(fp, "MOV R%d BP\n", j);
					fprintf(fp, "ADD R%d R%d\n", i, j);
					freereg();
					fprintf(fp, "MOV R%d, [R%d]\n", i, i);
				}
				else {
					struct Gsymbol *s = find(x -> l -> name);
					if(s != NULL) {
						i = getreg();
						fprintf(fp, "MOV R%d %d\n", i, s -> bind);
						fprintf(fp, "MOV R%d, [R%d]\n", i, i);
					}
				}
			}
			if(strcmp("second", x -> name) == 0) {
				struct Lsymbol *t = findInLtable(x -> l -> name);
				if(t != NULL) {
					i = getreg();
					fprintf(fp, "MOV R%d %d\n", i, t -> bind + 1);
					j = getreg();
					fprintf(fp, "MOV R%d BP\n", j);
					fprintf(fp, "ADD R%d R%d\n", i, j);
					freereg();
					fprintf(fp, "MOV R%d, [R%d]\n", i, i);
				}
				else {
					struct Gsymbol *s = find(x -> l -> name);
					if(s != NULL) {
						i = getreg();
						fprintf(fp, "MOV R%d %d\n", i, s -> bind + 1);
						fprintf(fp, "MOV R%d, [R%d]\n", i, i);
					}
				}
			}				
			if(strcmp("write", x -> name) == 0) {
				i = codegen(x -> l);
				fprintf(fp, "OUT R%d\n", i);
				freereg();
			}
			if(strcmp("read", x -> name) == 0) {
				if(x -> m == NULL) {
					i = getreg();
					//struct Gsymbol *t = find(x -> l -> name);
					fprintf(fp, "MOV R%d, %d\n", i, x -> l-> bind);
					j = getreg();
					fprintf(fp, "IN R%d\n", j);
					fprintf(fp, "MOV [R%d], R%d\n", i, j);
					freereg();
					freereg();
				}
				else {
					i = getreg();
					//struct Gsymbol *t = find(x -> l -> name);
					fprintf(fp, "MOV R%d, %d\n", i, x -> l -> bind);
					j = codegen(x -> m);
					fprintf(fp, "ADD R%d, R%d\n", i, j);
					freereg();
					k = getreg();
					fprintf(fp, "IN R%d\n", k);
					fprintf(fp, "MOV [R%d], R%d\n", i, k);
					freereg();
					freereg();
				}	
			}
			if(strcmp("while", x -> name) == 0) {
				l1 = getlable();
				l2 = getlable();
				
				fprintf(fp, "L%d:\n", l1);
				
				i = codegen(x->l);
				fprintf(fp, "JZ R%d, L%d\n", i, l2);
				freereg();
				
				i = codegen(x->r);
				fprintf(fp, "JMP L%d\nL%d:\n", l1, l2);
			}
				
			if(strcmp("if", x -> name) == 0) {
				l1 = getlable();
				l2 = getlable();
				
				i = codegen(x -> l);
				fprintf(fp, "JZ R%d L%d\n", i, l1);
				freereg();
				i = codegen(x -> m);
				fprintf(fp, "JMP L%d\nL%d:\n", l2, l1);
				i = codegen(x -> r);
				fprintf(fp, "L%d:\n", l2);
			}
				
		}
				
		if(x -> node_type == 4) {                     		// Statement and statement lists
				if(strcmp("slist", x->name) == 0) {
					codegen(x -> l);
					codegen(x -> r);
				}
				if(strcmp("statement", x->name) == 0) 
					codegen(x -> l);
		}
		
		if(x -> node_type == 5) 							// Program
			codegen(x -> l);
		
		if(x -> node_type == 6) {							// Function declaration		
			if(strcmp("FuncBody", x -> name) == 0) {
				codegen(x -> l);
				k = codegen(x -> r);
				i = getreg();
				fprintf(fp, "MOV R%d, %d\n", i, -2);
				j = getreg();
				fprintf(fp, "MOV R%d, BP\n", j);
				fprintf(fp, "ADD R%d, R%d\n", i, j);
				freereg();
				fprintf(fp, "MOV [R%d], R%d\n", i, k);
				if(function -> type >= 100) {
					i = getreg();
					fprintf(fp, "MOV R%d, %d\n", i, -3);
					j = getreg();
					fprintf(fp, "MOV R%d, BP\n", j);
					fprintf(fp, "ADD R%d, R%d\n", i, j);
					freereg();
					fprintf(fp, "MOV [R%d], R%d\n", i, k-1);
				}
				freereg();
			}
			if(strcmp("return", x -> name) == 0)
				i = codegen(x -> l);
		}
		
		if(x -> node_type == 7) {					// Function call
			
			if(function != NULL && strcmp(function -> name, "main") != 0) {
				struct Gsymbol *g = find(function -> name);
				if(g != NULL) 
					arguments = g -> argList;
			}
			else
				arguments = NULL;
			
			pushRegisters(regno - 1);
			pushcount = regno - 1;
			pushArguments(x -> l); 
			push(); 
			if(x -> type >= 100)
				push();
			call(x -> name);
			i = getreg();
			i = getreg();
			if(x -> type >= 100)
				i = getreg();
			//printf("PushCount: %d %d %d\n", pushcount, i, regno);	
			fprintf(fp, "POP R%d\n", i);
			if(x -> type >= 100)
				fprintf(fp, "POP R%d\n", i - 1);
			popArguments(x -> l);
			popRegisters(pushcount);
		}			
	return i;
	}	
}	

void fCheckTypeError(struct node *t) {
	if(t != NULL) {
		if(t -> node_type == 0 || t -> node_type == 2) {
			if(t -> type%10 == arguments -> type%10) {
				arguments = arguments -> next;
				fCheckTypeError(t -> r);
				fCheckTypeError(t -> l);
			}
			else { 
				printf("Type Error\nLINE NO %d\n", count);
				exit(EXIT_SUCCESS);
			}	
		}
		if(t -> node_type == 4) {
			fCheckTypeError(t -> r);
			fCheckTypeError(t -> l);
		}
	}
}

void pushLocalDecl(int lct) {
	while(lct--) {
		fprintf(fp, "PUSH R0\n");
	}
}

void popLocalDecl(int lct) {
	while(lct--) {
		fprintf(fp, "POP R0\n");
	}
}	

void pushArguments(struct node* t) {
	int i, j, k;
	if(t != NULL) {
		pushArguments(t -> next);
		//if(arguments != NULL)
			//printf("arguments: %s %s %d %d\n", arguments -> name, function -> name, arguments -> type, t -> type);
		if(t -> type >= 10 && arguments != NULL && arguments -> type >= 10) {
			i = getreg();
			fprintf(fp, "MOV R%d, %d\n", i, t -> bind);
			j = getreg();
			fprintf(fp, "MOV R%d, BP\n", j);
			fprintf(fp, "ADD R%d, R%d\n", i, j);
			freereg();
			fprintf(fp, "MOV R%d, [R%d]\n", i, i);
		}
		else if(t -> type >= 10) {
			i = getreg();
			fprintf(fp,"MOV R%d, %d\n", i, t->bind);
			j = getreg();
			fprintf(fp, "MOV R%d, BP\n", j);
			fprintf(fp, "ADD R%d, R%d\n", i, j);
			freereg();
		}
		else
			i = codegen(t);
		if(arguments != NULL)
			arguments = arguments -> next;
		fprintf(fp, "PUSH R%d\n", i);
		freereg();
	}
}

void popArguments(struct node* x) {
	if(x != NULL) {
		fprintf(fp, "POP R0\n");
		popArguments(x->next);
	}
}

struct Lsymbol * findInLtable(char a[25]) {
	struct Lsymbol *t = Ltable;
	
	while(t != NULL) {
		//printf("TName: %s %s\n", t -> name, a);
		if(strcmp(a, t -> name) == 0)
			return t;
		t = t -> next;
	}
}				

void pushRegisters(int k) {
	int i, size;
	
	size = k;
	i = 0;
	
	while(i <= size) {
		fprintf(fp, "PUSH R%d\n", i);
		i = i + 1;
	}
}

void addToLocalList(struct node *t, int type) {
	struct Lsymbol *lt = (struct Lsymbol*) malloc(sizeof(struct Lsymbol));
	
	strcpy(lt -> name, t -> name);
	lt -> type = type;
	lt -> bind = memL;
	memL++;
	if(type >= 100)
		memL++;
	
	if(Ltable == NULL)
		Ltable = lt;
	else {
		lt -> next = Ltable;
		Ltable = lt;
	}
}

void addArgListToLtable(struct node *func, struct node *list) {
	struct Gsymbol *t = find(func -> name);
	//printf("%s\n", func -> name);
	struct argStruct *m = t -> argList;
	struct argStruct *treeList, *tmp;
	struct Lsymbol *lt;
	int l;
	
	if(func ->type >= 100)
		l = -4;
	else
		l = -3;
	
	while(list != NULL) {
		tmp = (struct argStruct*) malloc(sizeof(struct argStruct));
		strcpy(tmp -> name, list -> name);
		tmp -> type = list -> type;

		if(treeList == NULL)
			treeList = tmp;
		else {
			tmp -> next = treeList;
			treeList = tmp;
		}
		list = list -> l;
	}
	
	while(m != NULL) {
		//printf("%d %d\n", m -> type, treeList -> type);
		if(m -> type%10 == treeList -> type%10 && strcmp(m -> name, treeList -> name) == 0) {
			lt = (struct Lsymbol*) malloc(sizeof(struct Lsymbol));
			strcpy(lt -> name, m -> name);
			lt -> type = m -> type;
			lt -> bind = l;
			l--;
			if(Ltable == NULL)
				Ltable = lt;
			else {
				lt -> next = Ltable;
				Ltable = lt;
			}	
			m = m -> next;
			treeList = treeList -> next;
		}
		else { 
			printf("Type Error\n Line no: %d\n", count);
			exit(EXIT_SUCCESS);
		}
	}
}

void call(char a[30]) {
	fprintf(fp, "CALL %s\n", a);
}

void push() {
	fprintf(fp, "%s%d\n", "PUSH R", 0);
}
	
void popRegisters(int i) {
	while(i >= 0) 
		fprintf(fp, "POP R%d\n", i--);
}
	
void isError(int a, int b) {
	if(a%10 != b%10) {
		printf("Type Error\nline: %d\n", count);
		exit(EXIT_SUCCESS);
	}
}		

void boolcheck(struct node *t) {
	if(t -> l -> type%10 == 2) {
		if(t -> r -> value != 1) {
			if( t -> r -> value != 0) {
				printf("Type Error\nline: %d\n", count);
				exit(EXIT_SUCCESS);
			}
		}
		else {
			t -> r -> type = 2;
		}
	}	 
}

		
void checkTypeError(struct node* n, int a, int b, int c) {
	if(n == NULL){
		printf("Some error\nline: %d\n", count);
		exit(EXIT_SUCCESS);
	}
	else {
		if(n -> type%10 != a%10){
			printf("Type Error\nline: %d\n", count);
			exit(EXIT_SUCCESS);
	    }
	   
		if(n -> l -> type%10 != b%10){
			printf("Type Error\nline: %d\n", count);
			exit(EXIT_SUCCESS);
	    }
	    if(n -> r -> type%10 != c%10){
			printf("Type Error\nline: %d\n", count);
			exit(EXIT_SUCCESS);
	    }
	}
}
	   

struct node* findnode(struct node* x, char a[20]) {
	  if(x != NULL) {
	  	//printf("Working\n");
	  	if(strcmp(x->name, a))
	  		return x;
	  	findnode(x -> l, a);
	  	findnode(x -> r, a);
	  	findnode(x -> m, a);
	}
}

// Adding variable to Global Symbol table
void addVariable(char a[25], int type, int size) {

	struct Gsymbol *head, *t;
	t = find(a);
	
	if(t == NULL) {
		head = table;
	
		t = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
		strcpy(t->name, a);
		t -> type = type;
		t -> size = size;
		t -> bind = mem;
		if(type == 1) 
			t -> binding = (int*)malloc(sizeof(int) * size);
		if(type == 2)
			t -> binding = (int*)malloc(sizeof(int) * size);
		mem = mem + size;
	
		if(head == NULL)
			table = t;
		else {	
			while(head -> next != NULL) 
				head = head -> next;
		
			head -> next = t;
		}
	}
	else 
		printf("Variable %s is already defined\n", a);
}		

// Adds fuction to the Global symbol table
void addFunction(char a[25], int type, struct node *l) {
	struct Gsymbol *head, *t;
	struct argStruct *argl, *tmp, *last;
	struct node* ptop;
	
	argl = NULL;
	ptop = l;
	while(ptop != NULL) {
		tmp = (struct argStruct*) malloc(sizeof(struct argStruct));
		strcpy(tmp->name, ptop -> name);
		tmp -> type = ptop -> type;
		
		if(argl == NULL) {
			argl = tmp;
		}
		else {
			tmp -> next = argl;
			argl = tmp;
		}
		ptop = ptop -> l;
	}
			
	
	t = find(a);
	
	if(t == NULL) {
		head = table;
		
		t = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
		strcpy(t->name, a);
		t -> type = type;
		t -> size = 0;
		t -> argList = argl;
		
		if(head == NULL)
			table = t;
		else {	
			while(head -> next != NULL) 
				head = head -> next;
		
			head -> next = t;
		}
	}
	else
		printf("ID already defined\n");
}

//
void makeArgList(struct node *a, struct node *b) {
	struct node *t;
	
	t = a;
	
	if(t == NULL)
		a = b;
	else {
		while(t -> l != NULL)
			t  = t -> l;
		t -> l = b;
	}
	
	t = a;
	
	/*while( t != NULL){
		printf("%s ", t -> name);
		t = t -> l;
	}
	printf("\n");*/
}
		
// adds type to argument-tree-list of function
void addType(int type, struct node *t) {
	t -> type = type;
}

void set_type(struct node *a) {

	if(a != NULL) {
	
		struct Lsymbol *q = findInLtable(a -> name);
		if(q != NULL) {
			a -> type = q -> type;
			a -> bind = q -> bind;
		}
		else {
			//printf("%s\n", a -> name);
			struct Gsymbol *t = find(a->name);
			a -> type = t -> type;
			a -> binding = t -> binding;
			a -> bind = t -> bind;
		}
	}
}

struct node *makenode(int node_type, char name[15], int value, struct node *l, struct node *m, struct node *r)	
{
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	
	newnode -> node_type = node_type;
	strcpy(newnode -> name, name);
	newnode -> value = value;
	newnode -> l = l;
	newnode -> m = m;
	newnode -> r = r;
	
	return newnode;
}
	
struct node * update(struct node* a, struct node *l, struct node *m, struct node *r, int type) {
	a -> l = l;
	a -> r = r;
	a -> m = m;
	a -> type = type;
	return a;
}

void print1(struct node *x) {
	if(x != NULL) {	
			
		printf("%s\n", x -> name);
		print1(x->l);
		print1(x -> m);
		print1(x->r);
	}
}

int evaluate(struct node *x) {
	if(x != NULL) {
		if(x -> node_type == 0)
			return x -> value;
		
		if(x -> node_type == 2) {
			int *b;
			//struct Gsymbol *t = find(x -> name);
			if(x -> l != NULL) 
				b = x -> binding + evaluate(x -> l);
			else
				b = x -> binding;
			return *b;
		}
		
		if(x -> node_type == 1) {
			if(strcmp("+", x->name) == 0)	
					return evaluate(x->l) + evaluate(x -> r);
			if(strcmp("-", x->name) == 0)
					return evaluate(x->l) - evaluate(x -> r);
			if(strcmp("*", x->name) == 0)
					return evaluate(x->l) * evaluate(x -> r); 
			if(strcmp("/", x->name) == 0)
					return evaluate(x->l) / evaluate(x -> r);
			if(strcmp(">", x->name) == 0)
					return evaluate(x->l) > evaluate(x -> r);
			if(strcmp("<", x->name) == 0)
					return evaluate(x->l) < evaluate(x -> r);
			if(strcmp("<=", x->name) == 0)
					return evaluate(x->l) <= evaluate(x -> r);
			if(strcmp(">=", x->name) == 0)
					return evaluate(x->l) >= evaluate(x -> r);
			if(strcmp("==", x->name) == 0)
					return evaluate(x->l) == evaluate(x -> r);
			if(strcmp("!=", x->name) == 0)
					return evaluate(x->l) != evaluate(x -> r);
			if(strcmp("=", x->name) == 0) {
					int *b;
					//struct Gsymbol *t = find(x -> l -> name);
					if(x -> m != NULL)
						b = x -> l -> binding + evaluate(x -> m);
					else
						b = x -> l -> binding;
					*b = evaluate(x -> r);
				}
			}
			
		if(x -> node_type == 3) {
			if(strcmp("exit", x->name) == 0)
				exit(EXIT_SUCCESS);
			if(strcmp("write", x->name) == 0)
				printf("Write   %d\n", evaluate(x -> l));
			if(strcmp("read", x->name) == 0) {
				int *b;
				printf("Enter a number: ");
				scanf("%d", &temp);
				//struct Gsymbol *t = find(x -> l -> name);
				
				if(x -> m != NULL)
					b = x -> l -> binding + evaluate(x -> m);
				else
					b = x -> l -> binding;
				*b = temp; 
			}

			if(strcmp("while", x->name) == 0) {
				while(evaluate(x->l) != 0) {
					printf("in while\n");
					evaluate(x -> r);
				}
			}
			if(strcmp("if", x->name) == 0) {
				if(evaluate(x -> l) != 0){
					printf("true\n");
					evaluate(x -> m);
				}
				else {
					if(x -> r != NULL) {
					printf("false\n");
					evaluate(x -> r);}
				}
			}
		}
		
		if(x -> node_type == 4) {
			if(strcmp("slist", x->name) == 0) {
				evaluate(x -> l);
				evaluate(x -> r);
			}
			if(strcmp("statement", x->name) == 0)
				evaluate(x -> l);
		}
		
		if(x -> node_type == 5) 
			evaluate(x -> l);
	}
}

struct Gsymbol* find(char a[26]) {
	struct Gsymbol *head = (struct Gsymbol*) malloc(sizeof(struct Gsymbol));
	head = table;
	
	while(head != NULL && strcmp(a, head->name) != 0)
		head = head -> next;
		
	return head;
}

void printtable() {
	struct Gsymbol *t;
	t = table;
				
	while(t != NULL) {
		printf("%s %d", t -> name, *t -> binding);
		t = t -> next;
	}
}

int getreg() {
	//printf("regno %d\n", regno);
	return regno++;
}

int getlable() {
	return lable++;
}

void freereg() {
	if(regno > 0)
		regno--;
}
	
			
void yyerror(char *s) {
	fprintf(stderr, "%s %d\n", s, count);
}

int main(int argc, char *argv[]) {

	FILE *input;
	fp = fopen("output.txt", "w");
	input = fopen(argv[1], "r");
	yyin = input;
	
	yyparse();
	return 0;
}



