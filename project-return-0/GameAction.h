#pragma once
#include<Siv3D.hpp>
#include"Scene.h"

class GameAction : public Scene {		//�A�N�V�����Q�[���̃N���X�iScene�N���X���p���j
public:
	GameAction(void);				//����������
	~GameAction(void);				//�J������
	void update(void);			//�v�Z�n����(Scene��update���I�[�o�[���C�h)
	void draw(void);			//�`��n����(Scene��draw���I�[�o�[���C�h)
private:
};