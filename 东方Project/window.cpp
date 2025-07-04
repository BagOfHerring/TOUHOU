#pragma once
#include"window.h"
#include"global.h"

int Window::getW() const {
	return width;
}
int Window::getH() const {
	return height;
}
void Window::SetT() {
	if (Mode == EASY||Mode == ENDLESS) {
		T = 500;
	}
	else {
		T = 300;
	}
}
int Window::GetT() const {
	return T;
}
int Window::GetBoss_HP() const {
	return Boss_HP;
}
void Window::LoadImage() {
	for (int i = 0; i < 150; ++i) {
		img[i] = new IMAGE();  // 初始化每个 IMAGE 指针
	}
	//boss
	loadimage(img[0], "./RES/entity/boss/boss-1-0.png");
	loadimage(img[1], "./RES/entity/boss/boss-1-1.png");
	loadimage(img[2], "./RES/entity/boss/boss-2-0.png");
	loadimage(img[3], "./RES/entity/boss/boss-2-1.png");
	loadimage(img[4], "./RES/entity/boss/boss-3-0.png");
	loadimage(img[5], "./RES/entity/boss/boss-3-1.png");
	loadimage(img[6], "./RES/entity/boss/boss-4-0.png");
	loadimage(img[7], "./RES/entity/boss/boss-4-1.png");
	loadimage(img[8], "./RES/entity/boss/bulb-0.png", 24, 24);
	loadimage(img[9], "./RES/entity/boss/bulb-1.png", 24, 24);
	loadimage(img[10], "./RES/entity/boss/bulm-0.png");
	loadimage(img[11], "./RES/entity/boss/bulm-1.png");
	loadimage(img[12], "./RES/entity/boss/buls-0.png");
	loadimage(img[13], "./RES/entity/boss/buls-1.png");
	loadimage(img[126], "./RES/entity/enemy/bul1-0.png", 8, 8);
	loadimage(img[127], "./RES/entity/enemy/bul1-1.png", 8, 8);
	loadimage(img[128], "./RES/entity/enemy/bul2-0.png", 20, 20);
	loadimage(img[129], "./RES/entity/enemy/bul2-1.png", 20, 20);
	loadimage(img[130], "./RES/entity/enemy/bul3-0.png",16,16);
	loadimage(img[131], "./RES/entity/enemy/bul3-1.png",16,16);
	loadimage(img[132], "./RES/entity/enemy/bul3-0.png",8,8);
	loadimage(img[133], "./RES/entity/enemy/bul3-1.png",8,8);
	loadimage(img[134], "./RES/entity/enemy/bul1-0.png", 16, 16);
	loadimage(img[135], "./RES/entity/enemy/bul1-1.png", 16, 16);

	loadimage(img[136], "./RES/entity/enemy/bul1-0.png", 24,24);
	loadimage(img[137], "./RES/entity/enemy/bul1-1.png", 24,24);
	loadimage(img[138], "./RES/entity/enemy/bul2-0.png", 24,24);
	loadimage(img[139], "./RES/entity/enemy/bul2-1.png", 24,24);
	loadimage(img[140], "./RES/entity/enemy/bul3-0.png", 24,24);
	loadimage(img[141], "./RES/entity/enemy/bul3-1.png", 24,24);
	

	//灵梦
	loadimage(img[14], "./RES/entity/character1/rm1-0.png");
	loadimage(img[15], "./RES/entity/character1/rm1-1.png");
	loadimage(img[16], "./RES/entity/character1/rm2-0.png");
	loadimage(img[17], "./RES/entity/character1/rm2-1.png");
	loadimage(img[18], "./RES/entity/character1/rm3-0.png");
	loadimage(img[19], "./RES/entity/character1/rm3-1.png");
	loadimage(img[20], "./RES/entity/character1/rm4-0.png");
	loadimage(img[21], "./RES/entity/character1/rm4-1.png");
	loadimage(img[22], "./RES/entity/character1/rm-b.png");
	loadimage(img[23], "./RES/entity/character1/rm-hb-0.png",10,10);
	loadimage(img[24], "./RES/entity/character1/rm-hb-1.png",10,10);

	//魔理沙
	loadimage(img[25], "./RES/entity/character2/mrs1-0.png");
	loadimage(img[26], "./RES/entity/character2/mrs1-1.png");
	loadimage(img[27], "./RES/entity/character2/mrs2-0.png");
	loadimage(img[28], "./RES/entity/character2/mrs2-1.png");
	loadimage(img[29], "./RES/entity/character2/mrs3-0.png");
	loadimage(img[30], "./RES/entity/character2/mrs3-1.png");
	loadimage(img[31], "./RES/entity/character2/mrs4-0.png");
	loadimage(img[32], "./RES/entity/character2/mrs4-1.png");
	loadimage(img[33], "./RES/entity/character2/mrs-b.png");
	loadimage(img[34], "./RES/entity/character2/mrs-hb-0.png");
	loadimage(img[35], "./RES/entity/character2/mrs-hb-1.png");

	//enemy
	loadimage(img[36], "./RES/entity/enemy/bul1-0.png");
	loadimage(img[37], "./RES/entity/enemy/bul1-1.png");
	loadimage(img[38], "./RES/entity/enemy/bul2-0.png", 20, 20);
	loadimage(img[39], "./RES/entity/enemy/bul2-1.png", 20, 20);
	loadimage(img[40], "./RES/entity/enemy/bul3-0.png");
	loadimage(img[41], "./RES/entity/enemy/bul3-1.png");
	loadimage(img[42], "./RES/entity/enemy/enemy1-0.png");
	loadimage(img[43], "./RES/entity/enemy/enemy1-1.png");
	loadimage(img[44], "./RES/entity/enemy/enemy2-0.png");
	loadimage(img[45], "./RES/entity/enemy/enemy2-1.png");
	loadimage(img[46], "./RES/entity/enemy/enemy3-0.png");
	loadimage(img[47], "./RES/entity/enemy/enemy3-1.png");

	// 掉落物
	loadimage(img[48], "./RES/entity/loot/blueloot.png");
	loadimage(img[49], "./RES/entity/loot/redloot.png");

	// UI
	// 角色选择
	loadimage(img[50], "./RES/entity/UI/characterchoose/Marisaname-0.png",500,120);
	loadimage(img[51], "./RES/entity/UI/characterchoose/Marisaname-1.png",500,120);
	loadimage(img[52], "./RES/entity/UI/characterchoose/Marisaselect-0.png",700,966);
	loadimage(img[53], "./RES/entity/UI/characterchoose/Marisaselect-1.png",700,966);
	loadimage(img[54], "./RES/entity/UI/characterchoose/Reimuname-0.png",500,120);
	loadimage(img[55], "./RES/entity/UI/characterchoose/Reimuname-1.png",500,120);
	loadimage(img[56], "./RES/entity/UI/characterchoose/Reimuselect-0.png",700,966);
	loadimage(img[57], "./RES/entity/UI/characterchoose/Reimuselect-1.png",700,966);
	loadimage(img[58], "./RES/entity/UI/characterchoose/select00.jpg");
	loadimage(img[59], "./RES/entity/UI/characterchoose/selectplayer-0.png",450,90);
	loadimage(img[60], "./RES/entity/UI/characterchoose/selectplayer-1.png",450,90);

	// 难度选择
	loadimage(img[61], "./RES/entity/UI/difficultychoose/easy-0.png", 500,200);
	loadimage(img[62], "./RES/entity/UI/difficultychoose/easy-1.png", 500, 200);
	loadimage(img[63], "./RES/entity/UI/difficultychoose/easy-b-0.png", 500, 200);
	loadimage(img[64], "./RES/entity/UI/difficultychoose/easy-b-1.png", 500, 200);
	loadimage(img[65], "./RES/entity/UI/difficultychoose/normal-0.png",500,200);
	loadimage(img[66], "./RES/entity/UI/difficultychoose/normal-1.png",500,200);
	loadimage(img[67], "./RES/entity/UI/difficultychoose/normal-b-0.png", 500, 200);
	loadimage(img[68], "./RES/entity/UI/difficultychoose/normal-b-1.png", 500, 200);
	loadimage(img[69], "./RES/entity/UI/difficultychoose/hard-0.png", 500, 200);
	loadimage(img[70], "./RES/entity/UI/difficultychoose/hard-1.png", 500,200);
	loadimage(img[71], "./RES/entity/UI/difficultychoose/hard-b-0.png", 500, 200);
	loadimage(img[72], "./RES/entity/UI/difficultychoose/hard-b-1.png", 500, 200);
	loadimage(img[73], "./RES/entity/UI/difficultychoose/select00.jpg",1200,1000);
	loadimage(img[74], "./RES/entity/UI/difficultychoose/selectlevel-0.png",450,90);
	loadimage(img[75], "./RES/entity/UI/difficultychoose/selectlevel-1.png",450,90);

	// 结束
	loadimage(img[76], "./RES/entity/UI/end/endtext-0.png");
	loadimage(img[77], "./RES/entity/UI/end/endtext-1.png");
	loadimage(img[78], "./RES/entity/UI/end/select00.jpg");

	// 游戏内
	loadimage(img[79], "./RES/entity/UI/ingame/hp-0.png",20,20);
	loadimage(img[80], "./RES/entity/UI/ingame/hp-1.png",20,20);
	loadimage(img[81], "./RES/entity/UI/ingame/l-tree-0.png");
	loadimage(img[82], "./RES/entity/UI/ingame/l-tree-1.png");
	loadimage(img[83], "./RES/entity/UI/ingame/lv-0.png",20,20);
	loadimage(img[84], "./RES/entity/UI/ingame/lv-1.png",20,20);
	loadimage(img[85], "./RES/entity/UI/ingame/righttablebg.png");
	loadimage(img[86], "./RES/entity/UI/ingame/road.png");
	loadimage(img[87], "./RES/entity/UI/ingame/r-tree-0.png");
	loadimage(img[88], "./RES/entity/UI/ingame/r-tree-1.png");
	loadimage(img[89], "./RES/entity/UI/ingame/table-0.png",300,384);
	loadimage(img[90], "./RES/entity/UI/ingame/table-1.png",300,384);

	// 标题页
	loadimage(img[91], "./RES/entity/UI/titlepage/quitbutton-0.png",140,60);
	loadimage(img[92], "./RES/entity/UI/titlepage/quitbutton-1.png", 140, 60);
	loadimage(img[93], "./RES/entity/UI/titlepage/quitbutton-b-0.png", 140, 60);
	loadimage(img[94], "./RES/entity/UI/titlepage/quitbutton-b-1.png", 140, 60);
	loadimage(img[95], "./RES/entity/UI/titlepage/startbutton-0.png", 140, 60);
	loadimage(img[96], "./RES/entity/UI/titlepage/startbutton-1.png", 140, 60);
	loadimage(img[97], "./RES/entity/UI/titlepage/startbutton-b-0.png", 140, 60);
	loadimage(img[98], "./RES/entity/UI/titlepage/startbutton-b-1.png", 140, 60);
	loadimage(img[99], "./RES/entity/UI/titlepage/titlebg-withtitle.png");
	//加载
	loadimage(img[100], "./RES/entity/UI/loading/load-0.png",450,90);
	loadimage(img[101], "./RES/entity/UI/loading/load-1.png",450,90);
	//特效
	loadimage(img[102], "./RES/entity/effect_0.png",40,40);
	loadimage(img[103], "./RES/entity/effect_1.png",40,40);
	loadimage(img[104], "./RES/entity/effect_0.png",45,45);
	loadimage(img[105], "./RES/entity/effect_1.png",45,45);
	loadimage(img[106], "./RES/entity/effect_0.png",50,50);
	loadimage(img[107], "./RES/entity/effect_1.png",50,50);
	loadimage(img[108], "./RES/entity/effect_0.png",55,55);
	loadimage(img[109], "./RES/entity/effect_1.png",55,55);
	loadimage(img[110], "./RES/entity/effect_0.png",60,60);
	loadimage(img[111], "./RES/entity/effect_1.png",60,60);
	loadimage(img[112], "./RES/entity/effect_0.png",65,65);
	loadimage(img[113], "./RES/entity/effect_1.png",65,65);
	loadimage(img[114], "./RES/entity/effect_0.png",70,70);
	loadimage(img[115], "./RES/entity/effect_1.png",70,70);
	loadimage(img[116], "./RES/entity/effect_0.png",75,75);
	loadimage(img[117], "./RES/entity/effect_1.png",75,75);
	loadimage(img[118], "./RES/entity/effect_0.png", 80,80);
	loadimage(img[119], "./RES/entity/effect_1.png", 80,80);
	loadimage(img[120], "./RES/entity/effect_0.png", 85,85);
	loadimage(img[121], "./RES/entity/effect_1.png", 85,85);
	loadimage(img[122], "./RES/entity/effect_0.png", 90,90);
	loadimage(img[123], "./RES/entity/effect_1.png", 90,90);
	loadimage(img[124], "./RES/entity/effect_0.png", 95,95);
	loadimage(img[125], "./RES/entity/effect_1.png", 95,95);
}

void Window::LoadWav()
{
	//标题bgm
	wav[0].load("./RES/sound/th07_01.wav");
	//道中bgm
	wav[1].load("./RES/sound/th07_02.wav");
	//bossbgm
	wav[2].load("./RES/sound/th07_08.wav");
	//选择
	wav[3].load("./RES/sound/se_ok00.wav");
	//biu
	wav[4].load("./RES/sound/se_pldead00.wav");
	//玩家射击
	wav[5].load("./RES/sound/se_item00.wav");
	//敌人射击
	wav[6].load("./RES/sound/se_tan00.wav");
	wav[7].load("./RES/sound/se_tan01.wav");
	wav[8].load("./RES/sound/se_tan02.wav");
	//敌人击破
	wav[9].load("./RES/sound/se_enep00.wav");
	wav[10].load("./RES/sound/se_enep01.wav");
	wav[11].load("./RES/sound/se_plst00.wav");
}
int Window::GetHighSpeed_Bullet()const {
	return HighSpeed_Bullet;
}

int Window::GetLowSpeed_Bullet() const {
	return LowSpeed_Bullet;
}

Window MyWindow = Window();
Window GraphicWindow = Window(1200, 1000);