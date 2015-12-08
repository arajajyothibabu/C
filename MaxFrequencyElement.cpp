#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char *fun(char *,char *);
int len(char []);
void main()
{
	char *s1,*k;
	int n;
	printf("Enter length: ");
	scanf("%d",&n);
	s1=(char *)malloc(n*sizeof(char));
	k=(char *)malloc(n*sizeof(char));
	printf("Enter String1 ");
	scanf("%s",s1);
	fun(s1,k);
	for(int i=0;k[i]!='\0';i++)
	printf("%c ",k[i]);
	getch();
}
char *fun(char s[],char *t)
{
	static int a[256];
	char x,y;
	int i,j,max=a[0],k=0;
	for(i=0;s[i]!='\0';i++)
		a[s[i]]++;
	for(i=0;s[i]!='\0';i++)
		if(max<a[s[i]])
			max=a[s[i]];
	if(max==1)
		printf("No repetition of elements..!");
	else
		for(i=0;i<256;i++)
			if(a[i]==max)
				t[k++]=(char)i;
		t[k]='\0';
		return t;
}
