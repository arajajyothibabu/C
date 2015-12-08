#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct test
{
	char a[100];
	char c[100];
	int m;
	int o;
}testc[9]={
	{"jb is cse of cse becuase cse","cse",28,3},
	{"Araja","Araja",5,1},
	{"he is araja jyothi babu from araja family","araja",41,2},
	{"","",0,0},
	{"ARAJA","",5,0},
	{"","ARAJA",0,0},
	{"Araja Jyothi Babu","CSE",17,0},
	{"ARAJA ARAJA araja Araja ArajA ARAJA arajA","ARAJA",41,3},
	{"Computer Science & Engineering & GVPCOE(A)","&",42,2}
};
bool cmp(char *a,char *b)
{
	int i,j;
	for(i=0,j=0;a[i]!='\0'||b[j]!='\0';i++,j++)
		if(a[i]!=b[j]) return false;
	return true;
}
int len(char *s)
{
	int n=0;
	while(s[n]!='\0')
		n++;
	return n;
}
int frequency(char *a,char *s,int l)
{
	int i=0,j,k=0,c=0,flag=0;
	char *s1;
	s1=(char*)malloc(1*sizeof(char));
	for(i=0;i<=l;i++)
	{
		if(k==0)
		{
			j=i;
			while(a[j]!=' '&&a[j]!='\0')
			{
				j++;
			}
			if(a[i]==s[0]&&j-i==len(s))
			{
				(char*)realloc(s1,(j-i)*sizeof(char));
				flag=1;
			}
		}
		if(a[i]==' '||i==l)
		{
			s1[k]='\0';
			if(cmp(s,s1)) c++;
			k=0;
		}
		else if(flag==1) s1[k++]=a[i];
		if(flag==0) i=j;
	}
	return c;
}

int recfreq(int l,char *a,char *s,int h)
{
	int i,flag=0,k=0,x=0;
	static int c,eflag=0;
	if(s[0]=='\0'||a[0]=='\0') return 0;
	for(i=l;a[i]!=' '&&a[i]!='\0';i++)
	{
		if(s[k]!='\0'){
		if(a[i]!=s[k++])
			flag=1;
		eflag=1;
		}
		else i++;
	}
	flag==0?c++:c=c;
	if(i<h){
		recfreq(i+1,a,s,h);
	}
	 return eflag==1?c:0;
}
void call(struct test testc[],int l)
{
	char *a,*c;
	int i,j,h;
	for(i=0;i<l;i++)
	{
		int slen=0;
		h=testc[i].m;
	a=(char *)malloc(h*sizeof(char));
	for(j=0;testc[i].a[j]!='\0';j++)
		a[j]=testc[i].a[j];
	a[j]='\0';
	/*while(testc[i].c[slen]!='\0')
		slen++;*/
	c=(char *)malloc(h*sizeof(char));
	for(j=0;testc[i].c[j]!='\0';j++)
		c[j]=testc[i].c[j];
	c[j]='\0';
	//printf("%d------%d\n",recfreq(0,a,c,h),testc[i].o);	
	if(frequency(a,c,h)==testc[i].o)
			printf("Passed..!\n");
		else printf("Failed..!\n");
	}
}
void main()
{
	/*char *a,*s;
	int n;
	a=(char*)malloc(5*sizeof(char));
	s=(char*)malloc(5*sizeof(char));
	gets(a);
	gets(s);
	scanf("%d",&n);
	printf("%d",frequency(a,s,n));*/
	call(testc,9);
	getch();
}