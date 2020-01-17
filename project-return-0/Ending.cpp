#include"SceneManager.h"
#include"Ending.h"



Ending::Ending(void) {
	end.load(U"resource/story/ending.csv");
	for (int i = 0; i < end.rows(); i++) {
		endRoll.push_back(end.get(i,0));
	}
	FontAsset::Register(U"EndF",30);
	end_BGM = new Audio(U"resource/musics/retrogamecenter.wav");
	end_BGM->setLoop(true);
	end_BGM->play();
	csvY = 720;
}

Ending::~Ending(void) {
	delete end_BGM;
}

void Ending::update(void) {
	if (KeyEnter.down()) {//タイトルへ移行
		SceneManager::SetNextScene(SceneManager::SCENE_TITLE);
	}
}

void Ending::draw(void) {
	DrawCSV();
}

void Ending::DrawCSV(void) {
	for (int j = 0; j < end.rows(); j++) {
		FontAsset(U"EndF")(endRoll[j]).draw(100,csvY + (j*50));
	}
	csvY--;
}