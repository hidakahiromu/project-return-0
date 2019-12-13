#pragma once
#include<Siv3D.hpp>
#include"Scene.h"

class GameAction : public Scene {		//アクションゲームのクラス（Sceneクラスを継承）
public:
	GameAction(void);				//初期化処理
	~GameAction(void);				//開放処理
	void update(void);			//計算系処理(Sceneのupdateをオーバーライド)
	void draw(void);			//描画系処理(Sceneのdrawをオーバーライド)
private:
};