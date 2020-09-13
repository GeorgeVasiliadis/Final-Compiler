#include "structures.h"
#include "globals.h"
#include "logger.h"

extern Hashtable *ht;

Symbol *check_add(Symbol *op1, Symbol *op2){
	Symbol *p = SMB_init("");

	if(op1->var_type == TYPE_INT){
		if(op2->var_type == TYPE_INT){
			p->var_type = TYPE_INT;
			p->value.i = op1->value.i + op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->var_type = TYPE_FLOAT;
			p->value.f = op1->value.i + op2->value.f;	
		}
	} else if (op1->var_type == TYPE_FLOAT){
		if(op2->var_type == TYPE_INT){
			p->var_type = TYPE_FLOAT;
			p->value.f = op1->value.f + op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->var_type = TYPE_FLOAT;
			p->value.f = op1->value.f + op2->value.f;
		}
	}
	return(p);
}

Symbol *check_substr(Symbol *op1, Symbol *op2){
	Symbol *p = SMB_init("");

	if(op1->var_type == TYPE_INT){
		if(op2->var_type == TYPE_INT){
			p->var_type = TYPE_INT;
			p->value.i = op1->value.i - op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->var_type = TYPE_FLOAT;
			p->value.f = op1->value.i - op2->value.f;	
		}
	} else if (op1->var_type == TYPE_FLOAT){
		if(op2->var_type == TYPE_INT){
			p->var_type = TYPE_FLOAT;
			p->value.f = op1->value.f - op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->var_type = TYPE_FLOAT;
			p->value.f = op1->value.f - op2->value.f;
		}
	}
	return(p);
}

Symbol *check_uminus(Symbol *op1){
	Symbol *p = SMB_init("");

	if(op1->var_type == TYPE_INT){
		p->var_type = TYPE_INT;
		p->value.i = -1 * op1->value.i;
	} else if (op1->var_type == TYPE_FLOAT){
		p->var_type = TYPE_FLOAT;
		p->value.f = -1 * op1->value.f;
	}
	return(p);
}


Symbol *check_division(Symbol *op1, Symbol *op2){
	Symbol *p = SMB_init("");

	if(op2->var_type == TYPE_INT){
		if(op2->value.i == 0){
			semant_err("Zero-Division.");
		}
	} else if (op2->var_type == TYPE_FLOAT){
		if(op2->value.f == 0){
			semant_err("Zero-Division.");
		}
	}

	if(op1->var_type == TYPE_INT){
		if(op2->var_type == TYPE_INT){
			p->var_type = TYPE_INT;
			p->value.i = op1->value.i / op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->var_type = TYPE_FLOAT;
			p->value.f = op1->value.i / op2->value.f;	
		}
	} else if (op1->var_type == TYPE_FLOAT){
		if(op2->var_type == TYPE_INT){
			p->var_type = TYPE_FLOAT;
			p->value.f = op1->value.f / op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->var_type = TYPE_FLOAT;
			p->value.f = op1->value.f - op2->value.f;
		}
	}
	return(p);
}

Symbol *check_mult(Symbol *op1, Symbol *op2){
	Symbol *p = SMB_init("");

	if(op1->var_type == TYPE_INT){
		if(op2->var_type == TYPE_INT){
			p->var_type = TYPE_INT;
			p->value.i = op1->value.i * op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->var_type = TYPE_FLOAT;
			p->value.f = op1->value.i * op2->value.f;	
		}
	} else if (op1->var_type == TYPE_FLOAT){
		if(op2->var_type == TYPE_INT){
			p->var_type = TYPE_FLOAT;
			p->value.f = op1->value.f * op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->var_type = TYPE_FLOAT;
			p->value.f = op1->value.f * op2->value.f;
		}
	}
	return(p);
}

Symbol *check_eq(Symbol *op1, Symbol *op2){
	Symbol *p = SMB_init("");
	p->var_type = TYPE_INT;
	
	if(op1->var_type == TYPE_INT){
		if(op2->var_type == TYPE_INT){		
			p->value.i = op1->value.i == op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->value.i = op1->value.i == op2->value.f;	
		}
	} else if (op1->var_type == TYPE_FLOAT){
		if(op2->var_type == TYPE_INT){
			p->value.i = op1->value.f == op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->value.i = op1->value.f == op2->value.f;
		}
	}
	return(p);
}

