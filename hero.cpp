
#include "hero.h"
#include "myScene1.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

//（装备属性顺序：1血量上限，2血量，3蓝量上限，4蓝量，5攻击，6攻速, 7移速，8护甲，9魔抗，10金钱）
Hero::heroproperty Hero::equip[12] = { { 0,  0,  0,  0,62, 15, 0,  0,  0,5500 } ,
{ 0,  0,  0,  0, 0,  0,65,  0,  0, 500 } ,
{ 200,200,150,150,15, 15, 0,  0,  0,3000 } ,
{ 200,200,  0,  0, 0,  0, 0, 90,  0,4250 } ,
{ 0,  0,250,250, 0,  0, 0,  0,  0,1300 } ,
{ 600,600,600,600, 0,  0,12,  0,  0,5500 } ,
{ 0,  0,  0,  0, 0,  0, 8, 66,  0,3800 } ,
{ 0,  0,  0,  0, 0,100, 0,  0,  0,3500 } ,
{ 0,  0,800,800, 0,  0, 0,  0,  0,3600 } ,
{ 0,  0,  0,  0, 0,  0, 0,  0, 30,1200 } ,
{ 0,  0,  0,  0,10, 25, 0,  0,  0,1000 } ,
{ 0,  0,  0,  0,65, 12,12,  0,  0,4500 } };





void Hero::puton(int equipTag)
{
	int p = equipTag - 1;
	hero.totalblood += equip[p].totalblood;
	hero.blood += equip[p].blood;
	hero.totalmagic += equip[p].totalmagic;
	hero.magic += equip[p].magic;
	hero.atk += equip[p].atk;
	hero.atkspeed += equip[p].atkspeed;
	hero.speed += equip[p].speed;
	hero.armor += equip[p].armor;
	hero.m_dfs += equip[p].m_dfs;
	hero.money -= equip[p].money;
	equipcnt++;
	equipsit[equipcnt] = 1;
}

void Hero::takeoff(int equipTag)
{
	int p = equipTag - 1;
	hero.totalblood -= equip[p].totalblood;
	hero.blood -= equip[p].blood;
	hero.totalmagic -= equip[p].totalmagic;
	hero.magic -= equip[p].magic;
	hero.atk -= equip[p].atk;
	hero.atkspeed -= equip[p].atkspeed;
	hero.speed -= equip[p].speed;
	hero.armor -= equip[p].armor;
	hero.m_dfs -= equip[p].m_dfs;
	hero.money += equip[p].money;
	hero.money -= 100;
	equipcnt--;

}

void death::AfirstSkill()
{
	//myScene1::arsorone();
	myScene1::pressQ();
}
int death::BfirstSkill(float x, float y)
{
	int damage = 0;

	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	// play a sound effect, just once.
	audio->playEffect("sound/Q_death.mp3", false, 2.0f, 2.0f, 2.0f);
	switch (qlevel)
	{
	case 1:
		hero.magic -= 60;
		damage = 80;
		break;
	case 2:
		hero.magic -= 80;
		damage = 120;
		break;
	case 3:
		hero.magic -= 100;
		damage = 160;
		break;
	case 4:
		hero.magic -= 120;
		damage = 200;
		break;
	}
	damage += hero.atk*0.4;
	Action* disappear = FadeOut::create(0.3);
	auto sprite = Sprite::create("skill/duang/Q_death.png");
	sprite->setScale(0.4);
	auto rotateTo = RotateTo::create(0.3f, 720.0f);
	sprite->runAction(rotateTo);
	sprite->setPosition(Vec2(20, 30));
	auto moveBy = MoveBy::create(0.2, Vec2(x, y));
	auto seq = Sequence::create(moveBy, disappear, nullptr);
	sprite->runAction(seq);
	this->addChild(sprite);
	return damage;
}
void death::AsecondSkill()
{
	switch (wlevel)
	{
	case 1:
		hero.magic -= 60;
		hero.armor += 40;
		break;
	case 2:
		hero.magic -= 80;
		hero.armor += 60;
		break;
	case 3:
		hero.magic -= 100;
		hero.armor += 80;
		break;
	case 4:
		hero.magic -= 120;
		hero.armor += 100;
		break;
	}
	Action* disappear = CCFadeOut::create(2);
	auto sprite = Sprite::create("skill/duang/W_death.png");
	sprite->setScale(1.0);
	sprite->setPosition(Vec2(30, 60));
	sprite->runAction(disappear);
	//auto moveBy = MoveBy::create(2, Vec2(sprite->getPositionY(), 500));
	//auto moveTo = MoveTo::create(2, Vec2(sprite->getPositionY(), 300));
	//auto delay = DelayTime::create(1);
	//auto seq = Sequence::create(moveTo, disappear, nullptr);
	//sprite->runAction(seq);
	// add the sprite as a child to this layer
	this->addChild(sprite, -1);
}//七宝有名四曰：防御
int death::BsecondSkill(float x, float y)
{
	return 0;
}

