#include"Cube_Layer.h"
#include "CG_GamingScene.h"
#include "Gameover.h"
#include "MenuScene.h"
//#include "targetver.h"
#include "BasicLayer.h"
#include<iostream>
#include <fstream>
#include<ShlObj.h>
#include<stdio.h>
#include<string>
#include <tchar.h>
#include<vector>
#include<array>
using std::cout;
using std::string;
using std::endl;
using namespace std;


using namespace std;
Cube_Layer::Cube_Layer(){
	x1= CCUserDefault::sharedUserDefault()->getIntegerForKey("cu_qu");
	x2= CCUserDefault::sharedUserDefault()->getIntegerForKey("cu_qu");
	//x1=0;
	//x2=0;
	const char * flowername1 = "flowers/��˹��.jpg";
	scorex = 0;
	num_cube=35;
	name2="ans_";
	name1="qu_";
	name3="con";
	flowerorder = 0;
}
Cube_Layer::~Cube_Layer(){}

bool Cube_Layer::init(){	
	if(!CCLayerColor::init()){
		return false; 
	}
	setupViews();
	return true;

}

//��ʼ���ؼ�
void Cube_Layer::setupViews()
{
	do{
			this->setTouchEnabled(true);
			CCSize size = CCDirector::sharedDirector()->getWinSize();
			_cubes=new CCArray;
			_coins=new CCArray;
			_jiaoyins=new CCArray;
			_yingtaos=new CCArray;

		CCSpriteBatchNode* batchNode = CCSpriteBatchNode::create("Scene/cube.png", 35);
		 batchNode->setPosition(CCPointZero);
		 this->addChild(batchNode);

		 int j=0;
		 for(int i = 0;i < 35;++i)
		{	
			if(i%5==0&&i>4){
				j++;
			}
			int x=80+(i%5)*80;
			int y=178+j*80;

			cube = CCSprite::createWithTexture(batchNode->getTexture());
			cube->setPosition( ccp(x, y) );
		 		// cube->setTag(1);
			this->addChild(cube);
			_cubes->addObject(cube);
			_cubes_data[i]=1;
		 }
		 CCLog("cube added  ****");
		scorex = CCUserDefault::sharedUserDefault()->getIntegerForKey("name"); 
		flowerorder = CCUserDefault::sharedUserDefault()->getIntegerForKey("levelqu");
		updscore();
		save_cu_score();
	}while(0);

}

