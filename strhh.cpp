#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
void process(char *s)
{
	int i=0,l=strlen(s)/2;
	printf("%c",s[0]);
	for(i=1;i<l;i++)
		if((i)%2==0)
			printf("%c",s[i]);
	printf("\n");
}
void main()
{
	int T=0,i=0;
	scanf("%d",&T);
	char **a = (char **)malloc(sizeof(char)*T);
	for(i=0;i<T;i++)
	{
		a[i] = (char *)malloc(sizeof(char)*100);
		fflush(stdin);
		gets(a[i]);
	}
	for(i=0;i<T;i++)
		process(a[i]);
	getche();
}