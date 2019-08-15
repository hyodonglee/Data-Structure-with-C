#include<stdio.h>
#include<stdlib.h>
#define MAX 200

typedef struct element* treePointer;
typedef struct element{
	int data;
	treePointer left;
	treePointer right;
}element;

FILE *fin;
FILE *fout;

treePointer insertNode(treePointer root, int data);
int* iterSearch(treePointer tree, int k);
void main()
{
	int n,m,i;
	int data;
	treePointer root;
	root = NULL;

	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	fscanf(fin,"%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		fscanf(fin,"%d",&data);
		root = insertNode(root,data);
	}

	for(i=1;i<=m;i++)
	{
		fscanf(fin,"%d",&data);
		if(iterSearch(root,data)==NULL)
			fprintf(fout,"-1\n");
		else
			fprintf(fout,"1\n");
	}

	fclose(fin);
	fclose(fout);
}

int* iterSearch(treePointer tree, int k)
{
	while (tree) {
		if (k == tree->data) return &(tree->data);
		if (k < tree->data)
			tree = tree->left;
		else
			tree = tree->right;
	}
	return NULL;
}


treePointer insertNode(treePointer root, int data)
{
	treePointer newnode;
	if (root == NULL) { //트리 처음 생성하는 경우
		newnode = (treePointer)malloc(sizeof(element));
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}

	else if (data < root->data) //root노드보다 작은 수인경우
		root->left = insertNode(root->left, data); //왼쪽 자식으로 이동
	else if (data > root->data) //root노드보다 큰 수인경우
		root->right = insertNode(root->right, data); //오른쪽 자식으로 이동
	else //data와 같은 노드인 경우
		return;

	return root;
}