#pragma once
#include<Siv3D.hpp>
#include"Enemy.h"


class Totem : public Enemy {				//��O�͂̓G�A�ǂݕ��̓g�[�e��
public:
	Totem();
	~Totem();

private:
	int HP;						//job���Ƃ�HP
	String Ex1, Ex2, Ex3;		//������1,2,3

	void jobDraw(void) final;
	void jobUpdate(void) final;
};