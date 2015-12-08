#include<stdio.h>
#include<conio.h>
#include<math.h>
bool right(float,float,float);
float pw(float,float);
char fun(float,float,float,float,float,float);
void main()
{
	float a1,b1,a2,b2,a3,b3;
	scanf("%f%f%f%f%f%f",&a1,&b1,&a2,&b2,&a3,&b3);
	switch(fun(a1,b1,a2,b2,a3,b3))
	{
	case 'e':printf("%s","and it is Equilateral");break;
	case 'x':printf("%s","and it is Isosceles Right Angled");break;
	case 'i':printf("%s","and it is Isosceles");break;
	case 's':printf("%s","and it is Scalene");break;
	case 'r':printf("%s","and it is Right Angled");break;
	default:printf("How can we say its type..!!!");
	}
	getch();
}
char fun(float a1,float b1,float a2,float b2,float a3,float b3)
{
	float a,b,c;
	float m1,m2,m3;
	//m1=(b2-b1)/(a2-a1);
	//m2=(b3-b2)/(a3-a2);
	//m3=(b1-b3)/(a1-a3);
	char e='e',i='i',r='r',z='x',s='s';
	a=(pw(b2-b1,2)+pw(a2-a1,2));/*printf("a=%f\n",a);*/
	b=(pw(b3-b2,2)+pw(a3-a2,2));/*printf("b=%f\n",b);*/
	c=(pw(b1-b3,2)+pw(a1-a3,2));/*printf("c=%f\n",c);*/
	if(sqrt(a)<sqrt(b)+sqrt(c)&&sqrt(b)<sqrt(a)+sqrt(c)&&sqrt(c)<sqrt(a)+sqrt(b))
	//if(m1==m2||m1==m3||m2==m3)
	{
		printf("Its a Triangle..!\n");	
		if(a==b&&a==c&&c==b)
			return e;
		else if(a==b&&a!=c||b==c&&b!=a||a==c&&a!=b)
		{
			if(right(c,a,b)||right(a,b,c)||right(b,a,c))
				return z;
			else
				return i;
		}
		else if(right(c,a,b)||right(a,b,c)||right(b,a,c))
			return r;
		else
			return s;
	}
	else
		printf("Not a Triangle..!\n");
}
float pw(float a,float b)
{
	int i;
	float mul=1;
	for(i=1;i<=b;i++)
		mul=mul*a;
	return mul;
}
bool right(float a,float b,float c)
{
	if(a==(b+c))
		return true;
	else
		return false;
}