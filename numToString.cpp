#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct test
{
	int l;
	char c[100];
	int m;
}testc[7]={
	{1234,"1234",4},
	{000005,"5",1},
	{17000,"17000",5},
	{-1234,"-1234",5},
	{-1,"-1",2},
	{100001,"100001",6},
	{123456,"123456",6}
};
bool cmp(char *a,char *b)
{
	int i,j;
	for(i=0,j=0;a[i]!='\0'||b[j]!='\0';i++,j++)
		if(a[i]!=b[j]) return false;
	return true;
}
char *rev(char *s)
{
	int i,j,k=0;
	while(s[k]!='\0')
		k++;
	for(i=0,j=k-1;i<k/2;i++,j--)
	{
		s[i]=s[i]+s[j];
		s[j]=s[i]-s[j];
		s[i]=s[i]-s[j];
	}
	return s;
}
int nod(int n)			//no: of digits in a number
{
	int i=0;
	while(n!=0){n=n/10;i++;}
	return n<0?i+1:i;
}
char *toString(int n)
{
	int i,k=0,flag=0;
	char *a;
	a=(char*)malloc(nod(n)*sizeof(char));
	n<0?n=-n:flag=1;
	while(n!=0)
	{
		a[k++]=n%10+'0';
		n=n/10;
	}
	flag==0?a[k++]='-':n=0;
	a[k]='\0';
	return rev(a);
}
void call(struct test testc[],int l)
{
	char *c;
	int i,j,k,n;
	for(i=0;i<l;i++)
	{
	n=testc[i].l;
		c=(char *)malloc(testc[i].m*sizeof(char));
	for(j=0;testc[i].c[j]!='\0';j++)
		c[j]=testc[i].c[j];
	c[j]='\0';
		if(cmp(toString(n),c))
			printf("Passed..!\n");
		else printf("Failed..!\n");
	}
}
void main()
{
	/*int n;
	scanf("%d",&n);
	printf("%s",toString(n));*/
	call(testc,7);
	getche();
}