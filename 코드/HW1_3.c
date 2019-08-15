//¿Ã»øµø
#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

void selectionSort(int *arr, int n);

void main()
{
	FILE *fin = fopen("input.txt", "r");
	FILE *fout = fopen("output.txt", "w");

	int i, n;
	int *arr;

	fscanf(fin, "%d", &n);

	arr = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++)
		fscanf(fin, "%d", &arr[i]);

	selectionSort(arr, n);

	for (i = 0; i < n; i++)
		fprintf(fout, "%d\n", arr[i]);

	free(arr);
	fclose(fin);
	fclose(fout);
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