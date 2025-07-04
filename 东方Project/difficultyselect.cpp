#pragma once
using namespace std;
#include<graphics.h>
#include"window.h"
#include"global.h"
int Timer(int duration, int id);

int difficultyselect() {
	int level=1;
	while (1) {
		cleardevice();
		putimage(0, 0, MyWindow.img[73]);
		putimage(0, 0, MyWindow.img[75], SRCAND);
		putimage(0, 0, MyWindow.img[74], SRCPAINT);
		//检测↑、↓键输入
		while (Timer(100, 1)) {
			if (GetAsyncKeyState(VK_DOWN) && level < 2) {
				level++;
			}
			if (GetAsyncKeyState(VK_UP) && level > 1) {
				level--;
			}
		}
		//根据选择的level贴出不一样的贴图
		switch (level) {
		case 1:
			putimage(250, 250, MyWindow.img[66], SRCAND);
			putimage(250, 250, MyWindow.img[65], SRCPAINT);
			putimage(500, 600, MyWindow.img[72], SRCAND);
			putimage(500, 600, MyWindow.img[71], SRCPAINT);
			break;
		case 2:
			putimage(250,250, MyWindow.img[68], SRCAND);
			putimage(250, 250, MyWindow.img[67], SRCPAINT);
			putimage(500, 600, MyWindow.img[70], SRCAND);
			putimage(500, 600, MyWindow.img[69], SRCPAINT);
			break;

		}
		//检测确认键
		if (GetAsyncKeyState('Z')||GetAsyncKeyState(VK_RETURN)) {
			soloud.play(MyWindow.wav[3]);
			Sleep(200);
			return level;
		}
		FlushBatchDraw();
	}
}