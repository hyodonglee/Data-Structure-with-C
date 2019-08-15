#include <stdio.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 80

typedef enum
{
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
}precedence;
precedence stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
char expr2[MAX_EXPR_SIZE];

int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };
int top = -1;
int i=0;

void push(precedence);
precedence pop();
void postfix();
precedence getToken(char*, int*);
void printToken(precedence);

FILE *fp;
FILE *fout;

void main()
{

	fp = fopen("input.txt", "r");
	fout = fopen("output.txt","w");
	fscanf(fp, "%s", expr);
	postfix();
	fclose(fp);
	fclose(fout);
}

void postfix()
{
	char symbol;
	precedence token;
	int n = 0;
	top = 0; 
	stack[0] = eos;
	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
	{
		if (token == operand)
			{
				fprintf(fout,"%c", symbol);
			}
		else if (token == rparen)
		{ 
			while (stack[top] != lparen)
				printToken(pop());
			pop(); 
		}
		else
		{
			while (isp[stack[top]] >= icp[token])
				printToken(pop());
			push(token);
		}
	}
	while ((token = pop()) != eos)
		printToken(token);
	fprintf(fout, "\n");

}

void printToken(precedence a)
{
	char w;

	switch (a)
	{
	case plus: w = '+';
		break;
	case minus: w = '-';
		break;
	case divide: w = '/';
		break;
	case times: w = '*';
		break;
	case mod: w = '%';
		break;
	}
	fprintf(fout, "%c", w);
	expr2[i++]=w;
}

precedence getToken(char *symbol, int *n)
{
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand;
	}
}

void push(precedence item) {
	stack[++top] = item;
}

precedence pop() {
	return stack[top--];
}