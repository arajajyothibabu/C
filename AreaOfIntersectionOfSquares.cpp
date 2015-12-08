#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int area(int a1,int a2,int b1,int b2,int x1,int x2,int y1,int y2)
{
	int i,j;
	if(x1>a2||y1>=b2)
		return 0;
	else if(x1<=a2&&x1>=a1&&y1>=b1&&y1<=b2&&x2>=a2&&y2>=b2)
		return (b2-y1)*(a2-x1);
	else if(x1<=a2&&x1>=a1&&y1>=b1&&y1<=b2&&x2<=a1&&y2>=b2)
		return (b2-y1)*(a1-x1);
	else if(x1<=a2&&x1>=a1&&y1>=b1&&y1<=b2&&x2>=a2&&y2<=b2)
		return (y2-y1)*(a2-x1);
	else if(x1<=a2&&x1>=a1&&y1>=b1&&y1<=b2&&x2<=a2&&y2>=b2)
		return (x2-x1)*(b2-y1);
	else if(x1<=a2&&x1>=a1&&y1>=b1&&y1<=b2&&x2<=a1&&y2<=b2)
		return (y2-y1)*(x1-a1);
	else if(x1<=a2&&x1>=a1&&y1>=b1&&y1<=b2&&x2<=a2&&y2<=b2&&b1>=y2)
		return (x2-x1)*(y1-b1);
	else if(x1<=a2&&x1>=a1&&y1>=b1&&y1<=b2&&x2<=a2&&y2<=b2)
		return (x2-x1)*(y2-y1);
}
int fun(int a1,int b1,int a,int x1,int y1,int b)
{
	int i,j,k,s,o;
		printf("1. Up Right\t2. Up Left\t3. Down Left\t4.Down Right\t0. Exit\nSelect the option for position of squares: ");
		scanf("%d",&s);
		printf("1. Up Right\t2. Up Left\t3. Down Left\t4.Down Right\nSelect the option for position of squares: ");
		scanf("%d",&o);
		switch(s)
		{
		case 1:switch(o)
				{
				case 1:return area(a1,a1+a,b1,b1+a,x1,x1+b,y1,y1+b);break;//(1 up right)
				case 2:return area(a1,a1+a,b1,b1+a,x1,x1-b,y1,y1+b);break;//(2 up left)
				case 3:return area(x1-b,x1,y1-b,y1,a1,a1+a,b1,b1+a);break;//(3 down left)
				case 4:return area(x1,x1+b,y1-b,y1,a1+a,a1,b1,b1+a);break;//(4 down right)
				default:{printf("Invalid Selection..!");return 0;}
				}
		case 2:switch(o)
			   {
				case 1:return area(a1-a,a1,b1,b1+a,x1,x1+b,y1,y1+b);break;
				case 2:return area(a1-a,a1,b1,b1+a,x1,x1-b,y1,y1+b);break;
				case 3:return area(x1-b,x1,y1-b,y1,a1,a1-a,b1,b1+a);break;
				case 4:return area(x1,x1+b,y1-b,y1,a1,a1-a,b1,b1+a);break;
				default:{printf("Invalid Selection..!");return 0;}
			   }
		case 3:switch(o)
			   {
				case 1:return area(a1-a,a1,b1-a,b1,x1,x1+b,y1,y1+b);break;
				case 2:return area(a1-a,a1,b1-a,b1,x1,x1-b,y1,y1+b);break;
				case 3:return area(a1-a,a1,b1-a,b1,x1,x1-b,y1-b,y1);break;
				case 4:return area(a1-a,a1,b1-a,b1,x1,x1+b,y1-b,y1);break;
				default:{printf("Invalid Selection..!");return 0;}
			   }
		case 4:switch(o)
			   {
				case 1:return area(a1,a1+a,b1-a,b1,x1,x1+b,y1,y1+b);break;
				case 2:return area(a1,a1+a,b1-a,b1,x1,x1-b,y1,y1+b);break;
				case 3:return area(a1,a1+1,b1-1,b1,x1-b,x1,y1-b,y1);break;
				case 4:return area(a1,a1+a,b1-a,b1,x1,x1+b,y1-b,y1);break;
				default:{printf("Invalid Selection..!");return 0;}
			   }
		default:{printf("Invalid Selection..!");return 0;}
		}
}
int abs(int x)
{
	if(x>0) return x;
	else return -x;
}
void main()
{
	int a,b,i,m,n,x1,y1,x2,y2,x;
	printf("Enter Square1(x1 y1 area): ");
	scanf("%d%d%d",&x1,&y1,&a);
	printf("Enter Square2(x2 y2 area): ");
	scanf("%d%d%d",&x2,&y2,&b);
	x=fun(x1,y1,a,x2,y2,b);
	if(x==0)
	printf("\nNo Intesection Area: %d",x);
	else
		printf("\nIntersection Area: %d ",abs(x));
	getch();
}