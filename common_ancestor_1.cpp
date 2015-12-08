#pragma warning(disable :4996)
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node 
{
	int value;
	Node * left;
	Node * right;
};

struct testcases
{
	int a;
	int b;
}TC[15]={
	{20,30},
	{40,70},
	{70,9},
	{56,70},
	{12,80},
	{70,80},
	{50,9},
	{50,12},
	{12,9},
	{40,50},
	{40,56},
	{12,30},
	{12,13},
	{90,8},
	{80,1},
	
};

Node* createNode(int value)
{
	Node * node = (Node*)malloc(sizeof(Node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void printNode(Node * root)
{
	printf("%d ", root->value);
}

void ancestor(Node* root,int *x,int *y,int value)
{
	if(root==NULL)
		return;
	if(*x==*y)
		return ;
	if(root->value==*x)
		*x=value;
	if(root->value==*y)
		*y=value;
}

void converge_in_postorder(Node *root,int *x,int* y,void (*ancestor)(Node*,int*,int*,int),int value)
{
	if(root)
	{
		converge_in_postorder(root->left,x,y,ancestor,root->value);
		converge_in_postorder(root->right,x,y,ancestor,root->value);
		ancestor(root,x,y,value);
	}
}

void main()
{
	int i,p,q;
	bool flag=false;
	Node* n10 = createNode(10);
	Node* n20 = createNode(20);
	Node* n30 = createNode(30);
	Node* n40 = createNode(40);
	Node* n50 = createNode(50);
	Node* n70 = createNode(70);
	Node* n80 = createNode(80);
	Node* n9  = createNode(9);
	Node *n12 = createNode(12);
	Node *n56 = createNode(56);

	n10->left = n20;
	n10->right=n30;
	n20-> left = n40;
	n20->right=n50;
	n30->right = n80;
	n30->left = n70;
	n70->left= n12;
	n80->left=n9;
	n40->left=n56;

	Node * root = n10;
	for(i=0;i<15;i++)
	{
		p=TC[i].a;
		q=TC[i].b;
		converge_in_postorder(root,&p,&q,ancestor,root->value);
		if(p==q)
				printf("common ancestor:%d\n",p);
			else printf("no common succesor..\n");
	}
	getche();
}