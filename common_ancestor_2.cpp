#pragma warning(disable :4996)
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
bool fnode=false;

struct testcases
{
	int input[100];
	int input_len;
	int a;
	int b;
}TC[10]={
	{{1,2,3,4,5,6,7},7,3,4},
	{{7,6,5,4,3,2,1},7,5,1},
	{{3,10,15,1,2,-1,4,9,77,3},10,4,-1},
	{{-1,2,-2,-3,9,7,0,13,91,-4,15,-7,-8,-9},15,-1,7},
	{{-1,2,-2,-3,9,7,0,13,91,-4,15,-7,-8,-9},15,-1,9},
	{{-1,2,-2,-3,9,7,0,13,91,-4,15,-7,-8,-9},15,-3,9},
	{{-1,2,-2,-3,9,7,0,13,91,-4,15,-7,-8,-9},15,0,91},
	{{-1,2,-2,-3,9,7,0,13,91,-4,15,-7,-8,-9},15,13,91},
};

struct node
{
	int data;
	node *left,*right;
};

node* create_node()
{
	node *new_node=(node*)malloc(sizeof(node));
	new_node->left=new_node->right=NULL;
	return new_node;
}

node* insert(int data,node *root)
{
	
	if(root==NULL)
	{
		node *temp=create_node();
		temp->data=data;
		root=temp;
	}
	else if(data < root->data)
		root->left=insert(data,root->left);
	else root->right=insert(data,root->right);
	return root;
}

void ancestor(node *root,int *x,int *y,int ans)
{
	if(root==NULL) return;
	if(*x==*y)
		return ;
	ancestor(root->left,x,y,root->data);
	if(*x==*y) 
		return;
	ancestor(root->right,x,y,root->data);
	if(*x==root->data)
		*x=ans;
	if(*y==root->data)
		*y=ans;
}

void converge_in_postorder(node *root,int *x,int* y,int value)
{
	if(root)
	{
		converge_in_postorder(root->left,x,y,root->data);
		converge_in_postorder(root->right,x,y,root->data);
		ancestor(root,x,y,value);
	}
}

void execute()
{}

void main()
{
	node *root;
	int i,j,*input,*output,p,q;
	for(i=0;i<8;i++)
	{
		root=NULL;
		input=(int*)calloc(sizeof(int),TC[i].input_len);
		for(j=0;j<TC[i].input_len;input[j]=TC[i].input[j++]);
		for(j=0;j<TC[i].input_len;j++)
			root=insert(input[j],root);
		p=TC[i].a;
		q=TC[i].b;
		converge_in_postorder(root,&p,&q,root->data);
		if(p==q)
			printf("common ancestor:%d",p);
		else printf("no common ancestor..\n");
		printf("\n\n");
	}
	getche();
}