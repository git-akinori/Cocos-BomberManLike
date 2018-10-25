#include "Player.h"

Player::Player(cocos2d::Sprite *sprite, const cocos2d::Vec2 &position, const float &speed) {
	mSprite = sprite;
	mSpeed = speed;
	sprite->setPosition(position);
}

void Player::update() {

	if (mStatus == NONE) return;

	if (mStatus == UP) {
		translate(cocos2d::Vec2(0, 1));
	}
	if (mStatus == DOWN) {
		translate(cocos2d::Vec2(0, -1));
	}
	if (mStatus == LEFT) {
		translate(cocos2d::Vec2(-1, 0));
	}
	if (mStatus == RIGHT) {
		translate(cocos2d::Vec2(1, 0));
	}
}

void Player::translate(cocos2d::Vec2 &position) {
	auto prev_pos = mSprite->getPosition();
	mSprite->setPosition(prev_pos + position);
}



Player::eStatus Player::getStatus() {
	return mStatus;
}



void Player::setSprite(cocos2d::Sprite* sprite) {
	mSprite = sprite;
}

void Player::setPosition(const cocos2d::Vec2 &position) {
	mSprite->setPosition(position);
}

void Player::setSpeed(const float &speed) {
	mSpeed = speed;
}

void Player::setStatus(const eStatus &status) {
	mStatus = status;
}

cocos2d::Sprite* Player::getSprite() {
	return mSprite;
}