#ifndef __LOADINGLAYER_H__
#define __LOADINGLAYER_H__
#include<iostream>
#include "cocos2d.h"
USING_NS_CC;

class LoadingLayer:public CCLayer
{
public:
	LoadingLayer();
	~LoadingLayer();

	virtual bool init();

	static CCScene* scene();
	CREATE_FUNC(LoadingLayer);

	void Loading_callback(CCObject* pSender );

public:
	int current_number;//当前读取的数量
	int total_number;//总图片的数量
	cocos2d::CCLabelTTF *m_pLabelLoading;
    cocos2d::CCLabelTTF *m_pLabelPercent;
};
#endif