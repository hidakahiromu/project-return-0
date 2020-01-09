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
	static void OnEnemyFlag(bool next);			//Enemy�̃t���O�؂�ւ�	
	static void Damage(int damage);				//Character����_���[�W��������Ă��鏈��
	
	void ChangeEnemy(int count);			//

private:
	static int enemyHp;					//�G��HP
	static int enemyNowCount;			//�G�̔ԍ��i�扽�͂ŏo�Ă���̂��j

	static bool EnemyTurnFlag;			//TRUE�̎�Enemy�̃^�[��


};