#include"Evoa.h"

Evoa::Evoa(void) {
	GetEnemyName(U"EVOA");
	HP = 100;
	Ex1 = U"AI����������������̑��݈Ӌ`��";
	Ex2 = U"�T���Ă���";
	Ex3 = U"����AI�͐i���������Ă���";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Evoa::~Evoa(void) {

}

void Evoa::jobUpdate(void) {

}

void Evoa::jobDraw(void) {

}