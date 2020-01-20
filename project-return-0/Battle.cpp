#include"SceneManager.h"
#include"Battle.h"
#include"Character.h"
#include"Enemy.h"
#include<vector>
#include"Mnotte.h"
#include"Abatte.h"
#include"Totem.h"
#include"Ramle.h"
#include"Warp.h"
#include"Gaia.h"
#include"Evoa.h"

bool Battle::WinFlagCharacter;
bool Battle::WinFlagEnemy;

int Battle::NowEnemyCount = 0;


Battle::Battle(void) {
	NowEnemyCount++;
	ChangeEnemy(NowEnemyCount);
	Cha = new Character();
	WinFlagCharacter = false;
	WinFlagEnemy = false;
	Character::turncount = 0;
	Character::OnCharacterFlag(true);
	Enemy::OnEnemyFlag(false);
	FontAsset::Register(U"FB",30);
	frame1X = -200, frame1Y = 350;
	frame2X = 520, frame2Y = 350;
}

Battle::~Battle(void) {
	TextureAsset::UnregisterAll();
	delete Ene;
	delete Cha;
}

void Battle::update(void) {
	if (KeyA.down()) {
		SceneManager::SetNextScene(SceneManager::SCENE_MOVIE_STORY);
	}
	TextureAsset(U"battle_back").draw();
	if (Enemy::SetEnemyName() == U"エーバット") {
		TextureAsset(Enemy::SetEnemyName()).draw(400, 0);
	}
	else if(Enemy::SetEnemyName() != U"EVOA" && Enemy::SetEnemyName() != U"モノット"){
		TextureAsset(Enemy::SetEnemyName()).draw(400, 100);
	}
	else{
		TextureAsset(Enemy::SetEnemyName()).draw(200, 100);
	}
	PrintFrame1();
	PrintFrame2();
	Cha->update();
	Ene->update();


	if(WinFlagCharacter == true || WinFlagEnemy == true) {			//どちらかの体力がなくなり、フラグがたったらエンディングへ移行
		//SceneManager::SetNextScene(SceneManager::SCENE_ENDING);
	}
}

void Battle::draw(void) {
	Cha->draw();
	Ene->draw();
}




void Battle::PrintFrame1(void) {					//白枠を描く処理（左）
	if (frame1X != 50 && System::FrameCount() % 4 == 0) {
		frame1X += 50;
	}
	Rect(frame1X, frame1Y, 200, 300).draw(Palette::Black);
	Rect(frame1X, frame1Y, 200, 300).drawFrame(3, Palette::White);
}

void Battle::PrintFrame2(void) {					//白枠を描く処理（右）
	if (frame2X != 270 && System::FrameCount() % 4 == 0) {
		frame2X -= 50;
	}
	Rect(frame2X, frame2Y, 960, 300).draw(Palette::Black);
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

void Battle::ChangeEnemy(int count) {
	switch (count){
	case 1:
		Ene = new Evoa();
		TextureAsset::Register(U"battle_back", U"resource/images/sougen2_yoru.png");
		TextureAsset::Register(U"EVOA", U"resource/images/character/EVOA_big.png");
		break;
	case 2:
		Ene = new Mnotte();
		TextureAsset::Register(U"battle_back", U"resource/images/doukutu1.png");
		TextureAsset::Register(U"モノット", U"resource/images/character/monoto_big.png");
		break;
	case 3:
		Ene = new Abatte();
		TextureAsset::Register(U"battle_back", U"resource/images/doukutu2.png");
		TextureAsset::Register(U"エーバット", U"resource/images/character/ebato_big.png");
		break;
	case 4:
		Ene = new Totem();
		TextureAsset::Register(U"battle_back", U"resource/images/hana_yoru.png");
		TextureAsset::Register(U"トーテム", U"resource/images/character/totemu_big.png");
		break;
	case 5:
		Ene = new Ramle();
		TextureAsset::Register(U"battle_back", U"resource/images/hana_yoru.png");
		TextureAsset::Register(U"ラムール", U"resource/images/character/ramuru_big.png");
		break;
	case 6:
		Ene = new Warp();
		TextureAsset::Register(U"battle_back", U"resource/images/sougen1_yorujpg.png");
		TextureAsset::Register(U"ワーフ", U"resource/images/character/wahu_big.png");
		break;
	case 7:
		Ene = new Gaia();
		TextureAsset::Register(U"battle_back", U"resource/images/taizyu_yoru.png");
		TextureAsset::Register(U"ガイア", U"resource/images/character/gaia_big.png");
		break;
	case 8:
		Ene = new Evoa();
		TextureAsset::Register(U"battle_back", U"resource/images/sougen2_yoru.png");
		TextureAsset::Register(U"EVOA", U"resource/images/character/EVOA_big.png");
		break;
	case 9:
		Ene = new Evoa();
		TextureAsset::Register(U"battle_back", U"resource/images/sougen2_asa.png");
		TextureAsset::Register(U"EVOA", U"resource/images/character/EVOA_big.png");
		break;
	default:
		break;
	}
}