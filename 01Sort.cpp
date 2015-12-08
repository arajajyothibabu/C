#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Sorting string containing 0,1s
struct test{
	int a[10];
	int n;
	int o[10];
}testc[7]={{{0,1,0},3,{0,0,1}},
			{{0,1,0,1,0},5,{0,0,0,1,1}},
			{{1,0,1,1,1},5,{0,1,1,1,1}},
			{{0,0,0,0},4,{0,0,0,0}},
			{{1,1,1,1},4,{1,1,1,1}},
			{{},0,{}},
			{{1,1,1,0,0,0},6,{0,0,0,1,1,1}}
		};
	/*int fun(int *a,int *b,int n)
	{
		int i,j=0,k=n-1;
		for(i=0;i<n;i++)
		if(a[i]==0)
			b[j++]=0;
		else
			b[k--]=1;
		return 0;
	}*/
int fun(int *a,int n)
{
	int i=0,j=n-1;
	while(i<j)
	{
		if(a[i]==1&&a[j]==0)
		{
			a[i]=0;i++;
			a[j]=1;j--;
		}
		else if(a[i]==0)
			i++;
		else if(a[j]==1)
			j--;
	}
	return n;
}
void call()
{
	int i,j,x,c;
	for(i=0;i<7;i++)
	{
		c=0;
		x=fun(testc[i].a,testc[i].n);
		for(j=0;j<x;j++)
			if(testc[i].a[j]==testc[i].o[j])
				c++;
		if(c==x)
			printf("%d.PASSED..!\n",i+1);
		else printf("%d.FAILED..!\n",i+1);
	}
}
void main()
{
	/*int n,*a,*b,i;
	printf("Enter Array Size: ");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	b=(int *)malloc(n*sizeof(int));
	printf("Enter Array: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	fun1(a,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);*/
	call();
	getch();
}
