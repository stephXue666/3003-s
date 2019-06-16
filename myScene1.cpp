
#include "myScene1.h"
#include "myScene2.h"
#include "myScene3.h"
#include "SimpleAudioEngine.h"
#include <vector>

USING_NS_CC;


bool myScene1::isQpressed = false;
bool myScene1::isWpressed = false;
bool myScene1::isRpressed = false;
bool myScene1::flash = false;

Scene* myScene1::createScene()
{
	return myScene1::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in myScene1.cpp\n");
}

bool myScene1::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	sprite2 = Sprite::create("new map.png");
	sprite2->setAnchorPoint(Vec2(0,0));
	sprite2->setPosition(Vec2(0,0));
	//sprite2->setScale(0.95);
	this->addChild(sprite2, 0);
	auto fazhen = Sprite::create("fazhen.png");
	fazhen->setAnchorPoint(Vec2(0, 0));
	fazhen->setPosition(Vec2(0, 55));
	//fazhen->setScale(1.1);
	sprite2->addChild(fazhen, 0);

	auto center1 = Sprite::create("centet_blue.png");
	//center1->setAnchorPoint(Vec2(0, 0));
	center1->setPosition(Vec2(800, 340));
	//fazhen->setScale(1.1);
	sprite2->addChild(center1, 0);

	auto center2 = Sprite::create("center_red.png");
	//center1->setAnchorPoint(Vec2(0, 0));
	center2->setPosition(Vec2(6200, 340));
	//fazhen->setScale(1.1);
	sprite2->addChild(center2, 0, tag++);
	getBloodProgress(center2);
	struct property unt = { 2000, 2000, 50, 20, 2 };
	all.push_back(unt);


	/*hero = new (std::nothrow) xin;
	if (hero && hero->initWithFile("action/xin/stand.png")) {
		hero->autorelease();
	}
	//hero = Sprite::create("xgg.png");
	hero->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	hero->setScale(0.7);
	sprite2->addChild(hero, 3);
	getBloodProgress(hero);
	*/
	int number = myScene3::select();
	//int number = 1;
	//（装备属性顺序：1血量上限，2血量，3蓝量上限，4蓝量，5攻击，6攻速, 7移速，8护甲，9魔抗，10金钱）
	if (number == 1)
	{
		hero = new (std::nothrow) xin;
		if (hero && hero->initWithFile("action/xin/stand.png")) {
			hero->autorelease();
		}
		hero->Hero::hero = { 408,408,402,402,66,80,480,30,20,800 };
		hero->qcd = 5;
		hero->rcd = 60;

		auto name = Sprite::create("head/name_xin.png");
		name->setPosition(Vec2(356, 20));
		name->setScale(0.36f);
		this->addChild(name, 21, 221);

		auto head = Sprite::create("head/xin.png");
		head->setPosition(Vec2(346, 82));
		head->setScale(0.74f);
		this->addChild(head, 22, 222);

		auto q = Sprite::create("skill/pic/Q_xin.png");
		q->setPosition(Vec2(469, 94));
		q->setScale(0.7f);
		this->addChild(q, 23, 223);

		auto w = Sprite::create("skill/pic/W_xin.png");
		w->setPosition(Vec2(560, 94));
		w->setScale(0.7f);
		this->addChild(w, 24, 224);

		auto r = Sprite::create("skill/pic/R_xin.png");
		r->setPosition(Vec2(654, 94));
		r->setScale(0.7f);
		this->addChild(r, 25, 225);
	}
	else if (number == 2)
	{
		hero = new (std::nothrow) sasuke;
		if (hero && hero->initWithFile("action/sasuke/stand.png")) {
			hero->autorelease();
		}
		hero->Hero::hero = { 365,365,208,208,72,100,480,40,20,800 };
		hero->rcd = 30;

		auto name = Sprite::create("head/name_sasuke.png");
		name->setPosition(Vec2(356, 20));
		name->setScale(0.36f);
		this->addChild(name, 21, 221);

		auto head = Sprite::create("head/sasuke.png");
		head->setPosition(Vec2(346, 82));
		head->setScale(0.74f);
		this->addChild(head, 22, 222);

		auto q = Sprite::create("skill/pic/Q_sasuke.png");
		q->setPosition(Vec2(469, 94));
		q->setScale(0.7f);
		this->addChild(q, 23, 223);

		auto w = Sprite::create("skill/pic/W_sasuke.png");
		w->setPosition(Vec2(560, 94));
		w->setScale(0.7f);
		this->addChild(w, 24, 224);

		auto r = Sprite::create("skill/pic/R_sasuke.png");
		r->setPosition(Vec2(654, 94));
		r->setScale(0.7f);
		this->addChild(r, 25, 225);
	}
	else if (number == 3)
	{
		hero = new (std::nothrow) death;
		if (hero && hero->initWithFile("action/death/stand.png")) {
			hero->autorelease();
		}
		hero->Hero::hero = { 786,786,364,364,55,80,480,83,20,800 };
		hero->qcd = 3;
		hero->rcd = 50;

		auto name = Sprite::create("head/name_death.png");
		name->setPosition(Vec2(356, 20));
		name->setScale(0.36f);
		this->addChild(name, 21, 221);

		auto head = Sprite::create("head/death.png");
		head->setPosition(Vec2(346, 82));
		head->setScale(0.74f);
		this->addChild(head, 22, 222);

		auto q = Sprite::create("skill/pic/Q_death.png");
		q->setPosition(Vec2(469, 94));
		q->setScale(0.7f);
		this->addChild(q, 23, 223);

		auto w = Sprite::create("skill/pic/W_death.png");
		w->setPosition(Vec2(560, 94));
		w->setScale(0.7f);
		this->addChild(w, 24, 224);

		auto r = Sprite::create("skill/pic/R_death.png");
		r->setPosition(Vec2(654, 94));
		r->setScale(0.7f);
		this->addChild(r, 25, 225);
	}

	if (hero && hero->initWithFile("action/xin/stand_l.png")) {
		hero->autorelease();
	}
	hero->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	//hero->setScale(0.3);
	sprite2->addChild(hero, 3);

	AI = new (std::nothrow) xin;
	if (AI && AI->initWithFile("action/death/stand.png")) {
		AI->autorelease();
	}
	//hero = Sprite::create("xgg.png");
	AI->setPosition(Vec2(7000, 300));
	AI->setScale(1);
	sprite2->addChild(AI, 3);
	getBloodProgress(AI);
	//{100, 100, 100, 100, 100, 40, 80, 5, 10, 0}
	AI->hero = { 0,0,100,100,100,0,0,0,0,0 };


	createTower(1, 2800, 340);
	createTower(1, 1800, 340);
	createTower(2, 5200, 340);
	createTower(2, 4200, 340);

	//CCSpriteBatchNode* spriteTexture = CCSpriteBatchNode::create("xiao.png");


	//auto moveTo = MoveTo::create(6, Vec2(250, 220));
	//Action* fadeout = CCFadeOut::create(0.5);
	
	//auto seq = Sequence::create(moveTo, CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, soldier)), nullptr);
	//auto seq = Sequence::create(moveTo, fadeout, nullptr);

	//soldier->runAction(seq);

	//creatSoldier();

	auto Klistener = EventListenerKeyboard::create();
	Klistener->onKeyPressed = CC_CALLBACK_2(myScene1::onKeyPressed, this);
	Klistener->onKeyReleased = CC_CALLBACK_2(myScene1::onKeyReleased, this);

	_mouseListener = EventListenerMouse::create();
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);//将监听器加入事件分发器
	_eventDispatcher->addEventListenerWithSceneGraphPriority(Klistener, this);

	//UI界面

	auto sprite_UI = Sprite::create("UI/board.png");//主面板
	sprite_UI->setAnchorPoint(Vec2(0, 0));
	sprite_UI->setPosition(Vec2(-28, 0));
	sprite_UI->setScale(0.7f);
	this->addChild(sprite_UI, 2, 200);

	auto sprite_store = Sprite::create("UI/store.png");//商店按钮
	auto bottom1 = MenuItemLabel::create(sprite_store, CC_CALLBACK_1(myScene1::showStore, this));
	auto menu1 = Menu::create(bottom1, NULL);
	menu1->setPosition(Vec2(1178, 32));
	sprite_UI->addChild(menu1, 11, 667);

	//面板
	auto data_bld = Label::createWithTTF("1000", "fonts/wow1.ttf", 18);
	data_bld->setPosition(Vec2(810, 56));
	sprite_UI->addChild(data_bld, 61, 261);

	auto data_g1 = Label::createWithTTF("/", "fonts/wow1.ttf", 18);
	data_g1->setPosition(Vec2(840, 56));
	sprite_UI->addChild(data_g1, 76, 276);

	auto data_ttbld = Label::createWithTTF("1000", "fonts/wow1.ttf", 18);
	data_ttbld->setPosition(Vec2(870, 56));
	sprite_UI->addChild(data_ttbld, 62, 262);

	auto data_mag = Label::createWithTTF("1000", "fonts/wow1.ttf", 18);
	data_mag->setPosition(Vec2(810, 30));
	sprite_UI->addChild(data_mag, 63, 263);

	auto data_g2 = Label::createWithTTF("/", "fonts/wow1.ttf", 18);
	data_g2->setPosition(Vec2(840, 30));
	sprite_UI->addChild(data_g2, 77, 277);

	auto data_ttmag = Label::createWithTTF("1000", "fonts/wow1.ttf", 18);
	data_ttmag->setPosition(Vec2(870, 30));
	sprite_UI->addChild(data_ttmag, 64, 264);

	auto data_atk = Label::createWithTTF("atk", "fonts/wow1.ttf", 24);
	data_atk->setPosition(Vec2(380, 106));
	sprite_UI->addChild(data_atk, 65, 265);

	auto data_atkspd = Label::createWithTTF("asp", "fonts/wow1.ttf", 24);
	data_atkspd->setPosition(Vec2(380, 168));
	sprite_UI->addChild(data_atkspd, 66, 266);

	auto data_spd = Label::createWithTTF("spd", "fonts/wow1.ttf", 24);
	data_spd->setPosition(Vec2(380, 138));
	sprite_UI->addChild(data_spd, 67, 267);

	auto data_phydfs = Label::createWithTTF("pdf", "fonts/wow1.ttf", 24);
	data_phydfs->setPosition(Vec2(380, 78));
	sprite_UI->addChild(data_phydfs, 68, 268);

	auto data_magdfs = Label::createWithTTF("mdf", "fonts/wow1.ttf", 24);
	data_magdfs->setPosition(Vec2(380, 46));
	sprite_UI->addChild(data_magdfs, 69, 269);

	auto data_mny = Label::createWithTTF("800", "fonts/wow1.ttf", 22);
	data_mny->setPosition(Vec2(1160, 32));
	sprite_UI->addChild(data_mny, 70, 270);

	auto data__exp = Label::createWithTTF("exp:        %", "fonts/wow1.ttf", 20);
	data__exp->setPosition(Vec2(376, 22));
	sprite_UI->addChild(data__exp, 76, 276);
	auto data_exp = Label::createWithTTF("0", "fonts/wow1.ttf", 20);
	data_exp->setPosition(Vec2(390, 21));
	sprite_UI->addChild(data_exp, 71, 271);

	auto data_level = Label::createWithTTF("1", "fonts/wow1.ttf", 23);
	data_level->setPosition(Vec2(459, 35));
	sprite_UI->addChild(data_level, 72, 272);

	auto data_qlevel = Label::createWithTTF("0", "fonts/wow1.ttf", 20);
	data_qlevel->setPosition(Vec2(758, 110));
	sprite_UI->addChild(data_qlevel, 73, 273);

	auto data_wlevel = Label::createWithTTF("0", "fonts/wow1.ttf", 20);
	data_wlevel->setPosition(Vec2(888, 110));
	sprite_UI->addChild(data_wlevel, 74, 274);

	auto data_rlevel = Label::createWithTTF("0", "fonts/wow1.ttf", 20);
	data_rlevel->setPosition(Vec2(1022, 110));
	sprite_UI->addChild(data_rlevel, 75, 275);

	setUIData();
	skillUp();

	auto UIBlood = Sprite::create("UI/blood.png");//满血条
	UIBlood->setScale(1);
	UIBlood->setAnchorPoint(Vec2(0, 0.5));
	UIBlood->setPosition(Vec2(641, 55.7f));
	sprite_UI->addChild(UIBlood, 51, 251);

	auto UIMagic = Sprite::create("UI/magic.png");//满蓝条
	UIMagic->setScale(1);
	UIMagic->setAnchorPoint(Vec2(0, 0.5));
	UIMagic->setPosition(Vec2(641, 29.7f));
	sprite_UI->addChild(UIMagic, 52, 252);

	setUIBloodAndMagic();

	//UI界面（结束)

	_mouseListener->onMouseDown = [=](Event* event)
	{
		this->unschedule("hello");
		
		sprite2->stopAllActions();
		hero->stopAllActions();

		auto animation = Animation::create();

		EventMouse* e = (EventMouse*)event;
		//isClick = 1;
		float cursorX = e->getCursorX();
		float cursorY = e->getCursorY();
		if (cursorY <= 132.3)return;

		float mapwidth = 7000.0f;
		float mapheight = 640.0f;
		float mapx = sprite2->getPositionX();//屏幕1080,640
		float mapy = sprite2->getPositionY();

		float aimx = cursorX - mapx;//点击地图坐标
		float aimy = cursorY;

		float x = hero->getPositionX();
		float y = hero->getPositionY();

		//float speed1 = 200;//临时速度
		float speed1 = hero->hero.speed / 3;

		for (int i = 0; i<tag; i++) {
			if (all[i].blood <= 0 || all[i].camp == 1)continue;
			auto unit = sprite2->getChildByTag(i);
			float dx = unit->getPositionX();
			float dy = unit->getPositionY();

			if (aimx<dx + 30 && aimx>dx - 30 && aimy<dy + 10 && aimy>dy - 20) {
			    //back:;
				//if (!isATKabled) { goto back; }
				this->unschedule(schedule_selector(myScene1::ctrlATK));
				float atkInterval = 300 / hero->hero.atkspeed;//攻击间隔
				//log("%d", hero->hero.atkspeed);
				if (isATKabled) {
					atkInterval *= 0.1;
				}
				else atkInterval *= 0.7;

				float dist = sqrt((dx - x)*(dx - x) + (dy - y)*(dy - y));
				hero->atk_ditance = 450;
				int atkd = hero->atk_ditance;
				
				if (dist <= atkd) {
					this->scheduleOnce(CC_CALLBACK_1(myScene1::heroATK, this, i),atkInterval, "hi");
					//heroATK(i);
					return;
				}
				float k = (dist - atkd) / dist;
				float dtx = k * (dx - x);
				float dty = k * (dy - y);
				float s = k * dist;;//路程
				float time = s / speed1;
				auto moveBy1 = MoveBy::create(time, Vec2(dtx, dty));
				auto moveBy2 = MoveBy::create(time, Vec2(-dtx, 0));
				hero->runAction(moveBy1);
				sprite2->runAction(moveBy2);

				this->scheduleOnce(CC_CALLBACK_1(myScene1::heroATK, this, i), time + atkInterval, "hi");
				//this->schedule(CC_CALLBACK_1(myScene1::ATK, this, i), atkInterval, "hello");
				
				return;
			}
		}

		/*for (cocos2d::Vector<Sprite*>::iterator it = myScene1::soldier2.begin(); it != myScene1::soldier2.end(); ) {
			float dx = (*it)->getPositionX();
			float dy = (*it)->getPositionY();

			if (aimx<dx + 30 && aimx>dx - 10 && aimy<dy + 10 && aimy>dy - 25) {
				//log("X:%f,Y:%f,dx:%f,dy:%f", X, Y, dx, dy);
				
				heroATK(it);

				int t = (*it)->getTag();

				
				//log("%d", soldier2.size());
				//cnt++;
				//goto bk;
				return;
			}
			else
				it++;
		}
		*/

		x += mapx;

		float dtx = cursorX - x;//位置变量
		float dty = cursorY - y;


		if (isQpressed == true) {
			int damage = hero->BfirstSkill(dtx, dty);
			setUIBloodAndMagic();
			isQpressed = false;
			return;
		}
		if (isWpressed == true) {
			int damage = hero->BsecondSkill(dtx, dty);
			setUIBloodAndMagic();
			isWpressed = false;
			return;
		}
		if (isRpressed == true) {
			int damage = hero->BfourthSkill(dtx, dty);
			setUIBloodAndMagic();
			isRpressed = false;

			return;
		}
		if (flash == true) {
			speed1 *= 10;

			flash = false;
		}

			float desx = mapx - dtx;
			float desy = mapy - dty;

			float s = sqrt(dtx * dtx + dty * dty);//路程
			float time = s / speed1;

			float boardx = 1080.0f - mapwidth;
			//float borady = 640.0f- mapheight;

			//log("%f,%f,%f", desx, desy, boardx);
			
			if (desx <=0 && desx >= boardx) {
				log("%f,%f", cursorX-mapx, cursorY);
				auto moveBy1 = MoveBy::create(time, Vec2(dtx, dty));
				auto moveBy2 = MoveBy::create(time, Vec2(-dtx, 0));
				hero->runAction(moveBy1);
				sprite2->runAction(moveBy2);
			}

			//帧动画
			if (number == 1) {
				if (dtx >= 0)
				{
					//auto animation = Animation::create();
					char nameSize[40] = { 0 };
					for (int i = 1; i < 4; i++)
					{
						sprintf(nameSize, "action/xin/run_r%d.png", i);
						animation->addSpriteFrameWithFile(nameSize);
					}
					animation->setDelayPerUnit(0.15f);
					animation->setLoops((time / 0.45f) + 1);
					animation->setRestoreOriginalFrame(true);
					auto animate = Animate::create(animation);
					hero->runAction(animate);
				}
				if (dtx < 0)
				{
					//auto animation = Animation::create();
					char nameSize[40] = { 0 };
					for (int i = 1; i < 4; i++)
					{
						sprintf(nameSize, "action/xin/run_l%d.png", i);
						animation->addSpriteFrameWithFile(nameSize);
					}
					animation->setDelayPerUnit(0.15f);
					animation->setLoops((time / 0.45f) + 1);
					animation->setRestoreOriginalFrame(true);
					auto animate = Animate::create(animation);
					hero->runAction(animate);
				}

			}
			if (number == 2) {
				if (dtx >= 0)
				{
					//auto animation = Animation::create();
					char nameSize[40] = { 0 };
					for (int i = 1; i < 4; i++)
					{
						sprintf(nameSize, "action/sasuke/run_r%d.png", i);
						animation->addSpriteFrameWithFile(nameSize);
					}
					animation->setDelayPerUnit(0.15f);
					animation->setLoops((time / 0.45f) + 1);
					animation->setRestoreOriginalFrame(true);
					auto animate = Animate::create(animation);
					hero->runAction(animate);
				}
				if (dtx < 0)
				{
					//auto animation = Animation::create();
					char nameSize[40] = { 0 };
					for (int i = 1; i < 4; i++)
					{
						sprintf(nameSize, "action/sasuke/run_l%d.png", i);
						animation->addSpriteFrameWithFile(nameSize);
					}
					animation->setDelayPerUnit(0.15f);
					animation->setLoops((time / 0.45f) + 1);
					animation->setRestoreOriginalFrame(true);
					auto animate = Animate::create(animation);
					hero->runAction(animate);
				}

			}
			if (number == 3) {
				if (dtx >= 0)
				{
					//auto animation = Animation::create();
					char nameSize[40] = { 0 };
					for (int i = 1; i < 5; i++)
					{
						sprintf(nameSize, "action/death/run_r%d.png", i);
						animation->addSpriteFrameWithFile(nameSize);
					}
					animation->setDelayPerUnit(0.15f);
					animation->setLoops((time / 0.6f) + 1);
					animation->setRestoreOriginalFrame(true);
					auto animate = Animate::create(animation);
					hero->runAction(animate);
				}
				if (dtx < 0)
				{
					//auto animation = Animation::create();
					char nameSize[40] = { 0 };
					for (int i = 1; i < 5; i++)
					{
						sprintf(nameSize, "action/death/run_l%d.png", i);
						animation->addSpriteFrameWithFile(nameSize);
					}
					animation->setDelayPerUnit(0.15f);
					animation->setLoops((time / 0.6f) + 1);
					animation->setRestoreOriginalFrame(true);
					auto animate = Animate::create(animation);
					hero->runAction(animate);
				}

			}

			//帧动画
	};

	_mouseListener->onMouseUp = [=](Event* event)
	{
		EventMouse* e = (EventMouse*)event;
		isClick = 0;
	};

	_mouseListener->onMouseMove = [=](Event* event)
	{
		EventMouse* e = (EventMouse*)event;
		if (isClick)
		{
			float cursorX = e->getCursorX();
			float cursorY = e->getCursorY();

			//sprite1->setAnchorPoint(Point(0.5, 0.5));
			hero->setPosition(cursorX, cursorY);
		}
	};

	this->schedule(schedule_selector(myScene1::towerAI), 1);
	this->schedule(schedule_selector(myScene1::soldierAI), 1);
	this->schedule(schedule_selector(myScene1::remoteAI), 1);

	this->schedule(schedule_selector(myScene1::setMoney), 0.1);

	this->schedule(schedule_selector(myScene1::dispatchArmy), 5);


	return true;
}

