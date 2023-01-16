#include "tofu.h"

void gotoXY(int x, int y)
{
	COORD Cur = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int UpDown(int x, int y, int term, int max)
{
	int ch, posX = x, posY = y, cur = 1;

	while (1)
	{
		gotoXY(posX, posY);
		printf("��\b\b");

		ch = _getch();
		if (ch == 224)
		{
			ch = _getch();
			switch (ch)
			{
			case UP:
			{
				printf("��");
				if (cur > 1)
				{
					posY -= term;
					cur--;
				}
				break;
			}
			case DOWN:
			{
				printf("��");
				if (cur < max)
				{
					posY += term;
					cur++;
				}
				break;
			}
			}
		}
		else if (ch == 's')
			break;
	}

	return cur;
}

void findFood(int* protein, int printX, int printY)
{
	int x = rand() % 30;
	if (rand() % 2)
	{
		gotoXY(printX, printY);
		printf("���ִ� ������ �ý��ߴ�! ü�� %d ����!                ", x);
		*protein += x;
	}
	else
	{
		if (*protein >= x)
			*protein -= x;
		else
			*protein = 0;
		gotoXY(printX, printY);
		printf("������ ������ �ý��ߴ�.. ü�� %d ����                   ", x);
	}
}

void findCall(int* time, int printX, int printY, int tofuX, int tofuY, int curX, int curY)
{
	int rand_time, good_bad;
	good_bad = rand() % 3;
	rand_time = rand() % 4 + 1;
	gotoXY(printX, printY + 2);
	printf("");
	if (good_bad == 0)
	{
		*time += rand_time;
		if (rand_time % 2 == 0) {
			mother1();
			printf("�Ƶ�~ �ƺ� �ʰ� ���Ŵ�~ õõ�� ���~ (+%d��)               ", rand_time);
		}
		else {
			mother2();
			printf("�Ƶ�~ ���� ���ӱ� ���ϱ� õõ�� �͵� ��~ (+%d��)           ", rand_time);
		}
	}
	else if (good_bad == 1)
	{
		*time -= rand_time;
		mother3();
		printf("�Ƶ� �κ� ����� ����? ���� �� ���? (-%d��)             ", rand_time);
	}
	else
	{
		int dist = abs(curY - tofuY) + abs(curX - tofuX);
		printf("��Ʈ! �κδ� %dĭ �̳��� �ֽ��ϴ�!               ", dist);
	}
}

int mini_Game(int level, int *mtime)
{
	minigamebgm();
	int start;
	int x = rand() % 3;
	start = time(NULL);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR4);
	int i,ch,count;

	if (x == 0)
	{
		int rhythm[20], input[20];
		system("cls");
		printf("\n  �� �ų��� ���� ���� ��\n\n  ");
		printf("ȭ�鿡 ���̴´�� ����Ű�� �������ƿ�!\n\n  ");

		for (i = 0; i < (5 + 5 * level); i++)
		{
			rhythm[i] = rand() % 4;
			if (rhythm[i] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR6);
				printf("��");
			}
			else if (rhythm[i] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR5);
				printf("��");
			}
			else if (rhythm[i] == 2) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR8);
				printf("��");
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR7);
				printf("��");
			}
			printf(" ");
		}

		printf("\n\n  ");

		for (i = 0, count = 0; i < (5 + 5 * level); i++)
		{
			ch = _getch();
			if (ch == 224) {
				ch = _getch();
				if (ch == RIGHT)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR6);
					printf("��");
					input[i] = 0;
				}
				else if (ch == LEFT)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR5);
					printf("��");
					input[i] = 1;
				}
				else if (ch == UP)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR8);
					printf("��");
					input[i] = 2;
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR7);
					printf("��");
					input[i] = 3;
				}
			}
			printf(" ");
			if (rhythm[i] == input[i]) count++;
		}
		*mtime += (int)(time(NULL) - start);
		if (count == (5 + 5 * level)) return 1;
		else return 0;
	}
	else if (x == 1)
	{
		return 2;
	}
	else if (x==2)
	{
		char word[11], input[11];
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("\n  �� Ÿ�� ����!");
		printf("\n\n  ��µ� ������ �Ȱ��� �Է��غ���!\n\n  ���� �ð� : %d ��\n\n  ", TIME_LIM);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR4);
		show_string(word);
		i = 0;
		while ((int)(time(NULL)-start) <= 5)
		{
			if (_kbhit())
			{
				ch = _getch();
				if (ch == 27) break;
				if (ch == 8)
				{
					if (i > 0)
					{
						printf("\b ");
						i--;
						input[i] = 0;
					}
				}
				printf("%c", ch);
				if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
				{
					input[i] = ch;
					i++;
				}
			}
			if (i >= 10)
			{
				input[10] = 0;
				*mtime += (int)(time(NULL) - start);
				if (!strcmp(word, input))
				{
					return 1;
				}
				else
					return 0;
			}
		}
		*mtime += (int)(time(NULL) - start);
		return 0;
	}
}

void show_string(char* w)
{
	int i, m;
	for (i = 0; i < 10; i++)
	{
		m = rand() % 26;
		if (m % 2 == 0)
			w[i] = 'a' + m;
		else
			w[i] = 'A' + m;
		printf("%c", w[i]);
	}
	w[10] = 0;
	printf("\n\n  ");
}