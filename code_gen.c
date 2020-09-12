#include "structures.h"
#include "globals.h"
#include <string.h>
#include <stdio.h>

Hashtable *constants;
Hashtable *ids;
FILE *fp;

int get_label_id(){
	static int id = 0;
	return id++;
}

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
			case ASTN_ASSIGN_EXPR:
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(HT_add(ids, smb)){
					if(var_type == TYPE_INT){
						fprintf(fp, "$var_%s: .word 0\n", smb->name);
					} else if (var_type == TYPE_FLOAT){
						fprintf(fp, "$var_%s: .float 0.0\n", smb->name);
					}
				}
				break;
	
	
	
			case ASTN_FACTOR_ID:
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(HT_add(ids, smb)){
					if(var_type == TYPE_INT){
						fprintf(fp, "$var_%s: .word 0\n", smb->name);
					} else if (var_type == TYPE_FLOAT){
						fprintf(fp, "$var_%s: .float 0.0\n", smb->name);
					}
				}
				break;
	
	
	
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
		int lid, lid1;
		
		AST_Node *temp;
		switch (root->node_type){
			case ASTN_PROGRAM:
				fputs("#Declarations\n", fp);
				fputs(".data\n", fp);
				fputs("$err_zero: .asciiz \"Error: Tried to divide by zero.\"\n", fp);
				declare_constants(root);
				make_room();
				fputs("#Actual Instructions\n", fp);
				fputs(".text\n", fp);
				fputc('\n', fp);
				fputc('\n', fp);
				traverse(root->p_nodelist[0]);
				make_room();
				fputs("b halt\n", fp);
				fputc('\n', fp);
				fputs("#Print Zero-Division error\n", fp);
				fputs("err_zero:\n", fp);
				fputs("li $v0, 4\n", fp);
				fputs("la $a0, $err_zero\n", fp);
				fputs("syscall\n", fp);
				fputs("b halt\n", fp);
				make_room();
				fputs("#Halt\n", fp);
				fputs("halt:\n", fp);
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
				
			case ASTN_CLOSED_STMT_WHILE:
				traverse(root->p_nodelist[0]);
				break;
				
			case ASTN_OPEN_WHILE_STMT:
			case ASTN_CLOSED_WHILE_STMT:
				lid = get_label_id();
				lid1 = get_label_id();				
				fprintf(fp, "$l_%d:\n", lid);
				traverse(root->p_nodelist[0]);	
				fprintf(fp, "beqz $t5, $l_%d\n", lid1);
				traverse(root->p_nodelist[1]);					
				fprintf(fp, "b $l_%d\n", lid);			
				fprintf(fp, "$l_%d:\n", lid1);
				break;
				
				
			case ASTN_OPEN_STMT_IF:
			case ASTN_CLOSED_STMT_IF:
				traverse(root->p_nodelist[0]);
				break;
				

			case ASTN_OPEN_IF_STMT:
				traverse(root->p_nodelist[0]);
				lid = get_label_id();
				fprintf(fp, "beqz $t5, $l_%d\n", lid);
				traverse(root->p_nodelist[1]);								
				fprintf(fp, "$l_%d:\n", lid);
				break;
			
			case ASTN_OPEN_IF_ELSE_STMT:
			case ASTN_CLOSED_IF_STMT:
				traverse(root->p_nodelist[0]);
				lid = get_label_id();
				lid1 = get_label_id();
				fprintf(fp, "beqz $t5, $l_%d\n", lid);
				traverse(root->p_nodelist[1]);				
				fprintf(fp, "b $l_%d\n", lid1);			
				fprintf(fp, "$l_%d:\n", lid);
				traverse(root->p_nodelist[2]);								
				fprintf(fp, "$l_%d:\n", lid1);
				break;
				

			case ASTN_CLOSED_STMT_SIMPLE:
				traverse(root->p_nodelist[0]);
				break;
				
	
	
	
			case ASTN_SIMPLE_STMT_PRINTLN:
				traverse(root->p_nodelist[0]);
				break;
	
			
			
			case ASTN_SIMPLE_STMT_ASSIGN:
				traverse(root->p_nodelist[0]);
				break;


			case ASTN_ASSIGN_STMT:
				traverse(root->p_nodelist[0]);
				break;
				
				
			case ASTN_EXPR_ASSIGN_EXPR:
				traverse(root->p_nodelist[0]);
				break;
	
			case ASTN_ASSIGN_EXPR:
				fputs("#Assign\n", fp);
				traverse(root->p_nodelist[0]);
				smb = root->wrapped_symbol;
				smb1 = root->p_nodelist[0]->wrapped_symbol;
				var_type = smb->var_type;
				var_type1 = smb1->var_type;
				if(var_type == TYPE_INT){
					if(var_type1 == TYPE_INT){
						fprintf(fp, "sw $t6, $var_%s\n", smb->name);
					} else if (var_type1 == TYPE_FLOAT) {
						fputs("mfc1 $t6, $f6\n", fp);
						fputs("cvt.w.s $t6, $t6\n", fp);
						fprintf(fp, "sw $t6, $var_%s\n", smb->name);
					}
				} else if (var_type == TYPE_FLOAT){
					if(var_type1 == TYPE_INT){
						fputs("mtc1 $t6, $f6\n", fp);
						fputs("cvt.s.w $f6, $f6\n", fp);
						fprintf(fp, "s.s $f6, $var_%s\n", smb->name);
					} else if(var_type1 == TYPE_FLOAT){
						fprintf(fp, "s.s $f6, $var_%s\n", smb->name);					
					}
				}
				make_room();
				break;

			case ASTN_PRINTLN_STMT:
				fputs("#Print\n", fp);
				traverse(root->p_nodelist[0]);
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(var_type == TYPE_INT){
					fputs("li $v0, 1\n", fp);
					fputs("move $a0, $t6", fp);
				} else if (var_type == TYPE_FLOAT){
					fputs("li $v0, 2\n", fp);
					fputs("mov.s $f12, $f6", fp);
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
				


			case ASTN_BOOL_EXPR_EQ:
				smb = root->wrapped_symbol;
				smb1 = root->p_nodelist[0]->wrapped_symbol;
				smb2 = root->p_nodelist[1]->wrapped_symbol;
				var_type = smb->var_type;
				var_type1 = smb1->var_type;
				var_type2 = smb2->var_type;
				traverse(root->p_nodelist[0]);
				if(var_type1 == TYPE_INT){
					fputs("move $t5, $t6", fp);
				} else if (var_type1 == TYPE_FLOAT){
					fputs("mov.s $f5, $f6", fp);
				}
				fputc('\n', fp);
				traverse(root->p_nodelist[1]);
				fputc('\n', fp);
				if(var_type1 == TYPE_INT){
					if(var_type2 == TYPE_INT){
						fputs("seq $t5, $t5, $t6", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("mtc1 $t5, $f5\n", fp);
						fputs("cvt.s.w $f5, $f5\n", fp);
						fputs("c.eq.s $f5, $f6\n", fp);
						fputs("li $t5, 1\n", fp);
						fputs("movf $t5, $zero\n", fp);
					}
				} else if(var_type1 == TYPE_FLOAT){
					if(var_type2 == TYPE_INT){
						fputs("mtc1 $t6, $f6\n", fp);
						fputs("cvt.s.w $f6, $f6\n", fp);
						fputs("c.eq.s $f5, $f6\n", fp);
						fputs("li $t5, 1\n", fp);
						fputs("movf $t5, $zero\n", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("c.eq.s $f5, $f6\n", fp);
						fputs("li $t5, 1\n", fp);
						fputs("movf $t5, $zero\n", fp);
					}
				}
				fputc('\n', fp);			
				break;
	

			case ASTN_BOOL_EXPR_LT:
				smb = root->wrapped_symbol;
				smb1 = root->p_nodelist[0]->wrapped_symbol;
				smb2 = root->p_nodelist[1]->wrapped_symbol;
				var_type = smb->var_type;
				var_type1 = smb1->var_type;
				var_type2 = smb2->var_type;
				traverse(root->p_nodelist[0]);
				if(var_type1 == TYPE_INT){
					fputs("move $t5, $t6", fp);
				} else if (var_type1 == TYPE_FLOAT){
					fputs("mov.s $f5, $f6", fp);
				}
				fputc('\n', fp);
				traverse(root->p_nodelist[1]);
				fputc('\n', fp);
				if(var_type1 == TYPE_INT){
					if(var_type2 == TYPE_INT){
						fputs("slt $t5, $t5, $t6", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("mtc1 $t5, $f5\n", fp);
						fputs("cvt.s.w $f5, $f5\n", fp);
						fputs("c.lt.s $f5, $f6\n", fp);
						fputs("li $t5, 1\n", fp);
						fputs("movf $t5, $zero\n", fp);
					}
				} else if(var_type1 == TYPE_FLOAT){
					if(var_type2 == TYPE_INT){
						fputs("mtc1 $t6, $f6\n", fp);
						fputs("cvt.s.w $f6, $f6\n", fp);
						fputs("c.lt.s $f5, $f6\n", fp);
						fputs("li $t5, 1\n", fp);
						fputs("movf $t5, $zero\n", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("c.lt.s $f5, $f6\n", fp);
						fputs("li $t5, 1\n", fp);
						fputs("movf $t5, $zero\n", fp);
					}
				}
				fputc('\n', fp);			
				break;

			case ASTN_BOOL_EXPR_LE:
				smb = root->wrapped_symbol;
				smb1 = root->p_nodelist[0]->wrapped_symbol;
				smb2 = root->p_nodelist[1]->wrapped_symbol;
				var_type = smb->var_type;
				var_type1 = smb1->var_type;
				var_type2 = smb2->var_type;
				traverse(root->p_nodelist[0]);
				if(var_type1 == TYPE_INT){
					fputs("move $t5, $t6", fp);
				} else if (var_type1 == TYPE_FLOAT){
					fputs("mov.s $f5, $f6", fp);
				}
				fputc('\n', fp);
				traverse(root->p_nodelist[1]);
				fputc('\n', fp);
				if(var_type1 == TYPE_INT){
					if(var_type2 == TYPE_INT){
						fputs("sle $t5, $t5, $t6", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("mtc1 $t5, $f5\n", fp);
						fputs("cvt.s.w $f5, $f5\n", fp);
						fputs("c.le.s $f5, $f6\n", fp);
						fputs("li $t5, 1\n", fp);
						fputs("movf $t5, $zero\n", fp);
					}
				} else if(var_type1 == TYPE_FLOAT){
					if(var_type2 == TYPE_INT){
						fputs("mtc1 $t6, $f6\n", fp);
						fputs("cvt.s.w $f6, $f6\n", fp);
						fputs("c.le.s $f5, $f6\n", fp);
						fputs("li $t5, 1\n", fp);
						fputs("movf $t5, $zero\n", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("c.le.s $f5, $f6\n", fp);
						fputs("li $t5, 1\n", fp);
						fputs("movf $t5, $zero\n", fp);
					}
				}
				fputc('\n', fp);			
				break;
	
		
			case ASTN_BOOL_EXPR_GT:
				smb = root->wrapped_symbol;
				smb1 = root->p_nodelist[0]->wrapped_symbol;
				smb2 = root->p_nodelist[1]->wrapped_symbol;
				var_type = smb->var_type;
				var_type1 = smb1->var_type;
				var_type2 = smb2->var_type;
				traverse(root->p_nodelist[0]);
				if(var_type1 == TYPE_INT){
					fputs("move $t5, $t6", fp);
				} else if (var_type1 == TYPE_FLOAT){
					fputs("mov.s $f5, $f6", fp);
				}
				fputc('\n', fp);
				traverse(root->p_nodelist[1]);
				fputc('\n', fp);
				if(var_type1 == TYPE_INT){
					if(var_type2 == TYPE_INT){
						fputs("sgt $t5, $t5, $t6", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("mtc1 $t5, $f5\n", fp);
						fputs("cvt.s.w $f5, $f5\n", fp);
						fputs("c.le.s $f5, $f6\n", fp);
						fputs("li $t5, 0\n", fp);
						fputs("li $t0, 1\n", fp);
						fputs("movf $t5, $t0\n", fp);
					}
				} else if(var_type1 == TYPE_FLOAT){
					if(var_type2 == TYPE_INT){
						fputs("mtc1 $t6, $f6\n", fp);
						fputs("cvt.s.w $f6, $f6\n", fp);
						fputs("c.le.s $f5, $f6\n", fp);
						fputs("li $t5, 0\n", fp);
						fputs("li $t0, 1\n", fp);
						fputs("movf $t5, $t0\n", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("c.le.s $f5, $f6\n", fp);
						fputs("li $t5, 0\n", fp);
						fputs("li $t0, 1\n", fp);
					}
				}
				fputc('\n', fp);			
				break;

			case ASTN_EXPR_R_VAL:
				traverse(root->p_nodelist[0]);
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(var_type == TYPE_INT){
					fputs("move $t6, $t7\n", fp);
				} else if (var_type == TYPE_FLOAT){
					fputs("mov.s $f6, $f7\n", fp);
				}
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
					fputs("move $t7, $t7", fp);
				} else if (var_type1 == TYPE_FLOAT){
					fputs("mov.s $f7, $f7", fp);
				}
				fputc('\n', fp);
				traverse(root->p_nodelist[1]);
				fputc('\n', fp);
				if(var_type1 == TYPE_INT){
					if(var_type2 == TYPE_INT){
						fputs("sub $t7, $t7, $t8", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("mtc1 $t7, $f7\n", fp);
						fputs("cvt.s.w $f7, $f7\n", fp);
						fputs("sub.s $f7, $f7, $f8\n", fp);
					}
				} else if(var_type1 == TYPE_FLOAT){
					if(var_type2 == TYPE_INT){
						fputs("mtc1 $t8, $f8\n", fp);
						fputs("cvt.s.w $f8, $f8\n", fp);
						fputs("sub.s $f7, $f7, $f8\n", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("sub.s $f7, $f7, $f8\n", fp);
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
					fputs("move $t7, $t7", fp);
				} else if (var_type1 == TYPE_FLOAT){
					fputs("mov.s $f7, $f7", fp);
				}
				fputc('\n', fp);
				traverse(root->p_nodelist[1]);
				fputc('\n', fp);
				if(var_type1 == TYPE_INT){
					if(var_type2 == TYPE_INT){
						fputs("add $t7, $t7, $t8", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("mtc1 $t7, $f7\n", fp);
						fputs("cvt.s.w $f7, $f7\n", fp);
						fputs("add.s $f7, $f7, $f8\n", fp);
					}
				} else if(var_type1 == TYPE_FLOAT){
					if(var_type2 == TYPE_INT){
						fputs("mtc1 $t8, $f8\n", fp);
						fputs("cvt.s.w $f8, $f8\n", fp);
						fputs("add.s $f7, $f7, $f8\n", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("add.s $f7, $f7, $f8\n", fp);
					}
				}
				fputc('\n', fp);
				break;
				
				
	
			case ASTN_R_VAL_TERM:
				traverse(root->p_nodelist[0]);
	
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(var_type == TYPE_INT){
					fputs("move $t7, $t8", fp);
				} else if (var_type == TYPE_FLOAT){
					fputs("mov.s $f7, $f8", fp);
				}
				fputc('\n', fp);
	
				break;
			
	
				case ASTN_TERM_MULT:
				smb = root->wrapped_symbol;
				smb1 = root->p_nodelist[0]->wrapped_symbol;
				smb2 = root->p_nodelist[1]->wrapped_symbol;
				var_type = smb->var_type;
				var_type1 = smb1->var_type;
				var_type2 = smb2->var_type;
				traverse(root->p_nodelist[0]);
				if(var_type1 == TYPE_INT){
					fputs("move $t8, $t8", fp);
				} else if (var_type1 == TYPE_FLOAT){
					fputs("mov.s $f8, $f8", fp);
				}
				fputc('\n', fp);
				traverse(root->p_nodelist[1]);
				fputc('\n', fp);
				if(var_type1 == TYPE_INT){
					if(var_type2 == TYPE_INT){
						fputs("mul $t8, $t8, $t9", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("mtc1 $t8, $f8\n", fp);
						fputs("cvt.s.w $f8, $f8\n", fp);
						fputs("mul.s $f8, $f8, $f9\n", fp);
					}
				} else if(var_type1 == TYPE_FLOAT){
					if(var_type2 == TYPE_INT){
						fputs("mtc1 $t9, $f9\n", fp);
						fputs("cvt.s.w $f9, $f9\n", fp);
						fputs("mul.s $f8, $f8, $f9\n", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("mul.s $f8, $f8, $f9\n", fp);
					}
				}
				fputc('\n', fp);
				break;
	
	
	
				case ASTN_TERM_DIVISION:
				smb = root->wrapped_symbol;
				smb1 = root->p_nodelist[0]->wrapped_symbol;
				smb2 = root->p_nodelist[1]->wrapped_symbol;
				var_type = smb->var_type;
				var_type1 = smb1->var_type;
				var_type2 = smb2->var_type;
				traverse(root->p_nodelist[0]);
				if(var_type1 == TYPE_INT){
					fputs("move $t8, $t8", fp);
				} else if (var_type1 == TYPE_FLOAT){
					fputs("mov.s $f8, $f8", fp);
				}
				fputc('\n', fp);
				traverse(root->p_nodelist[1]);
				if(var_type2 == TYPE_INT){
					fputs("beqz $t9, err_zero\n", fp);
				} else if (var_type2 == TYPE_FLOAT){
					fputs("mtc1 $zero, $f0\n", fp);
					fputs("c.eq.s $f9, $f0\n", fp);
					fputs("bc1t err_zero\n", fp);
				}
				fputc('\n', fp);
				if(var_type1 == TYPE_INT){
					if(var_type2 == TYPE_INT){
						fputs("div $t8, $t8, $t9", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("mtc1 $t8, $f8\n", fp);
						fputs("cvt.s.w $f8, $f8\n", fp);
						fputs("div.s $f8, $f8, $f9\n", fp);
					}
				} else if(var_type1 == TYPE_FLOAT){
					if(var_type2 == TYPE_INT){
						fputs("mtc1 $t9, $f9\n", fp);
						fputs("cvt.s.w $f9, $f9\n", fp);
						fputs("div.s $f8, $f8, $f9\n", fp);
					} else if(var_type2 == TYPE_FLOAT){
						fputs("div.s $f8, $f8, $f9\n", fp);
					}
				}
				fputc('\n', fp);
				break;
			
	
			case ASTN_TERM_FACTOR:
				traverse(root->p_nodelist[0]);
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(var_type == TYPE_INT){
					fputs("move $t8, $t9", fp);
				} else if (var_type == TYPE_FLOAT){
					fputs("mov.s $f8, $f9", fp);
				}
				fputc('\n', fp);
	
				break;


			case ASTN_FACTOR_PARENTH:
				traverse(root->p_nodelist[0]);
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(var_type == TYPE_INT){
					fputs("move $t9, $t6\n", fp);
				} else if (var_type == TYPE_FLOAT){
					fputs("mov.s $f9, $f6\n", fp);
				}
				fputc('\n', fp);
				break;	


			case ASTN_FACTOR_UMINUS:
				traverse(root->p_nodelist[0]);
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(var_type == TYPE_INT){
					fputs("neg $t9, $t9\n", fp);
				} else if (var_type == TYPE_FLOAT){
					fputs("neg.s $f9, $f9\n", fp);
				}
				fputc('\n', fp);
				break;				
			
			
			case ASTN_FACTOR_ID:
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(var_type == TYPE_INT){
					fprintf(fp, "lw $t9, $var_%s", smb->name);
				} else if (var_type == TYPE_FLOAT){
					fprintf(fp, "l.s $f9, $var_%s", smb->name);
				}
				fputc('\n', fp);
				break;
	
			case ASTN_FACTOR_NUM:
				smb = root->wrapped_symbol;
				var_type = smb->var_type;
				if(var_type == TYPE_INT){
					fputs("lw $t9, ", fp);
				} else if (var_type == TYPE_FLOAT){
					fputs("l.s $f9, ", fp);
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
	ids = HT_init();
	
	if(fp){
		traverse(root);
		fclose(fp);
	} else {
		fprintf(stderr, "Error: Couldn't create output file.\n");
	}
}
