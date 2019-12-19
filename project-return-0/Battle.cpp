#include"SceneManager.h"
#include"Battle.h"

Battle::Battle(void) {
	CharacterHP = Character::SetHp();
	FixHpC = Character::SetHp();
	nowproperty = {};
	nowskills = {};
	Character::SetProperty(nowproperty);
	Character::SetSkills(nowskills);
	nowdraw = NONE_SELECT;
	FuncDraw = &Battle::StatusPrint;
	FontAsset::Register(U"FB",30);
	nowselect = 0;
	coordinateX = 110;
	coordinateY = 380;
	frame1X = -200, frame1Y = 350;
	frame2X = 520, frame2Y = 350;
	x = coordinateX-10, y = coordinateY-5;
	menu[0] = U"�U��";
	menu[1] = U"�h��";
	menu[2] = U"����";
	menu[3] = U"���ׂ�";
}

Battle::~Battle(void) {

}

void Battle::update(void) {
	if(CharacterHP <= 0) {//�G���f�B���O�ֈڍs
		SceneManager::SetNextScene(SceneManager::SCENE_ENDING);
	}
	SelectMenu();
	DecisionSelect();
	if (KeyA.down()) {				//�e�X�g�pA�{�^���������Ƒ̗͂�����
		CharacterHP -= 15;
	}
}

void Battle::draw(void) {
	(this->*FuncDraw)();
	PrintSelectMenu();
	PrintFrame1();
	PrintFrame2();
}

void Battle::SelectMenu(void) {					//�o�g���R�}���h�I��p����֐�
	if ( KeyDown.down()) {
		if (nowselect >= 0 && nowselect < 3) {
			nowselect += 1;
			y += 50;
		}
	}
	if (KeyUp.down()) {
		if (nowselect > 0 && nowselect <= 3) {
			nowselect -= 1;
			y -= 50;
		}
	}


}

void Battle::PrintSelectMenu(void) {
	if (frame1X == 50) {
		Rect(x, y, 100, 50).drawFrame(3, Palette::White);
		FontAsset(U"FB")(menu[0]).draw(coordinateX, coordinateY);
		FontAsset(U"FB")(menu[1]).draw(coordinateX, coordinateY + 50);
		FontAsset(U"FB")(menu[2]).draw(coordinateX, coordinateY + 100);
		FontAsset(U"FB")(menu[3]).draw(coordinateX, coordinateY + 150);
	}
}


void Battle::ChangeDraw(NOWDRAW nextdraw) {
	nowdraw = nextdraw;
	switch (nowdraw){
	case Battle::NONE_SELECT:
		FuncDraw = &Battle::StatusPrint;;
		break;
	case Battle::ATTACK_SELECT:
		FuncDraw = &Battle::SkillPrint ;
		break;
	case Battle::DEFEND_SELECT:
		FuncDraw = &Battle::DefendPrint;
		break;
	case Battle::TOOL_SELECT:
		FuncDraw = &Battle::ToolPrint;
		break;
	case Battle::SEARCH_SELECT:
		FuncDraw = &Battle::SearchPrint;
		break;
	default:
		break;
	}
}

void Battle::DecisionSelect(void) {	
	if (nowselect == 0 && KeyEnter.down()) {
		ChangeDraw(ATTACK_SELECT);
	}
	if (nowselect == 1 && KeyEnter.down()) {
		ChangeDraw(DEFEND_SELECT);
	}
	if (nowselect == 2 && KeyEnter.down()) {
		ChangeDraw(TOOL_SELECT);
	}
	if (nowselect == 3 && KeyEnter.down()) {
		ChangeDraw(SEARCH_SELECT);
	}
}

void Battle::PrintFrame1(void) {					//���g��`�������i���j
	if (frame1X != 50 && System::FrameCount() % 4 == 0) {
		frame1X += 50;
	}
	Rect(frame1X, frame1Y, 200, 300).drawFrame(3, Palette::White);
}

void Battle::PrintFrame2(void) {					//���g��`�������i�E�j
	if (frame2X != 270 && System::FrameCount() % 4 == 0) {
		frame2X -= 50;
	}
	Rect(frame2X, frame2Y, 960, 300).drawFrame(3, Palette::White);
}

void Battle::StatusPrint(void) {
	Rect(600, 380, 200, 30).draw(Palette::Red);
	Rect(600, 380, CharacterHP / FixHpC * 200, 30).draw(Palette::Green);
	FontAsset(U"FB")(U"HP").draw(600, 370,Palette::Blue);
}

void Battle::SkillPrint(void) {		
	if (KeyBackspace.down()) {				//BackSpase�������ƃX�^�b�c�\�L�ɖ߂�
		ChangeDraw(NONE_SELECT);
	}
	int skillX = 600, skillY = 380;
	for (int i = 0; i < nowskills.size(); i++) {
		if (i % 2 == 0) {			//��o�͂�������s���鏈��
			skillY += 50;
		}
		if (skillX == 600) {			
			FontAsset(U"FB")(nowskills[i]).draw(skillX, skillY);
			skillX += 100;
		}
		else {
			FontAsset(U"FB")(nowskills[i]).draw(skillX, skillY);
			skillX -= 100;
		}
	}
}

void Battle::DefendPrint(void) {
	if (KeyBackspace.down()) {			//BackSpase�������ƃX�^�b�c�\�L�ɖ߂�
		ChangeDraw(NONE_SELECT);
	}
}

void Battle::ToolPrint(void) {
	if (KeyBackspace.down()) {				//BackSpase�������ƃX�^�b�c�\�L�ɖ߂�
		ChangeDraw(NONE_SELECT);
	}
	int toolX = 600, toolY = 380;
	for (int j = 0; j < nowproperty.size(); j++) {
		if (j % 2 == 0) {		//��o�͂�������s���鏈��
			toolY += 100;
		}
		if (toolX == 600) {
			FontAsset(U"FB")(nowproperty[j]).draw(toolX, toolY);
			toolX += 100;
		}
		else {
			FontAsset(U"FB")(nowproperty[j]).draw(toolX, toolY);
			toolX -= 100;
		}
	}
}

void Battle::SearchPrint(void) {
	if (KeyBackspace.down()) {				//BackSpase�������ƃX�^�b�c�\�L�ɖ߂�
		ChangeDraw(NONE_SELECT);
	}
}