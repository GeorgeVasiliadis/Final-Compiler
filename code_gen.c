#include "structures.h"
#include "globals.h"
#include <string.h>
#include <stdio.h>

FILE *fp;
Hashtable *constants;
int var_type;
static Symbol *smb;

void make_room(void){
	fputc('\n', fp);
	fputc('\n', fp);
	fputc('\n', fp);
}

void declare_float_constants(AST_Node *root){
	if(root){
		switch(root->node_type){
			case ASTN_NUM:
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(HT_add(constants, smb)){
					if(var_type == TYPE_INT){
						fprintf(fp, "$t_%s: .word %d\n", smb->name, smb->value.i);
					} else if (var_type == TYPE_FLOAT){
						fprintf(fp, "$t_%s: .float %f\n", smb->name, smb->value.f);
					}
				}
				break;
		}
		for(int i=0; i<4; i++){
			declare_float_constants(root->p_nodelist[i]);
		}
	}
}

void traverse(AST_Node *root){
	if(root){
	AST_Node *temp;
		switch (root->node_type){
			case ASTN_PROGRAM:
				printf("Program: %s\n", root->wrapped_symbol->name);
				
				fputs("#Declarations\n", fp);
				fputs(".data\n", fp);
				declare_float_constants(root);

				make_room();
				fputs("#Actual Instructions\n", fp);
				fputs(".text\n", fp);
				
				traverse(root->p_nodelist[0]);
				
				fputs("#Exit\n", fp);
				fputs("li $v0, 10\n", fp);
				fputs("syscall", fp);
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
				fputs("#Declaration\n", fp);
				var_type = root->wrapped_symbol->var_type;
				make_room();
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
			case ASTN_SIMPLE_STMT_PRINTLN:
				traverse(root->p_nodelist[0]);
				break;

			case ASTN_STMT_PRINTLN:
				fputs("#Print\n", fp);

				traverse(root->p_nodelist[0]);

				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(var_type == TYPE_INT){
					fputs("li $v0, 1\n", fp);
					fputs("move $a0, $t0", fp);
				} else if (var_type == TYPE_FLOAT){
					fputs("li $v0, 2\n", fp);
					fputs("mov.s $f12, $f0", fp);
				}
				fputc('\n', fp);
				fputs("syscall\n", fp);
				make_room();

				
				fputs("#Print newline\n", fp);
				fputs("li $v0, 11\n", fp);
				fputs("li $a0, 10\n", fp);
				fputs("syscall\n", fp);
				make_room();
				break;
				
			case ASTN_EXPR_R_VAL:
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(var_type == TYPE_INT){
					// no need --->  fputs("move $t0, $t0", fp);
				} else if (var_type == TYPE_FLOAT){
					// no need ---> fputs("mov.s %f0, $f0", fp);
				}
				traverse(root->p_nodelist[0]);
				//fputc('\n', fp);
				break;
				
				
			case ASTN_R_VAL_TERM:
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(var_type == TYPE_INT){
					// no need --->  fputs("move $t0, $t0", fp);
				} else if (var_type == TYPE_FLOAT){
					// no need ---> fputs("mov.s %f0, $f0", fp);
				}
				traverse(root->p_nodelist[0]);
				//fputc('\n', fp);
				break;
			
			
			case ASTN_TERM_FACTOR:
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(var_type == TYPE_INT){
					// no need --->  fputs("move $t0, $t0", fp);
				} else if (var_type == TYPE_FLOAT){
					// no need ---> fputs("mov.s %f0, $f0", fp);
				}
				traverse(root->p_nodelist[0]);
				//fputc('\n', fp);
				break;
				
				
			case ASTN_FACTOR_NUM:
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(var_type == TYPE_INT){
					fputs("lw $t0, ", fp);
				} else if (var_type == TYPE_FLOAT){
					fputs("l.s $f0, ", fp);
				}
				traverse(root->p_nodelist[0]);
				fputc('\n', fp);
				break;
				

			case ASTN_NUM:
					smb = root->wrapped_symbol;
					fprintf(fp, "$t_%s", smb->name);
				break;
		}
	}

}

void generate_code(AST_Node *root){
	fp = fopen("out.final.asm", "w");
	constants = HT_init();
	
	if(fp){
		traverse(root);
		fclose(fp);
	} else {
		fprintf(stderr, "Error: Couldn't create output file.\n");
	}
}
