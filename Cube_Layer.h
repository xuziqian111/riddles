#ifndef __Panel_LAYER_H__
#define __Panel_LAYER_H__

#include "BasicLayer.h"

USING_NS_CC;

class Cube_Layer : public CCLayerColor{
public:
	Cube_Layer();
	~Cube_Layer();

	virtual bool init();
	virtual void ccTouchesEnded(cocos2d::CCSet *touches,cocos2d::CCEvent* event);
	void setupViews();
	void add_panel(float d);
	void add_coin();
	void di_line();
	void di_ral();
	void pro_time();
	void level_end();
	void remove_panels();
	void spriteMoveFnished(CCNode * sender);
	void onPause(CCObject* pSender);
	void gameCallback(CCObject* pSender);
	void menuCloseCallback(CCObject* pSender);
	void updscore();
	void updgold();
	void overscore();
	void remove_flowers(CCObject* pSender);

	void creatFlowerButton();
	void IdentificationFlowers();
	
	CCSprite* FlowersButton;
	CCSprite* FlowersButton1;
	bool FlowersButtonTouch;
    bool FlowersButtonTouch1;
	bool ansx;
	;

	void gameqjy(CCObject* pSender);
	void gameqj(CCObject* pSender);
	void ygameqjy();
	void ngameqjy();

	//void overgold();

	void save_cu_score();
	void levelCallback(CCObject* pSender);

	CREATE_FUNC(Cube_Layer);

	CCSprite * cube;
	CCSprite *coin;
	CCSprite *yingtao;
	CCSprite *jiaoyin;
	CCSprite *dacuoceng;

	CCSprite* panel;
	CCSprite * booms;
	CCSprite * coins;

	CCSprite* pausebg;
	CCSprite* goldbg;
	CCLabelTTF* score;
	CCLabelTTF* gold;
	CCSprite* top;
	CCSprite* ti;
	CCSprite* di;
	CCMenuItemFont* con1;
	CCMenuItemFont* con2;
	CCMenu* childMenu;
	CCMenu* conMenu;
	CCMenu* conMenu1;
	CCDictionary* chnStrings;
	CCLabelTTF* qu1;
	CCLabelTTF* ans1;
	int scorexx;
	std::string qu;
	std::string ans;
	std::string con;
	std::string start;
	std::string next;
	std::string yes;
	std::string no;
	CCMenuItemImage* nextlevel;

	/*vector<string> flowerslist1 = {
		"flowers / ²¨Ë¹¾Õ.jpg",
		"flowers / µÛÍõ»¨.jpg",
		"flowers / ¸ë×ÓÀ¼.jpg",
		"flowers / À¶ºûµûð°Î².jpg",
		"flowers / À¶»¨éº.jpg",
		"flowers / ÁåÀ¼.jpg",
		"flowers / ÂíÌãÁ«.jpg",
		"flowers / Ã×À¼»¨.jpg",
		"flowers / Ä¾éÈ»¨.jpg",
		"flowers / Èý½ÇÃ·.jpg"
	};*/

	const char * name1;
	const char * name2;
	const char * name3;

	
	char buffer1[80]; 
	char buffer2[80];
	char buffer3[80];
	char scobuffer[100];
	char buf_level[100];
	char ans_buf[80];

	int flowerorder ;
    int levels;
	int x1;
	int x2;
	int scorex;
	int levelx;
	int n;
	int num_cube;
	int num_flowers;
	//´æ·Å·½¿éµÄÈÝÆ÷
	cocos2d::CCArray *_cubes;
	int _cubes_data[36];
	cocos2d::CCArray *_coins;
	cocos2d::CCArray *_jiaoyins;
	cocos2d::CCArray *_yingtaos;

	

};

#endif //__PAUSE_LAYER_H__