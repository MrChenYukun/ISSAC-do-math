#pragma once



#include<graphics.h>
#include <stdio.h>
#include "general.h"

typedef struct {
	char name[20];
	int score;
}USER;

void init(USER& user)
{
	rectangle(WIDTH - MENU_WIDTH + 2, 1, WIDTH - 2, HEIGHT - 2);
	outtextxy(SHOWNAME_X, SHOWNAME_Y, "Name ");
	outtextxy(SHOWNAME_X+SHOWNAME_SPERATE, SHOWNAME_Y, user.name);

	char buf[10];
	sprintf_s(buf, "%d", user.score);   //user.scoreΪ���ͣ�outtextxyҪ��������� char[]
	outtextxy(SHOWSCORE_X, SHOWSCORE_Y, "Score:");
	outtextxy(SHOWSCORE_X + SHOWNAME_SPERATE, SHOWSCORE_Y, buf);
}

//һ��ʹ�õ�����
/*
int main()
{
	USER user;

	
	init(user);   //��ʼ��

	printf("%s", user.name);    //������
	getchar();


	closegraph();
	return 0;
}
*/