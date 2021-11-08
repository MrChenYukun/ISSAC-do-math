#include"general.h"
#include"resource.h"
#include<time.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>//导入声音头文件
#pragma comment(lib,"Winmm.lib")


int main()
{
	reading_resource(&apple_drop,&background,character,character_head,&move_normal,move_right,move_left,character_b, character_head_b, &move_normal_b, move_right_b, move_left_b);

	//init

	init_menu();
	srand((unsigned int)time(NULL));
	USER user;
	user.score = 0;//积分清零
	InputBox(user.name, 20, "Enter you name：");
	init(user);   //请输入名字
	printf("%s", user.name);

	apple first, end;
	first.next = &end;
	first.last = NULL;
	end.next = NULL;
	end.last = &first;
	int timer = 0;
	int apple_num = 0;

		//start
	int state = 0, cnt = 0;//isaac's current state
	int current_location = 0;
	char buf[10];

	ExMessage k;
	apple* cur;
	math problem;

	generate_math(&problem);
	show_problem(problem);


	PlaySound(BGM_PATH, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	while (true)
	{	
		//creat_apple
		if (true)
		{
			timer = (timer + 1) % APPLE_SPAWN_RATE;
			if (apple_num < APPLE_MAX && ((timer) % APPLE_SPAWN_RATE) == 0)
			{
				apple* obj = new apple;
				obj->next = &end;
				obj->last = end.last;
				(end.last)->next = obj;
				end.last = obj;
				obj->x = rand() % ((WIDTH - MENU_WIDTH) / scale - ISAAC_SIZE);
				obj->y = 0;
				obj->value = rand() % VALUE_MAX;
				apple_num++;
			}
		}
		//clickcontrol
		state = key_control(&k,state,&current_location,user,&problem);

		BeginBatchDraw();
	
		putimage(0, 0, &background);
		draw_issac(&current_location,&cnt,state);

		//draw apple
		if (true)
		{

			cur = first.next;
			while (cur->next != NULL)
			{
				//print picture
				putimage((cur->x) * scale, (cur->y) * scale, &apple_drop, SRCINVERT);
				//print value
				sprintf_s(buf, "%d", cur->value);
				outtextxy((cur->x + APPLE_SIZE / 2) * scale, (cur->y + APPLE_SIZE / 2) * scale, buf);

				cur->y += APPLE_SPEED;
				cur = cur->next;

				//touch the bottom?
				if (first.next->y >= ((HEIGHT) / scale - APPLE_SIZE))
				{
					apple_num--;
					first.next->next->last = &first;
					first.next = first.next->next;
				}
				//issac eat the apple?
				if (first.next->y >= ((HEIGHT) / scale - 2 * ISAAC_SIZE + PLAYER_FIX - PLAYER_LOC - APPLE_SIZE) && first.next->x <= current_location + ISAAC_SIZE - APPLE_SIZE / 2 && first.next->x >= current_location - APPLE_SIZE / 2)
				{
					if (first.next->value == problem.ans)
					{
						user.score += 10;
						generate_math(&problem);
						cleardevice();
						init(user);
						show_problem(problem);
					}

					apple_num--;
					first.next->next->last = &first;
					first.next = first.next->next;
				}
			}
		}

		EndBatchDraw();
		Sleep(SPEED);
	}

	closegraph();
	return 0;
}