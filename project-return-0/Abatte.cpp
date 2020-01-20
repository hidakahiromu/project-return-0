#include"Abatte.h"
#include "Character.h"

Abatte::Abatte(void) {
	GetEnemyName(U"�G�[�o�b�g");	//battle3
	HP = 200;
	Ex1 = U"�A�h���X���X�L�������čs�������肵�Ă���";
	Ex2 = U"��������̃A�[�����B�������Ă��郍�{�b�g";
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
		FontAsset(U"EnemyF")(U"Abatte�̓��[���E�C���X��������I").draw(550, 380);
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