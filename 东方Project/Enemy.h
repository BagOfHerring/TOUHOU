#pragma once
#include"bullettrack.h"
#include<vector>
#include<memory>
using namespace std;
class Enemy:public Entity {
private:
	int HP;
	int BossStage;
	string EnemyName;
public:
	Enemy(double x, double y, int id,double dx, double dy ,int r, int HP,string EnemyName = "Null",int stage = -1) :Entity(x, y, id, dx, dy, r), HP(HP), EnemyName(EnemyName),BossStage(stage) {};
	Enemy() {};
	int GetHP()const;
	void HPDecline(int x);
	string GetName()const;
	int GetStage()const;
};

extern vector<Enemy> enemy;
extern unique_ptr<Enemy> boss;