#pragma once
#include "entity.h"
#include<vector>
using namespace std;
class HitEffect :public Entity {
public:
	int GetLifespan()const;
	void Update();
	HitEffect(double x, double y):Entity(x,y,0,0,0,0){}
private:
	int Lifespan=12;
};
extern vector<HitEffect> hiteffect;