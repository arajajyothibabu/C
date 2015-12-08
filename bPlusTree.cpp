//Searching the data pages between given two key strings with string as key.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct metaPage
{
	int node[3];
	char value1[8],value2[8];
	char type[4];
};

struct dataPage
{
	char key[12];
	char data[12];
	int prev,next;
};

int len(char *s)
{
	int i=0;
	for(;s[i]!='\0';i++){}
	return i;
}

int cmp(char *s,char *t)
{
	int ls = len(s),lt = len(t),i,j,k;
	if(ls>lt) return 1;
	else if(ls<lt) return -1;
	else
	{
		for(i=0;i<ls;i++)
			if(s[i] > t[i])	return 1;
			else if(s[i] < t[i]) return -1;
		return 0;
	}
}

void insertData(char *file)
{
	FILE *fp = fopen(file,"rb+");
	int i=0;
	while(i<9)
	{
		struct dataPage dAta;
		printf("Enter Id\t:");fflush(stdin);
		gets(dAta.key);
		fflush(stdin);
		printf("Enter Data\t:");
		gets(dAta.data);
		if(i!=0)
			dAta.prev = i-1;
		else dAta.prev = '\0';
		dAta.next = i+1;
		fwrite(&dAta,32,1,fp);
		i++;
	}
	//writing metaPages
		for(int j=0;j<9;j =j+3)
		{
			struct metaPage meta;
			for(int i=0;i<3;i++)
			{
				struct dataPage Data;
				meta.node[i] = i+j;
				fseek(fp,(i+j)*32,SEEK_SET);
				fread(&Data,32,1,fp);
				if (i==0) strcpy(meta.value1,Data.key);
				if (i==1) strcpy(meta.value2,Data.key);
				meta.type[i] = '0';
			}
			fseek(fp,0,SEEK_END);
			fwrite(&meta,32,1,fp);
		}
	//writing metaPages for metaPages
		struct metaPage meta2;
		for(i=0;i<3;i++)
		{
			struct metaPage meta1;
			meta2.node[i] = 9+i;
			fseek(fp,(9+i)*24,SEEK_SET);
			fread(&meta1,32,1,fp);
			if (i==0) strcpy(meta2.value1,meta1.value2);
			if (i==1) strcpy(meta2.value2,meta1.value1);
			meta2.type[i] = '1';
		}
		fseek(fp,0,SEEK_END);
		fwrite(&meta2,32,1,fp);
}

int search(char *key, FILE *fp, int root)
{
	int flag = -1;
	struct dataPage Data;
	fseek(fp,root,SEEK_SET);
	struct metaPage meta;
	fread(&meta,32,1,fp);
	if(cmp(key,meta.value1) == -1)
	{
		if(meta.type[0] == '1')
		{
			printf("%d=>",meta.node[0]);
			return search(key,fp,meta.node[0]*32);
		}
		else flag = 0;
	}
	else if(cmp(key,meta.value2) == 1)
	{
		if(meta.type[2] == '1')
		{
			printf("%d=>",meta.node[2]);
			return search(key,fp,meta.node[2]*32);
		}
		else flag = 2;
	}
	else
	{
		if(meta.type[1] == '1')
		{
			printf("%d=>",meta.node[1]);
			return search(key,fp,meta.node[1]*32);
		}
		else flag = 1;
	}
	if(flag != -1)
	{
		printf("%d\n",meta.node[flag]);
		fseek(fp,meta.node[flag]*32,SEEK_SET);
		fread(&Data,32,1,fp);
		//return Data.data;
		return Data.next;
	}
	//else return "No data found..!";
	else return -1;
}

void printData(int offSet,FILE *fp)
{
	struct dataPage Data;
	printf("%d\n",offSet);
	fseek(fp,offSet*32,SEEK_SET);
	fread(&Data,32,1,fp);
	printf("%s\n",Data.data);
}

void searchBetween(char *left,char *right, FILE *fp, int root)
{
	int leftSearch = search(left,fp,root);
	int rightSearch = search(right,fp,root); 
	if(leftSearch != -1 && rightSearch != -1)
		for(int i=leftSearch;i<rightSearch;i++)
			printData(i,fp);
}

void main()
{
	insertData("bPlusTree.bin");

	//printBTree();
	FILE *fp = fopen("bPlusTree.bin","wb");
	//fseek(fp,-24,SEEK_END);
	//printf("%d=>",12);
	//printf("%s",search("efg",fp,ftell(fp)));
	searchBetween("abc","raja",fp,ftell(fp));
	getche();
}
