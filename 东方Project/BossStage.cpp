#pragma once
#include"Enemy.h"
#include"bullettrack.h"
#include"body.h"
#include<windows.h>
#include<memory>
#include<thread>
#include<iostream>
#include<cstdlib>
int Timer(int duration, int id);
void BossStage() {//boss�׶�
	
	//��ʼ��������boss�׶α�������
	BossBgmHandle = soloud.play(MyWindow.wav[2]);
	soloud.setLooping(BossBgmHandle, true);

	//���ɲ��趨boss�ƶ�·��
	if (Status) {
		boss = make_unique<Enemy>(MyWindow.getW() / 2, 0, 0, 5, 5, 50, MyWindow.GetBoss_HP(), "Boss", 5);
		boss->move_towards(MyWindow.getW() / 2, MyWindow.getH() / 8, 2);
	}



	//����1 ���ϵĴ���

	int s = 1;
	while (Status && boss != nullptr && boss->GetStage() == 5) {
		//boss�ڳ�������λ������ƶ�
		if (boss->whether_arrived() && boss != nullptr && boss->GetStage() == 5) {
			switch (s % 2) {
			case 0:
				boss->move_towards(5 * MyWindow.getW() / 8, MyWindow.getH() / 8, 2);
				break;
			case 1:
				boss->move_towards(3 * MyWindow.getW() / 8, MyWindow.getH() / 8, 2);
				break;
			}
		}
		//boss�ƶ���ָ��λ�ú�ʼ����
		while (Status && boss != nullptr && !boss->whether_arrived()) {
			Sleep(20);
		}
		//��һ��
		for (int i = 0; i < 3 && boss->GetStage() == 5; i++) {
			//��״��λ��
			double theta = 0;
			globallock.lock();
			for (int j = 0; j < 120 && boss->GetStage() == 5; j++) {
				BulletTrack tempbullet(boss->GetX(), boss->GetY(), 0, 8, 0, "slope", "BM", 0.6);
				PushBullet(tempbullet);
				BackBuffer->back().Summond(theta + j * 3);
			}
			globallock.unlock();
			//ͣ��
			if (boss->GetStage() == 5)
				Sleep(2200);
			//��λ��������
			theta = 1.5;
			for (int j = 0; j < 5 && boss->GetStage() == 5; j++) {//��������
				if (Timer(10, 17)) {
					globallock.lock();
					for (int k = 0; k < 120; k++) {//��������
						BulletTrack tempbullet(boss->GetX(), boss->GetY(), 0, 4, 0, "slope", "BS", 2);
						PushBullet(tempbullet);
						BackBuffer->back().Summond(theta + k * 3);
					}
					globallock.unlock();
				}
				else
					j--;
			}

			//���ֵ���ͣ��ʱ�����ѶȲ�ͬ
			if (boss->GetStage() == 5)
				Sleep((Mode == HARD ? 500 : 1000));
		}
		//�ڶ���
		//��״��λ��
		for (int i = 0; i < 3 && boss->GetStage() == 5; i++) {
			double theta = i * 3.75;
			if (Timer(50, 17)) {
				globallock.lock();
				for (int j = 0; j < 40 && boss->GetStage() == 5; j++) {
					BulletTrack tempbullet(boss->GetX(), boss->GetY(),0, 8, 0, "slope", "RM", 0.6);
					PushBullet(tempbullet);
					BackBuffer->back().Summond(theta + j * 9);
				}
				globallock.unlock();
			}
			else
				i--;
		}
		if (boss->GetStage() == 5)
			Sleep(2200);
		//��λ��������
		for (int i = 0; i < 3 && boss->GetStage() == 5; i++) {
			double theta;
			switch (i) {
			case 0:
				theta = 4.5;
				break;
			case 1:
				theta = 8.75;
				break;
			case 2:
				theta = 3;
				break;
			}
			for (int j = 0; j < 5 && boss->GetStage() == 5; j++) {//��������
				if (Timer(30, 17)) {
					globallock.lock();
					for (int k = 0; k < 40 && boss->GetStage() == 5; k++) {//��������
						BulletTrack tempbullet(boss->GetX(), boss->GetY(),0, 4, 0, "slope", "RS", 2);
						PushBullet(tempbullet);
						BackBuffer->back().Summond(theta + k * 9);
					}
					globallock.unlock();
				}
				else
					j--;
			}
			Sleep(30);
		}
		if (boss->GetStage() == 5)
			Sleep((Mode == HARD ? 1000 : 2000));
		s++;
	}
	globallock.lock();
	BackBuffer->clear();
	FrontBuffer->clear();
	globallock.unlock();
	boss->move_towards(MyWindow.getW() / 2, MyWindow.getH() / 8, 2);
	Sleep(2000);

	//����2 ԭʼ�������
	while (Status && boss->GetStage() == 4) {
		//���������
		for (int i = 0; i < (Mode == HARD ? 400 : 250) && boss->GetStage() == 4; i++) {
			Sleep(5);
			//�ڴ��������ѡȡ����
			unsigned int randx = rand() % 900;
			unsigned int randy = rand() % 1000;
			globallock.lock();
			//�ĸ������������������
			if (randy + 2 * randx / 3 <= 600 && i % 4 == 0) {
				BulletTrack tempbullet(static_cast<int>(randx), static_cast<int>(randy),0, 12, 0, "stop", "GB");
				PushBullet(tempbullet);
				BackBuffer->back().Summond();
			}
			else if (2 * randx + randy >= 1800 && i % 4 == 1) {
				BulletTrack tempbullet(static_cast<int>(randx), static_cast<int>(randy),0, 12, 0, "stop", "B");
				PushBullet(tempbullet);
				BackBuffer->back().Summond();
			}
			else if (randy + 2 * randx / 3 >= 1000 && i % 4 == 2) {
				BulletTrack tempbullet(static_cast<int>(randx), static_cast<int>(randy),0, 12, 0, "stop", "RB");
				PushBullet(tempbullet);
				BackBuffer->back().Summond();
			}
			else if (randy >= 2 * randx && i % 4 == 3) {
				BulletTrack tempbullet(static_cast<int>(randx), static_cast<int>(randy), 0, 12, 0, "stop", "BB");
				PushBullet(tempbullet);
				BackBuffer->back().Summond();
			}
			globallock.unlock();
		}
		if (boss->GetStage() == 4)
			Sleep(2000);
		//������ƶ�
		double speed = 0.2;
		while (Status && boss->GetStage() == 4 && FrontBuffer->size() != 0) {
			globallock.lock();
			for (auto it = FrontBuffer->begin(); it != FrontBuffer->end(); ++it) {
				if (it->GetName() == "GB") {
					it->move_towards(it->GetX(), MyWindow.getH() + 10, speed);
				}
				else if (it->GetName() == "B") {
					it->move_towards(-10, it->GetY(), speed);
				}
				else if (it->GetName() == "RB") {
					it->move_towards(it->GetX(), -10, speed);
				}
				else if (it->GetName() == "BB") {
					it->move_towards(MyWindow.getW() + 10, it->GetY(), speed);
				}
			}
			globallock.unlock();
			if (speed <= 2) {
				speed += 0.3;
			}
			if (boss->GetStage() == 4)
				Sleep(1000);
		}

		if (boss->GetStage() == 4)
			Sleep(5000);
	}
	globallock.lock();
	BackBuffer->clear();
	FrontBuffer->clear();
	globallock.unlock();

	//����3 ս���ĺ���֮��
	while (Status && boss != nullptr && boss->GetStage() == 3) {
		if (boss->whether_arrived()) {
			//��״��λ��
			double theta = 0;
			for (int i = 1; i < (Mode == HARD ? 6 : 4) && boss != nullptr; i++) {
				switch (i % 2) {
				case 0:
					theta = 0;
					break;
				case 1:
					theta = 2.5;
					break;
				}
				globallock.lock();
				for (int j = 0; j < 72 && boss->GetStage() == 3 && boss != nullptr; j++) {
					BulletTrack tempbullet(boss->GetX(), boss->GetY(),0, 8, 0, "slope", "BM", 0.5);
					PushBullet(tempbullet);
					BackBuffer->back().Summond(theta + j * 5);
				}
				globallock.unlock();
				Sleep(200);
			}
			if (boss->GetStage() == 3)
				Sleep((Mode == HARD ? 2000 : 3000));
		}
	}
	globallock.lock();
	BackBuffer->clear();
	FrontBuffer->clear();
	globallock.unlock();

	//����4 ����ĵ�Ļ����
	if (Mode == HARD) {
		while (Status && boss != nullptr && (boss->GetStage() <= 2 && boss->GetStage() >= 0)) {
			//�׶�1
			if (Timer(400, 15)) {
				for (int j = 0; j < 2; j++) {
					//�жϴ˽׶��Ƿ����ⲿ�ֵ�Ļ
					if (boss->GetStage() <= 2) {
						int randx = rand() % MyWindow.getW();
						int randy = rand() % MyWindow.getH();
						double theta = 0;
						if (pow(randx - 450, 2) + pow(randy - 125, 2) <= pow(100, 2) && pow(randx - 450, 2) + pow(randy - 125, 2) >= pow(80, 2)) {
							globallock.lock();
							for (int i = 0; i < 15; i++) {
								BulletTrack tempbullet(randx, randy, 0, 8, 0, "slope", "RM", 1);
								PushBullet(tempbullet);
								BackBuffer->back().Summond(theta + i * 24);
							}
							globallock.unlock();
						}
						else {
							j--;
						}
					}
				}
			}
			//�׶�2
			if (Timer(300, 16)) {
				for (int j = 0; j < 1; j++) {
					//�жϴ˽׶��Ƿ����ⲿ�ֵ�Ļ
					if (boss->GetStage() <= 1) {
						unsigned int randx = rand() % MyWindow.getW();
						unsigned int randy = rand() % MyWindow.getH();
						if (j == 0 && (1 * MyWindow.getW() / 8 < randx && randx < 1 * MyWindow.getW() / 4 && 1 * MyWindow.getH() / 16 < randy && randy < 3 * MyWindow.getH() / 8)) {
							globallock.lock();
							for (int i = 0; i < 10; i++) {
								BulletTrack tempbullet(randx, randy, 0, 8, 0, "slope", "M", 1);
								PushBullet(tempbullet);
								BackBuffer->back().Summond(rand() % 360);
							}
							globallock.unlock();
						}
						else {
							j--;
						}
					}
				}
				for (int j = 0; j < 1; j++) {
					if (boss->GetStage() <= 1) {
						//�жϴ˽׶��Ƿ����ⲿ�ֵ�Ļ
						unsigned int randx = rand() % MyWindow.getW();
						unsigned int randy = rand() % MyWindow.getH();
						if (j == 0 && (1 * MyWindow.getW() / 4 < randx && randx < 7 * MyWindow.getW() / 8 && 1 * MyWindow.getH() / 16 < randy && randy < 3 * MyWindow.getH() / 8)) {
							globallock.lock();
							for (int i = 0; i < 10; i++) {
								BulletTrack tempbullet(randx, randy, 0, 8, 0, "slope", "M", 1);
								PushBullet(tempbullet);
								BackBuffer->back().Summond(rand() % 360);
							}
							globallock.unlock();
						}
						else {
							j--;
						}
					}
				}
			}
			//�׶�3
			if (Timer(800, 17)) {
				for (int j = 0; j < 1; j++) {
					if (boss->GetStage() <= 0) {
						//�жϴ˽׶��Ƿ����ⲿ�ֵ�Ļ
						unsigned int randx = rand() % MyWindow.getW();
						unsigned int randy = rand() % MyWindow.getH();
						double theta = 0;
						if (1 * MyWindow.getW() / 8 < randx && randx < 1 * MyWindow.getW() / 4 && 1 * MyWindow.getH() / 16 < randy && randy < 3 * MyWindow.getH() / 8) {
							globallock.lock();
							for (int i = 0; i < 72; i++) {
								BulletTrack tempbullet(randx, randy,0, 12, 0, "slope", "BB");
								PushBullet(tempbullet);
								BackBuffer->back().Summond(theta + i * 5);
							}
							globallock.unlock();
						}
						else {
							j--;
						}
					}
				}
				for (int j = 0; j < 1; j++) {
					if (boss->GetStage() <= 0) {
						//�жϴ˽׶��Ƿ����ⲿ�ֵ�Ļ
						unsigned int randx = rand() % MyWindow.getW();
						unsigned int randy = rand() % MyWindow.getH();
						double theta = 0;
						if (1 * MyWindow.getW() / 4 < randx && randx < 7 * MyWindow.getW() / 8 && 1 * MyWindow.getH() / 16 < randy && randy < 3 * MyWindow.getH() / 8) {
							globallock.lock();
							for (int i = 0; i < 72; i++) {
								BulletTrack tempbullet(randx, randy,0, 12, 0, "slope", "BB", 1.5);
								PushBullet(tempbullet);
								BackBuffer->back().Summond(theta + i * 5);
							}
							globallock.unlock();
						}
						else {
							j--;
						}
					}
				}
			}
			//����һ�׶Σ�bossѪ�����Զ�����
			if (Timer(40, 18)) {
				boss->HPDecline(10);
			}
		}
		globallock.lock();
		BackBuffer->clear();
		FrontBuffer->clear();
		globallock.unlock();
	}

	//����boss����������
	boss.reset(nullptr);
	Sleep(3000);
	soloud.stop(BossBgmHandle);
	
	Status = false;
}