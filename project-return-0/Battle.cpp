#include"SceneManager.h"
#include"Battle.h"

Battle::Battle(void) {
	nowdraw = DRAW1;
	FuncDraw = &Battle::PrintSelectMenu;
	FontAsset::Register(U"FB",30);
	nowselect = 0;
	coordinateX = 110;
	coordinateY = 380;
	frame1X = -200, frame1Y = 350;
	frame2X = 520, frame2Y = 350;
	x = coordinateX-10, y = coordinateY-5;
	menu[0] = U"攻撃";
	menu[1] = U"防御";
	menu[2] = U"道具";
	menu[3] = U"調べる";
}

Battle::~Battle(void) {

}

void Battle::update(void) {
	if (KeyEnter.down()) {//エンディングへ移行
		SceneManager::SetNextScene(SceneManager::SCENE_ENDING);
	}
	SelectMenu();
	
	
}

void Battle::draw(void) {
	(this->*FuncDraw)();
	PrintFrame1();
	PrintFrame2();
}

void Battle::SelectMenu(void) {					//バトルコマンド選択用操作関数
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

void Battle::DrawCommand1(void) {

}

void Battle::ChangeDraw(NOWDRAW next) {
	nowdraw = next;
	switch (nowdraw){
	case Battle::DRAW1:
		FuncDraw = &Battle::PrintSelectMenu;
		break;
	case Battle::DRAW2:
		FuncDraw = &Battle::DrawCommand1;
		break;
	default:
		break;
	}
}

void Battle::PrintFrame1(void) {
	if (frame1X != 50 && System::FrameCount() % 4 == 0) {
		frame1X += 50;
	}
	Rect(frame1X, frame1Y, 200, 300).drawFrame(3, Palette::White);
}

void Battle::PrintFrame2(void) {
	if (frame2X != 270 && System::FrameCount() % 4 == 0) {
		frame2X -= 50;
	}
	Rect(frame2X, frame2Y, 960, 300).drawFrame(3, Palette::White);
}