#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct test{
	char a[30];
	char b[30];
	char o[30];
}testc[8]={{"jyothi","JYOTHI",""},
			{"Program","rozgar","rogra"},
			{"tiger","fight","tig"},
			{"rama","mars","rama"},	
			{"man","don","n"},
			{"Mission","passion","ission"},
			{"R&D","R&D","R&D"},
			{"","",""}			
		};
char *fun(char *a,char *b)
{
	int i,k=0;
	int x[256];
	//static int x[256];
	char *s;
	s=(char *)malloc(10*sizeof(char));
	for(i=0;i<256;i++)									//we can eliminate this loop by using 'static' keyword. but this function have to run for multiple test cases in single program. Didn't use 'static'
		x[i]=0;
	for(i=0;a[i]!='\0';i++)
		if(x[a[i]]==0)
			x[a[i]]++;
	for(i=0;b[i]!='\0';i++)
		if(x[b[i]]==1)
			x[b[i]]++;
	for(i=0;a[i]!='\0';i++)
		if(x[a[i]]>1)
			s[k++]=a[i];
	s[k]='\0';
	return s;
}

void call()
{
	int i;
	for(i=0;i<8;i++)
	{
		if(strcmp(fun(testc[i].a,testc[i].b),testc[i].o)==0)
			printf("%d.PASSED..!\n",i+1);
		else printf("%d.FAILED..!\n",i+1);
	}
}
void main()
{
	/*char a[30],b[30];
	gets(a);
	gets(b);
	printf("%s",fun(a,b));*/
	call();
	getch();
}