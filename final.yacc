%{
#include <stdlib.h>
#include "globals.h"
#include "structures.h"
#include "check.h"
#include "logger.h"

extern Stack *st;
extern AST_Node *root;

int yylex(void);

Symbol *smb;
%}





%union{
	int yint;
	char ystr[15 + 1];
	struct AST_Node *p_astn;
}





%token <yint> MAINCLASS PUBLIC STATIC VOID MAIN INT FLOAT FOR WHILE IF ELSE PRINTLN

%token <ystr> INT_CONST FLOAT_CONST

%token <ystr> '(' ')' '{' '}'

%token <ystr> '=' ',' ';' '+' '-' '*' '/'

%token <ystr> EQ_OP NE_OP LT_OP GT_OP LE_OP GE_OP

%token <ystr> ID

%type <p_astn> program comp_stmt stmt_list stmt open_stmt closed_stmt simple_stmt declaration
%type <p_astn> id_list null_stmt assign_stmt assign_expr expr open_for_stmt closed_for_stmt type
%type <p_astn> opassign_expr opbool_expr open_while_stmt closed_while_stmt open_if_stmt closed_if_stmt
%type <p_astn> println_stmt bool_expr r_val term factor num

%start program





%%
program			:	MAINCLASS ID '{' PUBLIC STATIC VOID MAIN '(' ')' comp_stmt '}'
						{
							if(DEBUG) yydbg("ASTN_PROGRAM");
							smb = SMB_init($2);
							root = ASTN_init(ASTN_PROGRAM, smb, $10, NULL, NULL, NULL);
						}
			;


							
comp_stmt		:	'{' stmt_list '}'
						{
							if(DEBUG) yydbg("ASTN_COMP_STMT");
							$$ = ASTN_init(ASTN_COMP_STMT, NULL, $2, NULL, NULL, NULL);
						}
			;
			

				
stmt_list		:	stmt_list stmt
						{
							if(DEBUG) yydbg("ASTN_STMT_LIST");
							$$ = ASTN_init(ASTN_STMT_LIST, NULL, $1, $2, NULL, NULL);	
						}
			|	/* EMPTY */	
						{
							if(DEBUG) yydbg("ASTN_STMT_LIST_EMPTY");
							$$ = ASTN_init(ASTN_STMT_LIST_EMPTY, NULL, NULL, NULL, NULL, NULL);
						}	
			;


					
stmt			:	open_stmt
						{
							if(DEBUG) yydbg("ASTN_STMT_OPEN");
							$$ = ASTN_init(ASTN_STMT_OPEN, NULL, $1, NULL, NULL, NULL);
						}
			|	closed_stmt
						{
							if(DEBUG) yydbg("ASTN_STMT_CLOSED");
							$$ = ASTN_init(ASTN_STMT_CLOSED, NULL, $1, NULL, NULL, NULL);
						}
			;



open_stmt		:	open_for_stmt
						{
							if(DEBUG) yydbg("ASTN_OPEN_STMT_FOR");
							$$ = ASTN_init(ASTN_OPEN_STMT_FOR, NULL, $1, NULL, NULL, NULL);
						}
			|	open_while_stmt
						{
							if(DEBUG) yydbg("ASTN_OPEN_STMT_WHILE");
							$$ = ASTN_init(ASTN_OPEN_STMT_WHILE, NULL, $1, NULL, NULL, NULL);
						}
			|	open_if_stmt
						{
							if(DEBUG) yydbg("ASTN_OPEN_STMT_IF");
							$$ = ASTN_init(ASTN_OPEN_STMT_IF, NULL, $1, NULL, NULL, NULL);
						}
			;



closed_stmt		:	closed_for_stmt
						{
							if(DEBUG) yydbg("ASTN_CLOSED_STMT_FOR");
							$$ = ASTN_init(ASTN_CLOSED_STMT_FOR, NULL, $1, NULL, NULL, NULL);
						}
			|	closed_while_stmt
						{
							if(DEBUG) yydbg("ASTN_CLOSED_STMT_WHILE");
							$$ = ASTN_init(ASTN_CLOSED_STMT_WHILE, NULL, $1, NULL, NULL, NULL);
						}
			|	closed_if_stmt
						{
							if(DEBUG) yydbg("ASTN_CLOSED_STMT_IF");
							$$ = ASTN_init(ASTN_CLOSED_STMT_IF, NULL, $1, NULL, NULL, NULL);
						}
			|	simple_stmt
						{
							if(DEBUG) yydbg("ASTN_CLOSED_STMT_SIMPLE");
							$$ = ASTN_init(ASTN_CLOSED_STMT_SIMPLE, NULL, $1, NULL, NULL, NULL);
						}
			;


	
