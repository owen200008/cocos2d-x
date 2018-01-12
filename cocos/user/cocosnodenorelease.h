#ifndef COCOS_COCOSNODENORELEASE_H
#define COCOS_COCOSNODENORELEASE_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocosreader/publiccocosreader.h"

//永不释放的节点
class CC_DLL CNodeNoRelease : public cocos2d::Node{
public:
	CNodeNoRelease();
	virtual ~CNodeNoRelease();

	CREATE_FUNC(CNodeNoRelease);

	//完全什么都不做
	virtual void onExit() override;
	/**
	* Stops all running actions and schedulers
	*/
	virtual void cleanup();
};
DECLARE_XMQXZREADER_HEADER_DEFINE(NodeNoReleaseReader, CNodeNoRelease)

#endif