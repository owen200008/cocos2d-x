/********************************************************************
    created  :    2014/05/06   16:37
    Filename :    AnimatePacker3.h
    author   :    LT.GAME
	desc     :    it's for cocos2d-x 3.0 
*********************************************************************/
#ifndef _ANIMATEPACKER3_H__
#define _ANIMATEPACKER3_H__

#include "cocos2d.h"
#include "tinyxml2/tinyxml2.h"
using namespace cocos2d;
using namespace std;

class CC_DLL AnimatePacker3
{
public:
	static AnimatePacker3* GetInstance();

	void loadAnimations(const char *path);

	cocos2d::Animate* getAnimate(const char *name);
 };


#endif