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
treePointer tstack[MAX];

void push(int item);
int pop();
void insert(treePointer *root, int n);
void iterInorder(treePointer temp);
treePointer pop2();
void push2(treePointer temp);
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

	iterInorder(root);
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

void iterInorder(treePointer temp)
{
	top = -1;
	for(;;)
	{
		for(; temp; temp = temp->lChild)
			push2(temp);
		temp = pop2();
		if(!temp)break;
		if(temp->data != -1)
			fprintf(fout,"%d ", temp->data);
		temp = temp->rChild;
	}
}

void push2(treePointer temp)
{
	tstack[++top] = temp;
}

treePointer pop2()
{
	return tstack[top--];
}