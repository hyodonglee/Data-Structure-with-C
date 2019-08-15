#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

FILE *fin;
FILE *fout;

typedef struct{
	char key[20];
}element;

typedef struct treeNode *treePointer;
struct treeNode{
	treePointer leftChild;
	element data;
	short int bf;
	treePointer rightChild;
}treeNode;

treePointer queue[MAX];
int front =0;
int rear =0;

void levelOrder(treePointer ptr);
void leftRotation(treePointer *parent,int *unbalanced);
void avlInsert(treePointer *parent, element x, int *unbalanced);
void rightRotation(treePointer *parent,int *unbalanced);
treePointer deleteq();
void addq(treePointer x);
void main()
{
	int i,n;
	element x;
	treePointer parent = NULL;
	int unbalanced = 0;
	fin =fopen("input.txt","r");
	fout = fopen("output.txt","w");

	fscanf(fin,"%d",&n);
	for(i=0;i<n;i++)
	{
		fscanf(fin,"%s",x.key);
		avlInsert(&parent,x,&unbalanced);
	}

	levelOrder(parent);
	fclose(fin);
	fclose(fout);
}

void avlInsert(treePointer *parent, element x, int *unbalanced)
{
	if(!*parent){
		*unbalanced = TRUE;
		*parent = (treePointer)malloc(sizeof(treeNode));
		(*parent)->leftChild = (*parent)->rightChild = NULL;
		(*parent)->bf = 0;
		(*parent)->data = x;
	}
	else if(strcmp(x.key,(*parent)->data.key)<0) {
		avlInsert(&(*parent)->leftChild, x, unbalanced);
		if(*unbalanced){
			switch((*parent)->bf){
			case -1: (*parent)->bf = 0;
				*unbalanced = FALSE; break;
			case 0: (*parent)->bf = 1; break;
			case 1: leftRotation(parent,unbalanced);
			}
		}
	}
	else if(strcmp(x.key,(*parent)->data.key)>0){
		avlInsert(&(*parent)->rightChild, x, unbalanced);
		if(*unbalanced){
			switch((*parent)->bf){
			case 1: (*parent)->bf = 0;
				*unbalanced = FALSE; break;
			case 0: (*parent)->bf = -1; break;
			case -1: rightRotation(parent,unbalanced);
			}
		}
		else{
			*unbalanced = FALSE;
		}
	}
}
void leftRotation(treePointer *parent,int *unbalanced)
{
	treePointer grandChild,child;
	child = (*parent)->leftChild;
	if(child->bf ==1){
		(*parent)->leftChild = child->rightChild;
		child->rightChild = *parent;
		(*parent)->bf = 0;
		(*parent) = child;
	}
	else{
		grandChild = child->rightChild;
		child->rightChild = grandChild->leftChild;
		grandChild->leftChild = child;
		(*parent)->leftChild = grandChild->rightChild;
		grandChild->rightChild = *parent;
		switch(grandChild->bf){
		case 1:(*parent)->bf = -1;
			child->bf = 0;
			break;
		case 0:(*parent)->bf = child->bf = 0;
			break;
		case -1:(*parent)->bf = 0;
			child->bf = 1;
		}
		*parent = grandChild;
	}
	(*parent)->bf = 0;
	*unbalanced = FALSE;
}

void rightRotation(treePointer *parent,int *unbalanced)
{
	treePointer grandChild,child;
	child = (*parent)->rightChild;
	if(child->bf ==-1){
		(*parent)->rightChild = child->leftChild;
		child->leftChild = *parent;
		(*parent)->bf = 0;
		(*parent) = child;
	}
	else{
		grandChild = child->leftChild;
		child->leftChild = grandChild->rightChild;
		grandChild->rightChild = child;
		(*parent)->rightChild = grandChild->leftChild;
		grandChild->leftChild = *parent;
		switch(grandChild->bf){
		case -1:(*parent)->bf = 1;
			child->bf = 0;
			break;
		case 0:(*parent)->bf = child->bf = 0;
			break;
		case 1:(*parent)->bf = 0;
			child->bf = -1;
		}
		*parent = grandChild;
	}
	(*parent)->bf = 0;
	*unbalanced = FALSE;
}

treePointer deleteq()
{
	return queue[front++];
}

void addq(treePointer x)
{

	queue[rear++]=x;
}

void levelOrder(treePointer ptr)
{
	if(!ptr) return;

	addq(ptr);
	for(;;)
	{
		ptr = deleteq();
		if(ptr){
			fprintf(fout,"%s\n",ptr->data.key);

			if(ptr->leftChild)
				addq(ptr->leftChild);
			if(ptr->rightChild)
				addq(ptr->rightChild);
		}
		else break;
	}
}