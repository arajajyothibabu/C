#include<stdio.h>
#include<conio.h>
#include<stdio.h>
struct test{
	char a[10];
	int n[2];
	int o[2];
}testc[8]={{"Araja",{},{2,3}},
{"aAaA123",{},{0,4}},
{"r&d2014",{},{2,0}},
{"Mission",{},{4,3}},
{"123abc",{},{2,1}},
{"Araja JB",{},{4,3}},
{"%!@#$^",{},{0,0}},
{"AAAiii",{},{0,6}}
};
void fun(char *a,int *n)
{
	int x=0,y=0;
	for(int i=0;a[i]!='\0';i++)
		if(a[i]<91&&a[i]>64||a[i]>96&&a[i]<123)
		{
			if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U')
				x++;
			else y++;
		}
	n[0]=y;n[1]=x;
}

void call()
{
	int i;
	for(i=0;i<8;i++)
	{
		fun(testc[i].a,testc[i].n);
		if(testc[i].n[0]==testc[i].o[0]&&testc[i].n[1]==testc[i].o[1])
			printf("%d.PASSED..!\n",i+1);
		else printf("%d.FAILED..!\n",i+1);
	}
}
void main()
{
	call();
	getch();
}