#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "globals.h"
#include "structures.h"


extern Hashtable *ht;
extern Stack *st;
extern AST_Node *root;


void yyerror(char const *err){
	fprintf(stderr, "MIPS Error >> %s\nYacc >> Rejected", err);
	exit(1);
}
 
void traverse(AST_Node *root){
	if(root){
	printf("\n<------>\n");
	int var_type;
	Symbol *smb;
	AST_Node *temp;
		switch (root->node_type){
			case ASTN_PROGRAM:
				printf("Program: %s\n", root->wrapped_symbol->name);
				traverse(root->p_nodelist[0]);
				break;


			case ASTN_STMT_LIST:
				traverse(root->p_nodelist[0]);
				traverse(root->p_nodelist[1]);
				break;


			case ASTN_DECLARATION:
				printf("Declaration:\n");
				break;


			case ASTN_ASSIGN_EXPR:
				printf("Assign:\n");
				break;


			case ASTN_IF_STMT:
				printf("If:\n");
				if(root->wrapped_symbol->value.i){
					traverse(root->p_nodelist[0]);
				} else {
					traverse(root->p_nodelist[1]);
				}
				break;


			case ASTN_PRINTLN:
				printf("Print Line:\n");
				break;
		}
	}

}

int main(){
	ht = HT_init();
	st = ST_init();
	
	if(!yyparse()){
		printf("Yacc >> Accepted\n");
		traverse(root);
	}
	printf("\n");
	return 0;
}