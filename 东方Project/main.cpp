#include<iostream>
#include<conio.h>
#include<easyx.h>
#include<cmath>
#include<ctime>
#include<windows.h>
#include<stdio.h>
#include"body.h"
#include"global.h"
#include"window.h"
#include<cstdlib>
#include<vector>
#include<string>
#include<tchar.h>
#include"Enemy.h"
#include<thread>

#include"Loot.h"
#include<direct.h>

vector<Loot> blueloot;
vector<Loot> redloot;
vector<Enemy> enemy;
unique_ptr<Enemy> boss;
vector<BulletTrack> MyBullets;
atomic<bool> Status(true);
vector<BulletTrack> BulletBufferA;
vector<BulletTrack> BulletBufferB;
vector<BulletTrack>* FrontBuffer = &BulletBufferA;
vector<BulletTrack>* BackBuffer = &BulletBufferB;
mutex bufferLock;
int Score = 0;
int enemy_maxdrop = 6;
int boss_maxdrop = 5;
int LootSumRange = 100;


int TitleBgmHandle;
int MidBgmHandle;
int BossBgmHandle;
mutex globallock;
mutex olock;
GameMode Mode = EASY;
CharacterBullet BulletStatus = HIGHSPEED;
Soloud soloud;

using namespace std;
using namespace SoLoud;
void InitGame();
void UpdateGame();
void KeyDown();
void drawgame();
void sumbul();
void My_Sumbul();
void Enemy_Sumbul();
void GameStage();
bool titlepage();
int difficultyselect();
int characterselect();
void loading();
void end();
void Monitor();

int main() {
	//初始化
	soloud.init();
	MyWindow.LoadImage();
	MyWindow.LoadWav();
	srand(std::time(0));
	extern Window MyWindow;
	initgraph(GraphicWindow.getW(), GraphicWindow.getH());
	Status = true;
	MyWindow.SetT();
	BeginBatchDraw();
	//游戏主循环
	while (1) {
		loading();
		//标题页
		if (titlepage()) {
			break;
		}
		//难度选择
		switch (difficultyselect()) {
		case 1:
			Mode = EASY;
			break;
		case 2:
			Mode = HARD;
			break;
		}
		//角色选择
		switch (characterselect()) {
		case 1:
			extern Body character;
			character = Body(MyWindow.getW() / 2, 790, 7, 7, 5, 10, "rm");
			break;
		case 2:
			extern Body character;
			character = Body(MyWindow.getW() / 2, 790, 4, 4, 7, 15, "mrs");
			break;
		}
		loading();
		//进入游戏内部
		Status = true;
		thread update(UpdateGame);
		thread mysumbul(My_Sumbul);
		thread gamestage(GameStage);
		thread draw(drawgame);
		//thread monitor1(Monitor);

		//if(monitor1.joinable()) monitor1.join();
		if (update.joinable()) update.join();
		if (draw.joinable()) draw.join();
		if (mysumbul.joinable()) mysumbul.join();
		if (gamestage.joinable()) gamestage.detach();
		//游戏结束
		end();
	}
	//退出
	EndBatchDraw();	
	closegraph();
	soloud.deinit();
	return 0;
}
