#pragma once
class Character;
class Enemy;
#include<Siv3D.hpp>
#include"Scene.h"


class Battle : public Scene {		//RPG�o�g���̃N���X�iScene�N���X���p���j
public:
	Battle(Character* CHARACTER );				//����������
	~Battle(void);				//�J������
	void update(void);			//�v�Z�n����(Scene��update���I�[�o�[���C�h)
	void draw(void);			//�`��n����(Scene��draw���I�[�o�[���C�h)
	static void OnFlagFinalized(bool end);			//true���Ă΂��ƃL�����N�^�[�̏����Afalse�œG�̏���

	void ChangeEnemy(int count);			//�G�̐���

private:
	class Character* Cha;
	class Enemy* Ene;

	static bool WinFlagCharacter;			//�L�����N�^�[�����������̃t���O
	static bool WinFlagEnemy;				//�G�����������̃t���O
	static int NowEnemyCount;				//�����͖ڂ̓G�Ȃ̂�


	int frame1X, frame1Y;					//�I����ʂ̔��g��X���W��Y���W
	int frame2X, frame2Y;					//���Ɠ���
	
	void (Battle::* FuncDraw)(void);
	void PrintFrame1(void);	
	void PrintFrame2(void);

};