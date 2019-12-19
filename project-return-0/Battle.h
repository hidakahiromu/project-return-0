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
	enum NOWDRAW {
		NONE_SELECT,				//何も選択していないとき
		ATTACK_SELECT,				//攻撃を選択したとき
		DEFEND_SELECT,				//防御を選択したとき
		TOOL_SELECT,				//持ち物を選択したとき
		SEARCH_SELECT,				//調べるを選択したとき
	};
	Battle(void);				//初期化処理
	~Battle(void);				//開放処理
	void update(void);			//計算系処理(Sceneのupdateをオーバーライド)
	void draw(void);			//描画系処理(Sceneのdrawをオーバーライド)

private:
	double CharacterHP,FixHpC;			//（左から）キャラクターのHP、HPバーの固定用キャラクターのHP
	double EnemyHP,FixHpE;				//（左から）敵のHP、HPバーの固定用敵のHP

	String menu[4];							//攻撃、防御、持ち物、調べる
	std::vector<String> nowproperty;		//キャラクターの持ち物
	std::vector<String> nowskills;			//キャラクターのスキル
	NOWDRAW nowdraw;						//今何の選択画面を選んでいるのか
	int coordinateX, coordinateY;			//描画開始位置のx座標とy座標
	int frame1X, frame1Y;					//選択画面の白枠のX座標とY座標
	int frame2X, frame2Y;					//↑と同じ
	//int skillX, skillY;						//スキル表示のX座標とY座標
	//int toolX, toolY;
	int x, y;
	int nowselect;

	void (Battle::* FuncDraw)(void);			//drawの関数ポインタ
	void ChangeDraw(NOWDRAW nextdraw);				
	void DecisionSelect(void);					//何のコマンド（攻撃とか防御）を選択したか
	void SelectMenu(void);							
	void PrintSelectMenu(void);					//左下の攻撃、防御、持ち物、調べるを描画する
	void StatusPrint(void);						//キャラクターのステータス表示処理
	void SkillPrint(void);						//キャラクターのスキル描画
	void DefendPrint(void);						//防御の時のdraw
	void ToolPrint(void);						//持ち物（道具）の描画
	void SearchPrint(void);						//調べるを選択したときに相手の情報を描画する処理
	void PrintFrame1(void);	
	void PrintFrame2(void);
};