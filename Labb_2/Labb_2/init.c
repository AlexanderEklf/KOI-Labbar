/* init.c */

#include "global.h"

struct entry keywords[] = {
  { "div", DIV },
  { "mod", MOD, },
  { 0,     0 }
};

#pragma region Försökte mig på en riktig hardcore-lösning men fattar inte hur man ska implementer detta

/*Finns mer kod i global.h*/



struct Stack* stack;

void push(struct Stack* stack, char op)
{
	stack->arr[++stack->top] = op;
}
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;

	stack->arr = (int*)malloc(stack->capacity * sizeof(int));

	if (!stack->arr)
		return NULL;

	return stack;

}
#pragma endregion

void init()  /*  loads keywords into symtable  */
{
	stack = createStack(10);
	struct entry *p;
	for (p = keywords; p->token; p++)
		insert(p->lexptr, p->token);


}
