#pragma once
#include<Siv3D.hpp>

class Enemy {
public:
	Enemy(void);
	~Enemy(void);
	static void update(void);
	static void draw(void);
	static int SetHp(void);				//�G��HP��n������
private:
	static int enemyHp;					//�G��HP

};