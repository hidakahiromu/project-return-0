#include"SceneManager.h"
#include"Title.h"


#define X 500				//�{�b�N�X��X���W
#define Y 300				//�{�b�N�X��Y���W
#define W 200				//�{�b�N�X�̕�
#define H 50				//�{�b�N�X�̍���


Title::Title(void) {
	selectBox = 0;
}

Title::~Title(void) {

}

void Title::update(void){
	selectBoxEffect();
	if (selectBox == 1 && KeyEnter.down()) {
		SceneManager::SetNextScene(SceneManager::SCENE_DIFFICULT);
	}
}

void Title::draw(void) {
	Print << U"�^�C�g���ł�";
	boxDraw();
}

void Title::boxDraw(void) {
	Rect(X,Y,W,H).draw(Palette::White);
	Rect(X, Y+150, W, H).draw(Palette::White);
	if (selectBox == 1) {
		Rect(X, Y, W, H).draw(Palette::Red);
	}
	if (selectBox == 2) {
		Rect(X, Y+150, W, H).draw(Palette::Red);
	}
}

void Title::selectBoxEffect(void) {
	if (selectBox != 1 && KeyUp.down()) {
		selectBox = 1;
	}
	if (selectBox != 2 && KeyDown.down()) {
		selectBox = 2;
	}
}