Symbol *check_lt(Symbol *op1, Symbol *op2){
	Symbol *p = SMB_init("");
	p->var_type = TYPE_INT;
	
	if(op1->var_type == TYPE_INT){
		if(op2->var_type == TYPE_INT){		
			p->value.i = op1->value.i < op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->value.i = op1->value.i < op2->value.f;	
		}
	} else if (op1->var_type == TYPE_FLOAT){
		if(op2->var_type == TYPE_INT){
			p->value.i = op1->value.f < op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->value.i = op1->value.f < op2->value.f;
		}
	}
	return(p);
}

Symbol *check_gt(Symbol *op1, Symbol *op2){
	Symbol *p = SMB_init("");
	p->var_type = TYPE_INT;
	
	if(op1->var_type == TYPE_INT){
		if(op2->var_type == TYPE_INT){		
			p->value.i = op1->value.i > op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->value.i = op1->value.i > op2->value.f;	
		}
	} else if (op1->var_type == TYPE_FLOAT){
		if(op2->var_type == TYPE_INT){
			p->value.i = op1->value.f > op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->value.i = op1->value.f > op2->value.f;
		}
	}
	return(p);
}

Symbol *check_le(Symbol *op1, Symbol *op2){
	Symbol *p = SMB_init("");
	p->var_type = TYPE_INT;
	
	if(op1->var_type == TYPE_INT){
		if(op2->var_type == TYPE_INT){		
			p->value.i = op1->value.i <= op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->value.i = op1->value.i <= op2->value.f;	
		}
	} else if (op1->var_type == TYPE_FLOAT){
		if(op2->var_type == TYPE_INT){
			p->value.i = op1->value.f <= op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->value.i = op1->value.f <= op2->value.f;
		}
	}
	return(p);
}

Symbol *check_ge(Symbol *op1, Symbol *op2){
	Symbol *p = SMB_init("");
	p->var_type = TYPE_INT;
	
	if(op1->var_type == TYPE_INT){
		if(op2->var_type == TYPE_INT){		
			p->value.i = op1->value.i >= op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->value.i = op1->value.i >= op2->value.f;	
		}
	} else if (op1->var_type == TYPE_FLOAT){
		if(op2->var_type == TYPE_INT){
			p->value.i = op1->value.f >= op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->value.i = op1->value.f >= op2->value.f;
		}
	}
	return(p);
}

Symbol *check_ne(Symbol *op1, Symbol *op2){
	Symbol *p = SMB_init("");
	p->var_type = TYPE_INT;
	
	if(op1->var_type == TYPE_INT){
		if(op2->var_type == TYPE_INT){		
			p->value.i = op1->value.i != op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->value.i = op1->value.i != op2->value.f;	
		}
	} else if (op1->var_type == TYPE_FLOAT){
		if(op2->var_type == TYPE_INT){
			p->value.i = op1->value.f != op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->value.i = op1->value.f != op2->value.f;
		}
	}
	return(p);
}

Symbol *check_assign(Symbol *op1, Symbol *op2){
	
	op1 = HT_get(ht,op1->name);
	if(!op1){
		semant_err("Tried to use ID before declaration.");
	}
	
	Symbol *p = SMB_init(op1->name);
	
	if(op1->var_type == TYPE_INT){
		p->var_type = TYPE_INT;	
		if(op2->var_type == TYPE_INT){
			op1->value.i = op2->value.i;
			p->value.i = op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			op1->value.i = (int) op2->value.f;
			p->value.i = (int) op2->value.f;	
		}
	} else if (op1->var_type == TYPE_FLOAT){
		p->var_type = TYPE_FLOAT;
		if(op2->var_type == TYPE_INT){
			op1->value.f = op2->value.i;
			p->value.f = op2->value.i;
		} else if (op2->var_type == TYPE_FLOAT) {
			op1->value.f = op2->value.f;
			p->value.f = op2->value.f;
		}
	}
	return (p);
}

void check_declaration(Symbol *dummy, AST_Node *node){
	int var_type = dummy->var_type;
	Symbol *id;
	while(node){
		if(node->wrapped_symbol){
			id = HT_add(ht, node->wrapped_symbol);
			if(!id){
				semant_err("Tried to declare ID multiple times.");
			}
			id->var_type = var_type;
			if(var_type == TYPE_INT){
				id->value.i = 0;
			} else if (var_type == TYPE_FLOAT){
				id->value.f = 0;
			}
		}
		node = node->p_nodelist[0];
	}
}


Symbol *check_id_reference(Symbol *op1){
	Symbol *p = HT_get(ht, op1->name);
	if(!p){
		semant_err("Tried to use ID before declaration.");
	}
	return (p);
}

void check_println(Symbol *op1){

}