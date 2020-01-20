#include"Gaia.h"

Gaia::Gaia(void) {
	HP = 100;
	Ex1 = U"壊れたロボットの集合体で";
	Ex2 = U"自我を持ち始めているが";
	Ex3 = U"Evoaに操られている";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Gaia::~Gaia(void) {

}

void Gaia::jobUpdate(void) {

}

void Gaia::jobDraw(void) {

}