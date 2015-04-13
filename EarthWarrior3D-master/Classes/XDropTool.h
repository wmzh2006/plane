#ifndef __XDropTool_h__
#define __XDropTool_h__

#include "Head.h"

class XDropTool
{
public:
	XDropTool():type(0), min(0), max(0), prob(0){}
	int type;//���ͣ�0��ʾѪ����1��ʾ����A��2��ʾ����B��3��ʾ�������
	int min;//��ʾ���Ͷ�Ӧ�����������ĳ����Χ�ڣ���ΧȡֵΪ min <= prop < max�����type == 3��ô������������Ч
	int max;
	int prob;//�����Ӧ���ߵĿ����ԣ����type == 3��ô����������ߣ����ðٷֱȸ���
}; 

class XUnitFactory
{
public:
	XUnitFactory() :unitType(0), left(0), top(0), width(0), height(0), unitCount(0), interval(0){};
	int unitType;//��������
	int left;//�����ĵ�ͼ��Χ��ʹ��ʵ�ʵ�ͼ����
	int top;
	int width;
	int height;
	int unitCount;//��������
	int interval;//�˴γ���֮����Ҫ��ȴ��ʱ��
};

class XUnitOrder
{
public:
	XUnitOrder() :Direct(0), Speed(0), Time(0), BulletType(0), FireLogic(0), Addition(0){};
	int Direct;    //����
	int Speed;     //�ٶ�
	int Time;      //ʱ��tickΪ��λ
	int BulletType;//�ӵ�����
	int FireLogic; //�����߼�
	int Addition;  //
};

class Explode
{
public:
	Explode() :iAnimID(0), iAdd(0), iX(0), iY(0), iStart(0), iEnd(0), iBeginIndex(0){};
   int iAnimID;//�ñ�ը�Ķ���ID
   int iAdd;//������
   int iX;//��ըЧ�������ս��λ��׼���ƫ����
   int iY;
   int iStart;//�����ը�����Ĳ���range
   int iEnd;
   int iBeginIndex;//��ʾ�ӻ����˵�����������ʼ����ֱ��������beginIndex��ô��֮֡��ʼ���������ըЧ��
};
#endif // __XDropTool_h__
