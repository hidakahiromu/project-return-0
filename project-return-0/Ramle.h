#pragma once
#include<Siv3D.hpp>
#include"Enemy.h"


class Ramle : public Enemy {				//第四章の敵、読み方はラムール
public:
	Ramle();
	~Ramle();

private:
	int HP;						//jobごとのHP
	String Ex1, Ex2, Ex3;		//説明文1,2,3

	void jobDraw(void) final;
	void jobUpdate(void) final;
};