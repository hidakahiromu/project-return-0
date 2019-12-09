#include"SceneManager.h"
#include"Battle.h"



Battle::Battle(void) {
	
}

Battle::~Battle(void) {

}

void Battle::update(void) {
	if (KeyEnter.down()) {//エンディングへ移行
		SceneManager::SetNextScene(SceneManager::SCENE_ENDING);
	}
}

void Battle::draw(void) {
	Print << U"RPGバトル画面です";

}
