#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct test{
	char a[30];
	char b[30];
	char o[30];
}testc[9]={{"123","456","579"},
			{"111111","9","111120"},
			{"999","999","1998"},
			{"9999","1","10000"},	
			{"1","999","1000"},
			{"123456","654321","777777"},
			{"333","222","555"},
			{"","",""},		
			{"234","0","234"}
		};
int len(char *s)
{
	int i=0;
	while(s[i]!='\0')
		i++;
	return i;
}

char *fun(char *a,char *b)
{
	int i,j,k=0,m=len(a),n=len(b),c=0,t=0;
	char *s;
	s=(char *)malloc(10*sizeof(char));
	for(i=m-1,j=n-1;i>=0||j>=0;i--,j--)
	{
		if(i>=0&&j>=0)
			t=a[i]+b[j]+c-2*'0';
		else if(i>=0)
			t=a[i]+c-'0';
		else if(j>=0)
			t=b[j]+c-'0';
		c=t>9? 1:0;
		s[k++]=t%10+'0';
	}
	c==1?s[k++]=1+'0':c=1;
	s[k]='\0';
	for(i=0,j=k-1;i<k/2;i++,j--)				//to reverse the string
	{
		char x=s[j];
		s[j]=s[i];
		s[i]=x;
	}
	return s;
}

void call()
{
	int i;
	for(i=0;i<9;i++)
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