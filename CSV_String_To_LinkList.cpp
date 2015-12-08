#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

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
	int i,j,num=0;
	for(i=0;s[i]!='\0';i++)
		if(s[i]!=',')
			num = num * 10 + s[i]-'0';
		else 
		{
			root = endInsert(num,root);
			num = 0;
		}
	root = endInsert(num,root);
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
	return temp;
}

void main()
{
	char *s;
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
	display(root);
	//testcases();
	getche();
}