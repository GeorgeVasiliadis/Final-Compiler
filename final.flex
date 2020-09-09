%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
#include "lexer_utils.h"
#include "globals.h"

int debug = 0;

%}

%option noyywrap

%%


"=="			{if(debug)printf("Equal Operator\n"); return EQ_OP;}
"!="			{if(debug)printf("Different Operator\n"); return NE_OP;}
"<"			{if(debug)printf("Less Operator\n"); return LT_OP;}
">"			{if(debug)printf("Greater Operator\n"); return GT_OP;}
"<="			{if(debug)printf("Less Equal Operator\n"); return LE_OP;}
">="			{if(debug)printf("Greater Equal Operator\n"); return GE_OP;}

"="			{if(debug)printf("Assign Operator\n"); return '=';}
","			{if(debug)printf("Comma\n"); return ',';}
";"			{if(debug)printf("Semicolon\n"); return ';';}

"+"			{if(debug)printf("Add Operator\n"); return '+';}
"-"			{if(debug)printf("Substract Operator\n"); return '-';}
"*"			{if(debug)printf("Multiply Operator\n"); return '*';}
"/"			{if(debug)printf("Divide\n"); return '/';}

"{"			{if(debug)printf("Left Curly Bracket\n"); return '{';}
"}"			{if(debug)printf("Right Curly Bracket\n"); return '}';}
"("			{if(debug)printf("Left Parenthesis\n"); return '(';}
")"			{if(debug)printf("Right Parenthesis\n"); return ')';}

[a-zA-Z][a-zA-Z0-9_]*	{	
				int t = check_if_reserved(yytext);
				if(t==ID){
					if(debug)printf("ID -> %s\n", yytext);
				} else {
					if(debug)printf("Reserved Word -> %s\n", yytext);
				}
				strcpy(yylval.ystr, yytext);
				return t;
			}

0			{
				if(debug)printf("Integer -> %s\n", yytext);
				strcpy (yylval.ystr, yytext);
				return INT_CONST;
			}
			
[1-9][0-9]*		{
				if(debug)printf("Integer -> %s\n", yytext);
				strcpy(yylval.ystr, yytext);
				return INT_CONST;
			}
			
[0-9]*"."[0-9]*		{
				if(debug)printf("Float -> %s\n", yytext);
				strcpy(yylval.ystr, yytext);
				return FLOAT_CONST;
			}
			
[ \t\n]			{/*WhiteSpace*/}

.			{fprintf(stderr, "Error: Unrecognized character '%c'.\n", yytext[0]); exit(1);}

%%