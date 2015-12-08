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
	{"1,2,3,4,5",9,{5,4,3,2,1},5},
	{"1,2,3,-45,-78",13,{-78,-45,3,2,1},5},
	{"23,45,67",8,{67,45,23},3},
	{"0,2,0,2",7,{2,0,2,0},4},
	{"-23,-56,-34,12",14,{12,-34,-56,-23},4},
	{"12,34",5,{34,12},2},
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
struct node *reverseLinkedList(struct node *root)
{
	struct node *first = (struct node*)malloc(sizeof(struct node));
	struct node *mid = (struct node*)malloc(sizeof(struct node));
	struct node *last = (struct node*)malloc(sizeof(struct node));
	if(root == NULL)
		return NULL;
	else if(root->next == NULL)
		return root;
	else if(root->next->next ==NULL)
	{
		first = root->next;
		first->next = root;
		root->next = NULL;
		return first;
	}
	else
	{
		first = root;
		mid = first->next;
		last = mid->next;
		while(last->next != NULL)
		{
			mid->next = first;
			first =	mid;
			mid = last;
			last = last->next;
		}
		last->next = mid;
		mid->next = first;
		root->next=NULL;
		return last;
	}
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
	//inmportant code here: root->next = NULL;
	return temp;
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
		a = linkedList_To_Array(reverseLinkedList(stringToLinkedList(s,root)),test[i].l);
		//a = linkedList_To_Array(recRevLL(stringToLinkedList(s,root)),test[i].l);
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
	     //display(stringToLinkedList(s,root));
	printf("\n");
	     //reverseLinkedList(stringToLinkedList(s,root));
	root = stringToLinkedList(s,root);
	thead = root;
	root = recRevLL(root);
	thead->next=NULL;
	display(root);*/
	testcases();
	getche();
}