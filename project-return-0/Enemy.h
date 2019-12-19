#pragma once
#include<Siv3D.hpp>

class Enemy {
public:
	Enemy(void);
	~Enemy(void);
	static void update(void);
	static void draw(void);
	static int SetHp(void);				//“G‚ÌHP‚ğ“n‚·ˆ—
private:
	static int enemyHp;					//“G‚ÌHP

};