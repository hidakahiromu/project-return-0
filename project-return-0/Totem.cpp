#include"Totem.h"

Totem::Totem(void) {
	HP = 100;
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

}