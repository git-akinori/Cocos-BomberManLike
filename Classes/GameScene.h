#pragma once

#include "cocos2d.h"

class Game : public cocos2d::Scene
{

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	//void update(float delta);

	//void pauseMenuCallback();

	// implement the "static create()" method manually
	CREATE_FUNC(Game);
};