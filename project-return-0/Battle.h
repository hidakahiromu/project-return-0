#pragma once
#include"Scene.h"
#include"Character.h"
#include<Siv3D.hpp>
#include<vector>
#include <algorithm>    
#include <iterator> 

class Battle : public Scene {		//RPGバトルのクラス（Sceneクラスを継承）
public:
	enum NOWDRAW {
		DRAW1,
		DRAW2,
	};
	Battle(void);				//初期化処理
	~Battle(void);				//開放処理
	void update(void);			//計算系処理(Sceneのupdateをオーバーライド)
	void draw(void);			//描画系処理(Sceneのdrawをオーバーライド)

private:
	int CharacterHP;			//キャラクターのHP
	int EnemyHP;				//敵のHP

	std::vector<String> nowproperty;
	NOWDRAW nowdraw;
	int coordinateX, coordinateY;			//描画開始位置のx座標とy座標
	int x, y;
	int frame1X,frame1Y;
	int frame2X, frame2Y;
	int nowselect;
	String menu[6];

	void (Battle::* FuncDraw)(void);
	void ChangeDraw(NOWDRAW next);
	void DrawCommand1(void);
	void PrintSelectMenu(void);
	void SelectMenu(void);
	void PrintFrame1(void);
	void PrintFrame2(void);
};