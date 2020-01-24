#include"Gaia.h"
#include "Character.h"
#include"Difficult.h"

Gaia::Gaia(void) {
	jobDetailsFlag = false;
	enedisp = 0;
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
	if (KeyZ.down() | KeyEnter.down() | KeySpace.down()) {	//�e�L�X�g����
		enedisp += 1;
	}
}

void Gaia::jobDraw(void) {
	jobDetails();
}

void Gaia::jobDetails(void) {
	switch (enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"�K�C�A�͍U�������������Ă����I").draw(550, 380);
		break;
	case 2:
		if (jobDetailsFlag == false) {
			attackpoint = (100 * rand() & 21 + 90) / 100;
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