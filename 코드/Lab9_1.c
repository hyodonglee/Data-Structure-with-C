#include<stdio.h>
#include<stdlib.h>

struct list{
	int index;
	char data[10];
	int nextindex;
};

typedef struct list list;

FILE *fin;
FILE *fout;

void main()
{
	int n,m;
	int i,j;
	list inf[100];
	int tmp;

	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d %d", &n,&m);

	for(i=1;i<=n;i++)
		fscanf(fin, "%d %s %d", &inf[i].index,inf[i].data,&inf[i].nextindex);

	for(i=1;i<=n;i++)
	{
		if(inf[i].index==m)
		{
			fprintf(fout,"%s\n",inf[i].data);
			break;
		}
	}
	tmp = inf[i].nextindex;

	while(tmp!=0)
	{
		fprintf(fout,"%s\n",inf[tmp].data);
		tmp = inf[tmp].nextindex;
	}
	fclose(fin);
	fclose(fout);
}