#ifndef __XMap_h__
#define __XMap_h__

#include "Head.h"
#include "XDropTool.h"

class SMapFloor : public Ref{
public:
	SMapFloor() :iImageID(0), iFlipH(0), iX(0), iY(0){};
	int iImageID;
	bool iFlipH;
	int iX;
	int iY;
};

class SMapUnit : public Ref
{
public:
	SMapUnit();
	~SMapUnit();
	void release();
	short urID;//��ʾ�õ�λʹ�õ���һ����ս��λ��Դ
	short id;//����ս��λ��ID��
	short x;//����ս��λ�����ꣻ
	short y;
	short dir;//��ʼ����
	short AIType;//AI����
	short CampType;//��Ӫ���� 0 --- ����  1 --- �˾�  2 --- Player
	short MoveType;//�ƶ���ʽ
	//���ƶ���ʽΪ����ƶ�ʱ��ʾ �ƶ�ʱ��͸���
	//���ƶ���ʽΪ��·���ƶ�ʱ��ʾ ����
	short           iMoveItemCount;
	short           iDistItemCount;//Ŀ�����
	short           iFireItemCount; //�������
	short           iDropToolCount;//�������
	short           iOrderCount;   //ָ����
	short           iRecycleOrderCount; //ѭ��ָ����
	int*			iMoveProb;  //8��������ƶ��ĸ���
	Vec2*			iMoveItemData;
	Vec2*			iFireItemData;
	Vec2*			iDistItemData;
	XDropTool*      iDropToolData;
	XUnitOrder*     iOrderData;
	XUnitOrder*     iRecycleOrderData;
};

class SMapBuilding{
public:
	SMapBuilding();
	~SMapBuilding();
	void release();
	bool    bflip;  //0��ʾ��ˮƽ��ת��1��ʾˮƽ��ת
	bool    bcasern;//�Ƿ��Ӫ
	short   brID;   //��ʾ�ý���ʹ�õ��Ǹ���Դ
	short   id;     //�ý�����ID��
	short   x;      //�ý����Ļ�׼������ꣻע�⣺���������ĵ�
	short   y;      //
	short   state;  //��ʼ״̬��0��ʾ��ã�1��ʾ��٣�2��ʾȫ��
	short   tool;   //��ը����ֵĹ���
	short   add;    //������Ϣ
	int    iUnitFactoryCount;//��������
	int    iDropToolCount;//������������
	XUnitFactory* iUnitFactoryData;
	XDropTool* iDropToolData;
};

//��ͼͼ��ʼ����ֵ
static const int MAP_IMAGE_START_INDEX[] = {
	100, 300, 200, 300, 100 };
//��ͼͼ�����Ŀ
static const int MAP_IMAGE_COUNT[] = {
	34, 29, 32, 29, 34 };
//��ͼID��Ӧ�Ĺؿ�
static const int MAPID_TO_STAGE[] = {
	0, 0, 1, 1, 2, 2, 3, 3, 4, 4 };
//��ͼ�������ĸ߶�
static const int PART_HEIGHT = 24;

class XMap : public cocos2d::Ref
{
private:

public:
	XMap();
	XMap(int aID);
	~XMap();
	void init(int aID);
	void AnalyzeInfDataL();
	void AnalyzeFloorDataL();
	void AnalyzeUnitDataL();
	void AnalyzeBuildingDataL();
	void AnalyzeRectDataL();
	void Release();
	bool LoadMapImg();
	void DoGameLoad();
	void AnalyzeTopDataL();
	int getID() const { return iID; }
	void setID(int aID) { iID = aID; }
	int getTopCount() const { return iTopCount; }
	int getFloorCount() const { return iFloorCount; }
	SMapFloor* getMapFloor() const { return iMapFloor; }
	int getWidth() const { return iWidth; }
	int getHeight() const { return iHeight; }
	int getUnitCount() { return iUnitCount; }
	const SMapUnit* getSMapUnit() const { return iMapUnit; }
private:
	int             	iID;                    // ��ͼID��ȫ��Ψһv
	int					iActivist;
	int             	iWidth;                 // �����ص�
	int             	iHeight;                // �����ص�
	int 				iBackColor;				// ����ɫ
	//��ͼ�����
	int					iCameraX;				//�����X����
	int 				iCameraY;				//�����Y����

	int            		iFloorCount;            //�ذ���
	int            		iUnitCount;             //Unit��
	int            		iBuildingCount;         //������
	int            		iWalkRectCount;         //�������߾��εĸ���
	int            		iTopCount;				//����ذ���
	SMapFloor*     		iMapTop;                //����ذ�����
	SMapFloor*      	iMapFloor;				//�ذ�����
	SMapUnit*			iMapUnit;               //Unit����
	SMapBuilding*   	iMapBuilding;           //��������
	bool*	          	ibWalkRectActive;		//�������������Ƿ��Ծ
	Rect*	          	iMapWalkRect;           //�������߾���
};

#endif // __XMap_h__
