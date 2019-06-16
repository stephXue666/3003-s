
#include "myScene3.h"
#include "myScene1.h"
#include "SimpleAudioEngine.h"
//#include "ui/CocosGUI.h"

USING_NS_CC;

int myScene3::hero_num = 0;



Scene* myScene3::createScene()
{
	return myScene3::create();
}

auto audio1 = CocosDenshion::SimpleAudioEngine::getInstance();

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in myScene3.cpp\n");
}

bool myScene3::init()
{
	if (!Scene::init())
	{
		return false;
	}

	audio1->playEffect("sound/se.mp3", false, 1.0f, 1.0f, 1.0f);

	auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//“英雄选择”标签
	{
		//创建词典类实例，将xml文件加载到词典中
		auto *chnStrings = Dictionary::createWithContentsOfFile("2.xml");
		//通过xml文件中的key获取value
		const char *str_topic = ((String*)chnStrings->objectForKey("string1"))->getCString();

		//创建一个标签显示出来
		auto* label_topic = Label::create(str_topic, "wow1", 48);
		// 位置
		label_topic->setPosition(Vec2(origin.x + visibleSize.width / 2-390,
			                          origin.y + visibleSize.height+10-label_topic->getContentSize().height));
		//把这个标签加到这个层上
		this->addChild(label_topic, 0);
	}

    //英雄选择——蜡笔小新
	{
		auto sprite_hero1 = Sprite::create("head/xin.png");
		auto menuitem1 = MenuItemLabel::create(sprite_hero1, CC_CALLBACK_1(myScene3::ShowInfo1, this));
		auto menu = Menu::create(menuitem1, NULL);
		menu->setPosition(Vec2(150,480));
		this->addChild(menu, 1);
	}

	//英雄选择——佐助
	{
		auto sprite_hero2 = Sprite::create("head/sasuke.png");
		auto menuitem2 = MenuItemLabel::create(sprite_hero2, CC_CALLBACK_1(myScene3::ShowInfo2, this));
		auto menu = Menu::create(menuitem2, NULL);
		menu->setPosition(Vec2(150,320));
		this->addChild(menu, 2);
	}

	//英雄选择——死神
	{
		auto sprite_hero3 = Sprite::create("head/death.png");
		auto menuitem3 = MenuItemLabel::create(sprite_hero3, CC_CALLBACK_1(myScene3::ShowInfo3, this));
		auto menu = Menu::create(menuitem3, NULL);
		menu->setPosition(Vec2(150,160));
		this->addChild(menu, 3);
	}

	//“确定”按钮
	{
		auto *chnStrings = Dictionary::createWithContentsOfFile("2.xml");
		const char *str_start = ((String*)chnStrings->objectForKey("string2"))->getCString();

		auto* label_start = Label::create(str_start, "wow1", 42);
		if (label_start == nullptr)
		{
			problemLoading("'fonts/Marker Felt.ttf'");
		}
		auto menuitem0 = MenuItemLabel::create(label_start, CC_CALLBACK_1(myScene3::Enternext, this));
		auto menu = Menu::create(menuitem0, NULL);
		menu->setPosition(Vec2(visibleSize.width/2-390, visibleSize.height - 590));
		this->addChild(menu, 0);
	}

}

void myScene3::Enternext(Ref *pSender)
{
	audio1->pauseAllEffects();

	Director::getInstance()->replaceScene(myScene1::createScene());
}

void myScene3::ShowInfo1(Ref *pSender)
{

	auto sprite1 = Sprite::create("info/xin.png");
	if (sprite1 == nullptr)
	{
		problemLoading("'xin.png'");
	}
	else
	{
		// 调位置
		sprite1->setPosition(Vec2(688,320));
		//调大小
		sprite1->setScale(0.9);
		// add the sprite as a child to this layer
		this->addChild(sprite1, 0);
	}

	hero_num = 1;
}

void myScene3::ShowInfo2(Ref *pSender)
{

	auto sprite2 = Sprite::create("info/sasuke.png");
	if (sprite2 == nullptr)
	{
		problemLoading("'sasuke.png'");
	}
	else
	{
		// 调位置
		sprite2->setPosition(Vec2(688, 320));
		//调大小
		sprite2->setScale(0.9);
		// add the sprite as a child to this layer
		this->addChild(sprite2, 0);
	}

	hero_num = 2;
}

void myScene3::ShowInfo3(Ref *pSender)
{

	auto sprite3 = Sprite::create("info/death.png");
	if (sprite3 == nullptr)
	{
		problemLoading("'death.png'");
	}
	else
	{
		// 调位置
		sprite3->setPosition(Vec2(688, 320));
		//调大小
		sprite3->setScale(0.9);
		// add the sprite as a child to this layer
		this->addChild(sprite3, 0);

	}

	hero_num = 3;
}