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
}test[7] =
{
	{"1,2,3,4,5",9,{1,2,3,4,5},5},
	{"1,5,2,6,3",9,{1,2,3,5,6},5},
	{"100,23,5,67",11,{5,23,67,100},4},
	{"0,2,0,2",7,{0,0,2,2},4},
	{"-23,-56,-34,12",14,{-56,-34,-23,12},4},
	{"35,34",5,{34,35},2},
	{"",0,{},0}
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
		if (s[i] == '-')
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


struct node *sortedLinkedList(struct node *root)
{
	struct node *temp1 = (struct node*)malloc(sizeof(struct node));
	struct node *temp2 = (struct node*)malloc(sizeof(struct node));
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp = root;
	if(temp != NULL && temp->next != NULL)
	for(temp1= temp; temp1 != NULL;temp1=temp1->next)
		for(temp2= temp1->next; temp2 != NULL;temp2=temp2->next)
			if(temp1->item > temp2->item)
			{
				int x = temp1->item;
				temp1->item = temp2->item;
				temp2->item = x;
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
	for(i=0;i<7;i++)
	{
		a=(int*)malloc(test[i].l * sizeof(int));
		s = (char*)malloc(test[i].l1 * sizeof(char));
		for(j=0;j<test[i].l1;j++)
			s[j] = test[i].input[j];
		s[j] = '\0';
		root = NULL;
		a = linkedList_To_Array(sortedLinkedList(stringToLinkedList(s,root)),test[i].l);
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
	root = sortedLinkedList(root);
	display(root);*/
	testcases();
	getche();
}