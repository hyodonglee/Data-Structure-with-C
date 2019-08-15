#include <stdio.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 80
typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;

int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top = -1;

void push(int);
int pop();
int eval();
precedence getToken(char*, int*);

FILE *fp;
FILE *fout;

void main()
{
	int result = 0;

	fp = fopen("input.txt", "r");
	fout = fopen("output.txt","w");
	fscanf(fp, "%s", expr);
	result = eval();
	fprintf(fout,"%d", result);
	fclose(fp);
	fclose(fout);
}

int eval()
{
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0; 
	top = -1;
	token = getToken(&symbol, &n);
	while (token != eos)
	{
		if (token == operand)
			push(symbol - '0');
		else
		{
			op2 = pop();
			op1 = pop();
			switch (token)
			{
			case plus: push(op1 + op2);
				break;
			case minus: push(op1 - op2);
				break;
			case times: push(op1*op2);
				break;
			case divide: push(op1 / op2);
				break;
			case mod: push(op1%op2);
				break;
			}
		}
		token = getToken(&symbol, &n);
	}
	return pop();
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

void push(int item) {
	stack[++top] = item;
}

int pop() {
	return stack[top--];
}