#include "GameScene.h"
#include "AudioEngine.h"
#include <iostream>

USING_NS_CC;

Scene* Game::createScene()
{
	return Game::create();
}

// CSVファイル群をまとめて読み込む
void csvFilesLoader() {

}

void createSpritesFromCSV(std::map<std::string, std::string, Rect, Vec2> _fileNames) {
	for (auto filemap : _fileNames) {
		auto sf = Sprite::createWithSpriteFrameName(filemap.second);
	}
}

bool Game::init() {
	if (!Scene::init()) {
		return false;
	}

	// 読み込むファイルのリスト
	// fix: 後でCSVから読み込む形に変更したい
	//		が、通信周りを優先するため後回し
	// データ構造 :
	// 		filepath, 
	//		Portion(startPosX, startPosY, endPosX, endPosY),
	//		Pos(spritePosX, spritePosY) 
	//		(Roop(startPosX, startPosY, endPosX, endPosY)) あれば
	//std::map<std::string, Rect, Vec2, Rect> fileNames = {
	//	{ "floors128x32.png", Rect(0, 0, 15, 15), Vec2(100, 100), Rect(0, 0, 500, 500) },
	//	{ "objects64x32.png", Rect(0, 0, 31, 31), Vec2(50, 50), Rect(0, 0, 0, 0) }
	//};

	// CSVからスプライトを作成
	//createSpritesFromCSV(fileNames);

	auto fileNames = {
		"floors128x32",
		"objects64x32",
	};


	auto sprite = Sprite::create(fileNames["floors"]);
	sprite->setPosition(100, 100);
	this->addChild(sprite);
}