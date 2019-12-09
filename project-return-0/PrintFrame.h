#pragma once
#include<siv3d.hpp>

class PrintFrame {
public:
	void SetFrameCount(void);				//count‚Ì‰Šú‰»
	void UpFramePrint(void);				//‰æ–Êã‚É”’˜g‚ğ•`‰æ‚·‚éˆ—
	void DownFramePrint(void);				//‰æ–Ê‰º‚É”’˜g‚ğ•`‰æ‚·‚éˆ—	
	int upframecount;						//UpFramePrint‚ÌŠÖ”‚Åg‚¤•`‰æŠÇ——p•Ï”
	int downframecount;						//downFramePrint‚ÌŠÖ”‚Åg‚¤•`‰æŠÇ——p•Ï”
};