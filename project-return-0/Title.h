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
		int selectBox;					//ボタン管理用の変数

		void boxDraw(void);				//開始と終了の箱作成
		void selectBoxEffect(void);		//開始と終了を選択したときのエフェクト

};