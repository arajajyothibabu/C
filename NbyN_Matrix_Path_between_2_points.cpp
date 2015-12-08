
//given n*n matrix, 0,1. given two positions find whether there is path or not
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct test
{
	int x1,y1,x2,y2,rows,cols;
	char arr[10][10];
	//int output[20];
} testCase[6]={
	{2,1,1,6,6,7,{{1,0,0,0,0,0,0},{1,0,0,0,1,1,1},{1,1,1,0,1,0,1},{0,0,1,0,1,0,1},{0,0,1,1,1,0,1},{0,0,0,0,0,0,1}}},
	{3,3,2,2,4,4,{{0,0,0,0},{1,1,1,1},{0,0,0,0},{1,1,1,1}}},
	{0,0,2,4,3,5,{{1,1,0,0,0},{0,1,0,0,0},{0,1,1,1,1}}},
	{1,1,3,4,4,5,{{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}}},
	{5,6,2,3,3,2,{{1,1},{1,0},{0,1}}},
	{1,1,1,1,2,2,{{1,0},{0,1}}}
};

void findPath(int x1,int y1,int x2, int y2, char **arr,int rows,int cols,int *a, int length)
{
	if(x1 >= rows || x2 >= rows || y1 >= cols || y2 >= cols || x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0)
		return;
	else if(x1 == x2 && y1 == y2)
	{
		printf("\nPath :-\n");
		for(int i=0;i<length;i=i+2)
			printf("(%d , %d)\n",a[i],a[i+1]);
		printf("(%d , %d)\n",x2,y2);
		return;
	}
	else if(arr[x1][y1] == 0)
		length = 0;
	else 
	{
		a[length] = x1;
		a[length+1] = y1;
		arr[x1][y1] = 0;
		findPath(x1+1,y1,x2,y2,arr,rows,cols,a,length+2);
		findPath(x1-1,y1,x2,y2,arr,rows,cols,a,length+2);
		findPath(x1,y1+1,x2,y2,arr,rows,cols,a,length+2);
		findPath(x1,y1-1,x2,y2,arr,rows,cols,a,length+2);
	}
}

void performAction(int x1,int y1,int x2, int y2, char **arr,int rows,int cols,int *a, int length)
{
	if(x1 >= rows || x2 >= rows || y1 >= cols || y2 >= cols || x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0)
		printf("Invalid Points");
	else findPath(x1,y1,x2,y2,arr,rows,cols,a,length);
}

void execute()
{
	int i=0,m=0,n=0, *a = (int *)malloc(sizeof(int)*20);
	char **path = (char **)calloc(sizeof(char),6);
	for(i=0;i<6;i++)
		path[i] = (char *)calloc(sizeof(char),7);
	char **arr = (char **)calloc(sizeof(char),6);
	for(i=0;i<6;i++)
		arr[i] = (char *)calloc(sizeof(char),7);
	for(int k=0;k<6;k++)
	{
	for(i=0;i<testCase[k].rows;i++)
		for(int j=0;j<testCase[k].cols;j++)
			if(testCase[k].arr[i][j] == 1)
				arr[i][j] = 1;
	printf("\n******************************** %d *************************************\n",k+1);
	performAction(testCase[k].x1,testCase[k].y1,testCase[k].x2,testCase[k].y2,arr,testCase[k].rows,testCase[k].cols,a,0);
	}
}

void main()
{
	execute();
	getche();
}