#ifndef __UnitRes_h__
#define __UnitRes_h__

#include "Head.h"
#include "XDropTool.h"
#include "GameGlobe.h"

struct WeaponPos
{
	int id;
	short type; //��������
	short cover;//�ڵ���ϵ��0��ʾ�ڵ�UNIT��1��ʾ��UNIT�ڵ�
	int x;//�ùҽӵ��ڸ÷����ϵ�λ�������ս��λ��׼���ƫ��
	int y;
};

class UnitRes : public Ref
{
public:
	UnitRes();
	~UnitRes();

private:
	int			_ID; //ÿһ��Unit��Ӧһ��UnitRes, iID��UnitRes��Ψһ��ʶ
	int			_HP;
	int			_animID;
	int			_speedX[WALK_DIR_COUNT];//8�����ƶ��ٶȣ�8�������ݶ��У�˳��Ϊ D, DL, L, LU, U, UR, R, RD
	int			_speedY[WALK_DIR_COUNT];//8�����ƶ��ٶȣ�8�������ݶ��У�˳��Ϊ D, DL, L, LU, U, UR, R, RD
	int			_moveGridCount;//ռ�ظ����
	int			_bodyRectCounts[STAND_DIR_COUNT]; // ÿ�����򹥻����εĸ���
	int			_explodeCount[STAND_DIR_COUNT];//������ըЧ���ĸ���
	int			_weaponPosCount;//�ҽӵ���Ŀ������������ͬ
	int			_weaponTypeCount;//�ҽӵ��������͵���Ŀ
	int			_weaponEveryTypeCount;//ÿ���������͵Ĺҽӵ���Ŀ
	Vec2*		_moveGrids;//ÿ��������ͬ
	Rect**		_bodyRect[STAND_DIR_COUNT];//16���򹥻���Χ��16�������ݶ��У�˳��ͬ��
	Explode**	_explode[STAND_DIR_COUNT];//ÿ��������ը������
	WeaponPos** _weaponPos[STAND_DIR_COUNT];//ÿ������Ĺҽӵ�����
	int*		_weaponTypeList;//�ҽӵ����������б�
	int*		_weaponTypeIndexList; //ÿ���������͵Ĺҽӵ������ֵ��
	Vec2		_moveAnimRanges[WALK_DIR_COUNT];//8�����ƶ��ٶȣ�8�������ݶ��У�˳��Ϊ D, DL, L, LU, U, UR, R, RD
	Vec2		_dieAnimRanges[STAND_DIR_COUNT];//16���������Ķ���range��ֻ��9�������ݣ�˳��ͬ��
	Vec2		_standAnimRanges[STAND_DIR_COUNT];//16����վ���Ķ���range��ֻ��9�������ݣ�˳��Ϊ D, DDL, DL, DLL, L, LLU, LU, LUU, U
	Vec2		_centerPoints[STAND_DIR_COUNT];//16�����������ĵ��λ�ã�16�������ݶ��У�˳��ΪD, DDL, DL, DLL, L, LLU, LU, LUU, U, UUR, UR, URR, R, RRD, RD, RDD
};

#endif // __UnitRes_h__
