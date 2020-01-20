#include"Ramle.h"
#include "Character.h"

Ramle::Ramle(void) {
	GetEnemyName(U"�����[��");	//battle5
	HP = 400;
	Ex1 = U"EVOA�ɂ���č��ꂽ���{�b�g";
	Ex2 = U"���܂萫�\�͂悭�Ȃ��悤���E�E�E";
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
			FontAsset(U"EnemyF")(U"�����[���͖\�������I").draw(550, 380);
		}
		else {
			FontAsset(U"EnemyF")(U"�����[���͂��΂ꂽ�I").draw(550, 380);
		}
		break;
	case 2:
		if (HP <= 100) {
			attackpoint = (200 * rand() & 21 + 90) / 100;
			FontAsset(U"EnemyF")(U"�L��������", attackpoint, U"�̃_���[�W�I").draw(550, 380);
		}
		else {
			attackpoint = (80 * rand() & 21 + 90) / 100;
			FontAsset(U"EnemyF")(U"�L��������", attackpoint, U"�̃_���[�W�I").draw(550, 380);
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