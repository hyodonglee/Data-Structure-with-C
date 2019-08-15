#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) (((x)<(y))? -1:((x)==(y))? 0:1 )
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int BinSearch(int *arr, int searchnum, int left, int right);
void selectionSort(int *arr, int n);

void main()
{
	FILE *fin = fopen("input.txt", "r");
	FILE *fout = fopen("output.txt", "w");

	int n, m;
	int i;
	int *arr;
	int left = 0;

	fscanf(fin, "%d %d", &n, &m);

	int right = n - 1;

	arr = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++)
		fscanf(fin, "%d", &arr[i]);

	selectionSort(arr, n);

	for (i = 0; i < n; i++)
		fprintf(fout, "%d ", arr[i]);
	fprintf(fout, "\n");

	fprintf(fout, "%d", BinSearch(arr, m, left, right));

	free(arr);
	fclose(fin);
	fclose(fout);
}

int BinSearch(int *arr, int searchnum, int left, int right)
{
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		switch (COMPARE(searchnum, arr[mid]))
		{
		case -1: {
			left = mid + 1;
			break;
		}
		case 0: return mid + 1;
		case 1: right = mid - 1;
		}
	}
	return -1;
}

void selectionSort(int *arr, int n)
{
	int i, j, t;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i; j < n; j++)
			if (arr[i] < arr[j])
				SWAP(arr[i], arr[j], t);
	}
}