simple_stmt		:	assign_stmt
						{
							if(DEBUG) yydbg("ASTN_SIMPLE_STMT_ASSIGN");
							$$ = ASTN_init(ASTN_SIMPLE_STMT_ASSIGN, NULL, $1, NULL, NULL, NULL);
						}
			|	 comp_stmt
						{
							if(DEBUG) yydbg("ASTN_COMP_STMT");
							$$ = ASTN_init(ASTN_COMP_STMT, NULL, $1, NULL, NULL, NULL);
						}
			|	declaration
						{
							if(DEBUG) yydbg("ASTN_SIMPLE_STMT_DECLARATION");
							$$ = ASTN_init(ASTN_SIMPLE_STMT_DECLARATION, NULL, $1, NULL, NULL, NULL);
						}
			|	null_stmt
						{
							if(DEBUG) yydbg("ASTN_SIMPLE_STMT_NULL");
							$$ = ASTN_init(ASTN_SIMPLE_STMT_NULL, NULL, $1, NULL, NULL, NULL);
						}
			|	println_stmt
						{
							if(DEBUG) yydbg("ASTN_SIMPLE_STMT_PRINTLN");
							$$ = ASTN_init(ASTN_SIMPLE_STMT_PRINTLN, NULL, $1, NULL, NULL, NULL);
						}
			;
			


println_stmt		:	PRINTLN '(' expr ')' ';'
						{
							if(DEBUG) yydbg("ASTN_PRINTLN_STMT");
							smb = ST_pop(st);
							check_println(smb);
							$$ = ASTN_init(ASTN_PRINTLN_STMT, smb, $3, NULL, NULL, NULL);
						}
			;	


		
declaration		:	type id_list ';'
						{
							if(DEBUG) yydbg("ASTN_DECLARATION");
							Symbol *dummy = $1->wrapped_symbol;
							check_declaration(dummy, $2);
							$$ = ASTN_init(ASTN_DECLARATION, dummy, $2, NULL, NULL, NULL);
						}
			;
			


type			:	INT
						{
							if(DEBUG) yydbg("ASTN_TYPE_INT");
							smb = SMB_init("");
							smb->var_type = TYPE_INT;
							$$ = ASTN_init(ASTN_TYPE_INT, smb, NULL, NULL, NULL, NULL);
						}
			|
				FLOAT
						{
							if(DEBUG) yydbg("ASTN_TYPE_FLOAT");
							smb = SMB_init("");
							smb->var_type = TYPE_FLOAT;
							$$ = ASTN_init(ASTN_TYPE_FLOAT, smb, NULL, NULL, NULL, NULL);
						}
			;



id_list			:	ID ',' id_list
						{
							if(DEBUG) yydbg("ASTN_ID_LIST_MORE");
							smb = SMB_init($1);
							$$ = ASTN_init(ASTN_ID_LIST_MORE, smb, $3, NULL, NULL, NULL);
						}
			|	ID
						{
							if(DEBUG) yydbg("ASTN_ID_LIST_ONE");
							smb = SMB_init($1);
							$$ = ASTN_init(ASTN_ID_LIST_ONE, smb, NULL, NULL, NULL, NULL);
						}
			;



null_stmt		:	';'
						{
							if(DEBUG) yydbg("ASTN_NULL_STMT");
							$$ = ASTN_init(ASTN_NULL_STMT, NULL, NULL, NULL, NULL, NULL); 
						}
			;
				

		
assign_stmt		:	assign_expr ';'
						{
							if(DEBUG) yydbg("ASTN_ASSIGN_STMT");
							smb = ST_pop(st);
							$$ = ASTN_init(ASTN_ASSIGN_STMT, smb, $1, NULL, NULL, NULL);
						}
			;
			


