#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct test
{
	char input[30];
	int l1;
	int k;
	int output[30];
	int l;
}test[8] =
{
	{"1,2,3,4,5",9,2,{2,1,4,3,5},5},
	{"1,2,2",5,1,{1,2,2},3},
	{"23,45,67,23,45,67",17,4,{23,67,45,23,45,67},6},
	{"1,2,3,3,2,1",11,8,{1,2,3,3,2,1},6},
	{"-23,-56,-34,12",14,2,{-56,-23,12,-34},4},
	{"12,34,34,12",11,4,{12,34,34,12},4},
	{"",0,5,{},0},
	{"1,1,1,1,1,1",11,0,{1,1,1,1,1,1},6}
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
	root->next=NULL;
	return temp;
}

struct node* reversedKNodes(struct node *root,int k)
{
	if(root!= NULL && k!=0 && k!=1)
	{
		int i=1,flag=1;
		struct node *temp1 = (struct node*)malloc(sizeof(struct node));
		struct node *temp2 = (struct node*)malloc(sizeof(struct node));
		struct node *new1 = (struct node*)malloc(sizeof(struct node)),*new2 = (struct node*)malloc(sizeof(struct node));
		temp1 = root;
		while(temp1!=NULL)
		{
			temp2 = temp1;
			while(i<k)
			{
				if(temp1==NULL) return root;
				temp1 = temp1->next;
				i++;
			}i=1;
			if(temp1==NULL) return root;
			new1 = temp1->next;
			temp1->next = NULL;
			if(flag==1)
			{
				root = recRevLL(temp2);
				flag = 0;
			}
			else new2->next = recRevLL(temp2);
			new2 = temp2;
			temp1 = new1;
			temp2->next = temp1;
		}
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
		a = linkedList_To_Array(reversedKNodes(stringToLinkedList(s,root),test[i].k),test[i].l);
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
	printf("Enter k: ");
	scanf("%d",&k);
	struct node *root;
	root = NULL;
	printf("\n");
	root = stringToLinkedList(s,root);
	root = reversedKNodes(root,k);
	display(root);*/
	testcases();
	getche();
}