#ifndef XIAKE_CCSPRITEFRAMECACHEXMQXZ_H
#define XIAKE_CCSPRITEFRAMECACHEXMQXZ_H

#include "2d/CCSpriteFrameCache.h"

NS_CC_BEGIN
struct SpriteFrameValue{
	bool							m_bInit;
	std::string						m_strTextureName;
	cocos2d::Vector<SpriteFrame*>	m_vtFrame;
	SpriteFrameValue(){
		m_bInit = false;
	}
	//判断是否已经初始化
	bool IsInit(){ return m_bInit; }
	void Init(std::string& strTextureName, cocos2d::Vector<SpriteFrame*>& vtFrame){
		m_bInit = true;
		m_strTextureName = strTextureName;
		m_vtFrame = vtFrame;
	}
};

class SpriteFrameCacheAlwaysCachePList{
public:
	SpriteFrameCacheAlwaysCachePList();
	virtual ~SpriteFrameCacheAlwaysCachePList();

	//保存这些节点
	SpriteFrameValue* GetSpriteFrameByListName(const std::string& strList);
protected:
	std::map<std::string, SpriteFrameValue*>	m_mapCache;
};

class CC_DLL SpriteFrameCache_XiaKe : public cocos2d::SpriteFrameCache
{
public:
    SpriteFrameCache_XiaKe();
    virtual ~SpriteFrameCache_XiaKe();

    static SpriteFrameCache_XiaKe* getInstanceXiaKe(){
        return (SpriteFrameCache_XiaKe*)cocos2d::SpriteFrameCache::getInstance();
    }

    Texture2D* addSpriteFramesWithPlistFile(const std::string& plist, bool bNoRelease);
protected:
    //用于永久保存
    SpriteFrameCacheAlwaysCachePList	m_alwaysCache;
};

NS_CC_END

#endif