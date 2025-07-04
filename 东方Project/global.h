#pragma once
#include<mutex>
#include<atomic>
#include"soloud.h"
#include<vector>
#include"bullettrack.h"

using namespace std;
using namespace SoLoud;
extern atomic<bool> Status;
enum GameMode { EASY, HARD, ENDLESS };
extern GameMode Mode;
extern mutex globallock;
extern mutex enemylock;
extern mutex olock;
enum CharacterBullet { HIGHSPEED, LOWSPEED };
extern CharacterBullet BulletStatus;
extern int Score;
extern int enemy_maxdrop;
extern int boss_maxdropp;
extern int LootSumRange;
extern Soloud soloud;
extern int TitleBgmHandle;
extern int MidBgmHandle;
extern int BossBgmHandle;
extern std::mutex bufferLock;
