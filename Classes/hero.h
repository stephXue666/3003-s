#pragma once

#include "cocos2d.h"

class Hero:public cocos2d::Sprite
{
public:
	struct heroproperty {
		int totalblood;//Ѫ������*
		int blood;//��ǰѪ��
		int totalmagic;//��������*
		int magic;//��ǰ����
		int atk;//����*
		int atkspeed;//�����ٶ�*
		int speed;//�ƶ��ٶ�*
		int armor;//����*
		int m_dfs;//ħ��*
		int money;//��Ǯ
	};

	heroproperty hero;
	int equipcnt = 0;
	int equipsit[7] = { 0 };

	int atk_ditance;

	int camp;
	int level = 1;//�ȼ�
	int exp = 0;//����
	int qlevel = 0;
	int wlevel = 0;
	int elevel = 0;
	int rlevel = 0;
	int	qcd = 0;
	int wcd = 0;
	int rcd = 0;

	/*���¿��մ����װ������*/
	static heroproperty equip[12];


	void puton(int equipTag);//����
	void takeoff(int equipTag);//�ѣ�

	virtual void AfirstSkill() { return; } // ���������ܽ������
	virtual int BfirstSkill(float x, float y) { return 0; } //˫���������õ����
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