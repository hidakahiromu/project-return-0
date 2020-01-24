#include"Evoa.h"
#include "Character.h"
#include"Difficult.h"
#include"Battle.h"

Evoa::Evoa(void) {
	jobDetailsFlag = false;
	enedisp = 0;
	GetEnemyName(U"EVOA");	//battle1
	HP = 100;
	Ex1 = U"AI����������������̑��݈Ӌ`��";
	Ex2 = U"�T���Ă���";
	Ex3 = U"����AI�͐i���������Ă���";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
	if (Battle::SetEnemyCount() == 1) {				//���ڂ̃o�g���̎��̃X�e�[�^�X������

	}
	if (Battle::SetEnemyCount() == 8) {				//����ڂ̃o�g��(EVOA�͓���)�̃X�e�[�^�X

	}
	if (Battle::SetEnemyCount() == 9) {				//���ڂ̃o�g��(EVOA�͎O���)�̃X�e�[�^�X

	}
}

Evoa::~Evoa(void) {

}

void Evoa::jobUpdate(void) {
	if (KeyZ.down() | KeyEnter.down() | KeySpace.down()) {	//�e�L�X�g����
		enedisp += 1;
	}
}

void Evoa::jobDraw(void) {
	jobDetails();
}

void Evoa::jobDetails(void) {
	switch (enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"EVOA�̓�������������s�����I").draw(550, 380);
		break;
	case 2:
		if (jobDetailsFlag == false) {
			attackpoint = (50 * (rand() % 21 + 90)) / 100;
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