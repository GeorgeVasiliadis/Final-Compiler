#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "globals.h"
#include "structures.h"

/*
//	------------------
//	+---Hash Table---+
//	------------------
*/

/*
// 	Hashtable initializer.
// 	Should be called before usage.
*/
Hashtable *HT_init(){
	Hashtable *ht = (Hashtable*) malloc (sizeof(Hashtable));
	
	if(ht){
		for(int i=0; i<MAX_SYMBOLS_HASHTABLE; i++){
			ht->container[i] = NULL;
		}
		ht->size = 0;
	} else {
		fprintf(stderr, "Error: Out of memory.\n");
	}
	
	return ht;
}


/*
//	Generates a integer key in [0, (MAX_SYMBOLS_HASHTABLE-1)]
//	based on the given string.
//	When name is Null, 0 is returned!
*/
int HT_keygen(char *string){
	char *p_char;
	int sum = 0;
		
	if(string){
		for(p_char = string; *p_char; p_char++){
			sum += (*p_char);
		}
	}
	
	return sum % MAX_SYMBOLS_HASHTABLE;
}


/* 	
//	Adds a symbol record into given Hashtable.
//	The given symbol can be Null.
//	Symbol's name is used for distinction.
//	A symbol will not be added if another symbol
//	with the same name exists already.
*/
void HT_add(Hashtable *ht, Symbol *p_symb){
	if(p_symb){
		Symbol *ptr = HT_get(ht, p_symb->name);
		if(!ptr){
			int key = HT_keygen(p_symb->name);
			ptr = ht->container[key];
			p_symb->nextSymbol = ptr;
			p_symb->prevSymbol = NULL;
			if(ptr){
				ptr->prevSymbol = p_symb;
			}
			ht->container[key] = p_symb;
			ht->size++;
		}
	}
}


/*
//	Returns Null if there is no symbol 
//	with the given name, or otherwise, a pointer
//	pointing to that symbol. 
*/
Symbol *HT_get(Hashtable *ht, char *name){
	int key;
	Symbol *p_symb;
	
	if(name){
		key = HT_keygen(name);
		p_symb = ht->container[key];
		while(p_symb && (strcmp(p_symb->name, name) !=0))
			p_symb = p_symb->nextSymbol;
	}
	return p_symb;
}



/*
//	------------------
//	+------Stack-----+
//	------------------
*/


/*
// 	Stack initializer.
// 	Should be called before usage.
*/
Stack *ST_init(){
	Stack *st = (Stack*) malloc(sizeof(Stack));
	
	if(st){
		for(int i=0; i<MAX_SYMBOLS_STACK; i++){
			st->container[i] = NULL;
		}
		st->top_index = -1;
	} else {
		fprintf(stderr, "Error: Out of memory.\n");
	}
	
	return st;
}

/*
//	Pushes the given symbol to the given Stack.
//	The symbol can be Null.
*/
void ST_push(Stack *st, Symbol *p_symb){
	if(st->top_index < MAX_SYMBOLS_STACK - 1){
		st->top_index++;
		st->container[st->top_index] = p_symb;
	} else {
		fprintf(stderr, "Error: Stack out of memory.\n");
	}
}

/*
//	Returns the the symbol on top of given Stack.
//	If Stack is empty, Null is returned.
*/
Symbol *ST_pop(Stack *st){
	Symbol *p_symb = NULL;
	if(st->top_index >= 0){
		p_symb = st->container[st->top_index];
		st->top_index--;
	} else {
		fprintf(stderr, "Error: Tried to pop from empty Stack.\n");
	}
	return p_symb;
}	


/*
//	------------------
//	+----AST Nodes---+
//	------------------
*/

