#include<stdio.h>
#include<conio.h>
#include<stdio.h>
struct test{
	char a[10];
	int n;
	char b;
}testc[8]={{"Araja",4,'A'},
{"Araja",0,'a'},
{"r&d2014",1,'1'},
{"Araja",7,'\0'},
{"123abc",-1,'\0'},
{"Araja JB",2,' '},
{"%!@#$^",3,'@'},
{"9ARAJA",5,'9'}
};
char fun(char *a,int n)
{
	int i=0;
	while(a[i]!='\0')
		i++;
	if(n<i&&n>=0)
	return *(a+i-n-1);
	else return '\0';
}

void call()
{
	int i;
	for(i=0;i<8;i++)
		if(fun(testc[i].a,testc[i].n)==testc[i].b)
			printf("%d.PASSED..!\n",i+1);
		else printf("%d.FAILED..!\n",i+1);
}
void main()
{
	/*char a[20];
	int n;
	gets(a);
	scanf("%d",&n);
	printf("%c",fun(a,n));*/
	call();
	getch();
}