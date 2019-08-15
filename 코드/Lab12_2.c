#include<stdio.h>
#include<stdlib.h>

typedef struct node *nodePointer;
typedef struct node {
	nodePointer llink;
	int data;
	nodePointer rlink;
}node;

FILE *fin;
FILE *fout;
void printList(nodePointer header);
void dinsert(nodePointer node, nodePointer newnode);
void printListBack(nodePointer header);
void ddelete(nodePointer curr);
void freeList(nodePointer header);

void main()
{
	int i, n, j;
	nodePointer header;
	nodePointer curr;
	nodePointer newnode;
	int num, index;

	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");


	fscanf(fin, "%d", &n);
	header = (nodePointer)malloc(sizeof(node));
	header->llink = header;
	header->rlink = header;

	curr = header;
	for (i = 0; i < n; i++)
	{
		fscanf(fin, "%d", &num);
		newnode = (nodePointer)malloc(sizeof(node));
		newnode->data = num;
		dinsert(curr, newnode);
		curr = curr->rlink;
		if (i == n - 1)
			curr = header;
	}
	printList(header);
	//생성

	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
	{
		curr = header;
		fscanf(fin, "%d %d", &num, &index);
		newnode = (nodePointer)malloc(sizeof(node));
		newnode->data = num;
		if (index >= 0)
			for (j = 0; j < index; j++)
			{
				curr = curr->rlink;
			}
		else
			for (j = 0; j < -index; j++)
			{
				curr = curr->llink;
			}
		dinsert(curr, newnode);
	}

	printList(header);
	//삽입

	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(fin, "%d", &index);
		curr = header;
		if (index < 0)
			for (j = 0; j < -index; j++)
				curr = curr->llink;
		else
			for (j = 0; j < index; j++)
				curr = curr->rlink;
		ddelete(curr);
	}
	printList(header);
	//삭제

	freeList(header);
	//free리스트

	fclose(fin);
	fclose(fout);
}

void dinsert(nodePointer node, nodePointer newnode)
{
	newnode->llink = node;
	newnode->rlink = node->rlink;
	node->rlink->llink = newnode;
	node->rlink = newnode;
}

void printList(nodePointer header)
{
	nodePointer curr;

	curr = header->rlink;

	while (curr->rlink != header)
	{
		fprintf(fout, "%d ", curr->data);
		curr = curr->rlink;
	}
	fprintf(fout, "%d\n", curr->data);
}

void printListBack(nodePointer header)
{
	nodePointer curr;

	curr = header->llink;

	while (curr->llink != header)
	{
		fprintf(fout, "%d ", curr->data);
		curr = curr->llink;
	}
	fprintf(fout, "%d\n", curr->data);
}

void ddelete(nodePointer curr)
{
	curr->llink->rlink = curr->rlink;
	curr->rlink->llink = curr->llink;
	free(curr);
}

void freeList(nodePointer header)
{
	nodePointer curr;
	nodePointer tmp;
	curr = header->rlink;
	tmp = header;

	while (curr != header)
	{
		tmp = curr;
		curr = curr->rlink;
		free(tmp);
	}
	free(header);
}