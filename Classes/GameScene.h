#pragma once

#include "cocos2d.h"
#include "Player.h"

class Game : public cocos2d::Scene
{
	std::shared_ptr<Player> player1;

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void update(float delta);

	// キーを押したとき
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	// キーを離したとき
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	//void pauseMenuCallback();

	// implement the "static create()" method manually
	CREATE_FUNC(Game);
};