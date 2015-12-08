#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char *isPalindrome(char *s)
{
	int i,j,k=0;
	while(s[k]!='\0'){k++;}
		for(i=0,j=k-1;i<k/2;i++,j--)
			if(s[i]!=s[j]) return "";
	return s;
}
char **fun(char *s[20])
{
	int i,k=0;
	for(i=0;s[i]!='\0';i++)
		s[k++]=isPalindrome(s[i]);
	s[k]='\0';
	return s;
}

void main()
{
	char *s[20]={"MADAM","Jyothi","malayalam","HAH","SIS","BYE"};
	(char **)malloc(10*sizeof(char));
	fun(s);
	for(int i=0;s[i]!='\0';i++)
		printf("%s",s[i]);
	getch();
}