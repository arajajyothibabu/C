#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct test
{
	int in;
	int out;
}test[6]={
	{1234,4321},
	{1,1},
	{12,21},
	{0,0},
	{11,11},
	{-54321,-12345}
};

int abs(int n)
{
	return n>=0?n:-n;
}

int fibonacciOf(int n)
{
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else return fibonacciOf(n-1)+fibonacciOf(n-2);
}

void fibOf(int a,int b,int n)
{
	if(n>0)
	{
		printf("%d ",a+b);
		fibOf(b,a+b,n-1);
	}
	return;
}

int *fibArrayOf(int n,int *a)
{
	if(n==1)
	{
		a = (int *)malloc(sizeof(int));
		a[0]=0;
	}
	else if(n==2)
	{
		a = (int *)malloc(2 * sizeof(int));
		a[0] =0; a[1] = 1;
	}
	else 
	{
		a = (int *)malloc(n*sizeof(int));
		a[0] =0; a[1] = 1;
		for(int i=2;i<n;i++)
			a[i] = a[i-1]+a[i-2];
	}
	return a;
}

void testcases()
{
	for(int i=0;i<6;i++)
	{
		if(fibonacciOf(test[i].in) == test[i].out)
			printf("%d. Passed..!\n",i+1);
		else
			printf("%d. Failed..!\n",i+1);
	}
}

void main()
{
	int n,i,*a=(int *)malloc(5*sizeof(int));
	//testcases();
	/*for(i=0;i<50;i++)
	printf("%d ",fibonacciOf(i));*/
	printf("%d %d ",0,1);
	fibOf(0,1,10);
	/*a = fibArrayOf(5,a);
	for(i=0;i<5;i++)
		printf("%d ",a[i]);*/
	getche();
}