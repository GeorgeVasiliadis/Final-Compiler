#ifndef STRUCTURES_H
#define STRUCTURES_H

#ifndef MAX_ID_LENGTH
#define MAX_ID_LENGTH 15
#endif

#define MAX_SYMBOLS_HASHTABLE 40
#define MAX_SYMBOLS_STACK 30


typedef struct Symbol{
	unsigned char name [MAX_ID_LENGTH + 1];
	union{
		int i;
		float f;
	} value;
	int var_type;
	int has_value;
	int comes_from;
	int is_disposable;
	int is_lvalue;
	struct Symbol *nextSymbol;
	struct Symbol *prevSymbol;
} Symbol;

typedef struct AST_Node{
	int node_type;
	Symbol *wrapped_symbol;
	struct AST_Node* p_nodelist[4];
} AST_Node;

typedef struct Hashtable{
	int size;
	Symbol *container[MAX_SYMBOLS_HASHTABLE];
} Hashtable;

typedef struct Stack{
	int top_index;
	Symbol *container[MAX_SYMBOLS_STACK];
} Stack;
 
Hashtable *HT_init(void);
int HT_keygen(char*);
void HT_add(Hashtable*, Symbol*);
Symbol *HT_get(Hashtable*, char*);

Stack *ST_init(void);
void ST_push(Stack*, Symbol*);
Symbol *ST_pop(Stack*);

AST_Node *ASTN_init(int, Symbol*, AST_Node*, AST_Node*, AST_Node*, AST_Node*);

Symbol *SMB_init(char*);
void SMB_print(Symbol*);

Symbol *ID_init(Symbol *p_symb);

int test(void);

#endif