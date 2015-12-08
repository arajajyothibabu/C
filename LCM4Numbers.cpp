#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int lcm(int a,int b)
{
	if(a>b)
	{
		if(a%b==0)	return b*a/b;
		else return a*b;
	}
	else
		lcm(b,a);
}
int fun(int *a)
{
	if(a[0]==0||a[1]==0||a[2]==0||a[3]==0)
		return 0;
	else
	return lcm(lcm(a[0],a[1]),lcm(a[2],a[3]));
}
void main()
{
	int *a;
	a=(int *)malloc(4*sizeof(int));
	printf("Enter four elements: ");
	for(int i=0;i<4;i++)
		scanf("%d",&a[i]);
	printf("LCM:%d ",fun(a));
	getch();
}