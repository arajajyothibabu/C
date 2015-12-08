#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//finding number of highest negative number sequence
struct test{
	int a[10];
	int n;
	int o;
}testc[8]={{{1,2,3,3,2},5,0},
			{{-1,4,-3,-9,8,5,6},7,2},
			{{-1,2,-3,-4,9,-1,-2,3},8,2},
			{{-1,2,-3,4,-5},5,1},
			{{-1,-2,-3},3,3},
			{{},0,0},
			{{-1},1,1},
		   };
int fun(int *a,int n)
{
	int i,k=0,c=0,x=0;
	for(i=0;i<n;i++)
	if(a[i]<0)
		a[k++]=i;
	for(i=0;i<k-1;i++)
		if(a[i+1]-a[i]==1)
		{
			c++;
			if(x<c)
				x=c;
		}
		else
			c=0;
	return k==0?0:x+1;
}
void call()
{
	for(int i=0;i<8;i++)
		if(testc[i].o==fun(testc[i].a,testc[i].n))
			printf("%d.PASSED..!\n",i+1);
		else printf("%d.FAILED..!\n",i+1);
}
void main()
{
	/*int n,*a,i;
	printf("Enter Array Size: ");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("Enter Array: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("%d ",fun(a,n));*/
	call();
	getch();
}
