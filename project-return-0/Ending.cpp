#include"SceneManager.h"
#include"Ending.h"



Ending::Ending(void) {

}

Ending::~Ending(void) {

}

void Ending::update(void) {
	if (KeyEnter.down()) {//�^�C�g���ֈڍs
		SceneManager::SetNextScene(SceneManager::SCENE_TITLE);
	}
}

void Ending::draw(void) {
	Print << U"�G���f�B���O�ł�";
}