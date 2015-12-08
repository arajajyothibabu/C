//Code for inserting number in the appropriate position of sorted array

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int *fun(int *,int,int);
void main()
{
	int a[10],n,len,i;
	printf("Enter Length: ");
	scanf("%d",&len);
	printf("Enter Array:  ");
	for(i=0;i<len;i++)
		scanf("%d",&a[i]);
	printf("Enter Number: ");
	scanf("%d",&n);
	fun(a,n,len);
	for(i=0;i<len+1;i++)
		printf("%d ",a[i]);
	getch();
}
int *fun(int *a,int n,int len)
{
	int c=0,i,s[10];
	if(len<=0)
		s[0]=n;
	else
	{
	for(i=0;i<len;i++)
		if(n<a[i])
		{
			c++;
			s[i+1]=a[i];
		}
		else
			s[i]=a[i];
	s[len-c]=n;
	}
	for(i=0;i<len+1;i++)
			a[i]=s[i];
		return a;
}