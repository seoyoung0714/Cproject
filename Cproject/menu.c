#include "tofu.h"

int game_menu()
{
	bgm();
	system("cls");
	printf(" 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
	printf("\n∥                                      ∥");
	printf("\n∥        헬창 담백이의 인생극장        ∥");
	printf("\n∥                                      ∥");
	printf("\n 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
	printf("    ○  게임 시작 \n\n");
	printf("    ○  게임 가이드 \n\n");
	printf("    ○  게임 스토리 \n\n");
	printf("    ○  게임 종료 \n\n");
	printf(" 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\n");
	printf("      ↑ , ↓ 키를 눌러 메뉴 이동\n\n");
	printf("           S 키를 눌러 선택");
	return UpDown(4,6,2,4);
}