#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
#define N 0
#define NE 1
#define E 2
#define SE 3
#define S 4
#define SW 5
#define W 6
#define NW 7

typedef struct{
	int row;
	int col;
	int dir;
}element;

typedef struct{
	int vert;
	int horiz;
}offsets;

offsets move[8];

int maze[MAX][MAX];
int mark[MAX][MAX];

element pop();
element stack[100];

int top = -1;

void push(element position);
int path(int exitRow, int exitCol);

void main()
{
	FILE *fin = fopen("input.txt", "r");
	FILE *fout = fopen("output.txt", "w");

	int i, j, n, m;
	int item;
	int exitRow, exitCol;

	move[N].vert = -1;
	move[N].horiz = 0;
	move[NE].vert = -1;
	move[NE].horiz = 1;
	move[E].vert = 0;
	move[E].horiz = 1;
	move[SE].vert = 1;
	move[SE].horiz = 1;
	move[S].vert = 1;
	move[S].horiz = 0;
	move[SW].vert = 1;
	move[SW].horiz = -1;
	move[W].vert = 0;
	move[W].horiz = -1;
	move[NW].vert = -1;
	move[NW].horiz = -1;

	fscanf(fin, "%d", &n);
	fscanf(fin, "%d", &m);

	exitRow =n;
	exitCol =m;

	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=m+1;j++)
		{
			maze[i][j]=1;
			mark[i][j]=0;
		}
	}

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			fscanf(fin,"%d",&maze[i][j]);
		}
	}

	if(path(exitRow, exitCol)==1)
	{
		fprintf(fout,"%d\n",top+3);
		for(i=0;i<=top+1;i++)
			fprintf(fout,"%d %d\n",stack[i].row, stack[i].col);

		fprintf(fout,"%d %d\n", exitRow,exitCol);
	}
	else
		fprintf(fout,"-1");

	fclose(fin);
	fclose(fout);
}

void push(element position)
{
	stack[++top] = position;
}

element pop()
{
	return stack[top--];
}

int path(int exitRow, int exitCol)
{
	int i,row,col,nextRow,nextCol,dir,found = 0;
	element position;
	mark[1][1]=1;top=0;
	stack[0].row =1; 
	stack[0].col =1; 
	stack[0].dir =1;
	while(top>-1 && found==0)
	{
		position = pop();
		row = position.row;
		col = position.col;
		dir = position.dir;
		while(dir< 8 && found==0)
		{
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;
			if(nextRow== exitRow && nextCol == exitCol)
				found = 1;
			else if ( maze[nextRow][nextCol]==0 && mark[nextRow][nextCol]==0)
			{
				mark[nextRow][nextCol]=1;
				position.row = row; 
				position.col = col;
				position.dir = ++dir;
				push(position);
				row = nextRow; col = nextCol; dir=0;
			}
			else 
				++dir;
		}
	}
	if(found==1)
	{
		stack[top+1].row=row;
		stack[top+1].col=col;
		return 1;
	}
	else 
	{
		return -1;
	}
}