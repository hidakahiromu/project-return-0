#include"SceneManager.h"
#include"Difficult.h"
#include"Character.h"

String character_name;

Difficult::Difficult(void) {
	FontAsset::Register(U"DifF", 30);
}

Difficult::~Difficult(void) {

}

void Difficult::update(void) {
	if (SimpleGUI::Button(U"Œˆ’è", Vec2(600, 360), 150)) {
		SetCharacterName(tes1.text);
		SceneManager::SetNextScene(SceneManager::SCENE_MOVIE_STORY);
	}
}

void Difficult::draw(void) {
	FontAsset(U"DifF")(U"–¼‘O‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢").draw(450,250);
	SimpleGUI::TextBox(tes1, Vec2(600, 300));
}

void Difficult::SetCharacterName(String text) {
	character_name = text;
}

String Difficult::GetCharacterName(void) {
	return character_name;
}