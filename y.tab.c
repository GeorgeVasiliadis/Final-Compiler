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
  YYSYMBOL_println_stmt = 43,              /* println_stmt  */
  YYSYMBOL_declaration = 44,               /* declaration  */
  YYSYMBOL_type = 45,                      /* type  */
  YYSYMBOL_id_list = 46,                   /* id_list  */
  YYSYMBOL_null_stmt = 47,                 /* null_stmt  */
  YYSYMBOL_assign_stmt = 48,               /* assign_stmt  */
  YYSYMBOL_expr = 49,                      /* expr  */
  YYSYMBOL_opassign_expr = 50,             /* opassign_expr  */
  YYSYMBOL_assign_expr = 51,               /* assign_expr  */
  YYSYMBOL_opbool_expr = 52,               /* opbool_expr  */
  YYSYMBOL_open_for_stmt = 53,             /* open_for_stmt  */
  YYSYMBOL_closed_for_stmt = 54,           /* closed_for_stmt  */
  YYSYMBOL_open_while_stmt = 55,           /* open_while_stmt  */
  YYSYMBOL_closed_while_stmt = 56,         /* closed_while_stmt  */
  YYSYMBOL_open_if_stmt = 57,              /* open_if_stmt  */
  YYSYMBOL_closed_if_stmt = 58,            /* closed_if_stmt  */
  YYSYMBOL_bool_expr = 59,                 /* bool_expr  */
  YYSYMBOL_r_val = 60,                     /* r_val  */
  YYSYMBOL_term = 61,                      /* term  */
  YYSYMBOL_factor = 62,                    /* factor  */
  YYSYMBOL_num = 63                        /* num  */
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
#define YYLAST   104

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  113

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
       0,    44,    44,    51,    57,    62,    67,    71,    77,    81,
      85,    91,    95,    99,   103,   109,   113,   117,   121,   126,
     133,   141,   149,   156,   165,   174,   185,   191,   199,   204,
     212,   219,   224,   236,   242,   248,   257,   266,   273,   280,
     285,   292,   299,   307,   315,   323,   331,   339,   349,   358,
     366,   374,   383,   391,   399,   405,   412,   422,   430,   438
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
  "println_stmt", "declaration", "type", "id_list", "null_stmt",
  "assign_stmt", "expr", "opassign_expr", "assign_expr", "opbool_expr",
  "open_for_stmt", "closed_for_stmt", "open_while_stmt",
  "closed_while_stmt", "open_if_stmt", "closed_if_stmt", "bool_expr",
  "r_val", "term", "factor", "num", YY_NULLPTR
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

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       8,    -7,    38,    29,   -72,    46,    47,    45,    49,    36,
      39,    40,   -72,    48,    35,   -72,   -72,   -72,    50,    55,
      56,    57,   -72,   -72,    60,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,    42,   -72,   -72,    54,   -72,   -72,   -72,   -72,
     -72,   -72,    51,   -10,   -10,   -10,   -10,    61,    59,   -72,
      64,   -72,   -72,   -72,   -10,    63,    60,   -12,   -72,    66,
     -21,    -4,   -72,   -72,    71,    72,   -72,    42,   -72,   -10,
      75,   -72,   -72,   -10,   -10,   -10,   -10,   -10,   -10,    52,
      63,    63,    63,    63,    52,    76,   -72,    77,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,    -4,    -4,
     -72,   -72,   -72,    81,   -72,    51,    52,    80,   -72,   -72,
      52,   -72,   -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     5,     0,     0,     2,    22,    23,     0,     0,
       0,     0,     3,    26,     0,    16,     4,     6,     7,    14,
      19,    17,     0,    18,    15,     0,     8,    11,     9,    12,
      10,    13,    31,     0,     0,     0,     0,    25,     0,    27,
       0,    30,    58,    59,     0,     0,    56,     0,    28,     0,
      29,    50,    53,    57,     0,     0,    32,     0,    21,    34,
       0,    56,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,     0,    33,    54,
      42,    47,    43,    44,    45,    46,    37,    38,    48,    49,
      51,    52,    39,     7,    20,    31,     0,     0,    40,    41,
       0,    35,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -72,    84,   -72,    17,   -70,   -71,   -72,   -72,   -72,
     -72,    37,   -72,   -72,   -44,    -3,   -14,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -32,   -72,   -55,   -41,   -72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    25,    14,    26,    27,    28,    29,    30,    31,
      32,    48,    33,    34,    57,    50,    58,    87,    36,    37,
      38,    39,    40,    41,    59,    60,    61,    62,    63
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      35,    65,    66,    80,    81,    52,    53,    54,    97,    96,
      70,     1,    64,   103,    72,    55,    73,    74,    75,    76,
      77,    78,    82,    83,    56,    98,    99,     3,    51,    90,
      91,    92,    93,    94,    95,   109,   108,    88,     4,   112,
     111,   100,   101,    16,    17,    18,    19,    20,     5,    21,
       6,     8,     7,    10,    12,    22,     9,    11,    23,    12,
      16,    17,    18,    19,    20,    35,    21,    42,    15,    24,
      35,    12,    43,    44,    45,    23,    47,    49,    52,    53,
      54,    46,    68,    67,    79,    24,    24,    69,    55,    84,
      85,    51,    35,    89,   106,    13,    35,    71,   110,   104,
     105,   102,   107,     0,    86
};

