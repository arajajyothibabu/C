#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int firstRepeatedNumber(int *a, int n)
{
	int i,j,x;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]==a[j])
				return a[i];
	return NULL;
}

void main()
{
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	int *a=(int *)malloc(sizeof(int));
	printf("Enter Array: ");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%d",firstRepeatedNumber(a,n));
	getche();
}