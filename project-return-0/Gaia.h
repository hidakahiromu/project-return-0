#pragma once
#include<Siv3D.hpp>
#include"Enemy.h"


class Gaia : public Enemy {				//��Z�͂̓G�A�ǂݕ��̓K�C�A
public:
	Gaia();
	~Gaia();

private:
	int HP;						//job���Ƃ�HP
	String Ex1, Ex2, Ex3;		//������1,2,3

	void jobDraw(void) final;
	void jobUpdate(void) final;
};