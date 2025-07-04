#pragma once
#include "body.h"
#include<Windows.h>
#include<iostream>
#include"window.h"

using namespace std;

int Timer(int duration, int id);

void KeyDown() {
	static bool shift_pressed = 0;
	int ddx = 0;
	int ddy = 0;
	//检测输入
	if (GetAsyncKeyState(VK_LEFT)) {
		if (character.GetX() >= character.GetR()) {
			ddx--;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		if (character.GetX() <= MyWindow.getW() - character.GetR()) {
			ddx++;
		}
	}
	if (GetAsyncKeyState(VK_UP)) {
		if (character.GetY() >= character.GetR()) {
			ddy--;
		}
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		if (character.GetY() <= MyWindow.getH() - character.GetR()) {
			ddy++;
		}
	}
	//计算实际xy分速度
	int voltage = character.GetDx();
	BulletStatus = HIGHSPEED;
	if (GetAsyncKeyState(VK_SHIFT)) {
		voltage /= 2;
		BulletStatus = LOWSPEED;
	}
	if (ddx != 0 || ddy != 0) {
		character.UpdateX(voltage * ddx / sqrt(ddx * ddx + ddy * ddy));
		character.UpdateY(voltage * ddy / sqrt(ddx * ddx + ddy * ddy));
	}
	Sleep(10);
}