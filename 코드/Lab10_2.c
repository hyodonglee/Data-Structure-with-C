#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

typedef struct queue *queuePointer;
typedef struct queue{
	int data;
	queuePointer link;
};
queuePointer front, rear;

int cnt=0;
void push(int item);
int pop();
void queueFull();

FILE *fin;
FILE *fout;

void main()
{
	int i=1;
	int item;
	int n;
	char inf[10];
	

	 fin= fopen("input.txt","r");
	 fout= fopen("output.txt","w");
	

	fscanf(fin,"%d",&n);

	while(i<=n)
	{
		fscanf(fin,"%s",inf);
		if(strcmp(inf,"push")==0)
		{
			fscanf(fin,"%d",&item);
			push(item);
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
			fprintf(fout,"%d\n",cnt);
			i++;
		}
		//size

		else if(strcmp(inf,"empty")==0)
		{
			if(!front)
				fprintf(fout,"1\n");
			else
				fprintf(fout,"0\n");
			i++;
		}
		//empty

		else if(strcmp(inf,"front")==0)
		{
			if(!front)
				fprintf(fout,"-1\n");
			else
			{
				fprintf(fout,"%d\n",front->data);
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
				fprintf(fout,"%d\n",rear->data);
			}
			i++;
		}
		//back
	}

	fclose(fin);
	fclose(fout);

}


void push(int item)
{
	queuePointer temp;
	temp = (queuePointer)malloc(sizeof(*temp));
	temp->data = item;
	temp->link = NULL;
	if(front)
		rear->link = temp;
	else
		front = temp;
	rear = temp;
	++cnt;
}


int pop()
{
	queuePointer temp = front;
	int item;
	if(!temp)
		return -1;
	item = temp->data;
	front = temp->link;
	free(temp);
	--cnt;
	return item;
}