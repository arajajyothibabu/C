#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct test
{
int l;
int inp[10][10];
int out[10][10];
}testc[4]={
	{3,{{1,2,3},{4,5,6},{7,8,9}},{{1,4,7},{2,5,8},{3,6,9}}},
	{5,{{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}},{{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}}},
	{3,{{1,-2,3},{4,-5,6},{7,-8,9}},{{1,4,7},{-2,-5,-8},{3,6,9}}},
	{3,{{1,1,1},{2,2,2},{3,3,3}},{{1,2,3},{1,2,3},{1,2,3}}}
};

int **trans(int **s,int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			s[i][j]=s[i][j]+s[j][i];
			s[j][i]=s[i][j]-s[j][i];
			s[i][j]=s[i][j]-s[j][i];
		}
		return s;
}

void call(struct test testc[],int l)
{
	int **input,**output,n;
	for(int k=0;k<l;k++)
	{
		int c=0,flag=0,i,j;
		n=testc[k].l;
		input=(int**)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
		input[i]=(int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				input[i][j]=testc[k].inp[i][j];
						output=(int**)malloc(n*sizeof(int));
						for(i=0;i<n;i++)
						output[i]=(int*)malloc(n*sizeof(int));
						for(i=0;i<n;i++)
							for(j=0;j<n;j++)
								output[i][j]=testc[k].out[i][j];
		trans(input,n);
				for(i=0;i<n;i++)
				{
					for(j=0;j<n;j++)
					if(input[i][j]==output[i][j])
						c++;
					else {flag=1;break;}
					if(flag==1) break;
				}
			if(n*n==c) printf("Passed..!\n");
			else printf("Failed..!\n");
	}
}

void main()
{
	/*int n=3,i,j;
	int **s;
	s=(int**)malloc(3*sizeof(int));
	for(i=0;i<n;i++)
	s[i]=(int*)malloc(3*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&s[i][j]);
	trans(s,3);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",s[i][j]);
	printf("\n");
	}*/
	call(testc,4);
	getch();
}