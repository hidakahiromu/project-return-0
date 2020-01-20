#include"Character.h"
#include"Battle.h"
#include"Enemy.h"

int Enemy::enemyHp;					//�G��HP
String Enemy::explanation1;			//��������s��
String Enemy::explanation2;			//��������s��
String Enemy::explanation3;			//�������O�s��
bool Enemy::EnemyTurnFlag;

Enemy::Enemy(void) {
	FontAsset::Register(U"EnemyF", 30);

}

Enemy::~Enemy(void) {

}

void Enemy::update(void) {
	jobUpdate();
	if (KeyZ.down() | KeyEnter.down() | KeySpace.down())
		eneturn = eneturn % 3 + 1;

}

void Enemy::draw(void) {
	if (EnemyTurnFlag == true)
		jobDraw();

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

void Enemy::SetEnemyStatus(int HP, String Explain1, String Explain2, String Explain3) {
	enemyHp = HP;
	explanation1 = Explain1;
	explanation2 = Explain2;
	explanation3 = Explain3;
}

void Enemy::PrintExplanation(void) {
	FontAsset(U"EnemyF")(explanation1).draw(550, 380);
	FontAsset(U"EnemyF")(explanation2).draw(550, 420);
	FontAsset(U"EnemyF")(explanation3).draw(550, 460);
}