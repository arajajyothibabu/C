#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct test{
	char a[30];
	char s[30];
}testc[8]={{"Araja Jyothi Babu","Babu"},
{"a cat on mat","mat"},
{"r&d2014","r&d2014"},
{"Mission R&D","R&D"},
{"123\$% abc","abc"},
{"  Araja Babu","Babu"},
{"Hai..! how are you","you"},
{"",""}
};
char *fun(char *a)
{
	int i=0,j=0,k=0,l=0;
	char *s;
	s=(char *)malloc(10*sizeof(char));
	while(a[l]!='\0')
	{
		if(a[l]==' ')
			j=l+1;
		l++;
	}
	for(i=j;i<l;i++)
		s[k++]=a[i];
	s[k]='\0';
	return s;
}

void call()
{
	int i;
	for(i=0;i<8;i++)
	{
		if(strcmp(fun(testc[i].a),testc[i].s)==0)
			printf("%d.PASSED..!\n",i+1);
		else printf("%d.FAILED..!\n",i+1);
	}
}
void main()
{
	/*char a[30];
	gets(a);
	printf("%s",fun(a));*/
	call();
	getch();
}