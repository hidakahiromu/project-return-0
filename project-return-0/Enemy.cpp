#include"Enemy.h"

int Enemy::enemyHp;					//敵のHP
bool Enemy::EnemyTurnFlag;

Enemy::Enemy(void) {
	//enemyNowCount++;

}

Enemy::~Enemy(void) {

}

void Enemy::update(void) {
	
}

void Enemy::draw(void) {

}

void Enemy::Damage(int damage) {
	enemyHp -= damage;
	if (enemyHp <= 0) {				//攻撃を食らった時HPが無くなっていればバトル終了
		Battle::OnFlagFinalized(true);
	}
}

void Enemy::OnEnemyFlag(bool next) {
	EnemyTurnFlag = next;
}
