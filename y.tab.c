/* A Bison parser, made by GNU Bison 3.6.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "final.yacc"

#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "structures.h"
#include "check.h"

Hashtable *ht;
Stack *st;
AST_Node *root;
AST_Node *p, *p1, *p2, *p3, *p4;
Symbol *smb;


#line 86 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    MAINCLASS = 258,               /* MAINCLASS  */
    PUBLIC = 259,                  /* PUBLIC  */
    STATIC = 260,                  /* STATIC  */
    VOID = 261,                    /* VOID  */
    MAIN = 262,                    /* MAIN  */
    INT = 263,                     /* INT  */
    FLOAT = 264,                   /* FLOAT  */
    FOR = 265,                     /* FOR  */
    WHILE = 266,                   /* WHILE  */
    IF = 267,                      /* IF  */
    ELSE = 268,                    /* ELSE  */
    PRINTLN = 269,                 /* PRINTLN  */
    INT_CONST = 270,               /* INT_CONST  */
    FLOAT_CONST = 271,             /* FLOAT_CONST  */
    EQ_OP = 272,                   /* EQ_OP  */
    NE_OP = 273,                   /* NE_OP  */
    LT_OP = 274,                   /* LT_OP  */
    GT_OP = 275,                   /* GT_OP  */
    LE_OP = 276,                   /* LE_OP  */
    GE_OP = 277,                   /* GE_OP  */
    ID = 278                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define MAINCLASS 258
#define PUBLIC 259
#define STATIC 260
#define VOID 261
#define MAIN 262
#define INT 263
#define FLOAT 264
#define FOR 265
#define WHILE 266
#define IF 267
#define ELSE 268
#define PRINTLN 269
#define INT_CONST 270
#define FLOAT_CONST 271
#define EQ_OP 272
#define NE_OP 273
#define LT_OP 274
#define GT_OP 275
#define LE_OP 276
#define GE_OP 277
#define ID 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "final.yacc"

	int yint;
	float yfloat;
	char ystr[15 + 1];
	struct AST_Node *p_astn;

