#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct test
{
	char input1[30];
	int l1;
	char input2[30];
	int l2;
	int output[30];
	int l;
}test[8] =
{
	{"1,2,3",5,"4,5,6",5,{5,7,9},3},
	{"1,2,3",5,"1,2",3,{2,4,3},3},
	{"2,5,7",5,"4,5,3",5,{6,0,1,1},4},
	{"1,2,3,4",7,"",0,{1,2,3,4},4},
	{"",0,"1,2",3,{1,2},2},
	{"1,8",3,"9,9",3,{0,8,1},3},
	{"",0,"",0,{},0},
	{"1",1,"1",1,{2},1}
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
	{
		root = val;
	}
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
	if(s[0]=='\0') return NULL;
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
struct node *adder(struct node *root1, struct node *root2,struct node* root)
{
	if(root1 != NULL || root2 != NULL)
	{
		if(root1 == NULL) return root2;
		else if(root2 == NULL) return root1;
		else
		{
			int x=sizeOf(root1),y=sizeOf(root2),m,k,i=0,c=0;
			m=x>y?x:y;
			struct node *temp1 = (struct node *)malloc(sizeof(struct node)), *temp2 = (struct node *)malloc(sizeof(struct node));
			temp1=root1;
			temp2=root2;
			while(i<m)
			{
				if(temp1!=NULL && temp2!=NULL)
				{
					k = temp1->item + temp2->item + c;
					temp1 = temp1->next;
					temp2 = temp2->next;
				}
				else if(temp1!=NULL)
				{
					k = temp1->item + c;
					temp1 = temp1->next;
				}
				else if(temp2!=NULL)
				{
					k = temp2->item + c;
					temp2 = temp2->next;
				}
				root = endInsert(k%10,root);
				c = k/10 == 0?0:1;
				i++;
			}
			if(c == 1) root = endInsert(1,root);
			return root;
		}
	}
	else return NULL;
}

int *linkedList_To_Array(struct node *root,int l)
{
	int *a=(int*)malloc(l * sizeof(int)),i;
	if(root!=NULL)
	{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	for(i=0,temp=root;i<l&&temp!=NULL;i++,temp=temp->next)
		a[i] = temp->item;
	}
	return a;
}

void testcases()
{
	int i,j,flag=0;
	int *a;
	char *s1,*s2;
	struct node *root = (struct node *)malloc(sizeof(struct node)),*root1 = (struct node *)malloc(sizeof(struct node)),*root2 = (struct node *)malloc(sizeof(struct node));
	for(i=0;i<8;i++)
	{
		a=(int*)malloc(test[i].l * sizeof(int));
		s1 = (char*)malloc(test[i].l1 * sizeof(char));
		s2 = (char*)malloc(test[i].l2 * sizeof(char));
		for(j=0;j<test[i].l1;j++)
			s1[j]=test[i].input1[j];
		s1[j] = '\0';
		for(j=0;j<test[i].l2;j++)
			s2[j]=test[i].input2[j];
		s2[j]='\0';
		root = NULL;
		root1 = NULL;
		root2 = NULL;
		a = linkedList_To_Array(adder(stringToLinkedList(s1,root1),stringToLinkedList(s2,root2),root),test[i].l);
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
	char *s1,*s2;
	s1 = (char*)malloc(sizeof(char));
	s2 = (char*)malloc(sizeof(char));
	printf("Enter String: \n");
	gets(s1);
	printf("Enter String: \n");
	gets(s2);
	struct node *root1,*root2,*root;
	root1 = NULL;
	root2 = NULL;
	root = NULL;
	printf("\n");
	root1 = stringToLinkedList(s1,root2);
	root2 = stringToLinkedList(s2,root2);
	root = adder(root1,root2,root);
	display(root);
	testcases();
	getche();
}