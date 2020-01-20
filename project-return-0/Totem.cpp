#include"Totem.h"

Totem::Totem(void) {
	HP = 100;
	Ex1 = U"1トーテムポールのように３つのロボット";
	Ex2 = U"が重なってできている";
	Ex3 = U"一番下のロボットのみが本体";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Totem::~Totem(void) {

}

void Totem::jobUpdate(void) {

}

void Totem::jobDraw(void) {

}