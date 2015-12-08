#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct test             //considering only single '0' in 2D array.
{
int l;
int inp[10][10];
int out[10][10];
}testc[4]={
	{3,{{1,2,3},{4,0,6},{7,8,9}},{{1,0,3},{0,0,0},{7,0,9}}},
	{3,{{0,2,3},{4,5,6},{7,8,9}},{{0,0,0},{0,5,6},{0,8,9}}},
	{3,{{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}}},
	{2,{{0,2},{3,4}},{{0,0},{0,4}}}
};

int **trans(int **s,int n)
{
	int i,j,k,flag=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(s[i][j]==0)
			{
				for(k=0;k<n;k++)
				{
					s[i][k]=0;
					s[k][j]=0;
				}
				flag=1;
				break;
			}
		if(flag==1) break;
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
	trans(s,3);*/
	
	call(testc,4);
	getch();
}