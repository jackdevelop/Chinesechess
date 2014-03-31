#include "MainMenu.h"
#include "ChessRule.h"
#include <math.h>

USING_NS_CC;

CCScene* CCMainMenu::scene()
{
	CCScene* pScene = CCScene::create();
	CCMainMenu* pLayer = CCMainMenu::create();
	pScene->addChild(pLayer, 3);
	return pScene;
}

bool CCMainMenu::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	s = CCDirector::sharedDirector()->getWinSize();

	m_pBKG = CCSprite::spriteWithFile("background.png");
	CCRect r = m_pBKG->getTextureRect();
	m_pBKG->setAnchorPoint(CCPointZero);
	m_pBKG->setPosition(ccp(0, 0));
	m_pBKG->setScaleX(s.width/r.size.width*0.667f);
	m_pBKG->setScaleY(s.height/r.size.height);
	this->addChild(m_pBKG, -2);
	
	m_pFocus = CCSprite::spriteWithFile("selected.png");
	r = m_pFocus->getTextureRect();
	m_pFocus->setScaleX(0.667f);
	m_pFocus->setScaleY(0.6f);
	m_pFocus->setVisible(false);
	this->addChild(m_pFocus, 1);

	m_fPositionX = s.width - r.size.width*0.667f;
	m_fPositionY = s.height - r.size.height*0.6f;

	CCMenuItemImage* pItem = CCMenuItemImage::create("new.jpg", "new.jpg", this, menu_selector(CCMainMenu::menuCallBack));
	pItem->setPosition(ccp(m_fPositionX - s.width/6, m_fPositionY - s.height/8));
	pItem->setAnchorPoint(CCPointZero);
	pItem->setScaleX(0.667f);
	pItem->setScaleY(0.6f);
	
	CCMenu* pMenu = CCMenu::create(pItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	pItem = CCMenuItemImage::create("regret.jpg", "regret.jpg", this, menu_selector(CCMainMenu::menuRegret));
	pItem->setPosition(ccp(m_fPositionX - s.width/6, m_fPositionY - s.height/8*2));
	pItem->setAnchorPoint(CCPointZero);
	pItem->setScaleX(0.667f);
	pItem->setScaleY(0.6f);

	pMenu = CCMenu::menuWithItems(pItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	pItem = CCMenuItemImage::create("start.jpg", "start.jpg", this, menu_selector(CCMainMenu::menuStart));
	pItem->setPosition(ccp(m_fPositionX - s.width/6, m_fPositionY - s.height/8*3));
	pItem->setAnchorPoint(CCPointZero);
	pItem->setScaleX(0.667f);
	pItem->setScaleY(0.6f);

	pMenu = CCMenu::menuWithItems(pItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	pItem = CCMenuItemImage::create("difficulty.jpg", "difficulty.jpg", this, menu_selector(CCMainMenu::menuHardChoose));
	pItem->setPosition(ccp(m_fPositionX - s.width/6, m_fPositionY - s.height/8*4));
	pItem->setAnchorPoint(CCPointZero);
	pItem->setScaleX(0.667f);
	pItem->setScaleY(0.6f);

	pMenu = CCMenu::menuWithItems(pItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);

	m_pOpenVolice = CCMenuItemImage::create("openVolice.png", "openVolice.png", this, menu_selector(CCMainMenu::menuSoundChoose));
	CCSize r2 = m_pOpenVolice->getContentSize();
	m_pOpenVolice->setPosition(ccp(m_fPositionX - s.width/6 + r.size.width/2 - r2.width/6, m_fPositionY - s.height/8*5));
	m_pOpenVolice->setAnchorPoint(CCPointZero);
	m_pOpenVolice->setScaleX(0.667f);
	m_pOpenVolice->setScaleY(0.6f);
	pMenu = CCMenu::menuWithItems(m_pOpenVolice, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1, 100);

	m_pCloseVolice = CCMenuItemImage::create("closeVolice.png", "closeVolice.png", this, menu_selector(CCMainMenu::menuSoundChoose));
	m_pCloseVolice->setPosition(ccp(m_fPositionX - s.width/6 + r.size.width/2 - r2.width/6, m_fPositionY - s.height/8*5));
	m_pCloseVolice->setAnchorPoint(CCPointZero);
	m_pCloseVolice->setScaleX(0.667f);
	m_pCloseVolice->setScaleY(0.6f);
	pMenu = CCMenu::menuWithItems(m_pCloseVolice, NULL);
	pMenu->setPosition(CCPointZero);
	m_pCloseVolice->setVisible(false);
	this->addChild(pMenu, 1, 101);

	// coordinate info
	this->initCoordinate();
	// show time
	this->initTimeShow();
	// show chess
	this->initListImage();
	
	this->setTouchEnabled(true);

	this->schedule(schedule_selector(CCMainMenu::updateTime), 1.0f);

	//str = "../process.txt";

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			g_cur_map[i][j] = g_chess_map[i][j];
		}
	}
	//this->print();

	m_enGameStatus		= GAME_MENU;
	m_enCurRole			= ROLE_RED;
	m_bVolice			= true;
	m_pCurChess			= NULL;
	m_bSelect			= false;
	m_bCollectCorrect	= true;
	m_pTargetChess		= NULL;
	m_nContinuous		= 3;
	m_nCur				= 0;
	m_enCurChessType	= CHESS_NONE;
	m_enTarChessType    = CHESS_NONE;
	m_nWin				= -1;
	m_vecSprite.reserve(10);	
	return true;
}

