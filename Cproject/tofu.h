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

#define P1 3 //1 단계 사람 수
#define DUBU1 3 //1 단계 두부 수
#define CALL1 2 //1 단계 전화 수
#define MAP1 15 //1 단계 맵 크기
#define FOOD1 3 //1 단계 시식코너 수
#define DISPLAY1 5 //1 단계 진열대 수

#define P2 5 //2 단계 사람 수
#define DUBU2 5 //2 단계 두부 수
#define CALL2 4 //2 단계 전화 수
#define MAP2 20 //2 단계 맵 크기
#define FOOD2 5 //2 단계 시식코너 수
#define DISPLAY2 8 //2 단계 진열대 수

#define P3 7 //3 단계 사람 수
#define DUBU3 7 //3 단계 두부 수
#define CALL3 6 //3 단계 전화 수
#define MAP3 25 //3 단계 맵 크기
#define FOOD3 7 //3 단계 시식코너 수
#define DISPLAY3 10 //3 단계 진열대 수

#define COLOR1 2 //진한 초록
#define COLOR2 6 //진한 노랑
#define COLOR3 12 //진한 빨강
#define COLOR4 15 //밝은 흰색
#define COLOR5 10 //밝은 초록 
#define COLOR6 11 //하늘
#define COLOR7 12 //밝은 빨강
#define COLOR8 14 //밝은 노랑

#define BGM1 1 //하나로 마트 
#define BGM2 2 //이마트
#define BGM3 3 //홈플러스

#define TIME_LIM 8 //미니게임 시간 제한


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
