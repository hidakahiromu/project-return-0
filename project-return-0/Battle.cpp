#include"SceneManager.h"
#include"Battle.h"

bool Battle::WinFlagCharacter;
bool Battle::WinFlagEnemy;


Battle::Battle(Character* character, Enemy* enemy) {
	Cha = character;
	Ene = enemy;
	WinFlagCharacter = false;
	WinFlagEnemy = false;
	Character::OnCharacterFlag(true);
	Enemy::OnEnemyFlag(false);
	FontAsset::Register(U"FB",30);
	frame1X = -200, frame1Y = 350;
	frame2X = 520, frame2Y = 350;
}

Battle::~Battle(void) {

}

void Battle::update(void) {
	Cha->update();
	Ene->update();
	/*if(CharacterHP <= 0) {//エンディングへ移行
		SceneManager::SetNextScene(SceneManager::SCENE_ENDING);
	}
	SelectMenu();
	DecisionSelect();
	if (KeyA.down()) {				//テスト用Aボタンを押すと体力が減る
		CharacterHP -= 15;
	}*/
}

void Battle::draw(void) {
	Cha->draw();
	Ene->draw();
	PrintFrame1();
	PrintFrame2();
}




void Battle::PrintFrame1(void) {					//白枠を描く処理（左）
	if (frame1X != 50 && System::FrameCount() % 4 == 0) {
		frame1X += 50;
	}
	Rect(frame1X, frame1Y, 200, 300).drawFrame(3, Palette::White);
}

void Battle::PrintFrame2(void) {					//白枠を描く処理（右）
	if (frame2X != 270 && System::FrameCount() % 4 == 0) {
		frame2X -= 50;
	}
	Rect(frame2X, frame2Y, 960, 300).drawFrame(3, Palette::White);
}

void Battle::OnFlagFinalized(bool end) {			//TRUEならキャラクターの勝ち、FALSEなら敵の勝ち
	if (end == true) {
		WinFlagCharacter = true;
	}
	else {
		WinFlagEnemy = true;
	}
}