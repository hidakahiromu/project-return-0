#pragma once
#include<Siv3D.hpp>


class Character {
public:
	enum DRAW {				//�e�l���Ƃɕ`�悷�����
		NONE_DRAW,					//�X�e�[�^�X��`��
		ATTACK_DRAW,				//�X�L����`��
		DEFEND_DRAW,				//�h��̎��̃A�N�V������`��H
		PROPERTY_DRAW,				//��������`��
		SEARCH_DRAW,				//����i�G�j�̏���`��
		TELOP_DRAW,					//�U���A�h��A�������̒��̉�����I�������Ƃ��ɕ\������e���b�v
	};
	Character(void);
	~Character(void);
	void update(void);
	void draw(void);
	static void GetProperty(String tool);		//�L�����N�^�[���A�C�e�����E������
	static void Damage(int damage);				//Enemy����_���[�W��������Ă��鏈��
	static void OnCharacterFlag(bool now);			//�L�����N�^�[�̃^�[�����ǂ���
	static void OnFlagDefend(bool now);					//�h��̃t���O�iTRUE�Ȃ�damage�����炷�j
	
	void IntervalInitialize(void);		//Enemy�̃^�[������Character�̃^�[���ɂȂ����Ƃ��̏������i���ԏ������j
	void ChangeDraw(DRAW now);					//
	void (Character::* Funcdraw)(void);			
	void MenuDraw(void);						//
	void SelectMenu(void);						//�U���A�h��A�������A���ׂ��I������O�p�`
	void SkillSelect(void);						//�X�L���̑I��
	void PropertySelect(void);					//�������̑I��
	void SwitchSelect(void);
	void StatusDraw(void);						//�L�����N�^�[�̃X�e�[�^�X��`��
	void SkillDraw(void);						//�L�����N�^�[�̃X�L����`��
	void DefendDraw(void);						//TODO::�h��̎��̕`��
	void PropertyDraw(void);					//�L�����N�^�[�̎�������`��
	void SearchDraw(void);						//�G�̏���\��
	void SkillsSwitch(void);					//�U���̎�ށi�X�L���j����
	void PropertySwitch(void);					//����i�������j�̌��ʕ���

	static int turncount;						//���݂̃^�[����
	static bool counterflg;							//skill"scanf"�ŎQ��

private:
	Audio *Select, *Enter, *Back;
	int now_select;						//�U���A�h��A�������A���ׂ�̉����������̂��𔻒肷�邽�߂̕ϐ�
	int select_Point_X,select_Point_Y;					//�I�������Ƃ��̎O�p�`�`���X���W��Y���W�̋N�_
	bool skillFlag;						//�U����I�������Ƃ�TRUE
	bool propertyFlag;					//��������I�������Ƃ�TRUE
	bool telopFlag;						//�e���b�v��`�悷��Ƃ��ɑ���ł��Ȃ�����悤�ɂ��邽�߂̃t���O
	bool DetailsFlag;					//�X�L���⎝�������g�p�����Ƃ��ɉ�����v�Z���Ȃ��悤�ɂ��邽�߂̃t���O

	int attacktimes;

	DRAW nowdraw;
	double HP,HP_Width,HP_Max;					//�i������j�L�����N�^�[��HP�ƃQ�[�W�̕��ƍ���HP�̃t��
	static std::vector<String> property;						//�L�����N�^�[�̎�����
	static std::vector<String> skills;							//�L�����N�^�[�̃X�L��
	static int CharacterHp;										//�L�����N�^�[��HP
	static bool CharacterTurnFlag;									//�L�����N�^�[�̃^�[���̎�TRUE
	static bool DefendFlag;								//�h��p�̃t���O
	int attackpoint;				//�^�_���[�W��
};