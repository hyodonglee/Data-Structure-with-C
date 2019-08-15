#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

FILE *fin;
FILE *fout;

typedef struct element{
	char data[25];
	int key;
}element;

element **table;
int stringToInt(char *key);
int hash(int num, int b);
void main()
{
	int n, i, b, s, m, j;
	char str[25];
	int IntStr;

	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d %d %d",&b,&s,&n);

	table = (element**)malloc(sizeof(element*)*b);
	for(i=0;i<b;i++)
	{
		table[i]=(element*)malloc(sizeof(element)*s);
		for(j=0;j<s;j++)
		{
			strcpy(table[i][j].data,"");
			table[i][j].key = 0;
		}
	}

	for(i=0;i<n;i++)
	{
		fscanf(fin,"%s",str);
		IntStr = stringToInt(str);
		IntStr = hash(IntStr,b);

		for(j=0;j<s;j++)
		{
			if(table[IntStr][j].key != 1)
			{
				strcpy(table[IntStr][j].data,str);
				table[IntStr][j].key = 1;
				break;
			}
			if(table[IntStr][s-1].key == 1)
			{
				fprintf(fout,"%s overflow\n",str);
				break;
			}
		}
	}

	fscanf(fin,"%d",&m);
	for(i=0;i<m;i++)
	{
		fscanf(fin,"%s",str);
		IntStr = stringToInt(str);
		IntStr = hash(IntStr,b);

		for(j=0;j<=s;j++)
		{
			if(j==s)
			{
				fprintf(fout,"false\n");
				break;
			}
			if(strcmp(table[IntStr][j].data,str)==0)
			{
				fprintf(fout,"true\n");
				break;
			}
		}
	}

	for(i=0;i<b;i++)
		free(table[i]);
	free(table);

	fclose(fin);
	fclose(fout);
}

int stringToInt(char *key)
{
	int number = 0;
	while(*key)
		number += *key++;
	return number;
}

int hash(int num, int b)
{
	return num%b;
}