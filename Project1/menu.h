#include<graphics.h>
#include<cstdio>
#include"general.h"
#include <conio.h>

void init_menu()
{
	initgraph(WIDTH, HEIGHT, SHOWCONSOLE);  //�����С,����SHOWCONSOLE���Ϳ�����printf��
	setbkcolor(BACKGROUNDCOLOR);         //����ɫ
	cleardevice();             //����
	setcolor(LINECOLOR);             //����ɫ
	setlinestyle(PS_SOLID, 2);
	rectangle(1, 1, WIDTH - 2, HEIGHT - 2);  //�������#pragma once
}