static const yytype_int8 yycheck[] =
{
      14,    45,    46,    24,    25,    15,    16,    17,    79,    79,
      54,     3,    44,    84,    55,    25,    28,    29,    30,    31,
      32,    33,    26,    27,    34,    80,    81,    34,    42,    73,
      74,    75,    76,    77,    78,   106,   106,    69,     0,   110,
     110,    82,    83,     8,     9,    10,    11,    12,    19,    14,
       4,     6,     5,    17,    19,    20,     7,    18,    23,    19,
       8,     9,    10,    11,    12,    79,    14,    17,    20,    34,
      84,    19,    17,    17,    17,    23,    34,    23,    15,    16,
      17,    21,    23,    22,    18,    34,    34,    23,    25,    18,
      18,   105,   106,    18,    13,    11,   110,    34,    18,    23,
      23,    84,   105,    -1,    67
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    36,    34,     0,    19,     4,     5,     6,     7,
      17,    18,    19,    37,    38,    20,     8,     9,    10,    11,
      12,    14,    20,    23,    34,    37,    39,    40,    41,    42,
      43,    44,    45,    47,    48,    51,    53,    54,    55,    56,
      57,    58,    17,    17,    17,    17,    21,    34,    46,    23,
      50,    51,    15,    16,    17,    25,    34,    49,    51,    59,
      60,    61,    62,    63,    59,    49,    49,    22,    23,    23,
      49,    34,    62,    28,    29,    30,    31,    32,    33,    18,
      24,    25,    26,    27,    18,    18,    46,    52,    59,    18,
      49,    49,    49,    49,    49,    49,    40,    41,    61,    61,
      62,    62,    39,    41,    23,    23,    13,    50,    40,    41,
      18,    40,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    38,    38,    39,    39,    40,    40,
      40,    41,    41,    41,    41,    42,    42,    42,    42,    42,
      43,    44,    45,    45,    46,    46,    47,    48,    49,    49,
      50,    50,    51,    52,    52,    53,    54,    55,    56,    57,
      57,    58,    59,    59,    59,    59,    59,    59,    60,    60,
      60,    61,    61,    61,    62,    62,    62,    62,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,    11,     3,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     3,     1,     1,     3,     1,     1,     2,     1,     1,
       1,     0,     3,     1,     0,     9,     9,     5,     5,     5,
       7,     7,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     2,     1,     1,     1,     1
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
#line 1313 "y.tab.c"
    break;

  case 3:
#line 52 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_COMP_STMT, NULL, (yyvsp[-1].p_astn), NULL, NULL, NULL);
						}
#line 1321 "y.tab.c"
    break;

  case 4:
#line 58 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_STMT_LIST, NULL, (yyvsp[-1].p_astn), (yyvsp[0].p_astn), NULL, NULL);	
						}
#line 1329 "y.tab.c"
    break;

  case 5:
#line 62 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_STMT_LIST_EMPTY, NULL, NULL, NULL, NULL, NULL);
						}
#line 1337 "y.tab.c"
    break;

  case 6:
#line 68 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_STMT_OPEN, NULL, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1345 "y.tab.c"
    break;

  case 7:
