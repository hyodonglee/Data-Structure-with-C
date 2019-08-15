#include<stdio.h>
#include<stdlib.h>
#define MAX 100

FILE *fin;
FILE *fout;

void print(int a[], int n);
void merge(int a[], int left, int mid, int right);
void merge_sort(int a[], int left, int right);
void main()
{
	int n, i;
	int a[MAX];
	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d",&n);
	
	for(i=0;i<n;i++)
		fscanf(fin,"%d",&a[i]);
	
	merge_sort(a,0,n-1);
	print(a,n);
	
	fclose(fin);
	fclose(fout);
}

void merge_sort(int a[], int left, int right)
{
	int mid;

	if (left < right) {
		mid = (left + right) / 2;

		merge_sort(a, left, mid); 
		merge_sort(a, mid + 1, right); 
		merge(a, left, mid, right);
	}
}

void merge(int a[], int left, int mid, int right)
{
	int i, j, k, m;
	int tmp[10];

	i = left;
	j = mid + 1;
	k = left; 

	while (i <= mid && j <= right) {
		if (a[i] < a[j]) { 
			tmp[k] = a[i];
			i++;
		}
		else { 
			tmp[k] = a[j];
			j++;
		}
		k++;
	}

	if (i > mid) {
		for (m = j; m <= right; m++) {
			tmp[k] = a[m];
			k++;
		}
	}
	else { 
		for (m = i; m <= mid; m++) {
			tmp[k] = a[m];
			k++;
		}
	}

	for (m = left; m <= right; m++) {
		a[m] = tmp[m];
	}
}
void print(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
		fprintf(fout,"%d ",a[i]);
}