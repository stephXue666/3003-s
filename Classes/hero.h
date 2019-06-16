#pragma once

#include "cocos2d.h"

class Hero:public cocos2d::Sprite
{
public:
	struct heroproperty {
		int totalblood;//血量上限*
		int blood;//当前血量
		int totalmagic;//蓝量上限*
		int magic;//当前蓝量
		int atk;//攻击*
		int atkspeed;//攻击速度*
		int speed;//移动速度*
		int armor;//护甲*
		int m_dfs;//魔抗*
		int money;//金钱
	};

	heroproperty hero;
	int equipcnt = 0;
	int equipsit[7] = { 0 };

	int atk_ditance;

	int camp;
	int level = 1;//等级
	int exp = 0;//经验
	int qlevel = 0;
	int wlevel = 0;
	int elevel = 0;
	int rlevel = 0;
	int	qcd = 0;
	int wcd = 0;
	int rcd = 0;

	/*以下可照此填充装备定义*/
	static heroproperty equip[12];


	void puton(int equipTag);//穿！
	void takeoff(int equipTag);//脱！

	virtual void AfirstSkill() { return; } // 单操作技能仅用这个
	virtual int BfirstSkill(float x, float y) { return 0; } //双操作技能用到这个
	virtual void AsecondSkill() { return; }
	virtual int BsecondSkill(float x, float y) { return 0; }
	virtual void AfourthSkill(){ return; }
	virtual int BfourthSkill(float x, float y){ return 0; }
};

class death :public Hero
{

	virtual void AfirstSkill();
	virtual int BfirstSkill(float x, float y);
	virtual void AsecondSkill();
	virtual int BsecondSkill(float x, float y);
	virtual void AfourthSkill();
	virtual int BfourthSkill(float x, float y);
};


class xin :public Hero
{

	virtual void AfirstSkill();
	virtual int BfirstSkill(float x, float y);
	virtual void AsecondSkill();
	virtual int BsecondSkill(float x, float y);
	virtual void AfourthSkill();
	virtual int BfourthSkill(float x, float y);
};

class sasuke :public Hero
{
	virtual void AfirstSkill();
	virtual int BfirstSkill(float x, float y);
	virtual void AsecondSkill();
	virtual int BsecondSkill(float x, float y);
	virtual void AfourthSkill();
	virtual int BfourthSkill(float x, float y);
};