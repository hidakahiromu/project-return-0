#pragma once
#include"Scene.h"
#include<Siv3D.hpp>

class Ending : public Scene {		//エンディングのクラス（Sceneクラスを継承）
public:
	Ending(void);				//初期化処理
	~Ending(void);				//開放処理
	void update(void);			//計算系処理(Sceneのupdateをオーバーライド)
	void draw(void);			//描画系処理(Sceneのdrawをオーバーライド)
private:
};