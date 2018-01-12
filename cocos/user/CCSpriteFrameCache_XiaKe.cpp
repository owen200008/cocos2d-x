#include "CCSpriteFrameCache_XiaKe.h"
#include "2d/CCSprite.h"
#include "2d/CCAutoPolygon.h"
#include "platform/CCFileUtils.h"
#include "base/CCNS.h"
#include "base/ccMacros.h"
#include "base/ccUTF8.h"
#include "base/CCDirector.h"
#include "renderer/CCTexture2D.h"
#include "renderer/CCTextureCache.h"
#include "base/CCNinePatchImageParser.h"

using namespace std;

NS_CC_BEGIN
SpriteFrameCacheAlwaysCachePList::SpriteFrameCacheAlwaysCachePList(){
}

SpriteFrameCacheAlwaysCachePList::~SpriteFrameCacheAlwaysCachePList(){
	for (auto cacheData : m_mapCache){
		delete cacheData.second;
	}
	m_mapCache.clear();
}
//保存这些节点
SpriteFrameValue* SpriteFrameCacheAlwaysCachePList::GetSpriteFrameByListName(const std::string& strList){
	std::map<std::string, SpriteFrameValue*>::iterator iter = m_mapCache.find(strList);
	if (iter == m_mapCache.end()){
		SpriteFrameValue* pNewData = new SpriteFrameValue();
		m_mapCache[strList] = pNewData;
		return pNewData;
	}
	return iter->second;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
SpriteFrameCache_XiaKe::SpriteFrameCache_XiaKe()
{

}

SpriteFrameCache_XiaKe::~SpriteFrameCache_XiaKe()
{

}

Texture2D* SpriteFrameCache_XiaKe::addSpriteFramesWithPlistFile(const std::string& plist, bool bNoRelease){
	SpriteFrameValue* pCacheFrameValue = m_alwaysCache.GetSpriteFrameByListName(plist);
	CCASSERT(plist.size()>0, "plist filename should not be nullptr");

	std::string fullPath = FileUtils::getInstance()->fullPathForFilename(plist);
	if (fullPath.size() == 0){
		// return if plist file doesn't exist
		CCLOG("cocos2d: SpriteFrameCache: can not find %s", plist.c_str());
		return NULL;
	}

	if (_loadedFileNames->find(plist) == _loadedFileNames->end()){
		ValueMap dict = FileUtils::getInstance()->getValueMapFromFile(fullPath);

		string texturePath("");

		if (dict.find("metadata") != dict.end()){
			ValueMap& metadataDict = dict["metadata"].asValueMap();
			// try to read  texture file name from meta data
			texturePath = metadataDict["textureFileName"].asString();
		}

		if (!texturePath.empty()){
			// build texture path relative to plist file
			texturePath = FileUtils::getInstance()->fullPathFromRelativeFile(texturePath.c_str(), plist);
		}
		else{
			// build texture path by replacing file extension
			texturePath = plist;

			// remove .xxx
			size_t startPos = texturePath.find_last_of(".");
			texturePath = texturePath.erase(startPos);

			// append .png
			texturePath = texturePath.append(".png");

			CCLOG("cocos2d: SpriteFrameCache: Trying to use file %s as texture", texturePath.c_str());
		}

		Texture2D *texture = Director::getInstance()->getTextureCache()->addImage(texturePath.c_str());

		if (texture){
			addSpriteFramesWithDictionary(dict, texture);
			_loadedFileNames->insert(plist);

			if (!pCacheFrameValue->IsInit()){
				cocos2d::Vector<SpriteFrame*> vtFrame;
				if (bNoRelease){
					ValueMap& framesDict = dict["frames"].asValueMap();
					for (auto iter = framesDict.begin(); iter != framesDict.end(); ++iter)
					{
						std::string spriteFrameName = iter->first;
						SpriteFrame* pSpriteFrame = getSpriteFrameByName(spriteFrameName);
						if (pSpriteFrame){
							vtFrame.pushBack(pSpriteFrame);
						}
						else{
							assert(0);
						}
					}
				}
				pCacheFrameValue->Init(texturePath, vtFrame);
			}
			return texture;
		}
		else{
			CCLOG("cocos2d: SpriteFrameCache: Couldn't load texture");
		}
	}
	else{
		if (pCacheFrameValue->IsInit()){
			return Director::getInstance()->getTextureCache()->addImage(pCacheFrameValue->m_strTextureName.c_str());
		}
		else{
			assert(0);
		}
	}
	return NULL;
}

NS_CC_END