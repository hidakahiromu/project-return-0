#pragma once
#include"Scene.h"
#include<Siv3D.hpp>

class Difficult : public Scene {		//��Փx�I���̃N���X�iScene�N���X���p���j
public:
	Difficult(void);				//����������
	~Difficult(void);				//�J������
	void update(void);			//�v�Z�n����(Scene��update���I�[�o�[���C�h)
	void draw(void);			//�`��n����(Scene��draw���I�[�o�[���C�h)

	
	static String GetCharacterName(void);
private:
	TextEditState tes1;
	void SetCharacterName(String text);
};