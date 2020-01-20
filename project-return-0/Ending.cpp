#include"SceneManager.h"
#include"Ending.h"



Ending::Ending(void) {
	end.load(U"resource/story/ending.csv");
	for (int i = 0; i < end.rows(); i++) {
		endRoll.push_back(end.get(i,0));
	}
	FontAsset::Register(U"EndF",30);
	TextureAsset::Register(U"ending_back",U"resource/images/ending_back.png");
	end_BGM = new Audio(U"resource/musics/retrogamecenter.wav");
	end_BGM->setLoop(true);
	end_BGM->play();
	csvY = 720;
}

Ending::~Ending(void) {
	delete end_BGM;
	
}

void Ending::update(void) {
	if (KeyEnter.down()) {						//エンターキーでもタイトルへ移行
		SceneManager::SetNextScene(SceneManager::SCENE_TITLE);
	}
	if ((csvY + (end.rows() * 50) )  ==  -50) {			//最後の行がＹ座標の-50に行けば自動的にタイトルに移動
		SceneManager::SetNextScene(SceneManager::SCENE_TITLE);
	}
}

void Ending::draw(void) {
	TextureAsset(U"ending_back").draw();
	DrawCSV();
	Print << U"Enterキーでスキップ";
}

void Ending::DrawCSV(void) {
	for (int j = 0; j < end.rows(); j++) {
		FontAsset(U"EndF")(endRoll[j]).draw(200,csvY + (j*50),Palette::Black);
	}
	csvY--;
}