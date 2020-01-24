#include"Mnotte.h"
#include "Character.h"
#include"Difficult.h"

Mnotte::Mnotte(void) {
	jobDetailsFlag = false;
	enedisp = 0;
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
	if (KeyZ.down() | KeyEnter.down() | KeySpace.down()) {	//テキスト送り
		enedisp += 1;
	}
}

void Mnotte::jobDraw(void) {
	jobDetails();
}

void Mnotte::jobDetails(void) {
	switch (enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"モノットはF5連打を行った！").draw(550, 380);
		break;
	case 2:
		if (jobDetailsFlag == false) {
			attackpoint = (50 * rand() & 21 + 90) / 100;
		}
		jobDetailsFlag = true;
		FontAsset(U"EnemyF")(Difficult::GetCharacterName(),U"に", attackpoint, U"のダメージ！").draw(550, 380);
		Character::Damage(attackpoint);
		break;
	case 3:
		Character::OnCharacterFlag(true);
		OnEnemyFlag(false);
		enedisp = 0;
		jobDetailsFlag = false;
		break;
	default:
		break;
	}
}