void myScene1::heroATK(float dt, int i)
{
	if (all[i].blood <= 0)return;
	Action* disappear = CCFadeOut::create(0.1);
	float X = hero->getPositionX();
	float Y = hero->getPositionY();
	auto unit = sprite2->getChildByTag(i);
	float dx = unit->getPositionX();
	float dy = unit->getPositionY();

	Sprite* bird = Sprite::create("skill/duang/A_xin.png");
	bird->setPosition(100, 50);
	bird->setScale(0.5);
	hero->addChild(bird, 1);

	auto moveBy = MoveBy::create(0.1, Vec2(dx - X-10, dy - Y+10));
	auto seq = Sequence::create(moveBy, disappear, nullptr);
	bird->runAction(seq);

	int damage = hero->hero.atk - all[i].arm;
	if (damage <= 0)damage = 1;
	all[i].blood -= damage;

	float b = all[i].blood;
	//float current =b * 80 / all[t].totalblood
	setCurrentBlood(unit, b / all[i].totalblood);

	if (b <= 0) {
		sprite2->removeChildByTag(i);

		hero->exp += 50;
		hero->hero.money += 100;
		//gainExp(unit);
		return;
	}

	isATKabled = false;

	float atkInterval = 100 / hero->hero.atkspeed;//攻击间隔
	this->schedule(schedule_selector(myScene1::ctrlATK), atkInterval);
	this->schedule(CC_CALLBACK_1(myScene1::ATK, this, i), atkInterval*0.8, "hello");
}

