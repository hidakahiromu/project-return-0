#include"SceneManager.h"
#include"Difficult.h"
#include"Character.h"


Difficult::Difficult(void) {

}

Difficult::~Difficult(void) {

}

void Difficult::update(void) {
	if (KeyEnter.down()) {//�Q�[���ֈڍs
		SceneManager::SetNextScene(SceneManager::SCENE_GAME_ACTION);
	}
}

void Difficult::draw(void) {
	Print << U"��Փx�I����ʂł�";
}