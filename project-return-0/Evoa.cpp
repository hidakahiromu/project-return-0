#include"Evoa.h"

Evoa::Evoa(void) {
	GetEnemyName(U"EVOA");
	HP = 100;
	Ex1 = U"AIが自我を持ち自分の存在意義を";
	Ex2 = U"探している";
	Ex3 = U"このAIは進化し続けている";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Evoa::~Evoa(void) {

}

void Evoa::jobUpdate(void) {

}

void Evoa::jobDraw(void) {

}