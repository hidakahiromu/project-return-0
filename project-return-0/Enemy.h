#pragma once
#include<Siv3D.hpp>


class Enemy {
public:
	Enemy(void);
	~Enemy(void);
	void update(void);
	void draw(void);
	static void OnEnemyFlag(bool next);			//Enemy�̃t���O�؂�ւ�	
	static void Damage(int damage);				//Character����_���[�W��������Ă��鏈��
	static void SetEnemyStatus(int HP,String Explain1, String Explain2, String Explain3);	//�e�W���u����HP�Ɛ�������������Ă��鏈��
	static void PrintExplanation(void);			//�L�����N�^�[�Ŏg���G�̏���\������@�\

protected:				//�p���p�̊֐��Ƃ�
	virtual void jobDraw() = 0;					//EnemyJobs�Œ�`����p��Draw
	virtual void jobUpdate() = 0;				//EnemyJobs�Œ�`����p��Update

private:
	static int enemyHp;					//�G��HP
	static String explanation1, explanation2, explanation3;			//��������s�ځA��s�ځA�O�s��
	static bool EnemyTurnFlag;			//TRUE�̎�Enemy�̃^�[��


};