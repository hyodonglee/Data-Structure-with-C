#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int key;
}element;

FILE *fin;
FILE *fout;

element *a;

void print(element a[], int n);
void insert(element e, element a[], int i);
void insertionSort(element a[], int n);
void main()
{
	int n, i;
	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d",&n);
	a = (struct node*)malloc(sizeof(element)*(n+1));

	for(i=1;i<=n;i++)
		fscanf(fin,"%d",&a[i].key);
	
	insertionSort(a,n);
	print(a,n);
	
	free(a);
	fclose(fin);
	fclose(fout);
}

void insertionSort(element a[], int n)
{
	int j;
	for(j=2;j<=n;j++)
	{
		element temp = a[j];
		insert(temp,a,j-1);
	}
}

void insert(element e, element a[], int i)
{
	a[0]=e;
	while(e.key<a[i].key)
	{
		a[i+1] = a[i];
		i--;
	}
	a[i+1]=e;
}

void print(element a[], int n)
{
	int i;
	for(i=1;i<=n;i++)
		fprintf(fout,"%d ",a[i].key);
}