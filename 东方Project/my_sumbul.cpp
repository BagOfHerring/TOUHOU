#pragma once
#include"bullettrack.h"
#include"body.h"
#include"Enemy.h"
#include"global.h"
#include<windows.h>
#include<iostream>


int Timer(int duration, int id);
//�����Լ����ӵ�
void My_Sumbul() {
	while (Status) {
		
			bool z_pressed = 0;
			//�������
			if (GetAsyncKeyState('Z')||GetAsyncKeyState('z')) {
				if (!z_pressed) {
					//�����ӵ�
					character.SumBullet();
					//������Ч
					while(Timer(100, 13)) {
						soloud.play(MyWindow.wav[11],0.3);
					}
					z_pressed = 1;
				}
			}
			else {
				if (z_pressed) {
					z_pressed = 0;
				}
			}
		
	}
}