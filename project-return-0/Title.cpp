#include"SceneManager.h"
#include"Title.h"


Title::Title(void) {

}

Title::~Title(void) {

}

void Title::update(void) {
	if (KeyEnter.down()) {//��Փx�I���ֈڍs
		SceneManager::SetNextScene(SceneManager::SCENE_DIFFICULT);
	}
}

void Title::draw(void) {
	Print << U"�^�C�g���ł�";
}