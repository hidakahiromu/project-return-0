#include"Evoa.h"
#include "Character.h"

Evoa::Evoa(void) {
	GetEnemyName(U"EVOA");	//battle1
	HP = 100;
	Ex1 = U"AI����������������̑��݈Ӌ`��";
	Ex2 = U"�T���Ă���";
	Ex3 = U"����AI�͐i���������Ă���";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Evoa::~Evoa(void) {

}

void Evoa::jobUpdate(void) {

}

void Evoa::jobDraw(void) {
	switch (Enemy::enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"EVOA�̓�������������s�����I").draw(550, 380);
		break;
	case 2:
		attackpoint = (50 * rand() & 21 + 90) / 100;
		FontAsset(U"EnemyF")(U"�L��������", attackpoint, U"�̃_���[�W�I").draw(550, 380);
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