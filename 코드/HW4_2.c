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
void josephus(int m, listPointer first);

void main()
{
	int i, n, m;
	listPointer first;
	listPointer curr;
	first = (listNode*)malloc(sizeof(listNode));
	first = NULL;

	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	fscanf(fin, "%d %d", &n, &m);

	first = append(n, first);
	//append

	curr = first;
	josephus(m, first);

	fclose(fin);
	fclose(fout);
}

listPointer append(int num, listPointer first)
{
	listPointer temp;
	listPointer curr;
	int i;
	for (i = 0; i < num; i++)
	{
		temp = (listNode*)malloc(sizeof(listNode));
		if (!first)
		{
			temp->data = i + 1;
			temp->link = NULL;
			first = temp;
			curr = first;
		}
		else
		{
			temp->data = i + 1;
			temp->link = NULL;
			curr->link = temp;
			curr = temp;
		}
	}
	temp->link = first;
	return first;
}

void josephus(int m, listPointer first)
{
	listPointer temp = first;
	listPointer curr = first;
	int i = 0;
	int cnt = 0;
	fprintf(fout, "<");

	while (temp != temp->link)
	{
		if (cnt == 0)
		{
			for (i = 0; i < m - 2; i++)
			{
				temp = temp->link;
				curr = temp->link;
				cnt++;
			}
			temp->link = curr->link;
			fprintf(fout, "%d", curr->data);
		}
		else
		{
			for (i = 0; i < m - 1; i++)
			{
				temp = temp->link;
				curr = temp->link;
			}
			temp->link = curr->link;
			fprintf(fout, ", %d", curr->data);
		}
		free(curr);
	}
	fprintf(fout, ", %d", temp->data);
	fprintf(fout, ">");
	free(temp);
}

