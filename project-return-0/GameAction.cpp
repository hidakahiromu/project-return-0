#include"SceneManager.h"
#include"GameAction.h"
# include <Siv3D.hpp>


GameAction::GameAction(void) {
	TextureAsset::Register(U"backTex",U"example/windmill.png");//背景画像ロード
	TextureAsset::Register(U"blockTex", U"image/Brick.png");//ブロック画像ロード
	//B = new Block();
	P = new Player();

}

GameAction::~GameAction(void) {

}


//Blockクラスの初期化
void Block::update(){

}

Block::Block(const RectF& region) :
	m_region(region){}

	// プレイヤーの現在位置を更新する関数
void Block::setPlayerPos(const Vec2& pos)
	{
		m_playerPosition = pos;
	}

	// 描画以外の操作をする関数
void update() {}

// 点との当たり判定を取る関数
bool Block::intersects(const Vec2& shape) const
{
	return m_region.intersects(shape);
}

	// 描画をする関数（描画操作以外行わないこと.）
void Block::draw()
{
	m_region.movedBy(-m_playerPosition + Window::Center())(TextureAsset(U"blockTex")).draw();
}


	//左右移動入力
	int8 wide() { return (KeyRight | KeyD).pressed() - (KeyLeft | KeyA).pressed(); };




Player::Player(void) :
	m_position(0, 336),
	m_texture(U"image/sample.jpg"),
	m_isGrounded(false),
	m_speed(5.0, 0),
	m_isRight(false) {}
	
	

// 位置を取得する関数
Vec2 Player::getPos()
{
	return m_position;
}

	// 地面に接しているかを更新する関数
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

// 描画以外の操作をする関数
void Player::update()
{
	if (m_isGrounded)
	{
		if (KeySpace.down())
		{
			//初速度の設定
			m_speed.y = m_jump_v0;
			//Y座標の更新
			
			m_position.y += m_speed.y;
		}
	}
	else
	{
		//Y方向の速度に加速度を加える
		m_speed.y += m_gravity;
		//Y座標の更新
		m_position.y += m_speed.y;
			//上昇中にボタンを離したときの処理
		if (m_speed.y < 0 && KeySpace.pressed())
		{
			m_speed.y *= 0.9f;
		}
	}

	//X方向の移動
	m_position.x += wide() * m_speed.x;
	//キャラの向きを変える
	if (wide() == 1) m_isRight = true;
	if (wide() == -1) m_isRight = false;
}

// 描画をする関数（描画操作以外行わないこと.）
void Player::draw()
{
	RectF(Vec2(0, 0) + Window::Center(), 64,64)(m_texture).draw();
	Print << m_position;
}



void GameAction::update(void) {
	B->update();
	P->update();
	if (KeyEnter.down()) {//ストーリームービーへ移行
		SceneManager::SetNextScene(SceneManager::SCENE_MOVIE_STORY);
	}
}

void GameAction::draw(void) {
	B->draw();
	P->draw();
	Rect(Window::Size())(TextureAsset(U"backTex")).draw();//背景表示
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
		Texture(TextureAsset(U"blockTex")).draw(blockX, 624);//ブロック表示
		Rect block_region(blockX - 1, 623, 66, 66);//ブロックの領域を1pixel広く設定
	}*/

	/*
	Rect player_region(charpos.x, charpos.y, 64, 64);//プレイヤーの領域

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