/* parser.c -- without the optimizations */

#include "global.h"

int lookahead;
int flag = 0;


void match(int);
void start(), list(), expr(), moreterms(), term(), morefactors(), factor(), assignment();




void parse()  /*  parses and translates expression list  */
{
	lookahead = lexan();
	start();
}

//f�r att uppt�cka tilldelning
void assignment()
{
	int id_lexeme = tokenval;
	match(ID);
	emit(ID, id_lexeme);
	match('=');
	flag = 1;
	expr();
	emit('=', tokenval);

}

void start()
{
	/* Just one production for start, so we don't need to check lookahead */



	list();
	match(DONE);
}

//assignment tillagd s� att grammtiken ska kunna hantera tilldelningar
void list()
{
	if (lookahead == '(' || lookahead == ID || lookahead == NUM) {
		assignment();
		match(';');
		list();
	}
	else {
		/* Empty */
	}
}

void expr()
{
	/* Just one production for expr, so we don't need to check lookahead */
	term();
	moreterms();
}

void moreterms()
{
	if (lookahead == '+') {
		match('+');
		term();
		emit('+', tokenval);
		moreterms();
	}
	else if (lookahead == '-') {
		match('-');
		term();
		emit('-', tokenval);
		moreterms();
	}
	else {
		/* Empty */
	}
}

void term()
{
	/* Just one production for term, so we don't need to check lookahead */
	factor();
	morefactors();
}

//kod f�r att uppt�cka ^
void exponential()
{
	if (lookahead == '^') {
		match('^');
		factor();
		emit('^', tokenval);
		morefactors();
	}
}

void morefactors()
{
	exponential();
	if (lookahead == '*') {
		match('*');
		factor();
		//Om vi uppt�cker * s� m�ste vi kolla en bit fram�t f�r att se om det �r ett ^ efter som har h�gre prioritet
		exponential();
		emit('*', tokenval);
		morefactors();

	}
	else if (lookahead == '/') {
		match('/');
		factor();
		exponential();
		emit('/', tokenval);
		morefactors();
	}
	else if (lookahead == DIV) {
		match(DIV);
		factor();
		emit(DIV, tokenval);
		morefactors();
	}
	else if (lookahead == MOD) {
		match(MOD); factor(); emit(MOD, tokenval); morefactors();
	}
	else {
		/* Empty */
	}
}

void factor()
{
	if (lookahead == '(') {
		match('(');
		expr();
		match(')');
	}
	else if (lookahead == ID) {
		int id_lexeme = tokenval;
		match(ID);
		emit(ID, id_lexeme);
	}
	else if (lookahead == NUM) {
		int num_value = tokenval;
		match(NUM);
		emit(NUM, num_value);
	}
	else
		error("syntax error in factor");
}



void match(int t)
{
	if (lookahead == t) {
		lookahead = lexan();
	}
	else
		error("syntax error in match");
}
