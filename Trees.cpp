#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//#include <stdafx.h>
#pragma warning(disable:4996)

// Trees.cpp : Defines the entry point for the console application.
//

struct Node 
{
	int value;
	Node * left;
	Node * right;
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
	printf("%d  ", root->value);
}

void inorder(Node * root, void (*visit)(Node*))
{
	if (root == NULL) return;

	inorder(root->left, visit);
	visit(root);
	inorder(root->right, visit);
}

void preorder(Node * root, void (*visit)(Node*))
{
	if (root == NULL) return;

	visit(root);
	preorder(root->left, visit);
	preorder(root->right, visit);
}

void postorder(Node * root, void (*visit)(Node*))
{
	if (root == NULL) return;

	postorder(root->left, visit);
	postorder(root->right, visit);
	visit(root);
}

void fill_weight(Node* root)
{
	root->value = 1;
	if(root->left)
		root->value += root->left->value;
	if(root->right)
		root->value += root->right->value;
}

void fill_height(Node* root) //in preorder
{
	int hleft = 0,hright = 0;
	if(root->left)
		hleft = root->left->value;
	if(root->right)
		hright = root->right->value;
	root->value = 1 + hleft>hright?hleft:hright;
}

void isA_BST(Node * root,int lastMax,int flag) //not in Visit functions
{
	if(flag) return;
	if(root)
	{
		if(root->left)
		{
			if(root->left->value > root->value && !flag || root->value > lastMax && root->left->value < lastMax)
			{
				flag = 1;
				printf("Not a BST..!");return;
			}
			isA_BST(root->left, lastMax,flag);
		}
		if(root->right)
		{
			if(root->right->value < root->value && !flag || root->value < lastMax && root->right->value > lastMax)
			{
				flag = 1;
				printf("Not a BST..!");
			}
			isA_BST(root->right, lastMax,flag);
		}
	}
}

void makeFree(Node* root) //only in postorder
{
	free(root);
}

void fillBalance(Node* root)//only in preorder
{
	root->value -= 1;
	if(root->left && root->right)
		root->value = root->left->value - root->right->value;
	else if(root->left)
		root->value = root->left->value;
	else if(root->right) root->value = -root->right->value; 
}

int fill_balances(Node* root)//no visit functions
{
	if(root)
		return root->value = fill_balances(root->left) - fill_balances(root->right);
	return -1;
}

void fill_depths(Node* root)//no visit functions
{
	if(root != NULL)
	{
		if(root->left)
		{
			root->left->value = 1 + root->value;
			fill_depths(root->left);
		}
		if(root->right)
		{
			root->right->value = 1 + root->value;
			fill_depths(root->right);
		}
	}
}

Node* common_Ancestor(Node* root, Node* node1, Node* node2) //in Binary Search Tree
{
	if(node1->value<root->value && node2->value>root->value || node1->value>root->value && node2->value<root->value)
		return root;
	else if(node1->value<root->value && node2->value<root->value)
		return common_Ancestor(root->left,node1,node2);
	else if(node1->value>root->value && node2->value>root->value)
		return common_Ancestor(root->right,node1,node2);
}

struct Nde
{
	Nde* parent;
	Nde* left;
	Nde* right;
	int value;
};

Nde* createNde(int value)
{
	Nde * node = (Nde*)malloc(sizeof(Nde));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	return node;
}

int getInorderSuccessor(Nde* node)
{
	if(node->right)
	{
		Nde* temp = (Nde*)malloc(sizeof(Nde*));
		temp = node->right;
		while(temp->left != NULL)
			temp = temp->left;
		return temp->value;
	}
	else if(node->left == NULL && node->right == NULL)
		return node->parent->left == node?node->parent->value:-1;
	else return node->parent->parent!= NULL?node->parent->parent->left == node->parent?node->parent->parent->value : -1:-1;
}

void main()
{
	Node* n10 = createNode(10);
	Node* n20 = createNode(20);
	Node* n30 = createNode(30);
	Node* n40 = createNode(40);
	Node* n50 = createNode(50);

	//Nde creation.
	Nde* n1 = createNde(1);
	Nde* n2 = createNde(2);
	Nde* n3 = createNde(3);
	Nde* n4 = createNde(4);
	Nde* n5 = createNde(5);
	Nde* n6 = createNde(6);
	Nde* n7 = createNde(7);
	Nde* n8 = createNde(8);

	//tree creation
	n1->left = n2;
	n1->right = n3;
	n1->parent = NULL;
	n2->left = n4;
	n2->right = n5;
	n2->parent = n1;
	n5->left = n6;
	n3->parent = n1;
	n4->parent = n2;
	n5->parent = n2;
	n6->parent = n5;

	n30->left = n20;
	n30->right = n50;
	n20-> left = n40;
	n20 -> right = n10;

	Node * root = n30;
	/*postorder(root, fill_weight);
	printf("\n Inorder : ");
	//inorder(root, isBST);
	inorder(root, printNode);
	printf("\n Preorder : ");
	preorder(root, printNode);
	printf("\n Postorder : ");
	postorder(root, printNode);
	preorder(root, fillBalance);*/
	//fill_balances(root);
	//printf("\n Postorder(balances) : ");
	//postorder(root, printNode);
	//fill_depths(root);
	//printf("\n INorder(depths) : ");
	//inorder(root, printNode);
	//printf("%d",getInorderSuccessor(n3));
	//printf("%d",common_Ancestor(n10,n30,n50)->value);
	isA_BST(root,30,0);
	getche();
}