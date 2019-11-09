#include<stdio.h>
#include<stdlib.h>

int** arr;

int main()
{
	FILE* fin;
	FILE* fout;
	int i, j, n;
	int currRow, currCol;

	int cnt = 1;

	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	scanf("%d", &n);

	arr = (int**)malloc(sizeof(int*) * n);

	for (i = 0; i < n; i++)
		arr[i] = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			arr[i][j] = 0;

	//�켱 Ȧ���϶�����
	if (n % 2 == 1)
	{
		i = 0;
		j = (n - 1) / 2;

		while (cnt <= n * n)
		{
			arr[i][j] = cnt++;

			//������ǥi-1, j-1
			//������ǥ ����
			currRow = i;
			currCol = j;
			//���� ��ǥ�� �����ϴ��� Ȯ�� �� �̵�������
			if (i - 1 >= 0 && i - 1 < n)
				i = i - 1;
			else
				i = n - 1;

			if (j - 1 >= 0 && j - 1 < n)
				j = j - 1;
			else
				j = n - 1;
			//������ǥ�� ���� �����ϴ��� Ȯ��
			if (arr[i][j] > 0)
			{
				i = currRow + 1;
				j = currCol;
			}

		}


	}

	//4�� ��� �϶�
	else
	{
		cnt = 1;

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				if (i <= (n - 1) / 4 || i > 3 * (n - 1) / 4)
				{
					if (j <= (n - 1) / 4 || j > 3 * (n - 1) / 4)
						arr[i][j] = cnt;
					else
						arr[i][j] = n * n - cnt + 1;
				}

				else
				{
					if (j > (n - 1) / 4 && j <= 3 * (n - 1) / 4)
						arr[i][j] = cnt;
					else
						arr[i][j] = n * n - cnt + 1;
				}
				cnt++;
			}


	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%3d ", arr[i][j]);
		printf("\n");
	}

	for (i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
	return 0;
}