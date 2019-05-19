#ifndef __WELCOME_H__
#define __WELCOME_H__

#include "BasicLayer.h"


USING_NS_CC;



class MenuScene: public BasicLayer
{
public:
	MenuScene();
	~MenuScene();

	static CCScene* scene();
	virtual bool init();
	void setupViews();

	void CSgame_callback(CCObject* pSender);//经典模式
	void CGgame_callback(CCObject* pSender);//挑战模式
	void VSgame_callback(CCObject* pSender);//对战模式
	void out(CCObject* pSender);
	virtual void onEnter();
	CREATE_FUNC(MenuScene);
	char buf_level[80]; 
	char buf_score[80]; 
};




#endif //__WELCOME_H__