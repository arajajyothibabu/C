#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//find sum of 2 numbers equal to given key for sorted array
void findSumtoKey1(int *input,int length,int key) //bruteforce
{
	int i=0,j=0;
	for(i=0;i<length;i++)
	{
		while(input[i]==input[i+1]) i++;
		for(j=i+1;j<length;j++)
		{
			while(input[j]==input[j+1]) j++;
			if(input[i]+input[j] == key)
				printf("\t%d  %d\n",input[i],input[j]);
		}
	}
}

void findSumtoKey2(int *input,int length,int key) //O(n) removing duplicates
{
	int i=0,j=length-1;
	while(i<=j)
		if(input[i]+input[j]>key)
			j--;
		else if(input[i]+input[j]<key)
			i++;
		else
		{
			while(input[i]==input[i+1]) i++;
			while(input[j]==input[j-1]) j--;
			printf("\t%d  %d\n",input[i],input[j]);
			i++;j--;
		}
}

int bin_Search(int *input,int low,int high,int key)
{
	int mid=0;
	while(low<high)
	{
		mid=(low+high)/2;
		if(input[mid]>key)
			high = mid-1;
		else if(input[mid]<key)
			low = mid + 1;
		else return mid;
	}
	return -1;
}

void findSumtoKey3(int *input,int length,int key)
{
	for(int i=0;i<length;i++)
	{
		while(input[i]==input[i+1]) i++;
		int k = key - input[i];
		int j = bin_Search(input,i,length-1,k);
		if(j!=-1)printf("\t%d  %d\n",input[i],input[j]);
	}
}

//rotate the Array
void rotateLeftArray(int *a, int length,int n)
{
	int *temp = (int *)malloc(sizeof(int)*n),i=0,j=0,k=0;
	for(;j<n;j++)
		temp[j] = a[j];
	for(;i<length-1;i++)
		if(i<n)
			a[i]=a[i+n];
		else
			a[i] = temp[k++];
}

void rotateRightArray(int *a, int length,int n)
{
	int i=0,k=0,j=0,end=0;
	for(;i<n;i++)
	{
		end = a[length-1];
		for(j=0;j<length-2;j++)
				a[j+1]=a[j];
		a[0] = end;
	}
}

void rotateArray(int *a,int length,int n)
{
	int temp1=a[0],temp2=0,count=0,cp=0,pos=0;
	while(count<length)
	{
		pos = (cp+n)%length;
		temp2 = a[pos];
		a[pos] = temp1;
		temp1 = temp2;
		cp = pos;
		count++;
	}
}

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

void rotateWithGCD(int *a,int length,int rotations)
{
	int j = 0,i = 0,partition = gcd(length,rotations%length);
	for(i=0;i<length;i++)
	{
		
	}
}

void reverse(int *a,int start,int end)
{
	for(;start<=end;start++,end--)
	{
		int temp = a[start];
		a[start] = a[end];
		a[end] = temp;
	}
}

void rotateWithReverse(int *a,int length,int n)
{
	reverse(a,0,n-1);
	reverse(a,n,length-1);
	reverse(a,0,length-1);
}

int bin_Search_theLast_Occurance(int *a,int low,int high,int key)//My own solution
{
	int mid=(low+high)/2;
	if(a[low]>key || a[high]<key)
		return -1;
	if(a[mid]>key)
		return bin_Search_theLast_Occurance(a,low,mid-1,key);
	else if(a[mid]<key)
		return bin_Search_theLast_Occurance(a,mid+1,high,key);
	else
	{
		if(a[mid] == a[mid+1]) return bin_Search_theLast_Occurance(a,mid+1,high,key);
		else return mid;
	}
}

int bin_Search_forLast_Occurance(int *a,int low,int high,int key)
{
	int index = -1,mid=(low+high)/2;
	while(low<high)
		if(a[mid]>key)
			high = mid-1;
		else if(a[mid]<key)
			low = mid + 1;
		else
		{
			index = mid;
			low = mid + 1;
		}
	return mid;
}

int binSearch(int *a,int start,int end,int key,int size)
{
	if(start > end) return -1;
	int mid = (start + end)/2;
	if(a[mid] == key && mid==size-1 || a[mid]<a[mid+1])
		return mid;
	else
	{
		if(a[mid]>key) return binSearch(a,start,mid-1,key,size);
		else return binSearch(a,mid+1,end,key,size);
	}
}

int rainWater(int *a,int n)
{
	int i=0,j=0,temp = 0,flagleft =0,flagright=0,leftMax = a[0],rightMax = a[n-1],area = 0,p=0,q=n-1,maxHeight=0,solidArea = 0,skipArea =0;
	if(n==2 || n==1) return 0; //if only one are two buildings
	for(i=1,j=n-2;i<n;i++,j--)// finding left_max height and right_max height of buildings
	{
		if(a[i]>=leftMax &&!flagleft)
		{
				leftMax = a[i];
				p = i;
		}
		else flagleft = 1;
		if(a[j]>=rightMax && !flagright)
		{
				rightMax = a[j];
				q = j;
		}
		else flagright=1;
	}
	if(p==q) return 0;						//where leftmax and right max buildings are same
	maxHeight = leftMax>rightMax?leftMax:rightMax;
	for(int k=p+1;k<q;k++)
		solidArea += a[k]>maxHeight?maxHeight:a[k];					//finding the area occupied by buildings
	area = maxHeight *(q-p-1);				// finding total area (area of water + area of concrete buildings + air(based on varying heights of buildings))
	for(int k=p+1;k<q;k++)
	{
		if(a[k]<leftMax)
			temp = maxHeight - leftMax;		 //subtracting area occupied by vaccum
		else if(a[k]>leftMax)
		{
			if(a[k]>=maxHeight)
			{
				leftMax = maxHeight;
				temp = 0;
			}
			else
			{
			temp = maxHeight-a[k];
			leftMax = a[k];
			}
		}
		else temp = 0;
		skipArea += temp; //sum up total vaccum area(area to skip for rain water)
	}
	return area - solidArea - skipArea; // return total area of water
}

void main()
{
	//for finding sum to key of 2 numbers
	int a[13] = {3,6,6,6,6,8,10,12,12,12,12,34,50};
	/*int key = 18;
	printf("BruteForce-O(n^2):\n");
	findSumtoKey1(a,13,key);
	printf("Iterate 2 way-Order(1):\n");
	findSumtoKey2(a,13,key);
	printf("Binary Search-O(nlogn):\n");
	findSumtoKey3(a,13,key);*/
	int ra[6] = {1,2,3,4,5,6};
	//rotateArray(ra,6,3);
	//reverse(ra,0,5);
	/*rotateWithReverse(ra,6,2);
	for(int i=0;i<6;i++)
		printf("%d ",ra[i]);*/
	int y[12] = {2,5,2,2,3,4,7,5,3,7,3,2};
	//int y[4] = {3,2,2,4};
	//int y[11] = {3,2,5,2,2,3,2,4,6,2,2};
	//printf("%d", bin_Search_theLast_Occurance(a,0,12,50));
	//printf("%d", rainWater(y,12));
	printf("%s",compressor("aaabaaaccccbb"));
	getche();
}
