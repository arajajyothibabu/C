#include<stdio.h>
#include<conio.h>
int len(char *);
void main()
{
	int i=0;
	char s[40];
	gets(s);
	/*while(s[i]!='*'){
	scanf("%c",&s[i]);
	i++;}*/
	printf("%d",len(s));
	getch();
}
int len(char s[])
{
	int i=0;
	while(*(s+i)!='\0'&&*(s+i)!=' ')
		i++;
	return i;
}