void Cube_Layer::ccTouchesEnded(cocos2d::CCSet *touches,cocos2d::CCEvent* event)
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	//��������
	CCTouch *touch=(CCTouch *)touches->anyObject();
	CCPoint pt=touch->getLocationInView();//touch->lacationInView()
	pt=CCDirector::sharedDirector()->convertToGL(pt);//��õ�ǰ�����

	CCLog("%.2f,%.2f",pt.x,pt.y);
	for(int i=0;i<_cubes->count();i++)
	{
		cube=(CCSprite *)_cubes->objectAtIndex(i);
		CCLog("AABB%d",i);
		CCRect cubeRect=CCRectMake(
			cube->getPosition().x-(cube->getContentSize().width/2),
			cube->getPosition().y-(cube->getContentSize().height/2),
			cube->getContentSize().width,
			cube->getContentSize().height
			);
		CCRect ptRect=CCRectMake(pt.x,pt.y,1,1);
		if(ptRect.intersectsRect(cubeRect)&&(_cubes_data[i]==1))
			{
				
				CCLog("CCDD%d",i);
				int seed=101*CCRANDOM_0_1();
				if(seed%3==0)
				{
					//�������
					cube=(CCSprite *)_cubes->objectAtIndex(i);
					//cube->setVisible(false);//����
					this->removeChild(cube);
					_cubes_data[i]=0;
					num_cube--;
					//���һ��Ԫ���
					coin=CCSprite::create("Scene/100coin.png");
					coin->setPosition(ccp(cube->getPosition().x,cube->getPosition().y));
					this->addChild(coin);
					_coins->addObject(coin);
					++scorex;
					removeChild(score);
					updscore();
					add_coin();

				}
				else if (seed%5==0)
				{
					//����һ��
					for (int j = i-i%5; j <i-i%5+5;j++)
					{
						if(_cubes_data[j]==1)
						{
							cube=(CCSprite *)_cubes->objectAtIndex(j);
							//cube->setVisible(false);//����		
							_cubes_data[j]=0;
							num_cube--;
							//���һ��ӣ��ը��
							CCParticleSystemQuad *zhadan01 = new CCParticleSystemQuad();
							zhadan01->initWithFile("Particles/zhadan02.plist");
							zhadan01->setPosition(ccp(cube->getPosition().x,cube->getPosition().y));
							addChild(zhadan01, 10);

							this->removeChild(cube);
						}
					}
					di_line();
				}
				else if(seed%7==0)
				{
					//����һ��
					for (int j = i%5; j <_cubes->count();j=j+5)
					{
						if(_cubes_data[j]==1)
						{
							cube=(CCSprite *)_cubes->objectAtIndex(j);
							//cube->setVisible(false);//����
						
							this->removeChild(cube);
							_cubes_data[j]=0;
							num_cube--;
							//���ը��Ч��
							CCParticleSystemQuad *zhadan01 = new CCParticleSystemQuad();
							zhadan01->initWithFile("Particles/zhadan02.plist");
							zhadan01->setPosition(ccp(cube->getPosition().x,cube->getPosition().y));
							addChild(zhadan01, 10);
						}
					}
					di_ral();
				}	
				//����ʱ�仹û��ʵ��
				else if(seed%11==0)
				{
					//����ʱ��
					cube=(CCSprite *)_cubes->objectAtIndex(i);
					//cube->setVisible(false);//����
					_cubes_data[i]=0;
					num_cube--;
					this->removeChild(cube);
					CCSprite *yingtao2=CCSprite::create("Scene/yingtao.png");
					yingtao2->setPosition(ccp(cube->getPosition().x+20,cube->getPosition().y+10));
					this->addChild(yingtao2);
					_yingtaos->addObject(yingtao2);
					pro_time();
				}
				else
				{					
					this->setTouchEnabled(false);
					//��������
					cube=(CCSprite *)_cubes->objectAtIndex(i);
					//cube->setVisible(false);//����
					_cubes_data[i]=0;
					num_cube--;
					this->removeChild(cube);
					CCSprite *jiaoyin=CCSprite::create("Scene/loading.png");
					jiaoyin->setPosition(ccp(cube->getPosition().x,cube->getPosition().y));
					this->addChild(jiaoyin);
					_jiaoyins->addObject(jiaoyin);
					CCLog("panel");
					add_panel(0.1);

					//this->schedule(schedule_selector( GamingSceneCG::add_panel));
				}
			}
	}
}

//����������
void Cube_Layer::add_panel(float d){
	int flower1;
	CCLog("addpanel");

	CCDictionary* chnStrings = CCDictionary::createWithContentsOfFile("strData1.xml");
	CCSize size = CCDirector::sharedDirector()->getWinSize();
				//����������Ĳ�
	panel = CCSprite::create("Scene/panel1.png");
	panel->setPosition(ccp(size.width / 2,size.height/2+200));
	this->addChild(panel);

	//���ͼƬ
	creatFlowerButton();
	//CCLog("%d\n%d", flowerorder,x1);
	flowerorder++;
		
	CCActionInterval* moveto = CCMoveTo::create( 2.0, ccp(size.width / 2,size.height/2+24));
	CCActionInterval* jump = CCJumpBy::create( 0.5, ccp(0,10), 10, 1);
	panel->runAction( CCSequence::create(moveto,jump,NULL));
	CCLog("panel added.");
	++x1;
	sprintf(buffer1, "%s%d", name1,x1);//ƴ���ַ���
	qu = ((CCString*)chnStrings->objectForKey(buffer1))->getCString(); 
	qu1 = CCLabelTTF::create(qu.c_str(), "Thonburi", 25);
	qu1->setColor(ccc3(0,0,0));
    qu1->setPosition(ccp(size.width / 2, 400));
	panel->addChild(qu1, 1);

	//��
	++x2;
	sprintf(buffer2, "%s%d", name2,x2);//ƴ���ַ���
	ans = ((CCString*)chnStrings->objectForKey(buffer2))->getCString(); 

	//ѡ��
	di=CCSprite::create("Scene/panel2.png");
	//di->setScale();
	di->setPosition(ccp(size.width/2,374));
	this->addChild(di);
	CCMenuItemFont::setFontName("Thonburi");
	CCMenuItemFont::setFontSize(24);
	for (int i = 1; i < 5; i++){
		sprintf(buffer3, "%s%d%d", name3, x1, i);//ƴ���ַ���
		con = ((CCString*)chnStrings->objectForKey(buffer3))->getCString();
		//��ƥ��
		if (con == ans){
			con1 = CCMenuItemFont::create(con.c_str(), this, menu_selector(Cube_Layer::onPause));//���
			//panel->setVisible(false);
		}
		else{
			con1 = CCMenuItemFont::create(con.c_str(), this, menu_selector(Cube_Layer::gameCallback));//���
		}
		con1->setColor(ccc3(0, 0, 0));
		conMenu = CCMenu::create(con1, NULL);
		conMenu->setAnchorPoint(ccp(0, 0));

		if (i<3){ conMenu->setPosition(ccp(130 + (i - 1) * 150, 130)); }
		if (i>2){ conMenu->setPosition(ccp(130 + (i - 3) * 150, 60)); }
		di->addChild(conMenu, 1);
	}
}

