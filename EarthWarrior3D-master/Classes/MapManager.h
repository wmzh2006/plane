#ifndef __MapManager_h__
#define __MapManager_h__

#include "Head.h"
#include "GameGlobe.h"

class GameScene;
class XMap;

class MapManager : public Ref
{
public:
	enum MapLayer
	{
		EIdle = 0,
		ELoadMapInf, //��ͼ����
		ELoadMapFloor,//�ذ��
		ELoadMapTop,//����
		ELoadMapBuilding,//����
		ELoadMapUnit,//�����ɫ
		ELoadMapWalkRect,//���߷�Χ
		ELoadMapImg,//ͼ��
	};

	MapManager(GameScene* scene);
	~MapManager();
	bool RequestMap(int aMapID, bool aLocal);
	bool IsMapOk(int aMapID);
	bool AnalyzeDataL();
	bool LoadMapImg(int aMapID);
	void AnalyzeMap();
	bool createFloor();
	Node* getFloor() { return _floor; }
	void createUnits();
	int getXMapW();
	int getXMapH();
private:
	 GameScene*           iGameScene;
	 bool                 iLoadingMap;    //�Ƿ����������ͼ
	 bool                 iLocalMap;
	 bool                 iGetMap;
	 int                  iRequestMapID;
	 int                  iActiveMapID;   //��ǰ��Ծ�ĵ�ͼID
	 int 				  iLastCameraY;	//�ϴ��������Y����
	 int 				  iScreenPartCount; //��Ļ�����ɵĻ���������
	 int				  iImgCounts;
	 int				  iLoadState;     //�������
	 XMap*                iPrepareLoadMap;//׼������ĵ�ͼ��
	 XMap*                iActiveMap;     //��ǰ��Ծ�ĵ�ͼ
	 Texture2D** 		  iMapImgs;		//��ͼͼ��
	 std::string          iFileName;      //��ͼ����
	 Node*				 _floor;//�ذ�
};

#endif // __MapManager_h__
