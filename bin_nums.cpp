#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void bin_Num(int n)
{
	int x;
	x = n&1? 1:0;
	if(n>0)
	bin_Num(n>>1);
	else return;
	printf("%d",x);
}

void bin_Numbers(int n)
{
	for(int i=1;i<=n;i++)
	{
		bin_Num(i);
		printf("\n");
	}
}

void bin(int n)
{

}

void main()
{
	int n;
	printf("Enter Number: \n");
	scanf("%d",&n);
	bin_Numbers(n);
	//testcases();
	getche();
}

//given a number print all the numbers upto that number in binary format