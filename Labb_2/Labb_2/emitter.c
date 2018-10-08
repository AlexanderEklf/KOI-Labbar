/* emitter.c */

#include "global.h"
int i = 0;
int stack[10];
int index = 0;
int j = 0;
int temp = 0;

void push()
{
	stack[j] = arr[index];
	j++;
	index++;
}

//Denna funktion räknar ut värdet av uttrycket som lagrats i stacken med postfix-notation.
//Lösningen hade varit snyggare med enbart en stack istället för två, men detta kom vi på en bit in i labben.
int postfixalgorithm(int arr[])
{
	index = 0;
	j = 0;
	i = 0;

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

		case '/':
			stack[j - 2] = stack[j - 2] / stack[j - 1];
			index++;
			j--;
			break;

		case '^':
			stack[j - 2] = pow(stack[j - 2], stack[j - 1]);
			index++;
			j--;
			break;

		case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:

			stack[j] = arr[index];
			j++;
			index++;
			break;


		default:
			index = 10;
			j = 0;
		}
	}
	//här resettar vi flaggan när allt är uträknat.
	flag = 0;
	//här tilldelar vi resultatet av uttrycket till identifieraren.
	symtable[temp].value = stack[0];
	return stack[0];
}


//Vi har kompleterat denna funktion med ^ samt = operatorerna. Vi fyller även upp vår array med uttrycket här.
void emit(int t, int tval)  /*  generates output  */
{
	switch (t) {
	case '+': case '-': case '*': case '/': case '^':
		printf("%c\n", t);
		arr[i] = t;
		i++;

		break;
	case '=':
		printf("%c\n", t);
		arr[i] = t;
		i++;
		printf("Result: %d\n", postfixalgorithm(arr));
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
		//om flaggan är 1 så betyder det att vi har passerat = och vi lagrar identifierarens värde istället för själva tecknet. 
		if (flag == 1) {
			arr[i] = symtable[tval].value;
			i++;
			printf("%d\n", symtable[tval].value);
			
		}
		//om identifieraren är till vänster om = sparar vi tokenvärdet så att vi "minns" det.
		else {
			printf("%s\n", symtable[tval].lexptr);
			temp = tval;
		}
		break;
	default:
		printf("token %d, tokenval %d\n", t, tval);
	}
}
