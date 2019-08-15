#include<stdio.h>
#include<stdlib.h>

void main()
{
	FILE* fin = fopen("input.txt","r");
	FILE* fout = fopen("output.txt","w");

	int n;
	int i;
	int a,b;
	int *arr;

	fscanf(fin,"%d", &n);
	fscanf(fin,"%d %d", &a,&b);


	arr = (int*)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
		fscanf(fin, "%d",&arr[i]);

	for(i=a-1;i<b;i++)
		fprintf(fout,"%d ",arr[i]);

	free(arr);
	fclose(fin);
	fclose(fout);
}
	