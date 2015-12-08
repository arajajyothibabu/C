#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int setBit_Position(int n)
{
	for(int i=1;i<=n;i++)
		if(n & 1<<i)
			return n&n-1?-1:i+1;
	return -1;
}

void main()
{
	int n;
	printf("Enter Number: \n");
	scanf("%d",&n);
	printf("%d",setBit_Position(n));
	//testcases();
	getche();
}

//given a number return the set bit position. Read a valid integer(2,4,8,16,32)
/*given a date in string format(ddmmyyyy) and a number as input write program to add that many days to the given date a nd print new date
eg: "31012015" and 1 "01022015"
/*
2.given many numbers in string format  ,seperated values. add all the  numbers and print out the result.
eg: 1234,123 = 1357

3. given an array of structure: subid,marks for each subject. find the average marks, total average mark. There are only max of 8 sub-ids. Marks range between 0-100. and no: of students are 60.
*/