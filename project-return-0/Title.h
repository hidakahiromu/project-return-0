#pragma once
#include<Siv3D.hpp>
#include"Scene.h"

class Title : public Scene {		//タイトルのクラス（Sceneクラスを継承）
	public:
		Title(void);				//タイトルの初期化処理
		~Title(void);				//タイトルの開放処理
		void update(void);			//タイトルの計算系処理(Sceneのupdateをオーバーライド)
		void draw(void);			//タイトルの描画系処理(Sceneのdrawをオーバーライド)
	private:
};