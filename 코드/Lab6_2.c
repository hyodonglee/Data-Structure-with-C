#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

int queue[MAX];
int rear = -1;
int front = -1;
int Qnumber=0;

void push(int item, FILE *fout);
int pop();
void queueFull(FILE *fout);

void main()
{
	int i=1;
	int item;
	int n;


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
			fprintf(fout,"%d\n",Qnumber);
			i++;
		}
		//size

		else if(strcmp(inf,"empty")==0)
		{
			if(front==rear)
				fprintf(fout,"1\n");
			else
				fprintf(fout,"0\n");
			i++;
		}
		//empty

		else if(strcmp(inf,"front")==0)
		{
			if(front==rear)
				fprintf(fout,"-1\n");
			else
			{
				fprintf(fout,"%d\n",queue[++front]);
				front--;
			}
			i++;
		}
		//front

		else if(strcmp(inf,"back")==0)
		{
			if(front==rear)
				fprintf(fout,"-1\n");
			else
			{
				fprintf(fout,"%d\n",queue[rear]);
			}
			i++;
		}
		//back
	}

	fclose(fin);
	fclose(fout);

}


void push(int item, FILE *fout)
{
	if(rear==MAX)
		queueFull(fout);
	queue[++rear]=item;
	Qnumber++;
}

void queueFull(FILE *fout)
{
	fprintf(fout,"-1\n");
	return;
}

int pop()
{
	if(front==rear)
	{
		return -1;
	}
	Qnumber--;
	return queue[++front];
	
}