#include"Gaia.h"
#include "Character.h"

Gaia::Gaia(void) {
	GetEnemyName(U"�K�C�A");
	HP = 600;
	Ex1 = U"��ꂽ���{�b�g�̏W���̂�";
	Ex2 = U"����������n�߂Ă��邪";
	Ex3 = U"Evoa�ɑ����Ă���";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Gaia::~Gaia(void) {

}

void Gaia::jobUpdate(void) {

}

void Gaia::jobDraw(void) {
	switch (Enemy::enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"�K�C�A�͍U�������������Ă����I").draw(550, 380);
		break;
	case 2:
		attackpoint = (100 * rand() & 21 + 90) / 100;
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