#include <stdlib.h>
#include <stdio.h>
#include "structures.h"
#include "globals.h"

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
			fprintf(stderr, "Error: Zero-Division.\n");
			exit(1);
		}
	} else if (op2->var_type == TYPE_FLOAT){
		if(op2->value.f == 0){
			fprintf(stderr, "Error: Zero-Division.\n");
			exit(1);
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