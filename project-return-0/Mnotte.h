#pragma once
#include<Siv3D.hpp>
#include"Enemy.h"


class Mnotte : public Enemy {				//���͂̓G�A�ǂݕ��̓��m�b�g
public:
	Mnotte();
	~Mnotte();

private:
	int HP;						//job���Ƃ�HP
	String Ex1, Ex2, Ex3;		//������1,2,3

	void jobDraw(void) final;
	void jobUpdate(void) final;
};