#pragma once
#include<Siv3D.hpp>
#include<vector>
#include <algorithm>    
#include <iterator> 

class Character {
public:
	Character(void);
	~Character(void);
	static void update(void);
	static void draw(void);
	static int SetHp(void);						//�L�����N�^�[�̍���HP��n������
	static void GetHp(int nexthp);					//�o�g�����I��������HP������Ă��鏈��
	static void GetProperty(String tool);		//�L�����N�^�[���A�C�e�����E������
	static void SetProperty(std::vector<String> &tool);				//�L�����N�^�[�̓����n������
	static void GetTool(std::vector<String> &tool);					//�o�g�����I��������ƁA���̎�������������Ă��鏈��
	static void SetSkills(std::vector<String> &skill);						//�X�L����n������
	static void GetSkills(std::vector<String>& skill);						//�X�L����Ⴄ����

private:
	static int characterHp;										//�L�����N�^�[��HP
	static std::vector<String> property;						//�L�����N�^�[�̎�����
	static std::vector<String> skills;							//�L�����N�^�[�̃X�L��
};