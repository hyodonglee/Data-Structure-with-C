#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;

listPointer top;
int cnt=0;
void push(int item);
int pop();

FILE *fin; 
FILE *fout; 

void main()
{
	int i=1;
	int item;
	int n;
	
	char inf[10];
	
	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");

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
			if(cnt==0)
				fprintf(fout,"1\n");
			else
				fprintf(fout,"0\n");
			i++;
		}
		//empty

		else if(strcmp(inf,"top")==0)
		{
			if(cnt==0)
				fprintf(fout,"-1\n");
			else
				{
					fprintf(fout,"%d\n",top->data);
				}
			i++;
		}
		//top

	}

	fclose(fin);
	fclose(fout);

}


void push(int item)
{
	listPointer temp;
	temp = (listPointer)malloc(sizeof(*temp));
	temp->data = item;
	temp ->link = top;
	top=temp;
	cnt++;
}


int pop()
{
	listPointer temp = top;
	int item;
	if(!temp)
		return -1;
	item = temp->data;
	top = temp->link;
	free(temp);
	cnt--;
	return item;
}



