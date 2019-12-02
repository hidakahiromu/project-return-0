#include"SceneManager.h"
#include"GameAction.h"


GameAction::GameAction(void) {

}

GameAction::~GameAction(void) {

}

void GameAction::update(void) {
	if (KeyEnter.down()) {//ストーリームービーへ移行
		SceneManager::SetNextScene(SceneManager::SCENE_MOVIE_STORY);
	}
}

void GameAction::draw(void) {
	Print << U"アクションゲームです";
}