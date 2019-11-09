#include<stdio.h>
#include<stdlib.h>
#define SWAP(x,y,t) ((t)=(*x),(*x)=(*y),(*y)=(t))
/*polynomial*/

typedef struct Node {
	int cof;
	int exp;
}Node;

FILE* fin;
FILE* fout;
Node* arr;


void polynomial(int startA, int finishA, int startB, int finishB, int startD, int *finishD)
{
	int avail = startD;
	while (1)
	{
		if (startA == startB || startB == startD)
			break;

		if (arr[startA].exp > arr[startB].exp)
		{
			arr = (Node*)realloc(arr, sizeof(Node) * (avail + 1));
			arr[avail++] = arr[startA++];
		}
		else if (arr[startA].exp < arr[startB].exp)
		{
			arr = (Node*)realloc(arr, sizeof(Node) * (avail + 1));
			arr[avail++] = arr[startB++];
		}
		else
		{
			arr = (Node*)realloc(arr, sizeof(Node) * (avail + 1));
			arr[avail].cof = arr[startA].cof + arr[startB].cof;
			arr[avail++].exp = arr[startA++].exp;
			startB++;
		}
	}

	for (; startA <= finishA; startA++)
	{
		arr = (Node*)realloc(arr, sizeof(Node) * (avail + 1));
		arr[avail++] = arr[startA++];
	}
	for (; startB <= finishB; startB++)
	{
		arr = (Node*)realloc(arr, sizeof(Node) * (avail + 1));
		arr[avail++] = arr[startB++];
	}
	*finishD = avail-1;
}
void printArr(int start, int end, Node *arr)
{
	int i;

	for (i = start; i <= end; i++)
	{
		if(arr[i].cof!=0)
			printf("cof : %d exp : %d\n", arr[i].cof, arr[i].exp);
	}

}
int main()
{

	int n, m;
	int i, j;
	int startA, startB, finishA, finishB, startD;
	int finishD;


	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	fscanf(fin, "%d", &n);
	startA = 0;
	finishA = n - 1;

	arr = (Node*)malloc(sizeof(Node) * n);
	for (i = startA; i <=finishA; i++)
		fscanf(fin, "%d %d", &arr[i].cof, &arr[i].exp);

	
	fscanf(fin, "%d", &m);
	arr = (Node*)realloc(arr, sizeof(Node) * (n + m));

	startB = finishA + 1;
	finishB = startB + m-1;
	for (i = startB; i <= finishB; i++)
		fscanf(fin, "%d %d", &arr[i].cof, &arr[i].exp);

	startD = n + m ;
	finishD = n + m - 1;
	polynomial(startA,finishA,startB,finishB,startD,&finishD);
	printArr(startD, finishD, arr);
	free(arr);

	fclose(fin);
	fclose(fout);
}