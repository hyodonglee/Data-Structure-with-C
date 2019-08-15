#include<stdio.h>
#include<stdlib.h>

void sort(int *arr1, int n);

void main()
{
	FILE *fin=fopen("input.txt","rt");
	FILE *fout=fopen("ouput.txt","wt");

	int *arr1;
	int i,n;

	fscanf(fin,"%d",&n);

	arr1 = (int*)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
	{
		fscanf(fin,"%d",&arr1[i]);
	}

	sort(arr1,n);

	for(i=0;i<n;i++)
	{
		fprintf(fout,"%d\n",arr1[i]);
	}

	free(arr1);
	fclose(fin);
	fclose(fout);

}

void sort(int *arr1, int n)
{
	int i, j;
	int temp;

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
			if(arr1[j] < arr1[i])
			{
				temp = arr1[j];
				arr1[j]=arr1[i];
				arr1[i]=temp;
			}
	}
}