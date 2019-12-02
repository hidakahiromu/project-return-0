#include"SceneManager.h"
#include"Title.h"


Title::Title(void) {

}

Title::~Title(void) {

}

void Title::update(void) {
	if (KeyEnter.down()) {//難易度選択へ移行
		SceneManager::SetNextScene(SceneManager::SCENE_DIFFICULT);
	}
}

void Title::draw(void) {
	Print << U"タイトルです";
}