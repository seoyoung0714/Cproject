#include "tofu.h"

int game_menu()
{
	bgm();
	system("cls");
	printf(" ���������������������");
	printf("\n��                                      ��");
	printf("\n��        ��â ������� �λ�����        ��");
	printf("\n��                                      ��");
	printf("\n ���������������������\n\n");
	printf("    ��  ���� ���� \n\n");
	printf("    ��  ���� ���̵� \n\n");
	printf("    ��  ���� ���丮 \n\n");
	printf("    ��  ���� ���� \n\n");
	printf(" ���������������������\n\n");
	printf("      �� , �� Ű�� ���� �޴� �̵�\n\n");
	printf("           S Ű�� ���� ����");
	return UpDown(4,6,2,4);
}