#include "CS_GamingScene.h"
#include "exSource.h"


GamingSceneCS::GamingSceneCS(){
}

GamingSceneCS::~GamingSceneCS(){}


CCScene* GamingSceneCS::scene(){

	CCScene* sc =NULL;

	do{
		sc = CCScene::create();
		CC_BREAK_IF( !sc );

		GamingSceneCS* layer = GamingSceneCS::create();
		CC_BREAK_IF( !layer);

		sc->addChild( layer );

	} while(0);

	return sc;
}

//初始化方法
bool GamingSceneCS::init(){

	bool sRet = false;
	do{
	
		CC_BREAK_IF(!BasicLayer::init() );

		setupViews();
	

		sRet=true;
	}while(0);

	return sRet;
}

//初始化按钮
void GamingSceneCS::setupViews(){

	do
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
			"Music/CG_bg.mp3",true);
		setBackgroundImage("Scene/scene_bg.png");
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCSprite *bg=CCSprite::create("Gameover/Aboutus.png");
		bg->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(bg);

		/*创建一个返回按钮，回到主菜单
		CCMenuItemImage* BackItem = CCMenuItemImage::create("Scene/fanhui.png","Scene/fanhui2.png",this,menu_selector(GamingSceneCS::menuCloseCallback));
		BackItem->setAnchorPoint(ccp(0,1));
		BackItem->setPosition(ccp(25,830));
		CCMenu* menub = CCMenu::create( BackItem,NULL );
		menub->setPosition( CCPointZero );
		this->addChild( menub,111,156 );*/
		CCMenuItemImage*BackItem = CCMenuItemImage::create("Scene/fanhui.png", "Scene/fanhui1.png",this, menu_selector(GamingSceneCS::menuCloseCallback));
		BackItem->setAnchorPoint(ccp(0, 1));
		BackItem->setPosition(ccp(25, size.height -4));
		CCMenu* menub = CCMenu::create(BackItem, NULL);
		menub->setPosition(CCPointZero);
		this->addChild(menub, 111, 156);


	} while (0);
}

//从新开始
void GamingSceneCS::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
  CCDirector::sharedDirector()->replaceScene(MenuScene::scene());

}

