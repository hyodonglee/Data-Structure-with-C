#include<stdio.h>
#include<stdlib.h>
#define MAX_COLS 101
#define MAX_ROWS 101
#define MAX_TERMS 101

struct term 
{
	int row;
	int col;
	int value;
};

typedef struct term term;


void main()
{
	FILE *fin=fopen("input.txt","r");
	FILE *fout=fopen("output.txt","w");

	int arr[MAX_ROWS][MAX_COLS];
	int n,m;
	int i,j;
	int total=0;
	int k=1;


	term a[MAX_TERMS];

	fscanf(fin, "%d",&n);
	fscanf(fin, "%d",&m);

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			fscanf(fin,"%d",&arr[i][j]);
	}

	a[0].row = n;
	a[0].col = m;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			if(arr[i][j]!=0)
				{
					a[k].row=i;
					a[k].col=j;
					a[k].value=arr[i][j];
					k++;
				}
	}
	total=k;

	a[0].value=total;

	for(i=1;i<total;i++)
		fprintf(fout,"%d %d %d\n",a[i].row,a[i].col,a[i].value);

	fclose(fin);
	fclose(fout);
}
