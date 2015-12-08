#include<stdio.h>
#include<conio.h>
int max(int [],int n);
//int max2(int[],int);
void main()
{
	int s[10],i=0,n;
	printf("Enter lenght: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&s[i]);
	printf("First Largest:- %d",max(s,n));
	getch();
}
int max(int s[],int n)
{
	int min,j,max,i,c=0;
	max=s[0];min=max;
		for(j=1;j<n;j++)
		{
			if(max<=s[j])
			{
				if(s[j]==max)
					c++;
				if(max!=s[j])
					min=max;
				max=s[j];
			}
			else if(min>s[j]&&min==max||min<s[j])
			{
				min=s[j];
				if(min<s[j+1]&&j!=n-1&&max!=s[j+1])
					min=s[j+1];
			}
		}
		if(c==n-1) printf("Second Largest:- None\n");
		else printf("Second Largest:- %d\n",min);
	return max;
}
