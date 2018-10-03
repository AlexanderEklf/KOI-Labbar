/* error.c */

#include "global.h"


/*  value of token attribute */


void error(char* m)  /* generates all error messages  */
{
	fprintf(stderr, "line %d: %s\n", lineno, m);
	system("pause");
	exit(EXIT_FAILURE);  /*  unsuccessful termination  */
}
