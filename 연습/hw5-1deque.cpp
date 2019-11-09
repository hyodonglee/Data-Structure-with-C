#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node* nodePointer;
typedef struct Node {
	int data;
	nodePointer llink;
	nodePointer rlink;
}Node;

FILE* fin;
FILE* fout;
nodePointer root;
nodePointer front;
nodePointer back;
void push_front(int x)
{
	nodePointer newnode;
	nodePointer curr;
	newnode = (nodePointer)malloc(sizeof(Node));
	newnode->data = x;
	newnode->llink = NULL;
	newnode->rlink = NULL;

	if (!root)
	{
		root = newnode;
		front = root;
		back = root;
		return;
	}
	
	curr = root;
	while(curr->llink)
	{
		curr = curr->llink;
	}
	curr->llink = newnode;
	front = curr->llink;
	front->rlink = curr;
}

void push_back(int x)
{
	nodePointer newnode;
	nodePointer curr;
	newnode = (nodePointer)malloc(sizeof(Node));
	newnode->data = x;
	newnode->llink = NULL;
	newnode->rlink = NULL;

	if (!root)
	{
		root = newnode;
		back = root;
		front = root;
		return;
	}

	curr = root;
	while (curr->rlink)
	{
		curr = curr->rlink;
	}
	curr->rlink = newnode;
	back = curr->rlink;
	back->llink = curr;
}

int pop_front()
{
	if (root==NULL)
		return -1;

	if (front == back)
	{
		int tmp= root->data;
		root = NULL;
		front = NULL;
		back = NULL;
		return tmp;
	}

	nodePointer curr;
	int data;
	curr = front->rlink;
	
	data = front->data;
	free(front);

	front = curr;
	front->llink = NULL;
	return data;
}

int pop_back()
{
	if (root==NULL)
		return -1;

	if (front == back)
	{
		int tmp = root->data;
		root = NULL;
		front = NULL;
		back = NULL;
		return tmp;
	}
	nodePointer curr;
	int data;
	curr = back->llink;

	data = back->data;
	free(back);

	back = curr;
	back->rlink = NULL;
	return data;
}

int Size()
{
	if (!front)
		return 0;

	nodePointer curr;
	int cnt = 1;
	curr = front;
	while (curr->rlink)
	{
		curr = curr->rlink;
		cnt++;
	}
	return cnt;
}

int Empty()
{
	if (Size()==0)
		return 1;
	return 0;
}

int Front()
{
	if (Size()==0)
		return -1;
	return front->data;
}

int Back()
{
	if(Size()==0)
		return -1;
	return back->data;
}

void freeDeque()
{
	nodePointer curr;
	if (front)
	{
		while (front->rlink)
		{
			curr = front->rlink;
			free(front);
			front = curr;
		}
		free(front);
	}
}

int main()
{
	int n,i;
	char str[30];
	int data;

	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");


	fscanf(fin, "%d", &n);

	for (i = 0; i < n; i++)
	{
		fscanf(fin, "%s", str);

		if (!strcmp(str, "push_back"))
		{
			fscanf(fin, "%d", &data);
			push_back(data);
		}
		else if (!strcmp(str, "push_front"))
		{
			fscanf(fin, "%d", &data);
			push_front(data);
		}
		else if (!strcmp(str, "pop_front"))
		{
			printf("%d\n",pop_front());
		}
		else if (!strcmp(str, "pop_back"))
		{
			printf("%d\n", pop_back());
		}
		else if (!strcmp(str, "size"))
		{
			printf("%d\n",Size());
		}
		else if (!strcmp(str, "empty"))
		{
			printf("%d\n",Empty());
		}
		else if (!strcmp(str, "front"))
		{
 			printf("%d\n",Front());
		}
		else if (!strcmp(str, "back"))
		{
			printf("%d\n", Back());
		}
	}
	
	freeDeque();
	fclose(fin);
	fclose(fout);
}