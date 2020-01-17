#pragma once
#include"Scene.h"
#include<Siv3D.hpp>
#include<vector>

class Ending : public Scene {		//エンディングのクラス（Sceneクラスを継承）
public:
	Ending(void);				//初期化処理
	~Ending(void);				//開放処理
	void update(void);			//計算系処理(Sceneのupdateをオーバーライド)
	void draw(void);			//描画系処理(Sceneのdrawをオーバーライド)
private:
	void DrawCSV(void);			//CSVの描画

	std::vector<String> endRoll;		//CSVデータを入れるためのString型
	CSVData end;
	Audio* end_BGM;
	int csvY;			//csv描画の時のY座標


};