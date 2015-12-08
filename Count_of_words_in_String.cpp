#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

char *removeUnneccesaryChars(char *string)
{
	int index = 0, trimmedStringIndex = 0;
	char *trimmedString = (char *)malloc(sizeof(char) * strlen(string));
	while(string[index]!= '\0')
	{
		if(string[index] == ' ' && string[index+1] == ' ')
			index++;
		else if(string[index] == ' ' && string[index+1] == '\t')
			index++;
		else if(string[index] == '\t' && string[index+1] == ' ')
			index++;
		else if(string[index] == '\t' && string[index+1] == '\t')
			index++;
		else if(string[index] == '\t' && string[index+1] == '\n')
			index++;
		else if(string[index] == ' ' && string[index+1] == '\n')
			index++;
		else if(string[index] == '\n' && string[index+1] == ' ')
			index++;
		else if(string[index] == '\n' && string[index+1] == '\n')
			index++;
		else if(string[index] == '\t' && string[index+1] == '\0')
			index++;
		else if(string[index] == ' ' && string[index+1] == '\0')
			index++;
		else if(string[index] == '\n' && string[index+1] == '\0')
			index++;
		else if(string[index] == ' ' || string[index] == '\t' || string[index] == '\n')
		{
			if(trimmedStringIndex != 0)
			{
				trimmedString[trimmedStringIndex++] = string[index];
				index++;
			}
			else index++;
		}
		else
		{
			trimmedString[trimmedStringIndex++] = string[index];
			index++;
		}
	}
	trimmedString[trimmedStringIndex] = '\0';
	return trimmedString;
}

int countOfWords(char *string)
{
	int index = 0, wordCount = 0;
	char *trimmedString = (char *)malloc(sizeof(char) * strlen(string));
	
	trimmedString = removeUnneccesaryChars(string);

	if(trimmedString[0] == '\0') return 0;

	for(;trimmedString[index]!='\0';index++)
	{
		if(trimmedString[index] == ' ' || trimmedString[index] == '\t' || trimmedString[index] == '\n')
			wordCount++;
	}
	return wordCount+1;
}

void main()
{
	printf("%d\n",countOfWords("He is JB"));
	printf("%d\n",countOfWords("He"));
	printf("%d\n",countOfWords("He            is           JB"));
	printf("%d\n",countOfWords("He			 is		JB"));
	printf("%d\n",countOfWords("He is\nJB     "));
	printf("%d\n",countOfWords("He is\nJB     \n    "));
	printf("%d\n",countOfWords("			He is			\nJB     \n    "));
	printf("%d\n",countOfWords(""));
	printf("%d\n",countOfWords("									\n\n        "));
	getche();
}