#include"Gaia.h"
#include "Character.h"

Gaia::Gaia(void) {
	GetEnemyName(U"ガイア");
	HP = 600;
	Ex1 = U"壊れたロボットの集合体で";
	Ex2 = U"自我を持ち始めているが";
	Ex3 = U"Evoaに操られている";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Gaia::~Gaia(void) {

}

void Gaia::jobUpdate(void) {

}

void Gaia::jobDraw(void) {
	switch (Enemy::enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"ガイアは攻げきをしかけてきた！").draw(550, 380);
		break;
	case 2:
		attackpoint = (100 * rand() & 21 + 90) / 100;
		FontAsset(U"EnemyF")(U"キャラ名に", attackpoint, U"のダメージ！").draw(550, 380);
		Character::Damage(attackpoint);
		break;
	case 3:
		Character::OnCharacterFlag(true);
		OnEnemyFlag(false);
		Enemy::enedisp = 1;
		break;
	default:
		break;
	}
}