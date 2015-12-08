#include<stdio.h>
#include<conio.h>
void main()
{
	int n;
	printf("Enter Number: ");
	scanf("%d",&n);
	printf("Fun:- %d\n",sum(n));
	printf("Recrsive Fun:- %d",sumrec(n));
	getch();
}
int sum(int n)
{
	int i,s=0;
	while(n!=0)
	{
	s+=n%10;
	n=n/10;
	}
	return s;	
}
int sumrec(int n)
{
	static int s=0;
	s+=n%10;
	n=n/10;
	if(n!=0)
		sumrec(n);
	else
		return s;
}