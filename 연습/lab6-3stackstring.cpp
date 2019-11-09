#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define Y 1
#define N -1
#define SWAP(x,y,t) ((t)=(*x),(*x)=(*y),(*y)=(t))
/*stack*/

FILE* fin;
FILE* fout;
char stack[MAX];
int top = -1;

void push(char ch)
{
	if(top!= MAX)
		stack[++top] = ch;
}

char pop()
{
	if (top>-1)
		return stack[top--];
}

int ps(char* str)
{
	int i = 0;
	top = -1;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
			push(str[i]);
		else
		{
			if (top > -1)
				pop();
			else
				return N;
		}
		i++;
	}
	if (top != -1)
		return N;
	return Y;
}

int main()
{
	int n, m;
	int i, j;
	char str[100];
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	fscanf(fin, "%d", &n);

	for (i = 0; i < n; i++)
	{
		fscanf(fin, "%s", str);
		//fprintf("%s", str);
		if (ps(str) == Y) fprintf(fout,"YES\n");
		else fprintf(fout,"NO\n");
	}
	fclose(fin);
	fclose(fout);
}