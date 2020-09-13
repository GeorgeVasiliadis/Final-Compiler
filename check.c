#include "structures.h"
#include "globals.h"
#include "logger.h"

extern Hashtable *ht;


// Applied in all arithmetic operators.
// Produces an intermediate symbol made up from the two
// input symbols, which contains the variable type. 
Symbol *check_general(Symbol *op1, Symbol *op2){
	Symbol *p = SMB_init("");
	p->has_value = TRUE;
	if(op1->var_type == TYPE_INT){
		if(op2->var_type == TYPE_INT){
			p->var_type = TYPE_INT;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->var_type = TYPE_FLOAT;	
		}
	} else if (op1->var_type == TYPE_FLOAT){
		if(op2->var_type == TYPE_INT){
			p->var_type = TYPE_FLOAT;
		} else if (op2->var_type == TYPE_FLOAT) {
			p->var_type = TYPE_FLOAT;
		}
	}
	return p;
}

// Applied in all boolean operators.
// Produces an intermediate symbol made up from the two
// input symbols, which is integer.
Symbol *check_bool(Symbol *op1, Symbol *op2){
	Symbol *p = SMB_init("");
	p->has_value = TRUE;
	p->var_type == TYPE_INT;
	return p;
}



Symbol *check_uminus(Symbol *op1){
	Symbol *p = SMB_init("");
	p->has_value = TRUE;
	p->var_type = op1->var_type;
	return p;
}


// Ensures that the l-value of the the assignment is an
// existing (declared) ID.
Symbol *check_assign(Symbol *op1, Symbol *op2){
	Symbol *p = HT_get(ht,op1->name);
	if(!p){
		semant_err("Tried to use ID before declaration.");
	}	
	p->has_value = TRUE;
	return (p);
}


// Ensures that the to-declare ID is not already declared.
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
			id->has_value = FALSE;
		}
		node = node->p_nodelist[0];
	}
}

// Ensures that the referenced symbol is initialized properly.
Symbol *check_id_reference(Symbol *op1){
	Symbol *p = HT_get(ht, op1->name);
	if(!p){
		semant_err("Tried to use ID before declaration.");
	}
	if(!p->has_value){
		semant_err("Tried to use ID before initialization.");
	}
	return (p);
}