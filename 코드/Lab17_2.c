#include<stdio.h>
#include<stdlib.h>

typedef struct Node* nodePointer;
typedef struct Node{
	int vertex;
	nodePointer link;
}Node;

nodePointer *graph;
FILE *fin;
FILE *fout;

void printList(nodePointer node);
void insert(int data, nodePointer *node);
void freeList(nodePointer node);
void main()
{
	int n, i, m, num1,num2;
	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d",&n);
	fscanf(fin,"%d",&m);
	graph = (nodePointer*)malloc(sizeof(nodePointer)*n);

	for(i=0;i<n;i++)
		graph[i] = NULL;

	for(i=0;i<m;i++)
	{
		fscanf(fin,"%d %d",&num1, &num2);
		insert(num2,&graph[num1]);
		insert(num1,&graph[num2]);
	}

	for(i=0;i<n;i++)
	{
		printList(graph[i]);
		freeList(graph[i]);
	}
	free(graph);
	fclose(fin);
	fclose(fout);
}

void insert(int data, nodePointer *node)
{
	nodePointer newnode;
	nodePointer curr;
	newnode = (nodePointer)malloc(sizeof(Node));
	newnode->vertex = data;
	newnode->link = NULL;

	if(!*node){
		*node=newnode;
		return;
	}
	curr = *node;

	while(curr->link)
		curr = curr->link;
	curr->link = newnode;
}

void printList(nodePointer node)
{
	while(node){
		fprintf(fout,"%d ",node->vertex);
		node = node->link;
	}
	fprintf(fout,"\n");
}

void freeList(nodePointer node)
{
	nodePointer tmp;

	while(node !=NULL)
	{
		tmp = node;
		node = node->link;
		free(tmp);
	}
}