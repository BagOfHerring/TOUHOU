using namespace std;
#include<graphics.h>
#include"window.h"
void loading() {
	cleardevice();
	//贴两张图假装在加载，实际作用为防止界面切换时按键未松开导致误操作
	putimage(0, 0, MyWindow.img[73]);
	putimage(GraphicWindow.getW()/2, GraphicWindow.getW()/2, MyWindow.img[101],SRCAND);
	putimage(GraphicWindow.getW() / 2, GraphicWindow.getW() / 2, MyWindow.img[100],SRCPAINT);
	FlushBatchDraw();
	Sleep(2000);
}