void myScene1::ATK(float dt, int i)
{
	if (all[i].blood <= 0)return;
	Action* disappear = CCFadeOut::create(0.1);
	float X = hero->getPositionX();
	float Y = hero->getPositionY();
	auto unit = sprite2->getChildByTag(i);
	float dx = unit->getPositionX();
	float dy = unit->getPositionY();

	Sprite* bird = Sprite::create("skill/duang/A_xin.png");
	bird->setPosition(100, 50);
	bird->setScale(0.5);
	hero->addChild(bird, 1);

	auto moveBy = MoveBy::create(0.1, Vec2(dx - X-10, dy - Y+10));
	auto seq = Sequence::create(moveBy, disappear, nullptr);
	bird->runAction(seq);

	int damage = hero->hero.atk - all[i].arm;
	if (damage <= 0)damage = 1;
	all[i].blood -= damage;

	float b = all[i].blood;
	//float current =b * 80 / all[t].totalblood
	setCurrentBlood(unit, b / all[i].totalblood);

	if (b <= 0) {
		sprite2->removeChildByTag(i);
		hero->exp += 50;
		hero->hero.money += 100;
		//gainExp(unit);
	}
	isATKabled = false;

}
void myScene1::soldierATK(Sprite* who)
{

}
void myScene1::remoteATK(Sprite* who, int x, int y)
{
	float X = who->getPositionX();
	float Y = who->getPositionY();
	//auto unit = sprite2->getChildByTag(i);
	//float dx = unit->getPositionX();
	//float dy = unit->getPositionY();
	Action* disappear = CCFadeOut::create(0.1);
	Sprite* bullet = Sprite::create("yuan_atk.png");
	bullet->setPosition(40, 60);
	bullet->setScale(0.7);
	who->addChild(bullet, 1);

	auto moveBy = MoveBy::create(0.1, Vec2(x - X -10, y - Y));
	auto seq = Sequence::create(moveBy, disappear, nullptr);
	bullet->runAction(seq);
}
void myScene1::canATK(Sprite* who, int x, int y)
{
	float X = who->getPositionX();
	float Y = who->getPositionY();
	Action* disappear = CCFadeOut::create(0.2);
	Sprite* bird = Sprite::create("attack.png");
	bird->setPosition(30, 50);
	bird->setScale(0.8);
	who->addChild(bird, 1);

	auto moveBy = MoveBy::create(0.2, Vec2(x - X, y - Y - 20));
	//auto seq = Sequence::create(moveBy, disappear, nullptr);
	bird->runAction(moveBy);
	bird->runAction(disappear);
}

void myScene1::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	log("Key with keycode %d pressed", keyCode);
	switch (keyCode)
	{
	case 8:
		myScene1::showBoard();
		break;
	case 140://DEventKeyboard::KeyCode::KEY_Q
		//_mouseListener->setEnabled(false);
		//arsorone();
		if (isQabled) {
			hero->AfirstSkill();
			isQabled = false;
			this->scheduleOnce(schedule_selector(myScene1::QCD), hero->qcd);
			setUIData();
			setUIBloodAndMagic();
		}

		break;
	case 146://W
		if (isWabled) {
			hero->AsecondSkill();
			isWabled = false;
			this->scheduleOnce(schedule_selector(myScene1::WCD), hero->wcd);
			setUIData();
			setUIBloodAndMagic();
		}
		//gainExp(hero);
		break;
	case 128://E
		if (isEabled) {
			hero->AfourthSkill();
			isEabled = false;
			this->scheduleOnce(schedule_selector(myScene1::ECD), hero->rcd);
			setUIData();
			setUIBloodAndMagic();
		}

		break;
	case 142://S键停止操作
		sprite2->stopAllActions();
		hero->stopAllActions();
	}
}
void myScene1::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
	switch (keyCode)
	{
	case 8:
		this->getChildByTag(666)->removeFromParentAndCleanup(true);
		break;
	}
}


