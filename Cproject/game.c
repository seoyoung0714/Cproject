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

	//������ ����, �� ����
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

	//��ȭ�� ��ֹ� ��ġ
	for (i = 0; i < nCall; i++)
	{
		randX = rand() % nWall;
		randY = rand() % nWall;
		if (map[randX][randY] == 0)
			map[randX][randY] = 'C';
		else i--;
	}

	//�ý��ڳ� ��ֹ� ��ġ
	for (i = 0; i < nFood; i++)
	{
		randX = rand() % nWall;
		randY = rand() % nWall;
		if (map[randX][randY] == 0)
			map[randX][randY] = 'F';
		else i--;
	}

	//������ ��ֹ� ��ġ
	for (i = 0; i < nDisplay; i++)
	{
		randX = rand() % nWall;
		randY = rand() % nWall;
		if (map[randX][randY] == 0)
			map[randX][randY] = 'D';
		else i--;
	}

	//��¥ �κ� ��ġ
	for (i = 0; i < nTofu - 1; i++)
	{
		randX = rand() % nWall;
		randY = rand() % nWall;
		if (map[randX][randY] == 0)
			map[randX][randY] = 'T';
		else i--;
	}

	//��¥ �κ�(����) ��ġ
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

	//��� ��ֹ� ��ġ
	for (i = 0; i < nPeople; i++)
	{
		randX = rand() % nWall;
		randY = rand() % nWall;
		if (map[randX][randY] == 0)
			map[randX][randY] = 'P';
		else i--;
	}

	mtime = 20; // ���̵��� ��� ����, ���� �ð��� 20�ʷ� �����Ѵ�
	printMap(map, nWall, nColor, nBgm);
	startT = time(NULL);
	do
	{
		gotoXY(printX + x, printY + y);
		printf("��\b\b");
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
							printf("�߸��� �κθ� ������! �ٽ� ã�ƺ���!            ");
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
								printf("��");
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nColor);
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("���ӿ� �����Ͽ�, �κ��� ��ġ�� �߰��Ͽ���!            ");
							}
							else if (mini_result == 0)
							{
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("���ӿ� �����Ͽ�, ��Ʈ�� ȹ������ ���Ͽ���!            ");
							}
							else
							{
								gotoXY(printX + x, printY + y);
								printf("  \b\b");
								map[y][x / 2] = 0;
								x = 2, y = nWall - 2;
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("���� �Ҹ�ġ�� ���ߴ�!! ������ ���ư���            ");
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
							printf("�߸��� �κθ� ������! �ٽ� ã�ƺ���!            ");
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
								printf("��");
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nColor);
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("���ӿ� �����Ͽ�, �κ��� ��ġ�� �߰��Ͽ���!            ");
							}
							else if (mini_result == 0)
							{
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("���ӿ� �����Ͽ�, ��Ʈ�� ȹ������ ���Ͽ���!            ");
							}
							else
							{
								gotoXY(printX + x, printY + y);
								printf("  \b\b");
								map[y][x / 2] = 0;
								x = 2, y = nWall - 2;
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("���� �Ҹ�ġ�� ���ߴ�!! ������ ���ư���            ");
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
							printf("�߸��� �κθ� ������! �ٽ� ã�ƺ���!            ");
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
								printf("��");
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nColor);
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("���ӿ� �����Ͽ�, �κ��� ��ġ�� �߰��Ͽ���!            ");
							}
							else if (mini_result == 0)
							{
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("���ӿ� �����Ͽ�, ��Ʈ�� ȹ������ ���Ͽ���!            ");
							}
							else
							{
								gotoXY(printX + x, printY + y);
								printf("  \b\b");
								map[y][x / 2] = 0;
								x = 2, y = nWall - 2;
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("���� �Ҹ�ġ�� ���ߴ�!! ������ ���ư���            ");
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
							printf("�߸��� �κθ� ������! �ٽ� ã�ƺ���!            ");
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
								printf("��");
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nColor);
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("���ӿ� �����Ͽ�, �κ��� ��ġ�� �߰��Ͽ���!            ");
							}
							else if (mini_result == 0)
							{
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("���ӿ� �����Ͽ�, ��Ʈ�� ȹ������ ���Ͽ���!            ");
							}
							else
							{
								gotoXY(printX + x, printY + y);
								printf("  \b\b");
								map[y][x / 2] = 0;
								x = 2, y = nWall - 2;
								gotoXY(printX + (nWall * 2) + 1, printY + 2);
								printf("���� �Ҹ�ġ�� ���ߴ�!! ������ ���ư���              ");
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
		printf(" ���� �ð�: %d�� / �ܹ���(ü��) : %d    \b\b\b\b", (mtime) - (curT - startT), protein);
	} while ((mtime - (curT-startT) > 0) && game_result == 0 && protein > 0);

	if (game_result == 1)
	{
		if (level == 1 || level == 2)
		{
			victorybgm();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR4);
			system("cls");
			printf("\n\n  %d �ܰ� ����!", level);
			printf("\n\n  3�� �� %d �ܰ�� �̵��մϴ�!", level + 1);
			Sleep(3000);
			return level + 1;
		}
		else
		{
			closing();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR4);
			system("cls");
			printf("\n\n  ����̴� �ɺθ��� �����Ͽ�, ������ ȿ�� ��â�� �� �� �־����ϴ�.");
			printf("\n\n  ��Ӵ��� �κ� �丮�� �ܹ����� �����ϰ�,");
			printf("\n\n  ������ ���ư� ��� �������� ���� ��� �����߽��ϴ�!");
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
		printf("\n\n  ����̴� �κ� �ɺθ��� �����߽��ϴ�");
		printf("\n\n  ��Ӵϲ� ȥ���� ���߿� ������� �޴��� ���� �˶��� ��Ƚ��ϴ�.");
		printf("\n\n  ------------------------------------------------------------");
		printf("\n\n  [Web �߽�]");
		printf("\n\n  ��Ʈ�Ͻ� ȸ���Ե鲲 �˸��ϴ�! ���簡 �����Ǵ� ������ ����, \n\n  �̹� �޹��� �ָ����� ����˴ϴ�.");
		printf("\n\n  �������� ������� �����ֺ��� �˰ڽ��ϴ�. �����մϴ�.");
		printf("\n\n  ------------------------------------------------------------");
		printf("\n\n  ��Ʈ������ ���� ����̴�, �� �� ������ �߽��ϴ�.");
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
				printf("��");
			else if (map[i][j] == 'P')
				printf("��");
			else if (map[i][j] == 'C')
				printf("��");
			else if (map[i][j] == 'T' || map[i][j] == 'R')
				printf("��");
			else if (map[i][j] == 'F')
				printf("��");
			else if (map[i][j] == 'D')
				printf("��");
			else
				printf("  ");
		}
		printf("\n  ");
	}
}