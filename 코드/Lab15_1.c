#include<stdio.h>
#include<stdlib.h>
#define MAX 200
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
typedef struct{
	int key;
}element;

element heap[MAX];

FILE *fin;
FILE *fout;

void adjust(element a[], int root, int n);
void heapSort(element a[], int n);
void InOrder(int cnt, int n);
void main()
{
	int i, cnt;

	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");
	fscanf(fin, "%d", &cnt);
	for (i = 1; i <= cnt; i++)
		fscanf(fin, "%d", &heap[i].key);

	heapSort(heap, cnt);
	InOrder(1,cnt);
	fclose(fin);
	fclose(fout);
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
	rootkey = a[root].key;
	child = 2 * root;
	while (child <= n)
	{
		if ((child < n) && (a[child].key < a[child + 1].key))
			child++;
		if (rootkey > a[child].key)
			break;
		else
		{
			a[child / 2] = a[child];
			child *= 2;
		}
	}
	a[child / 2] = temp;
}

void InOrder(int cnt, int n)
{
	if (cnt > n)
		return;
	InOrder(2 * cnt, n);
	if (heap[cnt].key != -1)
		fprintf(fout, "%d ", heap[cnt].key);
	InOrder(2 * cnt + 1, n);
}