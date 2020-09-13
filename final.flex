%{
#include <string.h>
#include "y.tab.h"
#include "globals.h"
#include "lexer_utils.h"
#include "logger.h"
%}





%option noyywrap





%%
"//".*			{if(DEBUG)lex_dbg("Comment");}

"=="			{if(DEBUG)lex_dbg("Equal Operator"); 				return EQ_OP;}
"!="			{if(DEBUG)lex_dbg("Different Operator"); 			return NE_OP;}
"<"			{if(DEBUG)lex_dbg("Less Operator"); 				return LT_OP;}
">"			{if(DEBUG)lex_dbg("Greater Operator"); 			return GT_OP;}
"<="			{if(DEBUG)lex_dbg("Less Equal Operator"); 			return LE_OP;}
">="			{if(DEBUG)lex_dbg("Greater Equal Operator"); 			return GE_OP;}

"="			{if(DEBUG)lex_dbg("Assign Operator"); 				return '=';}
","			{if(DEBUG)lex_dbg("Comma"); 					return ',';}
";"			{if(DEBUG)lex_dbg("Semicolon"); 				return ';';}

"+"			{if(DEBUG)lex_dbg("Add Operator"); 				return '+';}
"-"			{if(DEBUG)lex_dbg("Substract Operator"); 			return '-';}
"*"			{if(DEBUG)lex_dbg("Multiply Operator"); 			return '*';}
"/"			{if(DEBUG)lex_dbg("Divide Operator"); 					return '/';}

"{"			{if(DEBUG)lex_dbg("Left Curly Bracket"); 			return '{';}
"}"			{if(DEBUG)lex_dbg("Right Curly Bracket"); 			return '}';}
"("			{if(DEBUG)lex_dbg("Left Parenthesis"); 			return '(';}
")"			{if(DEBUG)lex_dbg("Right Parenthesis"); 			return ')';}

[a-zA-Z][a-zA-Z0-9_]*	{	
				int t = check_if_reserved(yytext);
				if(t==ID){
					if(DEBUG)lex_dbg("ID");
				} else {
					if(DEBUG)lex_dbg("Reserved Word");
				}
				strcpy(yylval.ystr, yytext);
				return t;
			}

0			{
				if(DEBUG)lex_dbg("Integer");
				strcpy (yylval.ystr, yytext);
				return INT_CONST;
			}
			
[1-9][0-9]*		{
				if(DEBUG)lex_dbg("Integer");
				strcpy(yylval.ystr, yytext);
				return INT_CONST;
			}
			
[0-9]*"."[0-9]*		{
				if(DEBUG)lex_dbg("Float");
				strcpy(yylval.ystr, yytext);
				return FLOAT_CONST;
			}
			
[ \t\n]			{/*WhiteSpace*/}

.			{lex_err("Unrecognized Character");}
%%