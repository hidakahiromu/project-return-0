#pragma once

class Scene {			//�p���p�V�[��
public:
	Scene(void) {}
	virtual ~Scene(void) {}
	virtual void update(void) = 0;
	virtual void draw(void) = 0;
};