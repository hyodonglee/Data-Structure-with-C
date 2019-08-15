#include<stdio.h>
#include<stdlib.h>

void swap(int *arr1, int *arr2, int n);

void main()
{
	FILE *fin=fopen("input.txt","r");
	FILE *fout=fopen("ouput.txt","w");

	int *arr1;
	int *arr2;
	int n;
	int i,j;

	fscanf(fin,"%d",&n);

	arr1 = (int*)malloc(sizeof(int)*n);
	arr2 = (int*)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
	{
		fscanf(fin,"%d",&arr1[i]);
	}
	for(i=0;i<n;i++)
	{
		fscanf(fin,"%d",&arr2[i]);
	}

	swap(arr1,arr2,n);

	for(i=0;i<n;i++)
	{
		fprintf(fout,"%d ",arr1[i]);
	}

	fprintf(fout,"\n");

	for(i=0;i<n;i++)
	{
		fprintf(fout,"%d ",arr2[i]);
	}


	free(arr1);
	free(arr2);
	fclose(fin);
	fclose(fout);
}

void swap(int *arr1, int *arr2, int n)
{
	int temp;
	int i;

	for(i=0;i<n;i++)
	{
		temp=arr1[i];
		arr1[i]=arr2[i];
		arr2[i]=temp;
	}
}


