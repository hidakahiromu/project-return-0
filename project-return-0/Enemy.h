#pragma once
#include<Siv3D.hpp>
#include"Character.h"

class Enemy {
public:
	Enemy(void);
	~Enemy(void);
	void update(void);
	void draw(void);
	static void OnEnemyFlag(bool next);			//Enemy�̃t���O�؂�ւ�	
	static void Damage(int damage);				//Character����_���[�W��������Ă��鏈��
private:
	static int enemyHp;					//�G��HP
	static bool EnemyTurnFlag;			//TRUE�̎�Enemy�̃^�[��


};