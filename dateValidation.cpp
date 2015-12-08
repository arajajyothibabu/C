#include<stdio.h>
#include<conio.h>
void fun(char []);
int sum(char [],int,int);
void main()
{
	char s[11],i;
	printf("Enter Date: ");
	gets(s);
	fun(s);
	getch();
}
void fun(char s[])
{
	int x,y,z;
	x=sum(s,0,2);
	y=sum(s,3,5);
	z=sum(s,6,10);
	if(x>31||x==0)
		printf("Invalid date..!");
	else if(y>12||y==0)
		printf("Invalid date..!");
	else if(z>2014||z==0)
		printf("Invalid date..!");
	else
	{
		if(y==2)
			{
				if(z%400==0||z%4==0)
				{
					if(x>29)
						printf("Invalid date..!");
					else
						printf("Valid Date..!");
				}
				else if(x>28)
						printf("Invalid date..!");
			}
		else
			printf("Valid Date..!");
	}
}
int sum(char a[],int m,int n)
{
	int sum=0,i;
	for(i=m;i<n;i++)
	{
		if(i==m)
			sum=(int)a[i]-'0';
		else
			sum=((int)a[i]-'0')+sum*10;
	}
	return sum;
}


