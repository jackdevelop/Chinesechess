#ifndef __CHINESE_CHESS_MAIN_MENU_H__
#define __CHINESE_CHESS_MAIN_MENU_H__

#include "cocos2d.h"
#include "ChessDefine.h"
#include <vector>
//#include <fstream>
//#include <string>

USING_NS_CC;

typedef struct
{
	CCSprite* pSprite;
	float x; // coordinate
	float y;
}SPRITE_INFO;

typedef std::vector<SPRITE_INFO> VEC_SPRITE;
typedef VEC_SPRITE::iterator VEC_SPRITE_IT;

class CCMainMenu : public CCLayer
{
public:
	static CCScene* scene();
	virtual bool init();
	CREATE_FUNC(CCMainMenu);
	virtual void ccTouchesEnded(CCSet* pTouches, CCEvent* pEvent);

private:
	void		setPos(CCSprite* pSprite, int x, int y);
	void		setPosDigit(CCSprite* pSprite, int x, int y);

	void		menuCallBack(CCObject* pSender);
	void		menuRegret(CCObject* pSender);
	void		menuStart(CCObject* pSender);
	void		menuHardChoose(CCObject* pSender);
	void		menuSoundChoose(CCObject* pSender);

	void		updateTime(float dt);
	void		updateFocus(float dt);

	void		initCoordinate();
	void		initListImage();
	void		initTimeShow();
	void		initChessPosition();
	
	CCSprite*	getNumberSprite(int nNum);
	void		setNumberSprite(int nChessTime);

	CCSprite*	getListSprite(CHESS_TYPE nType);
	CHESS_TYPE  getChessType(int i, int j);
	void		dealWithChess(float x, float y);
	CCSprite*	getChessByCoord(float x, float y);
	bool		getChessByCoord(float& x, float& y, short dt);
	void		collectInfo(CCSprite* pSprite);
	bool		judgeAction(int tx, int ty);
	void		freeOne();
	void		freeAll();
	bool		judgeContinuous();
	void		clean();
	bool		judgeWin();
	//void		print();

private:
	CCSprite*	m_pFocus;
	CCSprite*	m_pBKG;
	CCSprite*	m_pMinute[2];
	CCSprite*	m_pSecond[2];
	CCSprite*	m_pCurChess;
	CCSprite*   m_pTargetChess;
	CHESS_TYPE  m_enCurChessType;
	CHESS_TYPE  m_enTarChessType;
	CCSprite*	m_pChess[2][16];
	CCMenuItemImage* m_pOpenVolice;
	CCMenuItemImage* m_pCloseVolice;

	//std::ofstream f_output;
	//std::string str;

	float		m_fPositionX;
	float		m_fPositionY;
	int			m_nChessTime;
	CCSize		s;
	bool		m_bSelect;		 // has a chess be selected? if true, cannot be change
	bool		m_bVolice;
	bool		m_bCollectCorrect;
	int			ox, oy;			 // the original coordinate of the current chess
	int			m_nContinuous;   // the max numbers to attact opponent's boss
	int			m_nCur;			 // 0:red; 1:black
	int         m_nWin;			 // 0:red; 1:black
	enum GAME_STATUS
	{
		GAME_MENU,
		GAME_RUNNING,
		GAME_WIN,
		GAME_OVER,
	};
	GAME_STATUS m_enGameStatus;
	enum GAME_ROLE
	{
		ROLE_RED,
		ROLE_BLACK,
	};
	GAME_ROLE m_enCurRole;	
	VEC_SPRITE m_vecSprite;
};

#endif // __CHINESE_CHESS_MAIN_MENU_H__