void CCMainMenu::setPos(CCSprite* pSprite, int x, int y)
{
	pSprite->setAnchorPoint(CCPointZero);
	pSprite->setScaleX(0.667f);
	pSprite->setScaleY(0.6f);
	pSprite->setPosition(ccp(x, y));
}

void CCMainMenu::setPosDigit(CCSprite* pSprite, int x, int y)
{
	pSprite->setAnchorPoint(CCPointZero);
	pSprite->setScaleX(0.2f);
	pSprite->setScaleY(0.2f);
	pSprite->setPosition(ccp(x, y));
}

void CCMainMenu::menuCallBack(CCObject* pSender)
{
	m_enGameStatus		= GAME_MENU;
	m_enCurRole			= ROLE_RED;
	m_nChessTime		= 600;
	m_pCurChess			= NULL;
	m_bSelect			= false;
	m_bCollectCorrect	= true;
	m_pTargetChess		= NULL;
	m_nContinuous		= 3;
	m_nCur				= 0;
	m_nWin				= -1;
	m_pFocus->setVisible(false);
	this->initChessPosition();
	this->freeAll();
	this->setNumberSprite(m_nChessTime);
	this->unschedule(schedule_selector(CCMainMenu::updateFocus));
}

void CCMainMenu::menuRegret(CCObject* pSender)
{
	this->freeOne(); 
	this->freeOne();
	if(m_pCurChess)
	{
		m_pFocus->setPosition(m_pCurChess->getPosition());
		m_pFocus->setVisible(true);
		m_bSelect		= true;
		m_pTargetChess	= NULL;
	}
}

void CCMainMenu::menuStart(CCObject* pSender)
{
	if(m_enGameStatus != GAME_MENU)
	{
		return;
	}
	this->schedule(schedule_selector(CCMainMenu::updateFocus), 0.5f);
	m_enGameStatus  = GAME_RUNNING;
	m_nChessTime	= 600;
	this->setNumberSprite(m_nChessTime);
}

void CCMainMenu::menuHardChoose(CCObject* pSender)
{

}

void CCMainMenu::menuSoundChoose(CCObject* pSender)
{
	if(m_bVolice)
	{
		m_pOpenVolice->setVisible(false);
		m_pCloseVolice->setVisible(true);
		m_bVolice = false;
	}
	else
	{
		m_pOpenVolice->setVisible(true);
		m_pCloseVolice->setVisible(false);
		m_bVolice = true;
	}
}

