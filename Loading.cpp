#include"Loading.h"
#include"MenuScene.h"

LoadingLayer::LoadingLayer(){

	current_number=0;//当前读取的数量
	total_number=10;//总图片的数量
}

LoadingLayer::~LoadingLayer(){}

bool  LoadingLayer::init(){
	bool sRect=false;
	do
	{
		CC_BREAK_IF(!CCLayer::init());

				//Loading Layer***********加载层***************
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		current_number=0;
		total_number=10;

		m_pLabelLoading = CCLabelTTF::create("loading...", "Arial", 15);
		m_pLabelPercent = CCLabelTTF::create("%0", "Arial", 15);
	
		m_pLabelLoading->setPosition(ccp(size.width / 2, size.height / 2 - 20));
		m_pLabelPercent->setPosition(ccp(size.width / 2, size.height / 2 + 20));

		this->addChild(m_pLabelLoading);
		this->addChild(m_pLabelPercent);


		// load textrues
		CCTextureCache::sharedTextureCache()->addImageAsync("Menu/bofang.png", this, callfuncO_selector(LoadingLayer::Loading_callback));
		CCTextureCache::sharedTextureCache()->addImageAsync("Menu/bofang1.png", this, callfuncO_selector(LoadingLayer::Loading_callback));
		CCTextureCache::sharedTextureCache()->addImageAsync("Menu/fenxiang.png", this, callfuncO_selector(LoadingLayer::Loading_callback));
		CCTextureCache::sharedTextureCache()->addImageAsync("Menu/fenxiang1.png", this, callfuncO_selector(LoadingLayer::Loading_callback));
		CCTextureCache::sharedTextureCache()->addImageAsync("Menu/shezhi.png", this, callfuncO_selector(LoadingLayer::Loading_callback));
		CCTextureCache::sharedTextureCache()->addImageAsync("Menu/shezhi1.png", this, callfuncO_selector(LoadingLayer::Loading_callback));
		CCTextureCache::sharedTextureCache()->addImageAsync("Menu/daY.png", this, callfuncO_selector(LoadingLayer::Loading_callback));
		CCTextureCache::sharedTextureCache()->addImageAsync("Menu/xiaoY.png", this, callfuncO_selector(LoadingLayer::Loading_callback));
		CCTextureCache::sharedTextureCache()->addImageAsync("Menu/level.png", this, callfuncO_selector(LoadingLayer::Loading_callback));
		CCTextureCache::sharedTextureCache()->addImageAsync("Menu/score.png", this, callfuncO_selector(LoadingLayer::Loading_callback));
		CCTextureCache::sharedTextureCache()->addImageAsync("Menu/menu_bgg.png", this, callfuncO_selector(LoadingLayer::Loading_callback));
	//	CCTextureCache::sharedTextureCache()->addImageAsync("Particles/BoilingFoam.png", this, callfuncO_selector(LoadingLayer::Loading_callback));


		CCProgressTimer * pross = CCProgressTimer::create(CCSprite::create("Scene/loading.png"));
		pross->setPosition(ccp(size.width / 2, size.height / 2 - 100));
    //设置进度条的样式(时针旋转方式)
		pross->setType( kCCProgressTimerTypeRadial);
    //设置进度值范围[0,100]
		pross->setPercentage(100);
    //反进度计时
		pross->setReverseProgress(true);
		addChild(pross);
		CCProgressTo *to1 = CCProgressTo::create(1, 100);
		pross->runAction(to1);  
		//prossR->runAction( CCRepeatForever::create(to2));
		

		sRect=true;

	} while (0);
	return sRect;
}

CCScene*  LoadingLayer::scene(){
	CCScene* sc=NULL;
	do
	{
		sc=CCScene::create();
		CC_BREAK_IF(!sc);
		 LoadingLayer* layer= LoadingLayer::create();
		 CC_BREAK_IF(!layer);
		 sc->addChild(layer);
	} while (0);
	return sc;
}
void LoadingLayer::Loading_callback(CCObject* pSender )
{
		++current_number;
		char tmp[10];
		sprintf(tmp,"%%%d", (int)(((float)current_number / total_number) * 100));
		m_pLabelPercent->setString(tmp);

		if(current_number==total_number)
		{ 
			CCDirector::sharedDirector()->pushScene(MenuScene::scene());
		}

}