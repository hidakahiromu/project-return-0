#pragma once
#include"Scene.h"
#include"Character.h"
#include"Enemy.h"
#include<Siv3D.hpp>
#include<vector>
#include <algorithm>    
#include <iterator> 

class Battle : public Scene {		//RPG�o�g���̃N���X�iScene�N���X���p���j
public:
	enum NOWDRAW {
		NONE_SELECT,				//�����I�����Ă��Ȃ��Ƃ�
		ATTACK_SELECT,				//�U����I�������Ƃ�
		DEFEND_SELECT,				//�h���I�������Ƃ�
		TOOL_SELECT,				//��������I�������Ƃ�
		SEARCH_SELECT,				//���ׂ��I�������Ƃ�
	};
	Battle(void);				//����������
	~Battle(void);				//�J������
	void update(void);			//�v�Z�n����(Scene��update���I�[�o�[���C�h)
	void draw(void);			//�`��n����(Scene��draw���I�[�o�[���C�h)

private:
	double CharacterHP,FixHpC;			//�i������j�L�����N�^�[��HP�AHP�o�[�̌Œ�p�L�����N�^�[��HP
	double EnemyHP,FixHpE;				//�i������j�G��HP�AHP�o�[�̌Œ�p�G��HP

	String menu[4];							//�U���A�h��A�������A���ׂ�
	std::vector<String> nowproperty;		//�L�����N�^�[�̎�����
	std::vector<String> nowskills;			//�L�����N�^�[�̃X�L��
	NOWDRAW nowdraw;						//�����̑I����ʂ�I��ł���̂�
	int coordinateX, coordinateY;			//�`��J�n�ʒu��x���W��y���W
	int frame1X, frame1Y;					//�I����ʂ̔��g��X���W��Y���W
	int frame2X, frame2Y;					//���Ɠ���
	//int skillX, skillY;						//�X�L���\����X���W��Y���W
	//int toolX, toolY;
	int x, y;
	int nowselect;

	void (Battle::* FuncDraw)(void);			//draw�̊֐��|�C���^
	void ChangeDraw(NOWDRAW nextdraw);				
	void DecisionSelect(void);					//���̃R�}���h�i�U���Ƃ��h��j��I��������
	void SelectMenu(void);							
	void PrintSelectMenu(void);					//�����̍U���A�h��A�������A���ׂ��`�悷��
	void StatusPrint(void);						//�L�����N�^�[�̃X�e�[�^�X�\������
	void SkillPrint(void);						//�L�����N�^�[�̃X�L���`��
	void DefendPrint(void);						//�h��̎���draw
	void ToolPrint(void);						//�������i����j�̕`��
	void SearchPrint(void);						//���ׂ��I�������Ƃ��ɑ���̏���`�悷�鏈��
	void PrintFrame1(void);	
	void PrintFrame2(void);
};