#line 72 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_STMT_CLOSED, NULL, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1353 "y.tab.c"
    break;

  case 8:
#line 78 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_OPEN_STMT_FOR, NULL, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1361 "y.tab.c"
    break;

  case 9:
#line 82 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_OPEN_STMT_WHILE, NULL, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1369 "y.tab.c"
    break;

  case 10:
#line 86 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_OPEN_STMT_IF, NULL, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1377 "y.tab.c"
    break;

  case 11:
#line 92 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_CLOSED_STMT_FOR, NULL, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1385 "y.tab.c"
    break;

  case 12:
#line 96 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_CLOSED_STMT_WHILE, NULL, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1393 "y.tab.c"
    break;

  case 13:
#line 100 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_CLOSED_STMT_IF, NULL, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1401 "y.tab.c"
    break;

  case 14:
#line 104 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_CLOSED_STMT_SIMPLE, NULL, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1409 "y.tab.c"
    break;

  case 15:
#line 110 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_SIMPLE_STMT_ASSIGN, NULL, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1417 "y.tab.c"
    break;

  case 16:
#line 114 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_SIMPLE_STMT_COMP, NULL, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1425 "y.tab.c"
    break;

  case 17:
#line 118 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_SIMPLE_STMT_DECLARATION, NULL, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1433 "y.tab.c"
    break;

  case 18:
#line 122 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_SIMPLE_STMT_NULL, NULL, NULL, NULL, NULL, NULL);
						}
#line 1441 "y.tab.c"
    break;

  case 19:
#line 127 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_SIMPLE_STMT_PRINTLN, NULL, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1449 "y.tab.c"
    break;

  case 20:
#line 134 "final.yacc"
                                                {
							smb = ST_pop(st);
							check_println(smb);
							(yyval.p_astn) = ASTN_init(ASTN_PRINTLN_STMT, smb, (yyvsp[-2].p_astn), NULL, NULL, NULL);
						}
#line 1459 "y.tab.c"
    break;

  case 21:
#line 142 "final.yacc"
                                                {
							Symbol *dummy = (yyvsp[-2].p_astn)->wrapped_symbol;
							check_declaration(dummy, (yyvsp[-1].p_astn));
							(yyval.p_astn) = ASTN_init(ASTN_DECLARATION, dummy, (yyvsp[-1].p_astn), NULL, NULL, NULL);
						}
#line 1469 "y.tab.c"
    break;

  case 22:
#line 150 "final.yacc"
                                                {
							smb = SMB_init("");
							smb->var_type = TYPE_INT;
							(yyval.p_astn) = ASTN_init(ASTN_TYPE_INT, smb, NULL, NULL, NULL, NULL);
						}
#line 1479 "y.tab.c"
    break;

  case 23:
#line 157 "final.yacc"
                                                {
							
							smb = SMB_init("");
							smb->var_type = TYPE_FLOAT;
							(yyval.p_astn) = ASTN_init(ASTN_TYPE_FLOAT, smb, NULL, NULL, NULL, NULL);
						}
#line 1490 "y.tab.c"
    break;

  case 24:
