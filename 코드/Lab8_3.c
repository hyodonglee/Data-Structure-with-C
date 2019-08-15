#include <stdio.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 80

typedef enum
{
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
}precedence;
precedence stack[MAX_STACK_SIZE];
int stack2[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
char expr2[MAX_EXPR_SIZE];
int i=0;

int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };
int top = -1;

void push(precedence);
precedence pop();
void postfix();
precedence getToken(char*, int*);
void printToken(precedence);
precedence getToken2(char *symbol, int *n);

FILE *fp;
FILE *fout;

void main()
{
	int result = 0;
	fp = fopen("input.txt", "r");
	fout = fopen("output.txt","w");
	fscanf(fp, "%s", expr);
	postfix();
	fprintf(fout,"\n");
	
	result = eval();
	fprintf(fout,"%d", result);

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
				expr2[i++]=symbol;
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
precedence getToken2(char *symbol, int *n)
{
	*symbol = expr2[(*n)++];
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

void push2(int item) {
	stack2[++top] = item;
}

int pop2() {
	return stack2[top--];
}

int eval()
{
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0; 
	token = getToken2(&symbol, &n);
	while (token != eos)
	{
		if (token == operand)
			push2(symbol - '0');
		else
		{
			op2 = pop2();
			op1 = pop2();
			switch (token)
			{
			case plus: push2(op1 + op2);
				break;
			case minus: push2(op1 - op2);
				break;
			case times: push2(op1*op2);
				break;
			case divide: push2(op1 / op2);
				break;
			case mod: push2(op1%op2);
				break;
			}
		}
		token = getToken2(&symbol, &n);
	}
	return pop2();
}