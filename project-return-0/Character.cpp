#include"Character.h"
#include"Difficult.h"
#include"Enemy.h"
#include"Battle.h"
#include<vector>
#include <algorithm>    
#include <iterator> 

std::vector<String> Character::property;			//持ち物
std::vector<String> Character::skills;				//スキル
bool Character::CharacterTurnFlag;					//キャラクターのターンかどうかのフラグ
bool Character::DefendFlag;							//防御のフラグ
int Character::CharacterHp;							//キャラクターのHP

Character::Character(void) {
	Select = new Audio(U"resource/musics/rpg_select.wav");
	Enter = new Audio(U"resource/musics/rpg_enter.wav");
	Back = new Audio(U"resource/musics/rpg_back.wav");
	select_Point_X = 90;
	select_Point_Y = 400;
	CharacterHp = 100;
	HP_Width = 200;
	HP_Max = CharacterHp;
	property = {U"回復草",U"回復薬"};
	skills = {U"for",U"printf",U"hidao"};
	FontAsset::Register(U"CharaF", 30);
	IntervalInitialize();
}

Character::~Character(void) {

}

void Character::update(void) {
	if (CharacterTurnFlag == true) {
		if (telopFlag == false) {
			if (skillFlag == true) {
				SkillSelect();
			}
			else if (propertyFlag == true) {
				PropertySelect();
			}
			else {
				SelectMenu();
			}
		}
		else {
			if (KeyZ.down()) {				//攻撃、防御、持ち物を選んだ時にここに分岐する
				IntervalInitialize();
				Character::OnCharacterFlag(false);
				Enemy::OnEnemyFlag(true);
				//敵のフラグをonにして敵のターンにする
			}
		}
	}
}

void Character::draw(void) {
	if (CharacterTurnFlag == true) {
		MenuDraw();
		(this->*Funcdraw)();
	}
}

void Character::ChangeDraw(DRAW now) {
	switch (now){
	case Character::NONE_DRAW:
		select_Point_X = 90;
		select_Point_Y = 400;
		Funcdraw = &Character::StatusDraw;
		nowdraw = NONE_DRAW;
		break;
	case Character::ATTACK_DRAW:
		select_Point_X = 530;
		select_Point_Y = 400;
		skillFlag = true;
		Funcdraw = &Character::SkillDraw;
		nowdraw = ATTACK_DRAW;
		break;
	case Character::DEFEND_DRAW:
		Funcdraw = &Character::DefendDraw;
		nowdraw = DEFEND_DRAW;
		break;
	case Character::PROPERTY_DRAW:
		select_Point_X = 530;
		select_Point_Y = 400;
		propertyFlag = true;
		Funcdraw = &Character::PropertyDraw;
		nowdraw = PROPERTY_DRAW;
		break;
	case Character::SEARCH_DRAW:
		Funcdraw = &Character::SearchDraw;
		nowdraw = SEARCH_DRAW;
		break;
	case Character::TELOP_DRAW:
		break;
	default:
		break;
	}
}

void Character::SwitchSelect(void) {
	switch (now_select){
	case 0:
		ChangeDraw(ATTACK_DRAW);
		now_select = 0;
		break;
	case 1:
		ChangeDraw(DEFEND_DRAW);
		now_select = 0;
		break;
	case 2:
		ChangeDraw(PROPERTY_DRAW);
		now_select = 0;
		break;
	case 3:
		ChangeDraw(SEARCH_DRAW);
		now_select = 0;
		break;
	default:
		break;
	}
}


void Character::GetProperty(String tool) {				//アイテムを拾う処理		
	property.push_back(tool);
}

void Character::MenuDraw(void) {			//攻撃、防御、持ち物、調べるの描画
	String menu[4] = { U"攻撃",U"防御",U"持ち物",U"調べる" };
	int menuY = 380;
	for (int i = 0; i < 4; i++) {
		FontAsset(U"CharaF")(menu[i]).draw(110, menuY);
		menuY += 50;
	}
}

void Character::SelectMenu(void) {				//攻撃、防御、持ち物、調べるの何を選択したのか
	if (KeyZ.down()) {
		Enter->play();
		SwitchSelect();
	}
	if (now_select <= 3 && now_select > 0 && KeyUp.down()) {
		Select->playOneShot();
		now_select--;
		select_Point_Y -= 50;
	}
	if (now_select >= 0 && now_select < 3 && KeyDown.down()) {
		Select->playOneShot();
		now_select++;
		select_Point_Y += 50;
	}
	
	Triangle(select_Point_X, select_Point_Y, 25, 6).draw();

}

void Character::SkillSelect(void) {				//skillの何を選択したのかを貰う処理
	if (KeyZ.down()) {
		Enter->play();
		telopFlag = true;
		nowdraw = TELOP_DRAW;
		Funcdraw = &Character::SkillsSwitch;
	}

	if (now_select <= skills.size() && now_select > 1 && KeyUp.down()) {
		Select->playOneShot();
		select_Point_Y -= 100;
		now_select -= 2;
	}
	if (now_select >= 0 && now_select+2 < skills.size() && KeyDown.down()) {
		Select->playOneShot();
		select_Point_Y += 100;
		now_select += 2;
	}
	if (now_select % 2 == 0 && now_select < skills.size()-1 && KeyRight.down()) {
		Select->playOneShot();
		select_Point_X += 200;
		now_select++;
	}
	if (now_select % 2 == 1 && now_select < skills.size() && KeyLeft.down()) {
		Select->playOneShot();
		select_Point_X -= 200;
		now_select--;
	}

	Triangle(select_Point_X,select_Point_Y,25,6).draw();
}

