/* emitter.c */

#include "global.h"
int i = 0;
char ch = ' ';
int index = 0;
int j = 0;
int stack[10];

//Riktig jävla spagetthi-band AID lösning.
//Kolla upp postfix
void push()
{
	stack[j] = arr[index];
	j++;
	index++;
}

int pop(int i)
{
	//hejhej

	return i;
}

int postfixalgorithm(int arr[])
{

	int sum = 0;
	index = 0;
	j = 0;
	i = 0;

	while (index < 10) {
		switch (arr[index]) {
		case '+':
			//pop
			stack[j - 2] = stack[j - 2] + stack[j - 1];
			j--;
			index++;
			break;
		case '-':
			//pop
			stack[j - 1] = stack[j - 1] - stack[j];
			index++;
			j--;
			break;

		case '*':
			//pop
			stack[j - 2] = stack[j - 2] * stack[j - 1];
			index++;
			j--;
			break;

		case '/':
			//pop
			stack[j - 2] = stack[j - 2] / stack[j - 1];
			index++;
			j--;
			break;
		case 1: case 2: case 3: case 4: case 5: case 6: case'7': case '8': case '9':

			//push
			push();
			break;

		default:
			index = 10;
			//index = 0;
			j = 0;

		}


	}
	return stack[0];
}

void emit(int t, int tval)  /*  generates output  */
{
	
	switch (t) {
	case '+': case '-': case '*': case '/':
		printf("%c\n", t);
		arr[i] = t;
		i++;

		break;
	case '=':
		printf("%c\n", t);
		arr[i] = t;
		i++;
		printf("%c contains: %d\n",ch, postfixalgorithm(arr));
		break;
	case DIV:
		printf("DIV\n");
		break;
	case MOD:
		printf("MOD\n"); break;
	case NUM:
		printf("%d\n", tval);
		arr[i] = tval;
		i++;
		break;
	case ID:
		ch = &(symtable[tval].lexptr);
		printf("%s\n", symtable[tval].lexptr);
		break;
	default:
		printf("token %d, tokenval %d\n", t, tval);
	}
}