#line 166 "final.yacc"
                                                {
							smb = SMB_init((yyvsp[-2].ystr));
							if(!HT_add(ht, smb)){
								fprintf(stderr, "Error: Tried to declare ID multiple times.\n");
								exit(1);
							}
							(yyval.p_astn) = ASTN_init(ASTN_ID_LIST_MORE, smb, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1503 "y.tab.c"
    break;

  case 25:
#line 175 "final.yacc"
                                                {
							smb = SMB_init((yyvsp[0].ystr));
							if(! (smb = HT_add(ht, smb))){
								fprintf(stderr, "Error: Tried to declare ID multiple times.\n");
								exit(1);
							}
							(yyval.p_astn) = ASTN_init(ASTN_ID_LIST_ONE, smb, NULL, NULL, NULL, NULL);
						}
#line 1516 "y.tab.c"
    break;

  case 26:
#line 186 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_NULL_STMT, NULL, NULL, NULL, NULL, NULL); 
						}
#line 1524 "y.tab.c"
    break;

  case 27:
#line 192 "final.yacc"
                                                {
							smb = ST_pop(st);
							(yyval.p_astn) = ASTN_init(ASTN_ASSIGN_STMT, smb, (yyvsp[-1].p_astn), NULL, NULL, NULL);
						}
#line 1533 "y.tab.c"
    break;

  case 28:
#line 199 "final.yacc"
                                                {
							smb = ST_pop(st);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_EXPR_ASSIGN_EXPR, smb, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1543 "y.tab.c"
    break;

  case 29:
#line 205 "final.yacc"
                                                {
							smb = ST_pop(st);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_EXPR_R_VAL, smb, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1553 "y.tab.c"
    break;

  case 30:
#line 213 "final.yacc"
                                                {
							smb = ST_pop(st);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_OPASSIGN_EXPR, smb, NULL, NULL, NULL, NULL);
						}
#line 1563 "y.tab.c"
    break;

  case 31:
#line 219 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_OPASSIGN_EXPR_EMPTY, NULL, NULL, NULL, NULL, NULL);
						}
#line 1571 "y.tab.c"
    break;

  case 32:
#line 225 "final.yacc"
                                                {
							smb = ST_pop(st);
							Symbol *id = HT_get(ht, (yyvsp[-2].ystr));
							smb = check_assign(id, smb);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_ASSIGN_EXPR, smb, (yyvsp[0].p_astn), NULL, NULL, NULL);							
						}
#line 1583 "y.tab.c"
    break;

  case 33:
#line 237 "final.yacc"
                                                {
							smb = ST_pop(st);
							(yyval.p_astn) = ASTN_init(ASTN_OPBOOL_EXPR, smb, NULL, NULL, NULL, NULL);
						}
#line 1592 "y.tab.c"
    break;

  case 34:
#line 242 "final.yacc"
                                                {
							(yyval.p_astn) = ASTN_init(ASTN_OPBOOL_EXPR_EMPTY, NULL, NULL, NULL, NULL, NULL);
						}
#line 1600 "y.tab.c"
    break;

  case 35:
#line 249 "final.yacc"
                                                {
							ST_pop(st);
							smb = ST_pop(st);
							ST_pop(st);
							(yyval.p_astn) = ASTN_init(ASTN_OPEN_FOR_STMT, smb, (yyvsp[-6].p_astn), (yyvsp[-2].p_astn), NULL, NULL);
						}
#line 1611 "y.tab.c"
    break;

  case 36:
#line 258 "final.yacc"
                                                {
							ST_pop(st);
							smb = ST_pop(st);
							ST_pop(st);
							(yyval.p_astn) = ASTN_init(ASTN_CLOSED_FOR_STMT, smb, (yyvsp[-6].p_astn), (yyvsp[-2].p_astn), NULL, NULL); 						
						}
#line 1622 "y.tab.c"
    break;

  case 37:
#line 267 "final.yacc"
                                                {
							smb = ST_pop(st);
							(yyval.p_astn) = ASTN_init(ASTN_OPEN_WHILE_STMT, smb, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1631 "y.tab.c"
    break;

  case 38:
#line 274 "final.yacc"
                                                {
							smb = ST_pop(st);
							(yyval.p_astn) = ASTN_init(ASTN_CLOSED_WHILE_STMT, smb, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1640 "y.tab.c"
    break;

  case 39:
#line 281 "final.yacc"
                                                {
							smb = ST_pop(st);
							(yyval.p_astn) = ASTN_init(ASTN_OPEN_IF_STMT, smb, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1649 "y.tab.c"
    break;

  case 40:
#line 286 "final.yacc"
                                                {
							smb = ST_pop(st);
							(yyval.p_astn) = ASTN_init(ASTN_OPEN_IF_ELSE_STMT, smb, (yyvsp[-2].p_astn), (yyvsp[0].p_astn), NULL, NULL);
						}
#line 1658 "y.tab.c"
    break;

  case 41:
#line 293 "final.yacc"
                                                {
							smb = ST_pop(st);
							(yyval.p_astn) = ASTN_init(ASTN_CLOSED_IF_STMT, smb, (yyvsp[-2].p_astn), (yyvsp[0].p_astn), NULL, NULL);
						}
#line 1667 "y.tab.c"
    break;

  case 42:
#line 300 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_eq(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_BOOL_EXPR_EQ, smb, NULL, NULL, NULL, NULL);
						}
#line 1679 "y.tab.c"
    break;

  case 43:
#line 308 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_lt(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_BOOL_EXPR_LT, smb, NULL, NULL, NULL, NULL);
						}
#line 1691 "y.tab.c"
    break;

  case 44:
#line 316 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_gt(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_BOOL_EXPR_GT, smb, NULL, NULL, NULL, NULL);
						}
#line 1703 "y.tab.c"
    break;

  case 45:
#line 324 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_le(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_BOOL_EXPR_LE, smb, NULL, NULL, NULL, NULL);
						}
#line 1715 "y.tab.c"
    break;

  case 46:
#line 332 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_ge(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_BOOL_EXPR_GE, smb, NULL, NULL, NULL, NULL);
						}
#line 1727 "y.tab.c"
    break;

  case 47:
#line 340 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_ne(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_BOOL_EXPR_NE, smb, NULL, NULL, NULL, NULL);
						}
