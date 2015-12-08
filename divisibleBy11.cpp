//given a number, find sum of the digits of number
#include<stdio.h>
#include<conio.h>
bool fun(int n)
{
	int i=1,s=0,t=0;
	while(n!=0)
	{
		if(i%2==0)
			s+=n%10;
		else
			t+=n%10;
		i++;
		n=n/10;
	}
	if((s-t)==0)
		return true;
	else if((s-t)>=11)
		fun(s-t);
	else
		return false;
}
void main()
{
	int n;
	scanf("%d",&n);
	if(fun(n))
		printf("%s","true");
	else
		printf("%s","false");
	getch();
}
