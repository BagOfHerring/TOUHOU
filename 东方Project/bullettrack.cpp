#include "bullettrack.h"
#include "body.h"
#include "window.h"
#include "Enemy.h"
#include "entity.h"
#include <cmath>
#include <string>

int Timer(int duration, int id);
extern Window MyWindow;
extern Body character;
extern unique_ptr<Enemy> boss;

// 析构函数
BulletTrack::~BulletTrack() {}

void BulletTrack::UpdateBullet() {
    UpdateX(GetDx() * t);
    UpdateY(GetDy() * t);
}

void BulletTrack::Summond(double k, string type) {
	if (BulletType == "snipe") {
		if (type == "enemy") {
			if (character.GetX() == enemy[Enemyid].GetX()) {
				SetDx(0);
				SetDy(-(double(enemy[Enemyid].GetY()) - double(character.GetY())) / abs(double((enemy[Enemyid].GetY() - character.GetY()))));
			}
			else {
				double tan = -(double(enemy[Enemyid].GetY()) - double(character.GetY())) / abs(double((enemy[Enemyid].GetX() - character.GetX())));
				SetDy(tan / sqrt(tan * tan + 1));
				SetDx(-double((enemy[Enemyid].GetX() - character.GetX()) / abs(enemy[Enemyid].GetX() - character.GetX())) / sqrt(tan * tan + 1));
			}
		}
		else if (type == "boss") {
			if (character.GetX() == boss->GetX()) {
				SetDx(0);
				SetDy(-(double(boss->GetY()) - double(character.GetY())) / abs(double((boss->GetY() - character.GetY()))));
			}
			else {
				double tan = -(double(boss->GetY()) - double(character.GetY())) / abs(double((boss->GetX() - character.GetX())));
				SetDy(tan / sqrt(tan * tan + 1));
				SetDx(-double((boss->GetX() - character.GetX()) / abs(boss->GetX() - character.GetX())) / sqrt(tan * tan + 1));
			}
		}
	}
	else if (BulletType == "linear_lowspeed" || BulletType == "mine") {
		SetDx(0);
		SetDy(-MyWindow.GetLowSpeed_Bullet());
	}
	else if (BulletType == "mine_slope") {
		double a = tan(k * 3.14159 / 180);
		SetDy(-MyWindow.GetLowSpeed_Bullet());
		SetDx(-MyWindow.GetLowSpeed_Bullet() / a);
	}
	else if (BulletType == "slope") {
		double a = tan(k * 3.14159 / 180);
		if (0 < k && k < 90) {
			SetDy(-a * MyWindow.GetLowSpeed_Bullet() / sqrt(a * a + 1));
			SetDx(a * MyWindow.GetLowSpeed_Bullet() / (abs(a) * sqrt(a * a + 1)));
		}
		else if (90 < k && k < 180) {
			SetDy(a * MyWindow.GetLowSpeed_Bullet() / sqrt(a * a + 1));
			SetDx(a * MyWindow.GetLowSpeed_Bullet() / (abs(a) * sqrt(a * a + 1)));
		}
		else if (180 < k && k < 270) {
			SetDy(a * MyWindow.GetLowSpeed_Bullet() / sqrt(a * a + 1));
			SetDx(-a * MyWindow.GetLowSpeed_Bullet() / (abs(a) * sqrt(a * a + 1)));
		}
		else if (270 < k && k < 360) {
			SetDy(-a * MyWindow.GetLowSpeed_Bullet() / sqrt(a * a + 1));
			SetDx(-a * MyWindow.GetLowSpeed_Bullet() / (abs(a) * sqrt(a * a + 1)));
		}
		else if (k == 0 || k == 360) {
			SetDy(0);
			SetDx(MyWindow.GetLowSpeed_Bullet());
		}
		else if (k == 90) {
			SetDy(-MyWindow.GetLowSpeed_Bullet());
			SetDx(0);
		}
		else if (k == 180) {
			SetDy(0);
			SetDx(-MyWindow.GetLowSpeed_Bullet());
		}
		else if (k == 270) {
			SetDy(MyWindow.GetLowSpeed_Bullet());
			SetDx(0);
		}
	}
	else if (BulletType == "stop") {
		SetDx(0);
		SetDy(0);
	}
}

string BulletTrack::GetName() const {
    return BulletName;
}

// 双缓冲机制：将子弹写入 BackBuffer
#include "global.h"
void PushBullet(const BulletTrack& bullet) {
    BackBuffer->push_back(bullet);
}
