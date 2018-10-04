/* emitter.c */

#include "global.h"
int i = 0;

//Riktig jävla spagetthi-band AID lösning.
//Kolla upp postfix
int postfixalgorithm(int arr[])
{
	int stack[10];
	int sum = 0;
	int index = 0;
	int j = 0;

	while (index < 10) {
		switch (arr[index]) {
		case '+':
			stack[j - 2] = stack[j - 2] + stack[j - 1];
			j--;
			index++;
			break;
		case '-':
			stack[j - 1] = stack[j - 1] - stack[j];
			index++;
			j--;
			break;

		case '*':
			stack[j - 2] = stack[j - 2] * stack[j - 1];
			index++;
			j--;
			break;

		case 1: case 2: case 3: case 4: case 5: case 6: case'7': case '8': case '9':

			stack[j] = arr[index];
			j++;
			index++;
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
		printf("aa: %d\n", postfixalgorithm(arr));
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
		printf("%s\n", symtable[tval].lexptr);
		break;
	default:
		printf("token %d, tokenval %d\n", t, tval);
	}
}