void death::AfourthSkill()
{
	switch (rlevel)
	{
	case 1:
		hero.magic -= 60;
		hero.blood += 400;
		break;
	case 2:
		hero.magic -= 80;
		hero.blood += 500;
		break;
	case 3:
		hero.magic -= 100;
		hero.blood += 600;
		break;
	case 4:
		hero.magic -= 120;
		hero.blood += 800;
		break;
	}
	Action* disappear = CCFadeOut::create(1.2);
	auto sprite = Sprite::create("skill/duang/R_death.png");
	sprite->setScale(0.1);
	sprite->setPosition(Vec2(30, 60));
	auto scaleBy = ScaleBy::create(1.2f, 10.0f);
	sprite->runAction(scaleBy);
	sprite->runAction(disappear);
	this->addChild(sprite);
}
int death::BfourthSkill(float x, float y)
{
	return 0;
}

void xin::AfirstSkill()
{
	myScene1::isflash();
	switch (qlevel)
	{
	case 1:

		break;
	case 2:
		hero.magic -= 200;

		break;
	case 3:

		hero.magic -= 180;
		break;
	case 4:

		hero.magic -= 160;
		break;
	}
	//hero.atk += hero.m_itn *0.8;
	//myScene1::pressQ();
}

int xin::BfirstSkill(float x, float y)
{
	return 0;
	//this->setPosition(Vec2(3.3*(2), 3.3*(3)));
	/*Action* disappear = CCFadeOut::create(0.8);
	auto sprite = Sprite::create("pia.png");
	sprite->setScale(3.4);
	// position the sprite on the center of the screen

	auto moveBy = MoveBy::create(0.2, Vec2(3.3*x, 3.3*y));
	//auto moveTo = MoveTo::create(0.8, Vec2(sprite->getPositionX(),getPositionY()));
	//auto delay = DelayTime::create(1);
	//	auto seq = Sequence::create(moveBy, disappear, nullptr);
	sprite->runAction(moveBy);
	sprite->runAction(disappear);
	// add the sprite as a child to this layer
	this->addChild(sprite);*/
}




void xin::AsecondSkill()
{
	switch (qlevel)
	{
	case 1:
		hero.atk += hero.magic*0.2;
		hero.magic += 80;
		break;
	case 2:
		hero.atk += hero.magic*0.3;
		hero.magic += 100;
		break;
	case 3:
		hero.atk += hero.magic*0.4;
		hero.magic += 120;
		break;
	case 4:
		hero.atk += hero.magic*0.5;
		hero.magic += 140;
		break;
	}
}//七宝有名，六曰：属性

int xin::BsecondSkill(float x, float y)
{
	return 0;
}