void Character::PropertySelect(void) {					//持ち物の何をもらってきたのかをもらってくる処理
	if (KeyZ.down()) {
		Enter->play();
		telopFlag = true;
		Funcdraw = &Character::PropertySwitch;
	}
	if (now_select <= property.size() && now_select > 1 && KeyUp.down()) {
		Select->playOneShot();
		select_Point_Y -= 100;
		now_select -= 2;
	}
	if (now_select >= 0 && now_select + 2 < property.size() && KeyDown.down()) {
		Select->playOneShot();
		select_Point_Y += 100;
		now_select += 2;
	}
	if (now_select % 2 == 0 && now_select < property.size()-1 && KeyRight.down()) {
		Select->playOneShot();
		select_Point_X += 200;
		now_select++;
	}
	if (now_select % 2 == 1 && now_select < property.size() && KeyLeft.down()) {
		Select->playOneShot();
		select_Point_X -= 200;
		now_select--;
	}

	Triangle(select_Point_X, select_Point_Y, 25, 6).draw();
}


void Character::StatusDraw(void) {				//キャラクターのステータスを描画する処理（TODO::まだ名前とSPをつけていない）
	Rect(600, 380, HP_Max, 30).draw(Palette::Red);
	Rect(600, 380, CharacterHp/HP_Max*HP_Width, 30).draw(Palette::Green);
	Rect(600, 380, HP_Width, 30).drawFrame(1);
	FontAsset(U"CharaF")(U"HP").draw(600, 370,Palette::Blue);
	FontAsset(U"CharaF")(Difficult::GetCharacterName()).draw(450, 380);
}

void Character::SkillDraw(void) {				//skillの描画
	if (KeyX.down()) {			//ステータス描画に戻る時効果音とnowselectを0に戻す
		skillFlag = false;
		Back->play();
		ChangeDraw(NONE_DRAW);
		now_select = 0;
	}
	int skillX = 550, skillY = 280;
	for (int i = 0; i < skills.size(); i++) {
		if (i % 2 == 0) {
			skillY += 100;
		}
		if (skillX == 550) {
			FontAsset(U"CharaF")(skills[i]).draw(skillX,skillY);
			skillX += 200;
		}
		else {
			FontAsset(U"CharaF")(skills[i]).draw(skillX,skillY);
			skillX -= 200;
		}
	}
}

void Character::DefendDraw(void) {				//防御の描画（ここはあまりすることがなかったので形だけ作った）
	telopFlag = true;
	FontAsset(U"CharaF")(Difficult::GetCharacterName(), U"は身構えた！！").draw(550,380);
	OnFlagDefend(true);
}

void Character::PropertyDraw(void) {				//キャラクターの持ち物を描画
	if (KeyX.down()) {			//ステータス描画に戻る時効果音とnowselectを0に戻す
		propertyFlag = false;
		Back->play();
		ChangeDraw(NONE_DRAW);
		now_select = 0;
	}
	int propertyX = 550, propertyY = 280;
	for (int i = 0; i < property.size(); i++) {
		if (i % 2 == 0) {
			propertyY += 100;
		}
		if (propertyX == 550) {
			FontAsset(U"CharaF")(property[i]).draw(propertyX, propertyY);
			propertyX += 200;
		}
		else {
			FontAsset(U"CharaF")(property[i]).draw(propertyX, propertyY);
			propertyX -= 200;
		}
	}
}

void Character::SearchDraw(void) {			//TODO::テキストデータか、CSVデータから敵の情報を取ってくる
	Enemy::PrintExplanation();
	if (KeyX.down()) {			//ステータス描画に戻る時効果音とnowselectを0に戻す（ここはいるのか？）
		Back->play();
		ChangeDraw(NONE_DRAW);
		now_select = 0;
	}

}

void Character::SkillsSwitch(void) {			//攻撃の種類（書く）
	if (skills[now_select] == U"for") {
		FontAsset(U"CharaF")(Difficult::GetCharacterName(),U"はfor文攻撃を行った！").draw(550, 380);
		FontAsset(U"CharaF")(U"敵名に三万のダメージ！！").draw(550, 420);
		Enemy::Damage(50);
	}
	if (skills[now_select] == U"print") {

	}

}

void Character::PropertySwitch(void) {			//持ち物の種類（効果などを書く）
	if (property[now_select]== U"回復草") {
		
	}
	if (property[now_select] == U"回復薬") {

	}
}


void Character::IntervalInitialize(void) {					//中間初期化（主にEnemyのターンからCharacterのターンになったら使う）
	telopFlag = false;
	skillFlag = false;
	propertyFlag = false;
	ChangeDraw(NONE_DRAW);
	now_select = 0;
}

void Character::OnCharacterFlag(bool now) {				//trueの時Characterのターン
	CharacterTurnFlag = now;
}

void Character::Damage(int damage) {					//Enemyで使うダメージをもらってくる処理
	if (DefendFlag == true) {
		CharacterHp -= damage / 2;
	}
	else {
		CharacterHp -= damage;
	}
	if (CharacterHp <= 0) {						//HPがゼロになればバトル終了
		Battle::OnFlagFinalized(false);
	}
}

void Character::OnFlagDefend(bool now) {
	DefendFlag = now;
}