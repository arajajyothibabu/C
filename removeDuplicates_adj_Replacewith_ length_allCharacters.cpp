#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct test{
	char a[120];
	char o[120];
}testc[8]={{"ARRAAAJJJJAAAAA","A,R-2,A-3,J-4,A-5"},
{"aaaaaaaaaa","a-10"},
{"ABCC","A,B,C-2"},
{"RRR&&&DDD","R-3,&-3,D-3"},
{"aaaaaaaaaa11111sssssssssssssss","a-10,1-5,s-15"},
{"",""},
{"a","a"},
{"ccc444222333","c-3,4-3,2-3,3-3"}
};
int pow(int a,int b)
{
	int r=1;
	for(int i=0;i<b;i++)
		r*=a;
	return r;
}
char *fun(char *a)
{
	int i,k=0,j=0,c=1,x,s=0,l=0,n=0;
	while(a[n]!='\0')
		n++;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]==a[i+1])
			c++;
		else 
		{
			a[k++]=a[i];
			if(c<=3||a[i+1]=='\0')                              //shifting code to adjust delimiters..!
			{
				for(j=n-1;j>i;j--)
					a[j+3]=a[j];
				n=n+3;
				i=i+3;
				a[n]='\0';
			}
			c==1? c=1:a[k++]='-';											//delimiter for symbol and frequency
			if(c>9)												//if number greater then 9
			{
				while(c/10!=0)
				{
					x=c;
					while(x/10!=0)
					{
						l++;x/=10;
					}
					a[k++]=x+'0';
					c-=x*pow(10,l);
					l=0;
				}
				a[k++]=c+'0';
			}
			else c==1?c=1:a[k++]=c+'0';									//if number less then 9
				c=1;
			a[i+1]=='\0'? c=1:a[k++]=',';					//delimiter for different symbols
		}
	}
	//a=(char *)realloc(a,k*sizeof(char));
	a[k]='\0';
	return a;
}


void call()
{
	int i;
	for(i=0;i<8;i++)
		if(strcmp(fun(testc[i].a),testc[i].o)==0)
			printf("%d.PASSED..!\n",i+1);
		else printf("%d.FAILED..!\n",i+1);
}
void main()
{
	/*char a[400];
	gets(a);
	printf("%s",fun(a));*/
	call();
	getch();
}