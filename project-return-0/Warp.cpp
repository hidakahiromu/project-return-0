#include"Warp.h"
#include "Character.h"

int Warp::count;

Warp::Warp(void) {
	GetEnemyName(U"ワーフ");	//battle6
	HP = 500;
	Ex1 = U"強固なシールドを持っており";
	Ex2 = U"いろいろな攻撃からインターネットを";
	Ex3 = U"守っているロボット";
	SetEnemyStatus(HP, Ex1, Ex2, Ex3);
}

Warp::~Warp(void) {

}

void Warp::jobUpdate(void) {
	if (count == 0) {
		damagehalf == false;
	}else if(damagehalf == true) {
		count--;
	}

}

void Warp::jobDraw(void) {
	switch (Enemy::enedisp) {
	case 1:
		if (Character::turncount == 1) {
			FontAsset(U"EnemyF")(U"ワーフはファイアウォールを展開した！").draw(550, 380);
			damagehalf = true;
			count = 2;
		}else {
			FontAsset(U"EnemyF")(U"ワーフの攻げき！").draw(550, 380);
		}
		break;
	case 2:
		if (Character::turncount == 1) {
			FontAsset(U"EnemyF")(U"ワーフはしばらくの間ダメージを半げん！").draw(550, 380);
		}
		else {
			attackpoint = (100 * rand() & 21 + 90) / 100;
			FontAsset(U"EnemyF")(U"キャラ名に",attackpoint,U"のダメージ！").draw(550, 380);
			Character::Damage(attackpoint);
		}
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