#pragma once
#include<Siv3D.hpp>
#include"Character.h"
#include"Battle.h"

class Enemy {
public:
	Enemy(void);
	~Enemy(void);
	void update(void);
	void draw(void);
	static void OnEnemyFlag(bool next);			//Enemyのフラグ切り替え	
	static void Damage(int damage);				//Characterからダメージをもらってくる処理
	
	void ChangeEnemy(int count);			//

private:
	static int enemyHp;					//敵のHP
	static int enemyNowCount;			//敵の番号（第何章で出てくるのか）

	static bool EnemyTurnFlag;			//TRUEの時Enemyのターン


};