#include"Character.h"

int characterHp=100;					//キャラクターのHP
std::vector<String> property = {U"火薬草",U"回復役"};			//キャラクターの持ち物
//String retool[10] = {};
int haveProperty=0;

Character::Character(void) {
	characterHp = 100;
}

Character::~Character(void) {

}

void Character::update(void) {

}

void Character::draw(void) {

}

int Character::NowHp(void) {
	return characterHp;
}

void Character::GetHp(int nexthp) {
	characterHp = nexthp;
}


void Character::GetProperty(String tool) {
	property.push_back(tool);
}

void Character::NowProperty(std::vector<String> &tool) {
	haveProperty = property.size();
	for (int i = 0; i < haveProperty; i++) {
		tool[i] = property[i];
	}
}
