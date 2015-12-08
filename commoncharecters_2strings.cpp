#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void fun(char *,char *);
int len(char []);
void main()
{
	char s1[10],s2[10];
	printf("Enter String1 ");
	scanf("%s",s1);
	printf("Enter String2 ");
	scanf("%s",s2);
	fun(s1,s2);
	getch();
}
void fun(char *a,char *b)
{
	int i,j,k,c1[5],c2[5],flag=0,b1,a1,x=-1;
	a1=len(a);
	b1=len(b);
	for(i=0;i<a1;i++)
	{
		x=-1;
		for(j=0;j<b1;j++)
		{
			if(a[i]==b[j])
			{
				if(x==-1)
				{
				printf("%c\t",a[i]);
				for(k=0;k<a1;k++)
					{
						if(a[i]==a[k])
						{
						printf("%d ",k);
						}
					}
				printf("\t");
				}
				printf("%d ",j);x=0;
			}
		}
		printf("\n");
	}
}
int len(char a[])
{
	int i=0;
	while(a[i]!='\0')
		i++;
	return i;
}
