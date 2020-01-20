#include"Mnotte.h"
#include "Character.h"

Mnotte::Mnotte(void) {
	GetEnemyName(U"モノット");	//battle2
	HP = 150;
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
	switch (Enemy::enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"モノットはF5連打を行った！").draw(550, 380);
		break;
	case 2:
		attackpoint = (50 * rand() & 21 + 90) / 100;
		FontAsset(U"EnemyF")(U"キャラ名に", attackpoint, U"のダメージ！").draw(550, 380);
		Character::Damage(attackpoint);
		break;
	case 3:
		Character::OnCharacterFlag(true);
		OnEnemyFlag(false);
		Enemy::enedisp = 1;
		break;
	default:
		break;
	}
}

