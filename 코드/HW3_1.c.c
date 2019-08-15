# include <stdio.h>
# include <string.h>
# define MAX 20
void infixtoprefix(char infix[20],char prefix[20]);
void reverse(char array[30]);
char pop();
int pop2();
void push(char symbol);
void push2(int token);
int isOperator(char symbol);
int prcd(char symbol);
char get_token2(char *symbol, int *n);
int top=-1;
int top2=0;
char stack[MAX];
char infix[20],prefix[20],temp;
int num[50];

FILE *f1;
FILE *f2;
void main() {
 
 
 f1=fopen("input.txt", "r");
 f2=fopen("output.txt", "w");
  
 fscanf(f1, "%s", &infix);
 
 
 infixtoprefix(infix,prefix);
 reverse(prefix);
 fprintf(f2,(prefix));
 fprintf(f2,"\n%d",eval());
 
 fclose(f1);
 fclose(f2);
 
}
int eval(void)
{
 char token;
 char symbol;
 int op1,op2;
 int n = 0;
 token = get_token2(&symbol, &n);
 while (token != '\0') {
  if (token == '0')
   push2(symbol - '0');
  else {
   
   op1 = pop2();
   op2 = pop2();
   switch(token) {
   case '+':
    push2(op1+op2); break;
   case '-':
    push2(op1-op2); break;
   case '*':
    push2(op1*op2); break;
   case '/':
    push2(op1/op2); break;
   case '%':
    push2(op1%op2); break;
   }
  }
  token = get_token2(&symbol, &n);
 }
 return pop2();
}

void infixtoprefix(char infix[20],char prefix[20]) {
 int i,j=0;
 char symbol;
 stack[++top]='#';
 reverse(infix);
 for (i=0;i<strlen(infix);i++) {
  symbol=infix[i];
  if (isOperator(symbol)==0) {
   prefix[j]=symbol;
   num[top2++]=symbol - '0';
   j++;
  } else   {
   if (symbol==')') {
    push(symbol);
   } else if(symbol == '(') {
    while (stack[top]!=')') {
     prefix[j]=pop();
     j++;
    }
    pop();
   } else {
    if (prcd(stack[top])<=prcd(symbol)) {
     push(symbol);
    } else {
     while(prcd(stack[top])>=prcd(symbol)) {
      prefix[j]=pop();
      j++;
     }
     push(symbol);
    }
   
   }
  }
  
 }
 while (stack[top]!='#') {
  prefix[j]=pop();
  j++;
 }
 prefix[j]='\0';
}

char get_token2(char *symbol, int *n)
{
 *symbol = stack[strlen(stack) - ++(*n)];
 switch(*symbol){
 case '(': return '(';
 case ')': return ')';
 case '+': return '+';
 case '-': return '-';
 case '/': return '/';
 case '*': return '*';
 case '%': return '%';
 case '\0': return '\0';
 default: return 0;
 }
}
void reverse(char array[30]) 
{
 int i,j;
 char temp[100];
 for (i=strlen(array)-1,j=0;i+1!=0;--i,++j) {
  temp[j]=array[i];
 }
 temp[j]='\0';
 strcpy(array,temp);
}
char pop() {
 char a;
 a=stack[top];
 top--;
 return a;
}
int pop2() {
 int a;
 a=num[--top2];
 return a;
}

void push(char symbol) {
 stack[++top]=symbol;
}
void push2(int token) {
 num[top2++]=(token);
}
int prcd(char symbol) 
{
 switch(symbol) {
  case '+':
          case '-':
          return 2;
  break;
  case '*':
          case '/':
          return 4;
  break;
  case '$':
          case '^':
          return 6;
  break;
  case '#':
          case '(':
          case ')':
          return 1;
  break;
 }
}
int isOperator(char symbol) {
 switch(symbol) {
  case '+':
          case '-':
          case '*':
          case '/':
          case '^':
          case '$':
          case '&':
          case '(':
          case ')':
          return 1;
  break;
  default:
          return 0;
  
 }
} 