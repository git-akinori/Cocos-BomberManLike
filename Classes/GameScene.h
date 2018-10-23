#pragma once

#include "cocos2d.h"

class Game : public cocos2d::Scene
{

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	//void update(float delta);

	//void pauseMenuCallback();

	// implement the "static create()" method manually
	CREATE_FUNC(Game);
};