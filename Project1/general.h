#pragma once
#define WIDTH 800
#define HEIGHT 480
#define MENU_WIDTH 160
const int scale = (WIDTH - MENU_WIDTH) * (HEIGHT) / (480 * 270);

#define SEPERATE 20
#define SHOWNAME_X (WIDTH - (MENU_WIDTH / 2)-(MENU_WIDTH)/4)
#define SHOWNAME_Y HEIGHT / 3*2 + SEPERATE*1-10 
#define SHOWNAME_SPERATE 50
#define SHOWSCORE_X (WIDTH - (MENU_WIDTH / 2)-(MENU_WIDTH)/4)
#define SHOWSCORE_Y HEIGHT / 3*2 + SEPERATE*2-10
#define SHOWMATH_X (WIDTH - (MENU_WIDTH / 2)-(MENU_WIDTH)/4)
#define SHOWMATH_Y HEIGHT / 3*2 + SEPERATE*3-10

#define SEPERATE_SETTING 50
#define SETTING_X (WIDTH - (MENU_WIDTH / 2)-(MENU_WIDTH)/4)
#define SETTING_Y HEIGHT / 20
#define BOX_X 80
#define BOX_Y 40
const char options[6][20] =
{
	"暂停",
	"增加",
	"减少",
	"跳过",
	"查看",
	"退出"
};

#define BACKGROUNDCOLOR BLACK
#define LINECOLOR WHITE

#define BACKGROUND_PATH "image\\nightmares_bg.png"
#define CHARACTER_PATH "image\\character_001_isaac.png"
#define CHARACTER_REVERSE_PATH "image\\character_001_isaac_reverse.png"
#define CHARACTER_PATH_B "image\\character_001_isaac_b.png" 
#define CHARACTER_REVERSE_PATH_B "image\\character_001_isaac_reverse_b.png" 
#define APPLE_DROP_PATH "image\\apple.png" 
#define BGM_PATH "sounds\\angel.wav"

#define PLAYER_FIX 23//头身偏差修正
#define SPEED 12//刷新速度
#define MOVE_SPEED 2
#define MOVE_RATE 4//移动动画的速度，越大越慢
#define PLAYER_LOC 0//距离地板的高度
#define ISAAC_SIZE 32

#define APPLE_SPEED 1
int APPLE_SPAWN_RATE=5; //苹果生成速率，越高越慢
#define APPLE_MAX 50
#define APPLE_SIZE 32
#define VALUE_MAX 10