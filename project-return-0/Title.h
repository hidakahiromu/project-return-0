#pragma once
#include"Scene.h"
#include<Siv3D.hpp>

class Title : public Scene {			//�^�C�g���̃N���X�iScene�N���X���p���j
	public:
		Title(void);					//�^�C�g���̏���������
		~Title(void);					//�^�C�g���̊J������
		void update(void);				//�^�C�g���̌v�Z�n����(Scene��update���I�[�o�[���C�h)
		void draw(void);				//�^�C�g���̕`��n����(Scene��draw���I�[�o�[���C�h)

	private:
		int selectBox;					//�{�^���Ǘ��p�̕ϐ�

		void boxDraw(void);				//�J�n�ƏI���̔��쐬
		void selectBoxEffect(void);		//�J�n�ƏI����I�������Ƃ��̃G�t�F�N�g

};