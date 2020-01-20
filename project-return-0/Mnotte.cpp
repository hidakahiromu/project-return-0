#include"Mnotte.h"
#include "Character.h"

Mnotte::Mnotte(void) {
	HP = 100;
	Ex1 = U"16進数によって人間の言語を表現できる";
	Ex2 = U"彼らにっとって人間の感情は複雑すぎる";
	Ex3 = U"基本的に単独で行動している";
	SetEnemyStatus(HP,Ex1,Ex2,Ex3);
	FontAsset::Register(U"mnotteF", 30);
}

Mnotte::~Mnotte(void) {

}

void Mnotte::jobUpdate(void) {

}

void Mnotte::jobDraw(void) {
	switch (Enemy::eneturn) {
	case 1:
		FontAsset(U"mnotteF")(U"敵の攻撃！").draw(550, 380);
		break;
	case 2:
		FontAsset(U"mnotteF")(U"Mnotteはウイルス攻撃を行った！").draw(550, 380);
		Character::Damage(50);
		break;
	case 3:
		Character::OnCharacterFlag(true);
		OnEnemyFlag(false);
		Enemy::eneturn = 1;
		break;
	default:
		break;
	}
}

