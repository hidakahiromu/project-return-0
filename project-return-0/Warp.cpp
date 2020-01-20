#include"Warp.h"
#include "Character.h"

int Warp::count;

Warp::Warp(void) {
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
	if (count == 0) {
		damagehalf == false;
	}else if(damagehalf == true) {
		count--;
	}

}

void Warp::jobDraw(void) {
	switch (Enemy::enedisp) {
	case 1:
		if (Character::turncount == 1) {
			FontAsset(U"EnemyF")(U"���[�t�̓t�@�C�A�E�H�[����W�J�����I").draw(550, 380);
			damagehalf = true;
			count = 2;
		}else {
			FontAsset(U"EnemyF")(U"���[�t�̍U�����I").draw(550, 380);
		}
		break;
	case 2:
		if (Character::turncount == 1) {
			FontAsset(U"EnemyF")(U"���[�t�͂��΂炭�̊ԃ_���[�W�𔼂���I").draw(550, 380);
		}
		else {
			attackpoint = (100 * rand() & 21 + 90) / 100;
			FontAsset(U"EnemyF")(U"�L��������",attackpoint,U"�̃_���[�W�I").draw(550, 380);
			Character::Damage(attackpoint);
		}
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