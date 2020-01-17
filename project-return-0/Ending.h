#pragma once
#include"Scene.h"
#include<Siv3D.hpp>
#include<vector>

class Ending : public Scene {		//�G���f�B���O�̃N���X�iScene�N���X���p���j
public:
	Ending(void);				//����������
	~Ending(void);				//�J������
	void update(void);			//�v�Z�n����(Scene��update���I�[�o�[���C�h)
	void draw(void);			//�`��n����(Scene��draw���I�[�o�[���C�h)
private:
	void DrawCSV(void);			//CSV�̕`��

	std::vector<String> endRoll;		//CSV�f�[�^�����邽�߂�String�^
	CSVData end;
	Audio* end_BGM;
	int csvY;			//csv�`��̎���Y���W


};