#include"Mnotte.h"
#include "Character.h"
#include"Difficult.h"

Mnotte::Mnotte(void) {
	jobDetailsFlag = false;
	enedisp = 0;
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
	if (KeyZ.down() | KeyEnter.down() | KeySpace.down()) {	//�e�L�X�g����
		enedisp += 1;
	}
}

void Mnotte::jobDraw(void) {
	jobDetails();
}

void Mnotte::jobDetails(void) {
	switch (enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"���m�b�g��F5�A�ł��s�����I").draw(550, 380);
		break;
	case 2:
		if (jobDetailsFlag == false) {
			attackpoint = (50 * rand() & 21 + 90) / 100;
		}
		jobDetailsFlag = true;
		FontAsset(U"EnemyF")(Difficult::GetCharacterName(),U"��", attackpoint, U"�̃_���[�W�I").draw(550, 380);
		Character::Damage(attackpoint);
		break;
	case 3:
		Character::OnCharacterFlag(true);
		OnEnemyFlag(false);
		enedisp = 0;
		jobDetailsFlag = false;
		break;
	default:
		break;
	}
}