#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct test
{
	char input[30];
	int l1;
	int element;
	int position;
	int output[30];
	int l;
}test[8] =
{
	{"1,2,3,4,5",10,6,6,{1,2,3,4,5,6},6},
	{"1,2,3",5,0,1,{0,1,2,3},4},
	{"23,45,67",8,25,2,{23,25,45,67},4},
	{"1,2,3,4",7,0,1,{0,1,2,3,4},5},
	{"-56,-34,-23,12",14,-43,2,{-56,-43,-34,-23,12},5},
	{"12,34",5,0,1,{0,12,34},3},
	{"",0,5,0,{},0},
	{"",0,3,1,{3},0}
};

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
		temp = temp->next;
		int c = 1;
		while(temp != root)
		{
			c += 1;
			temp = temp->next;
		}
		return c;
	}
}

struct node *beginInsert(int x, struct node *root)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node)),*temp1 = (struct node*)malloc(sizeof(struct node));
	temp->item = x;
	temp->next = root;
	if(root == NULL)
		root = temp;
		//printf("Please create LinkedList first..!");
	else
	{
		temp1 = root;
		while(temp1->next!=root)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
		temp->next = root;
		root = temp;
	}
	return root;
}

struct node *endInsert(int x,struct node* root)
 {
	struct node *val = (struct node*)malloc(sizeof(struct node));
	struct node *intr = (struct node*)malloc(sizeof(struct node));
	val->item = x;
	val->next = root;
	if(root == NULL)
	{
		root = val;
		root->next = root;
	}
	else
	{
		intr = root;
		while(intr->next!=root)
			intr=intr->next;
		intr->next = val;
	}
	return root;
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
	root = s[0]=='\0'?root:endInsert(num=flag==0?num:-num,root);
	return root;
}

int pos(int key,struct node *root)
{
	int i=1;
	struct node *temp=root;
	if(root!=NULL)
	while(temp->next != root)
	{
		if(key>temp->item)
			i++;
		else break;
		temp = temp->next;
	}
	return i;
}

struct node *insertAtPosition(int x,int p, struct node *root)
  {
	if(p==1)
		root = beginInsert(x,root);
	else if(p <= lengthOf(root)+1 && p != 0)
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
			s[j]=test[i].input[j];
		s[j]='\0';
		root = NULL;
		root=stringToLinkedList(s,root);
		a = linkedList_To_Array(insertAtPosition(test[i].element,pos(test[i].element,root),root),test[i].l);
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
	struct node *root, *thead;
	root = NULL;
	printf("\n");
	root = stringToLinkedList(s,root);
	root = insertAtPosition(56,1,root);
	display(root);*/
	testcases();
	getche();
}