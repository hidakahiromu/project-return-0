#pragma once
#include<Siv3D.hpp>
#include"Scene.h"

class Title : public Scene {		//�^�C�g���̃N���X�iScene�N���X���p���j
	public:
		Title(void);				//�^�C�g���̏���������
		~Title(void);				//�^�C�g���̊J������
		void update(void);			//�^�C�g���̌v�Z�n����(Scene��update���I�[�o�[���C�h)
		void draw(void);			//�^�C�g���̕`��n����(Scene��draw���I�[�o�[���C�h)
	private:
};