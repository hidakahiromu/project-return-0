#pragma once
#include<Siv3D.hpp>
#include"Enemy.h"


class Warp : public Enemy {				//第五章の敵、読み方はワーフ
public:
	Warp();
	~Warp();
	static int count;
private:
	int HP;						//jobごとのHP
	String Ex1, Ex2, Ex3;		//説明文1,2,3

	void jobDraw(void) final;
	void jobUpdate(void) final;
};