#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

FILE *fin;
FILE *fout;

typedef struct element* nodePointer;
typedef struct element{
	char data[25];
	nodePointer link;
}element;

nodePointer *table;
int stringToInt(char *key);
int hash(int num, int b);
void insert(nodePointer *node, char str[]);
int search(int k,char str[]);
void freeLink(nodePointer *node);
void main()
{
	int n, i, b, m, j;
	char str[25];
	int IntStr;

	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d %d",&b,&n);

	table = (nodePointer*)malloc(sizeof(nodePointer)*b);

	for(i=0;i<b;i++)
		table[i] = NULL;

	for(i=0;i<n;i++)
	{
		fscanf(fin,"%s",str);
		IntStr = stringToInt(str);
		IntStr = hash(IntStr,b);

		insert(&table[IntStr],str);
	}

	fscanf(fin,"%d",&m);
	for(i=0;i<m;i++)
	{
		fscanf(fin,"%s",str);
		IntStr = stringToInt(str);
		IntStr = hash(IntStr,b);

		if(search(IntStr,str))
			fprintf(fout,"true\n");
		else
			fprintf(fout,"false\n");
	}

	for(i=0;i<b;i++)
		freeLink(&table[i]);
	free(table);
	
	fclose(fin);
	fclose(fout);
}

int stringToInt(char *key)
{
	int number = 0;
	while(*key)
		number += *key++;
	return number;
}

int hash(int num, int b)
{
	return num%b;
}

int search(int k,char str[])
{
	nodePointer curr;
	
	for(curr = table[k];curr;curr = curr->link)
		if(strcmp(curr->data,str)==0) 
			return 1;

	return 0;
}

void insert(nodePointer *node, char str[])
{
	nodePointer newnode;
	newnode = (nodePointer)malloc(sizeof(element));
	strcpy(newnode->data,str);
	newnode->link = NULL;

	if(!*node)
		*node = newnode;

	else
	{
		nodePointer curr;

		curr = *node;
		while(curr->link != NULL)
			curr = curr->link;

		curr->link = newnode;
	}
}

void freeLink(nodePointer *node)
{
	nodePointer tmp;
	nodePointer curr;
	curr = *node;

	while(curr!=NULL)
	{
		tmp = curr;
		curr = curr->link;
		free(tmp);
	}
}

