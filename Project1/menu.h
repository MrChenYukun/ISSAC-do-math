#include<graphics.h>
#include<cstdio>
#include"general.h"
#include"resource.h"

void init_menu()
{
	initgraph(WIDTH, HEIGHT);  //�����С,����SHOWCONSOLE���Ϳ�����printf��
	setbkcolor(BACKGROUNDCOLOR);         //����ɫ
	cleardevice();             //����
	setcolor(LINECOLOR);             //����ɫ
	setlinestyle(PS_SOLID, 2);
	rectangle(WIDTH - MENU_WIDTH + 2, 1, WIDTH - 2, HEIGHT - 2);  //�������#pragma once
}

void pause()
{
	//cleardevice();
	rectangle(WIDTH / 3, HEIGHT / 3, WIDTH / 3 * 2, HEIGHT / 3 * 2);
	outtextxy(WIDTH/2 - 14,HEIGHT/2 -10, "��ͣ");
	outtextxy(WIDTH / 2 - 60, HEIGHT / 2 + 10, "�����ⰴť����");
	system("pause");
}
void add()
{
	APPLE_SPAWN_RATE--;
}
void decrease()
{
	APPLE_SPAWN_RATE++;
}
