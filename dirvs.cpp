#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int abs(int n)
{
	return n>0?n:-n;
}

int check(int x,int y,int **path,int count)
{
	int i=0;
	for(i=0;i<count;i++)
	{
		if(path[i][0] == x && path[i][1] == y)
			return 0;
	}
	return 1;
}

void traverse(int p,int q,int r1,int c1,int r2,int c2, int **a,int **path,int length,int i,int j,int count)
{
	int step=0,x=0,y=0, flag = 0;
	if(r1==r2 && c1==c2)
	{
		printf("The shortest path is %d steps long.",count);
		return;
	}
	else
	{
		step = a[r1][c1];
		if((r1+1 < p && (abs(a[r1+1][c1]-step) <= 1 || abs(step - a[r1+1][c1]) <= 3)) && check(r1+1,c1,path,count))
		{
			flag  = 1;
			x = r1+1;
			y = c1;
			path[count][0] = x;
			path[count][1] = y;
			traverse(p,q,x,y,r2,c2,a,path,length+1,r1,c1,count+1);
		}
		if((c1 + 1 < q && (abs(a[r1][c1+1]-step) <= 1 || abs(step - a[r1][c1+1]) <= 3)) && check(r1+1,c1,path,count))
		{
			flag = 1;
			x = r1;
			y = c1+1;
			path[count][0] = x;
			path[count][1] = y;
			traverse(p,q,x,y,r2,c2,a,path,length+1,r1,c1,count+1);
		}
		if((r1 - 1 > -1 && (abs(a[r1-1][c1]-step) <= 1 || abs(step-a[r1-1][c1]) <= 3)) && check(r1+1,c1,path,count))
		{
			flag = 1;
			x = r1-1;
			y = c1;
			path[count][0] = x;
			path[count][1] = y;
			traverse(p,q,x,y,r2,c2,a,path,length+1,r1,c1,count+1);
		}
		if((c1-1 > -1 && (abs(a[r1][c1-1]-step) <= 1 || abs(step - a[r1][c1-1]) <= 3)) && check(r1+1,c1,path,count))
		{
			flag = 1;
			x = r1;
			y = c1-1;
			path[count][0] = x;
			path[count][1] = y;
			traverse(p,q,x,y,r2,c2,a,path,length+1,r1,c1,count+1);
		}
		if(!flag)
		{
			if(r1+1 == p-1 || r1-1 == 0)
			{
				traverse(p,q,r1,c1,r2,c2,a,path,length-1,r1,c1,count);
			}
			else if(c1+1 == q-1 || c1-1 == 0)
			{
				traverse(p,q,r1,c1,r2,c2,a,path,length-1,r1,c1,count);
			}
			printf("Mission impossible!");
			for(int i = 0;i<count;i++)
			{
				printf("%d----%d",path[i][0],path[i][1]);
			}
			return;
		}
	}
}

void process()
{
	int P,Q,R1=0,C1=0,R2=0,C2=0,i,j;
	scanf("%d%d",&P,&Q);
	int **a = (int **)malloc(sizeof(int *)*P);
	int **path = (int **)malloc(sizeof(int *)*P*Q);
	for(i=0;i<P;i++)
		a[i] = (int *)malloc(sizeof(int)*Q);
	for(i=0;i<P*Q;i++)
		path[i] = (int *)malloc(sizeof(int)*2);
	for(i=0;i<P;i++)
		for(j=0;j<Q;j++)
			scanf("%d",&a[i][j]);
	scanf("%d%d%d%d",&R1,&C1,&R2,&C2);
	traverse(P,Q,R1-1,C1-1,R2-1,C2-1,a,path,0,-1,-1,0);
}

void main()
{
	int i,T;
	scanf("%d",&T);
	for(i=0;i<T;i++)
		process();
	getch();
}