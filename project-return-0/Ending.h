#pragma once
#include"Scene.h"
#include<Siv3D.hpp>

class Ending : public Scene {		//�G���f�B���O�̃N���X�iScene�N���X���p���j
public:
	Ending(void);				//����������
	~Ending(void);				//�J������
	void update(void);			//�v�Z�n����(Scene��update���I�[�o�[���C�h)
	void draw(void);			//�`��n����(Scene��draw���I�[�o�[���C�h)
private:
};