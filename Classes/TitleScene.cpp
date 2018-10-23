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
	if (!Scene::init())
	{
		return false;
	}

	// ��ʃT�C�Y�A���_�A��ʒ����̍��W
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto centerPos = origin + visibleSize / 2;


	/////////////////////////////
	// �C���[�W���g�������j���[�A�C�e����ǉ��i�N���b�N�ŃQ�[���V�[���֑J�ځj
	// �����𔲂��邽�߂̃N���[�Y�A�C�R����ǉ� �����I�ɊJ�������I�u�W�F�N�g
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(Title::gameStartCallback, this));
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);

	this->addChild(menu, 1);


	/////////////////////////////
	// �^�C�g�����x���ǉ�
	auto label = Label::createWithTTF("Title", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));

	this->addChild(label, 1);


	// �w�i�ǉ�
	auto sprite_bg = Sprite::create("bg/bg2.jpg");
	sprite_bg->setScale(3.2);
	sprite_bg->setPosition(centerPos);

	this->addChild(sprite_bg, 0);



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