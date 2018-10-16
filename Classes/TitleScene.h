#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include "cocos2d.h"

class Title : public cocos2d::Scene
{
	Node *aaa;

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void update(float delta);

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(Title);
};

#endif // __HELLOWORLD_SCENE_H__