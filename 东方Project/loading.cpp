using namespace std;
#include<graphics.h>
#include"window.h"
void loading() {
	cleardevice();
	//������ͼ��װ�ڼ��أ�ʵ������Ϊ��ֹ�����л�ʱ����δ�ɿ����������
	putimage(0, 0, MyWindow.img[73]);
	putimage(GraphicWindow.getW()/2, GraphicWindow.getW()/2, MyWindow.img[101],SRCAND);
	putimage(GraphicWindow.getW() / 2, GraphicWindow.getW() / 2, MyWindow.img[100],SRCPAINT);
	FlushBatchDraw();
	Sleep(2000);
}