void myScene1::towerAI(float dt)
{
	cocos2d::Vector<Sprite*>::iterator it1;
	Action* disappear = CCFadeOut::create(0.2);
	for (it1 = myScene1::tower1.begin(); it1 != myScene1::tower1.end(); it1++) {
		if (all[(*it1)->getTag()].blood <= 0) {
			//it1 = tower1.erase(it1);
			continue;
		}

		float X = (*it1)->getPositionX();
		float Y = (*it1)->getPositionY();
		int t;
		//log("X:%f,Y:%f", X, Y);

		for (cocos2d::Vector<Sprite*>::iterator it2 = myScene1::soldier2.begin(); it2 != myScene1::soldier2.end(); ) {
			if (all[(*it2)->getTag()].blood <= 0) {
				it2 = soldier2.erase(it2);
				continue;
			}

			float dx = (*it2)->getPositionX();
			float dy = (*it2)->getPositionY();
			//log("dx:%f,dy:%f", dx, dy);

			//float distance = (X - dx)*(X - dx) + (Y - dy)*(Y - dy);
			//log("dis:%f", distance);
			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 202500) {
				//log("X:%f,Y:%f,dx:%f,dy:%f", X,Y,dx, dy);
				Sprite* bird = Sprite::create("attack.png");
				bird->setPosition(60, 110);
				bird->setScale(0.8);
				(*it1)->addChild(bird, 1);

				auto moveBy = MoveBy::create(0.2, 1.25*Vec2(dx - X , dy - Y - 30));
				//auto seq = Sequence::create(moveBy, disappear, nullptr);
				bird->runAction(moveBy);
				bird->runAction(disappear);

				//log("%d", (*it2)->getTag());
				t = (*it2)->getTag();
				int damage = 50 - all[t].arm;
				if (damage <= 0)damage = 1;
				all[t].blood -= damage;
				float b = all[t].blood;
				//float current =b * 80 / all[t].totalblood
				
				setCurrentBlood((*it2), b / all[t].totalblood);

				if (b <= 0) {
					die((*it2));
					gainExp(*it2);
					it2 = soldier2.erase(it2);
				}
				//log("%d", soldier2.size());
				//cnt++;
				
				goto bk1;
			}
			else
				it2++;
		}
		for (cocos2d::Vector<Sprite*>::iterator it2 = myScene1::remote2.begin(); it2 != myScene1::remote2.end(); ) {
			if (all[(*it2)->getTag()].blood <= 0) {
				it2 = remote2.erase(it2);
				continue;
			}
			float dx = (*it2)->getPositionX();
			float dy = (*it2)->getPositionY();
	
			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 202500) {
				
				Sprite* bird = Sprite::create("attack.png");
				bird->setPosition(60, 110);
				bird->setScale(0.8);
				(*it1)->addChild(bird, 1);

				auto moveBy = MoveBy::create(0.2, 1.25*Vec2(dx - X , dy - Y - 30));
				//auto seq = Sequence::create(moveBy, disappear, nullptr);
				bird->runAction(moveBy);
				bird->runAction(disappear);

				t = (*it2)->getTag();
				int damage = 50 - all[t].arm;
				if (damage <= 0)damage = 1;
				all[t].blood -= damage;
				
				float b = all[t].blood;

				setCurrentBlood((*it2), b / all[t].totalblood);

				if (b <= 0) {
					die((*it2));
					gainExp(*it2);
					it2 = remote2.erase(it2);
				}
				goto bk1;
			}
			else
				it2++;
		}

		if (AI->hero.blood) {
			float dx = AI->getPositionX();
			float dy = AI->getPositionY();
			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 202500) {
				Sprite* bird = Sprite::create("attack.png");
				bird->setPosition(60, 110);
				bird->setScale(0.8);
				(*it1)->addChild(bird, 1);
				auto moveBy = MoveBy::create(0.2, 1.25*Vec2(dx - X, dy - Y - 30));
				bird->runAction(moveBy);
				bird->runAction(disappear);
				int damage= 50 - AI->hero.armor;
				if (damage <= 0)damage = 1;
				AI->hero.blood -= damage;
				float b = AI->hero.blood;
				setCurrentBlood(AI, b / AI->hero.totalblood);
				if (b <= 0) {
					//die(AI);
					hero->exp += 500;
					void setUIExpAndLevel();
					//void skillUp();
				}
			}
		}

	bk1:;
	}
	for (it1 = myScene1::tower2.begin(); it1 != myScene1::tower2.end(); it1++) {
		if (all[(*it1)->getTag()].blood <= 0) {
			//it1 = tower1.erase(it1);
			continue;
		}

		float X = (*it1)->getPositionX();
		float Y = (*it1)->getPositionY();
		int t;
		//log("X:%f,Y:%f", X, Y);

		for (cocos2d::Vector<Sprite*>::iterator it2 = myScene1::soldier1.begin(); it2 != myScene1::soldier1.end(); ) {
			if (all[(*it2)->getTag()].blood <= 0) {
				it2 = soldier1.erase(it2);
				continue;
			}
			float dx = (*it2)->getPositionX();
			float dy = (*it2)->getPositionY();

			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 202500) {
				Sprite* bird = Sprite::create("attack.png");
				bird->setPosition(60, 110);
				bird->setScale(0.8);
				(*it1)->addChild(bird, 1);

				auto moveBy = MoveBy::create(0.2, 1.25*Vec2(dx - X , dy - Y - 30));
				bird->runAction(moveBy);
				bird->runAction(disappear);

				t = (*it2)->getTag();
				int damage = 50 - all[t].arm;
				if (damage <= 0)damage = 1;
				all[t].blood -= damage;
				float b = all[t].blood;
				setCurrentBlood((*it2), b / all[t].totalblood);

				if (b <= 0) {
					die((*it2));
					gainExp(*it2);
					it2 = soldier1.erase(it2);
				}
				goto bk2;
			}
			else
				it2++;
		}
		for (cocos2d::Vector<Sprite*>::iterator it2 = myScene1::remote1.begin(); it2 != myScene1::remote1.end(); ) {
			if (all[(*it2)->getTag()].blood <= 0) {
				it2 = remote1.erase(it2);
				continue;
			}
			float dx = (*it2)->getPositionX();
			float dy = (*it2)->getPositionY();

			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 202500) {
				Sprite* bird = Sprite::create("attack.png");
				bird->setPosition(60, 110);
				bird->setScale(0.8);
				(*it1)->addChild(bird, 1);

				auto moveBy = MoveBy::create(0.2, 1.25*Vec2(dx - X , dy - Y - 30));
				bird->runAction(moveBy);
				bird->runAction(disappear);

				t = (*it2)->getTag();
				int damage = 50 - all[t].arm;
				if (damage <= 0)damage = 1;
				all[t].blood -= damage;
				float b = all[t].blood;

				setCurrentBlood((*it2), b / all[t].totalblood);

				if (b <= 0) {
					die((*it2));
					gainExp(*it2);
					it2 = remote1.erase(it2);
				}
				goto bk2;
			}
			else
				it2++;
		}
		if (hero->hero.blood) {
			float dx = hero->getPositionX();
			float dy = hero->getPositionY();
			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 202500) {
				Sprite* bird = Sprite::create("attack.png");
				bird->setPosition(60, 110);
				bird->setScale(0.8);
				(*it1)->addChild(bird, 1);
				auto moveBy = MoveBy::create(0.2, 1.25*Vec2(dx - X, dy - Y - 30));
				bird->runAction(moveBy);
				bird->runAction(disappear);
				int damage = 50 - hero->hero.armor;
				if (damage <= 0)damage = 1;
				hero->hero.blood -= damage;
				float b = hero->hero.blood;
				setUIData();
				setUIBloodAndMagic();
				//setCurrentBlood(hero, b / hero->hero.totalblood);
				if (b <= 0) {
					reborn();
				}
			}
		}
	bk2:;
	}
}
void myScene1::soldierAI(float dt)
{
	cocos2d::Vector<Sprite*>::iterator it1;
	Action* disappear = CCFadeOut::create(0.1);
	int attackpower = 20;
	for (it1 = myScene1::soldier1.begin(); it1 != myScene1::soldier1.end(); it1++) {
		if (all[(*it1)->getTag()].blood <= 0) {
			//it1 = tower1.erase(it1);
			continue;
		}

		float X = (*it1)->getPositionX();
		float Y = (*it1)->getPositionY();
		int t;

		for (cocos2d::Vector<Sprite*>::iterator it2 = myScene1::soldier2.begin(); it2 != myScene1::soldier2.end(); ) {
			if (all[(*it2)->getTag()].blood <= 0) {
				it2 = soldier2.erase(it2);
				continue;
			}
			float dx = (*it2)->getPositionX();
			float dy = (*it2)->getPositionY();

			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 10000) {
				(*it1)->stopAllActions();
				soldierATK(*it1);

				t = (*it2)->getTag();
				int damage = attackpower - all[t].arm;
				if (damage <= 0)damage = 1;
				all[t].blood -= damage;
				float b = all[t].blood;
				setCurrentBlood((*it2), b / all[t].totalblood);
				if (b <= 0) {
					die((*it2));
					gainExp(*it2);
					it2 = soldier2.erase(it2);
				}
				goto bk1;
			}
			else
				it2++;
		}
		for (cocos2d::Vector<Sprite*>::iterator it2 = myScene1::remote2.begin(); it2 != myScene1::remote2.end(); ) {
			if (all[(*it2)->getTag()].blood <= 0) {
				it2 = remote2.erase(it2);
				continue;
			}
			float dx = (*it2)->getPositionX();
			float dy = (*it2)->getPositionY();

			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 10000) {
				(*it1)->stopAllActions();
				soldierATK(*it1);

				t = (*it2)->getTag();
				int damage = attackpower - all[t].arm;
				if (damage <= 0)damage = 1;
				all[t].blood -= damage;
				float b = all[t].blood;
				setCurrentBlood((*it2), b / all[t].totalblood);
				if (b <= 0) {
					die((*it2));
					gainExp(*it2);
					it2 = remote2.erase(it2);
				}
				goto bk1;
			}
			else
				it2++;
		}
		for (cocos2d::Vector<Sprite*>::iterator it2 = myScene1::tower2.begin(); it2 != myScene1::tower2.end(); ) {
			if (all[(*it2)->getTag()].blood <= 0) {
				it2 = tower2.erase(it2);
				continue;
			}
			float dx = (*it2)->getPositionX();
			float dy = (*it2)->getPositionY();

			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 10000) {
				(*it1)->stopAllActions();
				soldierATK(*it1);

				t = (*it2)->getTag();
				int damage = attackpower - all[t].arm;
				if (damage <= 0)damage = 1;
				all[t].blood -= damage;
				float b = all[t].blood;
				setCurrentBlood((*it2), b / all[t].totalblood);
				if (b <= 0) {
					die((*it2));
					gainExp(*it2);
					it2 = tower2.erase(it2);
				}
				goto bk1;
			}
			else
				it2++;
		}
		if (AI->hero.blood) {
			float dx = AI->getPositionX();
			float dy = AI->getPositionY();
			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 10000) {
				(*it1)->stopAllActions();
				soldierATK(*it1);
				int damage = attackpower - AI->hero.armor;
				if (damage <= 0)damage = 1;
				AI->hero.blood -= damage;
				float b = AI->hero.blood;
				setCurrentBlood(AI, b / AI->hero.totalblood);
				if (b <= 0) {
					//die(AI);
					hero->exp += 500;
				}
				goto bk1;
			}
		}
		auto moveBy = MoveBy::create(1, Vec2(100, 0));
		(*it1)->runAction(moveBy);
	bk1:;
	}
	for (it1 = myScene1::soldier2.begin(); it1 != myScene1::soldier2.end(); it1++) {
		if (all[(*it1)->getTag()].blood <= 0) {
			//it1 = tower1.erase(it1);
			continue;
		}

		float X = (*it1)->getPositionX();
		float Y = (*it1)->getPositionY();
		int t;

		for (cocos2d::Vector<Sprite*>::iterator it2 = myScene1::soldier1.begin(); it2 != myScene1::soldier1.end(); ) {
			if (all[(*it2)->getTag()].blood <= 0) {
				it2 = soldier1.erase(it2);
				continue;
			}
			float dx = (*it2)->getPositionX();
			float dy = (*it2)->getPositionY();

			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 10000) {
				(*it1)->stopAllActions();
				soldierATK(*it1);

				t = (*it2)->getTag();
				int damage = attackpower - all[t].arm;
				if (damage <= 0)damage = 1;
				all[t].blood -= damage;
				float b = all[t].blood;
				setCurrentBlood((*it2), b / all[t].totalblood);
				if (b <= 0) {
					die((*it2));
					gainExp(*it2);
					it2 = soldier1.erase(it2);
				}
				goto bk2;
			}
			else
				it2++;
		}
		for (cocos2d::Vector<Sprite*>::iterator it2 = myScene1::remote1.begin(); it2 != myScene1::remote1.end(); ) {
			if (all[(*it2)->getTag()].blood <= 0) {
				it2 = remote1.erase(it2);
				continue;
			}
			float dx = (*it2)->getPositionX();
			float dy = (*it2)->getPositionY();

			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 10000) {
				(*it1)->stopAllActions();
				soldierATK(*it1);

				t = (*it2)->getTag();
				int damage = attackpower - all[t].arm;
				if (damage <= 0)damage = 1;
				all[t].blood -= damage;
				float b = all[t].blood;
				setCurrentBlood((*it2), b / all[t].totalblood);
				if (b <= 0) {
					die((*it2));
					gainExp(*it2);
					it2 = remote1.erase(it2);
				}
				goto bk2;
			}
			else
				it2++;
		}
		for (cocos2d::Vector<Sprite*>::iterator it2 = myScene1::tower1.begin(); it2 != myScene1::tower1.end(); ) {
			if (all[(*it2)->getTag()].blood <= 0) {
				it2 = tower1.erase(it2);
				continue;
			}
			float dx = (*it2)->getPositionX();
			float dy = (*it2)->getPositionY();

			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 10000) {
				(*it1)->stopAllActions();
				soldierATK(*it1);

				t = (*it2)->getTag();
				int damage = attackpower - all[t].arm;
				if (damage <= 0)damage = 1;
				all[t].blood -= damage;
				float b = all[t].blood;
				setCurrentBlood((*it2), b / all[t].totalblood);
				if (b <= 0) {
					die((*it2));
					gainExp(*it2);
					it2 = tower1.erase(it2);
				}
				goto bk2;
			}
			else
				it2++;
		}
		if (hero->hero.blood) {
			float dx = hero->getPositionX();
			float dy = hero->getPositionY();
			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 10000) {
				(*it1)->stopAllActions();
				soldierATK(*it1);
				int damage = attackpower - hero->hero.armor;
				if (damage <= 0)damage = 1;
				hero->hero.blood -= damage;
				float b = hero->hero.blood;
				setUIData();
				setUIBloodAndMagic();
				//setCurrentBlood(hero, b / hero->hero.totalblood);
				if (b <= 0) {
					reborn();
				}
				goto bk2;
			}
		}
		auto moveBy = MoveBy::create(1, Vec2(-100, 0));
		(*it1)->runAction(moveBy);
	bk2:;
	
	}
}
void myScene1::remoteAI(float dt)
{
	cocos2d::Vector<Sprite*>::iterator it1;
	Action* disappear = CCFadeOut::create(0.1);
	for (it1 = myScene1::remote1.begin(); it1 != myScene1::remote1.end(); it1++) {
		int t1 = (*it1)->getTag();
		if (all[t1].blood <= 0) {
			//it1 = tower1.erase(it1);
			continue;
		}
		float X = (*it1)->getPositionX();
		float Y = (*it1)->getPositionY();
		int t;

		for (cocos2d::Vector<Sprite*>::iterator it2 = myScene1::soldier2.begin(); it2 != myScene1::soldier2.end(); ) {
			if (all[(*it2)->getTag()].blood <= 0) {
				it2 = soldier2.erase(it2);
				continue;
			}
			float dx = (*it2)->getPositionX();
			float dy = (*it2)->getPositionY();

			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 160000) {
				(*it1)->stopAllActions();
				if (all[t1].atk == 30)
					canATK((*it1), dx, dy);
				else
					remoteATK((*it1), dx, dy);

				t = (*it2)->getTag();
				int damage = all[t1].atk - all[t].arm;
				if (damage <= 0)damage = 1;
				all[t].blood -= damage;

				float b = all[t].blood;
				setCurrentBlood((*it2), b / all[t].totalblood);
				if (b <= 0) {
					die((*it2));
					gainExp(*it2);
					it2 = soldier2.erase(it2);
				}
				goto bk1;
			}
			else
				it2++;
		}
		for (cocos2d::Vector<Sprite*>::iterator it2 = myScene1::remote2.begin(); it2 != myScene1::remote2.end(); ) {
			if (all[(*it2)->getTag()].blood <= 0) {
				it2 = remote2.erase(it2);
				continue;
			}
			float dx = (*it2)->getPositionX();
			float dy = (*it2)->getPositionY();

			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 160000) {
				(*it1)->stopAllActions();
				if (all[t1].atk == 30)
					canATK((*it1), dx, dy);
				else
					remoteATK((*it1), dx, dy);

				t = (*it2)->getTag();
				int damage = all[t1].atk - all[t].arm;
				if (damage <= 0)damage = 1;
				all[t].blood -= damage;
				float b = all[t].blood;
				setCurrentBlood((*it2), b / all[t].totalblood);
				if (b <= 0) {
					die((*it2));
					gainExp(*it2);
					it2 = remote2.erase(it2);
				}
				goto bk1;
			}
			else
				it2++;
		}
		for (cocos2d::Vector<Sprite*>::iterator it2 = myScene1::tower2.begin(); it2 != myScene1::tower2.end(); ) {
			if (all[(*it2)->getTag()].blood <= 0) {
				it2 = tower2.erase(it2);
				continue;
			}
			float dx = (*it2)->getPositionX();
			float dy = (*it2)->getPositionY();

			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 160000) {
				(*it1)->stopAllActions();
				if (all[t1].atk == 30)
					canATK((*it1), dx, dy);
				else
					remoteATK((*it1), dx, dy);

				t = (*it2)->getTag();
				int damage = all[t1].atk - all[t].arm;
				if (damage <= 0)damage = 1;
				all[t].blood -= damage;
				float b = all[t].blood;
				setCurrentBlood((*it2), b / all[t].totalblood);
				if (b <= 0) {
					die((*it2));
					gainExp(*it2);
					it2 = tower2.erase(it2);
				}
				goto bk1;
			}
			else
				it2++;
		}
		if (AI->hero.blood) {
			float dx = AI->getPositionX();
			float dy = AI->getPositionY();
			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 160000) {
				(*it1)->stopAllActions();
				if (all[t1].atk == 30)
					canATK((*it1), dx, dy);
				else
					remoteATK((*it1), dx, dy);

				int damage = all[t1].atk - AI->hero.armor;
				if (damage <= 0)damage = 1;
				AI->hero.blood -= damage;
				float b = AI->hero.blood;
				setCurrentBlood(AI, b / AI->hero.totalblood);
				if (b <= 0) {
					//die(AI);
					hero->exp += 500;
				}
				goto bk1;
			}
		}
		auto moveBy = MoveBy::create(1, Vec2(100, 0));
		(*it1)->runAction(moveBy);
	bk1:;
	}
	for (it1 = myScene1::remote2.begin(); it1 != myScene1::remote2.end(); it1++) {
		int t1 = (*it1)->getTag();
		if (all[(*it1)->getTag()].blood <= 0) {
			//it1 = tower1.erase(it1);
			continue;
		}

		float X = (*it1)->getPositionX();
		float Y = (*it1)->getPositionY();
		int t;

		for (cocos2d::Vector<Sprite*>::iterator it2 = myScene1::soldier1.begin(); it2 != myScene1::soldier1.end(); ) {
			if (all[(*it2)->getTag()].blood <= 0) {
				it2 = soldier1.erase(it2);
				continue;
			}
			float dx = (*it2)->getPositionX();
			float dy = (*it2)->getPositionY();

			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 160000) {
				(*it1)->stopAllActions();
				if (all[t1].atk == 30)
					canATK((*it1), dx, dy);
				else
					remoteATK((*it1), dx, dy);

				t = (*it2)->getTag();
				int damage = all[t1].atk - all[t].arm;
				if (damage <= 0)damage = 1;
				all[t].blood -= damage;
				float b = all[t].blood;
				setCurrentBlood((*it2), b / all[t].totalblood);
				if (b <= 0) {
					die((*it2));
					gainExp(*it2);
					it2 = soldier1.erase(it2);
				}
				goto bk2;
			}
			else
				it2++;
		}
		for (cocos2d::Vector<Sprite*>::iterator it2 = myScene1::remote1.begin(); it2 != myScene1::remote1.end(); ) {
			if (all[(*it2)->getTag()].blood <= 0) {
				it2 = remote1.erase(it2);
				continue;
			}
			float dx = (*it2)->getPositionX();
			float dy = (*it2)->getPositionY();

			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 160000) {
				(*it1)->stopAllActions();
				if (all[t1].atk == 30)
					canATK((*it1), dx, dy);
				else
					remoteATK((*it1), dx, dy);

				t = (*it2)->getTag();
				int damage = all[t1].atk - all[t].arm;
				if (damage <= 0)damage = 1;
				all[t].blood -= damage;
				float b = all[t].blood;
				setCurrentBlood((*it2), b / all[t].totalblood);
				if (b <= 0) {
					die((*it2));
					gainExp(*it2);
					it2 = remote1.erase(it2);
				}
				goto bk2;
			}
			else
				it2++;
		}
		for (cocos2d::Vector<Sprite*>::iterator it2 = myScene1::tower1.begin(); it2 != myScene1::tower1.end(); ) {
			if (all[(*it2)->getTag()].blood <= 0) {
				it2 = tower1.erase(it2);
				continue;
			}
			float dx = (*it2)->getPositionX();
			float dy = (*it2)->getPositionY();

			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 160000) {
				(*it1)->stopAllActions();
				if (all[t1].atk == 30)
					canATK((*it1), dx, dy);
				else
					remoteATK((*it1), dx, dy);

				t = (*it2)->getTag();
				int damage = all[t1].atk - all[t].arm;
				if (damage <= 0)damage = 1;
				all[t].blood -= damage;
				float b = all[t].blood;
				setCurrentBlood((*it2), b / all[t].totalblood);
				if (b <= 0) {
					die((*it2));
					gainExp(*it2);
					it2 = tower1.erase(it2);
				}
				goto bk2;
			}
			else
				it2++;
		}
		if (hero->hero.blood) {
			float dx = hero->getPositionX();
			float dy = hero->getPositionY();
			if ((X - dx)*(X - dx) + (Y - dy)*(Y - dy) <= 160000) {
				(*it1)->stopAllActions();
				if (all[t1].atk == 30)
					canATK((*it1), dx, dy);
				else
					remoteATK((*it1), dx, dy);

				int damage = all[t1].atk - hero->hero.armor;
				if (damage <= 0)damage = 1;
				hero->hero.blood -= damage;
				float b = hero->hero.blood;
				setUIData();
				setUIBloodAndMagic();
				//setCurrentBlood(hero, b / hero->hero.totalblood);
				if (b <= 0) {
					reborn();
				}
				goto bk2;
			}
		}
		auto moveBy = MoveBy::create(1, Vec2(-100, 0));
		(*it1)->runAction(moveBy);
	bk2:;

	}
}

