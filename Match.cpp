//*mission*coding*stars*.doc*
//2015_missionr&dcodingrockstars.docx

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

bool Match(char *str, char *pattern)
{
	int i=0,j=0,k=0,c=0,p =0,q=0,regFlag=0, flag = 0;
	for(;pattern[i]!='\0';i++)
	{
		c=0;
		regFlag = 0;
		if(pattern[i] == '*')
		{
			p = i+1;
			q = p;
			for(j=k;str[j]!= '\0';j++)
			{
				if((pattern[p] == '*' || pattern[p] == '\0') && p-i-1 != c)
					return false;
				else if((pattern[p] == '*'|| pattern[p] == '\0')) 
					break;
				if(pattern[p] == str[j])
				{
					regFlag = 1;
					c++;
				}
				else if(str[j] == pattern[q])
				{
					p=q;
					c = 0;
				}
				else
				{
					regFlag = 0;
					p = q;
					c = 0;
				}
				if(regFlag) p++;
			}
			if(str[j] == '\0' && strcmp(str,"") == 0) return false;
			k = j;
			i = p-1;
		}
		else
		{
			while(pattern[i] != '*' && str[j]!='\0')
			{
				if(str[j] != pattern[i])
					return false;
				i++;j++;
			}
		}
	}
	return true;
}

void execute()
{
	if(Match("","*"))
		printf("Matched");
	else
		printf("Not matched");
}

void main()
{
	execute();
	getche();
}