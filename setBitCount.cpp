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
	{"1,2,2",5,{1,2},2},
	{"23,45,67,23,45,67",17,{23,45,67},3},
	{"1,2,3,3,2,1",11,{1,2,3},3},
	{"-23,-56,-34,12",14,{-23,-56,-34,12},4},
	{"12,34,34,12",11,{12,34},2},
	{"",0,{},0},
	{"1,1,1,1,1,1",11,{1},1}
};

int setBitCount(int n)
{
	if(n!=0)
	{
		int x=a[0];
		for(int i=1;i<n;i++)
			x ^= a[i]; 
		return x;
	}
	return 0;
}

void testcases()
{
	/*int i,j,flag=0;
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
		a = linkedList_To_Array(noDuplicate(stringToLinkedList(s,root)),test[i].l);
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
			}*/
}

void main()
{
	int *input,n;
	printf("Enter Number: ");
	scanf("%d",&n);
	printf("\n%d",setBitCount(n));
	//testcases();
	getche();
}