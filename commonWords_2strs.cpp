#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct test
{
	char a[100];
	char b[100];
	char c[100];
}testc[6]={
	{"araja jyothi babu","jyothi Araja","jyothi"},
	{"araja jyothi babu cse","jyothi cse","jyothi cse"},
	{"araja jyothi babu","Araja Jyothi Babu",""},
	{"jb123 in mission R&D","jb123 not in MISSION R&D","jb123 in R&D"},
	{"he is standing there","there he is standing","he is standing there"},
	{"","HAI",""}
};
bool cmp(char *a,char *b)
{
	int i,j;
	for(i=0,j=0;a[i]!='\0'||b[j]!='\0';i++,j++)
		if(a[i]!=b[j]) return false;
	return true;
}
char *fun(char *a,char *b)
{
	int i,j,k=0,x=0,l=0,y=0,s=0,q=0,p=0;
	char *s1,*s2,*t;
	t=(char*)malloc(5*sizeof(char));
	s1=(char*)malloc(5*sizeof(char));
	s2=(char*)malloc(5*sizeof(char));
	while(a[x]!='\0')
	{
		for(i=x;a[i]!=' '&&a[i]!='\0';i++)
			s1[l++]=a[i];
		s1[l]='\0';l=0;
		x=i+1;
		while(b[y]!='\0')
		{
			for(j=y;b[j]!=' '&&b[j]!='\0';j++)
				s2[k++]=b[j];
			s2[k]='\0';
			y=j+1;k=0;
			if(cmp(s1,s2))
			{
				for(p=0,q=s;s1[p]!='\0';p++,q++)
					t[q]=s1[p];
				t[q]=' ';
				s=q+1;
			}
		}
		y=0;
	}
	t[q]='\0';
	return t;
}
void call()
{
	for(int i=0;i<6;i++)
		if(cmp(fun(testc[i].a,testc[i].b),testc[i].c))
			printf("Passed..!\n");
		else printf("Failed..!\n");
}
void main()
{
	/*char *a,*b;
	a=(char*)malloc(5*sizeof(char));
	b=(char*)malloc(5*sizeof(char));
	a="he is standing there";
	b="there he is standing";
	fun(a,b);
	printf("%s",fun(a,b));*/
	call();
	getch();
}