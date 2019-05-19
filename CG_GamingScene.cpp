#include "CG_GamingScene.h"

#include "exSource.h"
#include "MenuScene.h"

#include <stdlib.h>

GamingSceneCG::GamingSceneCG(){
	levelx=1;
}

GamingSceneCG::~GamingSceneCG(){}


CCScene* GamingSceneCG::scene(){

	CCScene* sc =NULL;

	do{
		sc = CCScene::create();
		CC_BREAK_IF( !sc );

		GamingSceneCG* layer = GamingSceneCG::create();
		CC_BREAK_IF( !layer);

		sc->addChild( layer );

	} while(0);

	return sc;
}

//初始化方法
bool GamingSceneCG::init(){

	bool sRet = false;
	do{
	
		CC_BREAK_IF(!CCLayerColor::init() );

	//	this->initWithColor(ccc4(255,255,255,255));
		levelx = CCUserDefault::sharedUserDefault()->getIntegerForKey("cu_level"); 
		setupViews();

		sRet=true;
	}while(0);

	return sRet;
}

//row一行有6个水晶
//line一列有9个水晶
//CCSprite* cube[ROW][LINE];
//初始化按钮
void GamingSceneCG::setupViews(){
	do{		
		//添加背景音乐
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
			"Music/CG_bg.mp3", true);
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		//添加背景框
		CCSprite *bg=CCSprite::create("Scene/scene_bg.png");
		bg->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(bg);
		//添加等级条
		CCSprite *level=CCSprite::create("Scene/L.png");
		level->setPosition(ccp(400,size.height-60));
		this->addChild(level,1);
		sprintf(level_buf,"%d",levelx);
		CCLabelTTF* l1=CCLabelTTF::create(level_buf,"Thonburi",35);
		l1->setColor(ccGREEN);
		l1->setPosition(ccp(410,size.height-68));
		this->addChild(l1,1);

		//添加cube层
		m_cube_Layer=Cube_Layer::create();
		this->addChild(m_cube_Layer);
		
		//创建一个返回按钮，回到主菜单
		BackItem = CCMenuItemImage::create("Scene/fanhui.png","Scene/fanhui1.png",this,menu_selector(GamingSceneCG::menuCloseCallback));
		BackItem->setAnchorPoint(ccp(0,1));
		BackItem->setPosition(ccp(25,BackItem->getContentSize().height+10));
		CCMenu* menub = CCMenu::create( BackItem,NULL );
		menub->setPosition( CCPointZero );
		this->addChild( menub,111,156 );
	
	} while (0);

}


void GamingSceneCG::RiddlePanel(CCObject* pSender)
{
	CCLog("RiddlePanel");
}

void GamingSceneCG::update(float dt){
	

}
void GamingSceneCG::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MenuScene::scene());
}

