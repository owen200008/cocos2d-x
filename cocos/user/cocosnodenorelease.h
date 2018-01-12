#ifndef COCOS_COCOSNODENORELEASE_H
#define COCOS_COCOSNODENORELEASE_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocosreader/publiccocosreader.h"

//�����ͷŵĽڵ�
class CC_DLL CNodeNoRelease : public cocos2d::Node{
public:
	CNodeNoRelease();
	virtual ~CNodeNoRelease();

	CREATE_FUNC(CNodeNoRelease);

	//��ȫʲô������
	virtual void onExit() override;
	/**
	* Stops all running actions and schedulers
	*/
	virtual void cleanup();
};
DECLARE_XMQXZREADER_HEADER_DEFINE(NodeNoReleaseReader, CNodeNoRelease)

#endif