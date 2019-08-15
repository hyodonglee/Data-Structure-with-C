#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX 987654321

int visited[30];
int n,m;
FILE *fin, *fout;

typedef struct nodeList* nodePointer;
typedef struct nodeList
{
	int cost;
	int vertex;
	int check; 
	nodePointer link;
}nodeList;

nodePointer *graph;
nodePointer *mst;
void insert(nodePointer *head,int data, int w);
void prim();
void main()
{
	int i, num1=0, num2=0, cost=0;
	nodePointer curr;

	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d %d",&n,&m);

	graph = (nodePointer*)malloc(sizeof(nodePointer)*n);
	mst = (nodePointer*)malloc(sizeof(nodePointer)*n);
	for(i=0; i<n; i++)
		graph[i]=NULL;

	for(i=0; i<m; i++)
	{
		fscanf(fin,"%d %d %d",&num1,&num2, &cost);
		insert(&graph[num1],num2, cost);
		insert(&graph[num2],num1, cost);
	}
	prim();
	fclose(fin);
	fclose(fout);
}
void dfs(int v)
{
	nodePointer w;
	visited[v] = TRUE;
	fprintf(fout,"%d ",v);
	for(w=graph[v]; w; w=w->link)
	{
		if( !visited[w->vertex] )
			dfs(w->vertex);
	}
}
void prim()
{
	int inTreeVertex[100] ={0,};
	int cnt=1, i;
	nodePointer t;
	visited[0] = 1;
	while(cnt<n)
	{
		int min = MAX, i;
		nodePointer temp;

		for(i=0; i<cnt; ++i)
		{
			for(t = graph[inTreeVertex[i]]; t; t= t->link)
			{
				if(visited[t->vertex] == 0 && min>(t->cost))
				{
					min = t->cost;
					temp = t;	
				}
			}
		}

		temp->check = 1;
		visited[temp->vertex]=1;
		inTreeVertex[cnt++] = temp->vertex;
	}

	for(i=0; i<cnt ; i++)
		fprintf(fout,"%d ",inTreeVertex[i]);
}
void insert(nodePointer *head,int data, int w)
{
	nodePointer curr, node;

	node = (nodePointer)calloc(1,sizeof(nodeList));
	node->vertex = data;
	node->cost = w;
	node->link = NULL;
	curr = *head;
	if(curr)
	{
		while(curr->link)
			curr = curr->link;
		curr->link = node;
	}
	else
		*head = node;
}