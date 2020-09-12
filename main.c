#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "globals.h"
#include "structures.h"
#include "code_gen.h"

extern Hashtable *ht;
extern Stack *st;
extern AST_Node *root;


void yyerror(char const *err){
	fprintf(stderr, "MIPS Error >> %s\nYacc >> Rejected", err);
	exit(1);
}
 

int main(){
	ht = HT_init();
	st = ST_init();
	
	if(!yyparse()){
		printf("Yacc >> Accepted\n");
		generate_code(root);
	}
	printf("\n");
	printf("File has been translated successfully!\n");


	return 0;
}