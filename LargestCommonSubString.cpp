#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct testcases
{
	char param1[100], param2[100], output[100];
	int l1,l2,l3;
}testcase[1]={
	{"surya teja","ravi teja"," teja",10,9,5}
};

int len(char *s)
{
	int i=0;
	for(i=0;s[i]!='\0';i++){}
	return i;
}

bool cmp(char *s, char *t)
{
	int c = 0,i = 0;
	if(len(s) != len(t))
		return false;
	else
		for(i=0;s[i]!='\0'&&t[i]!='\0';i++)
			if(s[i]==t[i])
				c++;
	return c==i?true:false;
}

char *largestCommonSubString(char *s1,char *s2)
{
	int i=0,j=0,k=0,l=0,flag =0,max=0, **indLen=(int **)malloc(sizeof(int)*2);
	char *output = (char *)malloc(sizeof(char)*10);
	for(l=0;l<10;l++)
		indLen[l] = (int *)malloc(2 * sizeof(int));
	for(;s1[i]!='\0';i++)
	{
		l = i;
		flag = 0;
		for(j=0;s2[j]!='\0' && s1[i]!='\0';j++)
		{
			if(s1[i] == s2[j]) 
			{
				flag==0?indLen[k++][0] = i:0;
				flag = 1;
				i++;
			}
			else 
			{
				flag==1?indLen[k-1][1] = i-l:0;
				i=l;
				flag = 0;
			}
		}
		if(s1[i-1] =='\0') break;
	}

	//taking 2nd string as reference
	/*for(i=0;s2[i]!='\0';i++)
	{
		l = i;
		flag = 0;
		for(j=0;s1[j]!='\0' && s2[i]!='\0';j++)
		{
			if(s2[i] == s1[j]) 
			{
				flag==0?indLen[k++][0] = i:0;
				flag = 1;
				i++;
			}
			flag==1?indLen[k-1][1] = i-l:0; 
		}
	}*/
	//finding max length
	for(i=0;i<k;i++)
		if(max <= indLen[i][1])
		{
			max = indLen[i][1];
			j = i;
		}
	k=0;
	for(i=j;i<max+j;i++)
		output[k++] = s1[i];
	output[k] = '\0';
	printf("%s",output);
	return output;
}

void test_cases()
{
	int i=0,j=0;
	for(;i<1;i++)
	{
		char *param1 = (char *)malloc(sizeof(char) * testcase[i].l1), *param2 = (char *)malloc(sizeof(char)*testcase[i].l2), *output = (char *)malloc(sizeof(char) * testcase[i].l3);
		for(j=0;j<testcase[i].l1;j++)
			param1[j] = testcase[i].param1[j];
		param1[j] = '\0';
		for(j=0;j<testcase[i].l2;j++)
			param2[j] = testcase[i].param2[j];
		param2[j] = '\0';
		for(j=0;j<testcase[i].l3;j++)
			output[j] = testcase[i].output[j];
		output[j] = '\0';
		if(cmp(largestCommonSubString(param1,param2),output))
			printf("%d. Passed\n",i+1);
		else printf("%d. Failed\n",i+1);
	}
}

void main()
{
	test_cases();
	getche();
}