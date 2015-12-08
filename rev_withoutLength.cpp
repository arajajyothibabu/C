#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct test
{
	int l;
	char a[100];
	char c[100];
}testc[12]={
	{5,"araja","ajara"},
	{5,"ArajA","AjarA"},
	{17,"araja jyothi babu","ubab ihtoyj ajara"},
	{6,"jb123 "," 321bj"},
	{7,"!@#$%^&","&^%$#@!"},
	{0,"",""},
	{7,"123MRD&","&DRM321"},
	{3,"   ","   "},
	{5," 234 "," 432 "},
	{4,"{}{}","}{}{"},
	{1,"\n","\n"},
	{2,"\1\2","\2\1"}
};
bool cmp(char *a,char *b)
{
	int i,j;
	for(i=0,j=0;a[i]!='\0'||b[j]!='\0';i++,j++)
		if(a[i]!=b[j]) return false;
	return true;
}
char *rev(char *a)
{
	int i,j,k=0;
	while(a[k]!='\0')
		k++;
	for(i=0,j=k-1;i<k/2;i++,j--)
	{
		a[i]=a[i]+a[j];
		a[j]=a[i]-a[j];
		a[i]=a[i]-a[j];
	}
	return a;
}
void call(struct test testc[],int l)
{
	char *a,*c;
	int i,j,k;
	for(i=0;i<l;i++)
	{
	a=(char *)malloc(testc[i].l*sizeof(char));
	for(j=0;testc[i].a[j]!='\0';j++)
		a[j]=testc[i].a[j];
	a[j]='\0';
	c=(char *)malloc(testc[i].l*sizeof(char));
	for(j=0;testc[i].c[j]!='\0';j++)
		c[j]=testc[i].c[j];
	c[j]='\0';
		if(cmp(rev(a),c))
			printf("Passed..!\n");
		else printf("Failed..!\n");
	}
}
void main()
{
	/*char *a;
	a=(char*)malloc(5*sizeof(char));
	scanf("%s",a);
	rev(a);*/
	call(testc,12);
	_getch();
}