
#ifndef __VS_GamingScene_H__
#define __VS_GamingScene_H__

#include "BasicLayer.h"
#include "MenuScene.h"
#include "VS_GamingScene1.h"

USING_NS_CC;

static CCApplication * sm_pSharedApplication;

class GamingSceneVS : public BasicLayer
{
public:
	GamingSceneVS();
	~GamingSceneVS();

	static CCScene* scene();
	virtual bool init();
	void setupViews();

	void menuCloseCallback(CCObject* pSender);
	void menuCloseCallback1(CCObject* pSender);
	CREATE_FUNC(GamingSceneVS);


};




#endif //__WELCOME_H__
#pragma once
