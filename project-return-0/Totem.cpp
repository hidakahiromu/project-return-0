#include"Totem.h"
#include "Character.h"
#include"Difficult.h"

Totem::Totem(void) {
	jobDetailsFlag = false;
	enedisp = 0;
	GetEnemyName(U"トーテム");	//battle4
	HP = 500;
	Ex1 = U"1トーテムポールのように３つのロボット";
	Ex2 = U"が重なってできている";
	Ex3 = U"一番下のロボットのみが本体";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Totem::~Totem(void) {

}

void Totem::jobUpdate(void) {
	if (KeyZ.down() | KeyEnter.down() | KeySpace.down()) {	//テキスト送り
		enedisp += 1;
	}
}

void Totem::jobDraw(void) {
	jobDetails();
}

void Totem::jobDetails(void) {
	switch (enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"トーテムはジェットストリームアタックをしかけてきた！").draw(550, 380);
		break;
	case 2:
		if (jobDetailsFlag == false) {
			attackpoint = (50 * (rand() % 21 + 90)) / 100;
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