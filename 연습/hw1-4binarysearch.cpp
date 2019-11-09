#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y,t) ((t)=(*x),(*x)=(*y),(*y)=(t))
/* binarysearch*/
int* arr;
FILE* fin;
FILE* fout;

int BinarySearch(int n, int m)
{
	int i, j;
	int start=0, end=n-1;
	int mid;
	
	while (start<=end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == m)
			return mid+1;
		else if (arr[mid] < m)
			end = mid-1;
		else
			start = mid+1;
	}
	return -1;
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

	int n, m;
	int i, j;

	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	fscanf(fin, "%d", &n);
	fscanf(fin, "%d", &m);

	makeArr(n);
	
	fprintf(fout, "%d", BinarySearch(n, m));
	free(arr);

	fclose(fin);
	fclose(fout);
}