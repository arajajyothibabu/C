#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int fun(int n,int *a,int *b)
{
	int i,j=0,sum=0,res=0;
	if(n>2){
		sum = a[0]+a[1]+a[2];
		res = sum;
		for(int i=1;i<n-2;i++)
		{
			sum=a[i]+a[i+1]+a[i+2];
			if(sum>res){
			res = sum;j=i;
			}
		}
		for(i=0;i<3;i++)
			b[i]=a[j++];
		return 3;
	}
	else {
		if(n==1){
			b[0]=a[0];return 1;
		}
		else{
			b[0]=a[0];b[1]=a[1];return 2;
		} 
	}
}

void main()
{
	int n;
	int *a,*b;
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	for(int j=0;j<n;j++)
		scanf("%d",&a[j]);
	b=(int *)malloc(3*sizeof(int));
	int x = fun(n,a,b);
	for(int i=0;i<x;i++)
		printf("%d ",b[i]);
	getch();
}