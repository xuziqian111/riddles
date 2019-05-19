#include"PauseLayer.h"
#include "CG_GamingScene.h"
#include "MenuScene.h"

PauseLayer::PauseLayer(){}
PauseLayer::~PauseLayer(){}

bool PauseLayer::init(){

	if(!CCLayerColor::initWithColor(ccc4(0,0,0,180))){
		return false;
	}

	setupViews();
	return true;

}


//��ʼ���ؼ�
void PauseLayer::setupViews()
{
	do{
		//����menu

		CCSize size = CCDirector::sharedDirector()->getWinSize();
		CCMenuItemImage* resumeItem = CCMenuItemImage::create("Scene/fanhui.png","Scene01/fanhui1.png",this,menu_selector(PauseLayer::play_logic));
		resumeItem->setPosition(ccp(size.width /2,size.height/2));
	
		CCMenu* menu = CCMenu::create(resumeItem,NULL);
		menu->setPosition(CCPointZero);
		this->addChild(menu,5,10);

	}while(0);

}

//�ָ��߼�
void PauseLayer::play_logic(CCObject* pSender)
{
	//1.��ȡ���ڵ㣬����pause layer
	//2.�趨CCMenu(���ڵ���)enableΪtrue
	//3.����CCDirector��resume����
	//GamingSceneCG* father  = (GamingSceneCG*)this->getParent();
	//father->m_pause_layer->setVisible(false);
	
	GamingSceneCG* father2  = (GamingSceneCG*)this->getParent();
	CCMenu* menu=(CCMenu*)father2->getChildByTag(156);
	menu->setEnabled(true);
	CCDirector::sharedDirector()->resume();


}
