#include"Enemy.h"

int Enemy::enemyHp;

Enemy::Enemy(void) {
	enemyHp = 100;
}

Enemy::~Enemy(void) {

}

void Enemy::update(void) {
	
}

void Enemy::draw(void) {

}

int Enemy::SetHp(void) {
	return enemyHp;
}

