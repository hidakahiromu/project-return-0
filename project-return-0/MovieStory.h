#pragma once
#include<Siv3D.hpp>
#include"Scene.h"

class MovieStory : public Scene {		//��Փx�I���̃N���X�iScene�N���X���p���j
public:
	MovieStory(void);				//����������
	~MovieStory(void);				//�J������
	void update(void);			//�v�Z�n����(Scene��update���I�[�o�[���C�h)
	void draw(void);			//�`��n����(Scene��draw���I�[�o�[���C�h)
private:
};