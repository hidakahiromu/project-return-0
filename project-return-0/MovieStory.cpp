#include"SceneManager.h"
#include"MovieStory.h"
#include"Difficult.h"

//TODO::あとは画像と名前を乗っけるだけ

int MovieStory::nowStoryCSV=0;

#define X 30						//文字の描画間隔のX座標（後で変更）
#define Y 50						//文の描画間隔のY座標（後で変更）


MovieStory::MovieStory(void) {
	SetFrameCount();
	SetOnFlagFalse();
	startX = 300, startY = 420;
	sentence = 0;
	line = 2;
	storycount = 1;
	nowStoryCSV++;
	ChangeCSV();
	FontAsset::Register(U"fontB", 30);

	talk = new Audio(U"resource/musics/story_talk.wav");

	nowname = csv.get<String>(line,1);
	if (nowname == U"主人公") {
		nowname = Difficult::GetCharacterName();
	}
	nowstory[sentence] = csv.get<String>(line,0);
	nowstory[sentence+1] = csv.get<String>(line + 1, 0);
	nowstory[sentence+2] = csv.get<String>(line + 2, 0);
}

MovieStory::~MovieStory(void) {
	TextureAsset::UnregisterAll();
	delete talk;
	SetOnFlagFalse();
	storycount = 0;
	sentence = 0;
	line = 0;
	csv.clear();
}

void MovieStory::update(void) {
	if (KeyControl.down()) {
		if (nowStoryCSV == 10) {
			SceneManager::SetNextScene(SceneManager::SCENE_ENDING);
		}
		else {
			SceneManager::SetNextScene(SceneManager::SCENE_BATTLE);
		}
	}
	if (storycount == csv.get<int>(1, 4)&& on3 == true && KeyEnter.down()) {//RPGバトルへ移行
		if (nowStoryCSV == 10) {
			SceneManager::SetNextScene(SceneManager::SCENE_ENDING);
		}
		else {
			SceneManager::SetNextScene(SceneManager::SCENE_BATTLE);
		}
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
	TextureAsset(U"MovieStory_back1").draw();

	if (nowStoryCSV == 1 && storycount >= 17) {
		TextureAsset(U"MovieStory_back2").draw();
	}
	if (nowStoryCSV == 9 && storycount >= 14) {
		TextureAsset(U"MovieStory_back2").draw();
	}
	if (nowStoryCSV == 2 && storycount >= 2) {
		TextureAsset(U"MovieStory_back2").draw();
	}
	if (nowStoryCSV == 3 && storycount >= 5) {
		TextureAsset(U"MovieStory_back2").draw();
	}

	Rect(50, 360, 1180, 300).draw(Palette::Black);
	DownFramePrint();
	FontAsset(U"fontB")(U"『",nowname,U"』").draw(300,370);
	if (nowname	!= U"ナレーション" && nowname != U"ｔｖ" && nowname != U"？？？" && nowname != U"機械音" && nowname != U"パソコン" && nowname != U"転送機械") {
		if (csv.get<String>(line, 1) == U"主人公" ) {
			TextureAsset(U"主人公").draw(60, 390);
		}
		else {
			TextureAsset(nowname).draw(60, 390);
		}
	}
	

	if (downframecount == 5) {			//白枠が出てきたら1行目を描画
		printSentence1();
	}
	if (on1 == true) {					//1行目がすべて描画できたら2行目を描画
		printSentence2();
	}
	if (on2== true) {					//2行目がすべて描画出来たら3行目を描画
		printSentence3();
	}
	Print << U"Ctrlキーでスキップ";
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
	nowname = csv.get<String>(line, 1);
	if (nowname == U"主人公") {
		nowname = Difficult::GetCharacterName();
	}
	nowstory[sentence] = csv.get<String>(line, 0);
	nowstory[sentence + 1] = csv.get<String>(line + 1, 0);
	nowstory[sentence + 2] = csv.get<String>(line + 2, 0);

}

void MovieStory::ChangeCSV(void) {
	switch (nowStoryCSV){
	case 1:												//エピローグ
		csv.load(U"resource/story/story_b0.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/sougen2_asa.png");
		TextureAsset::Register(U"MovieStory_back2", U"resource/images/sougen2_yoru.png");
		TextureAsset::Register(U"エマ", U"resource/images/character/ema.png");
		TextureAsset::Register(U"主人公", U"resource/images/character/syuzinkou.png");
		TextureAsset::Register(U"EVOA", U"resource/images/character/EVOA.png");
		break;
	case 2:
		csv.load(U"resource/story/story_b1.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/sougen2_yoru.png");
		TextureAsset::Register(U"MovieStory_back2", U"resource/images/doukutu1.png");
		TextureAsset::Register(U"EVOA", U"resource/images/character/EVOA.png");
		TextureAsset::Register(U"エマ", U"resource/images/character/ema.png");
		TextureAsset::Register(U"主人公", U"resource/images/character/syuzinkou.png");
		TextureAsset::Register(U"モノット", U"resource/images/character/monoto.png");
		break;
	case 3:
		csv.load(U"resource/story/story_b2.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/doukutu1.png");
		TextureAsset::Register(U"MovieStory_back2", U"resource/images/doukutu2.png");
		TextureAsset::Register(U"エマ", U"resource/images/character/ema.png");
		TextureAsset::Register(U"エーバット", U"resource/images/character/ebato.png");
		break;
	case 4:
		csv.load(U"resource/story/story_b3.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/hana_yoru.png");
		TextureAsset::Register(U"エマ", U"resource/images/character/ema.png");
		TextureAsset::Register(U"トーテム", U"resource/images/character/totemu.png");
		break;
	case 5:
		csv.load(U"resource/story/story_b4.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/hana_yoru.png");
		TextureAsset::Register(U"エマ", U"resource/images/character/ema.png");
		TextureAsset::Register(U"ラムール", U"resource/images/character/ramuru.png");
		break;
	case 6:
		csv.load(U"resource/story/story_b5.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/sougen1_yorujpg.png");
		TextureAsset::Register(U"エマ", U"resource/images/character/ema.png");
		TextureAsset::Register(U"ワーフ", U"resource/images/character/wahu.png");
		break;
	case 7:
		csv.load(U"resource/story/story_b6.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/taizyu_yoru.png");
		TextureAsset::Register(U"エマ", U"resource/images/character/ema.png");
		TextureAsset::Register(U"ガイア", U"resource/images/character/gaia.png");
		break;
	case 8:
		csv.load(U"resource/story/story_b7.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/sougen2_yoru.png");
		TextureAsset::Register(U"EVOA", U"resource/images/character/EVOA.png");
		TextureAsset::Register(U"エマ", U"resource/images/character/ema.png");
		break;
	case 9:
		csv.load(U"resource/story/story_b8.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/sougen2_yoru.png");
		TextureAsset::Register(U"MovieStory_back2", U"resource/images/sougen2_asa.png");
		TextureAsset::Register(U"EVOA", U"resource/images/character/EVOA.png");
		TextureAsset::Register(U"エマ", U"resource/images/character/ema.png");
		TextureAsset::Register(U"主人公", U"resource/images/character/syuzinkou.png");
		break;
	case 10:
		csv.load(U"resource/story/story_b9.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/sougen_yuugata.png");
		TextureAsset::Register(U"主人公", U"resource/images/character/syuzinkou.png");
		break;
	default:
		break;
	}
}