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

void fastTranspose(term a[],term b[]);

void main()
{
	FILE *fin=fopen("input.txt","r");
	FILE *fout=fopen("output.txt","w");

	int arr[MAX_ROWS][MAX_COLS];
	int n,m;
	int i,j;
	int total=0;
	int k=1;
	int rowTerms[MAX_COLS];
	int startingPos[MAX_COLS];

	term a[MAX_TERMS];
	term b[MAX_TERMS];

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
	total=k-1;

	a[0].value=total;

	fastTranspose(a,b,rowTerms,startingPos);

	for(i=1;i<total+1;i++)
		fprintf(fout,"%d %d %d\n",b[i].row,b[i].col,b[i].value);

	fclose(fin);
	fclose(fout);
}

void fastTranspose(term a[],term b[],int rowTerms[],int startingPos[])
{
	int i,j;
	int numCols = a[0].col, numTerms = a[0].value;
	b[0].row = numCols; b[0].col = a[0].row;
	b[0].value = numTerms;

	for(i=0;i<numCols;i++)
		rowTerms[i]=0;
	for(i=1;i<=numTerms;i++)
		rowTerms[a[i].col]++;
	startingPos[0]=1;
	for(i=1;i<numCols;i++)
		startingPos[i]=startingPos[i-1] + rowTerms[i-1];

	if(numTerms>0)
	{
		for(i=0;i<numCols;i++)
			rowTerms[i] = 0;
		for(i=1;i<=numTerms;i++)
			rowTerms[a[i].col]++;
		startingPos[0]=1;
		for(i=1;i<numCols;i++)
			startingPos[i]=startingPos[i-1] + rowTerms[i-1];
		for(i=1;i<=numTerms;i++)
		{
			j=startingPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}