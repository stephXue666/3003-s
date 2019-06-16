#pragma once

#include "cocos2d.h"

class myScene3 :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(myScene3);

	void Enternext(Ref *pSender);

	void myScene3::ShowInfo1(Ref *pSender);
	void myScene3::ShowInfo2(Ref *pSender);
	void myScene3::ShowInfo3(Ref *pSender);

	static int hero_num;

	static int select()
	{
		return hero_num;
	}
	
};