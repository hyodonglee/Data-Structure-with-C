#include<stdio.h>
#include<stdlib.h>
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int Mabangjin(int **arr, int n);
int Mabangjin2(int **arr, int n);

void main()
{
	FILE *fin = fopen("input.txt", "r");
	FILE *fout = fopen("output.txt", "w");

	int i, j, n;
	int **arr;

	fscanf(fin, "%d", &n);

	if (n % 4 != 0 && n % 2 == 0)
	{
		return;
	}

	arr = (int**)malloc(sizeof(int*)*n);

	for (i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(sizeof(int)*n);
	}

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			arr[i][j] = 0;

	if (n % 4 != 0)
		Mabangjin(arr, n);

	else if(n%4==0)
		Mabangjin2(arr, n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			fprintf(fout, "%-5d", arr[i][j]);
		fprintf(fout, "\n");
	}

	for (i = 0; i < n; i++)
		free(arr[i]);

	free(arr);
	fclose(fin);
	fclose(fout);
}

int Mabangjin(int **arr, int n)
{
	int i, j, count;
	int row, col;

	arr[0][(n - 1) / 2] = 1;

	i = 0;
	j = (n - 1) / 2;

	for (count = 2; count <= n*n; count++)
	{
		row = (i - 1 < 0) ? (n - 1) : (i - 1);
		col = (j - 1 < 0) ? (n - 1) : (j - 1);
		if (arr[row][col])
			i = (++i) % n;
		else {
			i = row;
			j = (j - 1 < 0) ? (n - 1) : --j;
		}
		arr[i][j] = count;
	}
}

int Mabangjin2(int **arr, int n)
{
	int num = 1;
	int cnt = n / 4;
	int i, j;
	int row;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			arr[i][j] = num;
			num++;
		}
	}
	for (row = 0; row < cnt; row++)
	{
		int col1 = n / 4;
		int col2 = n - n / 4 - 1;
		for (i = 0; i < n / 2; i++)
		{
			int tmp;
			swap(arr[row][col1], arr[n - 1 - row][col2], tmp);
			swap(arr[col1][row], arr[col2][n - 1 - row], tmp);
			col1++;
			col2--;
		}
	}
}