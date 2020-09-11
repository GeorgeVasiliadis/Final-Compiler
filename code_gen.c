#include "structures.h"
#include "globals.h"
#include <string.h>
#include <stdio.h>

Hashtable *constants;
FILE *fp;


void make_room(void){
	fputc('\n', fp);
	fputc('\n', fp);
	fputc('\n', fp);
}

void declare_constants(AST_Node *root){
	if(root){
	Symbol *smb;
	int var_type;
		switch(root->node_type){
			case ASTN_NUM_INT:
			case ASTN_NUM_FLOAT:
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
			declare_constants(root->p_nodelist[i]);
		}
	}
}

void traverse(AST_Node *root){
	if(root){
	Symbol *smb;
	Symbol *smb1;
	Symbol *smb2;
	int var_type, var_type1, var_type2;
	
	AST_Node *temp;
		switch (root->node_type){
			case ASTN_PROGRAM:
				fputs("#Declarations\n", fp);
				fputs(".data\n", fp);
				declare_constants(root);
				make_room();
				fputs("#Actual Instructions\n", fp);
				fputs(".text\n", fp);
				fputc('\n', fp);
				fputc('\n', fp);
				traverse(root->p_nodelist[0]);
				fputs("#Exit\n", fp);
				fputs("li $v0, 10\n", fp);
				fputs("syscall", fp);
				break;
				
				

			case ASTN_COMP_STMT:
				traverse(root->p_nodelist[0]);
				break;
				
				

			case ASTN_STMT_LIST:
				traverse(root->p_nodelist[0]);
				traverse(root->p_nodelist[1]);
				break;
				


			case ASTN_STMT_OPEN:
			case ASTN_STMT_CLOSED:
				traverse(root->p_nodelist[0]);
				break;
				
				
			case ASTN_CLOSED_STMT_SIMPLE:
				traverse(root->p_nodelist[0]);
				break;
				



			case ASTN_SIMPLE_STMT_PRINTLN:
				traverse(root->p_nodelist[0]);
				break;



			case ASTN_PRINTLN_STMT:
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
				traverse(root->p_nodelist[0]);
				break;


			case ASTN_R_VAL_SUBSTR:
				smb = root->wrapped_symbol;
				smb1 = root->p_nodelist[0]->wrapped_symbol;
				smb2 = root->p_nodelist[1]->wrapped_symbol;
				var_type = smb->var_type;
				var_type1 = smb1->var_type;
				var_type2 = smb2->var_type;
				traverse(root->p_nodelist[0]);
				if(var_type1 == TYPE_INT){
					fputs("move $t1, $t0", fp);
				} else if (var_type1 == TYPE_FLOAT){
					fputs("mov.s $f1, $f0", fp);
				}
				fputc('\n', fp);
				traverse(root->p_nodelist[1]);
				if(var_type2 == TYPE_INT){
					fputs("move $t0, $t0", fp);
				} else if (var_type2 == TYPE_FLOAT){
					fputs("mov.s $f0, $f0\n", fp);
				}
				fputc('\n', fp);
				if(var_type1 == TYPE_INT){
					if(var_type2 == TYPE_INT){
						fputs("sub $t0, $t1, $t0", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("mtc1 $t1, $f1\n", fp);
						fputs("cvt.s.w $f1, $f1\n", fp);
						fputs("sub.s $f0, $f1, $f0\n", fp);
					}
				} else if(var_type1 == TYPE_FLOAT){
					if(var_type2 == TYPE_INT){
						fputs("mtc1 $t0, $f0\n", fp);
						fputs("cvt.s.w $f0, $f0\n", fp);
						fputs("sub.s $f0, $f1, $f0\n", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("sub.s $f0, $f1, $f0\n", fp);
					}
				}
				fputc('\n', fp);
				break;



			case ASTN_R_VAL_ADD:
				smb = root->wrapped_symbol;
				smb1 = root->p_nodelist[0]->wrapped_symbol;
				smb2 = root->p_nodelist[1]->wrapped_symbol;
				var_type = smb->var_type;
				var_type1 = smb1->var_type;
				var_type2 = smb2->var_type;
				traverse(root->p_nodelist[0]);
				if(var_type1 == TYPE_INT){
					fputs("move $t1, $t0", fp);
				} else if (var_type1 == TYPE_FLOAT){
					fputs("mov.s $f1, $f0", fp);
				}
				fputc('\n', fp);
				traverse(root->p_nodelist[1]);
/*
				if(var_type2 == TYPE_INT){
					fputs("move $t0, $t0", fp);
				} else if (var_type2 == TYPE_FLOAT){
					fputs("mov.s $f0, $f0\n", fp);
				}
*/
				fputc('\n', fp);
				if(var_type1 == TYPE_INT){
					if(var_type2 == TYPE_INT){
						fputs("add $t0, $t1, $t0", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("mtc1 $t1, $f1\n", fp);
						fputs("cvt.s.w $f1, $f1\n", fp);
						fputs("add.s $f0, $f1, $f0\n", fp);
					}
				} else if(var_type1 == TYPE_FLOAT){
					if(var_type2 == TYPE_INT){
						fputs("mtc1 $t0, $f0\n", fp);
						fputs("cvt.s.w $f0, $f0\n", fp);
						fputs("add.s $f0, $f1, $f0\n", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("add.s $f0, $f1, $f0\n", fp);
					}
				}
				fputc('\n', fp);
				break;
				
				

			case ASTN_R_VAL_TERM:
				traverse(root->p_nodelist[0]);
/*	
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(var_type == TYPE_INT){
					fputs("move $t0, $t0", fp);
				} else if (var_type == TYPE_FLOAT){
					fputs("mov.s $f0, $f0", fp);
				}
				fputc('\n', fp);
*/
				break;
			
			

			case ASTN_TERM_FACTOR:
				traverse(root->p_nodelist[0]);
/*
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(var_type == TYPE_INT){
					fputs("move $t0, $t0", fp);
				} else if (var_type == TYPE_FLOAT){
					fputs("mov.s $f0, $f0", fp);
				}
				fputc('\n', fp);
*/
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
				

			case ASTN_NUM_INT:
			case ASTN_NUM_FLOAT:
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
