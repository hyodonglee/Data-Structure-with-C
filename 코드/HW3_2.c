#include <stdio.h>
#define MAX_STACK_SIZE 10
#define MAX_EXPR_SIZE 80

int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];

int i=0;

int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };
int top = 0;

void push(int item);
int pop();
void postfix();
int getToken(char*, int*);
int blank();


void main()
{
   FILE *f1, *f2;
   int result,i=0;
   char c;
   f1 = fopen("input.txt", "r");
   f2 = fopen("output.txt", "w");

   fscanf(f1, "%c", &c);

   while (!feof(f1)) {
      expr[i++] = c;
      fscanf(f1, "%c", &c);
   }
   expr[i] = ' ';

   result = blank();

   fprintf(f2, "%d", result);


}

int blank()
{
	char symbol;
	int token;
	int n = 0;
	int op1,op2;
	top = 0;
	

	for (token = getToken(&symbol, &n); token != 0; token = getToken(&symbol, &n)) {
      if (token == -1) {
         push(token);
      }
      else if (token == -3) {
         push(token);
      }
      else if (token == -2) {
         if (stack[top - 1] > 0) {//숫자라면
            op1 = pop();
            op2 = 2;
            pop();
            push(op1*op2);
            if (stack[top - 2] > 0) {
               op1 = pop();
               op2 = pop();
               push(op1 + op2);
            }
         }
         else if(stack[top-1] == -1) {
            pop();
            push(2);
            if (stack[top - 2] > 0) {
               op1 = pop();
               op2 = pop();
               push(op1 + op2);
            }
         }
      }
      else {
         if (stack[top - 1] > 0) {
            op1 = pop();
            pop();
            op2 = 3;
            push(op1*op2);
            if (stack[top - 2] > 0) {
               op1 = pop();
               op2 = pop();
               push(op1 + op2);
            }
         }
         else if(stack[top-1] == -3){
            pop();
            push(3);
            if (stack[top - 2] > 0) {
               op1 = pop();
               op2 = pop();
               push(op1 + op2);
            }
         }
      }

   }
   if (top != 1) {
      return 0;
   }
   return stack[top-1];
}

	


int getToken(char *symbol, int *n)
{
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '(': return -1;
	case ')': return -2;
	case '[': return -3;
	case ']': return -4;
	case ' ': return 0;
	}
}


void push(int item) {
	stack[top++] = item;
}

int pop() {
	return stack[--top];
}