#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct test
{
	int l;
	char a[100];
	char c[100];
	int m;
}testc[9]={
	{22,"  araja  jyothi   babu","araja jyothi babu",17},
	{7," araja ","araja",5},
	{35,"araja  jyothi                  babu","araja jyothi babu",17},
	{5,"     ","",0},
	{21," !  @  #  $  %  ^  & ","! @ # $ % ^ &",13},
	{7,"A 1 2 3","A 1 2 3",7},
	{34,"       araja                  babu","araja babu",10},
	{0,"","",0},
	{5,"ARAJA","ARAJA",5}
};
bool cmp(char *a,char *b)
{
	int i,j;
	for(i=0,j=0;a[i]!='\0'||b[j]!='\0';i++,j++)
		if(a[i]!=b[j]) return false;
	return true;
}
char *trim(char *a)
{
	int i,k=0;
	for(i=0;a[i]!='\0';i++)
		if(a[i]!=' '){
			if(a[k]!=a[i])
			a[k++]=a[i];
			else k++;
		}
		else if(a[i]==' '&&a[i-1]!=' '&&k!=0&&a[i+1]!='\0')
			a[k++]=' ';
	a[k]='\0';
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
	c=(char *)malloc(testc[i].m*sizeof(char));
	for(j=0;testc[i].c[j]!='\0';j++)
		c[j]=testc[i].c[j];
	c[j]='\0';
		if(cmp(trim(a),c))
			printf("Passed..!\n");
		else printf("Failed..!\n");
	}
}
void main()
{
	/*char *a;
	a=(char*)malloc(5*sizeof(char));
	gets(a);
	printf("%s",trim(a));*/
	call(testc,9);
	getche();
}