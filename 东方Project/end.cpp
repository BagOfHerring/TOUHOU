#pragma once
using namespace std;
#include<conio.h>
#include <graphics.h>
#include"window.h"
#include"global.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include"Enemy.h"
#include"Loot.h"
#include"body.h"
void end() {
	cleardevice();
	//�崦����ʣ��ʵ��
	enemy.clear();
	FrontBuffer->clear();
	BackBuffer->clear();
	MyBullets.clear();
	redloot.clear();
	blueloot.clear();
	boss = nullptr;
	//����������ͼ
	putimage(0, 0, MyWindow.img[73]);
	putimage(GraphicWindow.getW() / 2 - 125, GraphicWindow.getH() / 2 - 50, MyWindow.img[77], SRCAND);
	putimage(GraphicWindow.getW() / 2 - 125, GraphicWindow.getH() / 2 - 50, MyWindow.img[76], SRCPAINT);

	
	//�Ѷ���ʾ
	if (Mode == EASY) {
		TCHAR s[10] = "Normal";
		outtextxy(GraphicWindow.getW() / 2 + 50, GraphicWindow.getH() / 2 + 5, s);
	}
	if (Mode == HARD) {
		TCHAR s[10] = "Hard";
		outtextxy(GraphicWindow.getW() / 2 + 50, GraphicWindow.getH() / 2 + 5, s);
	}
	//���շ�������
	int FinalScore = Score + character.GetHP() * 200;
	if (character.GetLevel() == 5) {
		FinalScore += character.GetExp() * 2;
	}
	if (Mode == HARD) {
		FinalScore *= 1.2;
	}
	TCHAR s[10];
	sprintf_s(s, _T("%d"), FinalScore);
	outtextxy(GraphicWindow.getW() / 2 + 50, GraphicWindow.getH() / 2 - 15, s);
	//�ļ���д����¼��߷�
	ifstream record("record.txt", ios::in);
	ofstream score;
	if (!record.is_open()) {
		sprintf_s(s, _T("%d"), FinalScore);
		score.open("record.txt", ios::out);
		score  << FinalScore;
	}
	else {
		string ss;
		getline(record, ss);
		int prior = stoi(ss, nullptr, 10);


		if (FinalScore <= prior) {
			sprintf_s(s, _T("%d"), prior);
		}
		else {
			sprintf_s(s, _T("%d"), FinalScore);
			score.open("record.txt", ios::out);
			score  << FinalScore;
		}
	}
	record.close();
	score.close();
	outtextxy(GraphicWindow.getW() / 2 + 50, GraphicWindow.getH() / 2 + 25, s);
	FlushBatchDraw();
	Sleep(3000);
	//3���ɰ�z��enter���˳�
	while (!(GetAsyncKeyState('Z') || !GetAsyncKeyState(VK_RETURN))) {
		Sleep(20);
}
	Sleep(200);
}