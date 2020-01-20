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
		Audio* title_BGM;
		bool startFlag, endFlag;		//�X�^�[�g���I���̂ǂ����I�����Ă���̂����Ǘ�����t���O
		void NowSelect(void);			//�X�^�[�g���I���̂ǂ����I�����Ă���̂��\��
		void NowFlag(void);				//�X�^�[�g���I���̂ǂ���̃t���O�������Ă���̂��Ǘ�����֐�

};