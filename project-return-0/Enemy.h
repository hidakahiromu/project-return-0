#pragma once
#include<Siv3D.hpp>
#include"Character.h"

class Enemy {
public:
	Enemy(void);
	~Enemy(void);
	void update(void);
	void draw(void);
	static void OnEnemyFlag(bool next);			//Enemyのフラグ切り替え	
	static void Damage(int damage);				//Characterからダメージをもらってくる処理
private:
	static int enemyHp;					//敵のHP
	static bool EnemyTurnFlag;			//TRUEの時Enemyのターン


};