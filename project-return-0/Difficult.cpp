#include"SceneManager.h"
#include"Difficult.h"
#include"Character.h"


Difficult::Difficult(void) {

}

Difficult::~Difficult(void) {

}

void Difficult::update(void) {
	if (KeyEnter.down()) {//ゲームへ移行
		SceneManager::SetNextScene(SceneManager::SCENE_GAME_ACTION);
	}
}

void Difficult::draw(void) {
	Print << U"難易度選択画面です";
}