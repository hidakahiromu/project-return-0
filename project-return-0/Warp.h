#pragma once
#include<Siv3D.hpp>
#include"Enemy.h"


class Warp : public Enemy {				//��܏͂̓G�A�ǂݕ��̓��[�t
public:
	Warp();
	~Warp();
	static int count;
private:
	int HP;						//job���Ƃ�HP
	String Ex1, Ex2, Ex3;		//������1,2,3

	void jobDraw(void) final;
	void jobUpdate(void) final;
};