#include<stdio.h>
#include<stdlib.h>
#define MAX 200

FILE *fin;
FILE *fout;

int front =0;
int rear = 0;
int queue[MAX];

int a[MAX];

double w[MAX][MAX];
double r[MAX][MAX];
double c[MAX][MAX];

int KnuthMin(int i, int j);
void obst(double *p, double *q, int n);
void addq(int ptr);
int deleteq();
void main()
{
	int i, n,j, m;
	int tmp;
	int root;
	double p[MAX];
	double q[MAX];
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	fscanf(fin, "%d", &n);
	for(i=1;i<=n;i++)
		fscanf(fin,"%d",&a[i]);
	for(i=1;i<=n;i++)
		fscanf(fin,"%lf",&p[i]);
	for(i=0;i<=n;i++)
		fscanf(fin,"%lf",&q[i]);

	obst(p,q,n);

	root = r[0][n];
	addq(root);
	while(1)
	{
		if(r[0][root-1]!=0)
			addq(r[0][root-1]);
		for(i=0;i<=r[0][root-1];i++)
			{
				for(j=0;j<=i;j++)
					if(i<=j && r[i][j]!=0)
						addq(r[i][j]);
			}
		if(r[j-1][i-1]==r[root-1][root-1])
			break;
		root = r[0][root-1];
	}
	root = r[0][n];
	while(1)
	{
		for(i=root;i<=n;i++)
		{
			for(j=n;j>=i;j--)
				if(queue[rear-1] != r[i][j] && r[i][j]!=0)
					addq(r[i][j]);
		}
		if(r[i][j]==r[n][n])
			break;
	}
	
	while((tmp = deleteq())!=0)
		fprintf(fout,"%d ",a[tmp]);
	
	fclose(fin);
	fclose(fout);
}

void addq(int ptr)
{
	queue[rear++]= ptr;
}

int deleteq()
{
	if(front == rear)
		return 0;
	return queue[front++];
}

void obst(double *p, double *q, int n)
{
	int i,j,k,m;
	for(i=0;i<n;i++)
	{	
		w[i][i] = q[i]; 
		r[i][i] = 0;
		c[i][i] = 0;
		w[i][i+1] = q[i]+q[i+1]+p[i+1];
		r[i][i+1] = i+1;
		c[i][i+1] = w[i][i+1];
	}
	w[n][n] = q[n];
	r[n][n] = 0; 
	c[n][n] = 0;

	for(m=2;m<=n;m++)
	{
			for(i=0;i<=n-m;i++)
		{
			j = i+m;
			w[i][j] = w[i][j-1] + p[j] + q[j];
			k = KnuthMin(i,j);
			c[i][j] = w[i][j] + c[i][k-1] + c[k][j];
			r[i][j]=k;
		}
	}
}

int KnuthMin(int i, int j)
{
	int k, min = INT_MAX, mk;
	for(k=i;k<j;k++)
	{
		if(c[i][k] + c[k+1][j]<min)
		{
			min = c[i][k] + c[k+1][j];
			mk = k+1;
		}
	}
	return mk;
}