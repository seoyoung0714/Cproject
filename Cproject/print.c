#include "tofu.h"

void game_start()
{
	proteinbgm();
	system("cls");
	printf("    \n\n ����������������������");
	printf("\n\n\n\n        ��â ������� �λ�����    \n");
	printf("\n\n\n\n         S Ű�� ���� ���� ����");
	printf("\n\n\n\n ����������������������");
	printf("\n   ��                        @______@ \n");                                              
	printf("  / )))����   ��            / �������� \n"); 
	printf("��  l ������((( ��       �߫� ������ ����\n");                                             
	printf("(�� )�������� ��Y  ��   /��`/ �ң١� �١� ��\n"); 
	printf("|��(�� @____@�� /�� )  (   (߲���ѡ� /��  |\n");                                            
	printf("��  ��(������) ��  /   (�� )�ҡ� �������� ��    \n");                                        
	printf(" ��  |����Y�ҡ�/  /     ���ߣߣߣ�,�ߣ�__�� \n");                                         
	printf("���� ���� l��  /  /         ��( �� )�� \n");                                               
	printf("�� �� ��--��--�� /          /����_���� |\n"); 
	printf("������    ��    /           /����_���� |\n");
	printf("������)������  (           ������/�� �Ϋ�  \n");                                           
	printf("�� �� l��      l           ������/�� �Ϋ�  \n");                             
	while (_getch() != 's');
}

void game_story()
{
	opening();
	system("cls");
	printf(" ������������������������������������������������������������\n\n\n");
	int i;
	char story_head1[] = " ��â�� ���� � 3 ��°�� ����� �̸��� ����...\n";
	char story_head2[] = " 3 �� 500�� ��� ��������, �߰������� ������, ���� �߰��������� ȥ���� ���� �ܰ迡 ����.\n";
	char story_head3[] = " ������ Ư���� ���� ���� �ｺ���̶�� õ�������� �߻���, ������ ȨƮ���̴��� �ϰ� �ִµ�... ��Ӵ��� ��Ҹ��� �鸰��.";

	char story_line1[] = " ���� : ";
	char story_line2[] = "   ����, � �� �׸��ϰ� �κ� �� ��Ͷ�\n";
	char story_line3[] = " ��� : ";
	char story_line4[] = "   �ɺθ��� ����� ��̶� �ټսǿͿ�!\n";
	char story_line5[] = "   ��! ���� �� ������? 1!! 2!! 3!! �ƺ� 6�ÿ� �����ϽŴٴϱ�, �� ���� ��Ͷ�!\n";
	char story_line6[] = "   �ƾ�! �׷� ����߾�! �� ���� �ɺθ����� �װ� ����� ��̾�!!\n";
	char story_line7[] = "   (�� ������ ������ ��...)\n";
	char story_line8[] = "   ����̴� ȿ�� ��â�� �Ǳ�� �Ͽ���.\n";

	for (i = 0; i < strlen(story_head1); i++)
	{
		putchar(story_head1[i]);
		Sleep(60);
	}
	Sleep(500);
	printf("\n");

	for (i = 0; i < strlen(story_head2); i++)
	{
		putchar(story_head2[i]);
		Sleep(63);
	}
	Sleep(500); 
	printf("\n");

	for (i = 0; i < strlen(story_head3); i++)
	{
		putchar(story_head3[i]);
		Sleep(60);
	}
	Sleep(1000);

	printf("\n\n%s\n", story_line1);
	for (i = 0; i < strlen(story_line2); i++)
	{
		putchar(story_line2[i]);
		Sleep(50);
	}
	Sleep(500);

	printf("\n%s\n", story_line3);
	for (i = 0; i < strlen(story_line4); i++)
	{
		putchar(story_line4[i]);
		Sleep(50);
	}
	printf("\n%s\n", story_line1);
	for (i = 0; i < strlen(story_line5); i++)
	{
		putchar(story_line5[i]);
		Sleep(80);
	}
	printf("\n%s\n", story_line3);
	for (i = 0; i < strlen(story_line6); i++)
	{
		putchar(story_line6[i]);
		Sleep(50);
	}
	printf("\n%s\n", story_line7);
	printf("\n");
	Sleep(5000);
	for (i = 0; i < strlen(story_line8); i++)
	{
		putchar(story_line8[i]);
		Sleep(50);
	}
	Sleep(50);
	printf("\n\n\n\t\t                        S Ű�� ���� ���� ����");
	printf("\n\n\n ������������������������������������������������������������");
	while (_getch() != 's');

}

void game_guide()
{
	system("cls");
	printf("    \n\n ����������������������������������������������������������");
	printf("   \n\n \t\t                            �ɺθ� ���̵� �ȳ� \n ");
	printf("\n ");
	printf("- ������� �������� �߷� ǥ�õȴ�. ����Ű(��,��,��,��)�� �̿��� �־��� �ð��� ü���� ����Ͽ� �κ�(��)�� ȹ������.\n\n");
	printf(" - ���� ���������� �� 3���� �ϳ��θ�Ʈ-�̸�Ʈ-Ȩ�÷����� �����ȴ�\n\n");
	printf(" - ����ƾ(ü��) �Ǵ� �ð��� 0�� �Ǵ� ���� ���ӿ��� �й��Ѵ�.\n\n");
	printf(" - �����(��)�� ��â�̶� ����Ű�� ������ ������ ����ƾ(ü��)�� ���ҵǴ� ��������.\n\n");
	printf(" - ���� �κ�, �ݴ� �ý��ڳ�, �Ĵ� �ٸ� �մ�, �ϴ� ��ȭ��, �Ǵ� �������̴�.\n\n");
	printf(" - �κ�(��)�� ���� ���� �ִ�. ���� �κ� �� ������ ������ �� ������ �κθ� �����Ѵ�.\n\n");
	printf(" - �ý��ڳ�(��)�� �ý��� ���� ���Ŀ� ���� ü���� ���ҵǰų� ������ �� �ִ�.\n\n");
	printf(" - �մ�(��)�� ����ġ�� ���������� ���ư��ų� �̴ϰ����� ����ȴ�. ���ӿ� �̱�� �κ��� ��ġ ��Ʈ�� ���� �� �ִ�.\n\n");
	printf(" - ��ȭ��(��)�� ������ ������ ��ȭ�� �޾ƾ��Ѵ�. ������ ��п� ���� ������ �� ����, ���ذ� �� ���� ������ ��������.\n\n");
	printf(" - ������(��)�� �ƹ��� �ｺ�� �߾ ������� �����δ� �̵���ų �� ������ �ݵ�� ���ذ���.\n\n ");
	printf("\n  ��! ���� �ɺθ��� ��������?\n");
	printf("\n\t\t                          S Ű�� ���� ���� ����");
	printf("    \n\n ����������������������������������������������������������");


	while (_getch() != 's');
}