#include<stdio.h>
#include<conio.h>
#include<stdio.h>
struct test{
	char a[40];
	int n;
}testc[6]={{"Araja",5},
{"Araja123",8},
{"r&d2014",7},
{"_Araja Babu",11},
{"123abc %$#",10},
{"Araja**12%",10},
};
int fun(char *a)
{
	int i=0;
	while(a[i]!='\0')
		i++;
    return i;
}

void call()
{
	int i;
	for(i=0;i<6;i++)
		if(fun(testc[i].a)==testc[i].n)
			printf("%d.PASSED..!\n",i+1);
		else printf("%d.FAILED..!\n",i+1);
}
void main()
{
	/*char a[20];
	gets(a);
	printf("%d",fun(a));*/
	call();
	getch();
}