%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
#include "lexer_utils.h"
#include "globals.h"
%}

%option noyywrap

%%


"=="			{printf("Equal Operator\n"); return EQ_OP;}
"!="			{printf("Different Operator\n"); return NE_OP;}
"<"			{printf("Less Operator\n"); return LT_OP;}
">"			{printf("Greater Operator\n"); return GT_OP;}
"<="			{printf("Less Equal Operator\n"); return LE_OP;}
">="			{printf("Greater Equal Operator\n"); return GE_OP;}

"="			{printf("Assign Operator\n"); return '=';}
","			{printf("Comma\n"); return ',';}
";"			{printf("Semicolon\n"); return ';';}

"+"			{printf("Add Operator\n"); return '+';}
"-"			{printf("Substract Operator\n"); return '-';}
"*"			{printf("Multiply Operator\n"); return '*';}
"/"			{printf("Divide\n"); return '/';}

"{"			{printf("Left Curly Bracket\n"); return '{';}
"}"			{printf("Right Curly Bracket\n"); return '}';}
"("			{printf("Left Parenthesis\n"); return '(';}
")"			{printf("Right Parenthesis\n"); return ')';}

[a-zA-Z][a-zA-Z0-9_]*	{	
				int t = check_if_reserved(yytext);
				if(t==ID){
					printf("ID -> %s\n", yytext);
				} else {
					printf("Reserved Word -> %s\n", yytext);
				}
				strcpy(yylval.ystr, yytext);
				return t;
			}

0			{
				printf("Integer -> %s\n", yytext);
				strcpy (yylval.ystr, yytext);
				return INT_CONST;
			}
			
[1-9][0-9]*		{
				printf("Integer -> %s\n", yytext);
				strcpy(yylval.ystr, yytext);
				return INT_CONST;
			}
			
[0-9]*"."[0-9]*		{
				printf("Float -> %s\n", yytext);
				strcpy(yylval.ystr, yytext);
				return FLOAT_CONST;
			}
			
[ \t\n]			{/*WhiteSpace*/}

.			{/*Unrecognized Character*/}

%%