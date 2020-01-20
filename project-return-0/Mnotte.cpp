#include"Mnotte.h"
#include "Character.h"

Mnotte::Mnotte(void) {
	HP = 100;
	Ex1 = U"16�i���ɂ���Đl�Ԃ̌����\���ł���";
	Ex2 = U"�ނ�ɂ��Ƃ��Đl�Ԃ̊���͕��G������";
	Ex3 = U"��{�I�ɒP�Ƃōs�����Ă���";
	SetEnemyStatus(HP,Ex1,Ex2,Ex3);
	FontAsset::Register(U"mnotteF", 30);
}

Mnotte::~Mnotte(void) {

}

void Mnotte::jobUpdate(void) {

}

void Mnotte::jobDraw(void) {
	switch (Enemy::eneturn) {
	case 1:
		FontAsset(U"mnotteF")(U"�G�̍U���I").draw(550, 380);
		break;
	case 2:
		FontAsset(U"mnotteF")(U"Mnotte�̓E�C���X�U�����s�����I").draw(550, 380);
		Character::Damage(50);
		break;
	case 3:
		Character::OnCharacterFlag(true);
		OnEnemyFlag(false);
		Enemy::eneturn = 1;
		break;
	default:
		break;
	}
}

