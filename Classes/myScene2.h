#pragma once

#include "cocos2d.h"

class myScene2 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(myScene2);

	void Enternext1(Ref *pSender);

	void Enternext3(Ref *pSender);

	void menuCloseCallback(Ref* pSender);

	int GameMode = 0;

};