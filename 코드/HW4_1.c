#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10
int count = 0;

typedef struct stack *stackPointer;
typedef struct stack2 * stackPointer2;
typedef struct stack {
	char key;
	stackPointer link;
};

typedef struct stack2 {
	int key;
	stackPointer2 link;
};

stackPointer top;
stackPointer head;
stackPointer2 top2;

int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };

char expr[50];
char expr2[50];

int i = 0;
FILE * f1;
FILE * f2;

void push(char item)
{
	stackPointer temp;
	temp = (stackPointer)malloc(sizeof(*temp));
	temp->key = item;
	temp->link = top;
	top = temp;
}

char pop()
{
	stackPointer temp = top;
	char item;
	if (!temp)
		return 0;
	item = temp->key;
	top = temp->link;
	free(temp);
	return item;
}

void push2(int item)
{
	stackPointer2 temp;
	temp = (stackPointer2)malloc(sizeof(*temp));
	temp->key = item;
	temp->link = top2;
	top2 = temp;
}

int pop2()
{
	int item;
	stackPointer2 temp = top2;
	if (!temp)
		return 0;

	item = temp->key;
	top2 = temp->link;
	free(temp);
	return item;
}

char getToken2(char *symbol, int *n)
{
	*symbol = expr2[(*n)++];
	switch (*symbol)
	{
	case '(': return '(';
	case ')': return ')';
	case '+': return  '+';
	case '-': return '-';
	case '/': return '/';
	case '*': return '*';
	case '%': return '%';
	case '\0': return '\0';
	default: return '0';
	}
}

char getToken(char *symbol, int *n)
{
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '(': return '(';
	case ')': return ')';
	case '+': return  '+';
	case '-': return '-';
	case '/': return '/';
	case '*': return '*';
	case '%': return '%';
	case '\0': return '\0';
	default: return '0';
	}
}

int returnindex(char token) {
	switch (token)
	{
	case '(': return 0;
	case ')': return 1;
	case '+': return  2;
	case '-': return 3;
	case '/': return 4;
	case '*': return 5;
	case '%': return 6;
	case '\0': return 7;
	default: return 8;
	}
}

void postfix()
{
	char symbol;
	char token;
	int n = 0;
	char to;
	int index;
	for (token = getToken(&symbol, &n); token != '\0'; token = getToken(&symbol, &n))
	{
		if (token == '0')
		{
			fprintf(f2, "%c ", symbol);
			expr2[i++] = symbol;
		}//숫자일때

		else if (token == ')')
		{
			while (top->key != '(')
			{
				to = pop();
				fprintf(f2, "%c ", to);
				expr2[i++] = to;
			}
			pop();
		}
		else
		{
			while (isp[(returnindex(top->key))] >= icp[index = returnindex(token)])
			{
				to = pop();
				fprintf(f2, "%c ", to);
				expr2[i++] = to;
			}
			push(token);
		}
	}
	while ((token = pop()) != '\0')
	{
		fprintf(f2, "%c ", token);
		expr2[i++] = token;
	}
}

int eval()
{
	char token;
	char symbol;
	int op1, op2;
	int n = 0;
	token = getToken2(&symbol, &n);
	while (token != '\0')
	{
		if (token == '0')
			push2(symbol - '0');
		else
		{
			op2 = pop2();
			op1 = pop2();
			switch (token)
			{
			case '+': push2(op1 + op2);
				break;
			case '-': push2(op1 - op2);
				break;
			case '*': push2(op1*op2);
				break;
			case '/': push2(op1 / op2);
				break;
			case '%': push2(op1%op2);
				break;
			}
		}
		token = getToken2(&symbol, &n);
	}
	return pop2();
}


void main()
{
	int result = 0;
	f1 = fopen("input.txt", "r");
	f2 = fopen("output.txt", "w");

	fscanf(f1, "%s", expr);

	top = (stackPointer)malloc(sizeof(struct stack));
	top->link = NULL;
	top->key = 0;
	postfix();

	fprintf(f2, "\n");

	result = eval();
	fprintf(f2, "%d", result);
	free(top);
	fclose(f1);
	fclose(f2);
}

