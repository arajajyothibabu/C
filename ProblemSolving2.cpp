#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void fillDepths(int *parent,int *depths,int index)
{
	if(parent[index] == -1)
		depths[index] = 0;
	else
	{
		if(depths[parent[index]] == -1)
			fillDepths(parent,depths,parent[index]);
		depths[index] = depths[parent[index]]+1;
	}
}
//find max sum between indices
void findMaxSum(int *a,int length)
{
	int i=0,sum = a[0],arr[10];
	a[0] = sum;
	for(i=1;i<length;i++)
	{
		sum += a[i];
		arr[i] = sum;
		if(sum < 0) sum = 0;
	}
	for(i=0;i<length;i++)
	{

	}
}
//find binary sequence of numbers
int pow(int a,int b)
{
	int i=0,result=1;
	for(i=0;i<b;i++) result *= a;
	return result;
}

void binary_Sequence(int n)
{
	int i=0,m=pow(2,n);
	for(i=0;i<m;i++)
	{
		
	}
}

bool next_value(int *current,int N)
{
	int c=0;
	for(int i=0;i<N;i++)
		if(current[i] == 0)
		{
			c=1;
			break;
		}
	if(c == 0) return false;
	for(int i=N-1;i>=0;i++)
		if(current[i] == 1)
			current[i] = 0;
		else
		{
			current[i] = 1;
			break;
		}
	return true;
}

int *new_Counter(int *Counter)
{
	return 0;
}

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

int len(char *input)
{
	int i=0;
	for(;input[i]!=0;i++){}
	return i;
}

char *Next_Word(char *input)
{
	int l=len(input),i=0,j=0,isThere = 1;
	for(i=l-1;i>0;i--)
		if(input[i]>input[i-1])
			isThere = 0;
	if(isThere) 
		return "No further Lexicographic sequence..!";
	for(j=l-1;j>0;j--)
	{
		if(input[j-1]<input[j])
		{
			swap(&input[j],&input[j-1]);
			for(i=j;i<l-1;i++)
				if(input[i]>input[i+1])
					swap(&input[i],&input[i+1]);
			break;
		}
	}
	return input;
}

void permutator(int live,int length,char *stock)
{
	if(length == live)
	{
		printf("%s\n",stock);
	}
	else
	{
		for(int i=live;i<length;i++)
		{
			swap(&stock[i],&stock[live]);
			permutator(live+1,length,stock);
			swap(&stock[i],&stock[live]);
		}
	}
}

void main()
{
	int parent[10] = {4,3,4,-1,3,3,4,1,1,1};
	int depths[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	char s[6] = "apple";
	char *t = (char *)malloc(sizeof(char) * 15);
	//fillDepths(parent,depths,0);
	//int a[6] = {-8,10,-20,5,-2,6};
	//findMaxSum(a,6);
	//permutator(0,3,s);
	gets(t);
	printf("%s",filter(t));
	_getche();
}