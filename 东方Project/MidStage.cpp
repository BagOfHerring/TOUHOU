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
void MidStage() {
	//道中阶段
	//初始化并播放背景音乐
	MidBgmHandle = soloud.play(MyWindow.wav[1]);
	soloud.setLooping(MidBgmHandle, true);
	Sleep(2000);
	globallock.lock();
	//第一波敌人
	while (Status && enemy.size() == 0) {
		int i = 0;
		//绿
		Enemy tempenemy6(1, 80, i, 5, 5, 10, 30,"Green");
		enemy.push_back(tempenemy6);
		enemy[i].move_towards(1 * MyWindow.getW() / 4, 1 * MyWindow.getH() / 4, 3, 2);
		i++;
		Enemy tempenemy7(MyWindow.getW() - 1, 80, i, 5, 5, 10, 30, "Green");
		enemy.push_back(tempenemy7);
		enemy[i].move_towards(3 * MyWindow.getW() / 4, 1 * MyWindow.getH() / 4, 3, 2);
		i++;
		if (Mode == HARD) {
			Enemy tempenemy8(MyWindow.getW() / 2, 0, i, 5, 5, 10, 30, "Green");
			enemy.push_back(tempenemy8);
			enemy[i].move_towards(1 * MyWindow.getW() / 2, 65, 2, 2);
			i++;
		}

	}
	globallock.unlock();

	while (Status && enemy.size() != 0) {
		//随机弹
		for (int j = 0; j < 4; j++) {
			globallock.lock();
			for (auto i2t = enemy.begin(); i2t != enemy.end(); ++i2t) {
				if (i2t->GetName() == "Green" && i2t->whether_arrived()) {
					for (int k = 0; k < 9; k++) {
						BulletTrack tempbullet(i2t->GetX(), i2t->GetY(), 0, 10, 0, "slope", i2t->GetName(), 0.5);
						PushBullet(tempbullet);
						BackBuffer->back().Summond(rand() % 360);
					}
				}
			}
			globallock.unlock();
			Sleep(100);
		}
		Sleep(2000);
	}

	//第2波敌人
	globallock.lock();
	while (Status && enemy.size() == 0) {
		int i = 0;
		//红
		Enemy tempenemy1(MyWindow.getW() / 8, 0, i, 5, 5, 10, 150, "Red");
		enemy.push_back(tempenemy1);
		enemy[i].move_towards(5 * MyWindow.getW() / 8, MyWindow.getH() / 16, 5, 2);
		i++;
		Enemy tempenemy2(MyWindow.getW() / 2, 0, i, 5, 5, 10, 150, "Red");
		enemy.push_back(tempenemy2);
		enemy[i].move_towards(MyWindow.getW() / 2, MyWindow.getH() / 8, 5, 2);
		i++;
		Enemy tempenemy3(7 * MyWindow.getW() / 8, 0, i, 5, 5, 10, 150, "Red");
		enemy.push_back(tempenemy3);
		enemy[i].move_towards(3 * MyWindow.getW() / 8, MyWindow.getH() / 16, 5, 2);
		i++;
		if (Mode == HARD) {
			Enemy tempenemy4(3 * MyWindow.getW() / 8, 0, i, 5, 5, 10, 150, "Red");
			enemy.push_back(tempenemy4);
			enemy[i].move_towards(3 * MyWindow.getW() / 4, MyWindow.getH() / 8, 5, 2);
			i++;
			Enemy tempenemy5(5 * MyWindow.getW() / 8, 0, i, 5, 5, 10, 150, "Red");
			enemy.push_back(tempenemy5);
			enemy[i].move_towards(1 * MyWindow.getW() / 4, MyWindow.getH() / 8, 5, 2);
			i++;
		}

	}
	globallock.unlock();

	while (Status && enemy.size() != 0) {
		for (int j = 0; j < 5; j++) {
			globallock.lock();
			//自机狙
			int i = 0;
			for (auto it = enemy.begin(); it != enemy.end(); ++it) {
				if (it->GetName() == "Red" && it->whether_arrived()) {
					BulletTrack tempbullet(it->GetX(), it->GetY(), 0, 8, i, "snipe", it->GetName(), 5);
					PushBullet(tempbullet);
					BackBuffer->back().Summond();
				}
				i++;
			}
			globallock.unlock();
			Sleep(200);
		}
		if (Mode == EASY) {
			Sleep(2000);
		}
		else if (Mode == HARD) {
			Sleep(1000);
		}
	}

	//第3波敌人
	globallock.lock();
	while (Status && enemy.size() == 0) {
		int i = 0;

		//蓝
		Enemy tempenemy1(1, 40, i, 5, 5, 10, 270, "Blue");
		enemy.push_back(tempenemy1);
		enemy[i].move_towards(1 * MyWindow.getW() / 16, MyWindow.getH() / 8, 5, 2);
		i++;
		Enemy tempenemy2(MyWindow.getW() - 1, 40, i, 5, 5, 10, 270, "Blue");
		enemy.push_back(tempenemy2);
		enemy[i].move_towards(15 * MyWindow.getW() / 16, MyWindow.getH() / 8, 5, 2);
		i++;
		if (Mode == HARD) {
			Enemy tempenemy8(3, 50, i, 5, 5, 10, 270, "Blue");
			enemy.push_back(tempenemy8);
			enemy[i].move_towards(1 * MyWindow.getW() / 8, 1 * MyWindow.getH() / 4, 5, 2);
			i++;
			Enemy tempenemy9(MyWindow.getW() - 3, 50, i, 5, 5, 10, 270, "Blue");
			enemy.push_back(tempenemy9);
			enemy[i].move_towards(7 * MyWindow.getW() / 8, 1 * MyWindow.getH() / 4, 5, 2);
			i++;
		}


	}
	globallock.unlock();
	while (Status && enemy.size() != 0) {
		//复数链弹
		for (int j = 0; j < 10; j++) {//链弹数量
			if (Timer(30, 9)) {
				globallock.lock();

				for (auto i3t = enemy.begin(); i3t != enemy.end(); ++i3t) {//对每个敌人
					double theta = 300;
					for (int k = 0; k < 5; k++) {//链弹排数
						if (i3t->GetName() == "Blue" && i3t->GetID() == 0) {
							BulletTrack tempbullet(i3t->GetX(), i3t->GetY(), 0, 8, 0, "slope", i3t->GetName());

							PushBullet(tempbullet);
							BackBuffer->back().Summond(theta + k * 3);

						}
						else if (i3t->GetName() == "Blue" && i3t->GetID() == 1) {
							BulletTrack tempbullet(i3t->GetX(), i3t->GetY(), 0, 8, 0, "slope", i3t->GetName());

							PushBullet(tempbullet);
							BackBuffer->back().Summond(theta - k * 3 - 60);

						}
						else if (i3t->GetName() == "Blue" && i3t->GetID() == 2) {
							BulletTrack tempbullet(i3t->GetX(), i3t->GetY(), 0, 8, 0, "slope", i3t->GetName());

							PushBullet(tempbullet);
							BackBuffer->back().Summond(theta + k * 5);

						}
						else if (i3t->GetName() == "Blue" && i3t->GetID() == 3) {
							BulletTrack tempbullet(i3t->GetX(), i3t->GetY(),0, 8, 0, "slope", i3t->GetName());

							PushBullet(tempbullet);
							BackBuffer->back().Summond(theta - k * 5 - 60);

						}
					}
				}
				globallock.unlock();
			}
			else {
				j--;
			}
		}
		Sleep(2000);
	}


	//第4波敌人

	globallock.lock();
	while (Status && enemy.size() == 0) {
		int i = 0;
		//红
		Enemy tempenemy1(MyWindow.getW() / 8, 0, i, 5, 5, 10, 390, "Red");
		enemy.push_back(tempenemy1);
		enemy[i].move_towards(5 * MyWindow.getW() / 8, MyWindow.getH() / 8, 5, 2);
		i++;
		Enemy tempenemy2(MyWindow.getW() / 2, 0, i, 5, 5, 10, 390, "Red");
		enemy.push_back(tempenemy2);
		enemy[i].move_towards(MyWindow.getW() / 2, MyWindow.getH() / 8, 5, 2);
		i++;
		Enemy tempenemy3(7 * MyWindow.getW() / 8, 0, i, 5, 5, 10, 390, "Red");
		enemy.push_back(tempenemy3);
		enemy[i].move_towards(3 * MyWindow.getW() / 8, MyWindow.getH() / 8, 5, 2);
		i++;
		if (Mode == HARD) {
			Enemy tempenemy4(3 * MyWindow.getW() / 8, 0, i, 5, 5, 10, 390, "Red");
			enemy.push_back(tempenemy4);
			enemy[i].move_towards(3 * MyWindow.getW() / 4, MyWindow.getH() / 8, 5, 2);
			i++;
			Enemy tempenemy5(5 * MyWindow.getW() / 8, 0, i, 5, 5, 10, 390, "Red");
			enemy.push_back(tempenemy5);
			enemy[i].move_towards(1 * MyWindow.getW() / 4, MyWindow.getH() / 8, 5, 2);
			i++;
		}
		//绿
		Enemy tempenemy6(1 * MyWindow.getW() / 8, 80, i, 5, 5, 10, 390, "Green");
		enemy.push_back(tempenemy6);
		enemy[i].move_towards(1 * MyWindow.getW() / 8, 1 * MyWindow.getH() + 10, 3, 2);
		i++;
		Enemy tempenemy7(7 * MyWindow.getW() / 8, 80, i, 5, 5, 10, 390, "Green");
		enemy.push_back(tempenemy7);
		enemy[i].move_towards(7 * MyWindow.getW() / 8, 1 * MyWindow.getH() + 10, 3, 2);
		i++;
		if (Mode == HARD) {
			Enemy tempenemy8(MyWindow.getW() / 2, 80, i, 5, 5, 10, 390, "Green");
			enemy.push_back(tempenemy8);
			enemy[i].move_towards(1 * MyWindow.getW() / 2, 1 * MyWindow.getH() / 2, 3, 2);
			i++;
		}

	}
	globallock.unlock();

	//第4波子弹

	while (Status && enemy.size() != 0) {
		for (int j = 0; j < 5; j++) {
			globallock.lock();
			int i = 0;
			//自机狙
			for (auto it = enemy.begin(); it != enemy.end(); ++it) {
				if (it->GetName() == "Red" && it->whether_arrived()) {
					BulletTrack tempbullet(it->GetX(), it->GetY(), 0, 8, i, "snipe", it->GetName(), 5);
					PushBullet(tempbullet);
					BackBuffer->back().Summond();
				}
				i++;
			}
			//随机弹
			if (j <= 3) {
				for (auto i2t = enemy.begin(); i2t != enemy.end(); ++i2t) {
					if (i2t->GetName() == "Green") {
						for (int k = 0; k < 9; k++) {
							BulletTrack tempbullet(i2t->GetX(), i2t->GetY(), 0(), 10, 0, "slope", i2t->GetName(), 0.5);
							PushBullet(tempbullet);
							BackBuffer->back().Summond(rand() % 360);
						}
					}
				}
			}
			globallock.unlock();
			Sleep(200);
		}
		if (Mode == EASY) {
			Sleep(2000);
		}
		else {
			Sleep(1500);
		}
	}

	//第5波敌人
	globallock.lock();
	while (Status && enemy.size() == 0) {
		int i = 0;

		//蓝
		Enemy tempenemy1(1, 40, i, 5, 5, 10, 410, "Blue");
		enemy.push_back(tempenemy1);
		enemy[i].move_towards(1 * MyWindow.getW() / 16, MyWindow.getH() / 8, 5, 2);
		i++;
		Enemy tempenemy2(MyWindow.getW() - 1, 40, i, 5, 5, 10, 410, "Blue");
		enemy.push_back(tempenemy2);
		enemy[i].move_towards(15 * MyWindow.getW() / 16, MyWindow.getH() / 8, 5, 2);
		i++;
		//绿
		Enemy tempenemy6(1, 80, i, 5, 5, 10, 410, "Green");
		enemy.push_back(tempenemy6);
		enemy[i].move_towards(3 * MyWindow.getW() / 4, 1 * MyWindow.getH() / 4, 5, 2);
		i++;
		Enemy tempenemy7(MyWindow.getW() - 1, 80, i, 5, 5, 10, 410, "Green");
		enemy.push_back(tempenemy7);
		enemy[i].move_towards(1 * MyWindow.getW() / 4, 1 * MyWindow.getH() / 4, 5, 2);
		i++;
		if (Mode == HARD) {
			Enemy tempenemy8(3, 80, i, 5, 5, 10, 410, "Green");
			enemy.push_back(tempenemy8);
			enemy[i].move_towards(1 * MyWindow.getW() / 2, 1 * MyWindow.getH() / 4, 5, 2);
			i++;
		}


	}
	globallock.unlock();

	//第5波子弹
	while (Status && enemy.size() != 0) {
		//复数链弹
		if (Timer(2000, 10)) {
			for (int j = 0; j < 10; j++) {//链弹数量
				if (Timer(30, 9)) {
					globallock.lock();
					for (auto i3t = enemy.begin(); i3t != enemy.end(); ++i3t) {//对每个敌人
						double theta = 300;
						for (int k = 0; k < 5; k++) {//链弹排数
							if (i3t->GetName() == "Blue" && i3t->GetID() == 0) {
								BulletTrack tempbullet(i3t->GetX(), i3t->GetY(), 0(), 8, 0, "slope", i3t->GetName());
								PushBullet(tempbullet);
								BackBuffer->back().Summond(theta + k * 3);

							}
							else if (i3t->GetName() == "Blue" && i3t->GetID() == 1) {
								BulletTrack tempbullet1(i3t->GetX(), i3t->GetY(), 0(), 8, 0, "slope", i3t->GetName());
								PushBullet(tempbullet1);
								BackBuffer->back().Summond(theta - k * 3 - 60);
							}
						}

					}
					globallock.unlock();
				}
				else {
					j--;
				}
			}

		}

		//随机弹
		if (Timer(1000, 11)) {
			globallock.lock();
			for (int j = 0; j < 2; j++) {
				for (auto i2t = enemy.begin(); i2t != enemy.end(); ++i2t) {
					if (i2t->GetName() == "Green") {
						for (int k = 0; k < 9; k++) {
							BulletTrack tempbullet(i2t->GetX(), i2t->GetY(), 0(), 10, 0, "slope", i2t->GetName(), 0.5);
							PushBullet(tempbullet);
							BackBuffer->back().Summond(rand() % 360);
						}
					}

				}
			}
			globallock.unlock();
		}
	}

	//第6波敌人
	globallock.lock();
	while (Status && enemy.size() == 0) {
		int i = 0;
		//红
		Enemy tempenemy1(MyWindow.getW() / 8, 0, i, 5, 5, 10, 530, "Red");
		enemy.push_back(tempenemy1);
		enemy[i].move_towards(5 * MyWindow.getW() / 8, 3 * MyWindow.getH() / 8, 5, 2);
		i++;
		Enemy tempenemy2(MyWindow.getW() / 2, 0, i, 5, 5, 10, 530, "Red");
		enemy.push_back(tempenemy2);
		enemy[i].move_towards(MyWindow.getW() / 2, MyWindow.getH() / 4, 5, 2);
		i++;
		Enemy tempenemy3(7 * MyWindow.getW() / 8, 0, i, 5, 5, 10, 530, "Red");
		enemy.push_back(tempenemy3);
		enemy[i].move_towards(3 * MyWindow.getW() / 8, 3 * MyWindow.getH() / 8, 5, 2);
		i++;
		if (Mode == HARD) {
			Enemy tempenemy4(3 * MyWindow.getW() / 8, 0, i, 5, 5, 10, 530, "Red");
			enemy.push_back(tempenemy4);
			enemy[i].move_towards(3 * MyWindow.getW() / 4, MyWindow.getH() / 4, 5, 2);
			i++;
			Enemy tempenemy5(5 * MyWindow.getW() / 8, 0, i, 5, 5, 10, 530, "Red");
			enemy.push_back(tempenemy5);
			enemy[i].move_towards(1 * MyWindow.getW() / 4, MyWindow.getH() / 4, 5, 2);
			i++;
		}
		//蓝
		Enemy tempenemy6(1, 40, i, 5, 5, 10, 530, "Blue");
		enemy.push_back(tempenemy6);
		enemy[i].move_towards(1 * MyWindow.getW() / 16, MyWindow.getH() / 8, 5, 2);
		i++;
		Enemy tempenemy7(MyWindow.getW() - 1, 40, i, 5, 5, 10, 530, "Blue");
		enemy.push_back(tempenemy7);
		enemy[i].move_towards(15 * MyWindow.getW() / 16, MyWindow.getH() / 8, 5, 2);
		i++;
		if (Mode == HARD) {
			Enemy tempenemy8(MyWindow.getW() / 2, 1, i, 5, 5, 10, 530, "Blue");
			enemy.push_back(tempenemy8);
			enemy[i].move_towards(1 * MyWindow.getW() / 2, MyWindow.getH() / 16, 5, 2);
			i++;
		}

	}
	globallock.unlock();
	//第6波子弹
	while (Status && enemy.size() != 0) {
		if (Timer(1500, 14)) {
			for (int j = 0; j < 5; j++) {
				globallock.lock();
				//自机狙
				int i = 0;
				for (auto it = enemy.begin(); it != enemy.end(); ++it) {
					if (it->GetName() == "Red" && it->whether_arrived()) {
						BulletTrack tempbullet(it->GetX(), it->GetY(), 0(), 8, i, "snipe", it->GetName(), 5);
						PushBullet(tempbullet);
						BackBuffer->back().Summond();
					}
					i++;
				}
				globallock.unlock();
				Sleep(200);
			}
		}
		//复数链弹
		if (Timer(2000, 10)) {
			for (int j = 0; j < 10; j++) {//链弹数量
				if (Timer(30, 9)) {
					globallock.lock();
					for (auto i3t = enemy.begin(); i3t != enemy.end(); ++i3t) {//对每个敌人
						double theta = 300;
						for (int k = 0; k < 5; k++) {//链弹排数
							if (i3t->GetName() == "Blue" && i3t->GetID() == (Mode == HARD ? 5 : 3)) {
								BulletTrack tempbullet(i3t->GetX(), i3t->GetY(), 0(), 8, 0, "slope", i3t->GetName());
								PushBullet(tempbullet);
								BackBuffer->back().Summond(theta + k * 3);
							}
							else if (i3t->GetName() == "Blue" && i3t->GetID() == (Mode == HARD ? 6 : 4)) {
								BulletTrack tempbullet(i3t->GetX(), i3t->GetY(), 0(), 8, 0, "slope", i3t->GetName());
								PushBullet(tempbullet);
								BackBuffer->back().Summond(theta - k * 3 - 60);
							}
							else if (i3t->GetName() == "Blue" && i3t->GetID() == 7) {
								BulletTrack tempbullet(i3t->GetX(), i3t->GetY(), 0(), 8, 0, "slope", i3t->GetName());
								PushBullet(tempbullet);
								BackBuffer->back().Summond(276 - k * 3);

							}
						}

					}
					globallock.unlock();
				}
				else {
					j--;
				}
			}
		}
	}
	int test = MyWindow.getH();
	//第七波敌人
	globallock.lock();
	while (Status && enemy.size() == 0) {
		int i = 0;
		//红
		Enemy tempenemy1(5, 5 * MyWindow.getH() / 8, i, 5, 5, 10, 750, "Red");
		enemy.push_back(tempenemy1);
		enemy[i].move_towards(3 * MyWindow.getW() / 8, 7 * MyWindow.getH() / 16, 3, 2);
		i++;
		Enemy tempenemy2(MyWindow.getW() - 5, 5 * MyWindow.getH() / 8, i, 5, 5, 10, 750, "Red");
		enemy.push_back(tempenemy2);
		enemy[i].move_towards(5 * MyWindow.getW() / 8, 7 * MyWindow.getH() / 16, 3, 2);
		i++;
		if (Mode == HARD) {
			Enemy tempenemy4(1, 7 * MyWindow.getH() / 16, i, 5, 5, 10, 750, "Red");
			enemy.push_back(tempenemy4);
			enemy[i].move_towards(1 * MyWindow.getW() / 8, MyWindow.getH() / 2, 3, 2);
			i++;
			Enemy tempenemy5(MyWindow.getW() - 1, 7 * MyWindow.getH() / 16, i, 5, 5, 10, 750, "Red");
			enemy.push_back(tempenemy5);
			enemy[i].move_towards(7 * MyWindow.getW() / 8, MyWindow.getH() / 2, 3, 2);
			i++;
		}
		//蓝
		Enemy tempenemy6(5, 40, i, 5, 5, 10, 750, "Blue");
		enemy.push_back(tempenemy6);
		enemy[i].move_towards(1 * MyWindow.getW() / 16, MyWindow.getH() / 8, 5, 2);
		i++;
		Enemy tempenemy7(MyWindow.getW() - 5, 40, i, 5, 5, 10, 750, "Blue");
		enemy.push_back(tempenemy7);
		enemy[i].move_towards(15 * MyWindow.getW() / 16, MyWindow.getH() / 8, 5, 2);
		i++;
		//绿
		Enemy tempenemy8(5, 1 * MyWindow.getH() / 4, i, 5, 5, 10, 750, "Green");
		enemy.push_back(tempenemy8);
		enemy[i].move_towards(MyWindow.getW() + 10, 3 * MyWindow.getH() / 8, 1, 2);
		i++;
		Enemy tempenemy9(MyWindow.getW() - 5, 1 * MyWindow.getH() / 4, i, 5, 5, 10, 750, "Green");
		enemy.push_back(tempenemy9);
		enemy[i].move_towards(-10, 3 * MyWindow.getH() / 8, 1, 2);
		i++;
		if (Mode == HARD) {
			Enemy tempenemy10(MyWindow.getW() / 2, 1, i, 5, 5, 10, 750, "Green");
			enemy.push_back(tempenemy10);
			enemy[i].move_towards(MyWindow.getW() / 2, 3 * MyWindow.getH() / 8, 1, 2);
			i++;
		}
	}
	//第七波子弹
	globallock.unlock();
	while (Status && enemy.size() != 0) {
		//复数链弹
		if (Timer(2000, 10)) {
			for (int j = 0; j < 10; j++) {//链弹数量
				if (Timer(30, 9)) {
					globallock.lock();
					for (auto i3t = enemy.begin(); i3t != enemy.end(); ++i3t) {//对每个敌人
						double theta = 300;
						for (int k = 0; k < 5; k++) {//链弹排数
							if (i3t->GetName() == "Blue" && i3t->GetID() == (Mode == HARD ? 4 : 2)) {
								BulletTrack tempbullet(i3t->GetX(), i3t->GetY(), 0(), 8, 0, "slope", i3t->GetName());
								PushBullet(tempbullet);
								BackBuffer->back().Summond(theta + k * 3);
							}
							else if (i3t->GetName() == "Blue" && i3t->GetID() == (Mode == HARD ? 5 : 3)) {
								BulletTrack tempbullet(i3t->GetX(), i3t->GetY(), 0(), 8, 0, "slope", i3t->GetName());
								PushBullet(tempbullet);
								BackBuffer->back().Summond(theta - k * 3 - 60);
							}
						}

					}
					globallock.unlock();
				}
				else {
					j--;
				}
			}
		}
		for (int j = 0; j < 5; j++) {
			if (Timer(200, 13)) {
				globallock.lock();
				//自机狙
				for (int j = 0; j < 5; j++) {
					int i = 0;
					for (auto it = enemy.begin(); it != enemy.end(); ++it) {
						if (it->GetName() == "Red") {
							BulletTrack tempbullet(it->GetX(), it->GetY(), 0(), 8, i, "snipe", it->GetName(), 5);
							PushBullet(tempbullet);
							BackBuffer->back().Summond();
						}
						i++;
					}
				}
				globallock.unlock();
			}
			else {
				j--;
			}
		}
		//随机弹
		if (Timer(1000, 11)) {
			globallock.lock();
			for (int j = 0; j < 2; j++) {
				for (auto i2t = enemy.begin(); i2t != enemy.end(); ++i2t) {
					if (i2t->GetName() == "Green") {
						for (int k = 0; k < 9; k++) {
							BulletTrack tempbullet(i2t->GetX(), i2t->GetY(), 0(), 10, 0, "slope", i2t->GetName(), 0.5);
							PushBullet(tempbullet);
							BackBuffer->back().Summond(rand() % 360);
						}
					}

				}
			}
			globallock.unlock();
		}
		Sleep(2000);

	}
	while (Status && enemy.size() != 0) {
		Sleep(20);
	}

	//结束播放音乐
	soloud.stop(MidBgmHandle);
}