#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
struct test{
	char a[40];
	char o[40];
}testc[8]={{"Araja","Araja"},
{"HelLLLLLo","HelLo"},
{"aaaaaaa","a"},
{"12%#@!","12%#@!"},
{"aaa111222bbb","a12b"},
{"aaaRRRAAAJJAAAAA     jjjbb","aRAJA jb"},
{"BACKYARD","BACKYARD"},
{"",""}
};
char* fun(char *a)
{
	int k=0;
	for(int i=0;a[i]!='\0';i++)
		if(a[i]!=a[i+1])
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
	/*char s[40];
	gets(s);
	printf("%s",fun(s));*/
	call();
	getch();
}