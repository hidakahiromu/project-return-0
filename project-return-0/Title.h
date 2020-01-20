#pragma once
#include"Scene.h"
#include<Siv3D.hpp>

class Title : public Scene {			//タイトルのクラス（Sceneクラスを継承）
	public:
		Title(void);					//タイトルの初期化処理
		~Title(void);					//タイトルの開放処理
		void update(void);				//タイトルの計算系処理(Sceneのupdateをオーバーライド)
		void draw(void);				//タイトルの描画系処理(Sceneのdrawをオーバーライド)

	private:
		Audio* title_BGM;
		bool startFlag, endFlag;		//スタートか終了のどちらを選択しているのかを管理するフラグ
		void NowSelect(void);			//スタートか終了のどちらを選択しているのか表示
		void NowFlag(void);				//スタートか終了のどちらのフラグがたっているのか管理する関数

};