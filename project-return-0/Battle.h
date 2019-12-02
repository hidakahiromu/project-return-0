#pragma once
#include<Siv3D.hpp>
#include"Scene.h"

class Battle : public Scene {		//RPGバトルのクラス（Sceneクラスを継承）
public:
	Battle(void);				//初期化処理
	~Battle(void);				//開放処理
	void update(void);			//計算系処理(Sceneのupdateをオーバーライド)
	void draw(void);			//描画系処理(Sceneのdrawをオーバーライド)
private:
};