void myScene1::createTower(int camp, float x, float y) 
{
	Sprite* sprite1 = new (std::nothrow) Sprite;
	if (sprite1) {
		if (camp == 1)
			sprite1->initWithFile("tower_blue.png");
		else
			sprite1->initWithFile("Tower.png");
		sprite1->autorelease();
	}
	sprite1->setPosition(Vec2(x, y));
	sprite1->setScale(0.8);
	sprite2->addChild(sprite1, 2, tag++);

	struct property unt = { 2500, 2500, 50, 18, camp };
	all.push_back(unt);
	
	if (camp == 1)
		tower1.pushBack(sprite1);
	else
		tower2.pushBack(sprite1);

	getBloodProgress(sprite1);
}


/*创建各兵种*/
void myScene1::meleeSoldier(int camp, float x, float y)
{
	Sprite* soldier = new (std::nothrow) Sprite;
	if (soldier) {
		if (camp == 1)
			soldier->initWithFile("jin_blue_r1.png");
		else
			soldier->initWithFile("jin_red_l1.png");
		soldier->autorelease();
	}
	soldier->setPosition(x, y);
	soldier->setScale(0.8);
	sprite2->addChild(soldier, 2, tag++);
	getBloodProgress(soldier);

	struct property unt = { 200, 200, 30, 10, camp };

	all.push_back(unt);

	if (camp == 1) {
		soldier1.pushBack(soldier);
	}
	else soldier2.pushBack(soldier);
	//log("%d", soldier->atk);
}
void myScene1::remoteSoldier(int camp, float x, float y) 
{
	Sprite* soldier = new (std::nothrow) Sprite;
	if (soldier) {
		if (camp == 1)
			soldier->initWithFile("fa_blue_r.png");
		else
			soldier->initWithFile("fa_red_l.png");
		soldier->autorelease();
	}
	soldier->setPosition(x, y);
	soldier->setScale(0.9);
	sprite2->addChild(soldier, 2, tag++);
	getBloodProgress(soldier);

	struct property unt = { 100, 100, 45, 5, camp };
	all.push_back(unt);
	if (camp == 1) {
		remote1.pushBack(soldier);
	}
	else remote2.pushBack(soldier);
}
void myScene1::Cannon(int camp, float x, float y) {
	Sprite* cannon = new (std::nothrow) Sprite;
	if (cannon) {
		if (camp == 1)
			cannon->initWithFile("pao_blue_r.png");
		else
			cannon->initWithFile("pao_l.png");
		cannon->autorelease();
	}
	cannon->setPosition(x, y);
	cannon->setScale(0.9);
	sprite2->addChild(cannon, 2, tag++);
	getBloodProgress(cannon);

	struct property unt = { 300, 300, 50, 10, camp };
	all.push_back(unt);
	if (camp == 1) {
		remote1.pushBack(cannon);
	}
	else remote2.pushBack(cannon);

}


void myScene1::dispatchArmy(float dt) {

	meleeSoldier(1, 1100, 400);
	meleeSoldier(1, 1150, 350);
	meleeSoldier(1, 1100, 300);
	Cannon(1, 1000, 380);
	remoteSoldier(1, 1000, 320);

	meleeSoldier(2, 5700, 400);
	meleeSoldier(2, 5600, 350);
	meleeSoldier(2, 5700, 300);
	Cannon(2, 5800, 380);
	remoteSoldier(2, 5800, 320);

}
/*创建兵种结束*/


void myScene1::die(Sprite* who) {
	who->stopAllActions();
	auto fadeout = FadeOut::create(0.5);
	auto delay = DelayTime::create(0.2);
	auto seq = Sequence::create(delay, fadeout, CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, who)), nullptr);
	who->runAction(seq);

}


void myScene1::getBloodProgress(Node* who) {
	Sprite* emptyblood = Sprite::create("empty.png");//空血条
	emptyblood->setAnchorPoint(Vec2(0, 0));
	emptyblood->setScale(0.8);

	float width = (who->getContentSize().width - 66.0f) / 2;
	float height = who->getContentSize().height * 1.1f;
	emptyblood->setPosition(Vec2(width, height));
	who->addChild(emptyblood);
	Sprite *fullBlood = Sprite::create("blood.png");//满血条
	fullBlood->setAnchorPoint(Vec2(0, 0));
	fullBlood->setScale(0.8);
	fullBlood->setPosition(Vec2(width, height));
	who->addChild(fullBlood, 1, 1);

}
void myScene1::setCurrentBlood(Node* who, float current){
	who->getChildByTag(1)->removeFromParentAndCleanup(true);
	if (current <= 0) {
		return;
	}
	float width = (who->getContentSize().width - 66.0f) / 2;
	float height = who->getContentSize().height * 1.1f;
	
	//log("%f", current);
	Sprite *fullBlood = Sprite::create("blood.png", Rect(0, 0, current * 80.0f, 6));
	fullBlood->setAnchorPoint(Vec2(0, 0));
	fullBlood->setScale(0.8);
	fullBlood->setPosition(Vec2(width, height));
	who->addChild(fullBlood, 1, 1);
}


/*void myScene1::arsorone() {
	auto Listener = EventListenerMouse::create();
	_eventDispatcher->addEventListenerWithSceneGraphPriority(Listener, this);

	//Listener->;

	Listener->onMouseDown = [=](Event* event) {
		log("clicked");
		_mouseListener->setEnabled(true);
		//_eventDispatcher->removeEventListenersForTarget(Listener);
	};
}*/

void myScene1::showBoard()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	hero->hero.speed += 100;

	auto sprite_gameBoard = Sprite::create("fight/dataBoard.jpg");
	// 调位置
	sprite_gameBoard->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	//调大小
	sprite_gameBoard->setScale(1);
	// add the sprite as a child to this layer
	this->addChild(sprite_gameBoard, 10, 666);
}

//战况面板（结束）

//商店界面（开始）

