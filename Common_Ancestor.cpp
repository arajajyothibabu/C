#pragma warning(disable :4996)
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
bool fNode=false;

struct testestCaseases
{
	int input[20];
	int input_len;
	int a;
	int b;
	int output;
}testCase[10]={
	{{1,2,3,4,5,6,7},7,3,4,3},
	{{7,6,5,4,3,2,1},7,5,1,5},
	{{3,10,15,1,2,-1,4,9,77,3},10,4,-1,3},
	{{-1,2,-2,-3,9,7,0,13,91,-4,15,-7,-8,-9},15,-1,7,-1},
	{{-1,2,-2,-3,9,7,0,13,91,-4,15,-7,-8,-9},15,-1,9,-1},
	{{-1,2,-2,-3,9,7,0,13,91,-4,15,-7,-8,-9},15,-3,9,-1},
	{{-1,2,-2,-3,9,7,0,13,91,-4,15,-7,-8,-9},15,0,91,2},
	{{-1,2,-2,-3,9,7,0,13,91,-4,15,-7,-8,-9},15,13,91,13}
};

struct Node
{
	int value;
	Node *left,*right;
};

Node* create_Node()
{
	Node *new_Node=(Node*)malloc(sizeof(Node));
	new_Node->left=new_Node->right=NULL;
	return new_Node;
}

Node* insert(int value,Node *root)
{
	
	if(root==NULL)
	{
		Node *temp=create_Node();
		temp->value=value;
		root=temp;
	}
	else if(value < root->value) root->left=insert(value,root->left);
	else root->right=insert(value,root->right);
	return root;
}

int common_Ancestor(Node* root, int param1, int param2) //in Binary Search Tree
{
	if(param1 <= root->value && param2 >= root->value || param1 >= root->value && param2 <= root->value)
		return root->value;
	else if(param1<root->value && param2<root->value)
		return common_Ancestor(root->left,param1,param2);
	else if(param1>root->value && param2>root->value)
		return common_Ancestor(root->right,param1,param2);
}

void execute()
{
	Node *root;
	int i,j,*input;
	for(i=0;i<8;i++)
	{
		root=NULL;
		input=(int*)calloc(sizeof(int),testCase[i].input_len);
		for(j=0;j<testCase[i].input_len;input[j]=testCase[i].input[j++]);
		for(j=0;j<testCase[i].input_len;j++)
			root=insert(input[j],root); //constructing BST
		//printf("%d", common_Ancestor(root,testCase[i].a,testCase[i].b));
		if(testCase[i].output == common_Ancestor(root,testCase[i].a,testCase[i].b))
			printf("%d. Passed..!\n",i+1);
		else printf("%d. Failed..!\n",i+1);
		printf("\n\n");
	}
}

void main()
{
	execute();
	getche();
}