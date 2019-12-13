#include"SceneManager.h"
#include"MovieStory.h"


#define X 30						//�����̕`��Ԋu��X���W�i��ŕύX�j
#define Y 50						//���̕`��Ԋu��Y���W�i��ŕύX�j


MovieStory::MovieStory(void) {
	SetFrameCount();
	SetOnFlagFalse();
	startX = 300, startY = 370;
	sentence = 0;
	line = 0;
	storycount = 1;
	csv.load(U"resource/story/test.csv");
	FontAsset::Register(U"fontB", 30);

	nowstory[sentence] = csv.get<String>(line,0);
	nowstory[sentence+1] = csv.get<String>(line + 1, 0);
	nowstory[sentence+2] = csv.get<String>(line + 2, 0);
}

MovieStory::~MovieStory(void) {
	SetOnFlagFalse();
	storycount = 0;
	sentence = 0;
	line = 0;
	csv.clear();
}

void MovieStory::update(void) {
	if (storycount == csv.get<int>(0, 1)&& on3 == true && KeyEnter.down()) {//RPG�o�g���ֈڍs
		SceneManager::SetNextScene(SceneManager::SCENE_BATTLE);
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
	DownFramePrint();
	if (downframecount == 5) {			//���g���o�Ă�����1�s�ڂ�`��
		printSentence1();
	}
	if (on1 == true) {					//1�s�ڂ����ׂĕ`��ł�����2�s�ڂ�`��
		printSentence2();
	}
	if (on2== true) {					//2�s�ڂ����ׂĕ`��o������3�s�ڂ�`��
		printSentence3();
	}
}

void MovieStory::printSentence1(void) {		//��b�̂P�s�ڂ̕`�揈��
	if (System::FrameCount() % 5 == 0 && count1 < nowstory[sentence].length()) {
		count1++;
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
	}
	for (int k = 0; k < count3; k++) {
		FontAsset(U"fontB")(nowstory[sentence+2][k]).draw(startX + (X * k), startY + (Y*2));
	}
	if (count3 == nowstory[sentence+2].length()) {
		on3 = true;
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
	nowstory[sentence] = csv.get<String>(line, 0);
	nowstory[sentence + 1] = csv.get<String>(line + 1, 0);
	nowstory[sentence + 2] = csv.get<String>(line + 2, 0);
}