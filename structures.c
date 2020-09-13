#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "globals.h"
#include "structures.h"
#include "logger.h"



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
		for(int i=0; i<MAX_CHAINS_HASHTABLE; i++){
			ht->container[i] = NULL;
		}
		ht->size = 0;
	} else {
		fin_err("Out of memory.");
	}
	
	return ht;
}


/*
//	Generates a integer key in [0, (MAX_CHAINS_HASHTABLE-1)]
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
	
	return sum % MAX_CHAINS_HASHTABLE;
}


/* 	
//	Adds a symbol record into given Hashtable.
//	The given symbol can be Null.
//	Symbol's name is used for distinction.
//	A symbol will not be added if another symbol
//	with the same name exists already and Null will be returned.
//	Otherwise, a valid non-Null pointer (pointing to the 
//	preserved symbol) will be returned.
*/
Symbol *HT_add(Hashtable *ht, Symbol *p_symb){
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
			return p_symb;
		}
		return NULL;
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
		fin_err("Out of memory.");
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
		fin_err("Stack out of memory.");
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
		fin_err("Tried to pop from empty Stack.");
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
		fin_err("Out of memory.");
	}
	return p_node;
}



/*
//	------------------
//	+-----Symbols----+
//	------------------
*/


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
	p_symb->has_value = FALSE;
	p_symb->nextSymbol = NULL;
	p_symb->prevSymbol = NULL;
	return p_symb;
}