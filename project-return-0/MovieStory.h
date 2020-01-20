#pragma once
#include"Scene.h"
#include"PrintFrame.h"
#include<Siv3D.hpp>


class MovieStory : public Scene , public PrintFrame  {		//��Փx�I���̃N���X�iScene�N���X���p���j
public:
	MovieStory(void);				//����������
	~MovieStory(void);				//�J������
	void update(void);			//�v�Z�n����(Scene��update���I�[�o�[���C�h)
	void draw(void);			//�`��n����(Scene��draw���I�[�o�[���C�h)
	void ChangeCSV(void);		//�͂��Ƃ�CSV�����[�h���鏈��
private:
	bool on1, on2, on3;			//�������o�͏o�������ǂ�������p�̃t���O
	int count1, count2, count3;	//1���̕������J�E���g�p�ϐ�
	int startX,startY;					//startX�͕`��J�n�ʒux���W,startY�͕`��J�n�ʒuy���W

	Audio *talk;

	static int nowStoryCSV;							//���͂ǂ���CSV�f�[�^�Ȃ̂��i���͂Ȃ̂��j

	int line;			//csv�̍s�Ǘ��p�ϐ�
	CSVData csv;				//csv�ǂݍ��ޗp
	int storycount;				//�����͂Ȃ̂�
	String nowstory[3];		//csv�̃f�[�^��2�����z���String�ŕ\��(3��26����)
	String nowname;			//���N���b���Ă���̂���CSV������炤���߂̕ϐ�
	int sentence;				//���Ǘ��p�ϐ�
	
	void SetOnFlagFalse(void);				//on1,on2,on3�̃t���O��S��false�ɕς���
	void AllSentencePrint(void);			//�������`�悵����O�ɃG���^�[�L�[�������Ƃ��ׂď������ޗp�̊֐�
	void printSentence1(void);				//�X�g�[���[�̏������݂�1�s��
	void printSentence2(void);				//�X�g�[���[�̏������݂�2�s��
	void printSentence3(void);				//�X�g�[���[�̏������݂�3�s��
	void LoadCsv(void);						//csv�̃��[�h�p

};