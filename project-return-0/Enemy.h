#pragma once
#include<Siv3D.hpp>

class Enemy {
public:
	Enemy(void);
	~Enemy(void);
	static void update(void);
	static void draw(void);
	static int SetHp(void);				//GĚHPđnˇ
private:
	static int enemyHp;					//GĚHP

};