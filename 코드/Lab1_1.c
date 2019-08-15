#include<stdio.h>
#include<stdlib.h>

void main()
{
	FILE* fin=fopen("input.txt","r");
	FILE* fout=fopen("output.txt","w");

	
	int n;
	int i,j=0;

	fscanf(fin,"%d",&n);

	for(i=0;i<=n;i++)
		j+=i;

	fprintf(fout,"%d",j);

	fclose(fin);
	fclose(fout);

}