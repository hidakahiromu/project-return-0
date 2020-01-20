#include"Abatte.h"

Abatte::Abatte(void) {
	HP = 100;
	Ex1 = U"アドレスをスキャンして行き先を特定している";
	Ex2 = U"たくさんのアームを隠し持っているロボット";
	Ex3 = U"";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Abatte::~Abatte(void) {

}

void Abatte::jobUpdate(void) {

}

void Abatte::jobDraw(void) {

}