#pragma once
#include <cmath>
#include <string>
#include <vector>
#include "global.h"
#include "entity.h"
using namespace std;

class BulletTrack : public Entity {
private:
    double t = 2;
    int Enemyid;
    string BulletType;
    string BulletName;
public:
    BulletTrack(double x, double y, int id, double r, int Enemyid, string BulletType, string BulletName = "NULL", double t = 2)
        : Entity(x, y, id, 0, 0, r), Enemyid(Enemyid), BulletType(BulletType), BulletName(BulletName), t(t) {
    }
    ~BulletTrack();
    void UpdateBullet();
    void Summond(double k = 0, string type = "enemy");
    string GetName() const;
};

// Ë«»º³å½Ó¿Ú
void PushBullet(const BulletTrack& bullet);

//Ë«»º³åÈÝÆ÷
extern vector<BulletTrack> MyBullets;
extern std::vector<BulletTrack> BulletBufferA;
extern std::vector<BulletTrack> BulletBufferB;
extern std::vector<BulletTrack>* FrontBuffer;
extern std::vector<BulletTrack>* BackBuffer;