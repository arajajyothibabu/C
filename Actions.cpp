#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

//parse the html page for content

void parsePage(char *fileName)
{
	char **words = (char **)malloc(sizeof(char *)*2000), ch, *temp = (char *)malloc(sizeof(char)*200);
	int i=0,j=0,k=0,l=0,isDup=1,c=0,flag=0, *count = (int *)malloc(sizeof(int)*2000);
	for(;i<2000;i++)
		words[i] = (char *)malloc(sizeof(char)*200);
	FILE *fp = fopen(fileName,"r");
	FILE *wordFile = fopen("words.txt","a");
	fseek(fp,0,SEEK_SET);
	ch = fgetc(fp);
	while(ch != EOF)
	{
		while(ch == '\n') ch = fgetc(fp);
		if(ch == '<')
		{
			while(ch != '>')
				ch = fgetc(fp);
			ch = fgetc(fp);
			while(ch == '\n') ch = fgetc(fp);
			flag = 1;
		}
		/*if(ch == '\n')
		{
			ch = fgetc(fp);
			if(ch != '<' && ch != '\n')
				flag = 1;
			else if(ch == '\n')
			{
				ch = fgetc(fp);
				while(ch == '\n'){ch = fgetc(fp);}
				flag = 1;
			}
		}*/

		/*if(ch == '<' || ch == ' ')
		{
			flag = 0;
		}
		if(flag)
		{
				temp[k++] = ch;
		}*/
		if(ch != ' ')
			temp[k++] = ch;
		else if(k!=0)
		{
			temp[k] = '\0';
			fwrite(temp,strlen(temp),1,wordFile);
			fputc('\n',wordFile);
			printf("%s\n",temp);
			for(i=0;i<l;i++)
			{
				if(strcmp(temp,words[i]) == 0)
				{
					count[i]++;
					isDup = 0;
				}
			}
			if(isDup)
			{
				strcpy(words[l++],temp);
				count[l++] = 1;
				isDup = 1;
			}
			k = 0;
			//flag = 1;
		}
		ch = fgetc(fp);
	}
	int max = 1;
	for(i=0;i<l;i++)
		if(count[i]>max)
		{
			max = count[i];
			c = i;
		}
	printf("%s",words[c]);
	fclose(fp);
}

char *parseString()
{
	return "";
}

void main()
{
	parsePage("source.txt");
	getche();
}