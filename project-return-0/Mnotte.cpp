#include"Mnotte.h"
#include "Character.h"

Mnotte::Mnotte(void) {
	GetEnemyName(U"���m�b�g");	//battle2
	HP = 150;
	Ex1 = U"16�i���ɂ���Đl�Ԃ̌����\���ł���";
	Ex2 = U"�ނ�ɂ��Ƃ��Đl�Ԃ̊���͕��G������";
	Ex3 = U"��{�I�ɒP�Ƃōs�����Ă���";
	SetEnemyStatus(HP,Ex1,Ex2,Ex3);
}

Mnotte::~Mnotte(void) {

}

void Mnotte::jobUpdate(void) {

}

void Mnotte::jobDraw(void) {
	switch (Enemy::enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"���m�b�g��F5�A�ł��s�����I").draw(550, 380);
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

