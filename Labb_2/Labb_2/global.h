/* global.h */
#pragma once


#include <stdio.h>  /* include declarations for i/o routines */
#include <ctype.h>  /* ... and for character test routines */
#include <stdlib.h> /* ... and for some standard routines, such as exit */
#include <string.h> /* ... and for string routines */


#define BSIZE  128  /* buffer size */
#define NONE   -1
#define EOS    '\0'

#define NUM    256
#define DIV    257
#define MOD    258
#define ID     259
#define DONE   260

extern int tokenval;   /*  value of token attribute */
extern int lineno;

struct entry {  /*  form of symbol table entry  */
	char *lexptr;
	int  token;
	//spara värden

};

extern int arr[10];

//struct Stack
//{
//	int top;
//	unsigned capacity;
//	int* arry;
//};

//extern struct Stack* createStack(unsigned capacity);

//
//const int isEmpty(struct Stack* stack)
//{
//	return stack->top == -1;
//}
//
//const char peek(struct Stack* stack)
//{
//	return stack->arr[stack->top];
//}
//
//const char pop(struct Stack* stack)
//{
//	if (!isEmpty(stack))
//		return stack->arr[stack->top--];
//	return '$';
//}
//
//extern void push(struct Stack* stack, char op);

////Funktion för att kolla om karaktären är en operand
//const int isOperand(char c)
//{
//	return(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
//}
//
////funktion för att kolla prioriteter mellan operander
////dest högre värde som returneras desto högre prioritet
//
//const int precedence(char c) {
//	switch (c)
//	{
//	case '+':
//	case '-':
//		return 1;
//	case '*':
//	case '/':
//		return 2;
//	case '^':
//		return 3;
//	}
//	return -1;
//}


extern struct entry symtable[];  /* symbol table  */
//extern struct Stack* stack;

extern void init();  /*  loads keywords into symtable  */
extern void error(char* m);  /*  generates all error messages  */
extern int lexan();  /*  lexical analyzer  */
extern void parse();  /*  parses and translates expression list  */
extern int insert(char *s, int tok);  /*  returns position of entry for s */
extern int lookup(char *s);  /*  returns position of entry for s */
extern void emit(int t, int tval);  /*  generates output  */
