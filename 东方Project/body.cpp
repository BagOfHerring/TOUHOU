#pragma once
#include"body.h"
#include<cmath>
#include<Windows.h>

using namespace std;
int Timer(int duration, int id);

void Body::HPDecline() {
	HP--;
}
void Body::HPIncrease() {
    HP++;
}
void Body::HPSet(int a) {
	HP = a;
}
void Body::ExpUp(int a)
{
	exp += a;
}
 int Body::GetExp() const
{
	return exp;
}
 int Body::GetHP() const{
	return HP;
}
 int Body::GetLevel() const{
	return level;
}
 int Body::GetWheInvincible() const{
	return whether_invincible;
}
void Body::SetWheInvincible() {
	whether_invincible = 100;
}
void Body::UpdateWheInvincible() {
	if (whether_invincible > 0)
	whether_invincible--;
}
void Body::LevelUp() {
    level++;
}
void Body::SumBullet() {
	if (Timer(150, 6)) {
		globallock.lock();
		BulletTrack tempbullet1(character.GetX(), character.GetY(), MyBullets.size(), 5, -1, "mine");
		MyBullets.push_back(tempbullet1);
		MyBullets[MyBullets.size() - 1].Summond();
		BulletTrack tempbullet2(character.GetX() + character.GetR() + 5, character.GetY(), MyBullets.size(), 5, -1, "mine");
		MyBullets.push_back(tempbullet2);
		MyBullets[MyBullets.size() - 1].Summond();
		BulletTrack tempbullet3(character.GetX() - character.GetR() - 5, character.GetY(), MyBullets.size(), 5, -1, "mine");
		MyBullets.push_back(tempbullet3);
		MyBullets[MyBullets.size() - 1].Summond();
		if (BulletStatus == HIGHSPEED) {
			if (level >= 3) {
				BulletTrack tempbullet4(character.GetX(), character.GetY(), MyBullets.size(), 5, -1, "mine_slope");
				MyBullets.push_back(tempbullet4);
				MyBullets[MyBullets.size() - 1].Summond(82.5);
				BulletTrack tempbullet5(character.GetX(), character.GetY(), MyBullets.size(), 5, -1, "mine_slope");
				MyBullets.push_back(tempbullet5);
				MyBullets[MyBullets.size() - 1].Summond(-82.5);
			}
			BulletTrack tempbullet6(character.GetX() + character.GetR() + 5, character.GetY(), MyBullets.size(), 5, -1, "mine_slope");
			MyBullets.push_back(tempbullet6);
			MyBullets[MyBullets.size() - 1].Summond(85);
			BulletTrack tempbullet7(character.GetX() - character.GetR() - 5, character.GetY(), MyBullets.size(), 5, -1, "mine_slope");
			MyBullets.push_back(tempbullet7);
			MyBullets[MyBullets.size() - 1].Summond(-85);
		}
		else if (BulletStatus == LOWSPEED) {
			if (level >= 3) {
				BulletTrack tempbullet4(character.GetX(), character.GetY(), MyBullets.size(), 5, -1, "mine");
				MyBullets.push_back(tempbullet4);
				MyBullets[MyBullets.size() - 1].Summond();
				BulletTrack tempbullet5(character.GetX(), character.GetY(), MyBullets.size(), 5, -1, "mine");
				MyBullets.push_back(tempbullet5);
				MyBullets[MyBullets.size() - 1].Summond();
			}
			BulletTrack tempbullet6(character.GetX() + character.GetR() + 5, character.GetY(), MyBullets.size(), 5, -1, "mine");
			MyBullets.push_back(tempbullet6);
			MyBullets[MyBullets.size() - 1].Summond();
			BulletTrack tempbullet7(character.GetX() - character.GetR() - 5, character.GetY(), MyBullets.size(), 5, -1, "mine");
			MyBullets.push_back(tempbullet7);
			MyBullets[MyBullets.size() - 1].Summond();
		}
		globallock.unlock();
	}
}
 int Body::GetAttack()const
{
	return level * attack;
}
void Body::ResetExp()
{
	exp = 0;
}
void Body::UpdateLevel() {
	switch (character.GetLevel())
	{
	case 0:
		if (character.GetExp() >= 200) {
			character.LevelUp();
			character.ResetExp();
		}
		break;
	case 1:
		if (character.GetExp() >= 200) {
			character.LevelUp();
			character.ResetExp();
		}
		break;
	case 2:
		if (character.GetExp() >= 200) {
			character.LevelUp();
			character.ResetExp();
		}
		break;
	case 3:
		if (character.GetExp() >= 200) {
			character.LevelUp();
			character.ResetExp();
		}
		break;
	case 4:
		if (character.GetExp() >= 200) {
			character.LevelUp();
			character.ResetExp();
		}
		break;
	default:
		break;
	}
}
 string Body::GetName()const {
	return name;
}
Body character(MyWindow.getW()/2,790,0,0,0,0," ");