#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct msg
{
	char text[128];
};

int len(char *s)
{
	int i=0;
	for(;s[i]!='\0';i++){}
	return i;
}

int cmp(char *s,char *t)
{
	int ls = len(s),lt = len(t),i,j,k;
	if(ls>lt) return 1;
	else if(ls<lt) return -1;
	else
	{
		for(i=0;i<ls;i++)
			if(s[i] > t[i])	return 1;
			else if(s[i] < t[i]) return -1;
		return 0;
	}
}

void putMsg(struct msg Msg,FILE *fp)
{
	fseek(fp,0,SEEK_END);
	fwrite(&Msg,128,1,fp);
}

char *getMsg(FILE *fp)
{
	struct msg Msg;
	fseek(fp,-128,SEEK_END);
	fread(&Msg,128,1,fp);
	return Msg.text;
}

void main()
{
	FILE *forward = fopen("forward.bin","wb+");
	FILE *backward = fopen("backward.bin","wb+");
	while(1)
	{
	struct msg Msg;
	printf("\t\t\t\t=>:");fflush(stdin);
	gets(Msg.text);
	if(cmp(Msg.text,"exit") == 0)
		exit(0);
	putMsg(Msg,forward);
	printf("==>%s",getMsg(backward));
	}

}