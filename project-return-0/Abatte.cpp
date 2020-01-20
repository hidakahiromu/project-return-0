#include"Abatte.h"
#include "Character.h"

Abatte::Abatte(void) {
	GetEnemyName(U"エーバット");	//battle3
	HP = 200;
	Ex1 = U"アドレスをスキャンして行き先を特定している";
	Ex2 = U"たくさんのアームを隠し持っているロボット";
	Ex3 = U"";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Abatte::~Abatte(void) {

}

void Abatte::jobUpdate(void) {

}

void Abatte::jobDraw(void) {
	switch (Enemy::enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"Abatteはワームウイルスを放った！").draw(550, 380);
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