#include "VS_GamingScene1.h"
#include "exSource.h"
#include "stdafx.h"
#include "Cocos2dxWebBrowser.h"
#include "Gameover.h"
#include "AppDelegate.h"
#include "CCEGLView.h"
#include "CS_GamingScene.h"
#include "VS_GamingScene.h"
#include <atlbase.h>
#include <atlwin.h>  
#include <windows.h>  
#pragma comment(lib,"atl")  
#pragma comment(lib,"User32.lib")  

// Cocos2dxWebBrowser.cpp : 定义应用程序的入口点。



GamingSceneVS1::GamingSceneVS1() {}

GamingSceneVS1::~GamingSceneVS1() {}


CCScene* GamingSceneVS1::scene() {

	 CCScene * sc = NULL;

	do {
		sc = CCScene::create();
		CC_BREAK_IF(!sc);

		GamingSceneVS1* layer = GamingSceneVS1::create();
		CC_BREAK_IF(!layer);

		sc->addChild(layer);

	} while (0);

	return sc;
}



//初始化方法
bool GamingSceneVS1::init() {

	bool sRet = false;
	do {

		//CC_BREAK_IF(!BasicLayer::init());
		//_tWinMain1;

		sRet = true;
	} while (0);

	return sRet;
}

//初始化
void GamingSceneVS1::setupViews() {
	// int wmId, wmEvent;
	// PAINTSTRUCT ps;
	// HDC hdc;
	// RECT rc;

	
}


//从新开始
void GamingSceneVS1::menuCloseCallback(CCObject* pSender)
{
	// "close" menu item clicked
	CCDirector::sharedDirector()->replaceScene(MenuScene::scene());

}
void GamingSceneVS1::menuCloseCallback1(CCObject* pSender)
{// Cocos2dxWebBrowser.cpp : 定义应用程序的入口点。
//
}