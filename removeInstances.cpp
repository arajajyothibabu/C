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
	{"1,2,3,4,5",9,2,{1,3,4,5},4},
	{"1,2,2",5,2,{1},1},
	{"23,45,67",17,40,{23,45,67},3},
	{"1,1,1,1,1,1",11,1,{},0},
	{"-56,-48,-36,10",14,-48,{-56,-36,10},3},
	{"12,34",11,34,{12},1},
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

 struct node *beginDelete(struct node *root)
{
	if(root != NULL)
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp = root->next;
		root = temp;
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
struct node *deleteAtPosition(int p, struct node *root)
{
	if(root == NULL)
		return root;
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
				return root;
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

struct node* removeInstanceOf(struct node *root,int k)
{
	if(root!= NULL && k!=0 && root->item>k)
	{
		int i=1,flag=1;
		struct node *temp = (struct node*)malloc(sizeof(struct node)),*temp1 = NULL;
		temp = root;
		while(temp!=NULL)
		{
			temp1 = temp->next;
			if(temp->item == k)
				root=deleteAtPosition(i,root);
			else i++;
			temp = temp1;
		}
	}
	return root;
}

struct node* removeInstanceOf2(struct node *root,int k)
{
	if(root!= NULL && k!=0 && root->item>k)
	{
		int i=1,flag=0;
		struct node *temp = (struct node*)malloc(sizeof(struct node)),*temp1 = NULL;
		temp = temp1=root;
		while(temp!=NULL)
		{
			if(temp->item<k)
			{
				temp1 = temp;
				temp=temp->next;
			}
			else if(temp->item == k)
			{
				while(temp!=NULL && temp->item ==k)
					temp=temp->next;
				flag = 1;
			}
			if(temp1 == root) root = temp;
			else temp1->next = temp;
			if(flag) break;
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
		a = linkedList_To_Array(removeInstanceOf(stringToLinkedList(s,root),test[i].k),test[i].l);
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
	char *s;
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
	root = removeInstanceOf2(root,k);
	display(root);
	//testcases();
	getche();
}