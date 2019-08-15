#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int *arr;
FILE * fin;
FILE *fout;

void main()
{
	int n, m, newN, i, j, k, index;
	int num;
	int start = 0;
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	fscanf(fin, "%d", &n);

	while (1)
	{
		if (pow(2, start) <= n && n<pow(2, start + 1))
		{
			newN = pow(2, start + 1);
			break;
		}
		else
			start++;
	}

	arr = (int*)malloc(sizeof(int)*newN);
	for (i = 1; i <= n; i++)
		fscanf(fin, "%d", &arr[i]);
	for (i = n + 1; i<newN; i++)
		arr[i] = -1;

	fscanf(fin, "%d", &m);
	for (j = 0; j<m; j++)
	{
		fscanf(fin, "%d", &k);
		if (2 * k <= newN)
			fprintf(fout, "%d %d\n", arr[2 * k], arr[2 * k + 1]);
		else
			fprintf(fout, "-1 -1\n");
	}
	free(arr);
	fclose(fin);
	fclose(fout);
}