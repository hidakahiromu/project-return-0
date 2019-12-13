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
	static int NowHp(void);						//�L�����N�^�[�̍���HP������Ă��鏈��
	static void GetHp(int nexthp);					//�o�g�����I��������HP������Ă��鏈��
	static void GetProperty(String tool);		//�L�����N�^�[���A�C�e�����E������
	static void NowProperty(std::vector<String> &tool);
private:

	

};