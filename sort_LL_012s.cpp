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
}test[6] =
{
	{"1,2,0,1,2",9,{0,1,1,2,2},5},
	{"1,0,2,2,2",9,{0,1,2,2,2},5},
	{"1,1,1,1",7,{1,1,1,1},4},
	{"0,2,0,2",7,{0,0,2,2},4},
	{"2,2,2,2,2",9,{2,2,2,2},4},
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


struct node *sort(struct node *root)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp = root;
	int c0=0,c1=0,i;
	for(temp=root;temp != NULL;temp = temp->next)
		temp->item == 0?c0++:temp->item == 1?c1++:c0 = c0;
	for(temp = root,i=1;temp != NULL;temp = temp->next,i++)
		i <= c0?temp->item = 0:i-c0 <= c1?temp->item = 1:temp->item = 2;
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
	for(i=0;i<6;i++)
	{
		a=(int*)malloc(test[i].l * sizeof(int));
		s = (char*)malloc(test[i].l1 * sizeof(char));
		for(j=0;j<test[i].l1;j++)
			s[j] = test[i].input[j];
		s[j] = '\0';
		root = NULL;
		a = linkedList_To_Array(sort(stringToLinkedList(s,root)),test[i].l);
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
	char *s;
	s = (char*)malloc(sizeof(char));
	printf("Enter String: \n");
	gets(s);
	struct node *root;
	root = NULL;
	printf("\n");
	root = stringToLinkedList(s,root);
	root = sort(root);
	display(root);
	testcases();
	getche();
}