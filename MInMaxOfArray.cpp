#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//finding maximum and minimum element of an Array
struct test{
	int a[10];
	int n;
	int arr[2];
	int max;
	int min;
}testc[8]={{{1,2,3,4,5},5,{},5,1},
{{5,4,4,4,4},5,{},5,4},
{{4,4,4,4,4},5,{},4,4},
{{-2,2,3,-1,4},5,{},4,-2},
{{-1,1,-2,2},4,{},2,-2},
{{0},1,{},0,0},
{{-1,1},2,{},1,-1},
{{34,-99,278,-456,234,1000},6,{},1000,-456}
};
void fun(int *a,int n,int *arr)
{
	int i,min=a[0],max=a[0];
	for(i=1;i<n;i++)
	{
		if(max<a[i])
			max=a[i];
		if(min>a[i])
			min=a[i];
	}
	arr[0]=max;
	arr[1]=min;
}
void call()
{
	int i,j;
	for(i=0;i<8;i++)
	{
		fun(testc[i].a,testc[i].n,testc[i].arr);
		if(testc[i].max==testc[i].arr[0]&&testc[i].min==testc[i].arr[1])
			printf("%d.PASSED..!\n",i+1);
		else printf("%d.FAILED..!\n",i+1);		
	}
}
void main()
{
	/*int n,*a,i;
	printf("Enter Array Size: ");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	printf("Enter Array: ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	fun(a,n);
	printf("Max: %d\n",a[0]);
	if(a[0]==a[1])
		printf("Max and Min are same..!");
	else
		printf("Min: %d ",a[1]);*/
	call();
	getch();
}
