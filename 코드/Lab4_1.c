#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) ((x) < (y)? -1: ((x)==(y))? 0:1)

struct list{
	char name[10];
	int age;
};

int BinarySearch(int arr1[],int searchnum, int left, int right);

typedef struct list information;

void main()
{
	FILE *fin=fopen("input.txt","r");
	FILE *fout=fopen("output.txt","w");

	int n,m;
	information *arr;
	int i;
	
	int left,right;

	fscanf(fin,"%d %d", &n, &m);

	arr = (information*)malloc(sizeof(information)*n);

	for(i=0;i<n;i++)
		fscanf(fin,"%s %d",arr[i].name,&arr[i].age);

	left = 0;
	right = n-1;

	for(i=0;i<n;i++)
	{
		if(arr[i].age==m)
			{
				fprintf(fout,"%d %s",BinarySearch(arr,m,left,right),arr[i].name);
				return ;
			}

	}
	

	if(i==n)

	fprintf(fout,"-1");

	free(arr);
	fclose(fin);
	fclose(fout);
	
}

int BinarySearch(information *arr1,int searchnum, int left, int right)
{
	int middle;
	while(left<=right)
	{
		middle=(left+right)/2;
		switch(COMPARE(arr1[middle].age,searchnum))
		{
		case -1: left = middle+1;
				break;
		case 0: return middle+1;
		case 1: right = middle -1;
		}
	}
	return -1;
}