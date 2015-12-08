#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct metaData
{
	int nodes[3];
	int values[2];
	char type[4];
};

int offSet(FILE *fp)
{
	fseek(fp,0,SEEK_SET);
	char ch;
	int i=0;
	while(1)
	{
		ch = fgetc(fp);
		if(ch == '\0' && i%24 == 0)
			break;
		i++;
	}
	return i/24;
}

/*struct Node *makeTree(struct Node *root)
{
	root->left = NULL;
	root->middle = NULL;
	root->right = NULL;
	root->v1 = 0;
	root->v2 = 0;
	return root;
}
*/
struct Data
{
	int value;
	char data[20];
};

/*struct Node *insertNode(struct Node *root, struct Data *data)
{
	if(root->v1 == 0)
	{
		root->v1 = data->value;
	}
	else if(data->value < root->v1)
	{
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
		root->left = insertNode(root->left,data);
	}
	else if(root->v2 == 0)
	{
		root->v2 = data->value;
	}
	else if(data->value > root->v2)
	{
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
		root->right = insertNode(root->right,data);
	}
	else if(data->value > root->v1 && data->value < root->v2)
	{
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
		root->middle = insertNode(root->middle,data);
	}
	return root;
}*/

void writeData(struct Data *dAta, FILE *fp,int i)
{
	fseek(fp,i * 24,SEEK_SET);
	fwrite(dAta,24,1,fp);
	fflush(fp);
	return;
}

void addMetaPage(FILE *fp)
{
	struct Data data;
	/*for(int i=0;i<9;i++)
	{
		struct metaData meta;
		fseek(fp,12*24,SEEK_SET);
		fseek(fp,i*24,SEEK_SET);
		fread(&data,24,1,fp);
		meta.nodes[i%3] = i*24;
		if (i%2 != 0 && i != 0) meta.values[(i%3)/2] = data.value;
		meta.type[i%3] = '0';
		fseek(fp,0,SEEK_END);
		if((i+1)%3 == 0)fwrite(&meta,24,1,fp);
		fflush(fp);
	}*/
		struct metaData meta;
		fseek(fp,9*24,SEEK_SET);
		for(int i=0;i<3;i++)
		{
			meta.nodes[i%3] = ftell(fp)+ i*24;
			if (i%2 != 0 && i != 0) meta.values[(i%3)/2] = i=1?3:7;
			meta.type[i%3] = '0';
		}
		fseek(fp,0,SEEK_END);
		fwrite(&meta,24,1,fp);
}

void printMetaData(struct metaData meta)
{
	printf("\t| %d | %d | %d | %d | %d |\n",meta.nodes[0],meta.values[0],meta.nodes[1],meta.values[1],meta.nodes[2]);
}

void printBTree(FILE *fp, int root)
{
	fseek(fp,root,SEEK_SET);
	int x = ftell(fp);
	struct metaData meta;
	fread(&meta,24,1,fp);
	printMetaData(meta);
	//for(int i=0;i<3;i++)
	//if(meta.nodes[0] != '\0')
		//printBTree(fp,meta.nodes[0]);
}

void main()
{
	FILE *fp = fopen("btree.bin","rb+");
	int i=-1;
	//FILE *root = fopen("root.bin","wb+");
	//B_Trees(fp);
	/*struct Node *root = (struct Node *)malloc(sizeof(struct Node *));
	root = makeTree(root);
	while(1)
	{
	struct Data *dAta = (struct Data *)malloc(sizeof(struct Data *));
	printf("Enter Id\t:");
	scanf("%d",&dAta->value);fflush(stdin);
	if(dAta->value < 0)
		exit(0);
	printf("Enter Data\t:");
	gets(dAta->data);
	insertNode(root,dAta);
	}*/
	/*while(1)
	{
		struct Data *dAta = (struct Data *)malloc(sizeof(struct Data *));
		printf("Enter Id\t:");
		scanf("%d",&dAta->value);fflush(stdin);
		if(dAta->value < 0)
			exit(0);
		printf("Enter Data\t:");
		gets(dAta->data);
		writeData(dAta,fp,++i);
	}*/
	//addMetaPage(fp);
	printBTree(fp,14*24);
	fclose(fp);
	getche();
}