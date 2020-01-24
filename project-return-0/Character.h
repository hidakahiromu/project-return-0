#pragma once
#include<Siv3D.hpp>


class Character {
public:
	enum DRAW {				//各値ごとに描画するもの
		NONE_DRAW,					//ステータスを描画
		ATTACK_DRAW,				//スキルを描画
		DEFEND_DRAW,				//防御の時のアクションを描画？
		PROPERTY_DRAW,				//持ち物を描画
		SEARCH_DRAW,				//相手（敵）の情報を描画
		TELOP_DRAW,					//攻撃、防御、持ち物の中の何かを選択したときに表示するテロップ
	};
	Character(void);
	~Character(void);
	void update(void);
	void draw(void);
	static void GetProperty(String tool);		//キャラクターがアイテムを拾う処理
	static void Damage(int damage);				//Enemyからダメージをもらってくる処理
	static void OnCharacterFlag(bool now);			//キャラクターのターンかどうか
	static void OnFlagDefend(bool now);					//防御のフラグ（TRUEならdamageを減らす）
	
	void IntervalInitialize(void);		//EnemyのターンからCharacterのターンになったときの初期化（中間初期化）
	void ChangeDraw(DRAW now);					//
	void (Character::* Funcdraw)(void);			
	void MenuDraw(void);						//
	void SelectMenu(void);						//攻撃、防御、持ち物、調べるを選択する三角形
	void SkillSelect(void);						//スキルの選択
	void PropertySelect(void);					//持ち物の選択
	void SwitchSelect(void);
	void StatusDraw(void);						//キャラクターのステータスを描画
	void SkillDraw(void);						//キャラクターのスキルを描画
	void DefendDraw(void);						//TODO::防御の時の描画
	void PropertyDraw(void);					//キャラクターの持ち物を描画
	void SearchDraw(void);						//敵の情報を表示
	void SkillsSwitch(void);					//攻撃の種類（スキル）分岐
	void PropertySwitch(void);					//道具（持ち物）の効果分岐

	static int turncount;						//現在のターン数
	static bool counterflg;							//skill"scanf"で参照

private:
	Audio *Select, *Enter, *Back;
	int now_select;						//攻撃、防御、持ち物、調べるの何を押したのかを判定するための変数
	int select_Point_X,select_Point_Y;					//選択したときの三角形描画のX座標とY座標の起点
	bool skillFlag;						//攻撃を選択したときTRUE
	bool propertyFlag;					//持ち物を選択したときTRUE
	bool telopFlag;						//テロップを描画するときに操作できなくするようにするためのフラグ
	bool DetailsFlag;					//スキルや持ち物を使用したときに何回も計算しないようにするためのフラグ

	int attacktimes;

	DRAW nowdraw;
	double HP,HP_Width,HP_Max;					//（左から）キャラクターのHPとゲージの幅と今のHPのフル
	static std::vector<String> property;						//キャラクターの持ち物
	static std::vector<String> skills;							//キャラクターのスキル
	static int CharacterHp;										//キャラクターのHP
	static bool CharacterTurnFlag;									//キャラクターのターンの時TRUE
	static bool DefendFlag;								//防御用のフラグ
	int attackpoint;				//与ダメージ量
};