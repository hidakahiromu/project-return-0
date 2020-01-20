#include"SceneManager.h"
#include"Title.h"

//ToDo::ÇrÇdÇ∆âÊëúì\ÇËïtÇØÇÈÇæÇØ

Title::Title(void) {
	startFlag = false;
	endFlag = false;
	title_BGM = new Audio(U"resource/musics/famipop.wav");
	title_BGM->setLoop(true);
	title_BGM->play();
}

Title::~Title(void) {
	delete title_BGM;
}

void Title::update(void){
	NowFlag();
	if (startFlag == true && (KeyZ.down() | KeyEnter.down() | KeySpace.down())) {
		SceneManager::SetNextScene(SceneManager::SCENE_DIFFICULT);
	}

	if (endFlag == true && (KeyZ.down() | KeyEnter.down() | KeySpace.down())) {
		System::Exit();
	}
}

void Title::draw(void) {
	NowSelectTriangle();
}

void Title::NowFlag(void) {
	if (startFlag == false && KeyUp.down()) {
		startFlag = true;
		endFlag = false;
	}
	if (endFlag == false && KeyDown.down()) {
		startFlag = false;
		endFlag = true;
	}
}

void Title::NowSelectTriangle(void) {			//ToDo::Çxç¿ïWÇ‡Ç§ÇøÇÂÇ¡Ç∆â∫
	if (startFlag == true) {
		Triangle(500, 300, 25, 6).draw();
	}
	if (endFlag == true) {
		Triangle(500, 400, 25, 6).draw();
	}
}