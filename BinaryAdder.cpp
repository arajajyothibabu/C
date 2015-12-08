#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int len(char *s)
{
	int i=0;
	while(s[i]!='\0')
		i++;
	return i;
}
int fun(char *a,char *b)
{
	int i,x,p,q,n,j=0;
	char *c;
	c=(char *)malloc(5*sizeof(char));
	p=len(a);
	q=len(b);
	x=p-q;
		if(x>=0)
		{
			for(i=0;i<p;i++)
				c[i+x]=b[i];
			for(i=0;i<x;i++)
				c[i]='0';
		}
		else
		{
			x=-x;
			for(i=0;i<q;i++)
			{
				if(i<x)
					c[i]='0';
				else
					c[i]=a[i-x];
				a[i]=b[i];
			}
			p=q;
		}

		for(i=p-1;i>=0;i--)
		{
			if((a[i]-48)+(c[i]-48)+j==0)
				b[i+1]='0';
			else if((a[i]-48)+(c[i]-48)+j==1)
				b[i+1]='1';
			else if((a[i]-48)+(c[i]-48)+j==2)
			{
				b[i+1]='0';j=1;
			}
			else if((a[i]-48)+(c[i]-48)+j==3)
			{
				b[i+1]='1';j=1;
			}
			else
			{
				printf("Invalid Binary Number..!");
				return 0;
			}
		}
		b[i]=(char)(c+48);
		b[p+1]='\0';
}

void main()
{
	char *a,*b;
	int i;
	a=(char *)malloc(5*sizeof(char)); 
	b=(char *)malloc(5*sizeof(char));
	printf("Enter Binary Number1: ");
	scanf("%s",a);
	printf("Enter Binary Number2: ");
	scanf("%s",b);
	i=fun(a,b);
	if(i!=0)
		for(i=0;b[i]!='\0';i++)
			printf("%c",b[i]);
	getch();
}
