#pragma once

#include "cocos2d.h"

class Player {
public:
	enum eStatus {
		UP, DOWN, LEFT, RIGHT, NONE
	};

private:
	cocos2d::Sprite *mSprite;
	float mSpeed;
	eStatus mStatus;

public :
	Player(cocos2d::Sprite *sprite, const cocos2d::Vec2 &position, const float &speed);

	void update();
	void translate(cocos2d::Vec2 &position);

	eStatus getStatus();

	void setSprite(cocos2d::Sprite* sprite);
	void setPosition(const cocos2d::Vec2 &position);
	void setSpeed(const float &speed);
	void setStatus(const eStatus &status);

	cocos2d::Sprite* getSprite();
};