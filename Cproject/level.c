#include "tofu.h"

int game_level()
{
	system("cls");

	printf(" ���������������������");
	printf("\n��                                      ��");
	printf("\n��        ��� ��Ʈ�� �����ұ�?         ��");
	printf("\n��                                      ��");
	printf("\n ���������������������\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),COLOR1);
	printf("   ��  1 �ܰ�: �ϳ��θ�Ʈ (���̵� : �ڡ١�)\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR2);
	printf("   ��  2 �ܰ�: �̸�Ʈ (���̵� : �ڡڡ�)\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR3);
	printf("   ��  3 �ܰ�: Ȩ�÷��� (���̵� : �ڡڡ�)\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("\n ���������������������\n\n");
	printf("      �� , �� Ű�� ���� �޴� �̵�\n\n");
	printf("           S Ű�� ���� ����");

	return UpDown(3, 6, 2, 3);
}