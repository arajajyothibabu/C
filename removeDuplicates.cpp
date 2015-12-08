#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int fun(int *a,int n)// applicable for only single digit numbers
{
	int i,j=0;
	static int b[10];
	char *s;
	s=(char *)malloc(5*sizeof(char));
	for(i=0;i<n;i++)													
		if(b[a[i]]==0)
		{
			b[a[i]]++;
			a[j++]=a[i];
		}
	return j;
}
int fun1(int *a,int n)// applicable for all numbers
{
	int i,j,k=0,c=0;
	for(i=0;i<n;i++)
	{
		c=0;
		for(j=i+1;j<n;j++)
			if(a[i]==a[j])
				c=1;
		if(c==0)
			a[k++]=a[i];
	}
			return k;
}
void main()
{
	int *a,i,n,x;
	printf("Enter size of Array: ");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("Enter Array: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	x=fun1(a,n);
	if(x!=0)
		for(i=0;i<x;i++)
			printf("%d ",a[i]);
	getch();
}