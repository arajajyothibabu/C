#include<stdio.h>
#include<conio.h>
int fun(char []);
void fun1(int);
void fun2(int);
void main()
{
	char s[10],i;
	printf("Enter Date: ");
	for(i=0;i<10;i++)
	scanf("%c",&s[i]);
	fun(s);
	getche();
}
int fun(char k[])
{
	int i,s[10];
	for(i=0;i<10;i++)
		s[i]=k[i]-'0';
	//code for day
	if(s[0]==0||s[0]==2||s[0]==3)
	{
		if(s[1]==0&&s[0]==0||s[3]==0&&s[4]==0||s[3]==0&&s[4]==2&&(s[0]*10+s[1])>=28)
			{
				printf("Invalid Date..!");
				return 0;
			}
		else
		{
		if(s[0]==2)
		{
			if(s[1]==0)
				printf("Twentieth ");
			else
				printf("Twenty ");
		}
		else if(s[0]==3)
		{
			if(s[1]==1)
				printf("Thirty first ");
			else if(s[1]==0)
				printf("Thirthieth ");
			else
			{
				printf("Invalid Date..!");
				return 0;
			}
		}
		if(s[1]!=0&&s[0]<3)
				switch(s[1])
					{
					case 1:printf("First ");break;
					case 2:printf("Second ");break;
					case 3:printf("third ");break;
					case 4:printf("fourth ");break;
					case 5:printf("fifth ");break;
					case 6:printf("sixth ");break;
					case 7:printf("seventh ");break;
					case 8:printf("eighth ");break;
					case 9:printf("ninth ");break;
					default:;
					}
		}
	}
	else if(s[0]==1)
	{
		if(s[1]==0)
			printf("Tenth ");
		else
			{
				fun1(s[1]);
				printf("th ");
			}
	}
	else 
	{
		printf("Invalid Date");
		return 0;
	}
	//code for month
	if(s[3]==0)
		switch(s[4])
			{
		case 0:{printf("Invalid Date ");return 0;}break;
				case 1:printf("January ");break;
				case 2:printf("February ");break;
				case 3:printf("March ");break;
				case 4:printf("April ");break;
				case 5:printf("May ");break;
				case 6:printf("June ");break;
				case 7:printf("July ");break;
				case 8:printf("August ");break;
				case 9:printf("September ");break;
				default:;
			}
	else if(s[3]==1)
		switch(s[4])
		{
			case 0:printf("October ");break;
			case 1:printf("November ");break;
			case 2:printf("December ");break;
			default:printf("Invalid date");return 0;
		}
	else
	{
		printf("Invalid Month");return 0;
	}
	//code for year
	if(s[6]>0)
	{
		fun2(s[6]);
		printf("thousand ");
	}
	if(s[6]>=0)
	{
		fun2(s[7]);
		if(s[8]==0&&s[9]==0&&s[7]!=0)
			printf("hundered.");
		else if(s[7]!=0)
			printf("hundered and ");
	}
	if(s[8]==1)
		fun1(s[9]);
	else if(s[8]!=1||s[8]==0)
	{
		switch(s[8])
			{
				case 0:printf("");break;
				case 2:printf("twenty ");break;
				case 3:printf("thirty ");break;
				case 4:printf("forty ");break;
				case 5:printf("fifty ");break;
				case 6:printf("sixty ");break;
				case 7:printf("seventy ");break;
				case 8:printf("eighty ");break;
				case 9:printf("ninty ");break;
				default:;
			}
			fun2(s[9]);
	}
}
//end of fun()
void fun1(int i)
{
	switch(i)
				{
					case 0:printf("Ten.");break;
					case 1:printf("eleven");break;
					case 2:printf("twelve");break;
					case 3:printf("thirteen");break;
					case 4:printf("fourteen");break;
					case 5:printf("fifteen");break;
					case 6:printf("sixteen");break;
					case 7:printf("seventeen");break;
					case 8:printf("eighteen");break;
					case 9:printf("ninteen");break;
					default:;
				}
}
void fun2(int i)
{
	switch(i)
				{
				case 0:printf("");break;
				case 1:printf("one ");break;
				case 2:printf("two ");break;
				case 3:printf("three ");break;
				case 4:printf("four ");break;
				case 5:printf("five ");break;
				case 6:printf("six ");break;
				case 7:printf("seven ");break;
				case 8:printf("eight ");break;
				case 9:printf("nine ");break;
				default:;
				}
} 