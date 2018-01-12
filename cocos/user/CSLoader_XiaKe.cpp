#include "CSLoader_XiaKe.h"
#include "platform/CCFileUtils.h"

CSLoader_XiaKe::CSLoader_XiaKe(){
}

CSLoader_XiaKe::~CSLoader_XiaKe(){
}

cocos2d::Data CSLoader_XiaKe::getDataBufferFromFile(const std::string &fileName){
	auto iter = m_csbFileCache.find(fileName);
	if (iter != m_csbFileCache.end()){
		return (const cocos2d::Data)iter->second;
	}
	cocos2d::Data dataRead = cocos2d::FileUtils::getInstance()->getDataFromFile(fileName);
	m_csbFileCache[fileName] = dataRead;
	return dataRead;
}
