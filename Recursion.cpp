#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int fib(int n)
{
	return n==1?1:n==2?1:fib(n-1)+fib(n-2);
}

int fibwithoutBase(int n)
{
	return fibwithoutBase(n-1)+fibwithoutBase(n-2);
}

int search2(int key,int *a,int low,int high)
{
	int mid = (high+low)/2;
	if(key == a[mid])
		return mid;
	else if(low==high)
		return -1;
	else if(low<=high)
	{
		search2(key,a,low,mid-1);
		search2(key,a,mid+1,high);
		//int temp = search2(key,a,low,mid-1);
		//return temp!=-1?temp:search2(key,a,mid+1,high);
	}
}

int search1(int key,int *a,int length)
{
	if(key == a[length])
		return length;
	else if(length<0)
		return -1;
	else
		return search1(key,a,length-1);
}

int climbs(int n,int count)
{
	return n==0?count:n-1==0?climbs(n-1,count+1):n-2==0?climbs(n-2,count+2):climbs(n-1,count) + climbs(n-2,count);
}

int paths(int n,char *steps,int count)
{
	printf("%s",steps);
	if(n==0)
	{
		printf("\n");
		return count;
	}
	else if(n-1 == 0)
		return paths(n-1,steps,count+1);
	else if(n-2 == 0)
		return paths(n-2,steps,count+2);
	else
		return paths(n-1,"-S-",count) + paths(n-2,"-D-",count);
}

void pathsprint(int n,char *steps,int length)
{
	if(n==0)
	{
		steps[length] = '\0';
		printf("%s\n",steps);
	}
	if(n<0)
		return;
	steps[length] = 'S';
	pathsprint(n-1,steps,length+1);
	steps[length] = 'D';
	pathsprint(n-2,steps,length+1);
}

void printPaths(int n,char *steps,int length)
{
	if(n==0)
	{
		steps[length] = '\0';
		printf("%s\n",steps);
	}
	else if(n==1)
	{
		steps[length] = 'S';
		steps[length+1] = '\0';
		printf("%s\n",steps);
	}
	else
	{
		steps[length] = 'S';
		printPaths(n-1,steps,length+1);
		steps[length] = 'D';
		printPaths(n-2,steps,length+1);
	}
}

void subSetsOf(int now,int high)
{
	int i=1,k=1;
	for(k=now;k<now+1;k++)
	{
		for(i=1;i<=high;i++)
			if(i<k&&i>k)
				printf("%d ",i);
		printf("\n");
	}
	if(now!=high)
	subSetsOf(now+1,high);
}

void printSubSets(int n,int candidate,bool *selected)
{
	if(n==candidate)
	{
		for(int i=0;i<n;i++)
			if(selected[i])
				printf("%d",i+1);
		printf("\n");
	}
	if(n<candidate) return;
	selected[candidate] = false;
	printSubSets(n,candidate+1,selected);
	selected[candidate] = true;
	printSubSets(n,candidate+1,selected);
}

void swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void printPermuations(int n,int live,int *stock)
{
	int i=0;
	if(live == n)
	{
		for(i=0;i<n;i++)
			printf("%d ",stock[i]);
		printf("\n");
	}
	for(i=live;i<n;i++)
	{
		swap(&stock[i],&stock[live]);
		printPermuations(n,live+1,stock);
		swap(&stock[i],&stock[live]);
	}
}

bool placeQueen(int k,int i,int *solution)
{
	int j=0;
	for(j=0;j<k;j++)
		if(solution[j] == i || abs(solution[j]-i)==abs(j-k))
			return false;
	return true;
}

static int c = 0;

void N_Queens(int k,int n,int *solution)
{
	int i=0,j=0;
	for(i=0;i<n;i++)
		if(placeQueen(k,i,solution))
		{
			solution[k] = i;
			if(k==n-1)
			{
				for(int k=0;k<n;k++)
				{
					for(j=0;j<n;j++)
						if(solution[k] == j)
							printf("%d  ",1);
						else printf("%d  ",0);
					printf("\n\n");
				}
				printf("\n\n");
			}
			else N_Queens(k+1,n,solution);
		}
}

int getParanthesis(char *expression,int n)
{
	return 1;
}

void printParanthesis(char *expression)
{
	
}

int main()
{
	int a[8] = {1,2,3,8,7,6,5,4};
	int solution[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
	char *temp = (char *)malloc(sizeof(char)*10);
	bool *selected = (bool *)malloc(sizeof(bool)*10);
	int stock[4] = {3,1,2};
	char expression[6] = "a+b*c";
	//int *sol = (int *)malloc(sizeof(int)*10);
	//printf("%d",fibwithoutBase(3));
	//printf("%d",fib(3));
	//printf("%d",search1(4,a,7));
	//printf("%d",search2(4,a,0,7));
	//pathsprint(5,temp,0);
	//printPaths(5,temp,0);
	//pathsprint(5,temp,0);
	//printf(subSetsOf(0,4);
	//printSubSets(4,0,selected);
	printPermuations(3,0,stock);
	//N_Queens(0,8,solution);
	//printParanthesis(expression);
	//printf("Number of ways: %d",getParanthesis(expression,0));
	getche();
	return 0;
}
