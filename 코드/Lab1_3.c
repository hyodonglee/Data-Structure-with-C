#include<stdio.h>
#include<stdlib.h>


struct std{
	int number;
	char name[10];
	int score1;
	int score2;
	int score3;
}std;


void main()
{
	FILE* fin=fopen("input.txt","r");
	FILE* fout=fopen("output.txt","w");

	
	int n;
	int i,j,k;
	struct std *arr;

	fscanf(fin,"%d",&n);

	arr=(struct std*)malloc(sizeof(struct std)*n);


	for(i=0;i<n;i++)
	{
		fscanf(fin,"%d %s %d %d %d", &arr[i].number,arr[i].name,&arr[i].score1,&arr[i].score2,&arr[i].score3);
	}

	for(i=0;i<n;i++)
	fprintf(fout,"%d %s %d %d %d\n", arr[i].number,arr[i].name,arr[i].score1,arr[i].score2,arr[i].score3);

	free(arr);
	fclose(fin);
	fclose(fout);

}