void myScene1::showStore(Ref* pSender)
{
	//商店面板
	if (store_judge == 0)
	{
		_mouseListener->setEnabled(false);
		auto board_store = Sprite::create("store/board.png");
		board_store->setPosition(Vec2(540, 320));
		board_store->setScale(1.8f);
		this->addChild(board_store, 99, 99);
		store_judge++;

		//装备1
		auto sprite_zb1 = Sprite::create("store/pic/equip1.png");
		auto bottom_store_1 = MenuItemLabel::create(sprite_zb1, CC_CALLBACK_1(myScene1::show_equip1, this));
		auto menu1 = Menu::create(bottom_store_1, NULL);
		menu1->setScale(0.2f);
		menu1->setPosition(Vec2(-267, -40));
		board_store->addChild(menu1);

		//装备2
		auto sprite_zb2 = Sprite::create("store/pic/equip2.png");
		auto bottom_store_2 = MenuItemLabel::create(sprite_zb2, CC_CALLBACK_1(myScene1::show_equip2, this));
		auto menu2 = Menu::create(bottom_store_2, NULL);
		menu2->setScale(0.2f);
		menu2->setPosition(Vec2(-207, -40));
		board_store->addChild(menu2);

		//装备3
		auto sprite_zb3 = Sprite::create("store/pic/equip3.png");
		auto bottom_store_3 = MenuItemLabel::create(sprite_zb3, CC_CALLBACK_1(myScene1::show_equip3, this));
		auto menu3 = Menu::create(bottom_store_3, NULL);
		menu3->setScale(0.2f);
		menu3->setPosition(Vec2(-147, -40));
		board_store->addChild(menu3);

		//装备4
		auto sprite_zb4 = Sprite::create("store/pic/equip4.png");
		auto bottom_store_4 = MenuItemLabel::create(sprite_zb4, CC_CALLBACK_1(myScene1::show_equip4, this));
		auto menu4 = Menu::create(bottom_store_4, NULL);
		menu4->setScale(0.2);
		menu4->setPosition(Vec2(-87, -40));
		board_store->addChild(menu4);

		//装备5
		auto sprite_zb5 = Sprite::create("store/pic/equip5.png");
		auto bottom_store_5 = MenuItemLabel::create(sprite_zb5, CC_CALLBACK_1(myScene1::show_equip5, this));
		auto menu5 = Menu::create(bottom_store_5, NULL);
		menu5->setScale(0.2);
		menu5->setPosition(Vec2(-267, -100));
		board_store->addChild(menu5);

		//装备6
		auto sprite_zb6 = Sprite::create("store/pic/equip6.png");
		auto bottom_store_6 = MenuItemLabel::create(sprite_zb6, CC_CALLBACK_1(myScene1::show_equip6, this));
		auto menu6 = Menu::create(bottom_store_6, NULL);
		menu6->setScale(0.2);
		menu6->setPosition(Vec2(-207, -100));
		board_store->addChild(menu6);

		//装备7
		auto sprite_zb7 = Sprite::create("store/pic/equip7.png");
		auto bottom_store_7 = MenuItemLabel::create(sprite_zb7, CC_CALLBACK_1(myScene1::show_equip7, this));
		auto menu7 = Menu::create(bottom_store_7, NULL);
		menu7->setScale(0.2);
		menu7->setPosition(Vec2(-147, -100));
		board_store->addChild(menu7);

		//装备8
		auto sprite_zb8 = Sprite::create("store/pic/equip8.png");
		auto bottom_store_8 = MenuItemLabel::create(sprite_zb8, CC_CALLBACK_1(myScene1::show_equip8, this));
		auto menu8 = Menu::create(bottom_store_8, NULL);
		menu8->setScale(0.2);
		menu8->setPosition(Vec2(-87, -100));
		board_store->addChild(menu8);

		//装备9
		auto sprite_zb9 = Sprite::create("store/pic/equip9.png");
		auto bottom_store_9 = MenuItemLabel::create(sprite_zb9, CC_CALLBACK_1(myScene1::show_equip9, this));
		auto menu9 = Menu::create(bottom_store_9, NULL);
		menu9->setScale(0.2);
		menu9->setPosition(Vec2(-267, -160));
		board_store->addChild(menu9);

		//装备10
		auto sprite_zb10 = Sprite::create("store/pic/equip10.png");
		auto bottom_store_10 = MenuItemLabel::create(sprite_zb10, CC_CALLBACK_1(myScene1::show_equip10, this));
		auto menu10 = Menu::create(bottom_store_10, NULL);
		menu10->setScale(0.2);
		menu10->setPosition(Vec2(-207, -160));
		board_store->addChild(menu10);

		//装备11
		auto sprite_zb11 = Sprite::create("store/pic/equip11.png");
		auto bottom_store_11 = MenuItemLabel::create(sprite_zb11, CC_CALLBACK_1(myScene1::show_equip11, this));
		auto menu11 = Menu::create(bottom_store_11, NULL);
		menu11->setScale(0.2);
		menu11->setPosition(Vec2(-147, -160));
		board_store->addChild(menu11);

		//装备12
		auto sprite_zb12 = Sprite::create("store/pic/equip12.png");
		auto bottom_store_12 = MenuItemLabel::create(sprite_zb12, CC_CALLBACK_1(myScene1::show_equip12, this));
		auto menu12 = Menu::create(bottom_store_12, NULL);
		menu12->setScale(0.2);
		menu12->setPosition(Vec2(-87, -160));
		board_store->addChild(menu12);

		//购买按钮
		auto sprite_purchase = Sprite::create("store/button_purchase.png");
		auto bottom_store_99 = MenuItemLabel::create(sprite_purchase, CC_CALLBACK_1(myScene1::buyEquip, this));
		auto menu88 = Menu::create(bottom_store_99, NULL);
		menu88->setScale(0.3);
		menu88->setPosition(Vec2(-310, -190));
		board_store->addChild(menu88, 188);

		//关闭按钮
		auto sprite_store_close = Sprite::create("store/button_close.png");
		auto bottom_store_0 = MenuItemLabel::create(sprite_store_close, CC_CALLBACK_1(myScene1::closeStore, this));
		auto menu0 = Menu::create(bottom_store_0, NULL);
		menu0->setScale(0.66);
		menu0->setPosition(Vec2(192, 162));
		board_store->addChild(menu0, 100);
	}
}

//装备1展示
void myScene1::show_equip1(Ref *pSender)
{
	auto sprite_info_equip1 = Sprite::create("store/info/equip1.png");
	sprite_info_equip1->setScale(0.5);
	sprite_info_equip1->setPosition(Vec2(70, 130));
	this->getChildByTag(99)->addChild(sprite_info_equip1);
	myScene1::chosen_equip_number = 1;
}

//装备2展示
void myScene1::show_equip2(Ref *pSender)
{
	auto sprite_info_equip2 = Sprite::create("store/info/equip2.png");
	sprite_info_equip2->setScale(0.5);
	sprite_info_equip2->setPosition(Vec2(70, 130));
	this->getChildByTag(99)->addChild(sprite_info_equip2);
	myScene1::chosen_equip_number = 2;
}

//装备3展示
void myScene1::show_equip3(Ref *pSender)
{
	auto sprite_info_equip3 = Sprite::create("store/info/equip3.png");
	sprite_info_equip3->setScale(0.5);
	sprite_info_equip3->setPosition(Vec2(70, 130));
	this->getChildByTag(99)->addChild(sprite_info_equip3);
	myScene1::chosen_equip_number = 3;
}

//装备4展示
void myScene1::show_equip4(Ref *pSender)
{
	auto sprite_info_equip4 = Sprite::create("store/info/equip4.png");
	sprite_info_equip4->setScale(0.5);
	sprite_info_equip4->setPosition(Vec2(70, 130));
	this->getChildByTag(99)->addChild(sprite_info_equip4);
	myScene1::chosen_equip_number = 4;
}

//装备5展示
void myScene1::show_equip5(Ref *pSender)
{
	auto sprite_info_equip5 = Sprite::create("store/info/equip5.png");
	sprite_info_equip5->setScale(0.5);
	sprite_info_equip5->setPosition(Vec2(70, 130));
	this->getChildByTag(99)->addChild(sprite_info_equip5);
	myScene1::chosen_equip_number = 5;
}

//装备6展示
void myScene1::show_equip6(Ref *pSender)
{
	auto sprite_info_equip6 = Sprite::create("store/info/equip6.png");
	sprite_info_equip6->setScale(0.5);
	sprite_info_equip6->setPosition(Vec2(70, 130));
	this->getChildByTag(99)->addChild(sprite_info_equip6);
	myScene1::chosen_equip_number = 6;
}

//装备7展示
void myScene1::show_equip7(Ref *pSender)
{
	auto sprite_info_equip7 = Sprite::create("store/info/equip7.png");
	sprite_info_equip7->setScale(0.5);
	sprite_info_equip7->setPosition(Vec2(70, 130));
	this->getChildByTag(99)->addChild(sprite_info_equip7);
	myScene1::chosen_equip_number = 7;
}

//装备8展示
void myScene1::show_equip8(Ref *pSender)
{
	auto sprite_info_equip8 = Sprite::create("store/info/equip8.png");
	sprite_info_equip8->setScale(0.5);
	sprite_info_equip8->setPosition(Vec2(70, 130));
	this->getChildByTag(99)->addChild(sprite_info_equip8);
	myScene1::chosen_equip_number = 8;
}

//装备9展示
void myScene1::show_equip9(Ref *pSender)
{
	auto sprite_info_equip9 = Sprite::create("store/info/equip9.png");
	sprite_info_equip9->setScale(0.5);
	sprite_info_equip9->setPosition(Vec2(70, 130));
	this->getChildByTag(99)->addChild(sprite_info_equip9);
	myScene1::chosen_equip_number = 9;
}

//装备10展示
void myScene1::show_equip10(Ref *pSender)
{
	auto sprite_info_equip10 = Sprite::create("store/info/equip10.png");
	sprite_info_equip10->setScale(0.5);
	sprite_info_equip10->setPosition(Vec2(70, 130));
	this->getChildByTag(99)->addChild(sprite_info_equip10);
	myScene1::chosen_equip_number = 10;
}

//装备11展示
void myScene1::show_equip11(Ref *pSender)
{
	auto sprite_info_equip11 = Sprite::create("store/info/equip11.png");
	sprite_info_equip11->setScale(0.5);
	sprite_info_equip11->setPosition(Vec2(70, 130));
	this->getChildByTag(99)->addChild(sprite_info_equip11);
	myScene1::chosen_equip_number = 11;
}

//装备12展示
void myScene1::show_equip12(Ref *pSender)
{
	auto sprite_info_equip12 = Sprite::create("store/info/equip12.png");
	sprite_info_equip12->setScale(0.5);
	sprite_info_equip12->setPosition(Vec2(70, 130));
	this->getChildByTag(99)->addChild(sprite_info_equip12);
	myScene1::chosen_equip_number = 12;
}

//关闭按钮功能
void myScene1::closeStore(Ref* pSender)
{
	this->getChildByTag(99)->removeFromParentAndCleanup(true);
	store_judge = 0;
	myScene1::chosen_equip_number = 0;
	_mouseListener->setEnabled(true);
}

