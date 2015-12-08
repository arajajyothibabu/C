#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void swap(int a,int b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%d-%d",a,b);
}

void main()
{
	int n,m;
	printf("Enter Numbers: \n");
	scanf("%d",&m,&n);
	swap(m,n);
	//testcases();
	getche();
}

//swap two numbers