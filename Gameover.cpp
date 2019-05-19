#include "Gameover.h"
#include "CG_GamingScene.h"


Gameover::Gameover(){}

Gameover::~Gameover(){}


CCScene* Gameover::scene(){

	CCScene* sc =NULL;

	do{
		sc = CCScene::create();
		CC_BREAK_IF( !sc );

		Gameover* layer = Gameover::create();
		CC_BREAK_IF( !layer);

		sc->addChild( layer );

	} while(0);

	return sc;
}

//��ʼ������
bool Gameover::init(){

	bool sRet = false;
	do{
	
		CC_BREAK_IF(!BasicLayer::init() );

		setupViews();
	

		sRet=true;
	}while(0);

	return sRet;
}

//��ʼ����ť
void Gameover::setupViews(){
	do{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(
			"Music/CG_bg.mp3",true);
		//setBackgroundImage("Scene01/BG_A01.png");

		CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCSprite *bg=CCSprite::create("Gameover/gameover_bg.png");
		bg->setPosition(ccp(size.width/2,size.height/2));
		this->addChild(bg);

		 //��ȡ��ǰ����
		cu_score = CCUserDefault::sharedUserDefault()->getIntegerForKey("name");  	
		sprintf(buf_cuscore,"%d",cu_score);
		CCLabelTTF* s1=CCLabelTTF::create(buf_cuscore,"Thonburi",40);
		s1->setColor(ccGREEN);
		s1->setPosition(ccp(240,360));
		this->addChild(s1,1);

		//��ȡ��ǰ�ؿ���
		cu_level = CCUserDefault::sharedUserDefault()->getIntegerForKey("cu_level");  	
		sprintf(buf_culevel,"%d",cu_level);
		CCLabelTTF* l1=CCLabelTTF::create(buf_culevel,"Thonburi",40);
		l1->setColor(ccGREEN);
		l1->setPosition(ccp(240,500));
		this->addChild(l1,1);

		cu_level++;
		save_cu_level();//���浱ǰ�ؿ���

		//����һ�����ذ�ť���ص����˵�
		CCMenuItemImage* BackItem = CCMenuItemImage::create("Gameover/nextlevel.png","Gameover/nextlevel2.png",this,menu_selector(Gameover::menuCloseCallback));
		BackItem->setAnchorPoint(ccp(0,1));
		BackItem->setPosition(ccp(240,300));
		CCMenu* menub = CCMenu::create( BackItem,NULL );
		menub->setPosition( CCPointZero );
		this->addChild( menub,111,156 );


	} while (0);
}
//���浱ǰ�ؿ���
void Gameover::save_cu_level(){
	CCUserDefault::sharedUserDefault()->setIntegerForKey("cu_level", cu_level);  
	CCUserDefault::sharedUserDefault()->flush();//д�˶���Ҫ�ύ  
}
//���¿�ʼ
void Gameover::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
  CCDirector::sharedDirector()->replaceScene(GamingSceneCG::scene());

}

