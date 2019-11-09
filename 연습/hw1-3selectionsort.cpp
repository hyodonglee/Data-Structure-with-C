#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y,t) ((t)=(*x),(*x)=(*y),(*y)=(t))
/* 최소값을 아예 min에 따로 선택해서 임시 저장해둔다, 인덱스도 역시 따로 임시저장해둔다*/
int* arr;
FILE* fin;
FILE* fout;
void selectionSort(int n)
{
	int i, j, t;
	int min, index;
	for (i = 0; i < n - 1; i++)
	{
		min = 9999;
		for (j = i + 1; j < n; j++)
			if (min > arr[j])
			{
				min = arr[j];
				index = j;
			}
		SWAP(&arr[i], &arr[index], t);
	}
}

void makeArr(int n)
{
	int i;
	arr = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		fscanf(fin, "%d", &arr[i]);
}

int main()
{

	int n;
	int i, j;

	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	fscanf(fin, "%d", &n);

	makeArr(n);
	selectionSort(n);

	for (i = 0; i < n; i++)
		fprintf(fout, "%d ", arr[i]);
	free(arr);

	fclose(fin);
	fclose(fout);
}