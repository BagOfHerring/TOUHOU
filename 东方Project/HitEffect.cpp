#include "HitEffect.h"
//��ȡ����
int HitEffect::GetLifespan()const
{
	return Lifespan;
}
//��������
void HitEffect::Update()
{

	Lifespan--;
}
vector<HitEffect> hiteffect;