expr			
			:	assign_expr	{
							if(DEBUG) yydbg("ASTN_EXPR_ASSIGN_EXPR");
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_EXPR_ASSIGN_EXPR, smb, $1, NULL, NULL, NULL);
						}
			|	r_val		
						{
							if(DEBUG) yydbg("ASTN_EXPR_R_VAL");
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_EXPR_R_VAL, smb, $1, NULL, NULL, NULL);
						}
			;	



opassign_expr		:	assign_expr
						{
							if(DEBUG) yydbg("ASTN_OPASSIGN_EXPR");
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_OPASSIGN_EXPR, smb, $1, NULL, NULL, NULL);
						}
			|	/* EMPTY */
						{
							if(DEBUG) yydbg("ASTN_OPASSIGN_EXPR_EMPTY");
							smb = SMB_init("");
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_OPASSIGN_EXPR_EMPTY, smb, NULL, NULL, NULL, NULL);
						}	
			;
	


assign_expr		:	ID '=' expr
						{
							if(DEBUG) yydbg("ASTN_ASSIGN_EXPR");
							Symbol *id = SMB_init($1);
							smb = ST_pop(st);
							smb = check_assign(id, smb);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_ASSIGN_EXPR, smb, $3, NULL, NULL, NULL);							
						}
			;


		
opbool_expr		:	bool_expr
						{
							if(DEBUG) yydbg("ASTN_OPBOOL_EXPR");
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_OPBOOL_EXPR, smb, $1, NULL, NULL, NULL);
						}
			|	/* EMPTY */
						{
							if(DEBUG) yydbg("ASTN_OPBOOL_EXPR_EMPTY");
							smb = SMB_init("");
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_OPBOOL_EXPR_EMPTY, smb, NULL, NULL, NULL, NULL);
						}
			;
							
				
			
open_for_stmt		:	FOR '(' opassign_expr ';' opbool_expr ';' opassign_expr ')' open_stmt
						{
							if(DEBUG) yydbg("ASTN_OPEN_FOR_STMT");
							ST_pop(st);
							smb = ST_pop(st);
							ST_pop(st);
							$$ = ASTN_init(ASTN_OPEN_FOR_STMT, smb, $3, $5, $7, $9);
						}
			;



closed_for_stmt		:	FOR '(' opassign_expr ';' opbool_expr ';' opassign_expr ')' closed_stmt
						{
							if(DEBUG) yydbg("ASTN_CLOSED_FOR_STMT");
							ST_pop(st);
							smb = ST_pop(st);
							ST_pop(st);
							$$ = ASTN_init(ASTN_CLOSED_FOR_STMT, smb, $3, $5, $7, $9); 						
						}
			;
			

				
open_while_stmt		:	WHILE '(' bool_expr ')' open_stmt
						{
							if(DEBUG) yydbg("ASTN_OPEN_WHILE_STMT");
							smb = ST_pop(st);
							$$ = ASTN_init(ASTN_OPEN_WHILE_STMT, smb, $3, $5, NULL, NULL);
						}
			;



closed_while_stmt	:	WHILE '(' bool_expr ')' closed_stmt
						{
							if(DEBUG) yydbg("ASTN_CLOSED_WHILE_STMT");
							smb = ST_pop(st);
							$$ = ASTN_init(ASTN_CLOSED_WHILE_STMT, smb, $3, $5, NULL, NULL);
						}
			;



open_if_stmt		:	IF '(' bool_expr ')' stmt
						{
							if(DEBUG) yydbg("ASTN_OPEN_IF_STMT");
							smb = ST_pop(st);
							$$ = ASTN_init(ASTN_OPEN_IF_STMT, smb, $3, $5, NULL, NULL);
						}
			|	IF '(' bool_expr ')' closed_stmt ELSE open_stmt
						{
							if(DEBUG) yydbg("ASTN_OPEN_IF_ELSE_STMT");
							smb = ST_pop(st);
							$$ = ASTN_init(ASTN_OPEN_IF_ELSE_STMT, smb, $3, $5, $7, NULL);
						}
			;



closed_if_stmt		:	IF '(' bool_expr ')' closed_stmt ELSE closed_stmt
						{
							if(DEBUG) yydbg("ASTN_CLOSED_IF_STMT");
							smb = ST_pop(st);
							$$ = ASTN_init(ASTN_CLOSED_IF_STMT, smb, $3, $5, $7, NULL);
						}
			;
			

				
