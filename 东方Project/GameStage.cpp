#pragma once
#include"Enemy.h"
#include"bullettrack.h"
#include"body.h"
#include<windows.h>
#include<memory>
#include<thread>
#include<iostream>
#include<cstdlib>
void MidStage();
void BossStage();
using namespace std;

int Timer(int duration, int id);

void GameStage() {
	//µÀÖÐ
	MidStage();
	//Boss
	if(Status)
	BossStage();
}