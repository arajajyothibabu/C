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

int reverseOfNumber(int n,int x)
{
	if(n!=0)
	{
		x = (x + n%10) * 10;
		return reverseOfNumber(n/10,x);
	}
	else return x/10;
}

int revOfNum(int n)
{
	int sum = 0;
	if(n!=0)
	{
		return sum + revOfNum(n/10) * 10;
	}
	return sum;
}

void testcases()
{
	for(int i=0;i<6;i++)
	{
		if(reverseOfNumber(test[i].in,0) == test[i].out)
			printf("%d. Passed..!\n",i+1);
		else
			printf("%d. Failed..!\n",i+1);
	}
}

void main()
{
	int n;
	//testcases();
	printf("%d",revOfNum(123));
	getche();
}