void Cube_Layer::creatFlowerButton(){
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	if (x1 == 0){
		FlowersButton = CCSprite::create("flowers/��˹��.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else if (x1 == 1){
		FlowersButton = CCSprite::create("flowers/������.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else if (x1 == 2){
		FlowersButton = CCSprite::create("flowers/������.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else if (x1 == 3){
		FlowersButton = CCSprite::create("flowers/�������β.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else if (x1 == 4){
		FlowersButton = CCSprite::create("flowers/�����.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else if (x1 == 5){
		FlowersButton = CCSprite::create("flowers/����.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);

	}
	else if (x1 == 6){
		FlowersButton = CCSprite::create("flowers/������.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else if (x1 == 7){
		FlowersButton = CCSprite::create("flowers/������.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else if (x1 == 8){
		FlowersButton = CCSprite::create("flowers/ľ�Ȼ�.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else if (x1 == 9){
		FlowersButton = CCSprite::create("flowers/����÷.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else if (x1 == 10){
		FlowersButton = CCSprite::create("flowers/��˹��_1.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	
	else if (x1 == 11){
		FlowersButton = CCSprite::create("flowers/������_1.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else if (x1 == 12){
		FlowersButton = CCSprite::create("flowers/������_1.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else if (x1 == 13){
		FlowersButton = CCSprite::create("flowers/�������β_1.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else if (x1 == 14){
		FlowersButton = CCSprite::create("flowers/�����_1.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else if (x1 == 15){
		FlowersButton = CCSprite::create("flowers/����_1.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);

	}
	else if (x1 == 16){
		FlowersButton = CCSprite::create("flowers/������_1.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else if (x1 == 17){
		FlowersButton = CCSprite::create("flowers/������_1.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else if (x1 == 18){
		FlowersButton = CCSprite::create("flowers/ľ�Ȼ�_1.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else if (x1 == 19) {
		FlowersButton = CCSprite::create("flowers/����÷_1.jpg");
		FlowersButton->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton);
	}
	else {
	FlowersButton = CCSprite::create("write.png");
	FlowersButton->setPosition(ccp(size.width / 2, size.height / 2));
	CCActionInterval* jumpby = CCJumpBy::create(0.5, ccp(10, 15), 10, -1);
	FlowersButton->runAction(CCSequence::create(jumpby, jumpby->reverse(), NULL));
	this->addChild(FlowersButton);
	

	/*CCSprite *bg = CCSprite::create("Scene/scene_bg.png");
	bg->setPosition(ccp(size.width / 2, size.height / 2));*/
}

	
}

void Cube_Layer::add_coin(){
	CCLog("add_coin");
	level_end();

}
void Cube_Layer::di_line(){
	CCLog("diline");
	level_end();
}
void Cube_Layer::di_ral(){
	CCLog("diral");
	level_end();
}
void Cube_Layer::pro_time(){
	CCLog("pro_time");
	level_end();
}
//ͨ��
void Cube_Layer::level_end(){
	if(num_cube==0)
	{	
		updscore();
		save_cu_score();
		//ִ����Ϸ��һ�ؽ���
		CCDirector::sharedDirector()->replaceScene(Gameover::scene());
	}
	levels++;
}

void Cube_Layer::levelCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(GamingSceneCG::scene());
}

//���
void Cube_Layer::onPause(CCObject* pSender){
	CCLog("Right");
	++scorex;
		
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	CCParticleSystemQuad *colorful = new CCParticleSystemQuad();
	colorful->setTexture(CCTextureCache::sharedTextureCache()->addImage("Particles/100coin.png"));
	colorful->initWithFile("Particles/coin_pr.plist");
	colorful->setPosition(ccp(420,size.height-80));
	addChild(colorful, 1);
	
	remove_panels();
	this->setTouchEnabled(true);
	level_end();
}
//�Ƴ����棬�Ƴ��յ�
void Cube_Layer::remove_panels()
{
	this->removeChild(score);
	this->removeChild(FlowersButton);
	this->removeChild(goldbg);
	
	//this->removeChild(carmer);
		
	updscore();
	CCSize size = CCDirector::sharedDirector()->getWinSize();
		//�Ƴ�����
	CCActionInterval* actionMove = CCMoveTo::create( 2.0, ccp(size.width / 2,size.height/2+450));
	CCFiniteTimeAction *actionMoveDone=
		CCCallFuncN::create(this,
		callfuncN_selector(Cube_Layer::spriteMoveFnished));//�Ƴ�
	//�󶨶���
	panel->runAction(CCSequence::create(actionMove,actionMoveDone,NULL));

	//�Ƴ��յ�
	CCActionInterval* actionMove2 = CCMoveTo::create( 2.0, ccp(size.width / 2,size.height/2-450));
	CCFiniteTimeAction *actionMoveDone2=
		CCCallFuncN::create(this,
		callfuncN_selector(Cube_Layer::spriteMoveFnished));//�Ƴ�
	//�󶨶���
	di->runAction(CCSequence::create(actionMove2,actionMoveDone2,NULL));
	FlowersButtonTouch1 = false;
}

void Cube_Layer::spriteMoveFnished(CCNode * sender)
{
	CCSprite *pSprite=(CCSprite*)sender;
	CCLog("remove all");
	this->removeChild(pSprite,true);//�Ƴ�
}
//��������
void Cube_Layer::updscore(){
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		sprintf(scobuffer,"%d",scorex);
		score=CCLabelTTF::create(scobuffer,"Thonburi",40);
		score->setColor(ccGREEN);
		score->setPosition(ccp(360,size.height-120));
		addChild(score,2);
}

//����ǰ����,��Ŀ������
void Cube_Layer::save_cu_score(){
	CCUserDefault::sharedUserDefault()->setIntegerForKey("cu_qu", x1);  //���浱ǰ��Ŀ��
	 CCUserDefault::sharedUserDefault()->flush();//д�˶���Ҫ�ύ  
	CCUserDefault::sharedUserDefault()->setIntegerForKey("name", scorex);  
	CCUserDefault::sharedUserDefault()->flush();//д�˶���Ҫ�ύ  
	CCUserDefault::sharedUserDefault()->setIntegerForKey("numqu", flowerorder);
	CCUserDefault::sharedUserDefault()->flush();//д�˶���Ҫ�ύ 
}

//���¿�ʼ
void Cube_Layer::menuCloseCallback(CCObject* pSender)
{	 
  CCDirector::sharedDirector()->replaceScene(MenuScene::scene());
}

//���
void Cube_Layer::gameCallback(CCObject* pSender){
	chnStrings = CCDictionary::createWithContentsOfFile("strData1.xml");
	goldbg=CCSprite::create("goldbg.png");//��ͣ��屳��
	//goldbg->setScale(5.0f);
	goldbg->setPosition(ccp(240,400));
	this->addChild(goldbg,4);
	CCMenuItemFont::setFontName("Thonburi");
	CCMenuItemFont::setFontSize(40);
	std::string g=((CCString*)chnStrings->objectForKey("goldbg"))->getCString(); 
	CCLabelTTF* g1=CCLabelTTF::create(g.c_str(),"Thonburi", 25);
	g1->setPosition(ccp(190,180));
	goldbg->addChild(g1);

    CCMenuItemImage *py= CCMenuItemImage::create(
            "bt_yes.png",
            "bt_yes_press.png",
            this,
            menu_selector(Cube_Layer::gameqjy));
		py->setScale(0.4);
        py->setPosition(ccp(130,80));

	CCMenuItemImage *pn= CCMenuItemImage::create(
            "bt_no.png",
            "bt_no_press.png",
            this,
            menu_selector(Cube_Layer::menuCloseCallback));
		pn->setScale(0.4);
        pn->setPosition(ccp(280,80));
        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::create(py,pn, NULL);
        pMenu->setPosition(CCPointZero);
		goldbg->addChild(pMenu);

	//CCDirector::sharedDirector()->pause();

}

unsigned long shibie(char pathh[100]) {
	ofstream out("C:/py35/Lib/abcd.txt", ios::trunc);//�ĸĸĸĸĸĸĸĸĸĸĸ�
	if (out.is_open())
	{
		out << pathh;

		out.close();
	}
	STARTUPINFO si;

	PROCESS_INFORMATION pi;


	CCLog(pathh);
	ZeroMemory(&pi, sizeof(pi));

	ZeroMemory(&si, sizeof(si));

	si.cb = sizeof(STARTUPINFO);


	TCHAR cmd[256] = _T("D:/cocos2d-x-2.2.6/projects/Riddless/proj.win32/x64/Release/tensorflow.exe");  //�����ⲿ������

	BOOL working = ::CreateProcessAsUser(NULL, NULL, cmd, NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS | CREATE_NO_WINDOW, NULL, NULL, &si, &pi);  //��������

	if (working == 0)  //�򿪴���

	{

		DWORD error = GetLastError();

		cout << "CreateProcess Error : " << error << endl;

		getchar();

		return 0;

	}


	CCLog("abcdefg");
	//cout << "�򿪳ɹ�" << endl;
	WaitForSingleObject(pi.hProcess, INFINITE);  //�ȴ��������
	//cout << "����" << endl;
	CCLog("over");



	unsigned long Result;

	GetExitCodeProcess(pi.hProcess, &Result);  //�õ����򷵻�ֵ
	//string path = "D:/c++/tensorflow3/x64/Release/tensorflow3.exe";//�ĸĸĸĸĸĸĸĸĸĸĸĸĸĸĸĸĸ�
	//int a = WinExec(path.data(), SW_SHOWMAXIMIZED);
	//int b = system(path.data());
	//return b+"";
	return Result;


}
DWORD WINAPI fun(void* g)
{


	//CCLog("%lu", shibie("C:/Users/Administrator/Desktop/692872.jpg"));
	
	

	return 0;
}


//���YES
void Cube_Layer::gameqjy(CCObject* pSender){
	if(scorex>2)
	{		
		char* a = "abcd";
		::CreateThread(0, 0, fun, a, 0, 0);  // �����̣߳��̵߳���fun����
		ygameqjy();
	}
	else
	{
		ngameqjy();
	}
}

//���㹻���
void Cube_Layer::ygameqjy(){
	//pMenu->setEnabled(false);
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	dacuoceng = CCSprite::create("bg_a.png");
	dacuoceng->setPosition(ccp(240, 400));
	dacuoceng->setScale(0.8f);
	this->addChild(dacuoceng);
	scorex=scorex-2;
	removeChild(score);
	updscore();
	Sleep(3000);

	//creatFlowerButton();
	IdentificationFlowers();

	CCMenuItemImage *qd = CCMenuItemImage::create(
		"flowers/��ť-3.png",
		"flowers/��ť-33.png",
		this,
		menu_selector(Cube_Layer::remove_flowers));
	//qd->setScale(0.4);
	qd->setPosition(ccp(220, 120));
	CCMenu* pMenu = CCMenu::create(qd,NULL);
	pMenu->setPosition(CCPointZero);
	dacuoceng->addChild(pMenu);

	remove_panels();
	this->setTouchEnabled(true);
	level_end();
	//CCDirector::sharedDirector()->pause();

}

void Cube_Layer::remove_flowers(CCObject* pSender){

	this->removeChild(FlowersButton1);
	//this->removeChild(FlowersButton);
	this->removeChild(dacuoceng);
	if (ansx = true) {
		removeChild(ans1);
		
		ansx == false;
	}
}

void Cube_Layer::IdentificationFlowers()
{	
	//CCLog("i love y");
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	//creatFlowerButton();
	if (x1 == 1){
		FlowersButton1 = CCSprite::create("flowers/��˹�� - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
	else if (x1 == 2){
		FlowersButton1 = CCSprite::create("flowers/������ - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
	else if (x1 == 3){
		FlowersButton1 = CCSprite::create("flowers/������ - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
	else if (x1 == 4){
		FlowersButton1 = CCSprite::create("flowers/�������β - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
	else if (x1 == 5){
		FlowersButton1 = CCSprite::create("flowers/����� - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
	else if (x1 == 6){
		FlowersButton1 = CCSprite::create("flowers/���� - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);

	}
	else if (x1 == 7){
		FlowersButton1 = CCSprite::create("flowers/������ - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
	else if (x1 == 8){
		FlowersButton1 = CCSprite::create("flowers/������ - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
	else if (x1 == 9){
		FlowersButton1 = CCSprite::create("flowers/ľ�Ȼ� - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
	else if (x1 == 10){
		FlowersButton1 = CCSprite::create("flowers/����÷ - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
		else if (x1 == 11){
		FlowersButton1 = CCSprite::create("flowers/��˹��_1 - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
	else if (x1 == 12){
		FlowersButton1 = CCSprite::create("flowers/������_1 - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
	else if (x1 == 13){
		FlowersButton1 = CCSprite::create("flowers/������_1 - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
	else if (x1 == 14){
		FlowersButton1 = CCSprite::create("flowers/�������β_1 - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
	else if (x1 == 15){
		FlowersButton1 = CCSprite::create("flowers/�����_1 - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
	else if (x1 == 16){
		FlowersButton1 = CCSprite::create("flowers/����_1 - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);

	}
	else if (x1 == 17){
		FlowersButton1 = CCSprite::create("flowers/������_1 - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
	else if (x1 == 18){
		FlowersButton1 = CCSprite::create("flowers/������_1 - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
	else if (x1 == 19){
		FlowersButton1 = CCSprite::create("flowers/ľ�Ȼ�_1 - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}
	else if (x1 == 20) {
		FlowersButton1 = CCSprite::create("flowers/����÷_1 - ����.jpg");
		FlowersButton1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
		this->addChild(FlowersButton1);
	}

	else{



	//ansj= ((CCString*)chnStrings->objectForKey(ans))->getCString();
	ans1 = CCLabelTTF::create(ans.c_str(), "Thonburi", 45);
	ans1->setColor(ccc3(255, 255, 255));
	ans1->setPosition(ccp(size.width / 2, size.height / 2 + 20));
	this->addChild(ans1, 1);
	ansx == true;
	}
}


//û���㹻���
void Cube_Layer::ngameqjy(){
	//	pMenu->setEnabled(false);
	chnStrings = CCDictionary::createWithContentsOfFile("strData1.xml");
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	pausebg=CCSprite::create("goldbg.png");//��ͣ��屳��
	pausebg->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(pausebg,4);

	std::string nogold=((CCString*)chnStrings->objectForKey("nogold"))->getCString(); 
	CCLabelTTF* nogold1=CCLabelTTF::create(nogold.c_str(),"Thonburi", 20);
	nogold1->setPosition(ccp(190,180));
	pausebg->addChild(nogold1);
	CCMenuItemImage *pn= CCMenuItemImage::create(
            "bt_no.png",
            "bt_no_press.png",
            this,
            menu_selector(Cube_Layer::menuCloseCallback));
		pn->setScale(0.4);
        pn->setPosition(ccp(190,90));
        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::create(pn, NULL);
        pMenu->setPosition(CCPointZero);
		pausebg->addChild(pMenu);

	//CCDirector::sharedDirector()->pause();

}