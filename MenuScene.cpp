#include "MenuScene.h"
#include "Gameover.h"
#include "CS_GamingScene.h"
#include "CG_GamingScene.h"
#include "VS_GamingScene.h"


MenuScene::MenuScene(){}

MenuScene::~MenuScene(){}


CCScene* MenuScene::scene(){

	CCScene* sc =NULL;

	do{
		sc = CCScene::create();
		CC_BREAK_IF( !sc );

		MenuScene* layer = MenuScene::create();
		CC_BREAK_IF( !layer);

		sc->addChild( layer );

	} while(0);

	return sc;
}

//初始化方法
bool MenuScene::init(){

	bool sRet = false;
	do{
	
		CC_BREAK_IF(!BasicLayer::init() );

		setupViews();
	

		sRet=true;
	}while(0);

	return sRet;
}

//初始化按钮
void MenuScene::setupViews(){

	 //setBackgroundImage("Menu/menu_bgg.png");
	CCSprite* sp = CCSprite::create("Menu/menu_aa.png");
	sp->setPosition(ccp(getWinSize().width / 2, getWinSize().height / 2));
	this->addChild(sp);

	 CCSize s = CCDirector::sharedDirector()->getWinSize();
	 /*特效*/
	 CCParticleFlower *m_emitter = CCParticleFlower::create();
	 m_emitter->retain();

	 sp->addChild(m_emitter, 10);

	 m_emitter->setTexture(CCTextureCache::sharedTextureCache()->addImage("Menu/6.png"));
	 m_emitter->setLifeVar(0);
	 m_emitter->setLife(10);
	 m_emitter->setScale(1.5f);
	 m_emitter->setSpeed(80);
	 m_emitter->setSpeedVar(0);
	 m_emitter->setEmissionRate(2);
	 m_emitter->setPosition(ccp(480 * 0.5f / 2, 700));




	CCParticleSystemQuad *system = new CCParticleSystemQuad();
    system->initWithFile("Particles/BoilingFoam.plist");
  // system->setTextureWithRect(CCTextureCache::sharedTextureCache()->addImage("Images/particles.png"), CCRectMake(0,0,32,32));
  /* 特效;addChild(system, 10);*/ 
	

	 CCSprite* pLogo1 = CCSprite::create("Menu/396.png");
	 pLogo1->setPosition(ccp(getWinSize().width/2-100, getWinSize().height - 110));
	 this->addChild(pLogo1);	
	 CCActionInterval* jumpby = CCJumpBy::create(0.5, ccp(10, 15), 10, 1);
	 pLogo1->runAction(CCSequence::create(jumpby, jumpby->reverse(), NULL));

	 CCSprite* pLogo2 = CCSprite::create("Menu/379.png");
	 pLogo2->setPosition(ccp(getWinSize().width/2-130,getWinSize().height - 150));
	 this->addChild( pLogo2 );
	 CCActionInterval* jumpby2 = CCJumpBy::create( 0.5, ccp(-10,15), 10, 1);
	 pLogo2->runAction( CCSequence::create(jumpby2, jumpby2->reverse(), NULL));

	 //加入菜单按钮
	 CCSprite* pCGNormal =CCSprite::create("Menu/bofang.png");
	 CCSprite* pCGPressed =CCSprite::create("Menu/bofang1.png");
	 CCSprite* pCGDisabled =CCSprite::create("Menu/bofang.png");

	// CCSprite *d=CCSprite::create("CloseSelected.png");
	// d->setPosition(ccp(320,450));
	//  this->addChild(d);	
	 
	 CCMenuItemImage *out= CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(MenuScene::out));

	 CCMenu* pMenuout = CCMenu::create(out,NULL);

	 pMenuout->setPosition(ccp(320,440));                                                       //1
	  this->addChild(pMenuout);	


	 CCMenuItemSprite* play = CCMenuItemSprite::create(pCGNormal,pCGPressed,pCGDisabled,this,
		 menu_selector(MenuScene::CGgame_callback));
	

	 CCSprite* pCGNormal2 =CCSprite::create("Menu/fenxiang.png");
	 CCSprite* pCGPressed2 =CCSprite::create("Menu/fenxiang1.png");
	 CCSprite* pCGDisabled2 =CCSprite::create("Menu/fenxiang.png");

 CCMenuItemSprite* share = CCMenuItemSprite::create(pCGNormal2,pCGPressed2,pCGDisabled2,this,
		 menu_selector(MenuScene::VSgame_callback));

	 CCSprite* pCGNormal3 =CCSprite::create("Menu/shezhi.png");
	 CCSprite* pCGPressed3 =CCSprite::create("Menu/shezhi1.png");
	 CCSprite* pCGDisabled3 =CCSprite::create("Menu/shezhi.png");

	 CCMenuItemSprite* set = CCMenuItemSprite::create(pCGNormal3,pCGPressed3,pCGDisabled3,this,
		 menu_selector(MenuScene::CSgame_callback));
	 
	 CCMenu* pMenu2 = CCMenu::create(play,NULL);
	 pMenu2->setPosition(ccp(320,getWinSize().height/2+150));                      //2
	 this->addChild( pMenu2 );	 	

	 CCMenu* pMenu = CCMenu::create(share,set,NULL);
	 pMenu->setPosition(ccp(getWinSize().width/2-60,getWinSize().height/2+90));            //3
	 pMenu->alignItemsVerticallyWithPadding(10);

	 this->addChild( pMenu );

	 //关卡和分数显示面板
	 CCSprite* level = CCSprite::create("Menu/level.png");
	 level->setPosition(ccp(100,150));
	 this->addChild( level );
	 //读取最高等级
	int yy = CCUserDefault::sharedUserDefault()->getIntegerForKey("cu_level");  
	sprintf(buf_level,"%d",yy);
	CCLabelTTF* l1=CCLabelTTF::create(buf_level,"Thonburi",40);
	l1->setColor(ccGREEN);
	l1->setPosition(ccp(160,140));
	this->addChild(l1,1);

	 CCSprite* score = CCSprite::create("Menu/score.png");
	 score->setPosition(ccp(100,100));
	 this->addChild( score );
	 //读取最高分
	int xx = CCUserDefault::sharedUserDefault()->getIntegerForKey("name");  
	sprintf(buf_score,"%d",xx);
	CCLabelTTF* s1=CCLabelTTF::create(buf_score,"Thonburi",40);
	s1->setColor(ccGREEN);
	s1->setPosition(ccp(160,90));
	this->addChild(s1,1);


	 /*帧动画*/
	CCSprite* spHero = CCSprite::create("1.png");
	sp->addChild(spHero);
	spHero->setPosition(ccp(40, 120));
	//1.创建动画
	CCAnimation* animation = CCAnimation::create();
	//2.添加帧
	animation->addSpriteFrameWithFileName("1.png");
	animation->addSpriteFrameWithFileName("3.png");
	animation->addSpriteFrameWithFileName("2.png");
	animation->addSpriteFrameWithFileName("4.png");
	//3.设置时间间隔
	animation->setDelayPerUnit(0.6f);
	//4.设置循环次数
	animation->setLoops(-1);
	//5.创建动作
	CCAnimate* animate = CCAnimate::create(animation);
	//6.执行动作
	spHero->runAction(animate);
	CCSequence* seq1 = CCSequence::create(CCMoveTo::create(4.0, ccp(350, 110 )), CCFlipX::create(true), CCMoveTo::create(4.0, ccp(40, 110)), CCFlipX::create(false), NULL);
	spHero->runAction(CCRepeat::create(seq1, -1));
}

void MenuScene::CSgame_callback(CCObject* pSender)
{
	CCLog("CSgame");
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f,GamingSceneCS::scene()));
}

void MenuScene::CGgame_callback(CCObject* pSender)
{
	CCLog("CGgame");
	CCDirector::sharedDirector()->pushScene( CCTransitionFade::create(0.5f,GamingSceneCG::scene()));
}

void MenuScene::VSgame_callback(CCObject* pSender)
  {
	CCLog("VSgame");
	CCDirector::sharedDirector()->pushScene( CCTransitionFade::create(0.5f,GamingSceneVS::scene()));
}

void MenuScene::out(CCObject* pSender){
	 CCDirector::sharedDirector()->end();

}
//重写onEnter方法
void MenuScene::onEnter(){

	CCLayer::onEnter();

	CCLog("onEnter");

	//加入背景音乐

	//根据配置文件中记录的信息来播放配置文件
	bool flag = CCUserDefault::sharedUserDefault()->getBoolForKey("music_not_playing");
	if(!flag){
		if(!SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){
			SimpleAudioEngine::sharedEngine()->playBackgroundMusic("mainMainMusic.mp3",true);
		}
	}
	else {
				SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	}

}