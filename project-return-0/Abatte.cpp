#include"Abatte.h"
#include "Character.h"
#include"Difficult.h"

Abatte::Abatte(void) {
	enedisp = 0;
	jobDetailsFlag = false;
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
	if (KeyZ.down() | KeyEnter.down() | KeySpace.down()) {	//�e�L�X�g����
		enedisp += 1;
	}
}

void Abatte::jobDraw(void) {
	jobDetails();
}

void Abatte::jobDetails(void) {
	switch (enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"Abatte�̓��[���E�C���X��������I").draw(550, 380);
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