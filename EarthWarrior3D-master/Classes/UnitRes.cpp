#include "UnitRes.h"

UnitRes::UnitRes()
:_ID(0) //ÿһ��Unit��Ӧһ��UnitRes, iID��UnitRes��Ψһ��ʶ
,_HP(0)
,_animID(0)
,_moveGridCount(0)//ռ�ظ����
,_weaponPosCount(0)//�ҽӵ���Ŀ������������ͬ
,_weaponTypeCount(0)//�ҽӵ��������͵���Ŀ
,_weaponEveryTypeCount(0)//ÿ���������͵Ĺҽӵ���Ŀ
,_moveGrids(nullptr)//ÿ��������ͬ
,_weaponTypeList(nullptr)//�ҽӵ����������б�
,_weaponTypeIndexList(nullptr) //ÿ���������͵Ĺҽӵ������ֵ��
{
	memset(_speedX, 0, WALK_DIR_COUNT);
	memset(_speedY, 0, WALK_DIR_COUNT);
	memset(_bodyRectCounts, 0, WALK_DIR_COUNT);
	memset(_explodeCount, 0, WALK_DIR_COUNT);
}

UnitRes::~UnitRes()
{
	CC_SAFE_DELETE_ARRAY(_moveGrids);
	CC_SAFE_DELETE_ARRAY(_weaponTypeList);
	CC_SAFE_DELETE_ARRAY(_weaponTypeIndexList);
	for (int i = 0; i < STAND_DIR_COUNT; i++)
	{
		/*CC_SAFE_DELETE(_bodyRect[i]);*/
	}
	for (int i = 0; i < STAND_DIR_COUNT; i++)
	{
		/*CC_SAFE_DELETE(_explode[i]);*/
	}
	for (int i = 0; i < STAND_DIR_COUNT; i++)
	{
		//CC_SAFE_DELETE(_weaponPos[i]);
	}
}
