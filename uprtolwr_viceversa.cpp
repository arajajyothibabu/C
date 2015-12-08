#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
struct test{
	char a[10];
	char o[10];
}testc[8]={{"Araja","aRAJA"},
{"HelLLLLLo","hELlllllO"},
{"r&d2014","R&D2014"},
{"12%s&D/e","12%S&d/E"},
{"123abc","123ABC"},
{"Araja JB","aRAJA jb"},
{"%!@#$^","%!@#$^"},
{"",""}
};
char *fun(char *a)
{
	for(int i=0;a[i]!='\0';i++)
		if(a[i]<92&&a[i]>64)
			a[i]=(char)(a[i]+32);
		else if(a[i]>96&&a[i]<123)
			a[i]=(char)(a[i]-32);
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
	int n;
	gets(a);
	printf("%s",fun(a));*/
	call();
	getch();
}