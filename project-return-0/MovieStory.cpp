#include"SceneManager.h"
#include"MovieStory.h"

//TODO::あとは画像と名前を乗っけるだけ

int MovieStory::nowStoryCSV=0;

#define X 30						//文字の描画間隔のX座標（後で変更）
#define Y 50						//文の描画間隔のY座標（後で変更）


MovieStory::MovieStory(void) {
	SetFrameCount();
	SetOnFlagFalse();
	startX = 300, startY = 370;
	sentence = 0;
	line = 2;
	storycount = 1;
	nowStoryCSV++;
	ChangeCSV();
	FontAsset::Register(U"fontB", 30);

	talk = new Audio(U"resource/musics/story_talk.wav");

	nowstory[sentence] = csv.get<String>(line,0);
	nowstory[sentence+1] = csv.get<String>(line + 1, 0);
	nowstory[sentence+2] = csv.get<String>(line + 2, 0);
}

MovieStory::~MovieStory(void) {
	delete talk;
	SetOnFlagFalse();
	storycount = 0;
	sentence = 0;
	line = 0;
	csv.clear();
}

void MovieStory::update(void) {
	if (storycount == csv.get<int>(1, 4)&& on3 == true && KeyEnter.down()) {//RPGバトルへ移行
		SceneManager::SetNextScene(SceneManager::SCENE_BATTLE);
	}
	if (downframecount == 5 && on3 != true && KeyEnter.down()) {		//文字描画中にエンターキーを押すとすべて描画
		AllSentencePrint();
	}
	else if (storycount != csv.get<int>(0, 1) && downframecount == 5 && on3 == true && KeyEnter.down()) {			//すべて描画した後、会話に続きがあるならば初期化
		SetOnFlagFalse();
		LoadCsv();
		ClearPrint();
	}

}

void MovieStory::draw(void) {
	DownFramePrint();
	if (downframecount == 5) {			//白枠が出てきたら1行目を描画
		printSentence1();
	}
	if (on1 == true) {					//1行目がすべて描画できたら2行目を描画
		printSentence2();
	}
	if (on2== true) {					//2行目がすべて描画出来たら3行目を描画
		printSentence3();
	}
}

void MovieStory::printSentence1(void) {		//会話の１行目の描画処理
	if (System::FrameCount() % 5 == 0 && count1 < nowstory[sentence].length()) {
		count1++;
		talk->playOneShot();
	}
	for (int i = 0; i < count1; i++) {
		FontAsset(U"fontB")(nowstory[sentence][i]).draw(startX+(X*i), startY);
		
	}
	if (count1 == nowstory[sentence].length()) {
		on1 = true;
	}
	
	
}

void MovieStory::printSentence2(void) {			//会話の２行目の描画処理
	if (System::FrameCount() % 5 == 0 && count2 < nowstory[sentence+1].length()) {
		count2++;
		talk->playOneShot();
	}
	for (int j = 0; j < count2; j++) {
		FontAsset(U"fontB")(nowstory[sentence+1][j]).draw(startX + (X * j), startY+Y);

	}
	if (count2 == nowstory[sentence+1].length()) {
		on2 = true;
	}
}

void MovieStory::printSentence3(void) {
	if (System::FrameCount() % 5 == 0 && count3 < nowstory[sentence+2].length()) {
		count3++;
		talk->playOneShot();
	}
	for (int k = 0; k < count3; k++) {
		FontAsset(U"fontB")(nowstory[sentence+2][k]).draw(startX + (X * k), startY + (Y*2));
	}
	if (count3 == nowstory[sentence+2].length()) {
		on3 = true;
	}
	if (on3 == true ) {
		Triangle(1200, 620, 15, 3.2).draw();
	}
}

void MovieStory::SetOnFlagFalse(void) {			//フラグとカウントの初期化
	on1 = false;
	on2 = false;
	on3 = false;
	count1 = 0;
	count2 = 0;
	count3 = 0;
}

void MovieStory::AllSentencePrint(void) {			//フラグをTRUEに、カウントをMAXにする処理
	on1 = true;
	on2 = true;
	on3 = true;
	count1 = nowstory[sentence].length();
	count2 = nowstory[sentence + 1].length();
	count3 = nowstory[sentence + 2].length();
}

void MovieStory::LoadCsv(void) {					//次の会話に移行する処理
	line += 3;
	storycount++;
	nowstory[sentence] = csv.get<String>(line, 0);
	nowstory[sentence + 1] = csv.get<String>(line + 1, 0);
	nowstory[sentence + 2] = csv.get<String>(line + 2, 0);
}

void MovieStory::ChangeCSV(void) {
	switch (nowStoryCSV){
	case 1:												//エピローグ
		csv.load(U"resource/story/story_prolgue.csv");
		break;
	case 2:
		csv.load(U"resource/story/story_chapter1.csv");
		break;
	case 3:
		csv.load(U"resource/story/story_chapter2.csv");
		break;
	case 4:
		csv.load(U"resource/story/story_chapter3.csv");
		break;
	case 5:
		csv.load(U"resource/story/story_chapter4.csv");
		break;
	case 6:
		csv.load(U"resource/story/story_chapter5.csv");
		break;
	case 7:
		csv.load(U"resource/story/story_chapter6.csv");
		break;
	case 8:
		csv.load(U"resource/story/story_chapter7.csv");
		break;
	case 9:
		csv.load(U"resource/story/story_chapter8.csv");
		break;
	case 10:
		csv.load(U"resource/story/story_chapter9.csv");
		break;
	case 11:
		csv.load(U"resource/story/story_chapter10.csv");
		break;
	case 12:													//エンディング
		csv.load(U"resource/story/story_epilog.csv");
		break;
	default:
		break;
	}
}