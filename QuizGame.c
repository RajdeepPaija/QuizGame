/*
 * QuizGame.c
 *
 *  Created on: 29-Mar-2022
 *      Author: rajde
 */



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
char file_name[][5]={"a","b","c","d","e","f","g","h"};
static int id=0;
void start(void);
void history(void);
void finish(void);
int main()
{
	int ops;
	while(1)
	{
		sleep(2);
		system("clear");
		printf("\n.........App Name: Trivia App................\n");
		printf("\nchoose the opstion\n1)start quiz\n2)HISTORY\n3)FINISH\n4)EXIT\n");
		scanf("%d",&ops);
		switch(ops)
		{
			case 1:start();break;
			case 2:history();break;
			case 3:finish();break;
			case 4:exit(1);
			default:printf("choose correct option....!\n");
		}

	}

}
void start(void)
{
char name[30],ans[30],next;
int n=0;
char ans1[3][20];

int i=0;
printf("enter the name\n");
scanf(" %[^\n]",name);

//que------1-------------------
	printf("who is the best cricketer in the world\n");
	printf("opstions:\nA)Sachin Tendulakar\nB)Virat kohli\nc)Adam gilchrist\nD)Jacques kalish\n");
	printf("select only one.\n");
	scanf(" %[^\n]",ans);
	FILE *fp2=fopen(file_name[id],"w");
	fputs("\n....GAME: 1",fp2);
	fputs(__DATE__   __TIME__,fp2);
	fputs("\nName:",fp2);
	fputs(name,fp2);
	fputs("\nwho is the best cricketer in the world?\n",fp2);
	fputs("answer:",fp2);
	fputs(ans,fp2);
	//que-2-------------------------------
	printf("NEXT BUTTON(enter 'n' || 'N'):");
	scanf(" %c",&next);
	system("clear");
	if(next == 'n' || next == 'N')
	{
	n=1;
	char ch1='y';
	printf("\nwhat are the colour in the national flag?Select all:\n");
	printf("opstion:\n");
	printf("A)White\nB)Yellow\nC)Orange\nD)Green\n");
	fputs("\nwhat are the colours in the national flag?",fp2);
	fputs("\nanswer: ",fp2);
	printf("enter  opstion more than 1\n");
	fflush(stdin);
	fflush(stdout);
	for(i=0;(ch1 == 'y' || ch1 == 'Y') ;i++)
	{
		printf("enter your ans:");
		scanf("%s",ans1[i]);
		fputs(ans1[i],fp2);
		fputc(',',fp2);
		if(i == 2)
			break;
		printf("'y' or 'Y' for enter another opstion\n");
		scanf(" %c",&ch1);
	}
	//r(int c=0;c<i;c++){
	++id;
	fclose(fp2);
	}
	fflush(stdin);
	fflush(stdout);
	char next1;
	printf("NEXT BUTTON(enter 'n' || 'N'):");
	scanf(" %c",&next1);
	if(next1 == 'n' || next1 == 'N')
	{
		printf("\nHello name:%s\n",name);
		printf("Here are the answer selected:\n");
		printf("who is the best cricketer in the world\n");
		printf("Answer: %s\n",ans);
		if(n == 1)
		{

			printf("\nwhat are the colour in the national flag?\n");
			printf("Answer:");
			for(int c=0; c<i ; c++)
				printf("%s,",ans1[c]);

			printf("\n");
			sleep(3);
		}
	}
}
void history(void)
{
int i=0;
char ch3,s[50];

	fflush(stdin);
	fflush(stdout);
printf("history of the game is.............!\n");
	for(i=0;i<id;i++)
	{
	FILE *fp=fopen(file_name[i],"r");

	while(fgets(s,50,fp))
	puts(s);

	}
}
void finish(void)
{
	printf("your whole previous record going to be deleted success\n");
	for(int i=0;i<id;i++)
	{
	remove(file_name[i]);
	}
	id=0;
}

