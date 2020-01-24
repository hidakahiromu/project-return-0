#include"Warp.h"
#include "Character.h"
#include"Difficult.h"

int Warp::count;

Warp::Warp(void) {
	jobDetailsFlag = false;
	enedisp = 0;
	GetEnemyName(U"���[�t");	//battle6
	HP = 500;
	Ex1 = U"���łȃV�[���h�������Ă���";
	Ex2 = U"���낢��ȍU������C���^�[�l�b�g��";
	Ex3 = U"����Ă��郍�{�b�g";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Warp::~Warp(void) {

}

void Warp::jobUpdate(void) {
	if (KeyZ.down() | KeyEnter.down() | KeySpace.down()) {	//�e�L�X�g����
		enedisp += 1;
	}
	if (count == 0) {
		damagehalf == false;
	}else if(damagehalf == true) {
		count--;
	}

}

void Warp::jobDraw(void) {
	jobDetails();
}

void Warp::jobDetails(void) {
	switch (enedisp) {
	case 1:
		if (Character::turncount == 1) {
			FontAsset(U"EnemyF")(U"���[�t�̓t�@�C�A�E�H�[����W�J�����I").draw(550, 380);
			damagehalf = true;
			count = 2;
		}
		else {
			FontAsset(U"EnemyF")(U"���[�t�̍U�����I").draw(550, 380);
		}
		break;
	case 2:
		if (Character::turncount == 1) {
			FontAsset(U"EnemyF")(U"���[�t�͂��΂炭�̊ԃ_���[�W�𔼂���I").draw(550, 380);
		}
		else {
			if (jobDetailsFlag == false) {
				attackpoint = (100 * rand() & 21 + 90) / 100;
			}
			jobDetailsFlag = true;
			FontAsset(U"EnemyF")(Difficult::GetCharacterName(),U"��", attackpoint, U"�̃_���[�W�I").draw(550, 380);
			Character::Damage(attackpoint);
		}
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