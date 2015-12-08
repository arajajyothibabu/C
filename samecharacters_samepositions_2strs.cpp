#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct test{
	char a[30];
	char b[30];
	char o[30];
}testc[8]={{"Aaraja","Babu","a"},
			{"Mission","passion","ssion"},
			{"R&D","R&D","R&D"},
			{"tiger","fight","ig"},
			{"man","don","n"},
			{"Program","method",""},
			{"","",""},
			{"jyothi","JYOTHI",""}
		};
char *fun(char *a,char *b)
{
	int i,k=0;
	char *s;
	s=(char *)malloc(10*sizeof(char));
	for(i=0;a[i]!='\0'&&b[i]!='\0';i++)
		if(a[i]==b[i])
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