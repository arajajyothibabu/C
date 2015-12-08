#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct test{
	char a[120];
	char o[120];
}testc[8]={{"ARRAAAJJJJAAAAA","AR2A3J4A5"},
{"aaaaaaaaaa","a10"},
{"ABCCBA","ABC2BA"},
{"RRR&&&DDD","R3&3D3"},
{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","a110"},
{"",""},
{"a","a"},
{"cc++java","c2+2java"}
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
	int i,k=0,c=1,x,s=0,l=0;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]==a[i+1])
			c++;
		else 
		{
			a[k++]=a[i];
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
		}
	}
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