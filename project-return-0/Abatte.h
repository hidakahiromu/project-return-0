#pragma once
#include<Siv3D.hpp>
#include"Enemy.h"

class Abatte : public Enemy {				//���͂̓G�A�ǂݕ��̓G�[�o�b�g
public:
	Abatte();
	~Abatte();

private:
	int HP;						//job���Ƃ�HP
	String Ex1, Ex2, Ex3;		//������1,2,3


	void jobDraw() final;
	void jobUpdate() final;
};