void CCMainMenu::updateTime(float dt)
{
	if (GAME_RUNNING == m_enGameStatus)
	{
		--m_nChessTime;
		if(m_nChessTime < 0)
		{
			m_nChessTime = 0;
		}
		else
		{
			this->setNumberSprite(m_nChessTime);
		}
	}
}

void CCMainMenu::updateFocus(float dt)
{
	// alternate display
	static int i = 0;
	if(m_bSelect && m_pCurChess)
	{
		if(i == 0)
		{
			i = 1;
			m_pFocus->setVisible(false);
		}
		else
		{
			i = 0;
			m_pFocus->setVisible(true);
		}
	}
}

void CCMainMenu::ccTouchesEnded(CCSet* pTouches, CCEvent* pEvent)
{
	if(m_enGameStatus != GAME_RUNNING)
	{
		return;
	}
	CCSetIterator it = pTouches->begin();
	CCTouch* pTouch = (CCTouch*)(*it);
	CCPoint touchPoint = pTouch->getLocationInView();
	touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint);
	this->dealWithChess(touchPoint.x, touchPoint.y);
}

// core
void CCMainMenu::dealWithChess(float x, float y)
{
	// judge boundary
	if (x < 24 || x > 294 || y < 14 || y > 312)
	{
		return;
	}

	CCSprite* pSprite;
	pSprite = this->getChessByCoord(x, y);
	if(!this->getChessByCoord(x, y, 1)) 
	{
		// can not find coordinate
		return;
	}
	int x0 = static_cast<int>(x);
	int y0 = static_cast<int>(y);
	if (pSprite)
	{
		if(m_bSelect)
		{
			m_pTargetChess = pSprite;	
		}
		else
		{
			if (!m_nCur && m_enCurChessType < CHESS_BORDER)
			{
				return;
			}
			else if(m_nCur && m_enCurChessType > CHESS_BORDER)
			{
				return;
			}

			m_pFocus->setPosition(pSprite->getPosition());
			m_pFocus->setVisible(true);
			m_pCurChess = pSprite;
			ox = x0;
			oy = y0;
			m_bSelect = false;
		}
	}

	if (m_bSelect)
	{	
		if(!this->judgeAction(x0, y0))
		{
			this->clean();
			return;
		}
		if((m_enCurChessType < CHESS_BORDER && m_enTarChessType < CHESS_BORDER && m_enTarChessType > CHESS_NONE) || 
			(m_enCurChessType > CHESS_BORDER && m_enTarChessType > CHESS_BORDER))
		{
			this->clean();
			return;
		}
		if(m_pTargetChess && m_pTargetChess != m_pCurChess)
		{
			m_pTargetChess->setVisible(false);
			this->collectInfo(m_pTargetChess);
		}
		this->collectInfo(m_pCurChess);
		CCPoint p = g_chess_coord[x0][y0];
		m_pCurChess->setPosition(p);
		m_pFocus->setPosition(p);
		g_cur_map[x0][y0] = g_cur_map[ox][oy];
		g_cur_map[ox][oy] = 0;
		//this->print();
		m_nCur = m_nCur == 0 ? 1 : 0;
		this->clean();
		this->judgeWin();
	}
	else
	{
		m_bSelect = true;
	}
}

void CCMainMenu::collectInfo(CCSprite* pSprite)
{
	if(pSprite == NULL)
	{
		m_bCollectCorrect = false;
		return;
	}
	SPRITE_INFO stSpriteInfo;
	stSpriteInfo.pSprite = pSprite;
	stSpriteInfo.x		 = pSprite->getPosition().x;
	stSpriteInfo.y		 = pSprite->getPosition().y;
	m_vecSprite.push_back(stSpriteInfo);
}

