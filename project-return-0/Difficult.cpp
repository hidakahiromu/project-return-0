#include"SceneManager.h"
#include"Difficult.h"
#include"Character.h"

String character_name;

Difficult::Difficult(void) {
	FontAsset::Register(U"DifF", 30);
	TextureAsset::Register(U"difficult_back",U"resource/images/difficult.png");
}

Difficult::~Difficult(void) {

}

void Difficult::update(void) {
	TextureAsset(U"difficult_back").draw();
	if (tes1.text.length() != 0 && tes1.text.length() <= 6 && SimpleGUI::Button(U"Œˆ’è", Vec2(525, 360), 150)) {
		SetCharacterName(tes1.text);
		SceneManager::SetNextScene(SceneManager::SCENE_MOVIE_STORY);
	}
}

void Difficult::draw(void) {
	FontAsset(U"DifF")(U"–¼‘O‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢").draw(450,250);
	SimpleGUI::TextBox(tes1, Vec2(500, 300));
}

void Difficult::SetCharacterName(String text) {
	character_name = text;
}

String Difficult::GetCharacterName(void) {
	return character_name;
}