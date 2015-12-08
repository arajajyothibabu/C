#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int fun(char *);
int len(char []);
void main()
{
	char *s;
	int n;
	printf("Enter Length: ");
	scanf("%d",&n);
	s=(char *)malloc(n*sizeof(char));
	printf("Enter String1 ");
	scanf("%s",s);
	printf("%d",fun(s));
	getch();
}
int fun(char *s)
{
	int sum=0,i=0;
	while(i<strlen(s))
	{
	sum+=s[i];
	i++;
	}
	return sum;
}