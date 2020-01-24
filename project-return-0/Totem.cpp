#include"Totem.h"
#include "Character.h"
#include"Difficult.h"

Totem::Totem(void) {
	jobDetailsFlag = false;
	enedisp = 0;
	GetEnemyName(U"�g�[�e��");	//battle4
	HP = 500;
	Ex1 = U"1�g�[�e���|�[���̂悤�ɂR�̃��{�b�g";
	Ex2 = U"���d�Ȃ��Ăł��Ă���";
	Ex3 = U"��ԉ��̃��{�b�g�݂̂��{��";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Totem::~Totem(void) {

}

void Totem::jobUpdate(void) {
	if (KeyZ.down() | KeyEnter.down() | KeySpace.down()) {	//�e�L�X�g����
		enedisp += 1;
	}
}

void Totem::jobDraw(void) {
	jobDetails();
}

void Totem::jobDetails(void) {
	switch (enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"�g�[�e���̓W�F�b�g�X�g���[���A�^�b�N���������Ă����I").draw(550, 380);
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