//购买按钮功能
void myScene1::buyEquip(Ref* pSender)
{
	if (hero->equipcnt == 6)
		return;
	int p = myScene1::chosen_equip_number;
	if (hero->hero.money < hero->equip[p - 1].money)
		return;
	hero->Hero::puton(p);

	int px = 0;
	int py = 0;
	int n = hero->equipcnt;

	for (int i = 1; i <= n; i++)
	{
		if (hero->equipsit[i] == 0)
			n = i;
	}

	switch (n)
	{
	case 1:
		px = 670;
		py = -113;
		break;
	case 2:
		px = 733;
		py = -113;
		break;
	case 3:
		px = 796;
		py = -113;
		break;
	case 4:
		px = 670;
		py = -176;
		break;
	case 5:
		px = 733;
		py = -176;
		break;
	case 6:
		px = 796;
		py = -176;
		break;
	}

	if (p == 1)
	{
		auto sprite_zb = Sprite::create("store/pic/equip1.png");
		auto sell = MenuItemLabel::create(sprite_zb, CC_CALLBACK_1(myScene1::sellEquip, this, n, p));
		auto menu = Menu::create(sell, NULL);
		menu->setScale(0.18);
		menu->setPosition(Vec2(px, py));
		this->getChildByTag(200)->addChild(menu, 30 + n, 230 + n);
	}
	else if (p == 2)
	{
		auto sprite_zb = Sprite::create("store/pic/equip2.png");
		auto sell = MenuItemLabel::create(sprite_zb, CC_CALLBACK_1(myScene1::sellEquip, this, n, p));
		auto menu = Menu::create(sell, NULL);
		menu->setScale(0.18);
		menu->setPosition(Vec2(px, py));
		this->getChildByTag(200)->addChild(menu, 30 + n, 230 + n);
	}
	else if (p == 3)
	{
		auto sprite_zb = Sprite::create("store/pic/equip3.png");
		auto sell = MenuItemLabel::create(sprite_zb, CC_CALLBACK_1(myScene1::sellEquip, this, n, p));
		auto menu = Menu::create(sell, NULL);
		menu->setScale(0.18);
		menu->setPosition(Vec2(px, py));
		this->getChildByTag(200)->addChild(menu, 30 + n, 230 + n);
	}
	else if (p == 4)
	{
		auto sprite_zb = Sprite::create("store/pic/equip4.png");
		auto sell = MenuItemLabel::create(sprite_zb, CC_CALLBACK_1(myScene1::sellEquip, this, n, p));
		auto menu = Menu::create(sell, NULL);
		menu->setScale(0.18);
		menu->setPosition(Vec2(px, py));
		this->getChildByTag(200)->addChild(menu, 30 + n, 230 + n);
	}
	else if (p == 5)
	{
		auto sprite_zb = Sprite::create("store/pic/equip5.png");
		auto sell = MenuItemLabel::create(sprite_zb, CC_CALLBACK_1(myScene1::sellEquip, this, n, p));
		auto menu = Menu::create(sell, NULL);
		menu->setScale(0.18);
		menu->setPosition(Vec2(px, py));
		this->getChildByTag(200)->addChild(menu, 30 + n, 230 + n);
	}
	else if (p == 6)
	{
		auto sprite_zb = Sprite::create("store/pic/equip6.png");
		auto sell = MenuItemLabel::create(sprite_zb, CC_CALLBACK_1(myScene1::sellEquip, this, n, p));
		auto menu = Menu::create(sell, NULL);
		menu->setScale(0.18);
		menu->setPosition(Vec2(px, py));
		this->getChildByTag(200)->addChild(menu, 30 + n, 230 + n);
	}
	else if (p == 7)
	{
		auto sprite_zb = Sprite::create("store/pic/equip7.png");
		auto sell = MenuItemLabel::create(sprite_zb, CC_CALLBACK_1(myScene1::sellEquip, this, n, p));
		auto menu = Menu::create(sell, NULL);
		menu->setScale(0.18);
		menu->setPosition(Vec2(px, py));
		this->getChildByTag(200)->addChild(menu, 30 + n, 230 + n);
	}
	else if (p == 8)
	{
		auto sprite_zb = Sprite::create("store/pic/equip8.png");
		auto sell = MenuItemLabel::create(sprite_zb, CC_CALLBACK_1(myScene1::sellEquip, this, n, p));
		auto menu = Menu::create(sell, NULL);
		menu->setScale(0.18);
		menu->setPosition(Vec2(px, py));
		this->getChildByTag(200)->addChild(menu, 30 + n, 230 + n);
	}
	else if (p == 9)
	{
		auto sprite_zb = Sprite::create("store/pic/equip9.png");
		auto sell = MenuItemLabel::create(sprite_zb, CC_CALLBACK_1(myScene1::sellEquip, this, n, p));
		auto menu = Menu::create(sell, NULL);
		menu->setScale(0.18);
		menu->setPosition(Vec2(px, py));
		this->getChildByTag(200)->addChild(menu, 30 + n, 230 + n);
	}
	else if (p == 10)
	{
		auto sprite_zb = Sprite::create("store/pic/equip10.png");
		auto sell = MenuItemLabel::create(sprite_zb, CC_CALLBACK_1(myScene1::sellEquip, this, n, p));
		auto menu = Menu::create(sell, NULL);
		menu->setScale(0.18);
		menu->setPosition(Vec2(px, py));
		this->getChildByTag(200)->addChild(menu, 30 + n, 230 + n);
	}
	else if (p == 11)
	{
		auto sprite_zb = Sprite::create("store/pic/equip11.png");
		auto sell = MenuItemLabel::create(sprite_zb, CC_CALLBACK_1(myScene1::sellEquip, this, n, p));
		auto menu = Menu::create(sell, NULL);
		menu->setScale(0.18);
		menu->setPosition(Vec2(px, py));
		this->getChildByTag(200)->addChild(menu, 30 + n, 230 + n);
	}
	else if (p == 12)
	{
		auto sprite_zb = Sprite::create("store/pic/equip12.png");
		auto sell = MenuItemLabel::create(sprite_zb, CC_CALLBACK_1(myScene1::sellEquip, this, n, p));
		auto menu = Menu::create(sell, NULL);
		menu->setScale(0.18);
		menu->setPosition(Vec2(px, py));
		this->getChildByTag(200)->addChild(menu, 30 + n, 230 + n);
	}

	setUIData();
	setUIBloodAndMagic();
}


void myScene1::sellEquip(Ref* pSender, int n, int p)
{
	this->getChildByTag(200)->removeChildByTag(230 + n);
	hero->equipsit[n] = 0;
	hero->Hero::takeoff(p);

	setUIData();
	setUIBloodAndMagic();
}


//商店界面（结束）

//UI上数据显示（开始）

//升级技能按钮

void myScene1::skillUp()
{
	if (hero->qlevel != 4)
	{
		auto sprite_qskillup = Sprite::create("UI/skill_up.png");
		auto button_store_91 = MenuItemLabel::create(sprite_qskillup, CC_CALLBACK_1(myScene1::qSkillUp, this));
		auto menu91 = Menu::create(button_store_91, NULL);
		menu91->setScale(0.4);
		menu91->setPosition(Vec2(440, -52));
		this->getChildByTag(200)->addChild(menu91, 91, 191);
	}

	if (hero->wlevel != 4)
	{
		auto sprite_wskillup = Sprite::create("UI/skill_up.png");
		auto bottom_store_92 = MenuItemLabel::create(sprite_wskillup, CC_CALLBACK_1(myScene1::wSkillUp, this));
		auto menu92 = Menu::create(bottom_store_92, NULL);
		menu92->setScale(0.4);
		menu92->setPosition(Vec2(570, -52));
		this->getChildByTag(200)->addChild(menu92, 92, 192);
	}

	if (hero->rlevel != 4)
	{
		auto sprite_rskillup = Sprite::create("UI/skill_up.png");
		auto bottom_store_93 = MenuItemLabel::create(sprite_rskillup, CC_CALLBACK_1(myScene1::rSkillUp, this));
		auto menu93 = Menu::create(bottom_store_93, NULL);
		menu93->setScale(0.4);
		menu93->setPosition(Vec2(704, -52));
		this->getChildByTag(200)->addChild(menu93, 93, 193);
	}
}

void myScene1::qSkillUp(Ref*pSender)
{
	hero->qlevel++;
	setUIExpAndLevel();
	int number = myScene3::select();
	if (number == 2)
	{
		switch (hero->qlevel)
		{
		case 1:
			hero->hero.atkspeed += 25;
			break;
		case 2:
			hero->hero.atkspeed += 35;
			break;
		case 3:
			hero->hero.atkspeed += 45;
			break;
		case 4:
			hero->hero.atkspeed += 60;
			break;
		}
	}
	setUIData();
	this->getChildByTag(200)->removeChildByTag(191);
	this->getChildByTag(200)->removeChildByTag(192);
	this->getChildByTag(200)->removeChildByTag(193);
}

void myScene1::wSkillUp(Ref*pSender)
{
	hero->wlevel++;
	setUIExpAndLevel();
	//int number = myScene3::select();
	int number = 1;
	if (number == 1)
	{
		switch (hero->wlevel)
		{
		case 1:
			hero->hero.atk += 20;
			hero->hero.totalmagic += 40;
			break;
		case 2:
			hero->hero.atk += 30;
			hero->hero.totalmagic += 60;
			break;
		case 3:
			hero->hero.atk += 40;
			hero->hero.totalmagic += 80;
			break;
		case 4:
			hero->hero.atk += 50;
			hero->hero.totalmagic += 100;
			break;
		}
	}
	if (number == 2)
	{
		switch (hero->wlevel)
		{
		case 1:
			hero->hero.atk += 80;
			break;
		case 2:
			hero->hero.atk += 20;
			break;
		case 3:
			hero->hero.atk += 20;
			break;
		case 4:
			hero->hero.atk += 20;
			break;
		}
	}
	if (number == 3)
	{
		switch (hero->qlevel)
		{
		case 1:
			hero->hero.armor += 40;
			break;
		case 2:
			hero->hero.armor += 20;
			break;
		case 3:
			hero->hero.armor += 20;
			break;
		case 4:
			hero->hero.armor += 20;
			break;
		}
	}
	setUIData();
	this->getChildByTag(200)->removeChildByTag(191);
	this->getChildByTag(200)->removeChildByTag(192);
	this->getChildByTag(200)->removeChildByTag(193);
}

void myScene1::rSkillUp(Ref*pSender)
{
	hero->rlevel++;
	setUIExpAndLevel();
	this->getChildByTag(200)->removeChildByTag(191);
	this->getChildByTag(200)->removeChildByTag(192);
	this->getChildByTag(200)->removeChildByTag(193);
}

//UI上血条蓝条
void myScene1::setUIBloodAndMagic()
{
	if (hero->hero.blood > hero->hero.totalblood)
		hero->hero.blood = hero->hero.totalblood;

	float c_blood = hero->hero.blood;
	float c_magic = hero->hero.magic;
	float blood = hero->hero.totalblood;
	float magic = hero->hero.totalmagic;


	float k_blood = c_blood / blood;
	float k_magic = c_magic / magic;

	this->getChildByTag(200)->removeChildByTag(251);
	this->getChildByTag(200)->removeChildByTag(252);

	if (c_blood > 0)
	{
		auto UIBlood = Sprite::create("UI/blood.png", Rect(0, 0, k_blood * 401.5f, 16.0));//满血条
		UIBlood->setScale(1);
		UIBlood->setAnchorPoint(Vec2(0, 0.5));
		UIBlood->setPosition(Vec2(642, 55.7f));
		this->getChildByTag(200)->addChild(UIBlood, 51, 251);
	}

	if (c_magic > 0)
	{
		auto UIMagic = Sprite::create("UI/magic.png", Rect(0, 0, k_magic * 401.5f, 16.0));//满蓝条
		UIMagic->setScale(1);
		UIMagic->setAnchorPoint(Vec2(0, 0.5));
		UIMagic->setPosition(Vec2(641, 29.7f));
		this->getChildByTag(200)->addChild(UIMagic, 52, 252);
	}


}

//定时器刷新属性函数

void myScene1::setMoney(float dt)
{
	hero->hero.money += 2;

	//金钱
	int mny = hero->hero.money;
	int decimal10;
	int sign10 = 0;
	char* buffer10;
	buffer10 = _fcvt(mny, 0, &decimal10, &sign10);

	this->getChildByTag(200)->removeChildByTag(270);
	auto data_mny = Label::createWithTTF(buffer10, "fonts/wow1.ttf", 22);
	data_mny->setPosition(Vec2(1160, 32));
	this->getChildByTag(200)->addChild(data_mny, 70, 270);
	
	if(all[0].blood<=0)
		Director::getInstance()->replaceScene(myScene2::createScene());

}

//变动时刷新属性函数

