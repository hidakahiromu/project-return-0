#include"Character.h"

int Character::characterHp;
std::vector<String> Character::property;
std::vector<String> Character::skills;

Character::Character(void) {
	characterHp = 100;
	property = {U"‰ñ•œ‘",U"‰ñ•œ–ò"};
	skills = {U"for",U"printf",U"hidao",U"nisi"};
}

Character::~Character(void) {

}

void Character::update(void) {

}

void Character::draw(void) {

}

int Character::SetHp(void) {
	return characterHp;
}

void Character::GetHp(int nexthp) {
	characterHp = nexthp;
}


void Character::GetProperty(String tool) {
	property.push_back(tool);
}

void Character::SetProperty(std::vector<String> &tool) {			//¡‚Ì‚¿•¨‚ğ“n‚·ˆ—
	for (int i = 0; i < property.size(); i++) {
		tool.push_back(property[i]);
	}
}

void Character::GetTool(std::vector<String>& tool) {				//¡‚Ì‚¿•¨‚ğ‚à‚ç‚Á‚Ä‚­‚éˆ—
	property = {};
	for (int j = 0; j < tool.size(); j++) {
		property.push_back(tool[j]);
	}
}

void Character::SetSkills(std::vector<String>& skill) {
	for (int k = 0; k < skills.size(); k++) {
		skill.push_back(skills[k]);
	}
}

void Character::GetSkills(std::vector<String>& skill) {
	skills = {};
	for (int s = 0; s < skill.size(); s++) {
		skills.push_back(skill[s]);
	}
}