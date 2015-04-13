/****************************************************************************
 Copyright (c) 2014 Chukong Technologies Inc.

 http://github.com/chukong/EarthWarrior3D

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __Moon3d__AirCraft__
#define __Moon3d__AirCraft__

#include "cocos2d.h"
#include "GameEntity.h"
#include "UnitRes.h"
#include "XDropTool.h"
#include "Weapon.h"

USING_NS_CC;

using namespace std;

class Unit : public GameEntity
{
public:
	Unit();
	Unit(bool alive, float hp, int score);
	Unit(int type, int shadowType, int radius, bool alive, float hp, int score);
	virtual ~Unit(){};
    virtual bool hurt(float damage);
    virtual void die();
    void shoot();
    //CC_SYNTHESIZE(float, _HP, HP);
    bool alive();
    virtual void move(float y, float dt);
    virtual void reset();
	int getUnitID() const { return _unitID; }
	void setUnitID(int aUnitID) { _unitID = aUnitID; }
	int getMoveType() const { return _moveType; }
	void setMoveType(int aMoveType) { _moveType = aMoveType; }
	int getMaxHP() const { return _maxHP; }
	void setMaxHP(int aMaxHP) { _maxHP = aMaxHP; }
	int getBodyLevel() const { return _BodyLevel; }
	void setBodyLevel(int aBodyLevel) { _BodyLevel = aBodyLevel; }
	int getMoveX() const { return _moveX; }
	void setMoveX(int aMoveX) { _moveX = aMoveX; }
	int getMoveY() const { return _moveY; }
	void setMoveY(int aMoveY) { _moveY = aMoveY; }
	int getMotion() const { return _motion; }
	void setMotion(int aMotion) { _motion = aMotion; }
	int getWalkDir() const { return _walkDir; }
	void setWalkDir(int aWalkDir) { _walkDir = aWalkDir; }
	int getAIType() const { return _AIType; }
	void setAIType(int aAIType) { _AIType = aAIType; }
	int getCampType() const { return _campType; }
	void setCampType(int aCampType) { _campType = aCampType; }
	vector<int> getMoveProb() const;
	void setMoveProb(int* aMoveProb, int len);
	vector<Vec2> getMoveItemData() const;
	void setMoveItemData(Vec2* aMoveItemData, int len);
	vector<Vec2> getPointItemData() const { return _pointItemData; }
	void setPointItemData(Vec2* aPointItemData, int len);
	vector<Vec2> getFireItemData() const { return _fireItemData; }
	void setFireItemData(Vec2* aFireItemData, int len);
	vector<Vec2> getDistItemData() const { return _distItemData; }
	void setDistItemData(Vec2* aDistItemData, int len);
	vector<XDropTool> getDropToolData() const { return _dropToolData; }
	void setDropToolData(XDropTool* aDropToolData, int len);
	vector<XUnitOrder> getUnitRecycleOrder() const { return _unitRecycleOrder; }
	void setUnitRecycleOrder(XUnitOrder* aUnitRecycleOrder, int len);
	Rect getWalkRect() const { return _walkRect; }
	void setWalkRect(Rect aWalkRect) { _walkRect = aWalkRect; }
	Rect getMoveRect() const { return _moveRect; }
	void setMoveRect(Rect aMoveRect) { _moveRect = aMoveRect; }
	UnitRes getUnitRes() const { return _unitRes; }
	void setUnitRes(UnitRes aUnitRes) { _unitRes = aUnitRes; }
protected:
    float		_HP;
    bool		_alive;
	bool		_active;//�Ƿ񱻼���
	bool		_eventUnit;//�Ƿ��¼�Unit;
    int			_score;
	int			_iDieExplodCount;//������ը��������
	int			_startExplodeTick;//��ը��ʼʱ��
	int			_campType;
	int			_unitID;	//���¼�ϵͳ��ID
	int			_moveType;	//�˶���ʽ
	int			_maxHP;		//Ѫ�����ֵ
	int			_BodyLevel;//�������������
	//�ƶ��ٶ�
	int			_moveX;
	int			_moveY;
	//����
	int			_motion;//��ǰ�Ķ���
	//����
	int			_beAttackTick;//�������ӳ٣�������ɫ
	int			_diaphaneity;//͸����
	int			_dieTick;
	bool		_die;//������˸״̬
	//�ж�����
	int        	 _walkDir;       //�����°����򣬲���������ת���Unit��iWalkDir��������
	//AI
	int			_AIType;
	//fire
	bool		_unitFireRequire;
	int			_shotPosIndex;//���������
	int			_shotLogicType;
	int			_weaponResID;
	int			_fireTick;//�������漰�ӳ�
	vector<bool>	 _dieExplode;//��¼�Ƿ�ը
	//vector<Weapon>	 _weaponList; //��Unit��������Weapon

	//8��������ƶ��ĸ���
	vector<int>		_moveProb;
	//�ƶ�ʱ��͸���
	vector<Vec2>	_moveItemData;
	//�ƶ���ʽΪ��·���ƶ�ʱ�ı�ʾ����
	vector<Vec2>	_pointItemData;
	//�������
	vector<Vec2>	_fireItemData;
	//���ݾ��룬��Ŀ���ƶ��ĸ���
	vector<Vec2>	_distItemData;
	//�������
	vector<XDropTool> _dropToolData;
	//ѭ��ָ��
	vector<XUnitOrder>	_unitRecycleOrder;
	//�жϿ����߷�Χ
	bool		_endableMove;
	Rect		_walkRect;//������ײ�жϾ���
	Rect		_moveRect;//��Ч���߾���
	UnitRes		 _unitRes;
};

#endif /* defined(__Moon3d__AirCraft__) */
