#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

char stack[MAX];

int top=0;

void push(char item);
void pop();


void main()
{
	int i,j;
	int n;
	char inf[100];

	FILE *fin = fopen("input.txt","r");
	FILE *fout = fopen("output.txt","w");

	fscanf(fin,"%d",&n);

	for(i=0;i<n;i++)
	{
		fscanf(fin,"%s",inf);
		for(j=0;j<strlen(inf);j++)
		{
			if(inf[j]=='(')
				push(inf[j]);
			else
				pop();
		}

		if(top!=0)
			fprintf(fout,"NO\n");
		else
			fprintf(fout,"YES\n");

		top=0;
	}

	fclose(fin);
	fclose(fout);

}


void push(char item)
{
	if(top>=MAX)
		return;
	stack[top++]=item;
}


void pop()
{
	stack[--top];
}



