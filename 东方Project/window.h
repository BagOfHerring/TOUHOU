#pragma once
#include<easyx.h>
#include<vector>
#include"soloud.h"
#include"soloud_wav.h"
using namespace SoLoud;

class Window {
private:
	int width,height;
	int score = 0;
	int T;
	int Boss_HP = 26250;
	int HighSpeed_Bullet = 10;
	int LowSpeed_Bullet = 5;
public:
	IMAGE *img[150];
	Wav wav[12];
	Window(int x = 900, int y = 1000) :width(x), height(y) {};
	int getW()const;
	int getH()const;
	void SetT();
	int GetT()const;
	int GetBoss_HP()const;
	void LoadImage();
	void LoadWav();
	int GetHighSpeed_Bullet()const;
	int GetLowSpeed_Bullet()const;
};

extern Window MyWindow;
extern Window GraphicWindow;