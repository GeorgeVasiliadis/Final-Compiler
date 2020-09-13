#include "y.tab.h"
#include "structures.h"
#include "code_gen.h"
#include "logger.h"

Hashtable *ht;
Stack *st;
AST_Node *root;

int main(){
	ht = HT_init();
	st = ST_init();
	
	yyparse();
	generate_asm(root);
	fin_log("Success!");
	return 0;
}