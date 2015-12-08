#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

int len(char *input)
{
	int i=0;
	for(;input[i]!=0;i++){}
	return i;
}

char *Dec_To_Bin(float number)
{
	int i=0,j=0,k=0;
	float intermediate;
	char *output = (char *)malloc(sizeof(char)*12);
	output[k++] = '0';
	output[k++] = '.';
	while(k<12)
	{
		intermediate = number*2;
		if(intermediate > 1)
		{
			output[k++] = '1';
			number = intermediate-1;
		}
		else
		{
			output[k++] = '0';
			number = intermediate/1;
		}
	}
	output[k] = '\0';
	return output;
}

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
struct node *stringToLinkedList(char *s)
{
	struct node *root = (struct node*)malloc(sizeof(struct node));
	root = NULL;
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

struct node*changeOrder(struct node *root)
{
	struct node *first =  (struct node *)malloc(sizeof(struct node));
	struct node *lastButOne =  (struct node *)malloc(sizeof(struct node));
	if(root == NULL)
		return NULL;
	first = root;
	lastButOne = root;
	if(lastButOne->next != NULL)
	{
		if(root->next->next == NULL)
			return root;
		while(lastButOne->next->next != NULL)
			lastButOne = lastButOne->next;
		lastButOne->next->next = first->next;
		first->next = lastButOne->next;
		lastButOne->next = NULL;
	}
	if(first->next != NULL)
		changeOrder(first->next->next);
	return root;
}

void TAILofFile(char *fileName)
{
	FILE *fp = fopen(fileName, "r");
	fseek(fp,0,SEEK_END);
	int i=0,countOfLines = 0;
	char ch;
	while(1)
	{
		ch = fgetc(fp);
	}
}

void main()
{
	int i=0;
	char *s = (char *)malloc(sizeof(char)*20);
	//printf("%s",Dec_To_Bin(.1));
	printf("Enter Linked List : ");
	gets(s);
	struct node *root = (struct node *)malloc(sizeof(struct node));
	root = NULL;
	root = stringToLinkedList(s);
	display(root);
	printf("\nSorted:\n\n");
	root = changeOrder(root);
	display(root);
	getche();
}
