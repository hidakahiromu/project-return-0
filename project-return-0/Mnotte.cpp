#include"Mnotte.h"

Mnotte::Mnotte(void) {
	GetEnemyName(U"モノット");
	HP = 100;
	Ex1 = U"16進数によって人間の言語を表現できる";
	Ex2 = U"彼らにっとって人間の感情は複雑すぎる";
	Ex3 = U"基本的に単独で行動している";
	SetEnemyStatus(HP,Ex1,Ex2,Ex3);
}

Mnotte::~Mnotte(void) {

}

void Mnotte::jobUpdate(void) {

}

void Mnotte::jobDraw(void) {
	
}

