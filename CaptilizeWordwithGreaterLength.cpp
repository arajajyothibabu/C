#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int len(char *string)
{
	int i=0;
	for(;string[i]!= '\n' && string[i]!= '\0';i++){}
	return i;
}

void CaptilizeWordsInFile(FILE *input,int length)
{
	int i=0,j=0,k=0, max = 0, nol=1;
	char **lines,*buffer = (char *)malloc(1*sizeof(char));
	//FILE *output = fopen("outputWords.txt","r+");
	while(1)
	{
		char ch = fgetc(input);
		nol++;
		if(ch == EOF)
			break;
	}
	fseek(input,0,SEEK_SET);
	lines = (char **)malloc(sizeof(char) * nol);
	lines[0] = (char *)malloc(sizeof(char) * 50);
	while(fgets(lines[i++],100,input) != NULL)
		lines[i] = (char *)malloc(sizeof(char)*50);
	for(i=0;i<nol;i++)
	{
		printf("%s",lines[i]);
		if(len(lines[i])>length)
		{
			for(j=0;lines[i][j]!='\0';j++)
				lines[i][j] = lines[i][j]>96 && lines[i][j]<123?lines[i][j]-32:lines[i][j];
			fputs(lines[i],input);
		}
	}
	printf("Check out inputWords.txt for sorted words..!");
	fclose(input);
}

void CaptilizeWordsOfFile(FILE *input,int length)
{
	int i=0,j=0,k=0,flag = 0, max = 0,len=0, nol=1;
	char ch, **lines,*buffer = (char *)malloc(1*sizeof(char));
	//FILE *output = fopen("outputWords.txt","r+");
	while(1)
	{
		ch = fgetc(input);
		len++;
		if(ch == '\n' && len > length && flag == 0)
		{
				fseek(input,-len,SEEK_CUR);
				while(ch = fgetc(input) && ch != '\n')
				{
					ch>96 && ch <123?fputc(ch-32,input):0;
				}
				flag = 1;
		}
		flag ==1?len = 0:flag=0;
		if(ch == EOF)
			break;
	}
	fseek(input,0,SEEK_SET);
	printf("Check out inputWords.txt for sorted words..!");
	fclose(input);
}

void readFiles()
{
	FILE *input = fopen("inputWords.txt","r+");
	CaptilizeWordsOfFile(input,4);
}

void main()
{
	readFiles();
	getche();
}