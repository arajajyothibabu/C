#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//product mul of elements of given array
struct test{
	int a[10];
	int b[10];
	int n;
	int o[10];
}testc[8]={{{1,2,3,4,5},{},5,{120,60,40,30,24}},
			{{1,0,2,3},{},4,{0,6,0,0}},
			{{1,0,0,2,3},{},5,{0,0,0,0,0}},
			{{1,1,1,1},{},4,{1,1,1,1}},
			{{-1,-4,2,4},{},4,{-32,-8,16,8}},
			{{0,0,0,0,0},{},5,{0,0,0,0,0}},
			{{2},{},1,{2}},
			{{},{},0,{}}
		  };
int fun(int *a,int *b,int n)
{
	int i,c=0,m=1;
	for(i=0;i<n;i++)
		if(a[i]==0)
			c++;
	if(c>1)
		for(i=0;i<n;i++)
			b[i]=0;
	else if(c==1)
	{
		for(i=0;i<n;i++)
			if(a[i]!=0)
				m*=a[i];
		for(i=0;i<n;i++)
			if(a[i]==0)
				b[i]=m;
			else
				b[i]=0;
	}
	else
	{
		for(i=0;i<n;i++)
				m*=a[i];
		for(i=0;i<n;i++)
				b[i]=m/a[i];
	}
	return 0;
}
int fun1(int *a,int *b,int n)
{
	int i,j,k,m;
	for(i=0;i<n;i++)
	{
		m=1;
		for(j=0;j<n;j++)
			if(i!=j)
				m*=a[j];
		b[i]=m;
	}
	return 0;
}
void call()
{
	int i,j,x,c;
	for(i=0;i<8;i++)
	{
		c=0;
		x=fun1(testc[i].a,testc[i].b,testc[i].n);
		/*x=fun1(testc[i].a,testc[i].b,testc[i].n);*/			//code for fun1();
		for(j=0;j<x;j++)
			if(testc[i].b[j]==testc[i].o[j])
				c++;
		if(c==x)
			printf("%d.PASSED..!\n",i+1);
		else printf("%d.FAILED..!\n",i+1);
	}
}
void main()
{
	int n,*a,*b,i,I;
	printf("Enter Array Size: ");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	b=(int *)malloc(n*sizeof(int));
	printf("Enter Array: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
    fun1(a,b,n);
	for(i=0;i<n;i++)
	printf("%d ",b[i]);
	call();
	getch();
}
