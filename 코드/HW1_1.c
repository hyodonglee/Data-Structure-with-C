#include<stdio.h>
#include<stdlib.h>

struct inf {
	int num;
	char name[10];
	double score1;
	double score2;
	double total;
};
typedef struct inf inf;

void main()
{
	FILE *fin = fopen("input.txt", "r");
	FILE *fout = fopen("output.txt", "w");
	
	int i,n;
	inf *arr;

	fscanf(fin, "%d", &n);
	arr = (inf*)malloc(sizeof(inf)*n);

	for (i = 0; i < n; i++)
	{
		fscanf(fin, "%d %s %lf %lf", &arr[i].num, arr[i].name, &arr[i].score1, &arr[i].score2);
		arr[i].total = arr[i].score1 + arr[i].score2;
		fprintf(fout, "%d %s %.1lf %.1lf %.1lf\n", arr[i].num, arr[i].name, arr[i].score1, arr[i].score2, arr[i].total);
	}

	free(arr);
	fclose(fin);
	fclose(fout);
}