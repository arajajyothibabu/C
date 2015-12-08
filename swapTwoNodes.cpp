#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct test
{
	char input[30];
	int l1;
	int output[30];
	int l;
}test[8] =
{
	{"1,2,3,4,5",9,{2,1,4,3,5},5},
	{"1,2,3,-45,-78",13,{2,1,-45,3,-78},5},
	{"23,45,67",8,{45,23,67},3},
	{"1,2,3,4",7,{2,1,4,3},4},
	{"-23,-56,-34,12",14,{-56,-23,12,-34},4},
	{"12,34",5,{34,12},2},
	{"",0,{},0},
	{"1",1,{1},1}
};

struct node
{
	int item;
	struct node *next;
};


 struct node *endInsert(int x,struct node* root)
 {
	struct node *val = (struct node*)malloc(sizeof(struct node));
	struct node *intr = (struct node*)malloc(sizeof(struct node));
	val->item = x;
	val->next = NULL;
	if(root == NULL)
		root = val;
	else
	{
		intr = root;
		while(intr->next!=NULL)
			intr=intr->next;
		intr->next = val;
	}
	return root;
 }


void display(struct node *root)
{
	struct node *intr = (struct node*)malloc(sizeof(struct node));
	intr = root;
	if(intr != NULL)
	{
		while(intr!=NULL)
		{
		printf("%d ",intr->item);
		intr = intr->next;
		}
	}
	else printf("No elements to dispaly..!");
}
struct node *stringToLinkedList(char *s,struct node *root)
{
	//struct node *intr = (struct node*)malloc(sizeof(struct node));
	int i,j,num=0,flag = 0;
	for(i=0;s[i]!='\0';i++)
		if(s[i] == '-')
			flag = 1;
		else if(s[i]!=',')
			num = num * 10 + s[i]-'0';
		else 
		{
			root = endInsert(num=flag==0?num:-num,root);
			num = 0;
			flag = 0;
		}
	root = endInsert(num=flag==0?num:-num,root);
	return root;
}
int sizeOf(struct node * root)
{
	struct node *last = (struct node*)malloc(sizeof(struct node));
	int count=0;
	last = root;
	while(last != NULL){
	count++;
	last = last->next;
	}
	return count;
}

struct node *swapTwoNodes(struct node *root)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp = root;
	while(temp != NULL && temp->next!=NULL)
	{
		int x = temp->item;
		temp->item = temp->next->item;
		temp->next->item = x;
		temp = temp->next->next;
	}
	return root;
}

struct node *swapUsingTwoPointers(struct node *root)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *temp1 = (struct node *)malloc(sizeof(struct node));
	struct node *temp2 = (struct node *)malloc(sizeof(struct node));
	temp = root;
	root->next!=NULL?root = temp->next:root;
	while(temp != NULL && temp->next!=NULL)
	{		
		temp2 = temp;
		temp1->next = temp->next->next;
		temp->next->next = temp;
		temp->next = temp1->next;
		temp = temp->next;
		temp2->next = (temp!=NULL && temp->next!=NULL)? temp->next:temp;
	}
	return root;
}

int *linkedList_To_Array(struct node *root,int l)
{
	int *a=(int*)malloc(l * sizeof(int)),i;
	if(root!=NULL)
	{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	for(i=0,temp=root;i<l;i++,temp=temp->next)
		a[i] = temp->item;
	}
	return a;
}

void testcases()
{
	int i,j,flag=0;
	int *a;
	char *s;
	struct node *root = (struct node *)malloc(sizeof(struct node));
	for(i=0;i<8;i++)
	{
		a=(int*)malloc(test[i].l * sizeof(int));
		s = (char*)malloc(test[i].l1 * sizeof(char));
		for(j=0;j<test[i].l1;j++)
			s[j] = test[i].input[j];
		s[j]='\0';
		root = NULL;
		//a = linkedList_To_Array(swapTwoNodes(stringToLinkedList(s,root)),test[i].l);
		a = linkedList_To_Array(swapUsingTwoPointers(stringToLinkedList(s,root)),test[i].l);
		flag = 0;
		for(j=0;j<test[i].l;j++)
			if(a[j] != test[i].output[j])
			{
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
	/*char *s;
	s = (char*)malloc(sizeof(char));
	printf("Enter String: \n");
	gets(s);
	struct node *root;
	root = NULL;
	printf("\n");
	root = stringToLinkedList(s,root);
	root = swapUsingTwoPointers(root);
	display(root);*/
	testcases();
	getche();
}