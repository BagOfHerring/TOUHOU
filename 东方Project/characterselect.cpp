#pragma once
using namespace std;
#include<graphics.h>
#include"window.h"
#include"global.h"
int Timer(int duration, int id);

int characterselect() {
	int chara=1;
	while (1) {
		cleardevice();
		putimage(0, 0, MyWindow.img[73]);
		putimage(0, 0, MyWindow.img[60], SRCAND);
		putimage(0, 0, MyWindow.img[59], SRCPAINT);
		//�������������л���ɫ
			while (Timer(100, 1)) {
				if (GetAsyncKeyState(VK_DOWN) && chara < 2) {
					chara++;
				}
				if (GetAsyncKeyState(VK_UP) && chara > 1) {
					chara--;
				}
			}
			//�ڻ������½���ʾ֮ǰ��ѡ����Ѷ�
			if (Mode == EASY) {
				putimage(0, 800, MyWindow.img[66], SRCAND);
				putimage(0, 800, MyWindow.img[65], SRCPAINT);
			}
			

				if (Mode == HARD){
				putimage(0, 800, MyWindow.img[70], SRCAND);
				putimage(0, 800, MyWindow.img[69], SRCPAINT);
				}
				//����ѡ��Ľ�ɫ��ͬ������ͬ����ͼ
			switch (chara) {
			case 1:
				putimage(500, 0, MyWindow.img[57], SRCAND);
				putimage(500, 0, MyWindow.img[56], SRCPAINT);
				putimage(0, 400, MyWindow.img[55], SRCAND);
				putimage(0, 400, MyWindow.img[54], SRCPAINT);
				break;
			case 2:
				putimage(500, 0, MyWindow.img[53], SRCAND);
				putimage(500, 0, MyWindow.img[52], SRCPAINT);
				putimage(0, 400, MyWindow.img[51], SRCAND);
				putimage(0, 400, MyWindow.img[50], SRCPAINT);
			}
			//���ȷ�ϼ�
			if (GetAsyncKeyState('Z')||GetAsyncKeyState(VK_RETURN)) {
				soloud.play(MyWindow.wav[3]);
				soloud.stop(TitleBgmHandle);
				Sleep(200);
				return chara;
			}
			FlushBatchDraw();
	}
}