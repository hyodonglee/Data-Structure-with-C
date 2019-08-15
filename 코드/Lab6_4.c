#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct
{
	int key;

}element;
element queue[MAX];
int rear = 0;
int front = 0;

void addq(element item)
{
	queue[rear]=item;
	rear=(rear+1)%6;
}
element deleteq()
{
	element item;
	element temp = queue[front];

	front=(front+1)%6;
	return temp;
}
int main(void)
{
	FILE *fin,*fout;
	int n,size=0;
	int i;
	char find[20];
	element good;
	int dq=0;
	fin=fopen("input.txt","rt");
	fout=fopen("output.txt","wt");
	fscanf(fin,"%d",&n);
	for(i=0;i<n;i++)
	{
		fscanf(fin,"%s",find);
		if(strcmp(find,"push")==0)
		{
			fscanf(fin,"%d",&good.key);
			if(size==5)
			{
				fprintf(fout,"%d\n",-1);
			}
			else
			{
				addq(good);
				size++;
			}
		}
		if(strcmp(find,"pop")==0)
		{
			if(size == 0){
				fprintf(fout,"%d\n",-1);
			}
			else{
				dq=deleteq().key;
				size--;
				fprintf(fout,"%d\n",dq);
			}
		}
		if(strcmp(find,"empty")==0)
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
		if(strcmp(find,"front")==0)
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
		if(strcmp(find,"back")==0)
		{
			if(size==0)
				fprintf(fout,"%d\n",-1);

			else
			{
				if(rear == 0){
					fprintf(fout,"%d\n",queue[4]);
				}
				else{
					fprintf(fout,"%d\n",queue[rear-1]);
				}
			}
		}
		if(strcmp(find,"index")==0)
			fprintf(fout,"%d %d\n",front,rear);
	}
	fclose(fin);
	fclose(fout);
} 