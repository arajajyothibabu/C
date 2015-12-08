#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//find number of elements greater than given number
struct test{
	int a[10];
	int n;
	int k;
	int o;
}testc[10]={{{1,2,3,4,5},5,2,3},
{{1,2,2,2,3,4},6,2,2},
{{1,2,3,4},4,0,4},
{{1,2,4,6,8},5,7,1},
{{1,2,3,4,5},5,6,0},
{{-2,-1,1,2},4,-1,2},
{{1,1,1,1,1},5,0,5},
{{4},1,2,1},
{{4},1,5,0},
{{},0,1,0}
};
int fun(int *a,int n,int k)
{
	int i=0,m=n;
	if(k<a[0])
		return n;
	else if(k>a[n-1])
		return 0;
	else
	{
		while(a[i]<=k)
			i++;
		return m-i;
	}
}
int fun1(int *a,int n,int k,int x,int y)
{
	int m;
	if(k<a[0])
		return n;
	else if(k>a[n-1])
		return 0;
	else while(1)
		{
			m=(x+y)/2;
		if(a[m]>k&&a[m-1]<k)
			return n-m;
		else if(a[m]<k&&a[m+1]>k)
			return n-m-1;
		else if(a[m]>k)
			y=m-1;
		else if(a[m]<k)
			x=m+1;
		else return n-m-1;
		}
}
void call()
{
	int i,x;
	for(i=0;i<10;i++)
	{
		if(testc[i].o==fun(testc[i].a,testc[i].n,testc[i].k))
			printf("%d.PASSED..!\n",i+1);
		else printf("%d.FAILED..!\n",i+1);
		/*if(testc[i].o==fun1(testc[i].a,testc[i].n,testc[i].k,0,testc[i].n-1))      //exection code for fun1();
			printf("%d.PASSED..!\n",i+1);
		else printf("%d.FAILED..!\n",i+1);*/
	}
}
void main()
{
	/*int n,*a,i,I;
	printf("Enter Array Size: ");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("Enter Array: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter key: ");
	scanf("%d",&I);
	printf("%d ",fun(a,n,I));*/
	call();
	getch();
}
