#include "BasicLayer.h"


BasicLayer::BasicLayer(){

}


BasicLayer::~BasicLayer(){

}

//��ʼ������
bool BasicLayer::init(){

	bool bRet = false;
	do{

		CC_BREAK_IF( !CCLayer::init());

		bRet = true;
	
	}while(0);

	return bRet;
}

//��ȡ��Ļ��С����
CCSize BasicLayer::getWinSize(){

	return CCDirector::sharedDirector()->getWinSize();
}

void BasicLayer::setBackgroundImage(const char* back_image_name){
	//CCSize size = CCDirector::sharedDirector()->getWinSize();
	//CCSprite* sp = CCSprite::create(back_image_name);
	//sp->setPosition(ccp(getWinSize().width / 2,	getWinSize().height / 2));
	//this->addChild( sp );
}