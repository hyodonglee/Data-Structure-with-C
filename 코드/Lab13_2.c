#include<stdio.h>
#include<stdlib.h>
#define left -1
#define right 1
#define MAX 200

typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer lChild;
	treePointer rChild;
}node;

FILE *fin;
FILE *fout;

int stack[MAX];
int top = -1;

void push(int item);
int pop();
void search(treePointer root, int index);
void insert(treePointer *root, int n);
void main()
{
	int i, n, m;
	int index;
	treePointer root, curr, newnode;

	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	root = (treePointer)malloc(sizeof(node));

	fscanf(fin, "%d", &n);
	insert(&root, n);

	fscanf(fin, "%d", &m);
	for (i = 0; i < m; i++)
	{
		fscanf(fin, "%d", &index);
		search(root, index);
	}
	free(root);
	fclose(fin);
	fclose(fout);
}

void push(int item)
{
	stack[++top] = item;
}

int pop()
{
	return stack[top--];
}

void search(treePointer root, int index)
{
	treePointer curr;
	int dir;
	curr = root;

	while (1)
	{
		if (index == 1)
			break;
		else if (index % 2 == 0)
			push(left);
		else
			push(right);
		index /= 2;
	}

	while (top > -1)
	{
		dir = pop();
		if (dir == left)
			curr = curr->lChild;
		else
			curr = curr->rChild;
	}
	if (curr->lChild != NULL)
		fprintf(fout, "%d ", curr->lChild->data);
	else
		fprintf(fout, "-1 ");
	if (curr->rChild != NULL)
		fprintf(fout, "%d\n", curr->rChild->data);
	else
		fprintf(fout, "-1\n");
}

void insert(treePointer *root, int n)
{
	int i;
	int num, index, dir;
	treePointer curr, newnode;

	for (i = 1; i <= n; i++)
	{
		fscanf(fin, "%d", &num);
		if (i == 1)
		{
			(*root)->data = num;
			(*root)->lChild = NULL;
			(*root)->rChild = NULL;
			continue;
		}
		else
		{
			curr = *root;
			index = i;
			while (1)
			{
				if (index == 1)
					break;
				else if (index % 2 == 0)
					push(left);
				else
					push(right);

				index = index / 2;
			}
		}
		//자리 찾기

		newnode = (treePointer)malloc(sizeof(node));
		newnode->data = num;
		newnode->lChild = NULL;
		newnode->rChild = NULL;

		while (top > 0)
		{
			dir = pop();
			if (dir == left)
				curr = curr->lChild;
			else
				curr = curr->rChild;
		}
		dir = pop();
		if (dir == left)
			curr->lChild = newnode;
		else
			curr->rChild = newnode;
		//삽입
	}
}