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
	int temp;
	int regno, count;
	int lable, *a, ty;
	int mem = 0;
	FILE *fp;
	
	struct argStruct {
		int type;
		char name[25];
		struct argStruct *next;
	};
	struct Gsymbol {
		char name[25];
		int type;               // type = 1 -> Integer, type = 2 -> boolean, type = 0 -> notype
		int size;
		int *binding;
		int bind;
		struct Gsymbol *next;
	};
	struct Gsymbol *table;
	struct node {
		int type;            // Integer Boolean or Void
		int node_type;       // operators or Statement type eg. while etc
		char name[15];
		int value;
		int *binding;
		int bind;
		struct argStruct *argList;
		struct node *l, *m, *r;
	};
	typedef struct node* tr;
	#define YYSTYPE tr
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



/* Line 268 of yacc.c  */
#line 132 "y.tab.c"

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
     WHILE = 265,
     DO = 266,
     ENDWHILE = 267,
     IF = 268,
     THEN = 269,
     ELSE = 270,
     ENDIF = 271,
     READ = 272,
     PRINT = 273,
     BOOLEAN = 274,
     WRITE = 275,
     RELOP = 276,
     BOOLOP = 277
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
#define WHILE 265
#define DO 266
#define ENDWHILE 267
#define IF 268
#define THEN 269
#define ELSE 270
#define ENDIF 271
#define READ 272
#define PRINT 273
#define BOOLEAN 274
#define WRITE 275
#define RELOP 276
#define BOOLOP 277




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 218 "y.tab.c"

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   187

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  33
/* YYNRULES -- Number of states.  */
#define YYNSTATES  85

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,    24,    22,    29,    23,     2,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
       2,    20,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    21,    26,    27
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,    10,    13,    17,    20,    22,    24,
      28,    30,    35,    39,    42,    44,    48,    55,    60,    68,
      73,    81,    89,    99,   101,   103,   105,   110,   114,   118,
     122,   126,   130,   134
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      35,     0,    -1,    36,    42,    -1,     8,    37,     9,    -1,
      38,    28,    -1,    37,    38,    28,    -1,    39,    40,    -1,
       7,    -1,    41,    -1,    40,    29,    41,    -1,     4,    -1,
       4,    30,     6,    31,    -1,    42,    43,    28,    -1,    43,
      28,    -1,    44,    -1,     4,    20,    44,    -1,     4,    30,
      44,    31,    20,    44,    -1,    17,    32,     4,    33,    -1,
      17,    32,     4,    30,    44,    31,    33,    -1,    21,    32,
      44,    33,    -1,    10,    32,    44,    33,    11,    42,    12,
      -1,    13,    32,    44,    33,    14,    42,    16,    -1,    13,
      32,    44,    33,    14,    42,    15,    42,    16,    -1,     5,
      -1,     6,    -1,     4,    -1,     4,    30,    44,    31,    -1,
      44,    22,    44,    -1,    44,    23,    44,    -1,    44,    24,
      44,    -1,    44,    25,    44,    -1,    44,    26,    44,    -1,
      44,    27,    44,    -1,    32,    44,    33,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    81,    85,    86,    90,    94,    97,    98,
     102,   103,   107,   109,   113,   114,   116,   119,   120,   121,
     122,   123,   124,   125,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "VARIABLE", "EXIT", "NUM",
  "TYPE", "DECL", "ENDDECL", "WHILE", "DO", "ENDWHILE", "IF", "THEN",
  "ELSE", "ENDIF", "READ", "PRINT", "BOOLEAN", "'='", "WRITE", "'+'",
  "'-'", "'*'", "'/'", "RELOP", "BOOLOP", "';'", "','", "'['", "']'",
  "'('", "')'", "$accept", "program", "declaration", "declist", "decl",
  "type", "varlist", "variable", "slist", "statement", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      61,   275,    43,    45,    42,    47,   276,   277,    59,    44,
      91,    93,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    37,    37,    38,    39,    40,    40,
      41,    41,    42,    42,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     2,     3,     2,     1,     1,     3,
       1,     4,     3,     2,     1,     3,     6,     4,     7,     4,
       7,     7,     9,     1,     1,     1,     4,     3,     3,     3,
       3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     7,     0,     0,     0,     1,    25,
      23,    24,     0,     0,     0,     0,     0,     2,     0,    14,
       3,     0,     4,    10,     6,     8,     0,     0,     0,     0,
       0,     0,    25,     0,     0,    13,     0,     0,     0,     0,
       0,     0,     5,     0,     0,    15,     0,     0,     0,     0,
       0,     0,    33,    12,    27,    28,    29,    30,    31,    32,
       0,     9,    26,     0,     0,     0,    17,    19,     0,    11,
       0,     0,     0,     0,    26,    16,     0,     0,     0,    20,
       0,    21,    18,     0,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     5,     6,     7,    24,    25,    17,    18,
      19
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -63
static const yytype_int16 yypact[] =
{
      -2,     1,    15,    81,   -63,    -5,     5,    23,   -63,   -13,
     -63,   -63,     6,    10,    11,    12,    -1,    81,    25,   160,
     -63,    26,   -63,    21,    28,   -63,    -1,    -1,    -1,    -1,
      48,    -1,    34,    82,    30,   -63,    -1,    -1,    -1,    -1,
      -1,    -1,   -63,    59,    23,   160,   130,    94,   106,     2,
     118,    -1,   -63,   -63,    22,    22,    -7,    -7,    41,   -63,
      44,   -63,    56,    68,    76,    -1,   -63,   -63,   140,   -63,
      -1,    81,    81,   150,   -63,   160,    57,    24,    49,   -63,
      81,   -63,   -63,    67,   -63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,   -63,   -63,    87,   -63,   -63,    37,   -62,   -17,
     -15
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      34,    33,     4,    32,    20,    11,     1,    26,     4,    76,
      77,    45,    46,    47,    48,     8,    50,    27,    83,    40,
      41,    54,    55,    56,    57,    58,    59,    23,     9,    10,
      11,    16,    65,    22,    12,    66,    68,    13,    28,    80,
      81,    14,    29,    30,    31,    15,    38,    39,    40,    41,
      73,    43,    49,    35,    42,    75,    16,    44,    53,    34,
      34,     9,    10,    11,    51,    60,    34,    12,    41,    79,
      13,     9,    10,    11,    14,    69,    70,    12,    15,    71,
      13,    61,    82,    84,    14,     9,    10,    11,    15,    16,
      72,    12,    21,     0,    13,     0,     0,     0,    14,    16,
       0,     0,    15,     0,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    16,     0,    52,    36,    37,    38,    39,
      40,    41,     0,     0,     0,     0,     0,    63,    36,    37,
      38,    39,    40,    41,     0,     0,     0,     0,     0,    64,
      36,    37,    38,    39,    40,    41,     0,     0,     0,     0,
       0,    67,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    62,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    74,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    78,    36,    37,    38,    39,    40,    41
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-63))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      17,    16,     7,     4,     9,     6,     8,    20,     7,    71,
      72,    26,    27,    28,    29,     0,    31,    30,    80,    26,
      27,    36,    37,    38,    39,    40,    41,     4,     4,     5,
       6,    32,    30,    28,    10,    33,    51,    13,    32,    15,
      16,    17,    32,    32,    32,    21,    24,    25,    26,    27,
      65,    30,     4,    28,    28,    70,    32,    29,    28,    76,
      77,     4,     5,     6,    30,     6,    83,    10,    27,    12,
      13,     4,     5,     6,    17,    31,    20,    10,    21,    11,
      13,    44,    33,    16,    17,     4,     5,     6,    21,    32,
      14,    10,     5,    -1,    13,    -1,    -1,    -1,    17,    32,
      -1,    -1,    21,    -1,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    32,    -1,    33,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    33,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    22,    23,    24,    25,    26,    27
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    35,    36,     7,    37,    38,    39,     0,     4,
       5,     6,    10,    13,    17,    21,    32,    42,    43,    44,
       9,    38,    28,     4,    40,    41,    20,    30,    32,    32,
      32,    32,     4,    44,    43,    28,    22,    23,    24,    25,
      26,    27,    28,    30,    29,    44,    44,    44,    44,     4,
      44,    30,    33,    28,    44,    44,    44,    44,    44,    44,
       6,    41,    31,    33,    33,    30,    33,    33,    44,    31,
      20,    11,    14,    44,    31,    44,    42,    42,    31,    12,
      15,    16,    33,    42,    16
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
#line 70 "SIL.y"
    { (yyval) = makenode(5, "program", 0, (yyvsp[(2) - (2)]), NULL, NULL);
											  evaluate((yyval));
											  fp = fopen("output.txt", "w");
								 			  fprintf(fp, "%s\n", "START");
								 			  temp = codegen((yyval));
								 			  fprintf(fp, "%s\n", "HALT");
								 			  print1((yyvsp[(2) - (2)]));
											}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 81 "SIL.y"
    {}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 85 "SIL.y"
    {}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 86 "SIL.y"
    {}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 90 "SIL.y"
    {}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 94 "SIL.y"
    {ty = (yyvsp[(1) - (1)]) -> type;}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 97 "SIL.y"
    {}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 98 "SIL.y"
    {}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 102 "SIL.y"
    { addVariable((yyvsp[(1) - (1)])->name, ty, 1); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 103 "SIL.y"
    { addVariable((yyvsp[(1) - (4)])-> name, ty, (yyvsp[(3) - (4)])->value);}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 107 "SIL.y"
    {(yyval) = makenode(4, "slist", 0, (yyvsp[(1) - (3)]), NULL, (yyvsp[(2) - (3)]));}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 109 "SIL.y"
    {(yyval) = makenode(4, "statement", 0, (yyvsp[(1) - (2)]), NULL, NULL);}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 113 "SIL.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 114 "SIL.y"
    { (yyval) = update((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), NULL, (yyvsp[(3) - (3)]), 0); 
															  set_type((yyvsp[(1) - (3)])); boolcheck((yyvsp[(2) - (3)]));}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 116 "SIL.y"
    { (yyval) = update((yyvsp[(5) - (6)]), (yyvsp[(1) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(6) - (6)]), 0); 
															  isError((yyvsp[(3) - (6)]) -> type, 1); 
															  set_type((yyvsp[(1) - (6)])); boolcheck((yyvsp[(5) - (6)]));}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 119 "SIL.y"
    {(yyval) = update((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL, 0); set_type((yyvsp[(3) - (4)])); isError((yyvsp[(3) - (4)]) -> type, 1);}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 120 "SIL.y"
    {(yyval) = update((yyvsp[(1) - (7)]) , (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), NULL, 0);  set_type((yyvsp[(3) - (7)]));  isError((yyvsp[(3) - (7)]) -> type, 1);}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 121 "SIL.y"
    {(yyval) = update((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL, 0); isError((yyvsp[(3) - (4)]) -> type, 1);}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 122 "SIL.y"
    {(yyval) = update((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), NULL, (yyvsp[(6) - (7)]), 0); isError((yyvsp[(3) - (7)]) -> type, 2);}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 123 "SIL.y"
    {(yyval) = update((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(6) - (7)]), NULL, 0); isError((yyvsp[(3) - (7)]) -> type, 2);}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 124 "SIL.y"
    {(yyval) = update((yyvsp[(1) - (9)]), (yyvsp[(3) - (9)]), (yyvsp[(6) - (9)]), (yyvsp[(8) - (9)]), 0); isError((yyvsp[(3) - (9)]) -> type, 2);}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 125 "SIL.y"
    {(yyval) = update((yyvsp[(1) - (1)]), NULL, NULL, NULL, 0); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 129 "SIL.y"
    {(yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 130 "SIL.y"
    {(yyval) = (yyvsp[(1) - (1)]); set_type((yyvsp[(1) - (1)])); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 131 "SIL.y"
    {(yyval) = update((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]), NULL, NULL, (yyvsp[(1) - (4)]) -> type); set_type((yyvsp[(1) - (4)])); isError((yyvsp[(3) - (4)]) -> type, 1);}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 132 "SIL.y"
    {(yyval) = update((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), NULL, (yyvsp[(3) - (3)]), 1); checkTypeError((yyvsp[(2) - (3)]), 1, 1, 1);}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 133 "SIL.y"
    {(yyval) = update((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), NULL, (yyvsp[(3) - (3)]), 1); checkTypeError((yyvsp[(2) - (3)]), 1, 1, 1);}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 134 "SIL.y"
    {(yyval) = update((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), NULL, (yyvsp[(3) - (3)]), 1); checkTypeError((yyvsp[(2) - (3)]), 1, 1, 1);}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 135 "SIL.y"
    {(yyval) = update((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), NULL, (yyvsp[(3) - (3)]), 1); checkTypeError((yyvsp[(2) - (3)]), 1, 1, 1);}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 136 "SIL.y"
    {(yyval) = update((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), NULL, (yyvsp[(3) - (3)]), 2); checkTypeError((yyvsp[(2) - (3)]), 2, 1, 1);}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 137 "SIL.y"
    {(yyval) = update((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), NULL, (yyvsp[(3) - (3)]), 2); checkTypeError((yyvsp[(2) - (3)]), 2, 2, 2);}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 138 "SIL.y"
    {(yyval) = (yyvsp[(2) - (3)]); }
    break;



/* Line 1806 of yacc.c  */
#line 1757 "y.tab.c"
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
#line 141 "SIL.y"


void isError(int a, int b) {
	if(a != b) {
		printf("Type Error\nline: %d\n", count);
		exit(EXIT_SUCCESS);
	}
}		

void boolcheck(struct node *t) {
	if(t -> l -> type == 2) {
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
		if(n -> type != a){
			printf("Type Error\nline: %d\n", count);
			exit(EXIT_SUCCESS);
	    }
	   
		if(n -> l -> type != b){
			printf("Type Error\nline: %d\n", count);
			exit(EXIT_SUCCESS);
	    }
	    if(n -> r -> type != c){
			printf("Type Error\nline: %d\n", count);
			exit(EXIT_SUCCESS);
	    }
	}
}
	   

struct node* findnode(struct node* x, char a[20]) {
	  if(x != NULL) {
	  	printf("Working\n");
	  	if(strcmp(x->name, a))
	  		return x;
	  	findnode(x -> l, a);
	  	findnode(x -> r, a);
	  	findnode(x -> m, a);
	}
}

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
		printf("Variable is already defined\n");
}		

void set_type(struct node *a) {
	if(a != NULL) {
		struct Gsymbol *t = find(a->name);
		a -> type = t -> type;
		a -> binding = t -> binding;
		a -> bind = t -> bind;
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
		if(x->node_type == 0)
			printf("%d %d\n", x->value, x -> type);
		else
			printf("%s %d\n", x -> name, x -> type);		
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
	return regno++;
}

int getlable() {
	return lable++;
}

void freereg() {
	regno--;
}

int codegen(struct node *x) {
	if (x != NULL) {
		int i, m, j, l1, l2, l3, k;
		if(x-> node_type == 0) {
			i = getreg();
			fprintf(fp, "MOV R%d, %d\n", i, x->value);
			//printf("MOV R%d, %d", i, x->value);
		}
		
		if(x -> node_type == 2) {
			i = getreg();
			//struct Gsymbol *t;
			//t = find(x -> name);
			if(x -> l != NULL) {
				m = x -> bind;
				fprintf(fp, "MOV R%d, %d\n", i, m);
				j = codegen(x -> l);
				fprintf(fp, "ADD R%d, R%d\n", j, i);
				fprintf(fp, "MOV R%d, [R%d]\n", i, j);
				freereg(); 
			}	
			else {
				m = x -> bind;
				fprintf(fp, "MOV R%d, [%d]\n", i, m);
		 	}
		}
		
		if(x -> node_type == 1) {
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
				//i = codegen(x -> l);
				i = codegen(x -> r);
				//struct Gsymbol *t = (struct Gsymbol*) malloc(sizeof(struct Gsymbol));
				//t = find(x -> l -> name);
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
					fprintf(fp, "MOV [%d], R%d\n", m, i);
				}
				freereg();
			}
		}
		
		if(x -> node_type == 3) {
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
				
		if(x -> node_type == 4) {
				if(strcmp("slist", x->name) == 0) {
					codegen(x -> l);
					codegen(x -> r);
				}
				if(strcmp("statement", x->name) == 0) 
					codegen(x -> l);
		}
		
		if(x -> node_type == 5) 
			codegen(x -> l);
	return i;
	}	
}	

	
			
void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

int main(int argc, char *argv[]) {

	FILE *input;
	
	input = fopen(argv[1], "r");
	yyin = input;
	
	yyparse();
	return 0;
}



