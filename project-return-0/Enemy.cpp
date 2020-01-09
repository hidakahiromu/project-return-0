#include"Enemy.h"

int Enemy::enemyHp;					//“G‚ÌHP
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
	if (enemyHp <= 0) {				//UŒ‚‚ðH‚ç‚Á‚½ŽžHP‚ª–³‚­‚È‚Á‚Ä‚¢‚ê‚Îƒoƒgƒ‹I—¹
		Battle::OnFlagFinalized(true);
	}
}

void Enemy::OnEnemyFlag(bool next) {
	EnemyTurnFlag = next;
}
