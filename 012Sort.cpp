#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//sorting array having 0,1,2
struct test{
	int a[10];
	int n;
	int o[10];
}testc[9]={{{0,1,2,1,0},5,{0,0,1,1,2}},
{{0,0,0,0},4,{0,0,0,0}},
{{2,2,1,1,0,0},6,{0,0,1,1,2,2}},
{{1,0,2,0,1},5,{0,0,1,1,2}},
{{1,2,1,2,1},5,{1,1,1,2,2}},
{{1,1,1},3,{1,1,1}},
{{},0,{}},
{{2,2,2,2,2},5,{2,2,2,2,2}},
{{1,0,0,0,1},5,{0,0,0,1,1}}
};
int fun(int *a,int n)
{
	int i=0,c0=0,c1=0;
	for(i=0;i<n;i++)
		if(a[i]==0)
			c0++;
		else if(a[i]==1)
			c1++;
	if(c0!=n&&c1!=n||c0!=0&&c1!=0)
	for(i=0;i<n;i++)
		if(i<c0)
			a[i]=0;
		else if(i<c1+c0)
			a[i]=1;
		else
			a[i]=2;
		return n;
}
void call()
{
	int i,j,c,x;
	for(i=0;i<9;i++)
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
	/*int i,*a,n;
	printf("Enter Size: ");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("Enter Array: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	fun(a,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);*/
	call();
	getch();
}
