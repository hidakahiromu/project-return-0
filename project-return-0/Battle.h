#pragma once
#include"Scene.h"
#include"Character.h"
#include<Siv3D.hpp>
#include<vector>
#include <algorithm>    
#include <iterator> 

class Battle : public Scene {		//RPG�o�g���̃N���X�iScene�N���X���p���j
public:
	enum NOWDRAW {
		DRAW1,
		DRAW2,
	};
	Battle(void);				//����������
	~Battle(void);				//�J������
	void update(void);			//�v�Z�n����(Scene��update���I�[�o�[���C�h)
	void draw(void);			//�`��n����(Scene��draw���I�[�o�[���C�h)

private:
	int CharacterHP;			//�L�����N�^�[��HP
	int EnemyHP;				//�G��HP

	std::vector<String> nowproperty;
	NOWDRAW nowdraw;
	int coordinateX, coordinateY;			//�`��J�n�ʒu��x���W��y���W
	int x, y;
	int frame1X,frame1Y;
	int frame2X, frame2Y;
	int nowselect;
	String menu[6];

	void (Battle::* FuncDraw)(void);
	void ChangeDraw(NOWDRAW next);
	void DrawCommand1(void);
	void PrintSelectMenu(void);
	void SelectMenu(void);
	void PrintFrame1(void);
	void PrintFrame2(void);
};