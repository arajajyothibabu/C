//Search the range of elements between given two elements in B+ Tree
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct metaPage
{
	int node[3];
	int value[2];
	char type[4];
};

struct dataPage
{
	int key;
	char data[12];
	int prev,next;
};

void insertData(char *file)
{
	FILE *fp = fopen(file,"wb");
	int i=0;
	while(i<9)
	{
		struct dataPage dAta;
//		printf("Enter Id\t:");
		dAta.key = i+1;fflush(stdin);
		printf("Enter Data\t:");
		gets(dAta.data);
		if(i!=0)
			dAta.prev = i-1;
		else dAta.prev = '\0';
		dAta.next = i+1;
		fwrite(&dAta,24,1,fp);
		i++;
	}
	//writing metaPages
		for(int j=0;j<9;j =j+3)
		{
			struct metaPage meta;
			for(int i=0;i<3;i++)
			{
				meta.node[i] = i+j;
				if (i!=2) meta.value[i] = i==0?j+1:j+2;
				meta.type[i] = '0';
			}
			fseek(fp,0,SEEK_END);
			fwrite(&meta,24,1,fp);
		}
	//writing metaPages for metaPages
		struct metaPage meta;
		for(i=0;i<3;i++)
		{
			meta.node[i] = 9+i;
			if(i != 2) meta.value[i] = i==0?3:6;
			meta.type[i] = '1';
		}
		fseek(fp,0,SEEK_END);
		fwrite(&meta,24,1,fp);
}

void printMetaPage(struct metaPage meta)
{
	printf("\t| %d | %d | %d | %d | %d |\n",meta.node[0],meta.value[0],meta.node[1],meta.value[1],meta.node[2]);
}

void printBTree()
{
	FILE *fp = fopen("btree.bin","rb+");
	fseek(fp,-24,SEEK_END);
	struct metaPage meta;
	fread(&meta,24,1,fp);
	printMetaPage(meta);
}

int search(int key, FILE *fp, int root)
{
	int flag = -1;
	struct dataPage Data;
	fseek(fp,root,SEEK_SET);
	struct metaPage meta;
	fread(&meta,24,1,fp);
	if(key <= meta.value[0])
	{
		if(meta.type[0] == '1')
		{
			printf("%d=>",meta.node[0]);
			return search(key,fp,meta.node[0]*24);
		}
		else flag = 0;
	}
	else if(key > meta.value[1])
	{
		if(meta.type[2] == '1')
		{
			printf("%d=>",meta.node[2]);
			return search(key,fp,meta.node[2]*24);
		}
		else flag = 2;
	}
	else
	{
		if(meta.type[1] == '1')
		{
			printf("%d=>",meta.node[1]);
			return search(key,fp,meta.node[1]*24);
		}
		else flag = 1;
	}
	if(flag != -1)
	{
		printf("%d\n",meta.node[flag]);
		fseek(fp,meta.node[flag]*24,SEEK_SET);
		fread(&Data,24,1,fp);
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
	fseek(fp,offSet*24,SEEK_SET);
	fread(&Data,24,1,fp);
	printf("%s\n",Data.data);
}

void searchBetween(int left,int right, FILE *fp, int root)
{
	int leftSearch = search(left,fp,root);
	int rightSearch = search(right,fp,root); 
	if(leftSearch != -1 && rightSearch != -1)
		for(int i=leftSearch;i<rightSearch;i++)
			printData(i,fp);
}

void main()
{
	//insertData("btree.bin");
	//printBTree();
	FILE *fp = fopen("btree.bin","rb+");
	fseek(fp,-24,SEEK_END);
	printf("%d=>",12);
	//printf("%s",search(7,fp,ftell(fp)));
	searchBetween(1,5,fp,ftell(fp));
	getche();
}