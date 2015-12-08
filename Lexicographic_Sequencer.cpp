#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

int len(char *input)
{
	int i=0;
	for(;input[i]!=0;i++){}
	return i;
}

char *Next_Word(char *input)
{
	int l=len(input),i=0,j=0,k=0,isThere = 1;
	for(i=l-1;i>0;i--)									//
		if(input[i]>input[i-1])							//
			isThere = 0;								// checking for terminating condition in lexicographic sequence	
	if(isThere) {}										//
		//return "No further Lexicographic sequence..!";	//
	for(k=l-1;k>0;k--)										
		if(input[k-1]<input[k])							// finding the deviation in order from last
			break;
	for(i=k;i<l;i++)									//
		for(j=i+1;j<l;j++)								// sorting or swaping the remaining left side letters for proper sequence
			if(input[i]>input[j])						//
				swap(&input[i],&input[j]);				//
	for(i=k;i<l;i++)
		if(input[k-1]<input[i])							//
		{												// finding the least max from sorted left elements to swap with deviated element
			swap(&input[k-1],&input[i]);				//
			break;										//
		}
	return input;
}

int main()
{
	int i=0;
	char *input = (char *)malloc(sizeof(char)*20);
	printf("Enter Word: ");
	gets(input);
	printf("=>\t%s",input = Next_Word(input));
	printf("\n\n\t\tMenu:\t1. Next\t0. Exit\t:");
	while(1)
	{
		scanf("%d",&i);
			if(input == "No further Lexicographic sequence..!") break;
		switch(i)
		{
		case 1:input = Next_Word(input);printf("=>\t%s\t\t\t\t:",input);break;
		case 0:exit(0);
		default:printf("\tWrong Entry..!");
		}
	}
	getch();
	return 0;
}
