#include"Gaia.h"
#include "Character.h"
#include"Difficult.h"

Gaia::Gaia(void) {
	jobDetailsFlag = false;
	enedisp = 0;
	GetEnemyName(U"ガイア");
	HP = 600;
	Ex1 = U"壊れたロボットの集合体で";
	Ex2 = U"自我を持ち始めているが";
	Ex3 = U"Evoaに操られている";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Gaia::~Gaia(void) {

}

void Gaia::jobUpdate(void) {
	if (KeyZ.down() | KeyEnter.down() | KeySpace.down()) {	//テキスト送り
		enedisp += 1;
	}
}

void Gaia::jobDraw(void) {
	jobDetails();
}

void Gaia::jobDetails(void) {
	switch (enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"ガイアは攻げきをしかけてきた！").draw(550, 380);
		break;
	case 2:
		if (jobDetailsFlag == false) {
			attackpoint = (100 * rand() & 21 + 90) / 100;
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