#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct test
{
	int l;
	char a[100];
	char c[100];
}testc[5]={
	{17,"Araja Jyothi Babu","Babu Jyothi Araja"},
	{11,"He is right","right is He"},
	{17,"Hai 123 4 5 6","6 5 4 123 Hai"},
	{5,"jb123","jb123"},
	{9,"H E L L O","O L L E H"}
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
	int i=0,n=0,j=0,k=0,x=0;
	char *s;
	s=(char*)malloc(5*sizeof(char));
	while(a[n]!='\0')
		n++;
	k=n-1;
	while(k>=0)
	{
		while(a[k]!=' '&&k>=0)
		{ k--;}
		for(x=k+1;a[x]!=' '&&a[x]!='\0';x++)
			s[j++]=a[x];
		s[j++]=' ';
		k--;
	}
	s[j-1]='\0';
	return s;
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
	a="araja Jyothi Babu";
	printf("%s",rev(a));*/
	call(testc,5);
	_getch();
}