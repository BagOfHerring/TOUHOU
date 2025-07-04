#pragma once
#include"body.h"
#include"window.h"
#include<easyx.h>
#include"bullettrack.h"
#include"enemy.h"
#include"global.h"
#include "Loot.h"
#include<iostream>
#include"HitEffect.h"


using namespace std;
void KeyDown();
void drawgame();
int Timer(int duration, int id);
extern Body character;


//每帧的游戏状态更新
void UpdateGame() {
    while (Status) {

        KeyDown();
        globallock.lock();

        // 遍历前缓冲所有子弹，更新子弹状态和处理碰撞
        auto& bullets = *FrontBuffer;

        for (auto& bullet : bullets) {
            bullet.UpdateBullet();

            // 这里检测子弹是否越界或死亡，如果存活，写入后缓冲
            if (bullet.GetX() >= 0 && bullet.GetX() <= MyWindow.getW() &&
                bullet.GetY() >= 0 && bullet.GetY() <= MyWindow.getH()) {

               
                if (!character.HitDetect(character, bullet)) {
                    BackBuffer->push_back(bullet);
                }
                else {
                    // 处理碰撞后效果
                    if (character.GetWheInvincible() == 0) {
                        character.HPDecline();
                        soloud.play(MyWindow.wav[4]);
                        character.SetWheInvincible();
                    }
                }
            }
        }

    
       character.UpdateWheInvincible();
        //更新boss
        if (boss != nullptr) {
            if (boss->GetHP() <= 0) {
                HitEffect temphiteffect(boss->GetX(), boss->GetY());
                hiteffect.push_back(temphiteffect);
                soloud.play(MyWindow.wav[10]);
                boss.reset(nullptr);
            }
        }

     
            //更新我方子弹
             auto it = MyBullets.begin();
            while (it != MyBullets.end()) {
                it->UpdateBullet();
                if (it->GetX() > MyWindow.getW() || it->GetX() < 0 || it->GetY() > MyWindow.getH() || it->GetY() < 0) {
                    it = MyBullets.erase(it);
                }
                else {
                    ++it;
                }
            }

            //敌人移动
            auto i8t = enemy.begin();
            while (i8t != enemy.end()) {
                i8t->move_thread();
                ++i8t;
            }

            //boss移动
            if (boss != nullptr) {
                boss->move_thread();
            }

            //清除出界敌人
            auto i7t = enemy.begin();
            while (i7t != enemy.end()) {
                if (i7t->GetX() > MyWindow.getW() || i7t->GetX() < 0 || i7t->GetY() > MyWindow.getH() || i7t->GetY() < 0) {
                    i7t = enemy.erase(i7t);
                }
                else {
                    ++i7t;
                }
            }

            //我方子弹与敌人碰撞
            auto i6t = MyBullets.begin();
            while (i6t != MyBullets.end()) {
                bool bulletHit = false;
                auto i5t = enemy.begin();
                while (i5t != enemy.end()) {
                    if (i5t->HitDetect(*i5t, *i6t)) {
                        i5t->HPDecline(character.GetAttack());
                        bulletHit = true;
                        break; // 子弹击中一个敌人后就不再检测其他敌人
                    }
                    ++i5t;
                }
                if (bulletHit) {
                    i6t = MyBullets.erase(i6t);
                    Score++;
                }
                else {
                    ++i6t;
                }
            }

            //我方子弹与boss碰撞
            if (boss != nullptr) {
                it = MyBullets.begin();
                while (it != MyBullets.end()) {
                    if (boss->HitDetect(*boss, *it)) {
                        boss->HPDecline(character.GetAttack());
                        it = MyBullets.erase(it);
                        Score++;

                    }
                    else {
                        ++it;
                    }
                }
            }

            //更新掉落物
            auto i3t = redloot.begin();
            while (i3t != redloot.end()) {
                i3t->CheckMoveStyle();
                ++i3t;
            }
            i3t = redloot.begin();
            while (i3t != redloot.end()) {
                i3t->UpdateLoot();
                if (i3t->GetX() > MyWindow.getW() || i3t->GetX() < 0 || i3t->GetY() > MyWindow.getH()) {
                    i3t = redloot.erase(i3t);
                }
                else {
                    ++i3t;
                }
            }

            i3t = blueloot.begin();
            while (i3t != blueloot.end()) {
                i3t->CheckMoveStyle();
                ++i3t;
            }
            i3t = blueloot.begin();
            while (i3t != blueloot.end()) {
                i3t->UpdateLoot();
                if (i3t->GetX() > MyWindow.getW() || i3t->GetX() < 0 || i3t->GetY() > MyWindow.getH()) {
                    i3t = blueloot.erase(i3t);
                }
                else {
                    ++i3t;
                }
            }

            //人物与掉落物碰撞
            i3t = redloot.begin();
            while (i3t != redloot.end()) {
                if (character.HitDetect(character, *i3t)) {
                    character.ExpUp(i3t->GetExpBonus());
                    Score += i3t->GetScoreBonus();
                    i3t = redloot.erase(i3t);
                    soloud.play(MyWindow.wav[5]);
                }
                else {
                    ++i3t;
                }
            }
            i3t = blueloot.begin();
            while (i3t != blueloot.end()) {
                if (character.HitDetect(character, *i3t)) {
                    character.ExpUp(i3t->GetExpBonus());
                    Score += i3t->GetScoreBonus();
                    i3t = blueloot.erase(i3t);
                    soloud.play(MyWindow.wav[5]);
                }
                else {
                    ++i3t;
                }
            }
            //击杀敌人
            auto iit = enemy.begin();
            while (iit != enemy.end()) {

                if (iit->GetHP() <= 0) {
                    int tempredLootNum = rand() % enemy_maxdrop;
                    for (int i = 0; i < tempredLootNum; i++) {
                        Loot tempRedLoot(int(iit->GetX() - 50 + rand() % LootSumRange), int(iit->GetY() - 50 + rand() % LootSumRange), 0, 0, 0, 10, 20, 10);
                        redloot.push_back(tempRedLoot);
                    }
                    for (int i = 0; i < enemy_maxdrop - tempredLootNum; i++) {
                        Loot tempBlueLoot(int(iit->GetX() - 50 + rand() % LootSumRange), int(iit->GetY() - 50 + rand() % LootSumRange), 0, 0, 0, 10, 0, 50);
                        blueloot.push_back(tempBlueLoot);
                    }
                    HitEffect temphiteffect(iit->GetX(), iit->GetY());
                    hiteffect.push_back(temphiteffect);
                    iit = enemy.erase(iit);


                        soloud.play(MyWindow.wav[9]);

                    
               
                }
                else {
                    ++iit;
                }
            }
            auto i10t = hiteffect.begin();
            while (i10t != hiteffect.end()) {
                i10t->Update();
                if (i10t->GetLifespan() <= 0) {
                    i10t = hiteffect.erase(i10t);
                }
                else {
                    i10t++;
                }
            }
            //人物升级
            character.UpdateLevel();

            globallock.unlock();

            globallock.lock();
            std::swap(FrontBuffer, BackBuffer);
            BackBuffer->clear(); 
            globallock.unlock();


            //结束游戏
            if (character.GetHP() <= 0) {
                Status = false;
            }

        }
    }


