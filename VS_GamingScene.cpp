#include "VS_GamingScene.h"
#include "VS_GamingScene1.h"
#include "exSource.h"
#include "stdafx.h"

//#include "WebView.h"
#include "Cocos2dxWebBrowser.h"

#include <atlbase.h>
#include <atlwin.h>  
#include <windows.h>  
#pragma comment(lib,"atl")  
#pragma comment(lib,"User32.lib")  

CComModule _Module;

#define MAX_LOADSTRING 100


GamingSceneVS::GamingSceneVS(){}

GamingSceneVS::~GamingSceneVS(){}


CCScene* GamingSceneVS::scene(){

	CCScene* sc =NULL;

	do{
		sc = CCScene::create();
		CC_BREAK_IF( !sc );

		GamingSceneVS* layer = GamingSceneVS::create();
		CC_BREAK_IF( !layer);

		sc->addChild( layer );

	} while(0);

	return sc;
}

//初始化方法
bool GamingSceneVS::init(){

	bool sRet = false;
	do{
	
		CC_BREAK_IF(!BasicLayer::init() );

		setupViews();
	

		sRet=true;
	}while(0);

	return sRet;
}

//初始化按钮
void GamingSceneVS::setupViews(){
	do{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
			"Music/CG_bg.mp3",true);
		setBackgroundImage("Scene01/BG_A01.png");
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCSprite *bg=CCSprite::create("Gameover/Share.png");
		bg->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(bg);
		//创建外部网络按钮
		CCMenuItemImage* share= CCMenuItemImage::create("Scene/fanhui.png", "Scene/fanhui2.png", this, menu_selector(GamingSceneVS::menuCloseCallback1));
		share->setAnchorPoint(ccp(0, 1));
		share->setPosition(ccp(200, 830));
		CCMenu* menub1 = CCMenu::create(share, NULL);
		menub1->setPosition(CCPointZero);
		this->addChild(menub1, 111, 156);
		
		/*WebView* view = WebView::create();
		view->setUrl("http://www.google.com");
		this->addChild(view);*/

		//创建一个返回按钮，回到主菜单
		CCMenuItemImage* BackItem = CCMenuItemImage::create("Scene/fanhui.png","Scene/fanhui2.png",this,menu_selector(GamingSceneVS::menuCloseCallback));
		BackItem->setAnchorPoint(ccp(0,1));
		BackItem->setPosition(ccp(25,830));
		CCMenu* menub = CCMenu::create( BackItem,NULL );
		menub->setPosition( CCPointZero );
		this->addChild( menub,111,156 );
	} while (0);
}
//从新开始
void GamingSceneVS::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
  CCDirector::sharedDirector()->replaceScene(MenuScene::scene());

}
void GamingSceneVS::menuCloseCallback1(CCObject* pSender)
{
	//CCDirector::Cocos2dxWebBrowser.cp()->Cocos2dxWebBrowser.cpp// : 定义应用程序的入口点。
//	CCDirector::sharedDirector()->replaceScene(Cocos2dxWebBrowser::scene());
	CCDirector::sharedDirector()->replaceScene(GamingSceneVS1::scene());
//	CCApplication::shareApplication()->openURL("http://www.baidu.com");
//
}
