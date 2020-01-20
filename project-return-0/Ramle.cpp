#include"Ramle.h"

Ramle::Ramle(void) {
	GetEnemyName(U"ラムール");
	HP = 100;
	Ex1 = U"EVOAによって作られたロボット";
	Ex2 = U"あまり性能はよくないようだ・・・";
	Ex3 = U"";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Ramle::~Ramle(void) {

}

void Ramle::jobUpdate(void) {

}

void Ramle::jobDraw(void) {

}