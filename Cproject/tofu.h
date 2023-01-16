#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")


#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define P1 3 //1 �ܰ� ��� ��
#define DUBU1 3 //1 �ܰ� �κ� ��
#define CALL1 2 //1 �ܰ� ��ȭ ��
#define MAP1 15 //1 �ܰ� �� ũ��
#define FOOD1 3 //1 �ܰ� �ý��ڳ� ��
#define DISPLAY1 5 //1 �ܰ� ������ ��

#define P2 5 //2 �ܰ� ��� ��
#define DUBU2 5 //2 �ܰ� �κ� ��
#define CALL2 4 //2 �ܰ� ��ȭ ��
#define MAP2 20 //2 �ܰ� �� ũ��
#define FOOD2 5 //2 �ܰ� �ý��ڳ� ��
#define DISPLAY2 8 //2 �ܰ� ������ ��

#define P3 7 //3 �ܰ� ��� ��
#define DUBU3 7 //3 �ܰ� �κ� ��
#define CALL3 6 //3 �ܰ� ��ȭ ��
#define MAP3 25 //3 �ܰ� �� ũ��
#define FOOD3 7 //3 �ܰ� �ý��ڳ� ��
#define DISPLAY3 10 //3 �ܰ� ������ ��

#define COLOR1 2 //���� �ʷ�
#define COLOR2 6 //���� ���
#define COLOR3 12 //���� ����
#define COLOR4 15 //���� ���
#define COLOR5 10 //���� �ʷ� 
#define COLOR6 11 //�ϴ�
#define COLOR7 12 //���� ����
#define COLOR8 14 //���� ���

#define BGM1 1 //�ϳ��� ��Ʈ 
#define BGM2 2 //�̸�Ʈ
#define BGM3 3 //Ȩ�÷���

#define TIME_LIM 8 //�̴ϰ��� �ð� ����


void printMap(char map[][MAP3], int wall, int nColor, int nBgm);
void findCall(int* time, int printX, int printY, int tofuX, int tofuY, int curX, int curY);
int mini_Game(int level, int *mtime);
void findFood(int* protein, int printX, int printY);
void show_string(char* w);
int start_game(char map[][MAP3], int level);
void game_start();
void game_story();
void game_guide();
int game_menu();
int game_level();
int UpDown(int x, int y, int term, int max);
void gotoXY(int x, int y);
void opening();
void closing();
void bgm();
void proteinbgm();
void hanaro();
void emart();
void homeplus();
void mother1();
void mother2();
void mother3();
void soundstop();
void minigamebgm();
void losebgm();
void victorybgm();
