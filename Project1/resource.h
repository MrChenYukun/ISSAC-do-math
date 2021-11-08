#pragma once
#include<graphics.h>
#include<cstdio>
#include"general.h"
#include<conio.h>
#include"menu.h"
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
//reading
IMAGE background;
IMAGE character[2];
IMAGE character_head[3];//0 is normal, 1 right, 2 left
IMAGE move_normal;
IMAGE move_right[10];
IMAGE move_left[10];
//反图
IMAGE character_b[2];
IMAGE character_head_b[3];//0 is normal, 1 right, 2 left
IMAGE move_normal_b;
IMAGE move_right_b[10];
IMAGE move_left_b[10];
IMAGE apple_drop;

typedef struct {
	char name[20];
	int score;
}USER;
void generate_math(math* m)
{
	int t;
	do
	{
		m->factor1 = rand() % VALUE_MAX;
		m->factor2 = rand() % VALUE_MAX;
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
	} while (m->ans < 0 || m->ans >= VALUE_MAX);

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
void init(USER& user)
{
	rectangle(WIDTH - MENU_WIDTH + 2, 1, WIDTH - 2, HEIGHT - 2);
	outtextxy(SHOWNAME_X, SHOWNAME_Y, "昵称 ");
	outtextxy(SHOWNAME_X + SHOWNAME_SPERATE, SHOWNAME_Y, user.name);

	char buf[10];
	sprintf_s(buf, "%d", user.score);   //user.score为整型，outtextxy要求输出的是 char[]
	outtextxy(SHOWSCORE_X, SHOWSCORE_Y, "分数:");
	outtextxy(SHOWSCORE_X + SHOWNAME_SPERATE, SHOWSCORE_Y, buf);

	for (int i = 0; i < 6; i++)
	{
		rectangle(SETTING_X , SETTING_Y  + SEPERATE_SETTING * i, SETTING_X + BOX_X, SETTING_Y + BOX_Y + SEPERATE_SETTING * i);
		outtextxy(SETTING_X+BOX_X/3, SETTING_Y + SEPERATE_SETTING * i+BOX_Y/3, options[i]);
		//system("pause");
	}


}
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
int key_control(ExMessage* k, int state,int* current_location,USER user,math* problem)
{
	if (peekmessage(k))
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
		else if (k->message == WM_LBUTTONUP)
		{
			int i = 0;
			if (k->x >= SETTING_X && k->x <= SETTING_X + BOX_X && k->y >= SETTING_Y + SEPERATE_SETTING * i && k->y <= SETTING_Y + BOX_Y + SEPERATE_SETTING * i)
			{
				pause();
			}
			i++;
			if (k->x >= SETTING_X && k->x <= SETTING_X + BOX_X && k->y >= SETTING_Y + SEPERATE_SETTING * i && k->y <= SETTING_Y + BOX_Y + SEPERATE_SETTING * i)
			{
				add();
			}
			i++;
			if (k->x >= SETTING_X && k->x <= SETTING_X + BOX_X && k->y >= SETTING_Y + SEPERATE_SETTING * i && k->y <= SETTING_Y + BOX_Y + SEPERATE_SETTING * i)
			{
				decrease();
			}
			i++;
			if (k->x >= SETTING_X && k->x <= SETTING_X + BOX_X && k->y >= SETTING_Y + SEPERATE_SETTING * i && k->y <= SETTING_Y + BOX_Y + SEPERATE_SETTING * i)
			{
				//skip(problem,user);
				generate_math(problem);
				cleardevice();
				init(user);
				show_problem(*problem);
			}
			i++;
			if (k->x >= SETTING_X && k->x <= SETTING_X + BOX_X && k->y >= SETTING_Y + SEPERATE_SETTING * i && k->y <= SETTING_Y + BOX_Y + SEPERATE_SETTING * i)
			{
				//check(user);
				rectangle(WIDTH / 3, HEIGHT / 3, WIDTH / 3 * 2, HEIGHT / 3 * 2);
				outtextxy(WIDTH / 2 - 14, HEIGHT / 2 - 20, "暂停");
				char buf[10];
				sprintf_s(buf, "%d", user.score);   //user.score为整型，outtextxy要求输出的是 char[]
				outtextxy(WIDTH / 2 - 14, HEIGHT / 2, buf);
				outtextxy(WIDTH / 2 - 60, HEIGHT / 2 + 20, "按任意按钮继续");
				system("pause");
			}
			i++;
			if (k->x >= SETTING_X && k->x <= SETTING_X + BOX_X && k->y >= SETTING_Y + SEPERATE_SETTING * i && k->y <= SETTING_Y + BOX_Y + SEPERATE_SETTING * i)
			{
				exit(0);
			}
			i++;

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
void draw_issac(int *current_location,int *cnt,int state)
{
	if (state == 0)//stay still
	{
		putimage((*current_location)*scale, HEIGHT - (1 * ISAAC_SIZE + PLAYER_LOC) * scale, &move_normal, SRCINVERT);
		putimage((*current_location)*scale, HEIGHT - (2 * ISAAC_SIZE - PLAYER_FIX + PLAYER_LOC) * scale, &character_head[0], SRCINVERT);
	}
	else if (state == 1)//move right
	{
		putimage((*current_location)*scale, HEIGHT - (1 * ISAAC_SIZE + PLAYER_LOC) * scale, &move_right[*cnt / MOVE_RATE], SRCINVERT);
		putimage((*current_location)*scale, HEIGHT - (2 * ISAAC_SIZE - PLAYER_FIX + PLAYER_LOC) * scale, &character_head[1], SRCINVERT);
		*cnt = (*cnt + 1) % (MOVE_RATE * 10 + 1);
		*current_location += (MOVE_SPEED);
	}
	else if (state == 2)//move left
	{
		putimage((*current_location)*scale, HEIGHT - (1 * ISAAC_SIZE + PLAYER_LOC) * scale, &move_left[*cnt / MOVE_RATE], SRCINVERT);
		putimage((*current_location)*scale, HEIGHT - (2 * ISAAC_SIZE - PLAYER_FIX + PLAYER_LOC) * scale, &character_head[2], SRCINVERT);
		*cnt = (*cnt + 1) % (MOVE_RATE * 10 + 1);
		*current_location -= (MOVE_SPEED);
	}
}