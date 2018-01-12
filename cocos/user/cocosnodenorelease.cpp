#include "cocosnodenorelease.h"

USING_NS_CC;

IMPLEMENT_XMQXZREADER_INFO_DEFINE(NodeNoReleaseReader, CNodeNoRelease)

CNodeNoRelease::CNodeNoRelease(){
}

CNodeNoRelease::~CNodeNoRelease(){
}

//完全什么都不做
void CNodeNoRelease::onExit(){
}
/**
* Stops all running actions and schedulers
*/
void CNodeNoRelease::cleanup(){
}