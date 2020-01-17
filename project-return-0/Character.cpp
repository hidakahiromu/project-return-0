#include"Character.h"
#include"Difficult.h"
#include"Enemy.h"
#include"Battle.h"
#include<vector>
#include <algorithm>    
#include <iterator> 

std::vector<String> Character::property;			//������
std::vector<String> Character::skills;				//�X�L��
bool Character::CharacterTurnFlag;					//�L�����N�^�[�̃^�[�����ǂ����̃t���O
bool Character::DefendFlag;							//�h��̃t���O
int Character::CharacterHp;							//�L�����N�^�[��HP

Character::Character(void) {
	Select = new Audio(U"resource/musics/rpg_select.wav");
	Enter = new Audio(U"resource/musics/rpg_enter.wav");
	Back = new Audio(U"resource/musics/rpg_back.wav");
	select_Point_X = 90;
	select_Point_Y = 400;
	CharacterHp = 100;
	HP_Width = 200;
	HP_Max = CharacterHp;
	property = {U"�񕜑�",U"�񕜖�"};
	skills = {U"for",U"printf",U"hidao"};
	FontAsset::Register(U"CharaF", 30);
	IntervalInitialize();
}

Character::~Character(void) {

}

void Character::update(void) {
	if (CharacterTurnFlag == true) {
		if (telopFlag == false) {
			if (skillFlag == true) {
				SkillSelect();
			}
			else if (propertyFlag == true) {
				PropertySelect();
			}
			else {
				SelectMenu();
			}
		}
		else {
			if (KeyZ.down()) {				//�U���A�h��A��������I�񂾎��ɂ����ɕ��򂷂�
				IntervalInitialize();
				Character::OnCharacterFlag(false);
				Enemy::OnEnemyFlag(true);
				//�G�̃t���O��on�ɂ��ēG�̃^�[���ɂ���
			}
		}
	}
}

void Character::draw(void) {
	if (CharacterTurnFlag == true) {
		MenuDraw();
		(this->*Funcdraw)();
	}
}

void Character::ChangeDraw(DRAW now) {
	switch (now){
	case Character::NONE_DRAW:
		select_Point_X = 90;
		select_Point_Y = 400;
		Funcdraw = &Character::StatusDraw;
		nowdraw = NONE_DRAW;
		break;
	case Character::ATTACK_DRAW:
		select_Point_X = 530;
		select_Point_Y = 400;
		skillFlag = true;
		Funcdraw = &Character::SkillDraw;
		nowdraw = ATTACK_DRAW;
		break;
	case Character::DEFEND_DRAW:
		Funcdraw = &Character::DefendDraw;
		nowdraw = DEFEND_DRAW;
		break;
	case Character::PROPERTY_DRAW:
		select_Point_X = 530;
		select_Point_Y = 400;
		propertyFlag = true;
		Funcdraw = &Character::PropertyDraw;
		nowdraw = PROPERTY_DRAW;
		break;
	case Character::SEARCH_DRAW:
		Funcdraw = &Character::SearchDraw;
		nowdraw = SEARCH_DRAW;
		break;
	case Character::TELOP_DRAW:
		break;
	default:
		break;
	}
}

void Character::SwitchSelect(void) {
	switch (now_select){
	case 0:
		ChangeDraw(ATTACK_DRAW);
		now_select = 0;
		break;
	case 1:
		ChangeDraw(DEFEND_DRAW);
		now_select = 0;
		break;
	case 2:
		ChangeDraw(PROPERTY_DRAW);
		now_select = 0;
		break;
	case 3:
		ChangeDraw(SEARCH_DRAW);
		now_select = 0;
		break;
	default:
		break;
	}
}


void Character::GetProperty(String tool) {				//�A�C�e�����E������		
	property.push_back(tool);
}

void Character::MenuDraw(void) {			//�U���A�h��A�������A���ׂ�̕`��
	String menu[4] = { U"�U��",U"�h��",U"������",U"���ׂ�" };
	int menuY = 380;
	for (int i = 0; i < 4; i++) {
		FontAsset(U"CharaF")(menu[i]).draw(110, menuY);
		menuY += 50;
	}
}

void Character::SelectMenu(void) {				//�U���A�h��A�������A���ׂ�̉���I�������̂�
	if (KeyZ.down()) {
		Enter->play();
		SwitchSelect();
	}
	if (now_select <= 3 && now_select > 0 && KeyUp.down()) {
		Select->playOneShot();
		now_select--;
		select_Point_Y -= 50;
	}
	if (now_select >= 0 && now_select < 3 && KeyDown.down()) {
		Select->playOneShot();
		now_select++;
		select_Point_Y += 50;
	}
	
	Triangle(select_Point_X, select_Point_Y, 25, 6).draw();

}

void Character::SkillSelect(void) {				//skill�̉���I�������̂���Ⴄ����
	if (KeyZ.down()) {
		Enter->play();
		telopFlag = true;
		nowdraw = TELOP_DRAW;
		Funcdraw = &Character::SkillsSwitch;
	}

	if (now_select <= skills.size() && now_select > 1 && KeyUp.down()) {
		Select->playOneShot();
		select_Point_Y -= 100;
		now_select -= 2;
	}
	if (now_select >= 0 && now_select+2 < skills.size() && KeyDown.down()) {
		Select->playOneShot();
		select_Point_Y += 100;
		now_select += 2;
	}
	if (now_select % 2 == 0 && now_select < skills.size()-1 && KeyRight.down()) {
		Select->playOneShot();
		select_Point_X += 200;
		now_select++;
	}
	if (now_select % 2 == 1 && now_select < skills.size() && KeyLeft.down()) {
		Select->playOneShot();
		select_Point_X -= 200;
		now_select--;
	}

	Triangle(select_Point_X,select_Point_Y,25,6).draw();
}

