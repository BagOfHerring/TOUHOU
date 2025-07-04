#pragma once
#include"window.h"
#include<vector>
#include"bullettrack.h"
#include"entity.h"
class Body:public Entity {
private:
	int HP=5;
	int attack;
	int level = 1;
	int exp = 0;
	int whether_invincible = 0;
	string name;
	vector<BulletTrack> bullet;
public:
	static bool BulletHitDetect(Body body1, BulletTrack bullet);
	Body(double x, double y,double dx,double dy,double r,int attack,string name) :Entity(x,y,0,dx,dy,r),attack(attack),name(name){};
	Body(){}
    int GetHP()const;
	void HPDecline();
	void HPIncrease();
	void HPSet(int a);
	void ExpUp(int a);
	int GetExp() const;
	void LevelUp();
    int GetLevel() const;
    int GetWheInvincible() const;
	void SetWheInvincible();
	void UpdateWheInvincible();
	void SumBullet();
    int GetAttack()const;
	void ResetExp();
	void UpdateLevel();
 string GetName()const;
};

extern Body character;