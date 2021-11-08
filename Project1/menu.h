#include<graphics.h>
#include<cstdio>
#include"general.h"
#include"resource.h"

void init_menu()
{
	initgraph(WIDTH, HEIGHT);  //界面大小,加上SHOWCONSOLE，就可以用printf了
	setbkcolor(BACKGROUNDCOLOR);         //背景色
	cleardevice();             //清屏
	setcolor(LINECOLOR);             //线颜色
	setlinestyle(PS_SOLID, 2);
	rectangle(WIDTH - MENU_WIDTH + 2, 1, WIDTH - 2, HEIGHT - 2);  //最外侧线#pragma once
}

void pause()
{
	//cleardevice();
	rectangle(WIDTH / 3, HEIGHT / 3, WIDTH / 3 * 2, HEIGHT / 3 * 2);
	outtextxy(WIDTH/2 - 14,HEIGHT/2 -10, "暂停");
	outtextxy(WIDTH / 2 - 60, HEIGHT / 2 + 10, "按任意按钮继续");
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