bool CCMainMenu::judgeAction(int tx, int ty)
{
	if(!m_pCurChess)
	{
		return false;
	}

	/*bool ret = false;
	for (int i = 0; i < 10; ++i)
	{
		if(ret)
		{
			break;
		}
		for (int j = 0; j < 10; ++j)
		{
			if(g_chess_coord[i][j].x == x && g_chess_coord[i][j].y == y)
			{
				ret = true;
				break;
			}
		}
	}
	if (!ret)
	{
		return false;
	}*/
	
	return judge(m_enCurChessType, ox, oy, tx, ty);
}

void CCMainMenu::initTimeShow()
{
	m_nChessTime = 600;
	this->setNumberSprite(m_nChessTime);
}

void CCMainMenu::initCoordinate()
{
	/*std::string str = "../coordinate.txt";
	std::ofstream f_output;
	f_output.open(str.c_str(), std::ios::app);*/
	float xSpan  = 48.0f*0.667f;
	float ySpan  = 32.0f*0.6f;
	float xStart = 1;
	float yStart = xSpan;
	for (int i = 0, x = 9; i < 10; ++i, --x)
	{
		for (int j = 0, y = 1; j < 9; ++j, ++y)
		{
			g_chess_coord[i][j] = ccp(xStart + xSpan*y, yStart*x + ySpan);
			/*f_output<< "[" << i << "][" << j <<"]: (" << xStart + xSpan*y << ", " << yStart*x + ySpan << ")" << " ";
			if(j == 4 || j == 8)
			{
				f_output<<std::endl;
			}*/
		}
		/*f_output<<std::endl;*/
	}
	/*f_output.close();*/
}

void CCMainMenu::initListImage()
{
	// red
	m_pChess[1][0] = this->getListSprite(CHESS_RK);
	this->addChild(m_pChess[1][0], 0);

	m_pChess[1][1] = this->getListSprite(CHESS_RA);
	this->addChild(m_pChess[1][1], 0);

	m_pChess[1][2] = this->getListSprite(CHESS_RA);
	this->addChild(m_pChess[1][2], 0);

	m_pChess[1][3] = this->getListSprite(CHESS_RB);
	this->addChild(m_pChess[1][3], 0);

	m_pChess[1][4] = this->getListSprite(CHESS_RB);
	this->addChild(m_pChess[1][4], 0);

	m_pChess[1][5] = this->getListSprite(CHESS_RN);
	this->addChild(m_pChess[1][5], 0);

	m_pChess[1][6] = this->getListSprite(CHESS_RN);
	this->addChild(m_pChess[1][6], 0);

	m_pChess[1][7] = this->getListSprite(CHESS_RR);
	this->addChild(m_pChess[1][7], 0);

	m_pChess[1][8] = this->getListSprite(CHESS_RR);
	this->addChild(m_pChess[1][8], 0);

	m_pChess[1][9] = this->getListSprite(CHESS_RC);
	this->addChild(m_pChess[1][9], 0);
	
	m_pChess[1][10] = this->getListSprite(CHESS_RC);
	this->addChild(m_pChess[1][10], 0);

	m_pChess[1][11] = this->getListSprite(CHESS_RP);
	this->addChild(m_pChess[1][11], 0);

	m_pChess[1][12] = this->getListSprite(CHESS_RP);
	this->addChild(m_pChess[1][12], 0);

	m_pChess[1][13] = this->getListSprite(CHESS_RP);
	this->addChild(m_pChess[1][13], 0);

	m_pChess[1][14] = this->getListSprite(CHESS_RP);
	this->addChild(m_pChess[1][14], 0);

	m_pChess[1][15] = this->getListSprite(CHESS_RP);
	this->addChild(m_pChess[1][15], 0);

	//black
	m_pChess[0][0] = this->getListSprite(CHESS_BK);
	this->addChild(m_pChess[0][0], 0);

	m_pChess[0][1] = this->getListSprite(CHESS_BA);
	this->addChild(m_pChess[0][1], 0);

	m_pChess[0][2] = this->getListSprite(CHESS_BA);
	this->addChild(m_pChess[0][2], 0);

	m_pChess[0][3] = this->getListSprite(CHESS_BB);
	this->addChild(m_pChess[0][3], 0);

	m_pChess[0][4] = this->getListSprite(CHESS_BB);
	this->addChild(m_pChess[0][4], 0);

	m_pChess[0][5] = this->getListSprite(CHESS_BN);
	this->addChild(m_pChess[0][5], 0);

	m_pChess[0][6] = this->getListSprite(CHESS_BN);
	this->addChild(m_pChess[0][6], 0);

	m_pChess[0][7] = this->getListSprite(CHESS_BR);
	this->addChild(m_pChess[0][7], 0);

	m_pChess[0][8] = this->getListSprite(CHESS_BR);
	this->addChild(m_pChess[0][8], 0);

	m_pChess[0][9] = this->getListSprite(CHESS_BC);
	this->addChild(m_pChess[0][9], 0);

	m_pChess[0][10] = this->getListSprite(CHESS_BC);
	this->addChild(m_pChess[0][10], 0);

	m_pChess[0][11] = this->getListSprite(CHESS_BP);
	this->addChild(m_pChess[0][11], 0);

	m_pChess[0][12] = this->getListSprite(CHESS_BP);
	this->addChild(m_pChess[0][12], 0);

	m_pChess[0][13] = this->getListSprite(CHESS_BP);
	this->addChild(m_pChess[0][13], 0);

	m_pChess[0][14] = this->getListSprite(CHESS_BP);
	this->addChild(m_pChess[0][14], 0);

	m_pChess[0][15] = this->getListSprite(CHESS_BP);
	this->addChild(m_pChess[0][15], 0);

	this->initChessPosition();
}

