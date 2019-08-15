#include<stdio.h>
#include<stdlib.h>


struct inf{
	int number;
	char name[10];
	double mid;
	double final;
	double score1;
	double score2;
	int attend;
	double total;
}student;


void main()
{
	FILE* fin = fopen("input.txt","r");
	FILE* fout = fopen("output.txt","w");

	int n;
	int i;
	struct inf *arr;

	fscanf(fin,"%d",&n);
	arr=(struct inf*)malloc(sizeof(struct inf)*n);

	for(i=0;i<n;i++)	
	{
		fscanf(fin,"%d %s %lf %lf %lf %lf %d", &arr[i].number, arr[i].name, &arr[i].mid,&arr[i].final,&arr[i].score1,&arr[i].score2,&arr[i].attend);

		arr[i].mid*=0.3;
		arr[i].final*=0.4;
		arr[i].score1*=0.1;
		arr[i].score2*=0.1;
		arr[i].total=arr[i].mid + arr[i].final + arr[i].score1 + arr[i].score2 + arr[i].attend;

		if(arr[i].total>=95)
			fprintf(fout,"%d %s %.1lf %.1lf %.1lf %.1lf %d %.1lf A+\n",arr[i].number,arr[i].name, arr[i].mid,arr[i].final,arr[i].score1,arr[i].score2,arr[i].attend,arr[i].total);
		else if(arr[i].total>=90 &&arr[i].total<95)
			fprintf(fout,"%d %s %.1lf %.1lf %.1lf %.1lf %d %.1lf A0\n",arr[i].number,arr[i].name, arr[i].mid,arr[i].final,arr[i].score1,arr[i].score2,arr[i].attend,arr[i].total);
		else if(arr[i].total>=85 &&arr[i].total<90)
			fprintf(fout,"%d %s %.1lf %.1lf %.1lf %.1lf %d %.1lf B+\n",arr[i].number,arr[i].name, arr[i].mid,arr[i].final,arr[i].score1,arr[i].score2,arr[i].attend,arr[i].total);
		else if(arr[i].total>=80 &&arr[i].total<85)
			fprintf(fout,"%d %s %.1lf %.1lf %.1lf %.1lf %d %.1lf B0\n",arr[i].number,arr[i].name, arr[i].mid,arr[i].final,arr[i].score1,arr[i].score2,arr[i].attend,arr[i].total);
		else if(arr[i].total>=75 &&arr[i].total<80)
			fprintf(fout,"%d %s %.1lf %.1lf %.1lf %.1lf %d %.1lf C+\n",arr[i].number,arr[i].name, arr[i].mid,arr[i].final,arr[i].score1,arr[i].score2,arr[i].attend,arr[i].total);
		else if(arr[i].total>=70 &&arr[i].total<75)
			fprintf(fout,"%d %s %.1lf %.1lf %.1lf %.1lf %d %.1lf C0\n",arr[i].number,arr[i].name, arr[i].mid,arr[i].final,arr[i].score1,arr[i].score2,arr[i].attend,arr[i].total);
		else if(arr[i].total>=65 &&arr[i].total<70)
			fprintf(fout,"%d %s %.1lf %.1lf %.1lf %.1lf %d %.1lf D+\n",arr[i].number,arr[i].name, arr[i].mid,arr[i].final,arr[i].score1,arr[i].score2,arr[i].attend,arr[i].total);
		else if(arr[i].total>=60 &&arr[i].total<65)
			fprintf(fout,"%d %s %.1lf %.1lf %.1lf %.1lf %d %.1lf D0\n",arr[i].number,arr[i].name, arr[i].mid,arr[i].final,arr[i].score1,arr[i].score2,arr[i].attend,arr[i].total);
		else if(arr[i].total<60)
			fprintf(fout,"%d %s %.1lf %.1lf %.1lf %.1lf %d %.1lf F\n",arr[i].number,arr[i].name, arr[i].mid,arr[i].final,arr[i].score1,arr[i].score2,arr[i].attend,arr[i].total);
	}

	free(arr);
	fclose(fout);
	fclose(fin);
}