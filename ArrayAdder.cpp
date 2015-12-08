#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//Decimal adder using arrays
struct test {
	int a[10];																//first array
	int m;
	int b[10];														//second array
	int n;
	int c[10+1];													//resultant sum containg array
	int o[10+1];
} t[10] = {{{1,2,3},3,{4,5,6},3,{},{5,7,9}},
			{{9},1,{4,5,6},3,{},{4,6,5}},
			{{9,2,9},3,{4,5,6},3,{},{1,3,8,5}},
			{{1,1,1},3,{1,1,1},3,{},{2,2,2}},
			{{1,2,3,4,5,6},6,{6,5,4,3,2,1},6,{},{7,7,7,7,7,7}},
			{{0},1,{0},1,{},{0}},
			{{9,9,9},3,{9},1,{},{1,0,0,8}},
			{{9,9,9},3,{},0,{},{9,9,9}},
			{{},0,{9},1,{},{9}}
            };
int fun(int *a,int m,int *b,int n,int *c)										 //Function of program
{
	int i=m-1,j=n-1,k=0,x=0,t=0,f=0,l,p,q;
	/*for(p=0,q=0;p<m||q<n;p++,q++)									//to warn,if input have arrays with elements greater than 9;
		if(a[p]>9||b[q]>9) return -1;*/
	l=m>n? m+1:n+1;															//terinary
	while(k<l)
	{
		if(i>=0&&j>=0)
		x=a[i--]+b[j--]+t;
		else if(i>=0)
			x=a[i--]+t;
		else if(j>=0)
			x=b[j--]+t;
		else f=1;
		t=x>9? 1:0;													//terinary
		c[k++]=f!=1? x%10:t;										//terinary				
	}
	int z=t==0? l-1:l;
	for(i=0,j=z-1;i<z/2;i++,j--)
	{
		int t=c[i];
		c[i]=c[j];
		c[j]=t;
	}
	return z;
}
void call()																//Intermediate Calling Function..!
{
	int x,i,j,c;
	for(i=0;i<9;i++)
	{
		c=0;
		x=fun(t[i].a,t[i].m,t[i].b,t[i].n,t[i].c);
		for(j=0;j<x;j++)
			if(t[i].c[j]==t[i].o[j])
				c++;
		if(c==x)
			printf("%d.PASSED..!\n",i+1);
		else printf("%d.FAILED..!\n",i+1);
	}
}
void main()
{
	call();
	getch();
}
