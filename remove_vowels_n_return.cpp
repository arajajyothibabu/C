#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
struct test{
	char a[40];
	char o[40];
}testc[8]={{"Araja","rj"},
{"ArajaJyothiBabu","rjJythBb"},
{"r&d2014","r&d2014"},
{"_aeiou","_"},
{"123abc %$#","123bc %$#"},
{"AeIoUaEiOu",""},
{"",""},
{"BCDFGH","BCDFGH"}
};
char* fun(char *a)
{
	int k=0;
	for(int i=0;a[i]!='\0';i++)
		if(a[i]!='a'&&a[i]!='e'&&a[i]!='i'&&a[i]!='o'&&a[i]!='u'&&a[i]!='A'&&a[i]!='E'&&a[i]!='I'&&a[i]!='O'&&a[i]!='U')
			a[k++]=a[i];
		a[k]='\0';
    return a;
}

void call()
{
	int i;
	for(i=0;i<8;i++)
		if(strcmp(fun(testc[i].a),testc[i].o)==0)
			printf("%d.PASSED..!\n",i+1);
		else printf("%d.FAILED..!\n",i+1);
}
void main()
{
	/*char a[20];
	gets(a);
	printf("%s",fun(a));*/
	call();
	getch();
}