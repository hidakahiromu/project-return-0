#include"Ramle.h"
#include "Character.h"
#include"Difficult.h"

Ramle::Ramle(void) {
	jobDetailsFlag = false;
	enedisp = 0;
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
	if (KeyZ.down() | KeyEnter.down() | KeySpace.down()) {	//�e�L�X�g����
		enedisp += 1;
	}
}

void Ramle::jobDraw(void) {
	jobDetails();
}

void Ramle::jobDetails(void) {
	switch (enedisp) {
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
			if (jobDetailsFlag == false) {
				attackpoint = (200 * rand() & 21 + 90) / 100;
			}
			FontAsset(U"EnemyF")(Difficult::GetCharacterName(),U"��", attackpoint, U"�̃_���[�W�I").draw(550, 380);
		}
		else {
			if (jobDetailsFlag == false) {
				attackpoint = (80 * rand() & 21 + 90) / 100;
			}
			FontAsset(U"EnemyF")(Difficult::GetCharacterName(),U"��", attackpoint, U"�̃_���[�W�I").draw(550, 380);
		}
		jobDetailsFlag = true;
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