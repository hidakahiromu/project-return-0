#pragma once
#include<Siv3D.hpp>
#include<vector>
#include <algorithm>    
#include <iterator> 

class Character {
public:
	Character(void);
	~Character(void);
	static void update(void);
	static void draw(void);
	static int SetHp(void);						//キャラクターの今のHPを渡す処理
	static void GetHp(int nexthp);					//バトルが終わった後のHPを取ってくる処理
	static void GetProperty(String tool);		//キャラクターがアイテムを拾う処理
	static void SetProperty(std::vector<String> &tool);				//キャラクターの道具を渡す処理
	static void GetTool(std::vector<String> &tool);					//バトルが終わったあと、今の持ち物をもらってくる処理
	static void SetSkills(std::vector<String> &skill);						//スキルを渡す処理
	static void GetSkills(std::vector<String>& skill);						//スキルを貰う処理

private:
	static int characterHp;										//キャラクターのHP
	static std::vector<String> property;						//キャラクターの持ち物
	static std::vector<String> skills;							//キャラクターのスキル
};