/*
//	AST Node initializer.
// 	Should be called before usage.
*/
AST_Node *ASTN_init(int node_type, Symbol *wrapped_symbol, AST_Node *ASTN_p0, AST_Node *ASTN_p1, AST_Node *ASTN_p2, AST_Node *ASTN_p3){
	AST_Node *p_node = (AST_Node*) malloc(sizeof(AST_Node));
	if(p_node){
		p_node->node_type = node_type;
		p_node->wrapped_symbol = wrapped_symbol;
		p_node->p_nodelist[0] = ASTN_p0;
		p_node->p_nodelist[1] = ASTN_p1;
		p_node->p_nodelist[2] = ASTN_p2;
		p_node->p_nodelist[3] = ASTN_p3;
	} else {
		fprintf(stderr, "Error: Out of memory.\n");
	}
	return p_node;
}

/*
//	------------------
//	+-----Symbols----+
//	------------------
*/

//todo garbage collector
/*
//	Symbol initializer.
//	Should be called before usage.
*/
Symbol *SMB_init(char *name){
	Symbol *p_symb;
	p_symb =(Symbol*) calloc(1, sizeof(Symbol));
	strncpy(p_symb->name, name, (strlen(name)>MAX_ID_LENGTH)?MAX_ID_LENGTH:strlen(name));
	p_symb->var_type = TYPE_NONE;
	p_symb->value.i = 0;
	p_symb->value.f = 0;
	p_symb->is_disposable = 0;
	p_symb->is_lvalue = 1;
	p_symb->nextSymbol = NULL;
	p_symb->prevSymbol = NULL;
	return p_symb;
}


/*
//	Sets the variable type of first given symbol to the one of
//	the second one.
*/
int SMB_setVarType(Symbol *p_symb, int var_type){
	if(p_symb->var_type){
		return 1;
	}
		
	switch(var_type){
		case INT:
			p_symb->var_type = var_type;
			break;
		case FLOAT:
			p_symb->var_type = var_type;
			break;
	}
	return 0;
}

void SMB_discard(Symbol *p_symb){
	
}

/*
//	Simple debugging utility.
//	Prints basic properties of given symbol in standard output.
*/
void SMB_print(Symbol *p_symb){
	if(p_symb){
		printf("Symbol: %s\n", (p_symb->name? (char*)p_symb->name:"NULL"));
		printf("Type: %s\n", p_symb->var_type==TYPE_FLOAT?"FLOAT":(p_symb->var_type==TYPE_INT?"INT":"None Type"));
		printf("Integer value: %d\n", p_symb->value.i);
		printf("Float value: %f\n", p_symb->value.f);
		printf("Is Disposable: %s\n", p_symb->is_disposable?"TRUE":"FALSE");
		printf("Is lValue: %s\n", p_symb->is_lvalue?"TRUE":"FALSE");
		printf("Next Symbol: %s\n", p_symb->nextSymbol->name?(char*)p_symb->nextSymbol->name:"NULL");
		printf("Previous Symbol: %s\n", p_symb->prevSymbol->name? (char*)p_symb->prevSymbol->name:"NULL");	
	}
}

Symbol *ID_init(Symbol *p_symb){
	Symbol *ptr;
	
	ptr = SMB_init("");
	memcpy(ptr, p_symb, sizeof(Symbol));
	ptr->is_disposable = 1;
	ptr->is_lvalue = 1;
	ptr->nextSymbol = NULL;
	ptr->prevSymbol = NULL;
	return ptr;
}

/*
// Temporary testing function.
*/
int test(){

	Symbol *a = SMB_init("George");
	a->var_type = 10;
	
	Symbol *b = SMB_init("Dimitra");
	b->var_type = -55;
	
	Symbol *c = SMB_init("Vasilis");
	c->var_type = 123;
	
	Symbol *rec;
	Hashtable *ht = HT_init();
	Stack *st = ST_init();
	
	AST_Node *n0, *n1, *n2;
	n0 = ASTN_init(1, a, NULL, NULL, NULL, NULL);
	n1 = ASTN_init(2, b, n0, NULL, n1, NULL);
	n2 = ASTN_init(5, a, n1, n2, n0, n1);

	SMB_print(a);
	SMB_print(b);
	SMB_print(c);
			
	return 0;
}