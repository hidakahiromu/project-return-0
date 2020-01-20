#include"Totem.h"
#include "Character.h"

Totem::Totem(void) {
	GetEnemyName(U"トーテム");	//battle4
	HP = 500;
	Ex1 = U"1トーテムポールのように３つのロボット";
	Ex2 = U"が重なってできている";
	Ex3 = U"一番下のロボットのみが本体";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Totem::~Totem(void) {

}

void Totem::jobUpdate(void) {

}

void Totem::jobDraw(void) {
	switch (Enemy::enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"トーテムはジェットストリームアタックをしかけてきた！").draw(550, 380);
		break;
	case 2:
		attackpoint = (50 * rand() & 21 + 90) / 100;
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