#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * queue;
int rear = -1;
int front = -1;
int capacity = 5;

void copy(int a, int b,  int *c)
{
	int i;

	for (i=a; i<b; i++)
		c[i-a]=queue[i];
}
void queueFull()
{
	int *newqueue;
	int start;
	start=(front +1)%(capacity+1);
	newqueue=(int *)malloc(sizeof(int)*((2*capacity)+1));

	if(start<2)
		copy(start,start+capacity-1,newqueue);
	else
	{
		copy(start,capacity,newqueue);
		copy(0,rear-1,newqueue+capacity-start+1);
	}
	queue=(int *)malloc(sizeof(int)*((2*capacity)+1));

	front=2*capacity;
	rear=capacity-1;
	capacity*=2;
	free(queue);
	queue=newqueue;
}
void addq(int item)
{
	rear = (rear +1) % (capacity+1);
	if (front == rear && rear != -1)
	{
		queueFull();
		rear++;
	}
	queue[rear] = item;

	/*queue[rear]=item;
	rear=(rear+1)%6;*/
}
int deleteq()
{
	int item;
	front = (front + 1) % (capacity+1);

	if (front == rear)
		return -1;
	else
		return queue[front];

	//Queue temp = queue[front];

	/*front=(front+1)%6;
	return temp;*/
}


int main(void)
{
	FILE *fin,*fout;
	int n=0,size=0,i;
	char oper[20];
	int dq=0;
	int item;
	queue = (int *)malloc(sizeof(int)*(capacity+1));


	fin=fopen("input.txt","rt");
	fout=fopen("output.txt","wt");

	fscanf(fin,"%d",&n);

	for(i=0;i<n;i++)
	{
		fscanf(fin,"%s",oper);
		if(strcmp(oper,"push")==0)
		{
			fscanf(fin,"%d",&item);
			if(size==capacity)
			{
				fprintf(fout,"Queue Full!\n");
				queueFull();
				size++;
			}
			else
			{
				addq(item);
				size++;
			}
		}
		if(strcmp(oper,"pop")==0)
		{
			if(size == 0){
				fprintf(fout,"%d\n",-1);
			}
			else{
				dq=deleteq();
				size--;
				fprintf(fout,"%d\n",dq);
			}
		}
		if(strcmp(oper,"empty")==0)
		{
			if(size==0)
			{
				fprintf(fout,"%d\n",1);
			}
			else
			{
				fprintf(fout,"%d\n",0);
			}
		}
		if(strcmp(oper,"front")==0)
		{
			if(size==0)
			{
				fprintf(fout,"%d\n",-1);
			}
			else
			{
				fprintf(fout,"%d\n",queue[front]);
			}
		}
		if(strcmp(oper,"back")==0)
		{
			if(size==0)
			{
				fprintf(fout,"%d\n",-1);
			}
			else
			{
				if(rear == 0){
					fprintf(fout,"%d\n",queue[capacity-1]);
				}
				else{
					fprintf(fout,"%d\n",queue[rear-1]);
				}
			}
		}
		if(strcmp(oper,"size")==0)
		{
			fprintf(fout,"%d\n",size);
		}

		if(strcmp(oper,"index")==0)
		{
			fprintf(fout,"%d %d\n",front,rear);
		}

		if(strcmp(oper,"capacity")==0)
		{
			fprintf(fout,"%d\n",capacity);
		}
	}

	free(queue);

	fclose(fin);
	fclose(fout);
}  

