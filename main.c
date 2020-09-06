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
	//---
	//printf("START___%d___START\n", root->node_type);
	//---
		switch (root->node_type){
			case ASTN_PROGRAM:
				printf("Program: %s\n", root->wrapped_symbol->name);
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
	
		
		for(int i=0; i<4; i++){
			traverse(root->p_nodelist[i]);
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