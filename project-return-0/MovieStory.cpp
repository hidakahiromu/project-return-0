#include"SceneManager.h"
#include"MovieStory.h"


MovieStory::MovieStory(void) {

}

MovieStory::~MovieStory(void) {

}

void MovieStory::update(void) {
	if (KeyEnter.down()) {//RPG�o�g���ֈڍs
		SceneManager::SetNextScene(SceneManager::SCENE_BATTLE);
	}
}

void MovieStory::draw(void) {
	Print << U"�X�g�[���[�̃V�[���ł�";
}