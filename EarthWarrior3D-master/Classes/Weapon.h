
#ifndef __Weapon_h__
#define __Weapon_h__

#include "Unit.h"
#include "WeaponRes.h"

enum WeaponState
{
	W_FLAME = 0,
	W_BULLET,
	W_CASTOFF,
};

enum WeaponCampType
{
	W_ENEMY = 0,
	W_ALLY,
	W_NEUTRAL,
};

class Weapon
{
public:
	//weapon sound
	//TODO
	
	Weapon(){}
	~Weapon(){}

private:
	bool		_castoff;
	int			_castoffState;//�������״̬�������ڵ���1ʱ��ɾ��
	bool		_beCover;//�Ƿ�unit�ڵ�
	int			_posIndex;//unit�����Ĺҽڵ�����
	float		_x;//���������
	float		_y;
	
	float		_moveX;
	float		_moveY;
	int			_dir;//����
	int			_state;//
	bool		_bump;
	int			_wcampType;//�ӵ���������
	WeaponRes	_weaponRes;
	/*Unit*		_unit;*/
};
#endif // __Weapon_h__
