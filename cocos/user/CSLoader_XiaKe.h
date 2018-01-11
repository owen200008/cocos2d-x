#ifndef XIAKE_CSLOADERXMQXZ_H
#define XIAKE_CSLOADERXMQXZ_H

#include "editor-support/cocostudio/ActionTimeline/CSLoader.h"

class CSLoader_XiaKe : public cocos2d::CSLoader
{
public:
	CSLoader_XiaKe();
	virtual ~CSLoader_XiaKe();

	virtual cocos2d::Data getDataBufferFromFile(const std::string &fileName);
protected:
	std::unordered_map<std::string, cocos2d::Data> m_csbFileCache;
};

#endif