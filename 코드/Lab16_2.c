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
	if (root == NULL) { //Ʈ�� ó�� �����ϴ� ���
		newnode = (treePointer)malloc(sizeof(element));
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}

	else if (data < root->data) //root��庸�� ���� ���ΰ��
		root->left = insertNode(root->left, data); //���� �ڽ����� �̵�
	else if (data > root->data) //root��庸�� ū ���ΰ��
		root->right = insertNode(root->right, data); //������ �ڽ����� �̵�
	else //data�� ���� ����� ���
		return;

	return root;
}