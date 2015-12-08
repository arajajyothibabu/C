#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
struct node
{
	int item;
	struct node * next;
};

struct testc
{
	char *input;
	int len1;
	char *output;
	int len2;
} testc[7]={
	{"12,23,34,45",11,"12233445",8},
	{"99",2,"99",2},
	{"10,01",5,"1001",4},
	{"-12,34,56",9,"-123456",7},
	{"-90,45",6,"-9045",5},
	{"-11,-01",7,"-11-01",6},
	{"-10",3,"-10",3}
};

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

void display(struct node *root)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp = root;
	while(temp != NULL)
	{
	printf("%d ",temp->item);
	temp = temp->next;
	}
}

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

struct node *stringToLinkedList(char *s,struct node *root)
{
	//struct node *intr = (struct node*)malloc(sizeof(struct node));
	int i,num=0,sign = 0;
	for(i=0;s[i]!='\0';i++)
		if(s[i]!=',')
			s[i]=='-'?sign = 1:num = num * 10 + s[i]-'0';
		else 
		{
			root = endInsert(sign==0?num:-num,root);
			num = 0;
			sign = 0;
		}
		root = endInsert(sign==0?num:-num,root);
		return root;
}


char *llToNumString(struct node *root)
{
	char *s = (char *)malloc(2*sizeOf(root)*sizeof(char));
	int i=0;
	while(root!=NULL)
	{
		if(root->item<0){
			s[i++]='-';
		root->item=-root->item;
		}
		int x = root->item/10;
		s[i++] = x % 10 + '0';
		s[i++] = root->item % 10 + '0';
		root = root->next;
	}
	s[i]='\0';
	return s;
}
void testcases()
{
	int i,j;
	for(i=0;i<7;i++)
	{
		struct node *root = (struct node*)malloc(sizeof(struct node));
		root = NULL;
		char *input = (char *)malloc(testc[i].len1*sizeof(char));
		char *output = (char *)malloc(testc[i].len1*sizeof(char));
		output = testc[i].output;
		input = testc[i].input;
		if(strcmp(llToNumString(stringToLinkedList(input,root)),output)==0)
			printf("%d. Passed\n",i+1);
		else  printf("%d. Failed\n",i+1);
	}
}

void main()
{
	/*struct node *root = (struct node*)malloc(sizeof(struct node));
	root = NULL;
	printf("Enter CSV: ");
	root = stringToLinkedList("12,23,34,45",root);
	puts(llToNumString(stringToLinkedList("12,23,34,45",root)));*/
	testcases();
	getch();
}