#include"Ramle.h"
#include "Character.h"
#include"Difficult.h"

Ramle::Ramle(void) {
	jobDetailsFlag = false;
	enedisp = 0;
	GetEnemyName(U"ラムール");	//battle5
	HP = 400;
	Ex1 = U"EVOAによって作られたロボット";
	Ex2 = U"あまり性能はよくないようだ・・・";
	Ex3 = U"";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Ramle::~Ramle(void) {

}

void Ramle::jobUpdate(void) {
	if (KeyZ.down() | KeyEnter.down() | KeySpace.down()) {	//テキスト送り
		enedisp += 1;
	}
}

void Ramle::jobDraw(void) {
	jobDetails();
}

void Ramle::jobDetails(void) {
	switch (enedisp) {
	case 1:
		if (HP <= 100) {
			FontAsset(U"EnemyF")(U"ラムールは暴走した！").draw(550, 380);
		}
		else {
			FontAsset(U"EnemyF")(U"ラムールはあばれた！").draw(550, 380);
		}
		break;
	case 2:
		if (HP <= 100) {
			if (jobDetailsFlag == false) {
				attackpoint = (200 * rand() & 21 + 90) / 100;
			}
			FontAsset(U"EnemyF")(Difficult::GetCharacterName(),U"に", attackpoint, U"のダメージ！").draw(550, 380);
		}
		else {
			if (jobDetailsFlag == false) {
				attackpoint = (80 * rand() & 21 + 90) / 100;
			}
			FontAsset(U"EnemyF")(Difficult::GetCharacterName(),U"に", attackpoint, U"のダメージ！").draw(550, 380);
		}
		jobDetailsFlag = true;
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