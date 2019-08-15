#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct Node* nodePointer;
typedef struct Node{
	int vertex;
	nodePointer link;
}Node;

int *visited;
nodePointer *graph;
nodePointer front, rear;

FILE *fin;
FILE *fout;

void insert(int data, nodePointer *node);
void freeList(nodePointer node);
void dfs(int v);
void addq(int);
int deleteq();
void bfs(int v);
void main()
{
	int n, i, m, num1,num2;
	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d",&n);
	fscanf(fin,"%d",&m);
	graph = (nodePointer*)malloc(sizeof(nodePointer)*n);
	visited = (int*)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++)
		visited[i]=FALSE;

	for(i=0;i<n;i++)
		graph[i] = NULL;

	for(i=0;i<m;i++)
	{
		fscanf(fin,"%d %d",&num1, &num2);
		insert(num2,&graph[num1]);
		insert(num1,&graph[num2]);
	}

	dfs(0);
	fprintf(fout,"\n");
	//DFS로 출력
	for(i=0;i<n;i++)
		visited[i]=FALSE;
	bfs(0);
	//BFS로 출력

	for(i=0;i<n;i++){
		freeList(graph[i]);
	}
	free(visited);
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

void dfs(int v)
{
	nodePointer w;
	visited[v] = TRUE;
	fprintf(fout,"%d ",v);
	for(w=graph[v];w;w=w->link)
		if(!visited[w->vertex])
			dfs(w->vertex);
}
//stack으로 만들어 봤는데 순회 루트가 다름! 재귀함수로 만들것을 추천.

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
	return v;
}

void bfs(int v)
{
	nodePointer w;
	front = NULL;
	rear = NULL;
	fprintf(fout,"%d ", v);
	visited[v] = TRUE;
	addq(v);
	while(front)
	{
		v = deleteq();
		for(w = graph[v]; w; w = w->link)
			if(!visited[w->vertex]){
				fprintf(fout,"%d ", w->vertex);
				addq(w->vertex);
				visited[w->vertex] = TRUE;
			}
	}
}