void CCMainMenu::initChessPosition()
{
	m_pChess[1][0]->setPosition(g_chess_coord[9][4]);
	m_pChess[1][1]->setPosition(g_chess_coord[9][3]);
	m_pChess[1][2]->setPosition(g_chess_coord[9][5]);
	m_pChess[1][3]->setPosition(g_chess_coord[9][2]);
	m_pChess[1][4]->setPosition(g_chess_coord[9][6]);
	m_pChess[1][5]->setPosition(g_chess_coord[9][1]);
	m_pChess[1][6]->setPosition(g_chess_coord[9][7]);
	m_pChess[1][7]->setPosition(g_chess_coord[9][0]);
	m_pChess[1][8]->setPosition(g_chess_coord[9][8]);
	m_pChess[1][9]->setPosition(g_chess_coord[7][1]);
	m_pChess[1][10]->setPosition(g_chess_coord[7][7]);
	m_pChess[1][11]->setPosition(g_chess_coord[6][0]);
	m_pChess[1][12]->setPosition(g_chess_coord[6][2]);
	m_pChess[1][13]->setPosition(g_chess_coord[6][4]);
	m_pChess[1][14]->setPosition(g_chess_coord[6][6]);
	m_pChess[1][15]->setPosition(g_chess_coord[6][8]);
	//black
	m_pChess[0][0]->setPosition(g_chess_coord[0][4]);
	m_pChess[0][1]->setPosition(g_chess_coord[0][3]);
	m_pChess[0][2]->setPosition(g_chess_coord[0][5]);
	m_pChess[0][3]->setPosition(g_chess_coord[0][2]);
	m_pChess[0][4]->setPosition(g_chess_coord[0][6]);
	m_pChess[0][5]->setPosition(g_chess_coord[0][1]);
	m_pChess[0][6]->setPosition(g_chess_coord[0][7]);
	m_pChess[0][7]->setPosition(g_chess_coord[0][0]);
	m_pChess[0][8]->setPosition(g_chess_coord[0][8]);
	m_pChess[0][9]->setPosition(g_chess_coord[2][1]);
	m_pChess[0][10]->setPosition(g_chess_coord[2][7]);
	m_pChess[0][11]->setPosition(g_chess_coord[3][0]);
	m_pChess[0][12]->setPosition(g_chess_coord[3][2]);
	m_pChess[0][13]->setPosition(g_chess_coord[3][4]);
	m_pChess[0][14]->setPosition(g_chess_coord[3][6]);
	m_pChess[0][15]->setPosition(g_chess_coord[3][8]);
}

