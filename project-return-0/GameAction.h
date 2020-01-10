#pragma once
#pragma once
#include<Siv3D.hpp>
#include"Scene.h"
#include<vector>

class GameAction : public Scene {		//�A�N�V�����Q�[���̃N���X�iScene�N���X���p���j
public:
	GameAction(void);				//����������
	~GameAction(void);				//�J������
	void update(void);			//�v�Z�n����(Scene��update���I�[�o�[���C�h)
	void draw(void);			//�`��n����(Scene��draw���I�[�o�[���C�h)
private:
	class Block* B;
	class Player* P;
	
};

class Block {
public:
	Block(const RectF& region);
	~Block(void);
	void update(void);
	void draw(void);
	bool intersects(const Vec2& shape)const;
	void setPlayerPos(const Vec2& pos);

private:			
	// �u���b�N�̗̈�
	Array<Block> blocks;
	RectF m_region;
	
	// �v���C���[�̌��݂̈ʒu
	Vec2 m_playerPosition;
};

class Player {
public:
	Player(void);
	~Player(void);
	void update(void);
	void draw(void);
	Vec2 getPos();
	void checkGround(const Array<Block>& blocks);
private:
	// �v���C���[�̍��W
	Vec2 m_position;

	// �n�ʂɐڂ��Ă��邩�ۂ�
	bool m_isGrounded;

	//
	Texture m_texture;

	//�W�����v�̏����x
	float m_jump_v0 = -12.0f;

	//�W�����v�̏d��
	float m_gravity = 0.3f;

	//�L�����̑��x
	Vec2 m_speed;

	//�L�����̌���
	bool m_isRight;
};