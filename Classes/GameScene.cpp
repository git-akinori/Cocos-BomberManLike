#include "GameScene.h"
#include "AudioEngine.h"
#include <iostream>

USING_NS_CC;

Scene* Game::createScene()
{
	return Game::create();
}

// CSV�t�@�C���Q���܂Ƃ߂ēǂݍ���
void csvFilesLoader() {

}

//void createSpritesFromCSV(std::map<std::string, std::string> _fileNames) {
//	for (auto filemap : _fileNames) {
//		auto sf = Sprite::createWithSpriteFrameName(filemap.second);
//	}
//}

bool Game::init() {
	if (!Scene::init()) {
		return false;
	}

	// �t�@�C�����ɊȒP�Ȗ��O��t���ČĂяo���₷������
	std::map<std::string, std::string> fileNames = {
		{"floors",  "floors128x32.png"},
		{"objects", "objects64x32.png"},
	};

	std::vector<int> flag_map = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	// ��ʃT�C�Y�A���_�i�����j�A��ʒ������W
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto centerPos = origin + visibleSize / 2;

	// update() �L����
	this->scheduleUpdate();

	// �w�i�ǉ�
	// �T�C�Y�ύX�A���W�w��
	auto sprite_bg = Sprite::create("bg/bg1.jpg");
	sprite_bg->setScale(3.2);
	sprite_bg->setPosition(centerPos);
	this->addChild(sprite_bg, 0);


	// ���ǉ��i�^�C���}�b�v�j
	// �T�C�Y�ύX�A���W�w��
	auto map = TMXTiledMap::create("maps/map_base.tmx");
	float map_scale = 1.7;
	map->setScale(map_scale);
	//map->setAnchorPoint(Vec2(0.5, 0.5));
	map->setPosition(centerPos - map->getContentSize() * map_scale / 2);
	this->addChild(map, 1, 99);

	// �v���C���[�ǉ�
	// �T�C�Y�ύX�A���W�w��
	auto sprite = Sprite::create("charamap288x256.png", Rect(25, 129, 24, 32));
	player1 = std::make_shared<Player>(Player(sprite, Vec2(0, 0), 1));
	map->addChild(sprite, 1);

	// �L�[����
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(Game::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(Game::onKeyReleased, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

}

void Game::update(float delta){
	player1->update();
}

void Game::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {

	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW) {
		player1->setStatus(Player::eStatus::UP);
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
		player1->setStatus(Player::eStatus::DOWN);
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
		player1->setStatus(Player::eStatus::LEFT);
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		player1->setStatus(Player::eStatus::RIGHT);
	}
	log("Key with keycode %d pressed", keyCode);
}

void Game::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW
		|| player1->getStatus() != Player::eStatus::UP) {
		player1->setStatus(Player::eStatus::NONE);
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW
		|| player1->getStatus() != Player::eStatus::DOWN) {
		player1->setStatus(Player::eStatus::NONE);
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW
		|| player1->getStatus() != Player::eStatus::LEFT) {
		player1->setStatus(Player::eStatus::NONE);
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW
		|| player1->getStatus() != Player::eStatus::RIGHT) {
		player1->setStatus(Player::eStatus::NONE);
	}
}