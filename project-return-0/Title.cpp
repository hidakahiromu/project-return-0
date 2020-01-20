#include"SceneManager.h"
#include"Title.h"

//ToDo::‚r‚d‚Æ‰æ‘œ“\‚è•t‚¯‚é‚¾‚¯

Title::Title(void) {
	startFlag = false;
	endFlag = false;
	TextureAsset::Register(U"title_back", U"resource/images/title_back2.png");
	TextureAsset::Register(U"title_start_button1", U"resource/images/title_button.png");
	TextureAsset::Register(U"title_start_button2", U"resource/images/title_button1.png");
	TextureAsset::Register(U"title_end_button1", U"resource/images/title_button_end.png");
	TextureAsset::Register(U"title_end_button2", U"resource/images/title_button_end2.png");
	title_BGM = new Audio(U"resource/musics/famipop.wav");
	title_BGM->setLoop(true);
	title_BGM->play();
}

Title::~Title(void) {
	TextureAsset::Unregister(U"title_back");
	TextureAsset::Unregister(U"title_start_button1");
	TextureAsset::Unregister(U"title_start_button2");
	TextureAsset::Unregister(U"title_end_button1");
	TextureAsset::Unregister(U"title_end_button2");
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
	TextureAsset(U"title_back").draw();
	TextureAsset(U"title_start_button1").draw(450, 350);
	TextureAsset(U"title_end_button1").draw(450, 550);
	NowSelect();
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

void Title::NowSelect(void) {		
	if (startFlag == true) {
		TextureAsset(U"title_start_button2").draw(450, 350);
	}
	if (endFlag == true) {
		TextureAsset(U"title_end_button2").draw(450, 550);
	}
}