#include<stdio.h>
#include<stdlib.h>
#define MAX_COLS 101
#define MAX_ROWS 101
#define MAX_TERMS 101
#define COMPARE(x,y) (((x)<(y))? -1: (x)==(y)? 0:1)

struct term 
{
	int row;
	int col;
	int value;
};

typedef struct term term;

void fastTranspose(term a[],term b[]);
void mmult(term a[], term b[], term d[]);
void storeSum(term d[], int *totalD, int row, int column, int *sum);

void main()
{
	FILE *fin=fopen("input.txt","r");
	FILE *fout=fopen("output.txt","w");

	int arr[MAX_ROWS][MAX_COLS];
	int arr2[MAX_ROWS][MAX_COLS];
	int n,m;
	int x,y;
	int i,j;
	int total=0;
	int total2=0;
	int k=1;
	int p=1;

	term a[MAX_TERMS];
	term b[MAX_TERMS];
	term d[MAX_TERMS];

	//first
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
	a[0].value=total-1;


	//second
	fscanf(fin, "%d",&x);
	fscanf(fin, "%d",&y);

	if(m!=x)
	{
		fprintf(fout,"-1");
		fclose(fin);
		fclose(fout);
		return;
	}

	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
			fscanf(fin,"%d",&arr2[i][j]);
	}

	b[0].row = x;
	b[0].col = y;

	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
			if(arr2[i][j]!=0)
			{
				b[p].row=i;
				b[p].col=j;
				b[p].value=arr2[i][j];
				p++;
			}
	}
	total2=p;
	b[0].value=total2-1;

	mmult(a,b,d);

	for(i=1;i<=d[0].value;i++)
		fprintf(fout,"%d %d %d\n",d[i].row,d[i].col,d[i].value);

	fclose(fin);
	fclose(fout);
}

void mmult(term a[], term b[], term d[])
{
	int i,j,column,totalB=b[0].value, totalD=0;
	int rowsA=a[0].row, colsA = a[0].col,
		totalA=a[0].value; 
	int colsB = b[0].col;
	int rowBegin = 1, row = a[1].row, sum=0;
	term newB[MAX_TERMS];

	fastTranspose(b,newB);
	a[totalA+1].row =rowsA;
	newB[totalB+1].row = colsB;
	newB[totalB+1].col = 0;
	for(i=1;i<=totalA;)
	{
		column = newB[1].row;
		for(j=1;j<totalB+1;)
		{
			if(a[i].row != row){
				storeSum(d,&totalD,row,column,&sum);
				i=rowBegin;
				for(;newB[j].row == column;j++);
				column = newB[j].row;
			}
			else if (newB[j].row != column)
			{
				storeSum(d,&totalD,row,column,&sum);
				i = rowBegin;
				column=newB[j].row;
			}
			else switch (COMPARE(a[i].col,newB[j].col))
			{
			case -1: i++;break;
			case 0:
				sum+=(a[i++].value*newB[j++].value);
				break;
			case 1:j++;
			}
		}
		if(j>=totalB+1)
			storeSum(d,&totalD,row,column,&sum);

		for(;a[i].row == row;i++);
		rowBegin = i; row = a[i].row;
	}
	d[0].row = rowsA;
	d[0].col = colsB;
	d[0].value = totalD;
}

void storeSum(term d[], int *totalD, int row, int column, int *sum)
{
	if(*sum)
		if(*totalD < MAX_TERMS)
		{
			d[++*totalD].row = row;
			d[*totalD].col = column;
			d[*totalD].value = *sum;
			*sum=0;
		}
}

void fastTranspose(term a[],term b[])
{
	int rowTerms[MAX_COLS]; 
	int startingPos[MAX_COLS];
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