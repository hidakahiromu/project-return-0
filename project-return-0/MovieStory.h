#pragma once
#include<Siv3D.hpp>
#include"Scene.h"

class MovieStory : public Scene {		//難易度選択のクラス（Sceneクラスを継承）
public:
	MovieStory(void);				//初期化処理
	~MovieStory(void);				//開放処理
	void update(void);			//計算系処理(Sceneのupdateをオーバーライド)
	void draw(void);			//描画系処理(Sceneのdrawをオーバーライド)
private:
};