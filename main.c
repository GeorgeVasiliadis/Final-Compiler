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
	printf("MIPS Error >> %s\nYacc >> Rejected", err);
}

void traverse(AST_Node *root){
	if(root){
	Symbol *smb;
	AST_Node *temp;
	int var_type;
	//---
	//printf("START___%d___START\n", root->node_type);
	//---
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
				var_type = root->wrapped_symbol->var_type;
				temp = root->p_nodelist[0];
				while(temp){
					temp->wrapped_symbol->var_type = var_type;
					if(var_type == TYPE_INT){
						temp->wrapped_symbol->value.i = 0;
					} else if (var_type == TYPE_FLOAT){
						temp->wrapped_symbol->value.f = 0;
					}
					temp = temp->p_nodelist[0];
				}
				break;
			case ASTN_IF_STMT:
				if(root->wrapped_symbol->value.i){
					traverse(root->p_nodelist[0]);
				} else {
					traverse(root->p_nodelist[1]);
				}
				break;
			case ASTN_PRINTLN:
				smb = root->wrapped_symbol; 
				if(smb->var_type == TYPE_INT){
					printf("%i\n", smb->value.i);
				}else if (smb->var_type == TYPE_FLOAT){
					printf("%g\n", smb->value.f);
				}
				break;
		}
	//---
	//printf("END___%d___END\n", root->node_type);
	//---
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