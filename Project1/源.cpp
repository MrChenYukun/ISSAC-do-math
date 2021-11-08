#include"username.h"
#include"general.h"
#include"menu.h"
#include"resource.h"
#include<time.h>

int main()
{
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
	
	reading_resource(&apple_drop,&background,character,character_head,&move_normal,move_right,move_left,character_b, character_head_b, &move_normal_b, move_right_b, move_left_b);

	//init
	init_menu();
	srand((unsigned int)time(NULL));
	USER user;
	user.score = 0;//积分清零
	InputBox(user.name, 20, "Enter you name：");
	init(user);   //请输入名字
	printf("%s", user.name);

	apple first,end;
	first.next = &end;
	first.last = NULL;
	end.next = NULL;
	end.last = &first;
	int timer=0;
	int apple_num = 0;

	//start
	int state = 1,cnt = 0;//isaac's current state
	int current_location=0;
	char buf[10];

	ExMessage k;
	apple *cur;
	math problem;

	generate_math(&problem);
	show_problem(problem);

	while (true)
	{	
		//creat_apple
		timer=(timer+1)%APPLE_SPAWN_RATE;
		if (apple_num<APPLE_MAX&&!(timer) % APPLE_SPAWN_RATE) 
		{
			apple *obj = new apple;
			obj->next = &end;
			obj->last = end.last;
			(end.last)->next = obj;
			end.last = obj;
			obj->x = rand() % ((WIDTH - MENU_WIDTH) / scale - ISAAC_SIZE);
			obj->y = 0;
			obj->value = rand()%VALUE_MAX;
			apple_num++;
		}
		//clickcontrol
		state = key_control(&k,state,&current_location);

		BeginBatchDraw();
		//drawbasic
		putimage(0, 0, &background);
		//printf("%s", user.name);
		sprintf_s(buf, "%d", user.score);
		outtextxy(SHOWSCORE_X + SHOWNAME_SPERATE, SHOWSCORE_Y, buf);
		

		//draw_issac
		if (state == 0)//stay still
		{
			putimage((current_location)*scale, HEIGHT - (1 * ISAAC_SIZE+PLAYER_LOC) * scale, &move_normal, SRCINVERT);
			putimage((current_location)*scale, HEIGHT - ( 2 * ISAAC_SIZE - PLAYER_FIX+ PLAYER_LOC) * scale, &character_head[0], SRCINVERT);
		}
		else if (state == 1)//move right
		{
			putimage((current_location) * scale, HEIGHT - (1 * ISAAC_SIZE + PLAYER_LOC) * scale, &move_right[cnt/ MOVE_RATE], SRCINVERT);
			putimage((current_location)*scale, HEIGHT - (2 * ISAAC_SIZE - PLAYER_FIX + PLAYER_LOC) * scale, &character_head[1], SRCINVERT);
			cnt = (cnt + 1) % (MOVE_RATE * 10 + 1);
			current_location += (MOVE_SPEED);
		}
		else if (state == 2)//move left
		{
			putimage((current_location) * scale, HEIGHT - (1 * ISAAC_SIZE + PLAYER_LOC) * scale, &move_left[cnt/ MOVE_RATE], SRCINVERT);
			putimage((current_location)*scale, HEIGHT - (2 * ISAAC_SIZE - PLAYER_FIX + PLAYER_LOC) * scale, &character_head[2], SRCINVERT);
			cnt = (cnt + 1) % (MOVE_RATE * 10 + 1);
			current_location -= (MOVE_SPEED);
		}


		//draw apple
		cur = first.next;
		while (cur->next != NULL)
		{
			//print picture
			putimage((cur->x) * scale, (cur->y) * scale, &apple_drop, SRCINVERT);
			//print value
			sprintf_s(buf, "%d", cur->value);
			outtextxy((cur->x+APPLE_SIZE/2) * scale, (cur->y + APPLE_SIZE / 2) * scale, buf);

			cur->y += APPLE_SPEED;
			cur = cur->next;

			//touch the bottom?
			if (first.next->y>= ((HEIGHT) / scale - APPLE_SIZE))
			{
				apple_num--;
				first.next->next->last = &first;
				first.next = first.next->next;
			}
			//issac eat the apple?
			if (first.next->y >= ((HEIGHT) / scale - 2*ISAAC_SIZE + PLAYER_FIX-PLAYER_LOC-APPLE_SIZE) && first.next->x <= current_location + ISAAC_SIZE - APPLE_SIZE/2 && first.next->x >= current_location - APPLE_SIZE/2)
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

		EndBatchDraw();
		Sleep(SPEED);
	}

	closegraph();
	return 0;
}