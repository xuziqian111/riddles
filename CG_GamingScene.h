#ifndef __CG_GamingScene_H__
#define __CG_GamingScene_H__

#include "exSource.h"
#include "BasicLayer.h"
#include "Cube_Layer.h"


USING_NS_CC;



class GamingSceneCG: public CCLayerColor
{
public:
	GamingSceneCG();
	~GamingSceneCG();


	static CCScene* scene();
	virtual bool init();

	//virtual bool initWithColor(ccc4(255,255,255,255));
	void setupViews();
	void pause_logic(CCObject* pSender);
	void RiddlePanel(CCObject* pSender);
	void menuCloseCallback(CCObject* pSender);
	void save_level();
	void save_cu_level();
	void save_h_score();

	void update(float dt);

	CREATE_FUNC(GamingSceneCG);
	CC_SYNTHESIZE_READONLY(Cube_Layer*, m_cube_Layer, Cube_Layer);

	CCMenuItemImage* BackItem;
	CCMenuItemImage* pauseItem;
	
	int levelx;
	char level_buf[80];

	//´æ·Å·½¿éµÄÈÝÆ÷
	cocos2d::CCArray *_cubes;
};




#endif //__WELCOME_H__
