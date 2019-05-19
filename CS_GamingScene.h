#ifndef __CS_GamingScene_H__
#define __CS_GamingScene_H__

#include "BasicLayer.h"
#include "MenuScene.h"


USING_NS_CC;



class GamingSceneCS: public BasicLayer
{
public:
	GamingSceneCS();
	~GamingSceneCS();

	static CCScene* scene();
	virtual bool init();
	void setupViews();
	void menuCloseCallback(CCObject* pSender);
	CREATE_FUNC(GamingSceneCS);

};




#endif //__WELCOME_H__
