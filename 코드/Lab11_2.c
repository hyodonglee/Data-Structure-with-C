#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) ((x) < (y)? -1: ((x)==(y))? 0:1)

typedef struct listNode* listPointer;
typedef struct listNode {
	int cof;
	int exp;
	listPointer link;
}listNode;

FILE *fin;
FILE *fout;

listPointer append(int co, int ex, listPointer first);
void printList(listPointer first);
void freeList(listPointer first);
listPointer invert(listPointer lead);
listPointer padd(listPointer firstA, listPointer firstB, listPointer firstD);

void main()
{
	int i, n, m;
	int co, ex;
	int num;
	listPointer firstA;
	listPointer currA;
	listPointer firstB;
	listPointer currB;
	listPointer firstD;
	firstA = (listNode*)malloc(sizeof(listNode));
	firstA = NULL;
	firstB = (listNode*)malloc(sizeof(listNode));
	firstB = NULL;
	firstD = (listNode*)malloc(sizeof(listNode));
	firstD = NULL;

	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	fscanf(fin, "%d", &n);

	for (i = 0; i<n; i++)
	{
		fscanf(fin, "%d %d", &co, &ex);
		firstA = append(co, ex, firstA);
	}
	//A½Ä

	fscanf(fin, "%d", &m);

	for (i = 0; i<m; i++)
	{
		fscanf(fin, "%d %d", &co, &ex);
		firstB = append(co, ex, firstB);
	}
	//B½Ä
	firstD = padd(firstA, firstB, firstD);

	//printList(firstA);
	//printList(firstB);
	printList(firstD);
	freeList(firstA);
	freeList(firstB);
	freeList(firstD);
	fclose(fin);
	fclose(fout);
}

listPointer append(int co, int ex, listPointer first)
{
	listPointer temp;
	listPointer curr;

	temp = (listNode*)malloc(sizeof(listNode));
	temp->cof = co;
	temp->exp = ex;
	temp->link = NULL;

	if (!first)
	{
		first = temp;
		return first;
	}
	else
	{
		curr = first;
		while (curr->link)
		{
			curr = curr->link;
		}
		curr->link = temp;
	}
	return first;
}

void printList(listPointer first)
{
	listPointer curr;

	curr = first;

	while (curr->link)
	{
		fprintf(fout, "%d %d\n", curr->cof, curr->exp);
		curr = curr->link;
	}
	fprintf(fout, "%d %d\n", curr->cof, curr->exp);
}

void freeList(listPointer first)
{
	listPointer curr;
	listPointer temp;

	curr = first;

	while (curr->link)
	{
		temp = curr;
		curr = curr->link;
		free(temp);
	}
	free(curr);
}

listPointer padd(listPointer firstA, listPointer firstB, listPointer firstD)
{
	int cof;
	listPointer currA;
	listPointer currB;

	currA = firstA;
	currB = firstB;

	while (currA != NULL && currB != NULL)
	{
		switch (COMPARE(currA->exp, currB->exp))
		{
		case -1:
			firstD = append(currB->cof, currB->exp, firstD);
			currB = currB->link;
			break;

		case 0:
			cof = currA->cof + currB->cof;
			if (cof)
				firstD = append(cof, currA->exp, firstD);
			currA = currA->link;
			currB = currB->link;
			break;

		case 1:
			firstD = append(currA->cof, currA->exp, firstD);
			currA = currA->link;
		}
	}
	while (currA != NULL)
	{
		firstD = append(currA->cof, currA->exp, firstD);
		currA = currA->link;
	}
		
	while (currB != NULL)
	{
		firstD = append(currB->cof, currB->exp, firstD);
		currB = currB->link;
	}
	return firstD;
}