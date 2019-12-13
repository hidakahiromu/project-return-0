#include"Enemy.h"

int enemyHp;

Enemy::Enemy(void) {
	enemyHp = 100;
}

Enemy::~Enemy(void) {

}

void Enemy::update(void) {
	
}

void Enemy::draw(void) {

}

int Enemy::NowHp(void) {
	return enemyHp;
}

