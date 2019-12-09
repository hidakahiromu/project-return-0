#pragma once
#include<siv3d.hpp>

class PrintFrame {
public:
	void SetFrameCount(void);
	void UpFramePrint(void);
	void DownFramePrint(void);
	int upframecount;
	int downframecount;
};