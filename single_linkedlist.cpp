#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct node
{
	int item;
	struct node *next;
};

int lengthOf(struct node *root)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp = root;
	if(temp == NULL)
		return 0;
	else
	{
		int c = 0;
		while(temp != NULL)
		{
			c += 1;
			temp = temp->next;
		}
		return c;
	}
}

struct node *beginInsert(int x, struct node *root)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->item = x;
	temp->next = NULL;
	if(root == NULL)
		root = temp;
		//printf("Please create LinkedList first..!");
	else
	{
		temp->next = root;
		root = temp;
	}
	return root;
}
struct node *endInsert(int x, struct node *root)
 {
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	struct node *intr = (struct node*)malloc(sizeof(struct node));
	temp->item = x;
	temp->next = NULL;
	if(root == NULL)
		root = temp;
	else
	{
		intr = root;
		while(intr->next != NULL)
			intr = intr->next;
		intr->next = temp;
	}
	return root;
 }
struct node *insertAtPosition(int x,int p, struct node *root)
  {
	if(root != NULL)
	{
		if(p==1)
			root = beginInsert(x,root);
		else if(p+1>lengthOf(root) && p == 0)
			printf("*********Invalid position..!*********");
		else
		{
			struct node *new1 = (struct node*)malloc(sizeof(struct node));
			struct node *temp = (struct node*)malloc(sizeof(struct node));
			new1->item = x;
			new1->next = NULL;
			temp = root;
			for(int i=1;i<p-1;i++)
				temp=temp->next;
			new1->next = temp->next;
			temp->next = new1;
		}
	}
	return root;
  }
struct node *beginDelete(struct node *root)
{
	if(root == NULL)
		printf("\n*******************************************************************\nNo elements to delete..!\n*******************************************************************\n");
	else
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp = root->next;
		root = temp;
	}
	return root;
}

struct node *endDelete(struct node *root)
{
	if(root == NULL)
		printf("\n*******************************************************************\nNo elements to delete..!\n*******************************************************************\n");
	else
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp = root;
		if(temp->next == NULL)
			root = NULL;
		else
		{
			while(temp->next->next!=NULL)
					temp = temp->next;
			temp->next = NULL;
		}
	}
	return root;
}

struct node *deleteAtPosition(int p, struct node *root)
{
	if(root == NULL)
		printf("\n*******************************************************************\nNo elements to delete..!\n*******************************************************************\n");
	else
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp = root;
		if(p==1)
			root = beginDelete(root);
		else
		{
			for(int i=1;i<p-1 && temp->next!=NULL;i++)
				temp = temp->next;
			if(temp->next == NULL || temp == root && p!=2)
				printf("There is no item in position specified..!");
			else
			{
				struct node *new1 = (struct node*)malloc(sizeof(struct node));
				new1 = temp->next;
				temp->next = new1->next;
				free(new1);
			}
		}
	}
	return root;
}

void display(struct node *root)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp = root;
	if(temp != NULL)
	{
		while(temp != NULL)
		{
			printf("%d ",temp->item);
			temp = temp->next;
		}
	}
	else printf("No elements to dispaly..!");
}
struct node *createLinkedList(int length,struct node *root)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->item = 1;
	temp->next = NULL;
	root = temp;
	for(int i=2;i<=length;i++)
		endInsert(i,root);
	return root;
}

void main()
{
	int op,in,del,pos,val,len;
	struct node *root = (struct node *)malloc(sizeof(struct node));
	root = NULL;
	printf("Linked List Operations:-\n");
	while(1)
	{
	printf("\n-----------------------------------------------------------------\nMenu:0.Create\t1.insert \t2.delete\t3.display\t 4.exit\n");
	printf("Enter a choice of operation:");
	scanf("%d",&op);
		switch(op)
		{
		case 0:
			{
				if(root == NULL)
				{
					printf("Enter size of LinkedList: ");
					scanf("%d",&len);
					root = createLinkedList(len,root);
				}
				else
					printf("LinkedList already created..! ");
			}break;
		case 1:
			{
			printf("Insert at?:1.beginning\t 2.ending\t3.position:\t");
			scanf("%d",&in);
			printf("Enter Nuber to insert: ");
			scanf("%d",&val);
				switch(in)
				{
				case 1:root = beginInsert(val,root);break;
				case 2:root = endInsert(val,root);break;
				case 3:
					{
						printf("Enter Position: ");
						scanf("%d",&pos);
						root = insertAtPosition(val,pos,root);
					}break;
				default:;
				}
			}break;
		case 2:
			{
			printf("Delete from :1.beginnig\t 2.ending\t3.position:");
			scanf("%d",&del);
				switch(del)
				{
				case 1:root = beginDelete(root);break;
				case 2:root = endDelete(root);break;
				case 3:
					{
						printf("Enter Position: ");
						scanf("%d",&pos);
						root = deleteAtPosition(pos,root);
					}break;
				}
			}break;
		case 3:display(root);break;
		case 4:exit(0);
		default:printf("invalid choice..!");
		}
	}
	//testcases();
	getche();
}