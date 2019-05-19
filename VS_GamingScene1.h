#ifndef __VS_GamingScene1_H__
#define __VS_GamingScene1_H__

#include "BasicLayer.h"

USING_NS_CC;


class GamingSceneVS1 : public BasicLayer
{
public:
	
	GamingSceneVS1();
	~GamingSceneVS1();
	//是否已经初始化
BOOL                m_bInitCocos2dX;
	//创建Cocos2dX窗口
	BOOL        CreateCocos2dXWindow();
	
	static CCScene* scene();
	virtual bool init();
	void setupViews();

	void menuCloseCallback(CCObject* pSender);
	void menuCloseCallback1(CCObject* pSender);
	CREATE_FUNC(GamingSceneVS1);


};




#endif //__WELCOME_H__