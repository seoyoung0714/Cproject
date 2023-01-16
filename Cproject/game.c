#include "tofu.h"

int start_game(char map[][MAP3], int level)
{
	system("cls");
	int nPeople, nTofu, nCall, nWall, nColor, nFood, nDisplay, nBgm;
	int i, j, randX, randY, printX = 2, printY = 1, ch, mtime = 0, protein = 1000, game_result = 0, mini_result;
	int startT, curT;
	int tofuX, tofuY;
	switch (level)
	{
	case 1:
		nPeople = P1;
		nTofu = DUBU1;
		nCall = CALL1;
		nWall = MAP1;
		nColor = COLOR1;
		nFood = FOOD1;
		nDisplay = DISPLAY1;
		nBgm = BGM1;
		break;
	case 2:
		nPeople = P2;
		nTofu = DUBU2;
		nCall = CALL2;
		nWall = MAP2;
		nColor = COLOR2;
		nFood = FOOD2;
		nDisplay = DISPLAY2;
		nBgm = BGM2;
		break;
	case 3:
		nPeople = P3;
		nTofu = DUBU3;
		nCall = CALL3;
		nWall = MAP3;
		nColor = COLOR3;
		nFood = FOOD3;
		nDisplay = DISPLAY3;
		nBgm = BGM3;
		break;
	}

	int x = 2, y = nWall-2;

	srand((unsigned int)time(NULL));

	//레벨에 따른, 벽 설정
	for (i = 0; i < nWall; i++)
	{
		for (j = 0; j < nWall; j++)
		{
			if (i == 0 || i == nWall - 1 || j == 0 || j == nWall - 1)
				map[i][j] = 'W';
			else
				map[i][j] = 0;
		}
	}

	//전화기 장애물 배치
	for (i = 0; i < nCall; i++)
	{
		randX = rand() % nWall;
		randY = rand() % nWall;
		if (map[randX][randY] == 0)
			map[randX][randY] = 'C';
		else i--;
	}

	//시식코너 장애물 배치
	for (i = 0; i < nFood; i++)
	{
		randX = rand() % nWall;
		randY = rand() % nWall;
		if (map[randX][randY] == 0)
			map[randX][randY] = 'F';
		else i--;
	}

	//진열대 장애물 배치
	for (i = 0; i < nDisplay; i++)
	{
		randX = rand() % nWall;
		randY = rand() % nWall;
		if (map[randX][randY] == 0)
			map[randX][randY] = 'D';
		else i--;
	}

	//가짜 두부 배치
	for (i = 0; i < nTofu - 1; i++)
	{
		randX = rand() % nWall;
		randY = rand() % nWall;
		if (map[randX][randY] == 0)
			map[randX][randY] = 'T';
		else i--;
	}

	//진짜 두부(보물) 배치
	while (1)
	{
		randX = rand() % nWall;
		randY = rand() % nWall;
		if (map[randX][randY] == 0)
		{	
			map[randX][randY] = 'R';
			tofuX = randX;
			tofuY = randY;
			break;
		}
	}	

	//사람 장애물 배치
	for (i = 0; i < nPeople; i++)
	{
		randX = rand() % nWall;
		randY = rand() % nWall;
		if (map[randX][randY] == 0)
			map[randX][randY] = 'P';
		else i--;
	}

	mtime = 20; // 난이도에 상관 없이, 제한 시간을 20초로 설정한다
	printMap(map, nWall, nColor, nBgm);
	startT = time(NULL);
	do
	{
		gotoXY(printX + x, printY + y);
		printf("◈\b\b");
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 27)
				return 0;
			if (ch == 224) {
				ch = _getch();
				switch (ch) {
				case UP:
					if (map[y - 1][x / 2] != 'W' && map[y - 1][x / 2] != 'D')
					{
						printf("  ");
						y -= 1;
						if (map[y][x / 2] == 'C')
							findCall(&mtime, printX + (nWall * 2) + 1, printY, tofuX, tofuY, y, x / 2);
						else if (map[y][x / 2] == 'T') {
							gotoXY(printX + (nWall * 2) + 1, printY + 2);
							printf("잘못된 두부를 집었다! 다시 찾아보자!            ");
						}
						else if (map[y][x / 2] == 'R')
							game_result = 1;
						else if (map[y][x / 2] == 'F')
							findFood(&protein, printX + (nWall * 2) + 1, printY + 2);
						else if (map[y][x / 2] == 'P')
						{
							mini_result = mini_Game(level, &mtime);
							system("cls");
							printMap(map, nWall, nColor, nBgm);
							if (mini_result == 1)
							{
								gotoXY(printX + (tofuY * 2), tofuX + printY);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR4);
								printf("▶");
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nColor);
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("게임에 성공하여, 두부의 위치를 발견하였다!            ");
							}
							else if (mini_result == 0)
							{
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("게임에 실패하여, 힌트를 획득하지 못하였다!            ");
							}
							else
							{
								gotoXY(printX + x, printY + y);
								printf("  \b\b");
								map[y][x / 2] = 0;
								x = 2, y = nWall - 2;
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("돈을 소매치기 당했다!! 집으로 돌아가자            ");
							}
						}
						switch (level)
						{
						case 1:
							protein -= 10;
							break;
						case 2:
							protein -= 20;
							break;
						case 3:
							protein -= 25;
							break;
						}
						map[y][x / 2] = 0;
					}
					break;

				case DOWN:
					if (map[y + 1][x / 2] != 'W' && map[y + 1][x / 2] != 'D')
					{
						printf("  ");
						y += 1;
						if (map[y][x / 2] == 'C')
							findCall(&mtime, printX + (nWall * 2) + 1, printY, tofuX, tofuY, y, x / 2);
						else if (map[y][x / 2] == 'T') {
							gotoXY(printX + (nWall * 2) + 1, printY + 2);
							printf("잘못된 두부를 집었다! 다시 찾아보자!            ");
						}
						else if (map[y][x / 2] == 'R')
							game_result = 1;
						else if (map[y][x / 2] == 'F')
							findFood(&protein, printX + (nWall * 2) + 1, printY + 2);
						else if (map[y][x / 2] == 'P')
						{
							mini_result = mini_Game(level, &mtime);
							system("cls");
							printMap(map, nWall, nColor, nBgm);
							if (mini_result == 1)
							{
								gotoXY(printX + (tofuY * 2), tofuX + printY);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR4);
								printf("▶");
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nColor);
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("게임에 성공하여, 두부의 위치를 발견하였다!            ");
							}
							else if (mini_result == 0)
							{
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("게임에 실패하여, 힌트를 획득하지 못하였다!            ");
							}
							else
							{
								gotoXY(printX + x, printY + y);
								printf("  \b\b");
								map[y][x / 2] = 0;
								x = 2, y = nWall - 2;
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("돈을 소매치기 당했다!! 집으로 돌아가자            ");
							}
						}
						switch (level)
						{
						case 1:
							protein -= 10;
							break;
						case 2:
							protein -= 20;
							break;
						case 3:
							protein -= 25;
							break;
						}
						map[y][x / 2] = 0;
					}
					break;

				case LEFT:
					if (map[y][(x / 2)-1] != 'W' && map[y][(x / 2)-1] != 'D')
					{
						printf("  ");
						x -= 2;
						if (map[y][x / 2] == 'C')
							findCall(&mtime, printX + (nWall * 2) + 1, printY, tofuX, tofuY, y, x / 2);
						else if (map[y][x / 2] == 'T') {
							gotoXY(printX + (nWall * 2) + 1, printY + 2);
							printf("잘못된 두부를 집었다! 다시 찾아보자!            ");
						}
						else if (map[y][x / 2] == 'R')
							game_result = 1;
						else if (map[y][x / 2] == 'F')
							findFood(&protein, printX + (nWall * 2) + 1, printY + 2);
						else if (map[y][x / 2] == 'P')
						{
							mini_result = mini_Game(level, &mtime);
							system("cls");
							printMap(map, nWall, nColor, nBgm);
							if (mini_result == 1)
							{
								gotoXY(printX + (tofuY * 2), tofuX + printY);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR4);
								printf("▶");
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nColor);
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("게임에 성공하여, 두부의 위치를 발견하였다!            ");
							}
							else if (mini_result == 0)
							{
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("게임에 실패하여, 힌트를 획득하지 못하였다!            ");
							}
							else
							{
								gotoXY(printX + x, printY + y);
								printf("  \b\b");
								map[y][x / 2] = 0;
								x = 2, y = nWall - 2;
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("돈을 소매치기 당했다!! 집으로 돌아가자            ");
							}
						}
						switch (level)
						{
						case 1:
							protein -= 10;
							break;
						case 2:
							protein -= 20;
							break;
						case 3:
							protein -= 25;
							break;
						}
						map[y][x / 2] = 0;
					}
					break;

				case RIGHT:
					if (map[y][(x / 2)+1] != 'W' && map[y][(x / 2)+1] != 'D')
					{
						printf("  ");
						x += 2;;
						if (map[y][x / 2] == 'C')
							findCall(&mtime, printX + (nWall * 2) + 1, printY, tofuX, tofuY, y, x / 2);
						else if (map[y][x / 2] == 'T') {
							gotoXY(printX + (nWall * 2) + 1, printY + 2);
							printf("잘못된 두부를 집었다! 다시 찾아보자!            ");
						}
						else if (map[y][x / 2] == 'R')
							game_result = 1;
						else if (map[y][x / 2] == 'F')
							findFood(&protein, printX + (nWall * 2) + 1, printY + 2);
						else if (map[y][x / 2] == 'P')
						{
							mini_result = mini_Game(level, &mtime);
							system("cls");
							printMap(map, nWall, nColor, nBgm);
							if (mini_result == 1)
							{
								gotoXY(printX + (tofuY * 2), tofuX + printY);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR4);
								printf("▶");
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nColor);
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("게임에 성공하여, 두부의 위치를 발견하였다!            ");
							}
							else if (mini_result == 0)
							{
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("게임에 실패하여, 힌트를 획득하지 못하였다!            ");
							}
							else
							{
								gotoXY(printX + x, printY + y);
								printf("  \b\b");
								map[y][x / 2] = 0;
								x = 2, y = nWall - 2;
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("돈을 소매치기 당했다!! 집으로 돌아가자              ");
							}
						}
						switch (level)
						{
						case 1:
							protein -= 10;
							break;
						case 2:
							protein -= 20;
							break;
						case 3:
							protein -= 25;
							break;
						}
						map[y][x / 2] = 0;
					}
					break;
				}
			}
		}
		curT = time(NULL);
		gotoXY(printX + (nWall*2), printY);
		printf(" 남은 시간: %d초 / 단백질(체력) : %d    \b\b\b\b", (mtime) - (curT - startT), protein);
	} while ((mtime - (curT-startT) > 0) && game_result == 0 && protein > 0);

	if (game_result == 1)
	{
		if (level == 1 || level == 2)
		{
			victorybgm();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR4);
			system("cls");
			printf("\n\n  %d 단계 성공!", level);
			printf("\n\n  3초 뒤 %d 단계로 이동합니다!", level + 1);
			Sleep(3000);
			return level + 1;
		}
		else
		{
			closing();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR4);
			system("cls");
			printf("\n\n  담백이는 심부름에 성공하여, 진정한 효자 헬창이 될 수 있었습니다.");
			printf("\n\n  어머니의 두부 요리로 단백질을 보충하고,");
			printf("\n\n  방으로 돌아가 기쁜 마음으로 마저 운동을 시작했습니다!");
			printf("\n\n\n\n  Thank you for playing...");
			Sleep(19500);
			return 0;
		}
	}
	else
	{
		losebgm();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR4);
		system("cls");
		printf("\n\n  담백이는 두부 심부름에 실패했습니다");
		printf("\n\n  어머니께 혼나는 와중에 담백이의 휴대폰 문자 알람이 울렸습니다.");
		printf("\n\n  ------------------------------------------------------------");
		printf("\n\n  [Web 발신]");
		printf("\n\n  휘트니스 회원님들께 알립니다! 공사가 지연되는 연유로 인해, \n\n  이번 휴무는 주말까지 연장됩니다.");
		printf("\n\n  쾌적해진 모습으로 다음주부터 뵙겠습니다. 감사합니다.");
		printf("\n\n  ------------------------------------------------------------");
		printf("\n\n  스트레스를 받은 담백이는, 그 날 폭식을 했습니다.");
		Sleep(7000);
		return 0;
	}
}

void printMap(char map[][MAP3], int wall, int color, int bgm)
{
	switch (bgm)
	{
	case 1:
		hanaro();
		break;
	case 2:
		emart();
		break;
	case 3:
		homeplus();
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	system("cls");
	printf("\n  ");
	int i, j;
	for (i = 0; i < wall; i++)
	{
		for (j = 0; j < wall; j++)
		{
			if (map[i][j] == 'W')
				printf("▣");
			else if (map[i][j] == 'P')
				printf("◐");
			else if (map[i][j] == 'C')
				printf("☎");
			else if (map[i][j] == 'T' || map[i][j] == 'R')
				printf("▶");
			else if (map[i][j] == 'F')
				printf("⊙");
			else if (map[i][j] == 'D')
				printf("▤");
			else
				printf("  ");
		}
		printf("\n  ");
	}
}