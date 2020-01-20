#include"Warp.h"

Warp::Warp(void) {
	HP = 100;
	Ex1 = U"強固なシールドを持っており";
	Ex2 = U"いろいろな攻撃からインターネットを";
	Ex3 = U"守っているロボット";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Warp::~Warp(void) {

}

void Warp::jobUpdate(void) {

}

void Warp::jobDraw(void) {

}