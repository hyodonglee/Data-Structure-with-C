#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
FILE *fin;
FILE *fout;

typedef struct node{
	int key;
}element;

element *a;

void print(element a[], int n);
void quickSort(element a[], int left, int right);
void main()
{
	int n, i;
	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d",&n);
	a = (struct node*)malloc(sizeof(element)*(n+1));

	for(i=1;i<=n;i++)
		fscanf(fin,"%d",&a[i].key);
	
	quickSort(a,1,n);
	print(a,n);
	
	free(a);
	fclose(fin);
	fclose(fout);
}

void quickSort(element a[], int left, int right)
{
	int pivot, i, j;
	element temp;
	if(left<right)
	{
		i = left; j = right +1;
		pivot = a[left].key;
		do{
			do i++;while(a[i].key<pivot);
			do j--;while(a[j].key>pivot);
			if(i<j)SWAP(a[i],a[j],temp);
		}while(i<j);
		SWAP(a[left],a[j],temp);
		quickSort(a,left,j-1);
		quickSort(a,j+1,right);
	}
}

void print(element a[], int n)
{
	int i;
	for(i=1;i<=n;i++)
		fprintf(fout,"%d ",a[i].key);
}