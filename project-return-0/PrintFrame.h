#pragma once
#include<Siv3D.hpp>

class PrintFrame {
public:
	void SetFrameCount(void);				//count�̏�����
	void UpFramePrint(void);				//��ʏ�ɔ��g��`�悷�鏈��
	void DownFramePrint(void);				//��ʉ��ɔ��g��`�悷�鏈��	
	int upframecount;						//UpFramePrint�̊֐��Ŏg���`��Ǘ��p�ϐ�
	int downframecount;						//downFramePrint�̊֐��Ŏg���`��Ǘ��p�ϐ�
};