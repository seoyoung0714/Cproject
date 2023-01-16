#include "tofu.h"

#define BGM "C:\\Cproject\\Music\\wave_file.wav"
#define MINIGAMEBGM "C:\\Cproject\\Music\\minigamebgm.wav"
#define HANARO "C:\\Cproject\\Music\\hanaro.wav"
#define EMART "C:\\Cproject\\Music\\emart.wav"
#define HOMEPLUS "C:\\Cproject\\Music\\homeplus.wav"
#define PROTEINBGM "C:\\Cproject\\Music\\proteinbgm.wav"
#define OPENING "C:\\Cproject\\Music\\opening.wav"
#define CLOSING "C:\\Cproject\\Music\\closing.wav"
#define MOTHER1 "C:\\Cproject\\Music\\mother1.wav"
#define MOTHER2 "C:\\Cproject\\Music\\mother2.wav"
#define MOTHER3 "C:\\Cproject\\Music\\mother3.wav"
#define LOSEBGM "C:\\Cproject\\Music\\losebgm.wav"
#define VICTORYBGM "C:\\Cproject\\Music\\victorybgm.wav"



void opening() {
	PlaySound(TEXT(OPENING), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void closing() {
	PlaySound(TEXT(CLOSING), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void bgm() {
	PlaySound(TEXT(BGM), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void proteinbgm()
{
	PlaySound(TEXT(PROTEINBGM), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

}


void hanaro()
{
	PlaySound(TEXT(HANARO), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

}

void emart()
{
	PlaySound(TEXT(EMART), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

}

void homeplus()
{
	PlaySound(TEXT(HOMEPLUS), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

}

void mother1()
{
	PlaySound(TEXT(MOTHER1), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}


void mother2()
{
	PlaySound(TEXT(MOTHER2), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}


void mother3()
{
	PlaySound(TEXT(MOTHER3), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void minigamebgm()
{
	PlaySound(TEXT(MINIGAMEBGM), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void losebgm()
{
	PlaySound(TEXT(LOSEBGM), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void victorybgm()
{
	PlaySound(TEXT(VICTORYBGM), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}


void soundstop() {
	PlaySound("NULL", 0, 0);
}

