#pragma once
#include"Scene.h"
#include<Siv3D.hpp>

class Difficult : public Scene {		//難易度選択のクラス（Sceneクラスを継承）
public:
	Difficult(void);				//初期化処理
	~Difficult(void);				//開放処理
	void update(void);			//計算系処理(Sceneのupdateをオーバーライド)
	void draw(void);			//描画系処理(Sceneのdrawをオーバーライド)

	
	static String GetCharacterName(void);
private:
	TextEditState tes1;
	void SetCharacterName(String text);
};