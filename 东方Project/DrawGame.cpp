#pragma once
#include<easyx.h>
#include<graphics.h>
#include"body.h"
#include"bullettrack.h"
#include "Enemy.h"
#include"Loot.h"
#include"HitEffect.h"
//frame作为控制动画的帧数（设计上一秒60帧），roady控制road贴图的移动实现动态背景
int roady = -250;
int frame = 0;

int Timer(int duration, int id);


void drawgame() {
	while (Status) {
		if (Timer(10, 21)) {
			frame++;
			cleardevice();
			//控制road贴图移动并贴road的图
			if (roady > 0) {
				roady = -249;
			}
			roady += 5;
			putimage(0, roady, MyWindow.img[86]);
			globallock.lock();
			//为战利品贴图
			for (int i = 0; i < redloot.size(); i++) {
				putimage(int(redloot.at(i).GetX()) - 6, int(redloot.at(i).GetY()) - 6, MyWindow.img[49]);

			}
			for (int i = 0; i < blueloot.size(); i++) {
				putimage(int(blueloot.at(i).GetX()) - 6, int(blueloot.at(i).GetY()) - 6, MyWindow.img[48]);
			}
			globallock.unlock();

			globallock.lock();
			//根据角色为子弹贴图
			for (int i = 0; i < MyBullets.size(); i++) {
				if (character.GetName() == "rm") {
					putimage(int(MyBullets.at(i).GetX()) - 5, int(MyBullets.at(i).GetY()) - 5, MyWindow.img[22]);
				}
				if (character.GetName() == "mrs") {
					putimage(int(MyBullets.at(i).GetX()) - 5, int(MyBullets.at(i).GetY()) - 5, MyWindow.img[33]);
				}
			}
			globallock.unlock();
			//根据角色与帧数贴图达到动画效果
			if (character.GetName() == "rm") {
				switch (frame / 13) {
				case 0:
					if (character.GetWheInvincible() == 0) {
						putimage(character.GetX() - 15, character.GetY() - 21, MyWindow.img[15], SRCAND);
						putimage(character.GetX() - 15, character.GetY() - 21, MyWindow.img[14], SRCPAINT);
					}
					break;
				case 1:
					putimage(character.GetX() - 15, character.GetY() - 21, MyWindow.img[17], SRCAND);
					putimage(character.GetX() - 15, character.GetY() - 21, MyWindow.img[16], SRCPAINT);
					break;
				case 2:
					if (character.GetWheInvincible() == 0) {
						putimage(character.GetX() - 15, character.GetY() - 21, MyWindow.img[19], SRCAND);
						putimage(character.GetX() - 15, character.GetY() - 21, MyWindow.img[18], SRCPAINT);
					}
					break;
				case 3:
					putimage(character.GetX() - 15, character.GetY() - 21, MyWindow.img[21], SRCAND);
					putimage(character.GetX() - 15, character.GetY() - 21, MyWindow.img[20], SRCPAINT);
					break;
				}
				if (GetAsyncKeyState(VK_SHIFT)) {
					putimage(character.GetX() - 5, character.GetY() - 5, MyWindow.img[24], SRCAND);
					putimage(character.GetX() - 5, character.GetY() - 5, MyWindow.img[23], SRCPAINT);
				}
			}

			if (character.GetName() == "mrs") {
				switch (frame / 13) {
				case 0:
					if (character.GetWheInvincible() == 0) {
						putimage(character.GetX() - 15, character.GetY() - 21, MyWindow.img[26], SRCAND);
						putimage(character.GetX() - 15, character.GetY() - 21, MyWindow.img[25], SRCPAINT);
					}
					break;
				case 1:
					putimage(character.GetX() - 15, character.GetY() - 21, MyWindow.img[28], SRCAND);
					putimage(character.GetX() - 15, character.GetY() - 21, MyWindow.img[27], SRCPAINT);
					break;
				case 2:
					if (character.GetWheInvincible() == 0) {
						putimage(character.GetX() - 15, character.GetY() - 21, MyWindow.img[30], SRCAND);
						putimage(character.GetX() - 15, character.GetY() - 21, MyWindow.img[29], SRCPAINT);
					}
					break;
				case 3:
					putimage(character.GetX() - 15, character.GetY() - 21, MyWindow.img[32], SRCAND);
					putimage(character.GetX() - 15, character.GetY() - 21, MyWindow.img[31], SRCPAINT);
					break;
				}
				if (GetAsyncKeyState(VK_SHIFT)) {
					putimage(character.GetX() - 7, character.GetY() - 7, MyWindow.img[35], SRCAND);
					putimage(character.GetX() - 7, character.GetY() - 7, MyWindow.img[34], SRCPAINT);
				}
			}

			globallock.lock();
			//根据敌人类型为不同敌人贴图
			auto i4t = enemy.begin();
			while (i4t != enemy.end()) {
				if (i4t->GetName() == "Red") {
					putimage(i4t->GetX() - 15, i4t->GetY() - 15, MyWindow.img[43], SRCAND);
					putimage(i4t->GetX() - 15, i4t->GetY() - 15, MyWindow.img[42], SRCPAINT);
				}
				if (i4t->GetName() == "Green") {
					putimage(i4t->GetX() - 15, i4t->GetY() - 15, MyWindow.img[45], SRCAND);
					putimage(i4t->GetX() - 15, i4t->GetY() - 15, MyWindow.img[44], SRCPAINT);
				}
				if (i4t->GetName() == "Blue") {
					putimage(i4t->GetX() - 15, i4t->GetY() - 15, MyWindow.img[47], SRCAND);
					putimage(i4t->GetX() - 15, i4t->GetY() - 15, MyWindow.img[46], SRCPAINT);
				}
				++i4t;
			}
			//根据帧数为boss贴图实现动画效果
			if (boss != nullptr) {
				switch (frame / 13)
				{
				case 0:
					putimage(boss->GetX() - 50, boss->GetY() - 50, MyWindow.img[1], SRCAND);
					putimage(boss->GetX() - 50, boss->GetY() - 50, MyWindow.img[0], SRCPAINT);
					break;
				case 1:
					putimage(boss->GetX() - 50, boss->GetY() - 50, MyWindow.img[3], SRCAND);
					putimage(boss->GetX() - 50, boss->GetY() - 50, MyWindow.img[2], SRCPAINT);
					break;
				case 2:
					putimage(boss->GetX() - 50, boss->GetY() - 50, MyWindow.img[5], SRCAND);
					putimage(boss->GetX() - 50, boss->GetY() - 50, MyWindow.img[4], SRCPAINT);
					break;
				case 3:
					putimage(boss->GetX() - 50, boss->GetY() - 50, MyWindow.img[7], SRCAND);
					putimage(boss->GetX() - 50, boss->GetY() - 50, MyWindow.img[6], SRCPAINT);
					break;
				}
			}
			globallock.unlock();

			globallock.lock();
			//根据子弹类型贴图
			for (int i = 0; i < FrontBuffer->size(); i++) {
				if (FrontBuffer->at(i).GetName() == "Red") {
					putimage(int(FrontBuffer->at(i).GetX()) - 8, int(FrontBuffer->at(i).GetY()) - 8, MyWindow.img[37], SRCAND);
					putimage(int(FrontBuffer->at(i).GetX()) - 8, int(FrontBuffer->at(i).GetY()) - 8, MyWindow.img[36], SRCPAINT);
				}
				else if (FrontBuffer->at(i).GetName() == "Green") {
					putimage(int(FrontBuffer->at(i).GetX()) - 8, int(FrontBuffer->at(i).GetY()) - 8, MyWindow.img[39], SRCAND);
					putimage(int(FrontBuffer->at(i).GetX()) - 8, int(FrontBuffer->at(i).GetY()) - 8, MyWindow.img[38], SRCPAINT);
				}
				else if (FrontBuffer->at(i).GetName() == "Blue") {
					putimage(int(FrontBuffer->at(i).GetX()) - 8, int(FrontBuffer->at(i).GetY()) - 8, MyWindow.img[41], SRCAND);
					putimage(int(FrontBuffer->at(i).GetX()) - 8, int(FrontBuffer->at(i).GetY()) - 8, MyWindow.img[40], SRCPAINT);
				}
				else if (FrontBuffer->at(i).GetName() == "S") {
					putimage(int(FrontBuffer->at(i).GetX()) - 4, int(FrontBuffer->at(i).GetY()) - 4, MyWindow.img[13], SRCAND);
					putimage(int(FrontBuffer->at(i).GetX()) - 4, int(FrontBuffer->at(i).GetY()) - 4, MyWindow.img[12], SRCPAINT);
				}
				else if (FrontBuffer->at(i).GetName() == "M") {
					putimage(int(FrontBuffer->at(i).GetX()) - 8, int(FrontBuffer->at(i).GetY()) - 8, MyWindow.img[11], SRCAND);
					putimage(int(FrontBuffer->at(i).GetX()) - 8, int(FrontBuffer->at(i).GetY()) - 8, MyWindow.img[10], SRCPAINT);
				}
				else if (FrontBuffer->at(i).GetName() == "BS") {
					putimage(int(FrontBuffer->at(i).GetX()) - 4, int(FrontBuffer->at(i).GetY()) - 4, MyWindow.img[133], SRCAND);
					putimage(int(FrontBuffer->at(i).GetX()) - 4, int(FrontBuffer->at(i).GetY()) - 4, MyWindow.img[132], SRCPAINT);
				}
				else if (FrontBuffer->at(i).GetName() == "BM") {
					putimage(int(FrontBuffer->at(i).GetX()) - 8, int(FrontBuffer->at(i).GetY()) - 8, MyWindow.img[131], SRCAND);
					putimage(int(FrontBuffer->at(i).GetX()) - 8, int(FrontBuffer->at(i).GetY()) - 8, MyWindow.img[130], SRCPAINT);
				}
				else if (FrontBuffer->at(i).GetName() == "RS") {
					putimage(int(FrontBuffer->at(i).GetX()) - 4, int(FrontBuffer->at(i).GetY()) - 4, MyWindow.img[127], SRCAND);
					putimage(int(FrontBuffer->at(i).GetX()) - 4, int(FrontBuffer->at(i).GetY()) - 4, MyWindow.img[126], SRCPAINT);
				}
				else if (FrontBuffer->at(i).GetName() == "RM") {
					putimage(int(FrontBuffer->at(i).GetX()) - 8, int(FrontBuffer->at(i).GetY()) - 8, MyWindow.img[135], SRCAND);
					putimage(int(FrontBuffer->at(i).GetX()) - 8, int(FrontBuffer->at(i).GetY()) - 8, MyWindow.img[134], SRCPAINT);
				}
				else if (FrontBuffer->at(i).GetName() == "B") {
					putimage(int(FrontBuffer->at(i).GetX()) - 13, int(FrontBuffer->at(i).GetY()) - 13, MyWindow.img[9], SRCAND);
					putimage(int(FrontBuffer->at(i).GetX()) - 13, int(FrontBuffer->at(i).GetY()) - 13, MyWindow.img[8], SRCPAINT);
				}
				else if (FrontBuffer->at(i).GetName() == "RB") {
					putimage(int(FrontBuffer->at(i).GetX()) - 13, int(FrontBuffer->at(i).GetY()) - 13, MyWindow.img[137], SRCAND);
					putimage(int(FrontBuffer->at(i).GetX()) - 13, int(FrontBuffer->at(i).GetY()) - 13, MyWindow.img[136], SRCPAINT);
				}
				else if (FrontBuffer->at(i).GetName() == "GB") {
					putimage(int(FrontBuffer->at(i).GetX()) - 13, int(FrontBuffer->at(i).GetY()) - 13, MyWindow.img[139], SRCAND);
					putimage(int(FrontBuffer->at(i).GetX()) - 13, int(FrontBuffer->at(i).GetY()) - 13, MyWindow.img[138], SRCPAINT);
				}
				else if (FrontBuffer->at(i).GetName() == "BB") {
					putimage(int(FrontBuffer->at(i).GetX()) - 13, int(FrontBuffer->at(i).GetY()) - 13, MyWindow.img[141], SRCAND);
					putimage(int(FrontBuffer->at(i).GetX()) - 13, int(FrontBuffer->at(i).GetY()) - 13, MyWindow.img[140], SRCPAINT);
				}
			}
			//boss血条展示
			if (boss != nullptr) {
				setfillcolor(RED);
				solidrectangle(5, 5, boss->GetHP() * MyWindow.getW() / 26250, 10);
			}
			globallock.unlock();

			globallock.lock();
			//根据hiteffect剩余寿命贴敌人被击破的动画
			for (int i = 0; i < hiteffect.size(); i++) {
				switch (hiteffect[i].GetLifespan()) {
				case 12:
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[103], SRCAND);
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[102], SRCPAINT);
					break;
				case 11:
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[105], SRCAND);
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[104], SRCPAINT);
					break;
				case 10:
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[107], SRCAND);
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[106], SRCPAINT);
					break;
				case 9:
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[109], SRCAND);
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[108], SRCPAINT);
					break;
				case 8:
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[111], SRCAND);
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[110], SRCPAINT);
					break;
				case 7:
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[113], SRCAND);
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[112], SRCPAINT);
					break;
				case 6:
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[115], SRCAND);
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[114], SRCPAINT);
					break;
				case 5:
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[117], SRCAND);
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[116], SRCPAINT);
					break;
				case 4:
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[119], SRCAND);
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[118], SRCPAINT);
					break;
				case 3:
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[121], SRCAND);
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[120], SRCPAINT);
					break;
				case 2:
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[123], SRCAND);
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[122], SRCPAINT);
					break;
				case 1:
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[125], SRCAND);
					putimage(hiteffect[i].GetX() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), hiteffect[i].GetY() - 20 - 2.5 * (12 - hiteffect[i].GetLifespan()), MyWindow.img[124], SRCPAINT);
					break;

				}
			}
			globallock.unlock();
			//游戏内右侧UI贴图
			putimage(MyWindow.getW(), 0, MyWindow.img[85]);
			putimage(MyWindow.getW(), 250, MyWindow.img[90], SRCAND);
			putimage(MyWindow.getW(), 250, MyWindow.img[89], SRCPAINT);
			//根据剩余生命贴出红色星星
			for (int i = 0; i < character.GetHP(); i++) {
				putimage(MyWindow.getW() + 104 + 25 * i, 420, MyWindow.img[80], SRCAND);
				putimage(MyWindow.getW() + 104 + 25 * i, 420, MyWindow.img[79], SRCPAINT);
			}
			//根据等级贴出蓝色星星
			for (int i = 0; i < character.GetLevel(); i++) {
				putimage(MyWindow.getW() + 104 + 25 * i, 440, MyWindow.img[84], SRCAND);
				putimage(MyWindow.getW() + 104 + 25 * i, 440, MyWindow.img[83], SRCPAINT);
			}
			//分数显示
			TCHAR s[10];
			sprintf_s(s, _T("%d"), Score);
			outtextxy(MyWindow.getW() + 114, 400, s);
			//经验显示
			TCHAR s1[10];
			sprintf_s(s1, _T("%d"), character.GetExp());
			outtextxy(MyWindow.getW() + 114, 470, s1);
			//双缓冲绘图
			FlushBatchDraw();
			//重置帧数
			if (frame > 50) {
				frame = 0;
			}
		}
	}
}