#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct test{
	char a[30];
	char s[30];
}testc[8]={{"Araja Jyothi Babu","Araja"},
{"a cat on mat","a"},
{"r&d2014","r&d2014"},
{"Mission R&D","Mission"},
{"123\$% abc","123\$%"},
{"  Araja Babu","Araja"},
{"Hai..! how are you?","Hai..!"},
{"",""}
};
char *fun(char *a)
{
	int i,j=0,k=0;
	char *s;
	s=(char *)malloc(10*sizeof(char));
	if(a[0]==' ')										//code which helps for printing starting word, if sentence starts with spaces {"   Mission R&D"}
	{
		for(i=1;a[i]!='\0';i++)
			if(a[i]!=' ')
			{
				j=i;break;
			}
			else j=1;
	}
	while(a[j]!='\0')
		{
			if(a[j]==' ')
				break;
			else
				s[k++]=a[j];
			j++;
		}
	s[k]='\0';
	return s;
}

void call()
{
	int i;
	for(i=0;i<8;i++)
		if(strcmp(fun(testc[i].a),testc[i].s)==0)
			printf("%d.PASSED..!\n",i+1);
		else printf("%d.FAILED..!\n",i+1);
}
void main()
{
	/*char a[30];
	gets(a);
	printf("%s",fun(a));*/
	call();
	getch();
}