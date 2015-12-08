
//given n*n matrix, 0,1. given two positions find whether there is path or not
//mergesort for single linkedlist
//given a BST and 2 values find the greatest common ancestor
//given a tree, print values visible in right side
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void pretify(char *input,char *output)
{
	int i=0, count=0, top=-1,flag = 0,indent = 0,isValue = 0;
	char ch = ' ', prev, *stack = (char *)malloc(sizeof(char)*100);
	FILE *fp1 = fopen(input,"r");
	FILE *fp2 = fopen(output,"w+");
	while(1)
	{
		prev = ch;
		ch = fgetc(fp1);
		if(ch == EOF)
			break;
		if(ch == '\t' || ch == '\n' || (ch == ' ' && isValue == 0) )
		{
			while(ch == '\t' || ch == '\n' || (ch == ' ' && isValue == 0))
				ch = fgetc(fp1);
		}
		if(ch == ',' && isValue == 0)
		{
			if(prev == ':')
			{
				printf("Invalid JSON..!");
				break;
			}
			fputc(ch,fp2);
			fputc('\n',fp2);
			if(prev == '}' || prev == ']') indent++;
			for(i=0;i<indent-1;i++)
				fputc('\t',fp2);
		}
		else
		{
			if(ch == '\"')
				isValue = isValue == 0?1:0;
			if(ch == '{' || ch == '[')
			{
				stack[++top] = ch;
				if(prev != ':')
				{
					flag = 1;
					if(prev != ',')
					{
						if(prev != '{' && prev != '[')
							fputc('\n',fp2);
						for(i=0;i<indent;i++)
						fputc('\t',fp2);
					}
					else indent--;
					indent++;
				}
			}
			if((prev == '{' && flag==1) || (prev == '[' && flag==1))  //checking the condition for key having another JSON or Array
			{
				fputc('\n',fp2);
				if(ch == prev)
					indent--;
				for(i=0;i<indent;i++)
					fputc('\t',fp2);
				indent++;
			}
			if(ch == '}' || ch == ']')
			{
				if(stack[top--] != ch-2) //checking validity of JSON
				{
					printf("Invalid JSON..!");
					break;
				}
				fputc('\n',fp2);
				if(flag == 1)
				{
					indent--;
					flag = 0;
				}
				if(stack[top] == stack[top+1])
						flag = 1;
				if(prev != ch )	indent--;
				for(i=0;i<indent;i++)
					fputc('\t',fp2);
			}
			fputc(ch,fp2);
		}
	}
	if(indent <= 0) 
		printf("Valid JSON..!");
	fclose(fp1);
	fclose(fp2);
}

void main()
{
	pretify("input.json","output.json");
	getche();
}