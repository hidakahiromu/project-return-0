#pragma once
#include<Siv3D.hpp>
#include"Scene.h"

class Battle : public Scene {		//RPG�o�g���̃N���X�iScene�N���X���p���j
public:
	Battle(void);				//����������
	~Battle(void);				//�J������
	void update(void);			//�v�Z�n����(Scene��update���I�[�o�[���C�h)
	void draw(void);			//�`��n����(Scene��draw���I�[�o�[���C�h)
private:
};