void Character::PropertySelect(void) {					//�������̉���������Ă����̂���������Ă��鏈��
	if (KeyZ.down()) {
		Enter->play();
		telopFlag = true;
		Funcdraw = &Character::PropertySwitch;
	}
	if (now_select <= property.size() && now_select > 1 && KeyUp.down()) {
		Select->playOneShot();
		select_Point_Y -= 100;
		now_select -= 2;
	}
	if (now_select >= 0 && now_select + 2 < property.size() && KeyDown.down()) {
		Select->playOneShot();
		select_Point_Y += 100;
		now_select += 2;
	}
	if (now_select % 2 == 0 && now_select < property.size()-1 && KeyRight.down()) {
		Select->playOneShot();
		select_Point_X += 200;
		now_select++;
	}
	if (now_select % 2 == 1 && now_select < property.size() && KeyLeft.down()) {
		Select->playOneShot();
		select_Point_X -= 200;
		now_select--;
	}

	Triangle(select_Point_X, select_Point_Y, 25, 6).draw();
}


void Character::StatusDraw(void) {				//�L�����N�^�[�̃X�e�[�^�X��`�悷�鏈���iTODO::�܂����O��SP�����Ă��Ȃ��j
	Rect(600, 380, HP_Max, 30).draw(Palette::Red);
	Rect(600, 380, CharacterHp/HP_Max*HP_Width, 30).draw(Palette::Green);
	Rect(600, 380, HP_Width, 30).drawFrame(1);
	FontAsset(U"CharaF")(U"HP").draw(600, 370,Palette::Blue);
	FontAsset(U"CharaF")(Difficult::GetCharacterName()).draw(450, 380);
}

void Character::SkillDraw(void) {				//skill�̕`��
	if (KeyX.down()) {			//�X�e�[�^�X�`��ɖ߂鎞���ʉ���nowselect��0�ɖ߂�
		skillFlag = false;
		Back->play();
		ChangeDraw(NONE_DRAW);
		now_select = 0;
	}
	int skillX = 550, skillY = 280;
	for (int i = 0; i < skills.size(); i++) {
		if (i % 2 == 0) {
			skillY += 100;
		}
		if (skillX == 550) {
			FontAsset(U"CharaF")(skills[i]).draw(skillX,skillY);
			skillX += 200;
		}
		else {
			FontAsset(U"CharaF")(skills[i]).draw(skillX,skillY);
			skillX -= 200;
		}
	}
}

void Character::DefendDraw(void) {				//�h��̕`��i�����͂��܂肷�邱�Ƃ��Ȃ������̂Ō`����������j
	telopFlag = true;
	FontAsset(U"CharaF")(Difficult::GetCharacterName(), U"�͐g�\�����I�I").draw(550,380);
	OnFlagDefend(true);
}

void Character::PropertyDraw(void) {				//�L�����N�^�[�̎�������`��
	if (KeyX.down()) {			//�X�e�[�^�X�`��ɖ߂鎞���ʉ���nowselect��0�ɖ߂�
		propertyFlag = false;
		Back->play();
		ChangeDraw(NONE_DRAW);
		now_select = 0;
	}
	int propertyX = 550, propertyY = 280;
	for (int i = 0; i < property.size(); i++) {
		if (i % 2 == 0) {
			propertyY += 100;
		}
		if (propertyX == 550) {
			FontAsset(U"CharaF")(property[i]).draw(propertyX, propertyY);
			propertyX += 200;
		}
		else {
			FontAsset(U"CharaF")(property[i]).draw(propertyX, propertyY);
			propertyX -= 200;
		}
	}
}

void Character::SearchDraw(void) {			//TODO::�e�L�X�g�f�[�^���ACSV�f�[�^����G�̏�������Ă���
	Enemy::PrintExplanation();
	if (KeyX.down()) {			//�X�e�[�^�X�`��ɖ߂鎞���ʉ���nowselect��0�ɖ߂��i�����͂���̂��H�j
		Back->play();
		ChangeDraw(NONE_DRAW);
		now_select = 0;
	}

}

void Character::SkillsSwitch(void) {			//�U���̎�ށi�����j
	if (skills[now_select] == U"for") {
		FontAsset(U"CharaF")(Difficult::GetCharacterName(),U"��for���U�����s�����I").draw(550, 380);
		FontAsset(U"CharaF")(U"�G���ɎO���̃_���[�W�I�I").draw(550, 420);
		Enemy::Damage(50);
	}
	if (skills[now_select] == U"print") {

	}

}

void Character::PropertySwitch(void) {			//�������̎�ށi���ʂȂǂ������j
	if (property[now_select]== U"�񕜑�") {
		
	}
	if (property[now_select] == U"�񕜖�") {

	}
}


void Character::IntervalInitialize(void) {					//���ԏ������i���Enemy�̃^�[������Character�̃^�[���ɂȂ�����g���j
	telopFlag = false;
	skillFlag = false;
	propertyFlag = false;
	ChangeDraw(NONE_DRAW);
	now_select = 0;
}

void Character::OnCharacterFlag(bool now) {				//true�̎�Character�̃^�[��
	CharacterTurnFlag = now;
}

void Character::Damage(int damage) {					//Enemy�Ŏg���_���[�W��������Ă��鏈��
	if (DefendFlag == true) {
		CharacterHp -= damage / 2;
	}
	else {
		CharacterHp -= damage;
	}
	if (CharacterHp <= 0) {						//HP���[���ɂȂ�΃o�g���I��
		Battle::OnFlagFinalized(false);
	}
}

void Character::OnFlagDefend(bool now) {
	DefendFlag = now;
}