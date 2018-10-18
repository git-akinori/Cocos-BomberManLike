#include "AudioEngine.h"
#include "TitleScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* Title::createScene()
{
	return Title::create();
}

// �t�@�C����������Ȃ������Ƃ��ɒʏ�̃G���[���b�Z�[�W�̑���̃��b�Z�[�W��\������
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in TitleScene.cpp\n");
}

// �C���X�^���X�̏������������\�b�h
bool Title::init()
{
	//////////////////////////////
	// ��ɐe�N���X�̏������������s��
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	//// update() �� �L����
	//this->scheduleUpdate();
	//// aaa �� �X�v���C�g ������
	//aaa = Sprite::create("bomber.png");
	//if (aaa == nullptr)
	//{
	//	problemLoading("'bomber.png'");
	//}
	//else
	//{
	//	// position the sprite on the center of the screen
	//	aaa->setPosition(origin + visibleSize / 2);
	//	this->addChild(aaa, 2);
	//}



	/////////////////////////////
	// �C���[�W���g�������j���[�A�C�e����ǉ��i�N���b�N�Ńv���O�����I���j

	// �����𔲂��邽�߂̃N���[�Y�A�C�R����ǉ� �����I�ɊJ�������I�u�W�F�N�g
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(Title::gameStartCallback, this));

	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));
	}

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// add a label shows "Title"
	// create and initialize a label

	auto label = Label::createWithTTF("Title", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("slash_fire.png");
	if (sprite == nullptr)
	{
		problemLoading("'slash_fire.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
	}
	return true;
}


//void Title::update(float delta) {
//	aaa->setPosition(Vec2(aaa->getPosition().x + 0.1, aaa->getPosition().y));
//}


void Title::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);
}


void Title::gameStartCallback(Ref* pSender) {
	Director::getInstance()->replaceScene(TransitionFade::create(2, Game::createScene()));
}