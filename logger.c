#include <stdio.h>
#include <stdlib.h>

void lex_err(char const *s){
	fprintf(stderr, "Lexer>> Error: %s\n", s);
	exit(1); 
}

void lex_dbg(char const *s){
	fprintf(stdout, "Lexer>> Debug: %s\n", s);
}


void yyerror(char const *s){
	fprintf(stderr, "Syntaxer>> Error: %s\n", s);
	exit(1);
}

void yydbg(char const *s){
	fprintf(stdout, "Syntaxer>> Debug: %s\n", s);
}

void semant_err(char const *s){
	fprintf(stderr, "Semantixer>> Error: %s\n", s);
	exit(1);
}

void semant_dbg(char const *s){
	fprintf(stdout, "Semantixer>> Debug: %s\n", s);
}

void fin_err(char const *s){
	fprintf(stderr, "Final>> Error: %s\n", s);
	exit(1);
}

void fin_log(char const *s){
	fprintf(stdout, "Final>> %s\n", s);
}