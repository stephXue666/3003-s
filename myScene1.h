#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "hero.h"
#include <vector>

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


	void getBloodProgress(cocos2d::Node* who);//����Ѫ��
	void setCurrentBlood(cocos2d::Node* who, float current);//����Ѫ��

	void createTower(int camp, float x, float y);//����������
	void towerAI(float dt);
	void soldierAI(float dt);//��ս��ai
	void remoteAI(float dt);//Զ�̵�λai

	void meleeSoldier(int camp, float x, float y);//������ս��
	void soldierATK(cocos2d::Sprite* who);
	void remoteSoldier(int camp, float x, float y);//����Զ�̱�
	void remoteATK(cocos2d::Sprite* who, int x, int y);
	void Cannon(int camp, float x, float y);//�����ڳ�
	void canATK(cocos2d::Sprite* who, int x, int y);

	void dispatchArmy(float dt);//����

	void die(cocos2d::Sprite* who);

	//void heroATK(cocos2d::Vector<cocos2d::Sprite*>::iterator it);//Ӣ�۹���
	void heroATK(float dt, int i);
	//void ATK(float dt, cocos2d::Sprite* who);
	void ATK(float dt, int i);
	void ctrlATK(float dt) { isATKabled = true; }

	//Tab��ʾ��Ϣ��
	void showBoard();
	int store_judge = 0;

	//��ʾ�̵갴ť
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

	//UI����
	void setMoney(float dt);
	void setUIData();
	void setUIBloodAndMagic();
	void setUIExpAndLevel();
	void skillUp();
	void qSkillUp(Ref*pSender);
	void wSkillUp(Ref*pSender);
	void rSkillUp(Ref*pSender);

	//ս�����
	void gainExp(cocos2d::Node* who);


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

	void QCD(float dt);
	void WCD(float dt);
	void ECD(float dt);

	void reborn();

private:
	struct property {
		int totalblood;
		int blood;
		int atk;
		int arm;
		int camp;//��Ӫ
	};

	int isClick = 0;

	bool isQabled = true;
	bool isWabled = true;
	bool isEabled = true;
	bool isATKabled = true;

	int cnt = 0;

	int tag = 0;

	std::vector<property>all;//���е�λ��������

	cocos2d::Sprite* sprite2;//��ͼ

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
