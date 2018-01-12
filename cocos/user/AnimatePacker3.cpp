#include "AnimatePacker3.h"
using namespace cocos2d;
using namespace tinyxml2;

USING_NS_CC;
struct LTAnimate {
	std::string name;
	float delay;
	bool flipX;
	bool flipY;
	std::vector<std::string> spriteFrames;
};

static AnimatePacker3 *s_pAnimatePacker3 = nullptr;
AnimatePacker3* AnimatePacker3::GetInstance(){
	if (s_pAnimatePacker3){
		return s_pAnimatePacker3;
	}
	return new AnimatePacker3();
}
void AnimatePacker3::loadAnimations( const char *path ){
	ssize_t bufsize = 0;
	Data dataRead = CCFileUtils::getInstance()->getDataFromFile(path);
	if (dataRead.getSize() == 0)
	{
		return ;
	}
	tinyxml2::XMLDocument doc;
	doc.Parse((const char*)dataRead.getBytes(), dataRead.getSize());

	XMLElement *rootEle = doc.RootElement();
	tinyxml2::XMLElement *plist =rootEle->FirstChildElement();
	plist = plist->FirstChildElement();

	//解析xml
	vector<string> pLoadPlistFile;
	vector<LTAnimate> pAnimatesLoad;

	while(plist)
	{	
		pLoadPlistFile.push_back(plist->GetText());
		plist = plist->NextSiblingElement();
	}

	tinyxml2::XMLElement* pAnimateions = rootEle->FirstChildElement("animations");
	tinyxml2::XMLElement* animate= pAnimateions->FirstChildElement("animation");
	while (animate)
	{
		LTAnimate pAnimate;
	    XMLElement * animateInfo = animate->FirstChildElement("name");
		pAnimate.name = animateInfo->GetText();
		animateInfo = animate->FirstChildElement("delay");
		pAnimate.delay = atof(animateInfo->GetText());
		XMLElement *pFrame = animate->FirstChildElement("spriteFrame");
		while (pFrame)
		{
			pAnimate.spriteFrames.push_back(pFrame->GetText());
			pFrame = pFrame->NextSiblingElement();
		}
		animate = animate->NextSiblingElement();
		pAnimatesLoad.push_back(pAnimate);
	}
	//加载plist文件到cache中
	for (int i = 0; i<pLoadPlistFile.size(); i++)
	{
		string plistPath = CCFileUtils::getInstance()->fullPathFromRelativeFile(pLoadPlistFile[i].c_str(), path);
		CCSpriteFrameCache::getInstance()->addSpriteFramesWithFile(plistPath.c_str());
	}
	//加载动画到cache中
	Vector<SpriteFrame*>animFramesArray;
	
	for (int i = 0; i<pAnimatesLoad.size(); i++)
	{
		LTAnimate tAnimate = pAnimatesLoad[i];
		vector<string> tspriteFrames = tAnimate.spriteFrames;
		for(int j=0;j<tspriteFrames.size();j++)
		{
			SpriteFrame* frame1 = CCSpriteFrameCache::getInstance()->getSpriteFrameByName(tspriteFrames[j].c_str());
			animFramesArray.pushBack(frame1);
		}
		Animation* animation = Animation::createWithSpriteFrames(animFramesArray, tAnimate.delay);
		CCAnimationCache::getInstance()->addAnimation(animation, tAnimate.name.c_str());
		animFramesArray.clear();
		
	}
	pAnimatesLoad.clear();
	pLoadPlistFile.clear();
}

cocos2d::Animate* AnimatePacker3::getAnimate(const char *name){
	auto pAnimation = CCAnimationCache::getInstance()->getAnimation(name);
	if (pAnimation)
	{
		return CCAnimate::create(pAnimation);
	}
	return NULL;
}

