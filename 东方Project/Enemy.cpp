#pragma once
#include"enemy.h"

#include"window.h"
#include<Windows.h>
using namespace std;
int Enemy::GetHP() const{
	return HP;
}
void Enemy::HPDecline(int a) {
	HP -= a;
	if (HP <= 0 && BossStage > 0) {
		HP = MyWindow.GetBoss_HP();
		BossStage--;
		Sleep(10);
	}
}

string Enemy::GetName() const{
	return EnemyName;
}

int Enemy::GetStage()const {
	if (boss != nullptr) {
		return BossStage;
	}else{
		return NULL;
	}
}