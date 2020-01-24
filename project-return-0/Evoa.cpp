#include"Evoa.h"
#include "Character.h"
#include"Difficult.h"
#include"Battle.h"

Evoa::Evoa(void) {
	jobDetailsFlag = false;
	enedisp = 0;
	GetEnemyName(U"EVOA");	//battle1
	HP = 100;
	Ex1 = U"AIが自我を持ち自分の存在意義を";
	Ex2 = U"探している";
	Ex3 = U"このAIは進化し続けている";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
	if (Battle::SetEnemyCount() == 1) {				//一回目のバトルの時のステータスを書く

	}
	if (Battle::SetEnemyCount() == 8) {				//八回目のバトル(EVOAは二回目)のステータス

	}
	if (Battle::SetEnemyCount() == 9) {				//九回目のバトル(EVOAは三回目)のステータス

	}
}

Evoa::~Evoa(void) {

}

void Evoa::jobUpdate(void) {
	if (KeyZ.down() | KeyEnter.down() | KeySpace.down()) {	//テキスト送り
		enedisp += 1;
	}
}

void Evoa::jobDraw(void) {
	jobDetails();
}

void Evoa::jobDetails(void) {
	switch (enedisp) {
	case 1:
		FontAsset(U"EnemyF")(U"EVOAはメモリ改ざんを行った！").draw(550, 380);
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