void myScene1::setUIData()
{

	//血量上限
	int ttbld = hero->hero.totalblood;
	int decimal62;
	int sign62 = 0;
	char* buffer62;
	buffer62 = _fcvt(ttbld, 0, &decimal62, &sign62);

	this->getChildByTag(200)->removeChildByTag(262);
	auto data_ttbld = Label::createWithTTF(buffer62, "fonts/wow1.ttf", 18);
	data_ttbld->setPosition(Vec2(870, 56));
	this->getChildByTag(200)->addChild(data_ttbld, 62, 262);

	//血量
	if (hero->hero.blood > 0)
	{
		int bld = hero->hero.blood;
		int decimal61;
		int sign61 = 0;
		char* buffer61;
		buffer61 = _fcvt(bld, 0, &decimal61, &sign61);

		this->getChildByTag(200)->removeChildByTag(261);
		auto data_bld = Label::createWithTTF(buffer61, "fonts/wow1.ttf", 18);
		data_bld->setPosition(Vec2(810, 56));
		this->getChildByTag(200)->addChild(data_bld, 61, 261);
	}
	else
	{
		this->getChildByTag(200)->removeChildByTag(261);
		auto data_bld = Label::createWithTTF("0", "fonts/wow1.ttf", 18);
		data_bld->setPosition(Vec2(810, 56));
		this->getChildByTag(200)->addChild(data_bld, 61, 261);
	}

	//蓝量上限
	int ttmag = hero->hero.totalmagic;
	int decimal64;
	int sign64 = 0;
	char* buffer64;
	buffer64 = _fcvt(ttmag, 0, &decimal64, &sign64);

	this->getChildByTag(200)->removeChildByTag(264);
	auto data_ttmag = Label::createWithTTF(buffer64, "fonts/wow1.ttf", 18);
	data_ttmag->setPosition(Vec2(870, 30));
	this->getChildByTag(200)->addChild(data_ttmag, 64, 264);

	//蓝量
	if (hero->hero.magic > 0)
	{
		int mag = hero->hero.magic;
		int decimal63;
		int sign63 = 0;
		char* buffer63;
		buffer63 = _fcvt(mag, 0, &decimal63, &sign63);

		this->getChildByTag(200)->removeChildByTag(263);
		auto data_mag = Label::createWithTTF(buffer63, "fonts/wow1.ttf", 18);
		data_mag->setPosition(Vec2(810, 30));
		this->getChildByTag(200)->addChild(data_mag, 63, 263);
	}
	else
	{
		this->getChildByTag(200)->removeChildByTag(263);
		auto data_bld = Label::createWithTTF("0", "fonts/wow1.ttf", 18);
		data_bld->setPosition(Vec2(810, 30));
		this->getChildByTag(200)->addChild(data_bld, 63, 263);
	}

	//攻击力
	int atk = hero->hero.atk;
	int decimal65;
	int sign65 = 0;
	char* buffer65;
	buffer65 = _fcvt(atk, 0, &decimal65, &sign65);

	this->getChildByTag(200)->removeChildByTag(265);
	auto data_atk = Label::createWithTTF(buffer65, "fonts/wow1.ttf", 24);
	data_atk->setPosition(Vec2(380, 106));
	this->getChildByTag(200)->addChild(data_atk, 65, 265);

	//攻击速度
	int asp = hero->hero.atkspeed;
	int decimal66;
	int sign66 = 0;
	char* buffer66;
	buffer66 = _fcvt(asp, 0, &decimal66, &sign66);

	this->getChildByTag(200)->removeChildByTag(266);
	auto data_atkspd = Label::createWithTTF(buffer66, "fonts/wow1.ttf", 24);
	data_atkspd->setPosition(Vec2(380, 168));
	this->getChildByTag(200)->addChild(data_atkspd, 66, 266);

	//移动速度
	int spd = hero->hero.speed;
	int decimal67;
	int sign67 = 0;
	char* buffer67;
	buffer67 = _fcvt(spd, 0, &decimal67, &sign67);

	this->getChildByTag(200)->removeChildByTag(267);
	auto data_spd = Label::createWithTTF(buffer67, "fonts/wow1.ttf", 24);
	data_spd->setPosition(Vec2(380, 138));
	this->getChildByTag(200)->addChild(data_spd, 67, 267);

	//护甲
	int pdfs = hero->hero.armor;
	int decimal68;
	int sign68 = 0;
	char* buffer68;
	buffer68 = _fcvt(pdfs, 0, &decimal68, &sign68);

	this->getChildByTag(200)->removeChildByTag(268);
	auto data_phydfs = Label::createWithTTF(buffer68, "fonts/wow1.ttf", 24);
	data_phydfs->setPosition(Vec2(380, 78));
	this->getChildByTag(200)->addChild(data_phydfs, 68, 268);

	//魔抗
	int mdfs = hero->hero.m_dfs;
	int decimal69;
	int sign69 = 0;
	char* buffer69;
	buffer69 = _fcvt(mdfs, 0, &decimal69, &sign69);

	this->getChildByTag(200)->removeChildByTag(269);
	auto data_magdfs = Label::createWithTTF(buffer69, "fonts/wow1.ttf", 24);
	data_magdfs->setPosition(Vec2(380, 46));
	this->getChildByTag(200)->addChild(data_magdfs, 69, 269);
}

void myScene1::setUIExpAndLevel()
{

	//经验
	if (hero->exp > 0)
	{
		float exp = hero->exp;
		float percent = exp / 10.0;
		int decimal71;
		int sign71 = 0;
		char* buffer71;
		buffer71 = _fcvt(percent, 0, &decimal71, &sign71);

		if (hero->level == 12)
		{
			this->getChildByTag(200)->removeChildByTag(271);
			auto data_exp = Label::createWithTTF("MAX", "fonts/wow1.ttf", 20);
			data_exp->setPosition(Vec2(390, 21));
			this->getChildByTag(200)->addChild(data_exp, 71, 271);
		}
		else
		{
			this->getChildByTag(200)->removeChildByTag(271);
			auto data_exp = Label::createWithTTF(buffer71, "fonts/wow1.ttf", 20);
			data_exp->setPosition(Vec2(390, 21));
			this->getChildByTag(200)->addChild(data_exp, 71, 271);
		}


	}
	else
	{
		this->getChildByTag(200)->removeChildByTag(271);
		auto data_exp = Label::createWithTTF("0", "fonts/wow1.ttf", 20);
		data_exp->setPosition(Vec2(390, 21));
		this->getChildByTag(200)->addChild(data_exp, 71, 271);
	}

	//等级
	if (hero->level <= 12)
	{
		int level = hero->level;
		int decimal72;
		int sign72 = 0;
		char* buffer72;
		buffer72 = _fcvt(level, 0, &decimal72, &sign72);

		this->getChildByTag(200)->removeChildByTag(272);
		auto data_level = Label::createWithTTF(buffer72, "fonts/wow1.ttf", 23);
		data_level->setPosition(Vec2(459, 35));
		this->getChildByTag(200)->addChild(data_level, 72, 272);
	}


	//Q技能等级
	if (hero->qlevel > 0)
	{
		int qlevel = hero->qlevel;
		int decimal73;
		int sign73 = 0;
		char* buffer73;
		buffer73 = _fcvt(qlevel, 0, &decimal73, &sign73);

		this->getChildByTag(200)->removeChildByTag(273);
		auto data_qlevel = Label::createWithTTF(buffer73, "fonts/wow1.ttf", 20);
		data_qlevel->setPosition(Vec2(758, 110));
		this->getChildByTag(200)->addChild(data_qlevel, 73, 273);
	}
	else
	{
		this->getChildByTag(200)->removeChildByTag(273);
		auto data_qlevel = Label::createWithTTF("0", "fonts/wow1.ttf", 20);
		data_qlevel->setPosition(Vec2(758, 110));
		this->getChildByTag(200)->addChild(data_qlevel, 73, 273);
	}


	//W技能等级
	if (hero->wlevel > 0)
	{
		int wlevel = hero->wlevel;
		int decimal74;
		int sign74 = 0;
		char* buffer74;
		buffer74 = _fcvt(wlevel, 0, &decimal74, &sign74);

		this->getChildByTag(200)->removeChildByTag(274);
		auto data_wlevel = Label::createWithTTF(buffer74, "fonts/wow1.ttf", 20);
		data_wlevel->setPosition(Vec2(888, 110));
		this->getChildByTag(200)->addChild(data_wlevel, 74, 274);
	}
	else
	{
		this->getChildByTag(200)->removeChildByTag(274);
		auto data_wlevel = Label::createWithTTF("0", "fonts/wow1.ttf", 20);
		data_wlevel->setPosition(Vec2(888, 110));
		this->getChildByTag(200)->addChild(data_wlevel, 74, 274);
	}

	//R技能等级
	if (hero->rlevel > 0)
	{
		int rlevel = hero->rlevel;
		int decimal75;
		int sign75 = 0;
		char* buffer75;
		buffer75 = _fcvt(rlevel, 0, &decimal75, &sign75);

		this->getChildByTag(200)->removeChildByTag(275);
		auto data_rlevel = Label::createWithTTF(buffer75, "fonts/wow1.ttf", 20);
		data_rlevel->setPosition(Vec2(1022, 110));
		this->getChildByTag(200)->addChild(data_rlevel, 75, 275);
	}
	else
	{
		this->getChildByTag(200)->removeChildByTag(275);
		auto data_rlevel = Label::createWithTTF("0", "fonts/wow1.ttf", 20);
		data_rlevel->setPosition(Vec2(1022, 110));
		this->getChildByTag(200)->addChild(data_rlevel, 75, 275);
	}
}

//UI上数据显示（结束）

//经验获取（开始）

void myScene1::gainExp(Node* who)
{
	float soilder_x = who->getPositionX();
	float soilder_y = who->getPositionY();
	float nx = hero->getPositionX();
	float ny = hero->getPositionY();

	float dx = soilder_x - nx;
	float dy = soilder_x - ny;

	if ((dx*dx + dy * dy) <= 160000)    //吃经验范围
		hero->exp += 100;

	if (hero->exp >= 1000)
	{
		hero->exp -= 1000;
		if (hero->level <= 11)
		{
			hero->level++;
			skillUp();
		}

		//int number = myScene3::select();
		int number = 1;
		switch (number)
		{
		case 1:
			hero->hero.totalblood += 55;
			hero->hero.blood += 55;
			hero->hero.totalmagic += 80;
			hero->hero.magic += 80;
			hero->hero.atk += 4;
			hero->hero.armor += 3;
			break;
		case 2:
			hero->hero.totalblood += 70;
			hero->hero.blood += 70;
			hero->hero.totalmagic += 36;
			hero->hero.magic += 36;
			hero->hero.atk += 8;
			hero->hero.armor += 3;
			break;
		case 3:
			hero->hero.totalblood += 80;
			hero->hero.blood += 80;
			hero->hero.totalmagic += 12;
			hero->hero.magic += 12;
			hero->hero.atk += 4;
			hero->hero.armor += 2;
			break;
		}
		setUIData();
		setUIBloodAndMagic();
	}

	setUIExpAndLevel();
}

//经验获取（结束）

//CD计时


void myScene1::QCD(float dt)
{
	isQabled = true;
}
void myScene1::WCD(float dt)
{
	isWabled = true;
}
void myScene1::ECD(float dt)
{
	isEabled = true;
}

void myScene1::reborn()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	hero->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	sprite2->setPosition(Vec2(0, 0));
	hero->hero.blood = hero->hero.totalblood;
	setUIData();
	setUIBloodAndMagic();
}
