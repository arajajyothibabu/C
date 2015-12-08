//print all the right most visible nodes in a Tree
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct Node
{
	int data;
	Node *left,*right;
};

struct testestCaseases
{
	int Nodes[20];
	int visible[20];
	int input_len;
	int output_len;
}testCase[10]={
	{{1,2,3,4,5,6,7},{1,2,3,4,5,6,7},7,7},
	{{-1,2,-2,-3,9,7,0,13,91,-4,15,-7,-8,-9},{-1,2,9,13,91,15,-9},15,7},
	{{7,6,5,4,3,2,1},{7,6,5,4,3,2,1},7,7},
	{{3,10,15,1,2,-1,4,9,77,3},{3,10,15,9},8,4},
	{{},{},}
};

Node* create_Node()
{
	Node *new_Node=(Node*)malloc(sizeof(Node));
	new_Node->left=new_Node->right=NULL;
	return new_Node;
}

Node* insert(int data,Node *root)
{
	
	if(root==NULL)
	{
		Node *temp=create_Node();
		temp->data=data;
		root=temp;
	}
	else if(data < root->data)
		root->left=insert(data,root->left);
	else root->right=insert(data,root->right);
	return root;
}

void inorder(Node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

int max(int a ,int b)
{
	return a > b?a:b;
}

int get_levels(Node *root)
{
	if(root==NULL) return 0;
	else return max(get_levels(root->left),get_levels(root->right))+1;
}

void rightMost(Node *root,int level,int *flag,int *exp_output,int index)
{
	if(root==NULL)
		return;
	else if(level==0)
	{
		if(*flag==0)
		{
			exp_output[index]=root->data;
			*flag=1;
		}
	}
	else
	{
		if(*flag==0)
			rightMost(root->right,level-1,flag,exp_output,index);
		if(*flag==0)
			rightMost(root->left,level-1,flag,exp_output,index);
	}
}

int* rightVisibles(Node* root)
{
	int levels=get_levels(root),i,flag=0,*exp_output=(int*)calloc(sizeof(int),levels);
	for(i=0;i<levels;i++)
	{
		flag=0;
		rightMost(root,i,&flag,exp_output,i);
	}
	return exp_output;
}

void rightVisibles2(Node * root, int level, int temp)
{
	if(level > temp)
	{
		printf("%d-> ",root->value);
		temp++;
	}
	rightVisibles2(root->right,level+1,temp);
	rightVisibles2(root->left,level+1,temp);
}

void check_output(int *visible,int *obtained,int len,int index)
{
	int i,flag=0;
	for(i=0;i<len;i++)
		if(visible[i]!=obtained[i])
		{
			flag=1;break;
		}
	if(flag==0)
		printf("Input:%d passed..!\n",index+1);
	else printf("Input:%d Failed..!\n",index+1);
}

void execute()
{
	Node *root;
	int i,j,*input,*output,exp_len,*exp_output;
	for(i=0;i<4;i++)
	{
		root=NULL;
		exp_len=0;
		input=(int*)calloc(sizeof(int),testCase[i].input_len);
		output=(int*)calloc(sizeof(int),testCase[i].output_len);
		for(j=0;j<testCase[i].input_len;input[j]=testCase[i].input[j++]);
		for(j=0;j<testCase[i].output_len;output[j]=testCase[i].visible[j++]);
		for(j=0;j<testCase[i].input_len;j++)
			root=insert(input[j],root);
		//exp_output=rightVisibles(root);
		rightVisibles2(root); // just un comment it to see the second method output
		//inorder(root);
		printf("\n******************************** %d *****************************************\n");
		//check_output(output,exp_output,testCase[i].output_len,i);
	}
}

void main()
{
	execute();
	getestCasehe();
}