#include<stdio.h>
#include<stdlib.h>

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;

FILE *fin;
FILE *fout;

listPointer append(int num, listPointer first);
void printList(listPointer first);
void freeList(listPointer first);
listPointer invert(listPointer lead);

void main()
{
	int i, n;
	int num;
	listPointer first;
	listPointer curr;
	listPointer middle;
	first = (listNode*)malloc(sizeof(listNode));
	first = NULL;

	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	fscanf(fin, "%d", &n);

	for (i = 0; i<n; i++)
	{
		fscanf(fin, "%d", &num);
		first = append(num, first);
	}

	//printList(first);
	middle = invert(first);
	printList(middle);
	freeList(middle);
	fclose(fin);
	fclose(fout);
}

listPointer append(int num, listPointer first)
{
	listPointer temp;
	listPointer curr;

	temp = (listNode*)malloc(sizeof(listNode));
	temp->data = num;
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
		fprintf(fout, "%d\n", curr->data);
		curr = curr->link;
	}
	fprintf(fout, "%d\n", curr->data);
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

listPointer invert(listPointer lead)
{
	listPointer middle, trail;
	middle = NULL;
	
	while (lead)
	{
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;
	}
	return middle;

}