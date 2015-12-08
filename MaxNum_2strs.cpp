#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct test
{
	char a[100];
	char b[100];
	char c[100];
}testc[10]={
	{"1231","234","1231"},
	{"12345","12345","EQUAL"},
	{"9999","1111","9999"},
	{"-100","100","100"},
	{"-120","-100","-100"},
	{"000003","33","33"},
	{"00001000","000022","1000"},
	{"2222","2221","2222"},
	{"-00002222","-2222","EQUAL"},
	{"-0033","-00000004","-4"}
};

int len(char *s)
{
	int n=0;
	while(s[n]!='\0'){n++;}
	return n;
}
char *ltrim(char *s)
{
	int i=0,k=0;
	s[0]=='-'?k=1:k=0;
	if(s[k]=='0')
	{
		for(i=k;s[i]!='\0';i++)
			s[i]=s[i+1];
		return ltrim(s);
	}
	else return s;
}
char *fun(char *a,char *b)
{
	int m,n,i=0,flag=0;
	char *s;
	s=(char*)malloc(5*sizeof(char));
	a=ltrim(a);
	b=ltrim(b);
	if(a[0]=='-'&&b[0]=='-') flag=1;
	else if(a[0]=='-') return b;
	else if(b[0]=='-')return a;
	m=len(a);
	n=len(b);
	if(m>n) return flag==1?b:a;
	else if(m<n) return flag==1?a:b;
	else 
		while(i<m)
			if(a[i]==b[i])
			i++;
			else if(a[i]>b[i]) return flag==1?b:a;
			else return flag==1?a:b;
	return "EQUAL";
}
void call()
{
	int i=0;
	for(i=0;i<10;i++)
		if(strcmp(fun(testc[i].a,testc[i].b),testc[i].c)==0) printf("PASSED..!\n");
		else printf("FAILED..!\n");
}
void main()
{
	/*int n;
	char *a,*b;
	a=(char*)malloc(5*sizeof(char));
	b=(char*)malloc(5*sizeof(char));
	scanf("%s%s",a,b);
	printf("%s",fun(a,b));*/
	call();
	getch();
}



































/*char *Value(char *s,char *t)
{
	int i=0;
	while(s[i]!='0')
		if(s[i]==t[i])
			i++;
		else if(s[i]>t[i]) return s;
		else return t;
}*/