#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct node
{
	int item;
	struct node *left,*right;
};

struct node *insert(int val,struct node *root)
{
	if(root == NULL)
	{
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->item = val;
		temp->left = NULL;
		temp->right = NULL;
		root = temp;
	}
	else if(val < root->item)
		root->left = insert(val, root->left);
	else if(val > root->item)
		root->right = insert(val, root->right);
	return root;
}

void search(int key,struct node *root)
{
	if(root != NULL)
	{
		if(root->item == key)
			printf("Element Found..!");
		else if(key < root->item)
			search(key,root->left);
		else search(key, root->right);
	}
}

void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ",root->item);
		inorder(root->right);
	}
}

void preorder(struct node *root)
{
	if(root != NULL)
	{
		printf("%d ",root->item);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->item);
	}
}

struct node *destroy(struct node *root)
{
	if(root != NULL)
	{
		root->left = destroy(root->left);
		root->right = destroy(root->right);
		free(root);
	}
	return root;
}

void main()
{
	struct node *root=NULL;
	int n,val,ch;
	while(1)
	{
		printf("\nEnter Choice of operation:\n1. Insert\t2.Traversal\t3.Destroy\t0. Exit\n");
		scanf("%d",&n);
		switch(n)
		{
		case 1:{
				printf("Enter Value: ");
				scanf("%d",&val);
				root = insert(val,root);
			   }break;
		case 2:{
				printf("Enter type of traversal\n1. Inorder\t2. Preorder\t3. Postorder\n");
				scanf("%d",&ch);
					switch(ch)
					{
					case 1:inorder(root);break;
					case 2:preorder(root);break;
					case 3:postorder(root);break;
					default:printf("Invalid entry. Retry..!");
					}
			   }break;
		case 3:root = destroy(root);
			break;
		case 0:exit(0);
		default:printf("Invalid Choice..!");
		}
	}
	getche();
}