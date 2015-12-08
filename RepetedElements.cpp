#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char *fun(char *,char *,char *);
int len(char []);
void main()
{
	char *s1,*s2,*s;
	int m,n;
		printf("Enter Length1: ");
	scanf("%d",&m);
	s1=(char *)malloc(m*sizeof(char));
	s=(char *)malloc(m*sizeof(char));
	printf("Enter String1: ");
	scanf("%s",s1);
		printf("Enter Length2: ");
	scanf("%d",&n);
	s2=(char *)malloc(n*sizeof(char));
	printf("Enter String2: ");
	scanf("%s",s2);
	fun(s1,s2,s);
	if(s[0]=='\0')
		printf("No common elements..!");
	else
	for(m=0;s[m]!='\0';m++)
	printf("%c ",s[m]);
	getch();
}
char *fun(char *a,char *b,char *s)
{
	static int x[256];
	int i,j=0;
	for(i=0;a[i]!='\0';i++)
		if(x[a[i]]==0)
		x[a[i]]++;
	for(i=0;b[i]!='\0';i++)
		if(x[b[i]]==1)
			x[b[i]]++;
	for(i=0;i<256;i++)
		if(x[i]==2)
		s[j++]=(char)i;
	s[j]='\0';
	return s;
}