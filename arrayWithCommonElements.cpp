#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int fun1(int *a,int m,int *b,int n)    //for any numbers given in sorted arrays
{
	int *s,i=0,j=0,k=0,x=0;
	s=(int *)malloc((m+n)*sizeof(int));
	while(i<m&&j<n)
		if(a[i]<b[j])
			i++;
		else if(a[i]>b[j])
			j++;
		else
		{
			s[k++]=a[i];
			i++;j++;
		}
	for(i=0;i<k;i++)
		if(s[i]!=s[i+1])
			a[x++]=s[i];
		return x;
}
void main()
{
	int *a,*b,i,m,n,x;
	printf("Enter size of Array1: ");
	scanf("%d",&m);
	printf("Enter size of Array2: ");
	scanf("%d",&n);
	a=(int *)malloc(m*sizeof(int));
	b=(int *)malloc(n*sizeof(int));
	printf("Enter Sorted Array1: ");
	for(i=0;i<m;i++)
	scanf("%d",&a[i]);
	printf("Enter Sorted Array2: ");
	for(i=0;i<n;i++)
	scanf("%d",&b[i]);
	x=fun1(a,m,b,n);
	if(x!=0)
		for(i=0;i<x;i++)
			printf("%d ",a[i]);
	else
		printf("No common elements..!");
	getch();
}