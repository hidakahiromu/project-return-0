#pragma once
class Character;
class Enemy;
#include<Siv3D.hpp>
#include"Scene.h"


class Battle : public Scene {		//RPGバトルのクラス（Sceneクラスを継承）
public:
	Battle();				//初期化処理
	~Battle(void);				//開放処理
	void update(void);			//計算系処理(Sceneのupdateをオーバーライド)
	void draw(void);			//描画系処理(Sceneのdrawをオーバーライド)
	static void OnFlagFinalized(bool end);			//trueが呼ばれるとキャラクターの勝利、falseで敵の勝利
	static int SetEnemyCount(void);					//今の敵は何体目なのかを取ってくる処理

	void ChangeEnemy(int count);			//敵の生成

private:
	class Character* Cha;
	class Enemy* Ene;

	static bool WinFlagCharacter;			//キャラクターが勝った時のフラグ
	static bool WinFlagEnemy;				//敵が勝った時のフラグ
	static int NowEnemyCount;				//今何章目の敵なのか


	int frame1X, frame1Y;					//選択画面の白枠のX座標とY座標
	int frame2X, frame2Y;					//↑と同じ
	//String enemyName;						//敵の名前
	
	void (Battle::* FuncDraw)(void);
	void PrintFrame1(void);	
	void PrintFrame2(void);
	void CharacterWinScene(void);
	void EnemyWinScene(void);

};