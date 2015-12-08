#include<stdio.h>
#include<conio.h>
#pragma warning(disable:4996)
void process(int a,int b)
{
	int i=0,c=0,j=0;
	for(i=a;i<=b;i++)
	{
		c = 0;
		for(j=2;j<=i/2;j++)
			if(i%j == 0) c++;
		if(c==0 && i != 1) printf("%d\n",i);
	}
}
int main(void) {
	int t = 0,i=0,a[10][2];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	for(i=0;i<t;i++)
	{
		process(a[i][0],a[i][1]);
	}
	getch();
	return 0;
}