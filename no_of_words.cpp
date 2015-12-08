#include<stdio.h>
#include<conio.h>
#include<stdio.h>
struct test{
	char a[50];
	int n;
}testc[9]={{"Araja Jyothi Babu",3},
{"he is good boy",4},
{"r&d2014",1},
{"he joined army as solder.",5},
{"a i e o u",5},
{"Araja JB",2},
{"Araja   Jyothi   BAbu",3},
{"",0},
{"123",1}
};
int fun(char *a)
{
	int i,c=1;
	for(i=0;a[i]!='\0';i++)
		if(a[i]==' '&&a[i+1]!=' ')
			c++;
	return c==1? a[0]=='\0'? 0:c:c;
}

void call()
{
	int i;
	for(i=0;i<9;i++)
		if(fun(testc[i].a)==testc[i].n)
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