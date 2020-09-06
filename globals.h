#ifndef GLOBALS_H
#define GLOBALS_H

#define RESERVED_WORDS_COUNT 12
#define MAX_ID_LENGTH 15

#define FALSE 0
#define TRUE 1

#define ASTN_INT_CONST 0
#define ASTN_FLOAT_CONST 1
#define ASTN_DIVISION 2
#define ASTN_MULT 3
#define ASTN_SUBSTR 4
#define ASTN_ADD 5 
#define ASTN_EQ 6
#define ASTN_LT 7
#define ASTN_GT 8
#define ASTN_LE 9
#define ASTN_GE 10
#define ASTN_LG 11
#define ASTN_NE 12
#define ASTN_PROGRAM 13
#define ASTN_COMP_STMT 14
#define ASTN_STMT_LIST 15
#define ASTN_STMT 16
#define ASTN_OPEN_STMT 17
#define ASTN_CLOSED_STMT 18
#define ASTN_SIMPLE_STMT 19
#define ASTN_DECLARATION 20
#define ASTN_TYPE 21
#define ASTN_ID_LIST 22
#define ASTN_NULL_STMT 23
#define ASTN_ASSIGN_STMT 24
#define ASTN_EXPR 25
#define ASTN_ASSIGN_EXPR 26
#define ASTN_FOR_STMT 27
#define ASTN_CLOSED_FOR_STMT 28
#define ASTN_OPASSIGN_EXPR 29
#define ASTN_OPBOOL_EXPR 30
#define ASTN_IF_STMT 31
#define ASTN_WHILE_STMT 32
#define ASTN_BOOL_EXPR 33
#define ASTN_R_VAL 34
#define ASTN_TERM 35
#define ASTN_FACTOR 36
#define ASTN_NUM 37
#define ASTN_ID 38
#define ASTN_PRINTLN 39


#define TYPE_INT 0
#define TYPE_FLOAT 1
#define TYPE_NONE 2

int yylex();
void yyerror(char const*);

#endif