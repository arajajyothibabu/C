#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void fun(int *,int);
void main()
{
	int a[10],n,len,i;
	printf("Enter Length: ");
	scanf("%d",&len);
	printf("Enter Array:  ");
	for(i=0;i<len;i++)
		scanf("%d",&a[i]);
	fun(a,len);
	getch();
}
void fun(int s[],int n)
{
		int min,j,max,i,c=0;
	max=s[0];min=max;
	if(n==1)
		printf("Invalid Array..!");
	else
	{
	for(j=1;j<n;j++)
		{
			if(max>=s[j])
			{
				if(max!=s[j])
					min=max;
				max=s[j];
			}
			else if(min<s[j]&&min==max||min>s[j])
			{
				min=s[j];
				if(min>s[j+1]&&j!=n-1&&max!=s[j+1])
					min=s[j+1];
			}
		}
    printf("Second Smallest:- %d\n",min);
	printf("First Smallest:- %d\n",max);
	}
}