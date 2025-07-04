#pragma once

#include"entity.h"
#include <vector>
#include<string>
using namespace std;
class Loot :public Entity {
private:
	int ExpBonus;
	int ScoreBonus;
	string MoveStyle = "Slope";
public:
	Loot(int a, int b, int id, int dx, int dy, int r, int exp, int score);
	int GetExpBonus()const;
	int GetScoreBonus()const;
	void UpdateLoot();
	void CheckMoveStyle();
};
extern vector<Loot> blueloot;
extern vector<Loot> redloot;