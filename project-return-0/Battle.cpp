#include"SceneManager.h"
#include"Battle.h"



Battle::Battle(void) {
	
}

Battle::~Battle(void) {

}

void Battle::update(void) {
	if (KeyEnter.down()) {//�G���f�B���O�ֈڍs
		SceneManager::SetNextScene(SceneManager::SCENE_ENDING);
	}
}

void Battle::draw(void) {
	Print << U"RPG�o�g����ʂł�";

}
