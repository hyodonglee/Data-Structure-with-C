#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX 987654321
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int visited[30];
int n,m;
FILE *fin, *fout;

typedef struct nodeList* nodePointer;

typedef struct nodeList
{
	int cost;
	int vertex;
	nodePointer link;
}nodeList;

typedef struct Node{
	int vertex1;
	int vertex2;
	int cost;
}element;

element Heap[200];
nodePointer *graph;
void insert(nodePointer *head,int data, int w);
void adjust(nodeList a[], int root, int n);
void heapSort(nodeList a[], int n);
void main()
{
	int i, num1=0, num2=0, cost=0;
	nodePointer curr;
	int k = 1, cnt=0;

	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d %d",&n,&m);
	graph = (nodePointer*)malloc(sizeof(nodePointer)*n);

	for(i=0; i<n; i++)
		graph[i]=NULL;

	for(i=0; i<m; i++)
	{
		fscanf(fin,"%d %d %d",&num1,&num2, &cost);
		insert(&graph[num1],num2, cost);
		insert(&graph[num2],num1, cost);
	}


	for(i=0;i<n;i++)
		for(curr = graph[i];curr;curr = curr->link)
		{
			Heap[k].cost=curr->cost;
			Heap[k].vertex1 = i;
			Heap[k++].vertex2 = curr->vertex;
			cnt++;
		}

		heapSort(Heap,cnt);
		for(i=1;i<=cnt;i++)
			fprintf(fout, "%d %d %d\n", Heap[i].vertex1,Heap[i].vertex2,Heap[i].cost);
		fclose(fin);
		fclose(fout);
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

void heapSort(element a[], int n)
{
	int i, j;
	element temp;

	for (i = n / 2; i > 0; i--)
		adjust(a, i, n);
	for (i = n - 1; i > 0; i--)
	{
		SWAP(a[1], a[i + 1], temp);
		adjust(a, 1, i);
	}
}

void adjust(element a[], int root, int n)
{
	int child, rootkey;
	element temp;
	temp = a[root];
	rootkey = a[root].cost;
	child = 2 * root;
	while (child <= n)
	{
		if ((child < n) && (a[child].cost < a[child + 1].cost))
			child++;
		if (rootkey > a[child].cost)
			break;
		else
		{
			a[child / 2] = a[child];
			child *= 2;
		}
	}
	a[child / 2] = temp;
}