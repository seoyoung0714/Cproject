#include "tofu.h"

void game_start()
{
	proteinbgm();
	system("cls");
	printf("    \n\n 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
	printf("\n\n\n\n        헬창 담백이의 인생극장    \n");
	printf("\n\n\n\n         S 키를 눌러 게임 시작");
	printf("\n\n\n\n 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
	printf("\n   ＿                        @______@ \n");                                              
	printf("  / )))　　   ＿            / ㅇㅅㅇ＼ \n"); 
	printf("／  l 　　　((( ＼       ＿ノ ＼　ノ ＼＿\n");                                             
	printf("(　 )　　　　 ￣Y  ＼   /　`/ ⌒Ｙ⌒ Ｙ　 ＼\n"); 
	printf("|　(＼ @____@　 /　 )  (   (三＼人　 /　  |\n");                                            
	printf("＼  ＼(ㅇㅅㅇ) ／  /   (　 )⌒＼ ￣￣＼　 ノ    \n");                                        
	printf(" ＼  |　⌒Y⌒　/  /     ＼＿＿＿＞,＿＿__／ \n");                                         
	printf("　｜ ＼　 l　  /  /         ｜( 王 )〈 \n");                                               
	printf("　 ＼ ト--仝--イ /          /　＼_／　 |\n"); 
	printf("　　＼    土    /           /　＼_／　 |\n");
	printf("　　　)　　　  (           ｜　　/　 ノノ  \n");                                           
	printf("　 　 l　      l           ｜　　/　 ノノ  \n");                             
	while (_getch() != 's');
}

void game_story()
{
	opening();
	system("cls");
	printf(" 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\n\n");
	int i;
	char story_head1[] = " 헬창이 된지 어엿 3 년째인 당신의 이름은 김담백...\n";
	char story_head2[] = " 3 대 500을 찍고 나서부터, 닭가슴살이 나인지, 내가 닭가슴살인지 혼동이 오는 단계에 들어섰다.\n";
	char story_head3[] = " 오늘은 특별히 문을 닫은 헬스장이라는 천재지변이 발생해, 집에서 홈트레이닝을 하고 있는데... 어머니의 목소리가 들린다.";

	char story_line1[] = " 엄마 : ";
	char story_line2[] = "   담백아, 운동 좀 그만하고 두부 좀 사와라\n";
	char story_line3[] = " 담백 : ";
	char story_line4[] = "   심부름은 유산소 운동이라 근손실와요!\n";
	char story_line5[] = "   씁! 덤벨 안 내려놔? 1!! 2!! 3!! 아빠 6시에 도착하신다니까, 그 전에 사와라!\n";
	char story_line6[] = "   아악! 그래 결심했어! 숨 참고 심부름가면 그게 무산소 운동이야!!\n";
	char story_line7[] = "   (집 밖으로 나가는 중...)\n";
	char story_line8[] = "   담백이는 효자 헬창이 되기로 하였다.\n";

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
	printf("\n\n\n\t\t                        S 키를 눌러 게임 시작");
	printf("\n\n\n 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
	while (_getch() != 's');

}

void game_guide()
{
	system("cls");
	printf("    \n\n 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");
	printf("   \n\n \t\t                            심부름 가이드 안내 \n ");
	printf("\n ");
	printf("- 담백이의 움직임은 ◆로 표시된다. 방향키(←,↑,↓,→)를 이용해 주어진 시간과 체력을 고려하여 두부(▶)를 획득하자.\n\n");
	printf(" - 게임 스테이지는 총 3가지 하나로마트-이마트-홈플러스로 구성된다\n\n");
	printf(" - 프로틴(체력) 또는 시간이 0이 되는 순간 게임에서 패배한다.\n\n");
	printf(" - 담백이(◆)는 헬창이라 방향키를 움직일 때마다 프로틴(체력)이 감소되니 주의하자.\n\n");
	printf(" - ▶는 두부, ◎는 시식코너, ◐는 다른 손님, ☎는 전화기, ▤는 진열대이다.\n\n");
	printf(" - 두부(▶)는 여러 개가 있다. 여러 두부 중 엄마가 사오라고 한 적절한 두부를 골라야한다.\n\n");
	printf(" - 시식코너(◎)는 시식을 통해 음식에 따라 체력이 감소되거나 증가될 수 있다.\n\n");
	printf(" - 손님(◐)을 마주치면 시작점으로 돌아가거나 미니게임이 진행된다. 게임에 이기면 두부의 위치 힌트를 얻을 수 있다.\n\n");
	printf(" - 전화기(☎)를 만나면 엄마의 전화를 받아야한다. 엄마의 기분에 따라 찬스가 될 수도, 방해가 될 수도 있으니 주의하자.\n\n");
	printf(" - 진열대(▤)는 아무리 헬스를 했어도 담백이의 힘으로는 이동시킬 수 없으니 반드시 피해가자.\n\n ");
	printf("\n  자! 이제 심부름을 떠나볼까?\n");
	printf("\n\t\t                          S 키를 눌러 게임 시작");
	printf("    \n\n 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓");


	while (_getch() != 's');
}