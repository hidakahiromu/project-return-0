#pragma once
#include<Siv3D.hpp>


class Enemy {
public:
	Enemy(void);
	~Enemy(void);
	void update(void);
	void draw(void);
	static void OnEnemyFlag(bool next);			//Enemyのフラグ切り替え	
	static void Damage(int damage);				//Characterからダメージをもらってくる処理
	static void SetEnemyStatus(int HP,String Explain1, String Explain2, String Explain3);	//各ジョブからHPと説明文をもらってくる処理
	static void PrintExplanation(void);			//キャラクターで使う敵の情報を表示する機能

protected:				//継承用の関数とか
	virtual void jobDraw() = 0;					//EnemyJobsで定義する用のDraw
	virtual void jobUpdate() = 0;				//EnemyJobsで定義する用のUpdate

private:
	static int enemyHp;					//敵のHP
	static String explanation1, explanation2, explanation3;			//説明文一行目、二行目、三行目
	static bool EnemyTurnFlag;			//TRUEの時Enemyのターン


};