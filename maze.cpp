#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct testcases
{
	char maze[100][200];
	int m;
	int n;
	int r1;
	int c1;
	int r2;
	int c2;
}TC[7]={
	{{"11000","01000","01111"},3,5,0,0,2,4},
	{{"11110","01101","00110","10110","01101","00111"},6,5,0,0,5,4},
	{{"00000","000000","00000"},3,5,0,0,2,4},
	{{"11111","10001","10001","10001","11111"},5,5,0,0,4,4},
	{{"110000","011100","000111"},3,6,0,0,2,5},
	{{"11111","11111","11111","11111"},4,5,0,0,3,4},
	{{"11111","00110","11111","00000"},4,5,0,0,0,4}
};

void str_cpy(char *a, char *b)
{
	int i=0;
	while(b[i]!='\0')
		a[i]=b[i++];
	a[i]='\0';
}

int valid_step(char **maze,int r1,int c1,int m,int n)
{
	if((r1>=0&&r1<m)&&(c1>=0&&c1<n)&& maze[r1][c1]=='1')// co-ordinates should be within the range specified
		return 1;
	else return 0;
}

void print_path(int **path,int len)
{
	int i;
	printf("path:");
	for(i=0;i<len;i++)
		printf("(%d %d)",path[0][i],path[1][i]);
}


void trace_path(char **maze ,int r1,int c1,int r2,int c2,int m,int n,int **path,int len)
{
	if(!valid_step(maze,r1,c1,m,n))
		return;
	else if(r1==r2&&c1==c2)
		{
			path[0][len]=r1;
			path[1][len]=c1;
			print_path(path,len+1);
	}
	else
	{
		path[0][len]=r1;
		path[1][len]=c1;
		maze[r1][c1]='n';
		trace_path(maze,r1+1,c1,r2,c2,m,n,path,len+1);
		trace_path(maze,r1-1,c1,r2,c2,m,n,path,len+1);
		trace_path(maze,r1,c1+1,r2,c2,m,n,path,len+1);
		trace_path(maze,r1,c1-1,r2,c2,m,n,path,len+1);
	}
}

void main()
{
	int i,j,k,**path;
	char **maze;
	for(i=0;i<7;i++)
	{
		maze=(char**)malloc(sizeof(char*)*TC[i].m);
		path=(int**)malloc(sizeof(int)*TC[i].m);
		for(j=0;j<TC[i].m;j++)
			path[j]=(int*)malloc(sizeof(int)*TC[i].n);
		for(j=0;j<TC[i].m;j++)
			{
				maze[j]=(char*)malloc(sizeof(char)*TC[i].n);
				str_cpy(maze[j],TC[i].maze[j]);
			}
		if(TC[i].r2>=0&&TC[i].c2<=TC[i].n)
			trace_path(maze,TC[i].r1,TC[i].c1,TC[i].r2,TC[i].c2,TC[i].m,TC[i].n,path,0);
		else printf("Choose a valid start position");
		printf("\n\n");
	}
	getche();
}