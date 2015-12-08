#include<stdio.h>
#include<conio.h>
#include<stdlib.h> 
int fun(char *s)
{
	int i,j,sum1=0,sum2=0,x=0,y;
	if(s[0]=='-')
		x=1;
	for(i=x;s[i]!=',';i++)
		sum1=sum1*10+s[i]-'0';          //for first number
	y=i+1;
	if(s[i+1]=='-')
		y=i+2;
	for(j=y;s[j]!='\0';j++)
		sum2=sum2*10+s[j]-'0';			//for second number
	if(x==1)
		sum1-=2*sum1;
	if(y==i+2)
		sum2-=2*sum2;
	if(sum1==sum2)
		printf("and it is equal to other number: ");
	if(sum1>=sum2)
		return sum1;
	else if(sum1<=sum2)
		return sum2;
}
void main()
{
	char *s;
	int x;
	s=(char *)malloc(5*sizeof(char));               //memory allocation
	printf("Enter two numbers seperated by delimiter(,) : ");
	scanf("%s",s);
	printf("Largest number ");
	printf("%d  ",fun(s));
	getch();
}