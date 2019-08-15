#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) ((x) < (y)? -1: ((x)==(y))? 0:1)

void sort(int *arr1, int n);
int BinarySearch(int arr1[],int searchnum, int left, int right);


void main()
{
	FILE *fin=fopen("input.txt","rt");
	FILE *fout=fopen("ouput.txt","wt");

	int *arr1;
	int i,n,m;
	int left,right;

	fscanf(fin,"%d",&n);
	fscanf(fin,"%d",&m);

	arr1 = (int*)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
	{
		fscanf(fin,"%d",&arr1[i]);
	}

	sort(arr1,n);

	left=0;
	right=n-1;

	for(i=0;i<n;i++)
	{
		fprintf(fout,"%d ",arr1[i]);
	}

	fprintf(fout,"\n");
	fprintf(fout,"%d\n",BinarySearch(arr1,m,left,right));

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

int BinarySearch(int arr1[],int searchnum, int left, int right)
{
	int middle;
	while(left<=right)
	{
		middle=(left+right)/2;
		switch(COMPARE(arr1[middle],searchnum))
		{
		case -1: left = middle+1;
				break;
		case 0: return middle+1;
		case 1: right = middle -1;
		}
	}
	return -1;
}