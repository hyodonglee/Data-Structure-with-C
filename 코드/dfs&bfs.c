#include<stdio.h>
#include<stdlib.h>
#define T 1
#define F 0
//baekjoon 1260¹ø(dfs,bfs)

typedef struct Node* nodePointer;
typedef struct Node {
	int data;
	nodePointer next;
}node;

int* queue;
int* visited;
int front = -1;
int rear = -1;

void insertNode(int i, int num, nodePointer* graph);
void printNode(nodePointer* graph, int n);
void deleteNode(nodePointer* graph, int i);
int searchNodeData(nodePointer w);
void visitedClear(int n);
void addq(int data);
int deleteq();
void dfs(int i, nodePointer* graph);
void bfs(int i, nodePointer* graph);

int main()
{
	int n, m, v, i, j,t;
	int num1, num2;
	nodePointer* graph;

	scanf_s("%d %d %d", &n, &m, &v);

	visited = (int*)malloc(sizeof(int)*(n + 1));

	for (i = 1; i <= n; i++)
		visited[i] = 0;

	graph = (nodePointer)malloc(sizeof(node) * (n + 1));
	
	for (i = 1; i <= n; i++)
		graph[i] = NULL;

	for (i = 1; i <= m; i++)
	{
		scanf_s("%d %d", &num1, &num2);
		insertNode(num2, num1, graph);
		insertNode(num1, num2, graph);
	}

	//printNode(graph, n);

	//dfs(v, graph);
	
	//visitedClear(n);
	//dfs

	queue = (int*)malloc(sizeof(int) * (n + 1));
	
	bfs(v, graph);


	for (i = 1; i <= n; i++)
		deleteNode(graph, i);

	free(graph);
	free(visited);
	free(queue);
}

void insertNode(int i, int num, nodePointer* graph)
{
	nodePointer curr;
	nodePointer newnode;
	newnode = (nodePointer)malloc(sizeof(node));
	newnode->data = num;
	newnode->next = NULL;

	if (!graph[i])
	{
		graph[i] = newnode;
		return;
	}

	curr = graph[i];
	while (curr->next)
		curr = curr->next;
	curr->next = newnode;
	return;
}

void printNode(nodePointer* graph, int n)
{
	int i;
	nodePointer w;
	for (i = 1; i <= n; i++)
	{
		w = graph[i];
		while (w)
		{
			printf("%d ", w->data);
			w = w->next;
		}
		printf("\n");
	}
}

void deleteNode(nodePointer* graph, int i)
{
	nodePointer w;
	nodePointer tmp;
	if (!graph[i])
	{
		free(graph[i]);
		return;
	}

	w = graph[i];

	while (w->next)
	{
		tmp = w;
		w = w->next;
		free(tmp);
	}
	free(w);
}

int searchNodeData(nodePointer w)
{
	int pivot = w->data;

	while (w->next)
	{
		if (pivot > w->next->data && !visited[w->next->data])
			pivot = w->next->data;
		w = w->next;
	}

	return pivot;
}

void dfs(int i, nodePointer* graph)
{
	nodePointer w;
	visited[i] = T;
	printf("%d ", i);

	for (w = graph[i]; w; w = w->next)
	{
		if (!visited[searchNodeData(w)])
			dfs(searchNodeData(w), graph);
	}
	return;
}

void visitedClear(int n)
{
	int i;
	for (i = 1; i <= n; i++)
		visited[i] = F;
}

void addq(int data)
{
	queue[++rear] = data;
}

int deleteq()
{
	return queue[++front];
}

void bfs(int i, nodePointer* graph)
{
	int num;
	int key;
	nodePointer w;
	addq(i);

	while(front<rear)
	{
		num = deleteq();
		visited[num] = T;
		printf("%d ", num);

		for (w = graph[num]; w; w = w->next)
		{
			key = searchNodeData(w);
			if (!visited[key])
			{
				addq(key);
				visited[key]=T;
			}
		}
	}
}