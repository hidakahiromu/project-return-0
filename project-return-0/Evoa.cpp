#include"Evoa.h"
#include "Character.h"

Evoa::Evoa(void) {
	GetEnemyName(U"EVOA");	//battle1
	HP = 100;
	Ex1 = U"AIが自我を持ち自分の存在意義を";
	Ex2 = U"探している";
	Ex3 = U"このAIは進化し続けている";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Evoa::~Evoa(void) {

}

void Evoa::jobUpdate(void) {

}

void Evoa::jobDraw(void) {
	switch (Enemy::enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"EVOAはメモリ改ざんを行った！").draw(550, 380);
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