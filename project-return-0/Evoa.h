#pragma once
#include<Siv3D.hpp>
#include"Enemy.h"

class Evoa : public Enemy {				//�掵�͂̓G�A�ǂݕ��̓G�{�A
public:
	Evoa();
	~Evoa();

private:
	int HP;						//job���Ƃ�HP
	String Ex1, Ex2, Ex3;		//������1,2,3

	void jobDraw(void) final;
	void jobUpdate(void) final;
};