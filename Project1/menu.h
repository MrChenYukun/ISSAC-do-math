#include<graphics.h>
#include<cstdio>
#include"general.h"
#include <conio.h>

void init_menu()
{
	initgraph(WIDTH, HEIGHT);  //界面大小,加上SHOWCONSOLE，就可以用printf了
	setbkcolor(BACKGROUNDCOLOR);         //背景色
	cleardevice();             //清屏
	setcolor(LINECOLOR);             //线颜色
	setlinestyle(PS_SOLID, 2);
	rectangle(WIDTH - MENU_WIDTH + 2, 1, WIDTH - 2, HEIGHT - 2);  //最外侧线#pragma once
}
