
#include<graphics.h>
#include"window.h"
#include"global.h"

int Timer(int duration, int id);
using namespace std;


bool titlepage() {
	bool isquit=false;
	//��������������
	TitleBgmHandle=soloud.play(MyWindow.wav[0]);
	soloud.setLooping(TitleBgmHandle,true);
	while (1) {
		cleardevice();
		putimage(0, 0, MyWindow.img[99]);
		//����������в�ͬ��ͼ
		if (isquit) {
			putimage(150, 500, MyWindow.img[98], SRCAND);
			putimage(150, 500, MyWindow.img[97], SRCPAINT);
			putimage(150, 600, MyWindow.img[92], SRCAND);
			putimage(150, 600, MyWindow.img[91], SRCPAINT);
		}			 
		else {		 
			putimage(150, 500, MyWindow.img[96], SRCAND);
			putimage(150, 500, MyWindow.img[95], SRCPAINT);
			putimage(150, 600, MyWindow.img[94], SRCAND);
			putimage(150, 600, MyWindow.img[93], SRCPAINT);
		}
		//����������
		if (GetAsyncKeyState(VK_DOWN) ){
			if (!isquit) {
				isquit = !isquit;
			}
		}
		else if (GetAsyncKeyState(VK_UP)) {
			if (isquit) {
				isquit = !isquit;
			}
		}
		//���ȷ�ϰ���
		if (GetAsyncKeyState('Z')|| GetAsyncKeyState(VK_RETURN)) {
			soloud.play(MyWindow.wav[3]);
			Sleep(200);
			return isquit;
		}
		FlushBatchDraw();
	}
}