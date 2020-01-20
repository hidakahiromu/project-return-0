#include"Totem.h"
#include "Character.h"

Totem::Totem(void) {
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

}

void Totem::jobDraw(void) {
	switch (Enemy::enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"�g�[�e���̓W�F�b�g�X�g���[���A�^�b�N���������Ă����I").draw(550, 380);
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