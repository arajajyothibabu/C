#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void fun(int n,char *a)
{
	int i=0,x,k,j;
	char y;
	while(n!=0)
	{
		x=n%16;
		if(x==10)
			y='A';
		else if(x==11)
			y='B';
		else if(x==12)
			y='C';
		else if(x==13)
			y='D';
		else if(x==14)
			y='E';
		else if(x==15)
			y='F';
		else y=(char)(x+48);
		a[i++]=y;
		n=n/16;
	}
	a[i]='\0';
	for(k=0,j=i-1;k<i/2;k++,j--)
	{
		y=a[k];
		a[k]=a[j];
		a[j]=y;
	}
}
void main()
{
	char *s;
	int n,i;
	printf("Enter the Decimal Number: ");
	scanf("%d",&n);
	s=(char *)malloc(5*sizeof(char));              //memory allocation
	fun(n,s);
	for(i=0;s[i]!='\0';i++)
		printf("%c",s[i]);
	getch();
}