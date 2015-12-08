#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct test
{
	int input;
	int output[20];
	int l;
}test[6] =
{
	{5,{5},1},
	{1234,{1,2,3,4},4},
	{12300,{1,2,3,0,0},5},
	{23,{2,3},2},
	{987654321,{9,8,7,6,5,4,3,2,1},9},
	{-234567,{-2,3,4,5,6,7},6}
};

struct node
{
	int item;
	struct node *next;
};

struct node *beginInsert(int x, struct node *root)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->item = x;
	temp->next = NULL;
	if(root == NULL)
		root = temp;
	else
	{
		temp->next = root;
		root = temp;
	}
	return root;
}

void display(struct node *root)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp = root;
	while(temp != NULL)
	{
	printf("%d ",temp->item);
	temp = temp->next;
	}
}

struct node*number_to_linkedlist(int num,struct node *root)
{
	int x,flag=0;
	num>0?flag =1:num=-num;
	while(num/10!=0)
	{
		x=num%10;
		root = beginInsert(x,root);
		num=num/10;
	}
	root = flag==0?beginInsert(-num%10,root):beginInsert(num%10,root);
	return root;
}

int *linkedList_To_Array(struct node *root,int l)
{
	int *a=(int*)malloc(l * sizeof(int)),i;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	for(i=0,temp=root;i<l;i++,temp=temp->next)
		a[i] = temp->item;
	return a;
}

void testcases()
{
	int i,j,flag=0;
	int *a;
	struct node *root = (struct node *)malloc(sizeof(struct node));
	for(i=0;i<6;i++)
	{
		a=(int*)malloc(test[i].l * sizeof(int));
		root = NULL;
		a = linkedList_To_Array(number_to_linkedlist(test[i].input,root),test[i].l);
		flag = 0;
		for(j=0;j<test[i].l;j++)
			if(a[j] != test[i].output[j])
			{
				printf("%d. Failed...\n",i+1);
				flag = 1;
				break;
			}
		if(flag == 1)
			printf("%d. Failed\n",i+1);
		else printf("%d. Passed\n",i+1);
	}
}

void main()
{
	/*int x;
	struct node *root = (struct node *)malloc(sizeof(struct node));
	root = NULL;
	printf("Enter Number: ");
	scanf("%d",&x);
	root = number_to_linkedlist(x,root);
	display(root);*/
	testcases();
	getche();
}