void CCMainMenu::setNumberSprite(int nChessTime)
{
	int min = nChessTime/60;
	int sec = nChessTime%60;
	for (int i = 50; i <= 53; ++i)
	{
		this->removeChildByTag(i, true);
	}
	m_pMinute[0] = this->getNumberSprite(min/10);
	m_pMinute[1] = this->getNumberSprite(min%10);
	m_pSecond[0] = this->getNumberSprite(sec/10);
	m_pSecond[1] = this->getNumberSprite(sec%10);

	this->setPosDigit(m_pMinute[0], m_fPositionX - s.width/6 - 40, m_fPositionY - s.height/8*7);
	this->setPosDigit(m_pMinute[1], m_fPositionX - s.width/6 - 5, m_fPositionY - s.height/8*7);
	this->setPosDigit(m_pSecond[0], m_fPositionX - s.width/6 + 40, m_fPositionY - s.height/8*7);
	this->setPosDigit(m_pSecond[1], m_fPositionX - s.width/6 + 75, m_fPositionY - s.height/8*7);

	this->addChild(m_pMinute[0], 2, 50);
	this->addChild(m_pMinute[1], 2, 51);
	this->addChild(m_pSecond[0], 2, 52);
	this->addChild(m_pSecond[1], 2, 53);
}

CCSprite* CCMainMenu::getNumberSprite(int nNum)
{
	char str[20];
	sprintf(str, "d%d.png", nNum);
	return CCSprite::spriteWithFile(str);
}

CCSprite* CCMainMenu::getListSprite(CHESS_TYPE nType)
{
	CCSprite* pSprite;
	switch(nType)
	{
	case CHESS_RK:
		pSprite = CCSprite::spriteWithFile("rk.png");
		break;
	case CHESS_RA:
		pSprite = CCSprite::spriteWithFile("ra.png");
		break;
	case CHESS_RB: 
		pSprite = CCSprite::spriteWithFile("rb.png");
		break;
	case CHESS_RN: 
		pSprite = CCSprite::spriteWithFile("rn.png");
		break;
	case CHESS_RR: 
		pSprite = CCSprite::spriteWithFile("rr.png");
		break;
	case CHESS_RC:
		pSprite = CCSprite::spriteWithFile("rc.png");
		break;
	case CHESS_RP: 
		pSprite = CCSprite::spriteWithFile("rp.png");
		break;
	case CHESS_BK:
		pSprite = CCSprite::spriteWithFile("bk.png");
		break;
	case CHESS_BA:
		pSprite = CCSprite::spriteWithFile("ba.png");
		break;
	case CHESS_BB: 
		pSprite = CCSprite::spriteWithFile("bb.png");
		break;
	case CHESS_BN: 
		pSprite = CCSprite::spriteWithFile("bn.png");
		break;
	case CHESS_BR: 
		pSprite = CCSprite::spriteWithFile("br.png");
		break;
	case CHESS_BC:
		pSprite = CCSprite::spriteWithFile("bc.png");
		break;
	case CHESS_BP:
		pSprite = CCSprite::spriteWithFile("bp.png");
		break;
	}

	pSprite->setScaleX(0.5f);
	pSprite->setScaleY(0.5f);
	return pSprite;
}

CCSprite* CCMainMenu::getChessByCoord(float x, float y)
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 16; ++j)
		{
			if(abs(m_pChess[i][j]->getPosition().x - x) < 5.6 && 
				abs(m_pChess[i][j]->getPosition().y - y) < 5.6 &&
				m_pChess[i][j]->isVisible())
			{
				if (!m_pCurChess)
				{
					m_enCurChessType = g_chess[i][j];
				}
				else if (m_pCurChess && !m_pTargetChess)
				{
					m_enTarChessType = g_chess[i][j];
				}
				else
				{
					return NULL;
				}
				return m_pChess[i][j];
			}
		}
	}
	return NULL;
}

