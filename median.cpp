#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct node
{
	int item;
	struct node *next;
};

struct test
{
	char input[25];
	int l;
	float output;
}test[7]={{"1,2,3,4,5",9,3.0},
			{"1,2,3,4",7,2.5},
			{"-25,34,56,78,79",15,56.0},
			{"2,2",3,2.0},
			{"-10,-2,0,2",10,-1},
			{"1,1,1",5,1.0},
			{"",0,NULL}
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
		while(intr->next!=NULL)
		{
		printf("%d ",intr->item);
		intr = intr->next;
		}
		printf("%d ",intr->item);
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
int sizeOf(struct node * new1)
{
	struct node *last = (struct node*)malloc(sizeof(struct node));
	int count=0;
	last = new1;
	while(last != NULL){
	count++;
	last = last->next;
	}
	return count;
}
float median(struct node *root)
{
	int i=1,len=sizeOf(root);
	if(root != NULL)
	{
	for(i=1;i<len/2&&len>2;i++)
		root = root->next;
	return len==1?root->item:len%2==0?(root->item + root->next->item)/2.0:root->next->item;
	}
	else return NULL;
}

void testcases()
{
	int i,j;
	char *s;
	struct node *root = (struct node*)malloc(sizeof(struct node));
	for(i=0;i<7;i++)
	{
		root = NULL;
		s = (char*)malloc(test[i].l * sizeof(char));
		for(j=0;j<test[i].l;j++)
			s[j]=test[i].input[j];
		s[j]='\0';
		if(median(stringToLinkedList(s,root)) == test[i].output)
			printf("%d. Passed..!\n",i+1);
		else  printf("%d. Failed..!\n",i+1);
	}
}

void main()
{
	/*char *s;
	s = (char*)malloc(sizeof(char));
	printf("Enter String: \n");
	gets(s);
	struct node * root;
	root = NULL;
	printf("%f",median(stringToLinkedList(s,root)));*/
	testcases();
	getche();
}