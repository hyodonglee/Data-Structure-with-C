#include<stdio.h>
#include<stdlib.h>

void main()
{
	FILE* fin = fopen("input.txt","r");
	FILE* fout = fopen("output.txt","w");

	int n,m;
	int i,j,s;
	int k;
	int **arr1;
	int **arr2;
	int a,b,c,d;
	int temp=0;

	fscanf(fin,"%d %d", &n,&m);

	arr1=(int**)malloc(sizeof(int*)*n);


	for(i=0;i<n;i++)
	{
		arr1[i]=(int*)malloc(sizeof(int)*m);	
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			fscanf(fin,"%d",&arr1[i][j]);
	}

	fscanf(fin,"%d",&k);

	fscanf(fin, "%d %d %d %d",&a,&b,&c,&d);

	for(s=0;s<k;s++)
	{
		for(i=a-1;i<c;i++)
		{
			for(j=b-1;j<d;j++)
				temp+=arr1[i][j];
		}

		fprintf(fout,"%d\n",temp);
		temp=0;
		fscanf(fin, "%d %d %d %d",&a,&b,&c,&d);
	}

	for(i=0;i<n;i++)
	{
		free(arr1[i]);
	}
	free(arr1);
	fclose(fin);
	fclose(fout);

}