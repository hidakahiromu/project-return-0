#include"SceneManager.h"
#include"Ending.h"



Ending::Ending(void) {

}

Ending::~Ending(void) {

}

void Ending::update(void) {
	if (KeyEnter.down()) {//タイトルへ移行
		SceneManager::SetNextScene(SceneManager::SCENE_TITLE);
	}
}

void Ending::draw(void) {
	Print << U"エンディングです";
}