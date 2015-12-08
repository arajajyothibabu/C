#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int base = 1048576;

struct tree
{
	struct tree *left;
	int data;
	struct tree *right;
};

struct user
{
	char name[16];
};

struct group
{
	char name[10];//10 bytes
	char description[50];//50 bytes
	int users;//4 bytes
	int posts;//4 bytes
	int post[10];//40 bytes
	int Ipost[4];//16 bytes
	int IIpost;//4 bytes
};

struct post
{
	char username[16];//16 bytes
	char text[172]; // 172 bytes
	int likes; //4 bytes
	int comments; // 4 bytes
	int comment[10]; // 40 bytes
	int Icomment[4]; // 16 bytes
	int IIcomment; // 4 bytes
};

struct comment
{
	char username[16]; // 16 bytes
	char text[108]; // 108 bytes
	int likes; // 4 bytes
};

struct root
{
	struct Qgroup
	{
		struct Qpost
		{
			struct Qcomment
			{
				struct Qcomment *next;
				int likes;
				int address;
			}QComment[10];
			int likes;
			int comments;
			int address;
		}QPost[10];
		int address;
		int posts;
		int users;
	}QGroup[8];
	int address;
};

struct root *getData(struct root *Root)
{
	int i=0,k=0,j=0,indirectAddress=0;
	FILE *fp = fopen("db.bin","rb+");
	fseek(fp,1024*1024,SEEK_SET);
	printf("%d",ftell(fp));
	for(i=0;i<8;i++)
	{
		struct group Group;
		Root->QGroup[i].address = i*128+1024*1024;
		fseek(fp,Root->QGroup[i].address,SEEK_SET);
		fread(&Group,128,1,fp);
		Root->QGroup[i].posts = Group.posts; //no: of posts in Group
		Root->QGroup[i].users = Group.users; //no: of users in Group
		for(j=0;j<Group.posts;j++)
		{
			struct post Post;
			if(j<10)
			{
				Root->QGroup[i].QPost[j].address = Group.post[j];
				fseek(fp,Root->QGroup[i].QPost[j].address,SEEK_SET);
				fread(&Post,256,1,fp);
				Root->QGroup[i].QPost[j].likes = Post.likes;			//no of likes for Post
				Root->QGroup[i].QPost[j].comments = Post.comments;	//no of comments for Post
			}
			else
			{
				fseek(fp,Group.Ipost[(j-10)/32],SEEK_SET);
				fseek(fp,4*(j-10)%32,SEEK_CUR);
				fread(&indirectAddress,4,1,fp);
				Root->QGroup[i].QPost[j].address = indirectAddress;
				fseek(fp,Root->QGroup[i].QPost[j].address,SEEK_SET);
				fread(&Post,256,1,fp);
				Root->QGroup[i].QPost[j].likes = Post.likes;
				Root->QGroup[i].QPost[j].comments = Post.comments;
			}
			//Retrieving comments
			for(k=0;k<Post.comments;k++)
			{
				struct comment Comment;
				if(k<10)
				{
					Root->QGroup[i].QPost[j].QComment[k].address = Post.comment[k];
					fseek(fp,Root->QGroup[i].QPost[j].QComment[k].address,SEEK_SET);
					fread(&Comment,128,1,fp);
					Root->QGroup[i].QPost[j].QComment[k].likes = Post.likes;
				}
				else
				{
					fseek(fp,Post.Icomment[(k-10)/32],SEEK_SET);
					fseek(fp,4*(k-10)%32,SEEK_CUR);
					fread(&indirectAddress,4,1,fp);
					Root->QGroup[i].QPost[j].QComment[k].address = indirectAddress;
					fseek(fp,Root->QGroup[i].QPost[j].QComment[k].address,SEEK_SET);
					fread(&Comment,128,1,fp);
					Root->QGroup[i].QPost[j].QComment[k].likes = Post.likes;
				}
			}
		}
	}
	fclose(fp);
	return Root;
}

char *trimmed(char *query)
{
	int i=0,k=0;
	while(query[i-1]!='\0')
		if(query[i]==' ' && query[i+1] == ' ') i++;
		else query[k++] = query[i++];
	query[k] = '\0';
	return query;
}

int tokenizer(char *query,char **SymTab)
{
	int i=0,j=0,k=0;
	for(i=0;query[i]!='\0';i++)
		if(query[i]!=' ' && query[i]!='\0')
			SymTab[j][k++] = query[i];
		else
		{
			SymTab[j][k] = '\0';
			j++;
			k = 0;
		}
	SymTab[j][k] = '\0';
	return j+1;
}

bool isCorrect(int token_count,char **SymTab)
{
	char KeyWords[15][20] = {"get", "*", "post", "group", "and", "or", "comment", "like", "min", "max", "count", "user", "where", "=", "from"};
	for(int i=0;i<token_count;i++)
		for(int j=0;j<15;j++)
			if(!strcmp(SymTab[i],KeyWords[j]))
				return false;
	return true;
}

void displayUsers(char *input)
{
	
}

void queryParser(char *query)
{
	char **SymTab = (char **)malloc(sizeof(char)*15);
	int i=0,k=0,token_count=0;
	struct root *Root = (struct root *)malloc(sizeof(struct root *));
	for(i=0;i<15;i++)
		SymTab[i] = (char *)malloc(sizeof(char)*20);
	token_count = tokenizer(trimmed(query),SymTab);
	//Normal query parsing
	struct root *Data = (struct root *)malloc(sizeof(struct root *));
	Data = getData(Root);

}

void main()
{
	char *query = (char *)malloc(sizeof(char)*200);
	gets(query);
	queryParser(query);
	getche();
}