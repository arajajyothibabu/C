#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
struct test{
	char a[10];
	char o[10];
	bool con;
}testc[8]={{"araja","ajara",true},
{"car","rac",true},
{"rama","amar",true},
{"qwerty","ytrewq",true},
{"abc","cab",true},
{"Araja JB","aRAJA jb",false},
{"efgh","abcd",false},
{"","",true}
};

char *sort(char *s)
{
	for(int i=0;s[i]!='\0';i++)
		for(int j=i+1;s[j]!='\0';j++)
			if(s[i]>s[j])
			{
				char t = s[i];
				s[i]=s[j];
				s[j] = t;
			}
			return s;
}

bool cmp(char *a,char *b)
{
	for(int i=0;a[i]!='\0';i++)
		if(a[i]!=b[i])
			return false;
	return true;
}

bool fun(char *a,char *b)
{
	if(cmp(sort(a),sort(b)))
		return true;
	else return false;
}

void call()
{
	int i;
	for(i=0;i<8;i++)
		if(fun(testc[i].a,testc[i].o) == testc[i].con)
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