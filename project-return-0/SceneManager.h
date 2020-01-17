#pragma once
#include<Siv3D.hpp>
#include"Scene.h"
#include"Title.h"
#include"Difficult.h"
#include"GameAction.h"
#include"MovieStory.h"
#include"Battle.h"
#include"Ending.h"
#include"Character.h"




class SceneManager {				//シ－ン管理用クラス
	public:
		enum SCENE {
			SCENE_TITLE,			//Titleのシーン
			SCENE_DIFFICULT,		//難易度の選択画面
			SCENE_GAME_ACTION,				//アクションゲームのシーン
			SCENE_MOVIE_STORY,		//ストーリーのシーン
			SCENE_BATTLE,			//RPGゲームのシーン
			SCENE_ENDING,			//エンディングの種類
			//SCENE_RESULT			//リザルト？
		};
		static void initialize();	//初期化処理
		static void finalize();		//開放処理
		static void sceneUpdate();		//updateの箱
		static void sceneDraw();			//drawの箱
		static void SetNextScene(SCENE next);

	private:

		static Character* character;
		static Scene *scene;
		static SCENE nowscene;			//今のシーンはどこか
		static SCENE nextscene;			//次は度のシーンに飛びたいか
		static void ChangeScene();

};