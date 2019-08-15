#include<stdio.h>
#include<stdlib.h>

FILE *fin;
FILE *fout;

int **arr;

void main()
{
	int n, i, j, m;
	int num1,num2;
	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d",&n);
	fscanf(fin,"%d",&m);
	
	arr = (int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
		arr[i]=(int*)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			arr[i][j]=0;

	for(i=0;i<m;i++)
	{
		fscanf(fin,"%d %d",&num1,&num2);
		arr[num1][num2]=1;
		arr[num2][num1]=1;
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(arr[i][j] == 1) 
				fprintf(fout,"%d ",j);
		fprintf(fout,"\n");
	}
	
	for(i=0;i<n;i++)
		free(arr[i]);
	free(arr);
	fclose(fin);
	fclose(fout);
}