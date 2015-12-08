#include<stdio.h>
#include<conio.h>
bool check(int [],int,int);
int fun(int [],int,int);
void main()
{
	int a[10],len,n,i,x;
	printf("Enter Length: ");
	scanf("%d",&len);
	printf("Enter Array:  ");
	for(i=0;i<len;i++)
		scanf("%d",&a[i]);
	printf("Enter Number: ");
	scanf("%d",&n);
	x=fun(a,n,len);
	printf("Max: %d\n",x);
	getch();
}
//to avoid repetitions
int fun(int a[],int n,int len)
{
	int max=0,min=0,i;
	for(i=0;i<len;i++)
		if(n<a[i]&&check(a,a[i],i))
			max++;
		else if(n>a[i]&&check(a,a[i],i))
			min++;
	printf("Min: %d\n",min);
	return max;	
}

bool check(int a[],int n,int len)
{
	int i,c=0;
	for(i=0;i<len;i++)
		if(a[i]==n)
			c++;
		if(c>0)
			return false;
		else return true;
}