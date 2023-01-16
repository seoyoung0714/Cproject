#include "tofu.h"

int main(void)
{
	int curLevel;
	char map[MAP3][MAP3];
	game_start();
	//game_story();
	while(1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR4);
		switch (game_menu())
		{
		case 1:
		{
			curLevel = game_level();
			system("cls");
			do {
				curLevel = start_game(map, curLevel);
			} while (curLevel != 0);
			break;
		}
		case 2:
		{
			system("cls");
			printf("게임 가이드");
			game_guide();
			break;
		}
		case 3:
		{
			system("cls");
			game_story();
			game_menu();
			break;
		}
		case 4:
		{
			system("cls");
			printf("\n 게임을 종료합니다.\n");
			return 0;
		}
		} 
	} while (1);
	return 0;
}