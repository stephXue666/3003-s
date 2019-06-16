#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "hero.h"
#include <vector>
#include <cmath>

class myunite :public cocos2d::Sprite
{
public:

	int camp;
};

class myScene1:public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(myScene1);

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);


	void getBloodProgress(cocos2d::Node* who);//创建血条
	void setCurrentBlood(cocos2d::Node* who, float current);//更新血量

	void createTower(int camp, float x, float y);//创建防御塔
	void towerAI(float dt);
	void soldierAI(float dt);//近战兵ai
	void remoteAI(float dt);//远程单位ai

	void meleeSoldier(int camp, float x, float y);//创建近战兵
	void soldierATK(cocos2d::Sprite* who);
	void remoteSoldier(int camp, float x, float y);//创建远程兵
	void remoteATK(cocos2d::Sprite* who, int x, int y);
	void Cannon(int camp, float x, float y);//创建炮车
	void canATK(cocos2d::Sprite* who, int x, int y);

	void dispatchArmy(float dt);//出兵

	void die(cocos2d::Sprite* who);

	//void heroATK(cocos2d::Vector<cocos2d::Sprite*>::iterator it);//英雄攻击
	void heroATK(float dt, int i);
	//void ATK(float dt, cocos2d::Sprite* who);
	void ATK(float dt, int i);
	void ctrlATK(float dt) { isATKabled = true; }





	//Tab显示信息板
	void showBoard();
	int store_judge = 0;

	//显示商店按钮
	void showStore(Ref* pSender);
	void closeStore(Ref* pSender);
	int chosen_equip_number = 0;
	void buyEquip(Ref* pSender);
	void sellEquip(Ref* pSender, int, int);
	void show_equip1(Ref*pSender);
	void show_equip2(Ref*pSender);
	void show_equip3(Ref*pSender);
	void show_equip4(Ref*pSender);
	void show_equip5(Ref*pSender);
	void show_equip6(Ref*pSender);
	void show_equip7(Ref*pSender);
	void show_equip8(Ref*pSender);
	void show_equip9(Ref*pSender);
	void show_equip10(Ref*pSender);
	void show_equip11(Ref*pSender);
	void show_equip12(Ref*pSender);

	//UI界面
	void setMoney(float dt);
	void setUIData();
	void setUIBloodAndMagic();
	void setUIExpAndLevel();
	void skillUp();
	void qSkillUp(Ref*pSender);
	void wSkillUp(Ref*pSender);
	void rSkillUp(Ref*pSender);

	//战斗相关
	void gainExp(cocos2d::Node* who);


	bool isQabled = true;
	bool isWabled = true;
	bool isRabled = true;
	bool isATKabled = true;
	void QCD(float dt);
	void WCD(float dt);
	void RCD(float dt);

	static bool isQpressed;
	static void pressQ() {
		isQpressed = true;
	}
	static bool isWpressed;
	static void pressW() {
		isWpressed = true;
	}
	static bool isRpressed;
	static void pressR() {
		isRpressed = true;
	}
	static bool flash;
	static void isflash() {
		flash = true;
	}


private:
	struct property {
		int totalblood;
		int blood;
		int atk;
		int arm;
		int camp;//阵营
	};

	int isClick = 0;

	int cnt = 0;

	int tag = 0;

	std::vector<property>all;//所有单位基本属性

	cocos2d::Sprite* sprite2;//地图

	Hero* hero;
	Hero* AI;
	cocos2d::EventListenerMouse* _mouseListener;

	cocos2d::Vector<cocos2d::Sprite*> soldier1;
	cocos2d::Vector<cocos2d::Sprite*> soldier2;
	cocos2d::Vector<cocos2d::Sprite*> remote1;
	cocos2d::Vector<cocos2d::Sprite*> remote2;
	cocos2d::Vector<cocos2d::Sprite*> tower1;
	cocos2d::Vector<cocos2d::Sprite*> tower2;
	
};

class Soldier:public myunite
{
public:
	int blood = 50;
	int atk = 10;
	int arm = 3;

	int camp;

private:
	
};

class Tower :public myunite
{
public:
	int blood = 500;
	int atk = 30;
	int arm = 5;

	int camp;
};