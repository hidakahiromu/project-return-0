#pragma once
#include<Siv3D.hpp>

class PrintFrame {
public:
	void SetFrameCount(void);				//countの初期化
	void UpFramePrint(void);				//画面上に白枠を描画する処理
	void DownFramePrint(void);				//画面下に白枠を描画する処理	
	int upframecount;						//UpFramePrintの関数で使う描画管理用変数
	int downframecount;						//downFramePrintの関数で使う描画管理用変数
};