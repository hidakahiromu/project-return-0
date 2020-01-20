#pragma once
#include"Scene.h"
#include"PrintFrame.h"
#include<Siv3D.hpp>


class MovieStory : public Scene , public PrintFrame  {		//難易度選択のクラス（Sceneクラスを継承）
public:
	MovieStory(void);				//初期化処理
	~MovieStory(void);				//開放処理
	void update(void);			//計算系処理(Sceneのupdateをオーバーライド)
	void draw(void);			//描画系処理(Sceneのdrawをオーバーライド)
	void ChangeCSV(void);		//章ごとにCSVをロードする処理
private:
	bool on1, on2, on3;			//文字を出力出来たかどうか判定用のフラグ
	int count1, count2, count3;	//1文の文字数カウント用変数
	int startX,startY;					//startXは描画開始位置x座標,startYは描画開始位置y座標

	Audio *talk;

	static int nowStoryCSV;							//今はどこのCSVデータなのか（何章なのか）

	int line;			//csvの行管理用変数
	CSVData csv;				//csv読み込む用
	int storycount;				//今何章なのか
	String nowstory[3];		//csvのデータを2次元配列のStringで表示(3文26文字)
	String nowname;			//今誰が話しているのかをCSVからもらうための変数
	int sentence;				//文管理用変数
	
	void SetOnFlagFalse(void);				//on1,on2,on3のフラグを全部falseに変える
	void AllSentencePrint(void);			//文字が描画しきる前にエンターキーを押すとすべて書き込む用の関数
	void printSentence1(void);				//ストーリーの書き込みの1行目
	void printSentence2(void);				//ストーリーの書き込みの2行目
	void printSentence3(void);				//ストーリーの書き込みの3行目
	void LoadCsv(void);						//csvのロード用

};