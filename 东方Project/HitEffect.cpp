#include "HitEffect.h"
//获取寿命
int HitEffect::GetLifespan()const
{
	return Lifespan;
}
//更新寿命
void HitEffect::Update()
{

	Lifespan--;
}
vector<HitEffect> hiteffect;