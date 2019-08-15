#include <stdio.h>
#include <stdlib.h>
#define MAX 987654321
#define TRUE 1
#define FALSE 0
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

typedef struct Node* nodePointer;
typedef struct Node{
	int vertex;
	nodePointer link;
}Node;

int *visited;
int cnt = 0;
nodePointer *graph;
nodePointer front, rear;
FILE *fin, *fout;

void addq(int v);
int deleteq();
void bfs(int v, int man2);
void insert(int data, nodePointer *node);
void main()
{
	int man1,man2,n,m;
	int num1,num2;
	int i;
	int level = 0;
	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d",&n);
	fscanf(fin,"%d %d",&man1,&man2);


	fscanf(fin,"%d",&m);
	graph = (nodePointer*)malloc(sizeof(nodePointer)*(n+1));
	visited = (int*)malloc(sizeof(int)*(n+1));

	for(i=0;i<n;i++)
		visited[i]=FALSE;

	for(i=1;i<=n;i++)
		graph[i] = NULL;

	for(i=1;i<=m;i++)
	{
		fscanf(fin,"%d %d",&num1, &num2);
		insert(num2,&graph[num1]);
		insert(num1,&graph[num2]);
	}

	bfs(man1,man2);
	free(graph);
	free(visited);
	fclose(fin);
	fclose(fout);
}

void addq(int v)
{
	nodePointer temp;
	temp = (nodePointer)malloc(sizeof(Node));
	temp->vertex = v;
	temp->link = NULL;
	if(front)
		rear->link = temp;
	else
		front = temp;
	rear = temp;
}

int deleteq()
{
	nodePointer temp = front;
	int v;
	if(!temp)
		return -1;
	v = temp->vertex;
	front = temp->link;
	free(temp);
	cnt++;
	return v;
}

void bfs(int v, int man2)
{
	nodePointer w;
	front = NULL;
	rear = NULL;

	visited[v] = TRUE;
	addq(v);
	while(front)
	{
		v = deleteq();
		for(w = graph[v]; w; w = w->link)
		{
			if(!visited[w->vertex]){
				addq(w->vertex);
				visited[w->vertex] = TRUE;
			}
			if(w->vertex == man2)
			{
				fprintf(fout,"%d",cnt);
				return;
			}
		}
	}
	fprintf(fout,"-1");
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