bool CCMainMenu::getChessByCoord(float& x, float& y, short dt)
{
	// Correct coordinate parameter
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if(i == 8 && j == 0)
			{
				int k = 1;
			}
			if (abs(g_chess_coord[i][j].x - x) < 5.6 &&
				 abs(g_chess_coord[i][j].y - y) < 5.6)
			{	
				x = i;
				y = j;
				return true;
			}
		}
	}
	return false;
}

void CCMainMenu::freeOne()
{	
	if(m_vecSprite.empty())
	{
		return;
	}
	//VEC_SPRITE_IT it = m_vecSprite.back();
	SPRITE_INFO pInfo = m_vecSprite.back();
	if(pInfo.pSprite)
	{
		pInfo.pSprite->setPosition(ccp(pInfo.x, pInfo.y));
		pInfo.pSprite->setVisible(true);
	}
	m_vecSprite.pop_back();
}

void CCMainMenu::freeAll()
{
	VEC_SPRITE_IT it = m_vecSprite.begin();
	for (; it != m_vecSprite.end(); ++it)
	{
		it->pSprite->setVisible(true);
	}
	m_vecSprite.clear();
}

CHESS_TYPE CCMainMenu::getChessType(int i, int j)
{

	if(i < 0 || i > 1 || j < 0 || j > 15)
	{
		return CHESS_NONE;
	}
	return g_chess[i][j];
}

void CCMainMenu::clean()
{
	m_pCurChess		= NULL;
	m_enCurChessType = CHESS_NONE;
	m_pTargetChess	= NULL;	
	m_enTarChessType = CHESS_NONE;
	m_bSelect = false;
	m_pFocus->setVisible(false);
}

//void CCMainMenu::print()
//{
//	f_output.open(str.c_str(), std::ios::app);
//
//	for (int i = 0, x = 9; i < 10; ++i, --x)
//	{
//		for (int j = 0, y = 1; j < 9; ++j, ++y)
//		{
//			f_output<< std::showpoint <<g_cur_map[i][j] << " ";
//		}
//		f_output<<std::endl;
//	}
//	f_output<<std::endl;
//	f_output.close();
//}
bool CCMainMenu::judgeWin()
{
	bool ret = true;
	// need simplification
	float nRedXf		= m_pChess[1][0]->getPosition().x;
	float nBlackXf		= m_pChess[0][0]->getPosition().x;
	float nRedYf		= m_pChess[1][0]->getPosition().y;
	float nBlackYf		= m_pChess[0][0]->getPosition().y;
	this->getChessByCoord(nRedXf, nRedYf, 1);
	this->getChessByCoord(nBlackXf, nBlackYf, 1);
	int nRedX			= static_cast<int>(nRedXf);	
	int nBlackX			= static_cast<int>(nBlackXf);	
	int nRedY			= static_cast<int>(nRedYf);	
	int nBlackY			= static_cast<int>(nBlackYf);	
	
	if (nRedY == nBlackY)
	{
		for (int i = nBlackX + 1; 
			i < nRedX; ++i)
		{
			if(g_cur_map[i][nRedY] != 0)
			{
				ret = false;
				break;
			}
		}
		if (ret)
		{
			m_enGameStatus = GAME_OVER;
			m_nWin = m_nCur;
		}
	}
	

	if (!m_pChess[0][0]->isVisible())
	{
		m_enGameStatus = GAME_OVER;
		m_nWin = 0;
	}
	if (!m_pChess[1][0]->isVisible())
	{
		m_enGameStatus = GAME_OVER;
		m_nWin = 1;
	}

	if (m_enGameStatus == GAME_OVER)
	{
		this->menuCallBack(m_pCurChess);
	}

	return false;
}