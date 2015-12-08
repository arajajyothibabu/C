#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

bool search(int *a,int low,int high,int key)
{
	int mid=(low+high)/2;
	if(key==a[mid])
		return true;
	else if(low<=high)
	{
		key<a[mid]?high=mid-1:low=mid+1;
		search(a,low,high,key);
	}
	else return false;
}

int fun(int m,int *a,int n,int *b)
{
	int i,j,c=0;
	for(i=0;i<n;i++)
		if(!search(a,0,m-1,b[i]))
			return 0;
		return 1;
}

void main()
{
	int n,m,i,j;
	int *a,*b;
	scanf("%d",&m);
	a=(int *)malloc(m*sizeof(int));
	for(j=0;j<m;j++)
		scanf("%d",&a[j]);
	scanf("%d",&n);
	b=(int *)malloc(n*sizeof(int));
	for(j=0;j<n;j++)
		scanf("%d",&b[j]);
	if(fun(m,a,n,b)==1) printf("True");
	else printf("False");
	getch();
}