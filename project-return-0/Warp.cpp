#include"Warp.h"

Warp::Warp(void) {
	HP = 100;
	Ex1 = U"���łȃV�[���h�������Ă���";
	Ex2 = U"���낢��ȍU������C���^�[�l�b�g��";
	Ex3 = U"����Ă��郍�{�b�g";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Warp::~Warp(void) {

}

void Warp::jobUpdate(void) {

}

void Warp::jobDraw(void) {

}