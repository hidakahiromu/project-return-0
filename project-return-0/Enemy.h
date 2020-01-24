#pragma once
#include<Siv3D.hpp>


class Enemy {
public:
	Enemy(void);
	~Enemy(void);
	void update(void);
	void draw(void);

	int attackpoint;		//enemyの攻撃値
	static bool damagehalf;


	static void OnEnemyFlag(bool next);				
	static void Damage(int damage);				
	static void SetEnemyStatus(int HP,String Explain1, String Explain2, String Explain3);	
	static void PrintExplanation(void);			
	static void GetEnemyName(String name);		
	static String SetEnemyName(void);			

protected:
	bool jobDetailsFlag;
	int enedisp;		//enemyのテキスト表示順
	virtual void jobDetails() = 0;			//ジョブごとの攻撃の詳細が書いてある関数
	virtual void jobDraw() = 0;					
	virtual void jobUpdate() = 0;				

private:
	static String enemyName;
	static int enemyHp;					
	static String explanation1, explanation2, explanation3;			
	static bool EnemyTurnFlag;			
};