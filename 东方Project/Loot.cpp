#pragma once
#include "Loot.h"
#include"body.h"
#include<cmath>

Loot::Loot(int a, int b, int id, int dx, int dy, int r, int exp, int score) :Entity(a, b, id, dx, dx, r), ExpBonus(exp), ScoreBonus(score) {}
//获取经验奖励
int Loot::GetExpBonus()const
{
	return ExpBonus;
}
//获取分数奖励
int Loot::GetScoreBonus()const
{
	return ScoreBonus;
}
//根据与自机距离判断是否被吸附
void Loot::CheckMoveStyle() {
	if (MoveStyle == "Slope") {
		if (HitDetect(character, *this, 100) == 1) {
			MoveStyle = "Follow";
		}
	}
}
//更新战利品位置

void Loot::UpdateLoot() {
	if (MoveStyle == "Slope") {
		UpdateY(1);
	}
	else if (MoveStyle == "Follow") {
		move_towards(character.GetX(), character.GetY(), 10, 2);
		this->UpdateX(this->GetDx());
		this->UpdateY(this->GetDy());
	}
}


