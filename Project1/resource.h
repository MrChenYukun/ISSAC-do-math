#pragma once
#include<graphics.h>
#include<cstdio>
#include"general.h"
#include <conio.h>
struct apple
{
	int x;
	int y;
	int value;
	apple* next;
	apple* last;
};
struct math
{
	int factor1;
	int factor2;
	int ans;
	char ope;
};

void reading_resource(IMAGE* apple_drop,IMAGE *background, IMAGE *character, IMAGE *character_head, IMAGE *move_normal, IMAGE *move_right, IMAGE *move_left, IMAGE *character_b, IMAGE *character_head_b, IMAGE *move_normal_b, IMAGE* move_right_b, IMAGE* move_left_b)
{
//readiing resouce
initgraph(512 * scale, 512 * scale);
//大图
loadimage(background, BACKGROUND_PATH, WIDTH - MENU_WIDTH, HEIGHT, true);
loadimage(&character[0], CHARACTER_PATH, 512 * scale, 512 * scale, true);
loadimage(&character[1], CHARACTER_REVERSE_PATH, 512 * scale, 512 * scale, true);
loadimage(apple_drop, APPLE_DROP_PATH, APPLE_SIZE * scale, APPLE_SIZE * scale, true);
//loadimage(&character_b[0], CHARACTER_PATH_B, 512 * scale, 512 * scale, true);
//loadimage(&character_b[1], CHARACTER_REVERSE_PATH_B, 512 * scale, 512 * scale, true); 

//正常图

putimage(0, 0, &character[0]);
getimage(&character_head[0], 0, 0, ISAAC_SIZE * scale, ISAAC_SIZE * scale);
getimage(&character_head[1], 2 * ISAAC_SIZE * scale, 0, ISAAC_SIZE * scale, ISAAC_SIZE * scale);
getimage(move_normal, 0, ISAAC_SIZE * scale, ISAAC_SIZE * scale, ISAAC_SIZE * scale);
for (int i = 0; i < 8; i++)
	getimage(&move_right[i], i * ISAAC_SIZE * scale, 2 * ISAAC_SIZE * scale, ISAAC_SIZE * scale, ISAAC_SIZE * scale);
for (int i = 0; i < 2; i++)
	getimage(&move_right[i + 8], i * ISAAC_SIZE * scale, 3 * ISAAC_SIZE * scale, ISAAC_SIZE * scale, ISAAC_SIZE * scale);

putimage(0, 0, &character[1]);
getimage(&character_head[2], 13 * ISAAC_SIZE * scale, 0, ISAAC_SIZE * scale, ISAAC_SIZE * scale);
for (int i = 0; i < 8; i++)
	getimage(&move_left[i], (15 - i) * ISAAC_SIZE * scale, 2 * ISAAC_SIZE * scale, ISAAC_SIZE * scale, ISAAC_SIZE * scale);
for (int i = 0; i < 2; i++)
	getimage(&move_left[i + 8], (15 - i) * ISAAC_SIZE * scale, 3 * ISAAC_SIZE * scale, ISAAC_SIZE * scale, ISAAC_SIZE * scale);

//反图
/*
putimage(0, 0, &character_b[0]);
getimage(&character_head_b[0], 0, 0, ISAAC_SIZE * scale, ISAAC_SIZE * scale);
getimage(&character_head_b[1], 2 * ISAAC_SIZE * scale, 0, ISAAC_SIZE * scale, ISAAC_SIZE * scale);
getimage(move_normal_b, 0, ISAAC_SIZE * scale, ISAAC_SIZE * scale, ISAAC_SIZE * scale);
for (int i = 0; i < 8; i++)
	getimage(&move_right_b[i], i * ISAAC_SIZE * scale, 2 * ISAAC_SIZE * scale, ISAAC_SIZE * scale, ISAAC_SIZE * scale);
for (int i = 0; i < 2; i++)
	getimage(&move_right_b[i + 8], i * ISAAC_SIZE * scale, 3 * ISAAC_SIZE * scale, ISAAC_SIZE * scale, ISAAC_SIZE * scale);

putimage(0, 0, &character_b[1]);
getimage(&character_head_b[2], 13 * ISAAC_SIZE * scale, 0, ISAAC_SIZE * scale, ISAAC_SIZE * scale);
for (int i = 0; i < 8; i++)
	getimage(&move_left_b[i], (15 - i) * ISAAC_SIZE * scale, 2 * ISAAC_SIZE * scale, ISAAC_SIZE * scale, ISAAC_SIZE * scale);
for (int i = 0; i < 2; i++)
	getimage(&move_left_b[i + 8], (15 - i) * ISAAC_SIZE * scale, 3 * ISAAC_SIZE * scale, ISAAC_SIZE * scale, ISAAC_SIZE * scale);
*/

closegraph();
}
int key_control(ExMessage* k, int state,int* current_location)
{
	if (peekmessage(k) && k->message)
	{
		if (k->vkcode == 0x41)//A
		{
			state = 2;
		}
		else if (k->vkcode == 0x44)//D
		{
			state = 1;
		}
		else if (k->vkcode == 0x53)//S
		{
			state = 0;
		}
	}
	//else state = 0;

	if (state == 1 && (*current_location + ISAAC_SIZE) * scale >= WIDTH - MENU_WIDTH)
	{
		state = 0;
		*current_location = (WIDTH - MENU_WIDTH) / scale - ISAAC_SIZE;
	}
	if (state == 2 && *current_location <= 0)
	{
		state = 0;
		*current_location = 0;
	}

	return state;
}
void generate_math(math* m)
{
	int t;
	do
	{
		m->factor1 = rand() % 10;
		m->factor2 = rand() % 10;
		t = rand() % 5;
		if (!(m->factor2 == 0 && t == 3) && !(m->factor2 == 0 && t == 4))
		{
			switch (t)
			{
			case 0:m->ope = '+'; m->ans = m->factor1 + m->factor2; break;
			case 1:m->ope = '-'; m->ans = m->factor1 - m->factor2; break;
			case 2:m->ope = '*'; m->ans = m->factor1 * m->factor2; break;
			case 3:m->ope = '/'; m->ans = m->factor1 / m->factor2; break;
			case 4:m->ope = '%'; m->ans = m->factor1 % m->factor2; break;
			}
		}
		else continue;
	} while (m->ans < 0 || m->ans > 9);

}
void show_problem(math problem)
{
	char buf[10];
	outtextxy(SHOWMATH_X, SHOWMATH_Y, "Problem:");
	sprintf_s(buf, "%d", problem.factor1);
	outtextxy(SHOWMATH_X, SHOWMATH_Y + 20, buf);
	sprintf_s(buf, "%c", problem.ope);
	outtextxy(SHOWMATH_X + 20 * 1, SHOWMATH_Y + 20, buf);
	sprintf_s(buf, "%d", problem.factor2);
	outtextxy(SHOWMATH_X + 20 * 2, SHOWMATH_Y + 20, buf);
	outtextxy(SHOWMATH_X + 20 * 3, SHOWMATH_Y + 20, "=");
	outtextxy(SHOWMATH_X + 20 * 4, SHOWMATH_Y + 20, "?");
	//sprintf_s(buf, "%d", problem.ans);
	//outtextxy(SHOWMATH_X + 20 * 4, SHOWMATH_Y + 20, buf);
}