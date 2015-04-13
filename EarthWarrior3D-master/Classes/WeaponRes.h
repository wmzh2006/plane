#ifndef __WeaponRes_h__
#define __WeaponRes_h__

#include "Head.h"
using namespace std;

class WeaponRes
{
private:
	int		_ID;
	bool	_flame;//�Ƿ��л���
	bool	_flameFollowUnit;//�����Ƿ����unit
	bool	_lockUnit;//�Ƿ���סunit�ķ���

	int		_flameAnimID;//����Ķ�������
	int		_bulletAnimID;//�ӵ��Ķ�������
	int		_fireAnimID;//�ӵ�������Ķ�������
	int		_smokeAnimID;//β�̵Ķ�������
	int		_explordeAnimID;//��ը��������

	int		_shotFrame;//�����ڵڼ�֡�����ӵ�
	int		_power;//�ӵ�����
	int		_bulletLogicType;//�ӵ����߼�����
	int		_fireDelay;//������ӳ�
	int		_smokeDelay;//���������ӳ�
	Rect	_weaponHitRect;//�ӵ���������
	int		_speed;//�ӵ��ٶ�

	vector<Vec2>	_flameAnimRange;
	vector<Vec2>	_bulletAnimRange;
	vector<Vec2>	_fireAnimRange;
};

#endif // __WeaponRes_h__
