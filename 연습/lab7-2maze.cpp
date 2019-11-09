#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
/*stack*/

FILE * fin;
FILE* fout;

typedef struct direction
{
	int currX;
	int currY;
}direction;

int map[25][25];
int visited[25][25];
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int top = -1;
direction stack[MAX];
int cnt = 0;
direction arr[MAX];

void push(int X, int Y)
{
	stack[++top].currX = X;
	stack[top].currY = Y;
}

direction pop()
{
	return stack[top--];
}

int findDir(int n, int m, int startX, int startY)
{
	int nextX, nextY;
	int i, j;
	int currX = startX;
	int currY = startY;
	direction dir;
	if (map[startX][startY] == 1)
		return -1;

	push(currX, currY);
	visited[currX][currY] = 1;

	while (top > -1)
	{
		dir = pop();
		arr[cnt++] = dir;
		currX = dir.currX;
		currY = dir.currY;
		if (currX == n && currY == m)
			return 1;
		if ((currX <= n && currY <= m))
		{
			for (i = 0; i < 8; i++)
			{
				nextX = currX + dx[i];
				nextY = currY + dy[i];

				if ((nextX > 0 && nextX <= n) && (nextY > 0 && nextY <= m))
				{
					if (visited[nextX][nextY] == 0 && map[nextX][nextY]==0)
					{
						push(nextX, nextY);
						visited[nextX][nextY] = 1;
					}
				}
			}
		}
	}

}

void makeMap(int n, int m)
{
	int i, j, tmp;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			fscanf(fin, "%d", &tmp);
			map[i][j] = tmp;
			visited[i][j] = tmp;
		}
}

void printMap(int n, int m)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
			printf("%d", map[i][j]);
		printf("\n");
	}
}

int main()
{

	int n, m;
	int i, j;
	int startX, startY;
	int result;
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	fscanf(fin, "%d %d", &n, &m);
	for (i = 0; i <= n + 1; i++)
	{
		for (j = 0; j <= m + 1; j++)
			visited[i][j] = 1;
	}
	makeMap(n, m);
	printMap(n, m);
	fscanf(fin, "%d %d", &startX, &startY);

	if (findDir(n, m, startX, startY) == 1)
	{
		printf("%d\n", cnt);
		for (i = 0; i < cnt; i++)
			printf("%d %d\n", arr[i].currX, arr[i].currY);
	}
	else
		printf("-1");
	fclose(fin);
	fclose(fout);
}