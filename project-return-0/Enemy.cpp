#include"Character.h"
#include"Battle.h"
#include"Enemy.h"

int Enemy::enemyHp;					//敵のHP
String Enemy::enemyName;			//敵の名前
String Enemy::explanation1;			//説明文一行目
String Enemy::explanation2;			//説明文二行目
String Enemy::explanation3;			//説明文三行目
bool Enemy::EnemyTurnFlag;
bool Enemy::damagehalf;		//Warpのスキルで参照


Enemy::Enemy(void) {
	FontAsset::Register(U"EnemyF", 30);

}

Enemy::~Enemy(void) {

}

void Enemy::update(void) {
	jobUpdate();

	if (KeyZ.down() | KeyEnter.down() | KeySpace.down())	//テキスト送り
		enedisp += 1;

}

void Enemy::draw(void) {
	if (EnemyTurnFlag == true)
		jobDraw();

}

void Enemy::Damage(int damage) {
	if (damagehalf == true) {
		enemyHp -= damage / 2;
	}
	else {
		enemyHp -= damage;
	}
	if (enemyHp <= 0) {				//攻撃を食らった時HPが無くなっていればバトル終了
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

void Enemy::GetEnemyName(String name) {
	enemyName = name;
}

String Enemy::SetEnemyName(void) {
	return enemyName;
}