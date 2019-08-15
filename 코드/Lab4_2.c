#include<stdio.h>
#include<stdlib.h>

struct list{
	char name[10];
	int age;
	double score;
};
typedef struct list list;

void sort(list *arr, int n);
void sort2(list *arr, int n);

void main()
{
	FILE *fin=fopen("input.txt","r");
	FILE *fout=fopen("output.txt","w");

	int n;
	list *arr;

	int i;


	fscanf(fin,"%d", &n);

	arr=(list*)malloc(sizeof(list)*n);


	for(i=0;i<n;i++)
		{
			fscanf(fin,"%s %d %lf",arr[i].name,&arr[i].age,&arr[i].score);
		}

	sort(arr,n);

	for(i=0;i<n;i++)
		{
			fprintf(fout,"%s %d %.1lf\n",arr[i].name,arr[i].age,arr[i].score);	
	}

	fprintf(fout,"\n");

	sort2(arr,n);

	for(i=0;i<n;i++)
		{
			fprintf(fout,"%s %d %.1lf\n",arr[i].name,arr[i].age,arr[i].score);
	}

	free(arr);
	fclose(fin);
	fclose(fout);
}

void sort(list *arr, int n)
{
	int i, j;
	list tmp;

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
			if(arr[j].age > arr[i].age)
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i]=tmp;
			}
	}
}

void sort2(list *arr, int n)
{
	int i, j;
	list tmp;

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
			if(arr[j].score > arr[i].score)
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i]=tmp;
			}
	}
}
