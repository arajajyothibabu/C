#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct trie
{
	char c[26]={'a','b','c','d','e','f','g','h'};
}

int cmp(char *s, char *t)
{
	int c = 0,i = 0;
	for(i=0;s[i]!='\0'&&t[i]!='\0';)
	{
		if(s[i]==t[i])
			i++;
		else if(s[i]>t[i])
			return 1;
		else return -1;
	}
	return 0;
}

void sortWordsToFile(FILE *input)
{
	int i=0,j=0,k=0, max = 0, nol=1;
	char **lines,*buffer = (char *)malloc(1*sizeof(char));
	FILE *output = fopen("output.txt","w");
	while(1)
	{
		char ch = fgetc(input);
		if(ch == '\n')
			nol++;
		if(ch == EOF)
			break;
	}
	fseek(input,0,SEEK_SET);
	lines = (char **)malloc(sizeof(char) * nol);
	lines[0] = (char *)malloc(sizeof(char) * 50);
	while(fgets(lines[i++],100,input) != NULL)
		lines[i] = (char *)malloc(sizeof(char)*50);
	fclose(input);
	for(i=0;i<nol;i++)
		for(j=0;j<nol;j++)
			if(cmp(lines[i],lines[j])<0)
			{
				buffer = lines[i];
				lines[i] = lines[j];
				lines[j] = buffer;
			}
	for(i=0;i<nol;i++)
		fputs(lines[i],output);
	printf("Check out output.txt for sorted words..!");
	fclose(output);
}

void readFiles()
{
	FILE *input = fopen("input.txt","r");
	sortWordsToFile(input);
}

void main()
{
	readFiles();
	getche();
}