#pragma once
#include<Siv3D.hpp>
#include"Enemy.h"


class Ramle : public Enemy {				//��l�͂̓G�A�ǂݕ��̓����[��
public:
	Ramle();
	~Ramle();

private:
	int HP;						//job���Ƃ�HP
	String Ex1, Ex2, Ex3;		//������1,2,3

	void jobDraw(void) final;
	void jobUpdate(void) final;
};