#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct test
{
	char in[20];
	char out[20];
	int len;
}test[7]={
	{"araja","ajara",5},
	{"aaa","aaa",3},
	{"qazxsw","wsxzaq",6},
	{"","",0},
	{"123","321",3},
	{"-54321","12345-",6},
	{"12345","54321",5},
};

int len(char *s)
{
	int i=0;
	while(s[i]!='\0')
		i++;
	return i;
}

char *revOf(char *s,char *t,int n)
{
	if(n>0)
	{
		t[len(s)-n] = s[n-1];
		revOf(s,t,n-1);
	}
	else
		{
			t[len(s)]='\0';
			return t;
		}	
}

char *reverseOf(int i,char *s,int j)
{
	if(i!=j && s[i]!=s[j])
	{
		char t = s[i];
		s[i] = s[j];
		s[j] = t;
		s = reverseOf(i+1,s,j-1);
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

void testcases()
{
	for(int i=0;i<6;i++)
	{
		char *s = (char *)malloc(test[i].len * sizeof(char));
		if(cmp(reverseOf(0,test[i].in,test[i].len-1),test[i].out))
			printf("%d. Passed..!\n",i+1);
		else
			printf("%d. Failed..!\n",i+1);
	}
}

void main()
{
	char *s=(char *)malloc(5*sizeof(char)),*t=(char *)malloc(5*sizeof(char));
	testcases();
	//gets(s);
	//printf("%s",revOf(s,t,5));
	getche();
}