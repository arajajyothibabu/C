#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int fun(int *a,int m,int *b,int n,int *s)
{
	int i=0,j=n-1,k=0,x;
	while(i<m&&j>=0)
		if(a[i]<=b[j])
		{
			s[k++]=a[i];
			i++;
		}
		else
		{
			s[k++]=b[j];
			j--;
		}
	if(i>=m)
		for(x=j;x>=0;x--)
			s[k++]=b[x];
	else
		for(x=i;x<m;x++)
			s[k++]=a[x];
	return k;
}

void main()
{
	int *a,*b,*s,i,m,n,x;
	printf("Enter size of Array1: ");
	scanf("%d",&m);
	printf("Enter size of Array2: ");
	scanf("%d",&n);
	a=(int *)malloc(m*sizeof(int));
	b=(int *)malloc(n*sizeof(int));
	s=(int *)malloc((m+n)*sizeof(int));
	printf("Enter Sorted Array1: ");
	for(i=0;i<m;i++)
	scanf("%d",&a[i]);
	printf("Enter Sorted Array2: ");
	for(i=0;i<n;i++)
	scanf("%d",&b[i]);
	x=fun(a,m,b,n,s);
	for(i=0;i<x;i++)
		printf("%d ",s[i]);
	getch();
}