#line 191 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MAINCLASS = 3,                  /* MAINCLASS  */
  YYSYMBOL_PUBLIC = 4,                     /* PUBLIC  */
  YYSYMBOL_STATIC = 5,                     /* STATIC  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_MAIN = 7,                       /* MAIN  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_FLOAT = 9,                      /* FLOAT  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_PRINTLN = 14,                   /* PRINTLN  */
  YYSYMBOL_INT_CONST = 15,                 /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 16,               /* FLOAT_CONST  */
  YYSYMBOL_17_ = 17,                       /* '('  */
  YYSYMBOL_18_ = 18,                       /* ')'  */
  YYSYMBOL_19_ = 19,                       /* '{'  */
  YYSYMBOL_20_ = 20,                       /* '}'  */
  YYSYMBOL_21_ = 21,                       /* '='  */
  YYSYMBOL_22_ = 22,                       /* ','  */
  YYSYMBOL_23_ = 23,                       /* ';'  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '-'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_EQ_OP = 28,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 29,                     /* NE_OP  */
  YYSYMBOL_LT_OP = 30,                     /* LT_OP  */
  YYSYMBOL_GT_OP = 31,                     /* GT_OP  */
  YYSYMBOL_LE_OP = 32,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 33,                     /* GE_OP  */
  YYSYMBOL_ID = 34,                        /* ID  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_comp_stmt = 37,                 /* comp_stmt  */
  YYSYMBOL_stmt_list = 38,                 /* stmt_list  */
  YYSYMBOL_stmt = 39,                      /* stmt  */
  YYSYMBOL_open_stmt = 40,                 /* open_stmt  */
  YYSYMBOL_closed_stmt = 41,               /* closed_stmt  */
  YYSYMBOL_simple_stmt = 42,               /* simple_stmt  */
  YYSYMBOL_declaration = 43,               /* declaration  */
  YYSYMBOL_type = 44,                      /* type  */
  YYSYMBOL_id_list = 45,                   /* id_list  */
  YYSYMBOL_null_stmt = 46,                 /* null_stmt  */
  YYSYMBOL_assign_stmt = 47,               /* assign_stmt  */
  YYSYMBOL_expr = 48,                      /* expr  */
  YYSYMBOL_opassign_expr = 49,             /* opassign_expr  */
  YYSYMBOL_assign_expr = 50,               /* assign_expr  */
  YYSYMBOL_open_for_stmt = 51,             /* open_for_stmt  */
  YYSYMBOL_closed_for_stmt = 52,           /* closed_for_stmt  */
  YYSYMBOL_opbool_expr = 53,               /* opbool_expr  */
  YYSYMBOL_open_while_stmt = 54,           /* open_while_stmt  */
  YYSYMBOL_closed_while_stmt = 55,         /* closed_while_stmt  */
  YYSYMBOL_open_if_stmt = 56,              /* open_if_stmt  */
  YYSYMBOL_closed_if_stmt = 57,            /* closed_if_stmt  */
  YYSYMBOL_bool_expr = 58,                 /* bool_expr  */
  YYSYMBOL_r_val = 59,                     /* r_val  */
  YYSYMBOL_term = 60,                      /* term  */
  YYSYMBOL_factor = 61,                    /* factor  */
  YYSYMBOL_num = 62                        /* num  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   103

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  112

#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      17,    18,    26,    24,    22,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    23,
       2,    21,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    19,     2,    20,     2,     2,     2,     2,
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
      15,    16,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    44,    44,    51,    57,    62,    67,    70,    76,    79,
      82,    87,    90,    93,    96,   102,   105,   108,   111,   114,
     122,   130,   137,   147,   156,   167,   173,   181,   186,   194,
     199,   204,   215,   220,   226,   230,   234,   239,   244,   249,
     256,   266,   274,   282,   290,   298,   306,   316,   325,   333,
     341,   350,   358,   366,   372,   379,   389,   397,   405
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MAINCLASS", "PUBLIC",
  "STATIC", "VOID", "MAIN", "INT", "FLOAT", "FOR", "WHILE", "IF", "ELSE",
  "PRINTLN", "INT_CONST", "FLOAT_CONST", "'('", "')'", "'{'", "'}'", "'='",
  "','", "';'", "'+'", "'-'", "'*'", "'/'", "EQ_OP", "NE_OP", "LT_OP",
  "GT_OP", "LE_OP", "GE_OP", "ID", "$accept", "program", "comp_stmt",
  "stmt_list", "stmt", "open_stmt", "closed_stmt", "simple_stmt",
  "declaration", "type", "id_list", "null_stmt", "assign_stmt", "expr",
  "opassign_expr", "assign_expr", "open_for_stmt", "closed_for_stmt",
  "opbool_expr", "open_while_stmt", "closed_while_stmt", "open_if_stmt",
  "closed_if_stmt", "bool_expr", "r_val", "term", "factor", "num", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,    40,    41,   123,
     125,    61,    44,    59,    43,    45,    42,    47,   272,   273,
     274,   275,   276,   277,   278
};
#endif

#define YYPACT_NINF (-71)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       8,    -6,    38,    24,   -71,    45,    46,    47,    50,    35,
      40,    41,   -71,    34,    36,   -71,   -71,   -71,    44,    48,
      61,    62,   -71,   -71,    42,   -71,   -71,   -71,   -71,   -71,
     -71,    28,   -71,   -71,    57,   -71,   -71,   -71,   -71,   -71,
     -71,    49,   -10,   -10,   -10,   -10,    59,    64,   -71,    65,
     -71,   -71,   -71,   -10,    51,    42,   -12,   -71,    66,   -21,
      -4,   -71,   -71,    71,    74,   -71,    28,   -71,   -10,    75,
     -71,   -71,   -10,   -10,   -10,   -10,   -10,   -10,    63,    51,
      51,    51,    51,    63,    73,   -71,    76,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,    -4,    -4,   -71,
     -71,   -71,    81,   -71,    49,    63,    80,   -71,   -71,    63,
     -71,   -71
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     5,     0,     0,     2,    21,    22,     0,     0,
       0,     0,     3,    25,     0,    16,     4,     6,     7,    14,
      17,     0,    18,    15,     0,     8,    11,     9,    12,    10,
      13,    30,     0,     0,     0,     0,    24,     0,    26,     0,
      29,    57,    58,     0,     0,    55,     0,    27,     0,    28,
      49,    52,    56,     0,     0,    31,     0,    20,    35,     0,
      55,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     0,    34,    53,    41,
      46,    42,    43,    44,    45,    36,    37,    47,    48,    50,
      51,    38,     7,    19,    30,     0,     0,    39,    40,     0,
      32,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,    89,   -71,    18,   -69,   -70,   -71,   -71,   -71,
      37,   -71,   -71,   -43,    -2,   -14,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -31,   -71,   -54,   -40,   -71
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    25,    14,    26,    27,    28,    29,    30,    31,
      47,    32,    33,    56,    49,    57,    35,    36,    86,    37,
      38,    39,    40,    58,    59,    60,    61,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      34,    64,    65,    79,    80,    51,    52,    53,    96,    95,
      69,     1,    63,   102,    71,    54,    72,    73,    74,    75,
      76,    77,    81,    82,    55,    97,    98,    50,     3,    89,
      90,    91,    92,    93,    94,   108,   107,    87,     4,   111,
     110,    99,   100,     5,    16,    17,    18,    19,    20,     6,
      21,     7,    10,     8,    15,    12,    22,     9,    11,    23,
      12,    41,    46,    45,    34,    42,    51,    52,    53,    34,
      24,    16,    17,    18,    19,    20,    54,    21,    43,    44,
      48,    66,    12,    24,    78,    70,    23,    67,    68,    83,
      50,    34,    84,    88,   105,    34,   103,    24,   109,   104,
      13,   101,   106,    85
};

static const yytype_int8 yycheck[] =
{
      14,    44,    45,    24,    25,    15,    16,    17,    78,    78,
      53,     3,    43,    83,    54,    25,    28,    29,    30,    31,
      32,    33,    26,    27,    34,    79,    80,    41,    34,    72,
      73,    74,    75,    76,    77,   105,   105,    68,     0,   109,
     109,    81,    82,    19,     8,     9,    10,    11,    12,     4,
      14,     5,    17,     6,    20,    19,    20,     7,    18,    23,
      19,    17,    34,    21,    78,    17,    15,    16,    17,    83,
      34,     8,     9,    10,    11,    12,    25,    14,    17,    17,
      23,    22,    19,    34,    18,    34,    23,    23,    23,    18,
     104,   105,    18,    18,    13,   109,    23,    34,    18,    23,
      11,    83,   104,    66
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    36,    34,     0,    19,     4,     5,     6,     7,
      17,    18,    19,    37,    38,    20,     8,     9,    10,    11,
      12,    14,    20,    23,    34,    37,    39,    40,    41,    42,
      43,    44,    46,    47,    50,    51,    52,    54,    55,    56,
      57,    17,    17,    17,    17,    21,    34,    45,    23,    49,
      50,    15,    16,    17,    25,    34,    48,    50,    58,    59,
      60,    61,    62,    58,    48,    48,    22,    23,    23,    48,
      34,    61,    28,    29,    30,    31,    32,    33,    18,    24,
      25,    26,    27,    18,    18,    45,    53,    58,    18,    48,
      48,    48,    48,    48,    48,    40,    41,    60,    60,    61,
      61,    39,    41,    23,    23,    13,    49,    40,    41,    18,
      40,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    38,    38,    39,    39,    40,    40,
      40,    41,    41,    41,    41,    42,    42,    42,    42,    42,
      43,    44,    44,    45,    45,    46,    47,    48,    48,    49,
      49,    50,    51,    52,    53,    53,    54,    55,    56,    56,
      57,    58,    58,    58,    58,    58,    58,    59,    59,    59,
      60,    60,    60,    61,    61,    61,    61,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,    11,     3,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       3,     1,     1,     3,     1,     1,     2,     1,     1,     1,
       0,     3,     9,     9,     1,     0,     5,     5,     5,     7,
       7,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     2,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 45 "final.yacc"
                                                {
							smb = SMB_init((yyvsp[-9].ystr));
							root = ASTN_init(ASTN_PROGRAM, smb, (yyvsp[-1].p_astn), NULL, NULL, NULL);
						}
#line 1311 "y.tab.c"
    break;

  case 3:
#line 52 "final.yacc"
                                                {
							(yyval.p_astn) = (yyvsp[-1].p_astn);
						}
#line 1319 "y.tab.c"
    break;

  case 4:
#line 58 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_STMT_LIST, NULL, (yyvsp[-1].p_astn), (yyvsp[0].p_astn), NULL, NULL);	
						}
#line 1327 "y.tab.c"
    break;

  case 5:
#line 62 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_STMT_LIST, NULL, NULL, NULL, NULL, NULL);
						}
#line 1335 "y.tab.c"
    break;

  case 6:
#line 68 "final.yacc"
                                                {
						}
#line 1342 "y.tab.c"
    break;

  case 7:
#line 71 "final.yacc"
                                                {
							(yyval.p_astn) = (yyvsp[0].p_astn);
						}
#line 1350 "y.tab.c"
    break;

  case 8:
#line 77 "final.yacc"
                                                {
						}
#line 1357 "y.tab.c"
    break;

  case 9:
#line 80 "final.yacc"
                                                {
						}
#line 1364 "y.tab.c"
    break;

  case 10:
#line 83 "final.yacc"
                                                {
						}
#line 1371 "y.tab.c"
    break;

  case 11:
#line 88 "final.yacc"
                                                {
						}
#line 1378 "y.tab.c"
    break;

  case 12:
#line 91 "final.yacc"
                                                {
						}
#line 1385 "y.tab.c"
    break;

  case 13:
#line 94 "final.yacc"
                                                {
						}
#line 1392 "y.tab.c"
    break;

  case 14:
#line 97 "final.yacc"
                                                {
							(yyval.p_astn) = (yyvsp[0].p_astn);
						}
#line 1400 "y.tab.c"
    break;

  case 15:
#line 103 "final.yacc"
                                                {
						}
#line 1407 "y.tab.c"
    break;

  case 16:
#line 106 "final.yacc"
                                                {
						}
#line 1414 "y.tab.c"
    break;

  case 17:
#line 109 "final.yacc"
                                                {
						}
#line 1421 "y.tab.c"
    break;

  case 18:
#line 112 "final.yacc"
                                                {
						}
#line 1428 "y.tab.c"
    break;

  case 19:
#line 115 "final.yacc"
                                                {
							smb = ST_pop(st);
							check_println(smb);
							(yyval.p_astn) = ASTN_init(ASTN_PRINTLN, smb, NULL, NULL, NULL, NULL);
						}
#line 1438 "y.tab.c"
    break;

  case 20:
#line 123 "final.yacc"
                                                {
							Symbol *dummy = (yyvsp[-2].p_astn)->wrapped_symbol;
							check_declaration(dummy, (yyvsp[-1].p_astn));
							(yyval.p_astn) = ASTN_init(ASTN_DECLARATION, dummy, (yyvsp[-1].p_astn), NULL, NULL, NULL);
						}
#line 1448 "y.tab.c"
    break;

  case 21:
#line 131 "final.yacc"
                                                {
							smb = SMB_init("");
							smb->var_type = TYPE_INT;
							(yyval.p_astn) = ASTN_init(ASTN_TYPE, smb, NULL, NULL, NULL, NULL);
						}
#line 1458 "y.tab.c"
    break;

  case 22:
#line 138 "final.yacc"
                                                {
							
							smb = SMB_init("");
							smb->var_type = TYPE_FLOAT;
							(yyval.p_astn) = ASTN_init(ASTN_TYPE, smb, NULL, NULL, NULL, NULL);
						}
#line 1469 "y.tab.c"
    break;

  case 23:
#line 148 "final.yacc"
                                                {
							smb = SMB_init((yyvsp[-2].ystr));
							if(!HT_add(ht, smb)){
								fprintf(stderr, "Error: Tried to declare ID multiple times.\n");
								exit(1);
							}
							(yyval.p_astn) = ASTN_init(ASTN_ID_LIST, smb, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1482 "y.tab.c"
    break;

  case 24:
#line 157 "final.yacc"
                                                {
							smb = SMB_init((yyvsp[0].ystr));
							if(! (smb = HT_add(ht, smb))){
								fprintf(stderr, "Error: Tried to declare ID multiple times.\n");
								exit(1);
							}
							(yyval.p_astn) = ASTN_init(ASTN_ID_LIST, smb, NULL, NULL, NULL, NULL);
						}
#line 1495 "y.tab.c"
    break;

  case 25:
#line 168 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_NULL_STMT, NULL, NULL, NULL, NULL, NULL); 
						}
#line 1503 "y.tab.c"
    break;

  case 26:
#line 174 "final.yacc"
                                                {
							smb = ST_pop(st);
							(yyval.p_astn) = ASTN_init(ASTN_ASSIGN_STMT, smb, (yyvsp[-1].p_astn), NULL, NULL, NULL);
						}
#line 1512 "y.tab.c"
    break;

  case 27:
#line 181 "final.yacc"
                                                {
							smb = ST_pop(st);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_EXPR, smb, NULL, NULL, NULL, NULL);
						}
#line 1522 "y.tab.c"
    break;

  case 28:
#line 187 "final.yacc"
                                                {
							smb = ST_pop(st);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_EXPR, smb, NULL, NULL, NULL, NULL);
						}
#line 1532 "y.tab.c"
    break;

  case 29:
#line 195 "final.yacc"
                                                {
							(yyval.p_astn) = (yyvsp[0].p_astn);
						}
#line 1540 "y.tab.c"
    break;

  case 30:
#line 199 "final.yacc"
                                                {
							(yyval.p_astn) = NULL;
						}
#line 1548 "y.tab.c"
    break;

  case 31:
#line 205 "final.yacc"
                                                {
							smb = ST_pop(st);
							Symbol *id = HT_get(ht, (yyvsp[-2].ystr));
							smb = check_assign(id, smb);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_ASSIGN_EXPR, smb, NULL, NULL, NULL, NULL);							
						}
#line 1560 "y.tab.c"
    break;

  case 32:
#line 216 "final.yacc"
                                                {							
						}
#line 1567 "y.tab.c"
    break;

  case 33:
#line 221 "final.yacc"
                                                {							
						}
#line 1574 "y.tab.c"
    break;

  case 34:
#line 227 "final.yacc"
                                                {
						}
#line 1581 "y.tab.c"
    break;

  case 35:
#line 230 "final.yacc"
                                                {
						}
#line 1588 "y.tab.c"
    break;

  case 36:
#line 235 "final.yacc"
                                                {
						}
#line 1595 "y.tab.c"
    break;

  case 37:
#line 240 "final.yacc"
                                                {
						}
#line 1602 "y.tab.c"
    break;

  case 38:
#line 245 "final.yacc"
                                                {
							smb = ST_pop(st);
							(yyval.p_astn) = ASTN_init(ASTN_IF_STMT, smb, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1611 "y.tab.c"
    break;

  case 39:
#line 250 "final.yacc"
                                                {
							smb = ST_pop(st);
							(yyval.p_astn) = ASTN_init(ASTN_IF_STMT, smb, (yyvsp[-2].p_astn), (yyvsp[0].p_astn), NULL, NULL);
						}
#line 1620 "y.tab.c"
    break;

  case 40:
#line 257 "final.yacc"
                                                {
							smb = ST_pop(st);
							(yyval.p_astn) = ASTN_init(ASTN_IF_STMT, smb, (yyvsp[-2].p_astn), (yyvsp[0].p_astn), NULL, NULL);
						}
#line 1629 "y.tab.c"
    break;

  case 41:
#line 267 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_eq(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_BOOL_EXPR, smb, NULL, NULL, NULL, NULL);
						}
#line 1641 "y.tab.c"
    break;

  case 42:
#line 275 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_lt(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_BOOL_EXPR, smb, NULL, NULL, NULL, NULL);
						}
#line 1653 "y.tab.c"
    break;

  case 43:
#line 283 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_gt(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_BOOL_EXPR, smb, NULL, NULL, NULL, NULL);
						}
#line 1665 "y.tab.c"
    break;

  case 44:
#line 291 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_le(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_BOOL_EXPR, smb, NULL, NULL, NULL, NULL);
						}
#line 1677 "y.tab.c"
    break;

  case 45:
#line 299 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_ge(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_BOOL_EXPR, smb, NULL, NULL, NULL, NULL);
						}
#line 1689 "y.tab.c"
    break;

  case 46:
#line 307 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_ne(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_BOOL_EXPR, smb, NULL, NULL, NULL, NULL);
						}
#line 1701 "y.tab.c"
    break;

  case 47:
#line 317 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_add(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_R_VAL, smb, NULL, NULL, NULL, NULL);
						
						}
#line 1714 "y.tab.c"
    break;

  case 48:
#line 326 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_substr(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_R_VAL, smb, NULL, NULL, NULL, NULL);
						}
#line 1726 "y.tab.c"
    break;

  case 49:
#line 334 "final.yacc"
                                                {
							smb = ST_pop(st);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_R_VAL, smb, NULL, NULL, NULL, NULL);	
						}
#line 1736 "y.tab.c"
    break;

  case 50:
#line 342 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_mult(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_TERM, smb, NULL, NULL, NULL, NULL);
							
						}
#line 1749 "y.tab.c"
    break;

  case 51:
#line 351 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_division(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_TERM, smb, NULL, NULL, NULL, NULL);
						}
#line 1761 "y.tab.c"
    break;

  case 52:
#line 359 "final.yacc"
                                                {
							smb = ST_pop(st);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_TERM, smb, NULL, NULL, NULL, NULL);
						}
#line 1771 "y.tab.c"
    break;

  case 53:
#line 367 "final.yacc"
                                                {
							smb = ST_pop(st);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_FACTOR, smb, NULL, NULL, NULL, NULL);
						}
#line 1781 "y.tab.c"
    break;

  case 54:
#line 373 "final.yacc"
                                                {
							smb = ST_pop(st);
							smb = check_uminus(smb);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_TERM, smb, NULL, NULL, NULL, NULL);
						}
#line 1792 "y.tab.c"
    break;

  case 55:
#line 380 "final.yacc"
                                                {
							smb = HT_get(ht, (yyvsp[0].ystr));
							if(!smb){
								fprintf(stderr, "Error: Tried to use ID before declaration.\n");
								exit(1);
							}
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_FACTOR, smb, NULL, NULL, NULL, NULL);
						}
#line 1806 "y.tab.c"
    break;

  case 56:
#line 390 "final.yacc"
                                                {
							smb = ST_pop(st);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_FACTOR, smb, NULL, NULL, NULL, NULL);
						}
#line 1816 "y.tab.c"
    break;

  case 57:
#line 398 "final.yacc"
                                                {
							smb = SMB_init((yyvsp[0].ystr));
							smb->var_type = TYPE_INT;
							smb->value.i = atoi((yyvsp[0].ystr));
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_NUM, smb, NULL, NULL, NULL, NULL);
						}
#line 1828 "y.tab.c"
    break;

  case 58:
#line 406 "final.yacc"
                                                {
							smb = SMB_init((yyvsp[0].ystr));
							smb->var_type = TYPE_FLOAT;
							smb->value.f = atof((yyvsp[0].ystr));
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_NUM, smb, NULL, NULL, NULL, NULL);
						}
#line 1840 "y.tab.c"
    break;


#line 1844 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 415 "final.yacc"
