#include"SceneManager.h"
#include"MovieStory.h"
#include"Difficult.h"

//TODO::���Ƃ͉摜�Ɩ��O��������邾��

int MovieStory::nowStoryCSV=0;

#define X 30						//�����̕`��Ԋu��X���W�i��ŕύX�j
#define Y 50						//���̕`��Ԋu��Y���W�i��ŕύX�j


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
	if (nowname == U"��l��") {
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
	if (storycount == csv.get<int>(1, 4)&& on3 == true && KeyEnter.down()) {//RPG�o�g���ֈڍs
		if (nowStoryCSV == 10) {
			SceneManager::SetNextScene(SceneManager::SCENE_ENDING);
		}
		else {
			SceneManager::SetNextScene(SceneManager::SCENE_BATTLE);
		}
	}
	if (downframecount == 5 && on3 != true && KeyEnter.down()) {		//�����`�撆�ɃG���^�[�L�[�������Ƃ��ׂĕ`��
		AllSentencePrint();
	}
	else if (storycount != csv.get<int>(0, 1) && downframecount == 5 && on3 == true && KeyEnter.down()) {			//���ׂĕ`�悵����A��b�ɑ���������Ȃ�Ώ�����
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
	FontAsset(U"fontB")(U"�w",nowname,U"�x").draw(300,370);
	if (nowname	!= U"�i���[�V����" && nowname != U"����" && nowname != U"�H�H�H" && nowname != U"�@�B��" && nowname != U"�p�\�R��" && nowname != U"�]���@�B") {
		if (csv.get<String>(line, 1) == U"��l��" ) {
			TextureAsset(U"��l��").draw(60, 390);
		}
		else {
			TextureAsset(nowname).draw(60, 390);
		}
	}
	

	if (downframecount == 5) {			//���g���o�Ă�����1�s�ڂ�`��
		printSentence1();
	}
	if (on1 == true) {					//1�s�ڂ����ׂĕ`��ł�����2�s�ڂ�`��
		printSentence2();
	}
	if (on2== true) {					//2�s�ڂ����ׂĕ`��o������3�s�ڂ�`��
		printSentence3();
	}
	Print << U"Ctrl�L�[�ŃX�L�b�v";
}

void MovieStory::printSentence1(void) {		//��b�̂P�s�ڂ̕`�揈��
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

void MovieStory::printSentence2(void) {			//��b�̂Q�s�ڂ̕`�揈��
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

void MovieStory::SetOnFlagFalse(void) {			//�t���O�ƃJ�E���g�̏�����
	on1 = false;
	on2 = false;
	on3 = false;
	count1 = 0;
	count2 = 0;
	count3 = 0;
}

void MovieStory::AllSentencePrint(void) {			//�t���O��TRUE�ɁA�J�E���g��MAX�ɂ��鏈��
	on1 = true;
	on2 = true;
	on3 = true;
	count1 = nowstory[sentence].length();
	count2 = nowstory[sentence + 1].length();
	count3 = nowstory[sentence + 2].length();
}

void MovieStory::LoadCsv(void) {					//���̉�b�Ɉڍs���鏈��
	line += 3;
	storycount++;
	nowname = csv.get<String>(line, 1);
	if (nowname == U"��l��") {
		nowname = Difficult::GetCharacterName();
	}
	nowstory[sentence] = csv.get<String>(line, 0);
	nowstory[sentence + 1] = csv.get<String>(line + 1, 0);
	nowstory[sentence + 2] = csv.get<String>(line + 2, 0);

}

void MovieStory::ChangeCSV(void) {
	switch (nowStoryCSV){
	case 1:												//�G�s���[�O
		csv.load(U"resource/story/story_b0.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/sougen2_asa.png");
		TextureAsset::Register(U"MovieStory_back2", U"resource/images/sougen2_yoru.png");
		TextureAsset::Register(U"�G�}", U"resource/images/character/ema.png");
		TextureAsset::Register(U"��l��", U"resource/images/character/syuzinkou.png");
		TextureAsset::Register(U"EVOA", U"resource/images/character/EVOA.png");
		break;
	case 2:
		csv.load(U"resource/story/story_b1.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/sougen2_yoru.png");
		TextureAsset::Register(U"MovieStory_back2", U"resource/images/doukutu1.png");
		TextureAsset::Register(U"EVOA", U"resource/images/character/EVOA.png");
		TextureAsset::Register(U"�G�}", U"resource/images/character/ema.png");
		TextureAsset::Register(U"��l��", U"resource/images/character/syuzinkou.png");
		TextureAsset::Register(U"���m�b�g", U"resource/images/character/monoto.png");
		break;
	case 3:
		csv.load(U"resource/story/story_b2.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/doukutu1.png");
		TextureAsset::Register(U"MovieStory_back2", U"resource/images/doukutu2.png");
		TextureAsset::Register(U"�G�}", U"resource/images/character/ema.png");
		TextureAsset::Register(U"�G�[�o�b�g", U"resource/images/character/ebato.png");
		break;
	case 4:
		csv.load(U"resource/story/story_b3.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/hana_yoru.png");
		TextureAsset::Register(U"�G�}", U"resource/images/character/ema.png");
		TextureAsset::Register(U"�g�[�e��", U"resource/images/character/totemu.png");
		break;
	case 5:
		csv.load(U"resource/story/story_b4.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/hana_yoru.png");
		TextureAsset::Register(U"�G�}", U"resource/images/character/ema.png");
		TextureAsset::Register(U"�����[��", U"resource/images/character/ramuru.png");
		break;
	case 6:
		csv.load(U"resource/story/story_b5.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/sougen1_yorujpg.png");
		TextureAsset::Register(U"�G�}", U"resource/images/character/ema.png");
		TextureAsset::Register(U"���[�t", U"resource/images/character/wahu.png");
		break;
	case 7:
		csv.load(U"resource/story/story_b6.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/taizyu_yoru.png");
		TextureAsset::Register(U"�G�}", U"resource/images/character/ema.png");
		TextureAsset::Register(U"�K�C�A", U"resource/images/character/gaia.png");
		break;
	case 8:
		csv.load(U"resource/story/story_b7.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/sougen2_yoru.png");
		TextureAsset::Register(U"EVOA", U"resource/images/character/EVOA.png");
		TextureAsset::Register(U"�G�}", U"resource/images/character/ema.png");
		break;
	case 9:
		csv.load(U"resource/story/story_b8.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/sougen2_yoru.png");
		TextureAsset::Register(U"MovieStory_back2", U"resource/images/sougen2_asa.png");
		TextureAsset::Register(U"EVOA", U"resource/images/character/EVOA.png");
		TextureAsset::Register(U"�G�}", U"resource/images/character/ema.png");
		TextureAsset::Register(U"��l��", U"resource/images/character/syuzinkou.png");
		break;
	case 10:
		csv.load(U"resource/story/story_b9.csv");
		TextureAsset::Register(U"MovieStory_back1", U"resource/images/sougen_yuugata.png");
		TextureAsset::Register(U"��l��", U"resource/images/character/syuzinkou.png");
		break;
	default:
		break;
	}
}