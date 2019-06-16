
#include "myScene3.h"
#include "myScene2.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* myScene2::createScene()
{
	return myScene2::create();
}

auto audio = CocosDenshion::SimpleAudioEngine::getInstance();

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in myScene2.cpp\n");
}

bool myScene2::init()
{
	if (!Scene::init())
	{
		return false;
	}

	audio->playEffect("sound/sta.mp3", false, 1.0f, 1.0f, 1.0f);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	auto label1 = Label::createWithTTF("START", "fonts/wow1.ttf", 56);
	if (label1 == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}

	auto menuitem1 = MenuItemLabel::create(label1, CC_CALLBACK_1(myScene2::Enternext, this));
	auto menu1 = Menu::create(menuitem1, NULL);
	menu1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 300));
	this->addChild(menu1, 1);

	auto label3 = Label::createWithTTF("EXIT", "fonts/wow1.ttf", 56);
	if (label3 == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	auto menuitem3 = MenuItemLabel::create(label3, CC_CALLBACK_1(myScene2::menuCloseCallback, this));
	auto menu3 = Menu::create(menuitem3, NULL);
	menu3->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 500));
	this->addChild(menu3, 1);


}

void myScene2::Enternext(Ref *pSender)
{
	audio->pauseAllEffects();
	Director::getInstance()->replaceScene(myScene3::createScene());

}

void myScene2::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}
