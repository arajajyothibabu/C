#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Median of two sorted arrays
struct test{
	int a[10];
	int b[10];
	int m;
	int n;
	float o;
}t[9]={{{1,3},{2,4,5},2,3,3.0},
		{{1,2,3},{4,5,6},3,3,3.5},
		{{1,2,3,4},{-2},4,1,2},
		{{5},{1,2,3,4},1,4,3},
		{{},{2,3,4},0,3,3},
		{{1,1,1},{2,2,2},3,3,1.5},
		{{1,3,5},{2,4,6},3,3,3.5},
		{{0},{-2,0},1,2,0},
		{{1,1},{1,1},2,2,1}
};
float fun(int *a,int *b,int m,int n)
{
	int i=0,j=0,k=0,x=0,y=0,c=-1;
	while(k<=(m+n)/2)
	{
		y=x;
		if(a[i]<b[j]&&i<m||i<m&&j>=n)
		{
			x=a[i];i++;
		}
		else if(a[i]>b[j]&&j<n||j<n&&i>=m)
		{
			x=b[j];j++;
		}
		else if(i<m&&j<n)
		{
			x=a[i];y=a[i];i++;j++;k++;
		}
		k++;
	}
		return (m+n)%2==0? (x+y)/2.0:x;
}
void call()
{
	int i;
	for(i=0;i<9;i++)
	{
		if(fun(t[i].a,t[i].b,t[i].m,t[i].n)==t[i].o)
			printf("%d.PASSED..!\n",i+1);
		else
			printf("%d.FAILED..!\n",i+1);
	}
}
void main()
{
	call();
	getch();
}
