#include"Mnotte.h"

Mnotte::Mnotte(void) {
	GetEnemyName(U"���m�b�g");
	HP = 100;
	Ex1 = U"16�i���ɂ���Đl�Ԃ̌����\���ł���";
	Ex2 = U"�ނ�ɂ��Ƃ��Đl�Ԃ̊���͕��G������";
	Ex3 = U"��{�I�ɒP�Ƃōs�����Ă���";
	SetEnemyStatus(HP,Ex1,Ex2,Ex3);
}

Mnotte::~Mnotte(void) {

}

void Mnotte::jobUpdate(void) {

}

void Mnotte::jobDraw(void) {
	
}

