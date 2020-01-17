#include"PrintFrame.h"


void PrintFrame::SetFrameCount(void) {
	upframecount = 0;
	downframecount = 0;
}


void PrintFrame::UpFramePrint(void) {				//è„ÇÃâÊñ Ç…îíògÇï`âÊÇ∑ÇÈèàóù
	if (upframecount == 0 &&  System::FrameCount() % 4 == 0) {
		upframecount++;
		Rect(550, 310, 180, 50).drawFrame(5, Palette::White);
	}
	else if (upframecount == 1 && System::FrameCount() % 4 == 0) {
		upframecount++;
		Rect(450, 260, 380, 100).drawFrame(5, Palette::White);
	}
	else if (upframecount == 2 && System::FrameCount() % 4== 0) {
		upframecount++;
		Rect(350, 210, 580, 150).drawFrame(5, Palette::White);
	}
	else if (upframecount == 3 && System::FrameCount() % 4 == 0) {
		upframecount++;
		Rect(250, 160, 780, 200).drawFrame(5, Palette::White);
	}
	else if (upframecount == 4 && System::FrameCount() % 4 == 0) {
		upframecount++;
		Rect(150, 110, 980, 250).drawFrame(5, Palette::White);
	}
	else if (upframecount == 5) {
		Rect(50, 50, 1180, 300).drawFrame(5, Palette::White);
	}
}

void PrintFrame::DownFramePrint(void) {					//â∫âÊñ Ç…îíògÇï`âÊÇ∑ÇÈèàóù
	if (downframecount == 0 && System::FrameCount() % 4 == 0) {
		downframecount++;
		Rect(550, 360, 180, 50).drawFrame(5, Palette::White);
	}
	else if (downframecount == 1 && System::FrameCount() % 4 == 0) {
		downframecount++;
		Rect(450, 410, 380, 100).drawFrame(5, Palette::White);
	}
	else if (downframecount == 2 && System::FrameCount() % 4 == 0) {
		downframecount++;
		Rect(350, 460, 580, 150).drawFrame(5, Palette::White);
	}
	else if (downframecount == 3 && System::FrameCount() % 4 == 0) {
		downframecount++;
		Rect(250, 510, 780, 200).drawFrame(5, Palette::White);
	}
	else if (downframecount == 4 && System::FrameCount() % 4 == 0) {
		downframecount++;
		Rect(150, 560, 980, 250).drawFrame(5, Palette::White);
	}
	else if (downframecount == 5) {
		Rect(50, 360, 1180, 300).drawFrame(5, Palette::White);
	}
}