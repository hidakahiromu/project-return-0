#include"Ramle.h"

Ramle::Ramle(void) {
	GetEnemyName(U"�����[��");
	HP = 100;
	Ex1 = U"EVOA�ɂ���č��ꂽ���{�b�g";
	Ex2 = U"���܂萫�\�͂悭�Ȃ��悤���E�E�E";
	Ex3 = U"";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Ramle::~Ramle(void) {

}

void Ramle::jobUpdate(void) {

}

void Ramle::jobDraw(void) {

}