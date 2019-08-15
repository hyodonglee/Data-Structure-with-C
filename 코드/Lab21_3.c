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
	int n, i, b, m, j;
	char str[25];
	int flag = 0;
	int check = 0;
	int IntStr;

	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d %d",&b,&n);

	table = (element**)malloc(sizeof(element*)*b);
	for(i=0;i<b;i++)
	{
		table[i]=(element*)malloc(sizeof(element));
		strcpy(table[i][0].data,"");
		table[i][0].key = 0;
	}

	for(i=0;i<n;i++)
	{
		fscanf(fin,"%s",str);
		IntStr = stringToInt(str);
		IntStr = hash(IntStr,b);


		if(flag >= b)
			fprintf(fout,"%s overflow\n",str);
		else
		{
			for(j=IntStr;j<b;j++)
			{
				if(table[j][0].key == 0)
				{
					strcpy(table[j][0].data,str);
					table[j][0].key = 1;
					flag++;
					break;
				}
			}

			if(j==b)
			{
				for(j=0;j<IntStr;j++)
					if(table[j][0].key == 0)
					{
						strcpy(table[j][0].data,str);
						table[j][0].key = 1;
						flag++;
						break;
					}
			}
		}

	}

	fscanf(fin,"%d",&m);
	flag = 0;
	for(i=0;i<m;i++)
	{
		fscanf(fin,"%s",str);
		IntStr = stringToInt(str);
		IntStr = hash(IntStr,b);
		check = 0;

		for(j=IntStr;j<b;j++)
			if(strcmp(table[j][0].data,str)==0)
				{
					fprintf(fout,"%d %d\n",IntStr,j);
					check = 1;
					break;
				}

		if(j==b)
		for(j=0;j<IntStr;j++)
			if(strcmp(table[j][0].data,str)==0)
				{
					fprintf(fout,"%d %d\n",IntStr,j);
					check = 1;
					break;
				}
			if(check==0){
				flag=1;
			}

			
		if(flag == 1)
			{
				fprintf(fout,"%d %d\n",IntStr,-1);
				flag = 0;
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