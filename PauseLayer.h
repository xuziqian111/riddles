#ifndef __PAUSE_LAYER_H__
#define __PAUSE_LAYER_H__

#include "BasicLayer.h"

USING_NS_CC;

class PauseLayer : public CCLayerColor{
public:
	PauseLayer();
	~PauseLayer();

	virtual bool init();

	void setupViews();

	CREATE_FUNC(PauseLayer);

	void play_logic(CCObject* pSender);
};

#endif //__PAUSE_LAYER_H__