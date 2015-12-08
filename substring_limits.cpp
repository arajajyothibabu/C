#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
//Removing elements according to given range of ndices
struct test{
	char a[40];
	int I;
	int J;
	char o[10];
}testc[10]={{"Araja Jyothi Babu",6,11,"Jyothi"},
		{"Araja Jyothi Babu",11,6,"Jyothi"},
		{"Araja Jyothi Babu",5,6," J"},
		{"Mission Research and Development",-2,1,"Mi"},
		{"Mission Research and Development",30,36,"nt"},
		{"Mission Research and Development",36,29,"ent"},
		{"Mission Research and Development",34,89,""},
		{"Mission Research and Development",-6,-4,""},
		{"hai",1,1,"a"},
		{"",-2,2,""},
		};
char* fun(char *a,int I,int J)
{
	int i,k=0,n=0;
	if(I>J)
	{
		int t=I;
		I=J;
		J=t;
	}
	while(a[n]!='\0')
		n++;
	if(I>=0&&I<n||J>=0&&J<n)
		for(i=0;i<n;i++)
			if(i>=I&&i<=J)
				a[k++]=a[i];
	a[k]='\0';
	return a;
}
void call()
{
	int i,j,x,c;
	for(i=0;i<11;i++)
		if(strcmp(fun(testc[i].a,testc[i].I,testc[i].J),testc[i].o)==0)
			printf("%d.PASSED..!\n",i+1);
		else printf("%d.FAILED..!\n",i+1);
}
void main()
{
	/*char s[20];
	int i,j;
	gets(s);
	scanf("%d%d",&i,&j);
	
	printf("%s",fun(s,i,j));*/
	call();
	getch();
}