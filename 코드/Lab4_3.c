#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) ((x) < (y)? -1: ((x)==(y))? 0:1)

struct list{
	float cof;
	int exp;
};

int avail;

typedef struct list list;

void attach(float cof, int exp, list *arr)
{
	arr[avail].cof=cof;
	arr[avail++].exp=exp;
}

void padd(int startA,int finishA,int startB,int finishB,int *startD,int *finishD, list *arr)
{
	float cof;
	*startD = avail;
	
	while(startA <=finishA && startB <= finishB){
		switch(COMPARE(arr[startA].exp,arr[startB].exp)){
		case -1 :
			attach(arr[startB].cof,arr[startB].exp,arr);
			startB++;
			break;

		case 0 :
			cof = arr[startA].cof + arr[startB].cof;
			if(cof)
				attach(cof,arr[startA].exp,arr);
			startA++;
			startB++;
			break;

		case 1: 
			attach(arr[startA].cof,arr[startA].exp,arr);
			startA++;
	}
	}
	for(;startA<=finishA; startA++)
		attach(arr[startA].cof,arr[startA].exp,arr);
	for(;startB<=finishB; startB++)
		attach(arr[startB].cof,arr[startB].exp,arr);
	*finishD = avail-1;

}


void main()
{
	FILE *fin=fopen("input.txt","r+");
	FILE *fout=fopen("output.txt","w+");

	int n,m;
	list arr[100];

	int startD, finishD;
	int i;
	int startA,finishA,startB,finishB;

	fscanf(fin,"%d", &n);



	for(i=0;i<n;i++)
		{
			fscanf(fin,"%f %d",&arr[i].cof,&arr[i].exp);
		}


	fscanf(fin,"%d", &m);


	for(i=n;i<m+n;i++)
		{
			fscanf(fin,"%f %d",&arr[i].cof,&arr[i].exp);
		}

	startA=0;
	finishA=n-1;
	startB=n;
	finishB=n+m-1;
	avail = n+m;
	


	padd(startA,finishA,startB,finishB, &startD, &finishD, arr);
	
	for(i = startD;i < finishD+1;i++)
		{
			fprintf(fout,"%.f %d\n",arr[i].cof,arr[i].exp);
		}


	fclose(fin);
	fclose(fout);
}

