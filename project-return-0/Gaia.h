#pragma once
#include<Siv3D.hpp>
#include"Enemy.h"


class Gaia : public Enemy {				//‘æ˜ZÍ‚Ì“GA“Ç‚İ•û‚ÍƒKƒCƒA
public:
	Gaia();
	~Gaia();

private:
	int HP;						//job‚²‚Æ‚ÌHP
	String Ex1, Ex2, Ex3;		//à–¾•¶1,2,3

	void jobDraw(void) final;
	void jobUpdate(void) final;
};