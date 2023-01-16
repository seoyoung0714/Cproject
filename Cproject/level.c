#include "tofu.h"

int game_level()
{
	system("cls");

	printf(" 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
	printf("\n∥                                      ∥");
	printf("\n∥        어느 마트를 선택할까?         ∥");
	printf("\n∥                                      ∥");
	printf("\n 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),COLOR1);
	printf("   ○  1 단계: 하나로마트 (난이도 : ★☆☆)\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR2);
	printf("   ○  2 단계: 이마트 (난이도 : ★★☆)\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR3);
	printf("   ○  3 단계: 홈플러스 (난이도 : ★★★)\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("\n 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
	printf("      ↑ , ↓ 키를 눌러 메뉴 이동\n\n");
	printf("           S 키를 눌러 선택");

	return UpDown(3, 6, 2, 3);
}