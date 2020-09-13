#ifndef GLOBALS_H
#define GLOBALS_H

#define RESERVED_WORDS_COUNT 12
#define MAX_ID_LENGTH 15

#define FALSE 0
#define TRUE 1

#define DEBUG FALSE

#define TYPE_NONE 0
#define TYPE_INT 1
#define TYPE_FLOAT 2

#define ASTN_NUM_FLOAT			0
#define ASTN_NUM_INT			1
#define ASTN_FACTOR_NUM			2
#define ASTN_FACTOR_ID			3
#define ASTN_FACTOR_UMINUS		4
#define ASTN_FACTOR_PARENTH		5
#define ASTN_TERM_FACTOR		6
#define ASTN_TERM_DIVISION		7
#define ASTN_TERM_MULT			8
#define ASTN_R_VAL_TERM			9
#define ASTN_R_VAL_SUBSTR		10
#define ASTN_R_VAL_ADD			11
#define ASTN_BOOL_EXPR_NE		12
#define ASTN_BOOL_EXPR_GE		13
#define ASTN_BOOL_EXPR_LE		14
#define ASTN_BOOL_EXPR_GT		15
#define ASTN_BOOL_EXPR_LT		16
#define ASTN_BOOL_EXPR_EQ		17
#define ASTN_CLOSED_IF_STMT		18
#define ASTN_OPEN_IF_STMT		19
#define ASTN_OPEN_IF_ELSE_STMT		20
#define ASTN_CLOSED_WHILE_STMT		21
#define ASTN_OPEN_WHILE_STMT		22
#define ASTN_CLOSED_FOR_STMT		23
#define ASTN_OPEN_FOR_STMT		24
#define ASTN_OPBOOL_EXPR_EMPTY		25
#define ASTN_OPBOOL_EXPR		26
#define ASTN_ASSIGN_EXPR		27
#define ASTN_OPASSIGN_EXPR_EMPTY	28	
#define ASTN_OPASSIGN_EXPR		29
#define ASTN_EXPR_R_VAL			30
#define ASTN_EXPR_ASSIGN_EXPR		31	
#define ASTN_ASSIGN_STMT		32		
#define ASTN_NULL_STMT			33	
#define ASTN_ID_LIST_ONE		34	
#define ASTN_ID_LIST_MORE		35		
#define ASTN_TYPE_FLOAT			36	
#define ASTN_TYPE_INT			37	
#define ASTN_DECLARATION		38		
#define ASTN_PRINTLN_STMT		39		
#define ASTN_SIMPLE_STMT_PRINTLN	40		
#define ASTN_SIMPLE_STMT_NULL		41
#define ASTN_SIMPLE_STMT_DECLARATION	42
#define ASTN_SIMPLE_STMT_COMP		43	
#define ASTN_SIMPLE_STMT_ASSIGN		44
#define ASTN_CLOSED_STMT_SIMPLE		45
#define ASTN_CLOSED_STMT_IF		46	
#define ASTN_CLOSED_STMT_WHILE		47
#define ASTN_CLOSED_STMT_FOR		48
#define ASTN_OPEN_STMT_IF		49
#define ASTN_OPEN_STMT_WHILE		50
#define ASTN_OPEN_STMT_FOR		51
#define ASTN_STMT_CLOSED		52
#define ASTN_STMT_OPEN			53
#define ASTN_STMT_LIST_EMPTY		54
#define ASTN_STMT_LIST			55
#define ASTN_COMP_STMT			56
#define ASTN_PROGRAM			57

#endif
