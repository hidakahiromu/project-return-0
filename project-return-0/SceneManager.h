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




class SceneManager {				//�V�|���Ǘ��p�N���X
	public:
		enum SCENE {
			SCENE_TITLE,			//Title�̃V�[��
			SCENE_DIFFICULT,		//��Փx�̑I�����
			SCENE_GAME_ACTION,				//�A�N�V�����Q�[���̃V�[��
			SCENE_MOVIE_STORY,		//�X�g�[���[�̃V�[��
			SCENE_BATTLE,			//RPG�Q�[���̃V�[��
			SCENE_ENDING,			//�G���f�B���O�̎��
			//SCENE_RESULT			//���U���g�H
		};
		static void initialize();	//����������
		static void finalize();		//�J������
		static void sceneUpdate();		//update�̔�
		static void sceneDraw();			//draw�̔�
		static void SetNextScene(SCENE next);

	private:

		static Character* character;
		static Scene *scene;
		static SCENE nowscene;			//���̃V�[���͂ǂ���
		static SCENE nextscene;			//���͓x�̃V�[���ɔ�т�����
		static void ChangeScene();

};