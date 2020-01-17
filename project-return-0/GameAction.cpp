#include"SceneManager.h"
#include"GameAction.h"
# include <Siv3D.hpp>


GameAction::GameAction(void) {
	TextureAsset::Register(U"backTex",U"example/windmill.png");//�w�i�摜���[�h
	TextureAsset::Register(U"blockTex", U"image/Brick.png");//�u���b�N�摜���[�h
	//B = new Block();
	P = new Player();

}

GameAction::~GameAction(void) {

}


//Block�N���X�̏�����
void Block::update(){

}

Block::Block(const RectF& region) :
	m_region(region){}

	// �v���C���[�̌��݈ʒu���X�V����֐�
void Block::setPlayerPos(const Vec2& pos)
	{
		m_playerPosition = pos;
	}

	// �`��ȊO�̑��������֐�
void update() {}

// �_�Ƃ̓����蔻������֐�
bool Block::intersects(const Vec2& shape) const
{
	return m_region.intersects(shape);
}

	// �`�������֐��i�`�摀��ȊO�s��Ȃ�����.�j
void Block::draw()
{
	m_region.movedBy(-m_playerPosition + Window::Center())(TextureAsset(U"blockTex")).draw();
}


	//���E�ړ�����
	int8 wide() { return (KeyRight | KeyD).pressed() - (KeyLeft | KeyA).pressed(); };




Player::Player(void) :
	m_position(0, 336),
	m_texture(U"image/sample.jpg"),
	m_isGrounded(false),
	m_speed(5.0, 0),
	m_isRight(false) {}
	
	

// �ʒu���擾����֐�
Vec2 Player::getPos()
{
	return m_position;
}

	// �n�ʂɐڂ��Ă��邩���X�V����֐�
void Player::checkGround(const Array<Block>& blocks)
{
	m_isGrounded = false;
		for (size_t i = 0; i < blocks.size(); i++)
	{
		if (blocks[i].intersects(m_position))
			{
			m_isGrounded = true;
		}
	}
}

// �`��ȊO�̑��������֐�
void Player::update()
{
	if (m_isGrounded)
	{
		if (KeySpace.down())
		{
			//�����x�̐ݒ�
			m_speed.y = m_jump_v0;
			//Y���W�̍X�V
			
			m_position.y += m_speed.y;
		}
	}
	else
	{
		//Y�����̑��x�ɉ����x��������
		m_speed.y += m_gravity;
		//Y���W�̍X�V
		m_position.y += m_speed.y;
			//�㏸���Ƀ{�^���𗣂����Ƃ��̏���
		if (m_speed.y < 0 && KeySpace.pressed())
		{
			m_speed.y *= 0.9f;
		}
	}

	//X�����̈ړ�
	m_position.x += wide() * m_speed.x;
	//�L�����̌�����ς���
	if (wide() == 1) m_isRight = true;
	if (wide() == -1) m_isRight = false;
}

// �`�������֐��i�`�摀��ȊO�s��Ȃ�����.�j
void Player::draw()
{
	RectF(Vec2(0, 0) + Window::Center(), 64,64)(m_texture).draw();
	Print << m_position;
}



void GameAction::update(void) {
	B->update();
	P->update();
	if (KeyEnter.down()) {//�X�g�[���[���[�r�[�ֈڍs
		SceneManager::SetNextScene(SceneManager::SCENE_MOVIE_STORY);
	}
}

void GameAction::draw(void) {
	B->draw();
	P->draw();
	Rect(Window::Size())(TextureAsset(U"backTex")).draw();//�w�i�\��
	Player player;

	Array<Block> blocks;
	blocks.push_back(Block({ 0, 400, 60, 60 }));
	blocks.push_back(Block({ 64, 400, 60, 60 }));
	blocks.push_back(Block({ 128, 400, 60, 60 }));
	blocks.push_back(Block({ 192, 400, 60, 60 }));
	blocks.push_back(Block({ 256, 200, 60, 60 }));
	blocks.push_back(Block({ 320, 400, 60, 60 }));
	blocks.push_back(Block({ 384, 400, 60, 60 }));
	blocks.push_back(Block({ 448, 400, 60, 60 }));
	blocks.push_back(Block({ 512, 400, 60, 60 }));

	/*for (int blockX=0; blockX < 1000; blockX += 64) {
		Texture(TextureAsset(U"blockTex")).draw(blockX, 624);//�u���b�N�\��
		Rect block_region(blockX - 1, 623, 66, 66);//�u���b�N�̗̈��1pixel�L���ݒ�
	}*/

	/*
	Rect player_region(charpos.x, charpos.y, 64, 64);//�v���C���[�̗̈�

	if (player_region.intersects(block_region)&&KeySpace.down()) {
		jumpflg = true;
	}
	*/

	player.update();


	for (size_t i = 0; i < blocks.size(); i++)
	{
		blocks[i].setPlayerPos(player.getPos());
		blocks[i].update();
	}

	for (size_t i = 0; i < blocks.size(); i++)
	{
		blocks[i].draw();
	}

	player.draw();

}