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
	static int NowHp(void);						//キャラクターの今のHPを取ってくる処理
	static void GetHp(int nexthp);					//バトルが終わった後のHPを取ってくる処理
	static void GetProperty(String tool);		//キャラクターがアイテムを拾う処理
	static void NowProperty(std::vector<String> &tool);
private:

	

};