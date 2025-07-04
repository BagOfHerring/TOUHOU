#pragma once
#include "Loot.h"
#include"body.h"
#include<cmath>

Loot::Loot(int a, int b, int id, int dx, int dy, int r, int exp, int score) :Entity(a, b, id, dx, dx, r), ExpBonus(exp), ScoreBonus(score) {}
//��ȡ���齱��
int Loot::GetExpBonus()const
{
	return ExpBonus;
}
//��ȡ��������
int Loot::GetScoreBonus()const
{
	return ScoreBonus;
}
//�������Ի������ж��Ƿ�����
void Loot::CheckMoveStyle() {
	if (MoveStyle == "Slope") {
		if (HitDetect(character, *this, 100) == 1) {
			MoveStyle = "Follow";
		}
	}
}
//����ս��Ʒλ��

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


