#pragma once
#include<Siv3D.hpp>
#include"Enemy.h"

class Abatte : public Enemy {				//第二章の敵、読み方はエーバット
public:
	Abatte();
	~Abatte();

private:
	int HP;						//jobごとのHP
	String Ex1, Ex2, Ex3;		//説明文1,2,3


	void jobDraw() final;
	void jobUpdate() final;
};