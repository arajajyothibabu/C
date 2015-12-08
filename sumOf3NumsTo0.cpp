#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int *threeElementSumToZero(int *a,int length)
{
	int i, j, k, isThere = 0, *temp = (int *)malloc(sizeof(int)*3);
	if(length > 3)
		for(i=0;i<length;i++)
			for(j=i+1;j<length;j++)
				for(k=j+1;j<length;j++)
					if(a[i]+a[j]+a[k] == 0)
					{
						printf("%d ",temp[0] = a[i]);
						printf("%d ",temp[1] = a[j]);
						printf("%d ",temp[2] = a[k]);
						isThere = 1;
					}
	else if(length == 3)
		if(a[0] + a[1] + a[2] == 0)
			return a;
	else printf("Invalid Length for Array..!");
	if(!isThere) printf("No such elements..!");
	return temp;
}

int *sort(int *a,int length)
{
	for(int i=0;i<length;i++)
		for(int j=0;j<length-i;j++)
			if(a[j]>a[j+1])
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
	return a;
}

int *threeElementSumToBeZero(int *a,int length)
{
	int start=0, end=length-1, sum=0, selected = 0, isThere = 0, *temp = (int *)malloc(sizeof(int)*3);
	if(length > 3)
	{
		//a = sort(a,length);
		while(start<end)
		{
			sum = a[start] + a[end];
			for(int i=start+1;i<end;i++)
			if(sum + a[i] == 0)
			{
				printf("%d ",temp[0] = a[start]);
				printf("%d ",temp[1] = a[end]);
				printf("%d ",temp[2] = a[i]);
				isThere = 1;
			}
			selected?start++:end--;
			selected = selected?0:1;
		}
	}
	else if(length == 3)
	{
		if(a[0] + a[1] + a[2] == 0)
			return a;
	}
	else printf("Invalid Length for Array..!");
	if(!isThere) printf("No such elements..!");
	return temp;
}

char *compressor(char *input)
{
		int i=0,j=0,index=0,counter=1;
		char previous='\0';
		if(input[0] !='\0')
		{
			previous = input[index++] = input[i];
			for(i=1;input[i]!='\0';i++)
			{
				if(input[i] != previous)
				{
					if(counter > 1) input[index++] = counter + '0';
					counter = 1;
					input[index++] = previous = input[i];
				}
				else if(input[i] == previous)
					counter++;
			}	
			if(counter > 1) input[index++] = counter + '0';
			input[index] = '\0';
		}
		return input;
}

//print reverse format of given strings.

struct outputs
{
	char output[100][100];
};

char *reverse(char *input)
{
	int i=0,j=0,length=0;
	char ch;
	for(;input[length]!='\0';length++);
	for(i=0,j=length-1;i<j;i++,j--)
	{
		ch = input[i];
		input[i] = input[j];
		input[j] = ch;
	}
	return input;
}

 struct outputs *dataFormatReversal(int length, char input[][100])
{
	struct outputs *Output = (struct outputs *)malloc(sizeof(struct outputs));
	for(int i=0;i < length;i++)
	{
		strcpy(Output->output[i],reverse(input[length-i-1]));
	}
	return Output;
}

char *removeChar(char *input,char ch)
{
	char *temp = (char *)malloc(sizeof(input));
	int i=0,index=0;
	for(;input[i]!='\0';i++)
		if(input[i]!=ch)
			output[index++] = input[i];
	output[index] = '\0';
}

void isThereString(char *main, char *sub)
{
	int i=0,j=0;
	for(i=0;main[i]!='\0';i++)
}
void main()
{
	//int a[8] = {3,1,-2,4,-1,0,1,-5};
	//threeElementSumToBeZero(a,8);
	char a[100][100];
	//char *input = (char *)malloc(sizeof(char) * 20);
	//printf("%s",compressor(gets(input)));
	int n;
	scanf("%d",&n);
	struct outputs *Output = (struct outputs *)malloc(sizeof(struct outputs));
	for(int i=0;i<n;i++)
	{
		fflush(stdin);
		gets(a[i]);
	}
	Output = dataFormatReversal(n,a);
	for(int i=0;i<n;i++)
	{
		printf("%s\n",Output->output[i]);
	}
	getche();
}