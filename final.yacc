%{
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

%}

%union{
	int yint;
	float yfloat;
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
%type <p_astn> bool_expr r_val term factor num

%start program

%%

program			:	MAINCLASS ID '{' PUBLIC STATIC VOID MAIN '(' ')' comp_stmt '}'
						{
							smb = SMB_init($2);
							root = ASTN_init(ASTN_PROGRAM, smb, $10, NULL, NULL, NULL);
						}
			;
							
comp_stmt		:	'{' stmt_list '}'
						{
							$$ = $2;
						}
			;
							
stmt_list		:	stmt_list stmt
						{
							$$ = ASTN_init(ASTN_STMT_LIST, NULL, $1, $2, NULL, NULL);	
						}
			|	/* EMPTY */	
						{
							$$ = ASTN_init(ASTN_STMT_LIST, NULL, NULL, NULL, NULL, NULL);
						}	
			;
					
stmt			:	open_stmt
						{
						}
			|	closed_stmt
						{
							$$ = $1;
						}
			;

open_stmt		:	open_for_stmt
						{
						}
			|	open_while_stmt
						{
						}
			|	open_if_stmt
						{
						}
			;

closed_stmt		:	closed_for_stmt
						{
						}
			|	closed_while_stmt
						{
						}
			|	closed_if_stmt
						{
						}
			|	simple_stmt
						{
							$$ = $1;
						}
			;
	
simple_stmt		:	assign_stmt
						{
						}
			|	comp_stmt
						{
						}
			|	declaration
						{
						}
			|	null_stmt
						{
						}
			|	PRINTLN '(' expr ')' ';'
						{
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_PRINTLN, smb, NULL, NULL, NULL, NULL);
						}
			;
						
declaration		:	type id_list ';'
						{
							smb = ST_pop(st);
							Symbol *dummy = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_DECLARATION, dummy, $2, NULL, NULL, NULL);
						}
			;
			
type			:	INT
						{
							smb = SMB_init("");
							smb->var_type = TYPE_INT;
							ST_push(st, smb);
						}
			|
				FLOAT
						{
							
							smb = SMB_init("");
							smb->var_type = TYPE_FLOAT;
							ST_push(st, smb);
						}


id_list			:	ID ',' id_list
						{
							smb = SMB_init($1);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_ID_LIST, smb, $3, NULL, NULL, NULL);
						}
			|	ID
						{
							smb = SMB_init($1);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_ID_LIST, smb, NULL, NULL, NULL, NULL);
						}
			;

null_stmt		:	';'
						{
						}
			;
						
assign_stmt		:	assign_expr ';'
						{
						}
			;
			
expr			
			:	assign_expr	{
						}
			|	r_val		
						{
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_EXPR, smb, NULL, NULL, NULL, NULL);
						}
// THIS SECTION SHOULD BE DELETED _START_
			|	bool_expr
						{
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_EXPR, smb, NULL, NULL, NULL, NULL);
						}
// THIS SECTION SHOULD BE DELETED _STOP_
			;	
	
assign_expr		:	ID '=' expr
						{
								
						}
			;
							
open_for_stmt		:	FOR '(' opassign_expr ';' opbool_expr ';' opassign_expr ')' open_stmt
						{							
						}
			;

closed_for_stmt		:	FOR '(' opassign_expr ';' opbool_expr ';' opassign_expr ')' closed_stmt
						{							
						}
			;
							
opassign_expr		:	assign_expr
						{
						}
			|	/* EMPTY */
						{
						}	
			;
						
opbool_expr		:	bool_expr
						{
						}
			|	/* EMPTY */
						{
						}
			;
							
open_while_stmt		:	WHILE '(' bool_expr ')' open_stmt
						{
						}
			;

closed_while_stmt	:	WHILE '(' bool_expr ')' closed_stmt
						{
						}
			;

open_if_stmt		:	IF '(' bool_expr ')' stmt
						{	
							ST_pop(st);
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_IF_STMT, smb, $5, NULL, NULL, NULL);
						}
			|	IF '(' bool_expr ')' closed_stmt ELSE open_stmt
						{
							ST_pop(st);
							ST_pop(st);
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_IF_STMT, smb, $5, $7, NULL, NULL);
						}
			;

closed_if_stmt		:	IF '(' bool_expr ')' closed_stmt ELSE closed_stmt
						{
							ST_pop(st);
							ST_pop(st);
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_IF_STMT, smb, $5, $7, NULL, NULL);
						}
			;



							
bool_expr		:	expr EQ_OP expr
						{
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_eq(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_BOOL_EXPR, smb, NULL, NULL, NULL, NULL);
						}
			|	expr LT_OP expr
						{
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_lt(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_BOOL_EXPR, smb, NULL, NULL, NULL, NULL);
						}
			|	expr GT_OP expr
						{
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_gt(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_BOOL_EXPR, smb, NULL, NULL, NULL, NULL);
						}
			|	expr LE_OP expr
						{
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_le(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_BOOL_EXPR, smb, NULL, NULL, NULL, NULL);
						}
			|	expr GE_OP expr
						{
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_ge(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_BOOL_EXPR, smb, NULL, NULL, NULL, NULL);
						}
			|	expr NE_OP expr
						{
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_ne(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_BOOL_EXPR, smb, NULL, NULL, NULL, NULL);
						}
			;

r_val			:	r_val '+' term
						{
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_add(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_R_VAL, smb, NULL, NULL, NULL, NULL);
						
						}
			|	r_val '-' term
						{
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_substr(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_R_VAL, smb, NULL, NULL, NULL, NULL);
						}
			|	term
						{
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_R_VAL, smb, NULL, NULL, NULL, NULL);	
						}
			;
					
term			:	term '*' factor
						{
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_mult(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_TERM, smb, NULL, NULL, NULL, NULL);
							
						}
			|	term '/' factor
						{
							Symbol *temp = ST_pop(st);
							smb = ST_pop(st);
							smb = check_division(smb, temp);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_TERM, smb, NULL, NULL, NULL, NULL);
						}
			|	factor
						{
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_TERM, smb, NULL, NULL, NULL, NULL);
						}
			;
				
factor			:	'(' expr ')'
						{
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_FACTOR, smb, NULL, NULL, NULL, NULL);
						}
			|	'-' factor
						{
							smb = ST_pop(st);
							smb = check_uminus(smb);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_TERM, smb, NULL, NULL, NULL, NULL);
						}
			|	ID
						{

						}
			|	num
						{
							smb = ST_pop(st);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_FACTOR, smb, NULL, NULL, NULL, NULL);
						}
			;

num			:	INT_CONST
						{
							smb = SMB_init($1);
							smb->var_type = TYPE_INT;
							smb->value.i = atoi($1);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_NUM, smb, NULL, NULL, NULL, NULL);
						}
			|	FLOAT_CONST	
						{
							smb = SMB_init($1);
							smb->var_type = TYPE_FLOAT;
							smb->value.f = atof($1);
							ST_push(st, smb);
							$$ = ASTN_init(ASTN_NUM, smb, NULL, NULL, NULL, NULL);
						}
			;			
							
%%