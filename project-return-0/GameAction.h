#pragma once
#pragma once
#include<Siv3D.hpp>
#include"Scene.h"
#include<vector>

class GameAction : public Scene {		//アクションゲームのクラス（Sceneクラスを継承）
public:
	GameAction(void);				//初期化処理
	~GameAction(void);				//開放処理
	void update(void);			//計算系処理(Sceneのupdateをオーバーライド)
	void draw(void);			//描画系処理(Sceneのdrawをオーバーライド)
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
	// ブロックの領域
	Array<Block> blocks;
	RectF m_region;
	
	// プレイヤーの現在の位置
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
	// プレイヤーの座標
	Vec2 m_position;

	// 地面に接しているか否か
	bool m_isGrounded;

	//
	Texture m_texture;

	//ジャンプの初速度
	float m_jump_v0 = -12.0f;

	//ジャンプの重力
	float m_gravity = 0.3f;

	//キャラの速度
	Vec2 m_speed;

	//キャラの向き
	bool m_isRight;
};