bool_expr		:	expr EQ_OP expr
						{
							if(DEBUG) yydbg("ASTN_BOOL_EXPR_EQ");
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_eq(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_BOOL_EXPR_EQ, smb, $1, $3, NULL, NULL);
						}
			|	expr LT_OP expr
						{
							if(DEBUG) yydbg("ASTN_BOOL_EXPR_LT");
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_lt(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_BOOL_EXPR_LT, smb, $1, $3, NULL, NULL);
						}
			|	expr GT_OP expr
						{
							if(DEBUG) yydbg("ASTN_BOOL_EXPR_GT");
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_gt(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_BOOL_EXPR_GT, smb, $1, $3, NULL, NULL);
						}
			|	expr LE_OP expr
						{
							if(DEBUG) yydbg("ASTN_BOOL_EXPR_LE");
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_le(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_BOOL_EXPR_LE, smb, $1, $3, NULL, NULL);
						}
			|	expr GE_OP expr
						{
							if(DEBUG) yydbg("ASTN_BOOL_EXPR_GE");
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_ge(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_BOOL_EXPR_GE, smb, $1, $3, NULL, NULL);
						}
			|	expr NE_OP expr
						{
							if(DEBUG) yydbg("ASTN_BOOL_EXPR_NE");
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_ne(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_BOOL_EXPR_NE, smb, $1, $3, NULL, NULL);
						}
			;



r_val			:	r_val '+' term
						{
							if(DEBUG) yydbg("ASTN_R_VAL_ADD");
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_add(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_R_VAL_ADD, smb, $1, $3, NULL, NULL);
						
						}
			|	r_val '-' term
						{
							if(DEBUG) yydbg("ASTN_R_VAL_SUBSTR");
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_substr(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_R_VAL_SUBSTR, smb, $1, $3, NULL, NULL);
						}
			|	term
						{
							if(DEBUG) yydbg("ASTN_R_VAL_TERM");
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_R_VAL_TERM, smb, $1, NULL, NULL, NULL);	
						}
			;
				

	
term			:	term '*' factor
						{
							if(DEBUG) yydbg("ASTN_TERM_MULT");
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_mult(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_TERM_MULT, smb, $1, $3, NULL, NULL);
							
						}
			|	term '/' factor
						{
							if(DEBUG) yydbg("STN_TERM_DIVISION");
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_division(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_TERM_DIVISION, smb, $1, $3, NULL, NULL);
						}
			|	factor
						{
							if(DEBUG) yydbg("ASTN_TERM_FACTOR");
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_TERM_FACTOR, smb, $1, NULL, NULL, NULL);
						}
			;
			

	
factor			:	'(' expr ')'
						{
							if(DEBUG) yydbg("ASTN_FACTOR_PARENTH");
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_FACTOR_PARENTH, smb, $2, NULL, NULL, NULL);
						}
			|	'-' factor
						{
							if(DEBUG) yydbg("ASTN_FACTOR_UMINUS");
							smb = ST_pop(st);
							smb = check_uminus(smb);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_FACTOR_UMINUS, smb, $2, NULL, NULL, NULL);
						}
			|	ID
						{
							if(DEBUG) yydbg("ASTN_FACTOR_ID");
							smb = SMB_init($1);
							smb = check_id_reference(smb);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_FACTOR_ID, smb, NULL, NULL, NULL, NULL);
						}
			|	num
						{
							if(DEBUG) yydbg("ASTN_FACTOR_NUM");
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_FACTOR_NUM, smb, $1, NULL, NULL, NULL);
						}
			;



num			:	INT_CONST
						{
							if(DEBUG) yydbg("ASTN_NUM_INT");
							smb = SMB_init($1);
							smb->var_type = TYPE_INT;
							smb->value.i = atoi($1);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_NUM_INT, smb, NULL, NULL, NULL, NULL);
						}
			|	FLOAT_CONST	
						{
							if(DEBUG) yydbg("ASTN_NUM_FLOAT");
							smb = SMB_init($1);
							smb->var_type = TYPE_FLOAT;
							smb->value.f = atof($1);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_NUM_FLOAT, smb, NULL, NULL, NULL, NULL);
						}
			;						
%%