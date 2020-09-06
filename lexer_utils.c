#include <string.h>
#include "globals.h"
#include "y.tab.h"

static char *reserved_words[RESERVED_WORDS_COUNT] = {"mainclass", "public", "static", "void", "main", "int", "float", "for", "while", "if", "else", "println"};

static int reserved_values[RESERVED_WORDS_COUNT] = {MAINCLASS, PUBLIC, STATIC, VOID, MAIN, INT, FLOAT, FOR, WHILE, IF, ELSE, PRINTLN};

int check_if_reserved(char *word){
	int i;
	for(i=0; i<RESERVED_WORDS_COUNT; i++){
		if(strcmp(word, reserved_words[i]) == 0){
			break;
		}
	}
	
	if(i<RESERVED_WORDS_COUNT){
		return reserved_values[i];
	} else {
		return ID;
	}
}