#include<stdio.h>
#include<stdlib.h>

void main()
{
	FILE* fin=fopen("input.txt","r");
	FILE* fout=fopen("output.txt","w");

	
	int n;
	int i,j,k;
	int **D1;
	int **D2;
	int **a;

	fscanf(fin,"%d",&n);

	D1=(int**)malloc(sizeof(int*)*n);
	D2=(int**)malloc(sizeof(int*)*n);
	a=(int**)malloc(sizeof(int*)*n);

	for(i=0;i<n;i++)
		{
			D1[i]=(int*)malloc(sizeof(int)*n);
			D2[i]=(int*)malloc(sizeof(int)*n);
			a[i]=(int*)malloc(sizeof(int)*n);
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			fscanf(fin,"%d",&D1[i][j]);
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			fscanf(fin,"%d",&D2[i][j]);
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			a[i][j]=0;
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				a[i][j]+=D1[i][k]*D2[k][j];
			}
		}
	}

	for(i=0;i<n;i++)
	fprintf(fout,"%d %d %d\n",a[i][0],a[i][1],a[i][2]);
		for(i=0;i<n;i++)
		{
			free(D1[i]);
			free(D2[i]);
			free(a[i]);

		
	}
	free(a);
	free(D1);
	free(D2);

	fclose(fin);
	fclose(fout);

}