#line 1739 "y.tab.c"
    break;

  case 48:
#line 350 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_add(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_R_VAL_ADD, smb, (yyvsp[-2].p_astn), (yyvsp[0].p_astn), NULL, NULL);
						
						}
#line 1752 "y.tab.c"
    break;

  case 49:
#line 359 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_substr(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_R_VAL_SUBSTR, smb, (yyvsp[-2].p_astn), (yyvsp[0].p_astn), NULL, NULL);
						}
#line 1764 "y.tab.c"
    break;

  case 50:
#line 367 "final.yacc"
                                                {
							smb = ST_pop(st);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_R_VAL_TERM, smb, (yyvsp[0].p_astn), NULL, NULL, NULL);	
						}
#line 1774 "y.tab.c"
    break;

  case 51:
#line 375 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_mult(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_TERM_MULT, smb, (yyvsp[-2].p_astn), (yyvsp[0].p_astn), NULL, NULL);
							
						}
#line 1787 "y.tab.c"
    break;

  case 52:
#line 384 "final.yacc"
                                                {
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_division(smb, temp);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_TERM_DIVISION, smb, (yyvsp[-2].p_astn), (yyvsp[0].p_astn), NULL, NULL);
						}
#line 1799 "y.tab.c"
    break;

  case 53:
#line 392 "final.yacc"
                                                {
							smb = ST_pop(st);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_TERM_FACTOR, smb, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1809 "y.tab.c"
    break;

  case 54:
#line 400 "final.yacc"
                                                {
							smb = ST_pop(st);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_FACTOR_PARENTH, smb, (yyvsp[-1].p_astn), NULL, NULL, NULL);
						}
#line 1819 "y.tab.c"
    break;

  case 55:
#line 406 "final.yacc"
                                                {
							smb = ST_pop(st);
							smb = check_uminus(smb);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_FACTOR_UMINUS, smb, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1830 "y.tab.c"
    break;

  case 56:
#line 413 "final.yacc"
                                                {
							smb = HT_get(ht, (yyvsp[0].ystr));
							if(!smb){
								fprintf(stderr, "Error: Tried to use ID before declaration.\n");
								exit(1);
							}
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_FACTOR_ID, smb, NULL, NULL, NULL, NULL);
						}
#line 1844 "y.tab.c"
    break;

  case 57:
#line 423 "final.yacc"
                                                {
							smb = ST_pop(st);
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_FACTOR_NUM, smb, (yyvsp[0].p_astn), NULL, NULL, NULL);
						}
#line 1854 "y.tab.c"
    break;

  case 58:
#line 431 "final.yacc"
                                                {
							smb = SMB_init((yyvsp[0].ystr));
							smb->var_type = TYPE_INT;
							smb->value.i = atoi((yyvsp[0].ystr));
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_NUM_INT, smb, NULL, NULL, NULL, NULL);
						}
#line 1866 "y.tab.c"
    break;

  case 59:
#line 439 "final.yacc"
                                                {
							smb = SMB_init((yyvsp[0].ystr));
							smb->var_type = TYPE_FLOAT;
							smb->value.f = atof((yyvsp[0].ystr));
							ST_push(st, smb);
							(yyval.p_astn) = ASTN_init(ASTN_NUM_FLOAT, smb, NULL, NULL, NULL, NULL);
						}
#line 1878 "y.tab.c"
    break;


#line 1882 "y.tab.c"

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

#line 448 "final.yacc"
