#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
#define L -1
#define R 1
#define TRUE 1
#define FALSE 0

FILE *fin;
FILE *fout;

int *arr;
int stack[MAX];
int top =0;

void push(int dir);
int pop();
void iterInorder(int max, int n);
void main()
{
	int n, i, num;
	int max;
	int start =0;

	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d",&n);
	arr = (int*)malloc(sizeof(int)*(2*n+2));

	for(i=1;i<=2*n+1;i++)
		arr[i]=-1;

	for(i=1;i<=n;i++)
	{
		fscanf(fin,"%d",&num);
		arr[i] = num;
	}

	while(1)
	{
		if(pow(2,start)<= n && n<pow(2,start+1))
		{
			max = pow(2,start+1);
			break;
		}
		else
			start++;
	}
	iterInorder(max,n);

	free(arr);
	fclose(fin);
	fclose(fout);
}

void push(int dir)
{
	stack[++top]=dir;
}

int pop()
{
	return stack[top--];
}

void iterInorder(int max, int n)
{
	int index=1;
	int cnt =1;
	for(;;)
	{
		for(;arr[index]!=-1;index*=2)
		{
			push(index);
		}
		index = pop();
		fprintf(fout, "%d ",arr[index]);
		cnt++;
		index = 2*index +1;
		if(cnt== n-1)
			break;
	}
}