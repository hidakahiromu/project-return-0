#include"Enemy.h"

int Enemy::enemyHp;
bool Enemy::EnemyTurnFlag;

Enemy::Enemy(void) {
	enemyHp = 100;
}

Enemy::~Enemy(void) {

}

void Enemy::update(void) {
	
}

void Enemy::draw(void) {

}

void Enemy::Damage(int damage) {
	enemyHp -= damage;
	if (enemyHp <= 0) {				//�U����H�������HP�������Ȃ��Ă���΃o�g���I��
		Battle::OnFlagFinalized(true);
	}
}

void Enemy::OnEnemyFlag(bool next) {
	EnemyTurnFlag = next;
}

