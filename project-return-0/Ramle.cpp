#include"Ramle.h"
#include "Character.h"

Ramle::Ramle(void) {
	GetEnemyName(U"ラムール");	//battle5
	HP = 400;
	Ex1 = U"EVOAによって作られたロボット";
	Ex2 = U"あまり性能はよくないようだ・・・";
	Ex3 = U"";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Ramle::~Ramle(void) {

}

void Ramle::jobUpdate(void) {

}

void Ramle::jobDraw(void) {
	switch (Enemy::enedisp) {
	case 1:
		if (HP <= 100) {
			FontAsset(U"EnemyF")(U"ラムールは暴走した！").draw(550, 380);
		}
		else {
			FontAsset(U"EnemyF")(U"ラムールはあばれた！").draw(550, 380);
		}
		break;
	case 2:
		if (HP <= 100) {
			attackpoint = (200 * rand() & 21 + 90) / 100;
			FontAsset(U"EnemyF")(U"キャラ名に", attackpoint, U"のダメージ！").draw(550, 380);
		}
		else {
			attackpoint = (80 * rand() & 21 + 90) / 100;
			FontAsset(U"EnemyF")(U"キャラ名に", attackpoint, U"のダメージ！").draw(550, 380);
		}
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