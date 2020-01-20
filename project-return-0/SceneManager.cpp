#include"SceneManager.h"

Scene* SceneManager::scene;
SceneManager::SCENE SceneManager::nowscene;
SceneManager::SCENE SceneManager::nextscene;

void SceneManager::initialize() {
	scene = new Title();
}

void SceneManager::finalize() {

}

void SceneManager::sceneUpdate() {
	if (nowscene != nextscene) {
		ChangeScene();
	}
	scene->update();
}

void SceneManager::sceneDraw() {
	scene->draw();
}

void SceneManager::SetNextScene(SCENE next) {
	nextscene = next;
}

void SceneManager::ChangeScene() {
	switch (nextscene){
	case SCENE_TITLE:
		delete scene;
		scene = new Title();
		break;

	case SCENE_DIFFICULT:
		delete scene;
		scene = new Difficult();
		break;

	case SCENE_MOVIE_STORY:
		delete scene;
		scene = new MovieStory();
		break;

	case SCENE_BATTLE:
		delete scene;
		scene = new Battle();
		break;

	case SCENE_ENDING:
		delete scene;
		scene = new Ending();
		break;

	default:
		break;
	}
	nowscene = nextscene;
}
