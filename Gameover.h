#ifndef __VS_GAMEOVER_H__
#define __VS_GAMEOVER_H__

#include "BasicLayer.h"
#include "MenuScene.h"

USING_NS_CC;



class Gameover: public BasicLayer
{
public:
	Gameover();
	~Gameover();

	static CCScene* scene();
	virtual bool init();
	void setupViews();
	void save_cu_level();

	void menuCloseCallback(CCObject* pSender);
	CREATE_FUNC(Gameover);

	char buf_cuscore[80];
	char buf_culevel[80];
	int cu_level;
	int cu_score;

};




#endif //__WELCOME_H__
