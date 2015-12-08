#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Removing elements according to given range of ndices
struct test{
	int a[10];
	int n;
	int I;
	int J;
	int o[10];
}testc[11]={{{1,2,3,4,5},5,2,3,{1,2,5}},
		{{1,2,3,4,5},5,0,4,{}},
		{{1,2,3,4,5},5,-1,5,{}},
		{{1,2,3,4,5},5,-1,2,{4,5}},
		{{1,2,3,4,5},5,3,6,{1,2,3}},
		{{1,2,3,4,5},5,-2,-3,{1,2,3,4,5}},
		{{1,2,3,4,5},5,6,89,{1,2,3,4,5}},
		{{1,2,3,4,5},5,4,2,{1,2}},
		{{1,2,3,4,5},5,5,-5,{}},
		{{},0,2,3,{}},
		{{1,2,3,4,5},5,2,2,{1,2,4,5}}
		};
int fun1(int *a,int n,int I,int J)
{
	int i,k=0;
	if(I>J)
	{
		int t=I;
		I=J;
		J=t;
	}
	if(I>=0&&I<n||J>=0&&J<n)
	{
		for(i=0;i<n;i++)
			if(i<I)
				a[k++]=a[i];
			else if(i>J)
				a[k++]=a[i];
		a=(int *)malloc(k*sizeof(int));
		return k;
	}
	else return k;
}
void call()
{
	int i,j,x,c;
	for(i=0;i<11;i++)
	{
		c=0;
		x=fun1(testc[i].a,testc[i].n,testc[i].I,testc[i].J);
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
	/*int n,*a,i,z,I,J;
	printf("Enter Array Size: ");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("Enter Array: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter Range (I,J): ");
	scanf("%d%d",&I,&J);
	z=fun1(a,n,I,J);
	for(i=0;i<z;i++)
	printf("%d ",a[i]);*/
	call();
	getch();
}