void xin::AfourthSkill()
{
	myScene1::pressR();
}
int xin::BfourthSkill(float x, float y)
{

	double hx = this->getPositionX();
	double hy = this->getPositionY();
	int damage = 0;
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	// play a sound effect, just once.
	audio->playEffect("sound/R_xin.mp3", false, 2.0f, 2.0f, 2.0f);
	switch (rlevel)
	{
	case 1:
		hero.magic -= 120;
		damage = 100;
		break;
	case 2:
		hero.magic -= 180;
		damage = 140;
		break;
	case 3:
		hero.magic -= 240;
		damage = 180;
		break;
	case 4:
		hero.magic -= 300;
		damage = 220;
		break;
	}
	damage += hero.atk*0.2;
	Action* disappear = CCFadeOut::create(0.8);
	auto sprite = Sprite::create("skill/duang/R_xin.png");
	sprite->setScale(1.0);
	sprite->setPosition(Vec2(20, 30));
	auto rotateTo = RotateTo::create(0.2f, 1080.0f);
	sprite->runAction(rotateTo);
	auto moveBy = MoveBy::create(0.2, Vec2(x, y));
	//auto moveTo = MoveTo::create(0.8, Vec2(sprite->getPositionX(),getPositionY()));
	//auto delay = DelayTime::create(1);
	auto seq = Sequence::create(moveBy, disappear, nullptr);
	sprite->runAction(seq);
	// add the sprite as a child to this layer
	this->addChild(sprite);
	return damage;
}

void sasuke::AfirstSkill()
{
	switch (qlevel)
	{
	case 1:

		hero.atkspeed *= 1.2;
		break;
	case 2:

		hero.atkspeed *= 1.4;
		break;
	case 3:

		hero.atkspeed *= 1.6;
		break;
	case 4:

		hero.atkspeed *= 1.8;
		break;
	}
	Action* disappear = CCFadeOut::create(1.2);
	auto sprite = Sprite::create("skill/duang/Q_sasuke.png");
	sprite->setScale(0.1);
	sprite->setPosition(Vec2(30, 60));
	auto scaleBy = ScaleBy::create(1.2f, 10.0f);
	sprite->runAction(scaleBy);
	sprite->runAction(disappear);
	this->addChild(sprite);
}//七宝有名二曰：速

int sasuke::BfirstSkill(float x, float y)
{
	return 0;
}

void sasuke::AsecondSkill()
{
	switch (qlevel)
	{
	case 1:

		hero.atk += 80;
		break;
	case 2:

		hero.atk += 100;
		break;
	case 3:

		hero.atk += 120;
		break;
	case 4:

		hero.atk += 140;
		break;
	}
}//七宝有名五曰：攻击

int sasuke::BsecondSkill(float x, float y)
{
	return 0;
}

void sasuke::AfourthSkill()
{
	myScene1::pressR();
}

int sasuke::BfourthSkill(float x, float y)
{

	int damage = 0;
	switch (rlevel)
	{
	case 1:
		hero.magic -= 100;
		damage = 100;
		break;
	case 2:
		hero.magic -= 120;
		damage = 140;
		break;
	case 3:
		hero.magic -= 140;
		damage = 180;
		break;
	case 4:
		hero.magic -= 160;
		damage = 220;
		break;
	}
	damage += hero.atk*0.2;
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	// play a sound effect, just once.
	audio->playEffect("sound/R_sasuke.mp3", false, 1.0f, 1.0f, 1.0f);
	hero.magic -= 60;
	Action* disappear = CCFadeOut::create(0.2);
	auto sprite = Sprite::create("skill/duang/R_sasuke.png");
	auto rotateTo = RotateTo::create(0.3f, 720.0f);
	sprite->runAction(rotateTo);
	sprite->setScale(0.8);
	sprite->setPosition(Vec2(20, 30));
	auto moveBy = MoveBy::create(0.2, Vec2(x, y));
	//auto moveTo = MoveTo::create(0.8, Vec2(sprite->getPositionX(),getPositionY()));
	//auto delay = DelayTime::create(1);
	auto seq = Sequence::create(moveBy, disappear, nullptr);
	sprite->runAction(seq);
	this->addChild(sprite);
	return damage;
}