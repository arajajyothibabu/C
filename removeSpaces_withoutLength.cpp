#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct test
{
	int l;
	char a[100];
	char c[100];
	int m;
}testc[10]={
	{7,"  araja","araja",6},
	{6,"Araj A","ArajA",5},
	{17,"araja jyothi babu","arajajyothibabu",15},
	{10,"j b 1 2 3 ","jb123",5},
	{9," !@#$%^& ","!@#$%^&",7},
	{1," ","",0},
	{7,"123MRD&","123MRD&",7},
	{11,"   H A I   ","HAI"},
	{5,"  1  ","1",1},
	{6,"{ }{ }","{}{}",4}
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
		if(a[i]!=' ')
			a[k++]=a[i];
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
	call(testc,10);
	_getche();
}