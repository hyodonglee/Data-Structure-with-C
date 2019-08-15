#include <stdio.h>
#include <stdlib.h>
#define MAX 24
#define FALSE 0
#define TRUE 1
typedef struct node *nodePointer;
typedef struct node {
	int data;
	nodePointer link;
};

FILE *fin;
FILE *fout;

void main()
{
	int out[MAX];
	nodePointer seq[MAX];
	nodePointer x, y, top;
	int i, j, n, m, k;

	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	fscanf(fin, "%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		out[i] = TRUE;
		seq[i] = NULL;
	}
	
	for (i = 0; i < m;)
	{
		fscanf(fin, "%d %d", &i, &j);
		x = (nodePointer*)malloc(sizeof(nodePointer));
		x->data = j; x->link = seq[i]; seq[i] = x;
		x = (nodePointer*)malloc(sizeof(nodePointer));
		x->data = i; x->link = seq[j]; seq[j] = x;
	}

	for (i = 0; i < n;i++)
	{
		if (out[i])
		{
			fprintf(fout, "\n%d ", i);
			out[i] = FALSE;
			x = seq[i]; top = NULL;
			for (;;)
			{
				while (x)
				{
					j = x->data;
					if (out[j])
					{
						fprintf(fout, "%d ", j);
						out[j] = FALSE;
						y = x->link; x->link = top; top = x; x = y;
					}
					else x = x->link;
				}
				if (!top) break;
				x = seq[top->data]; top = top->link;
			}
		}
	}
	fclose(fin);
	fclose(fout);
}

