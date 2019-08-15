#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

int stack[MAX];
int top=0;

void push(int item, FILE *fout);
int pop();
void stackFull(FILE *fout);

void main()
{
	int i=1;
	int item;
	int n;
	int stacknumber=0;

	FILE *fin = fopen("input.txt","r");
	FILE *fout = fopen("output.txt","w");

	char inf[10];

	fscanf(fin,"%d",&n);

	while(i<=n)
	{
		fscanf(fin,"%s",inf);
		if(strcmp(inf,"push")==0)
		{
			fscanf(fin,"%d",&item);
			push(item,fout);
			i++;
		}
		//push

		else if(strcmp(inf,"pop")==0)
		{
			fprintf(fout,"%d\n",pop());
			i++;
		}
		//pop

		else if(strcmp(inf,"size")==0)
		{
			fprintf(fout,"%d\n",top);
			i++;
		}
		//size

		else if(strcmp(inf,"empty")==0)
		{
			if(top==0)
				fprintf(fout,"1\n");
			else
				fprintf(fout,"0\n");
			i++;
		}
		//empty

		else if(strcmp(inf,"top")==0)
		{
			if(top==0)
				fprintf(fout,"-1\n");
			else
				{
					fprintf(fout,"%d\n",stack[--top]);
					top++;
				}
			i++;
		}
		//top

	}

	fclose(fin);
	fclose(fout);

}


void push(int item, FILE *fout)
{
	if(top>=MAX)
		stackFull(fout);
	stack[top++]=item;
}

void stackFull(FILE *fout)
{
	fprintf(fout,"-1\n");
	return;
}

int pop()
{
	if(top==0)
	{
		return -1;
	}
	return stack[--top];
}



