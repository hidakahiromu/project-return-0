#include"SceneManager.h"
#include"GameAction.h"


GameAction::GameAction(void) {

}

GameAction::~GameAction(void) {

}

void GameAction::update(void) {
	if (KeyEnter.down()) {//�X�g�[���[���[�r�[�ֈڍs
		SceneManager::SetNextScene(SceneManager::SCENE_MOVIE_STORY);
	}
}

void GameAction::draw(void) {
	Print << U"�A�N�V�����Q�[���ł�";
}