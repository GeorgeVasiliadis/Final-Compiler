#include "structures.h"
#include "globals.h"
#include <stdio.h>

FILE *fp;


void traverse(AST_Node *root){
	if(root){
	printf("<------>\n");
	int var_type;
	Symbol *smb;
	AST_Node *temp;
		switch (root->node_type){
			case ASTN_PROGRAM:
				printf("Program: %s\n", root->wrapped_symbol->name);
				fputs("#Actual Instructions\n", fp);
				fputs(".text\n", fp);
				traverse(root->p_nodelist[0]);
				fputs("#Exit\n", fp);
				fputs("li $v0, 10\n", fp);
				break;


			case ASTN_STMT_LIST:
				printf("Statement List\n");
				traverse(root->p_nodelist[0]);
				traverse(root->p_nodelist[1]);
				break;
				
			case ASTN_STMT:
				traverse(root->p_nodelist[0]);
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
					printf("Chose \"IF\" side\n");
					traverse(root->p_nodelist[0]);
				} else {
					printf("Chose \"NOT-IF\" side\n");
					traverse(root->p_nodelist[1]);
				}
				break;


			case ASTN_PRINTLN:
				fputs("#Print\n", fp);
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
					fputs("li $v0, 1\n", fp);				
				if(var_type == TYPE_INT){
					fputs("la $a0, ", fp);
				} else if (var_type == TYPE_FLOAT){
				}
printf("\n1\n");
				traverse(root->p_nodelist[0]);
				fputs("\n", fp);
				fputs("syscall\n", fp);
				break;
				
			case ASTN_EXPR:
				traverse(root->p_nodelist[0]);
				break;
				
				
			case ASTN_R_VAL:
				traverse(root->p_nodelist[0]);
				break;
			
			
			case ASTN_TERM:
				traverse(root->p_nodelist[0]);
				break;
				
				
			case ASTN_FACTOR:
				traverse(root->p_nodelist[0]);
				break;
				

			case ASTN_NUM:
					smb = root->wrapped_symbol;
					var_type = smb->var_type;
					if(var_type == TYPE_INT){
						fprintf(fp, "%d", smb->value.i);
					}
				break;
		}
	}

}

void generate_code(AST_Node *root){
	fp = fopen("a.final", "w");
	if(fp){
		traverse(root);
		fclose(fp);
	} else {
		fprintf(stderr, "Error: Couldn't create output file.\n");
	}
}
