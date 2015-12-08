#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//sorting two sorted arrays
struct test {
	int a[20];			//first array
	int m;
	int b[40];			//second array in which resultant array is stored
	int n;
	int c[40];		//Result checking array
} t[10] = {{{1,2,3},3,{4,5,6},3,{1,2,3,4,5,6}},
			{{9},1,{4,5,6},3,{4,5,6,9}},
			{{2,9,9},3,{4,5,6},3,{2,4,5,6,9,9}},
			{{5},1,{-10,-2,4},3,{-10,-2,4,5}},
			{{1,1,1},3,{1,1,1},3,{1,1,1,1,1,1}},
			{{1,2,3,4,5,6},6,{1,2,3,4,5,6},6,{1,1,2,2,3,3,4,4,5,5,6,6}},
			{{0},1,{},0,{0}},
			{{4},1,{1,3,6},3,{1,3,4,6}},
			{{1,3,5},3,{2,4,6},3,{1,2,3,4,5,6}},
			{{},0,{},0,{}}	 //return -1		
            };
int fun(int *a,int m,int *b,int n)   //feasible Function..!
{
	int i=m-1,j=n-1,k=m+n-1;
	while(k>=0)
	{
		if(a[i]>b[j]&&i>=0||j<0)
		{
			b[k--]=a[i];i--;
		}
		else if(a[i]<b[j]&&j>=0||i<0)
		{
			b[k--]=b[j];j--;
		}
		else if(a[i]==b[j])
		{
			b[k--]=a[i];i--;
			b[k--]=b[j];j--;
		}
	}
	return m+n;
}

int fun2(int *a,int m,int *b,int n)							//2nd most feasible function
{
	int i=0,j=m,*t,k=0,x,s,y;
	for(x=m+n-1,y=n-1;x>=m;x--,y--)
		b[x]=b[y];
	while(i<m&&j<n+m)
	{
		if(a[i]<b[j])
		{
			b[k++]=a[i];i++;
		}
		else if(a[i]>b[j])
		{
			b[k++]=b[j];j++;
		}
		else
		{
			b[k++]=a[i];i++;
			b[k++]=b[j];j++;
		}
	}
	if(i<m)
		for(x=i;x<m;x++)
			b[k++]=a[x];
	return k;
}
int fun3(int *a,int m,int *b,int n)
{
	int i=0,j=m,k=0,x,s,y;
	for(x=m,y=0;x<m+n;x++,y++)
		a[x]=b[y];
	while(i<m&&j<n+m)
	{
		if(a[i]<a[j])
		{
			b[k++]=a[i];i++;
		}
		else if(a[i]>a[j])
		{
			b[k++]=a[j];j++;
		}
		else
		{			
			b[k++]=a[i];i++;
			b[k++]=a[j];j++;
		}
	}
	if(i<m)
		for(x=i;x<m;x++)
			b[k++]=a[x];
	else 
		for(x=j;x<m+n;x++)
			b[k++]=a[x];
	return k;
}

void call()						//intermediate Calling function
{
	int x,i,j,c;
	for(i=0;i<10;i++)
	{
		x=fun(t[i].a,t[i].m,t[i].b,t[i].n);
		//x=fun2(t[i].a,t[i].m,t[i].b,t[i].n);
		//x=fun3(t[i].a,t[i].m,t[i].b,t[i].n);            change (fun <=> fun2 <=> fun3) to check other functions
		c=0;
		if(x==0)
		printf("%d.PASSED..!\n",i+1);
		else
		{
				for(j=0;j<x;j++)
					if(t[i].b[j]==t[i].c[j])
						c++;
				if(c==x)
					printf("%d.PASSED..!\n",i+1);
				else printf("%d.Failed..!\n",i+1);
		}
	}
}

void main()
{
	call();
	getch();
}
