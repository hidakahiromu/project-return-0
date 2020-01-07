#pragma once
#include"Scene.h"
#include"Character.h"
#include"Enemy.h"
#include<Siv3D.hpp>
#include<vector>
#include <algorithm>    
#include <iterator> 

class Battle : public Scene {		//RPGバトルのクラス（Sceneクラスを継承）
public:
	Battle(Character* character,Enemy* enemy);				//初期化処理
	~Battle(void);				//開放処理
	void update(void);			//計算系処理(Sceneのupdateをオーバーライド)
	void draw(void);			//描画系処理(Sceneのdrawをオーバーライド)
	static void OnFlagFinalized(bool end);			//trueが呼ばれるとキャラクターの勝利、falseで敵の勝利
	

private:
	class Character* Cha;
	class Enemy* Ene;

	static bool WinFlagCharacter;			//キャラクターが勝った時のフラグ
	static bool WinFlagEnemy;				//敵が勝った時のフラグ


	int frame1X, frame1Y;					//選択画面の白枠のX座標とY座標
	int frame2X, frame2Y;					//↑と同じ
	
	void (Battle::* FuncDraw)(void);
	void PrintFrame1(void);	
	void PrintFrame2(void);

};