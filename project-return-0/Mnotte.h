#pragma once
#include<Siv3D.hpp>
#include"Enemy.h"


class Mnotte : public Enemy {				//第一章の敵、読み方はモノット
public:
	Mnotte();
	~Mnotte();

private:
	int HP;						//jobごとのHP
	String Ex1, Ex2, Ex3;		//説明文1,2,3

	void jobDraw(void) final;
	void jobUpdate(void) final;
};