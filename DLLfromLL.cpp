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
	{"1,2,3,4,5",9,{1,2,3,4,5},5},
	{"1,2,2",5,{1,2,2},2},
	{"23,45,67,23,45,67",17,{23,45,67,23,45,67},6},
	{"1,2,3,3,2,1",11,{1,2,3,3,2,1},6},
	{"-23,-56,-34,12",14,{-23,-56,-34,12},4},
	{"12,34,34,12",11,{12,34,34,12},4},
	{"",0,{},0},
	{"1,1,1,1,1,1",11,{1,1,1,1,1,1},6}
};

struct node
{
	int item;
	struct node *next;
};

struct node2
{
	int item;
	struct node2 *next;
	struct node2 *pre;
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


void display(struct node2 *root2)
{
	struct node2 *intr = (struct node2*)malloc(sizeof(struct node2));
	intr = root2;
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
	int i,j,num=0,flag = 0;
	for(i=0;s[i] != '\0';i++)
		if(s[i] == '-')
			flag = 1;
		else if(s[i] != ',')
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

struct node *recRevLL(struct node *root)
{
	struct node *temp;
	if(root == NULL)
		return NULL;
	else if(root->next == NULL)
		return root;
	else
	{
		temp = recRevLL(root->next);
		root->next->next = root;
	}
	return temp;
}

struct node2* DLLofLL(struct node *root,struct node2 *root2)
{
	if(root!= NULL)
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		struct node2 *temp2 = (struct node2*)malloc(sizeof(struct node2));
		struct node2 *last2 = NULL;
		temp = root;
		while(temp!=NULL)
		{
			struct node2 *new2=(struct node2*)malloc(sizeof(struct node2));
			new2->item = temp->item;
			new2->pre=NULL;
			new2->next = NULL;
			if(root2 == NULL)
			{
				root2 =last2 = new2;	
			}
			else
			{
				last2->next = new2;
				new2->pre = last2;
				last2 = new2;
				last2->next = NULL;
			}
			temp = temp->next;
		}
	}
	return root2;
}

int *linkedList_To_Array(struct node2 *root,int l)
{
	int *a=(int*)malloc(l * sizeof(int)),i;
	if(root!=NULL)
	{
	struct node2 *temp = (struct node2 *)malloc(sizeof(struct node2));
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
	struct node2 *root2 = (struct node2 *)malloc(sizeof(struct node2));
	for(i=0;i<8;i++)
	{
		a=(int*)malloc(test[i].l * sizeof(int));
		s = (char*)malloc(test[i].l1 * sizeof(char));
		for(j=0;j<test[i].l1;j++)
			s[j]=test[i].input[j];
		s[j]='\0';
		root = NULL;
		root2 = NULL;
		a = linkedList_To_Array(DLLofLL(stringToLinkedList(s,root),root2),test[i].l);
		flag = 0;
		for(j=0;j<test[i].l;j++)
			if(a[j] != test[i].output[j])
			{
				//printf("%d. Failed...\n",i+1);
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
	int k;
	s = (char*)malloc(sizeof(char));
	printf("Enter String: \n");
	gets(s);
	struct node *root;
	struct node2 *root2;
	root = NULL;
	root2 = NULL;
	printf("\n");
	root = stringToLinkedList(s,root);
	root2 = DLLofLL(root,root2);
	display(root2);*/
	testcases();
	getche();
}