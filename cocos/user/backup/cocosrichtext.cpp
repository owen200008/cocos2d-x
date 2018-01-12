#include "cocosrichtext.h"
#include <basic.h>
#include "ui/UIHelper.h"

using namespace cocos2d;

GlobalCocosRichTextTypeCallback CCocosRichTextNode::m_globalFuncForType;
//绑定type的全局处理回调
void CCocosRichTextNode::BindReaderTypeCallback(const GlobalCocosRichTextTypeCallback& callback)
{
	m_globalFuncForType = callback;
}

CCocosRichTextNode::CCocosRichTextNode()
{
	_leftSpaceWidth = 0.0f;
	m_touchListener = nullptr;
	m_bSingleLine = false;
	m_realWidth = 0;
	m_fLineAddMinY = 0.0f;
}

CCocosRichTextNode::~CCocosRichTextNode()
{
	//clean up _touchListener
	_eventDispatcher->removeEventListener(m_touchListener);
	CC_SAFE_RELEASE_NULL(m_touchListener);

	_elementRenders.clear();
}
void CCocosRichTextNode::SetTouchEnable(bool bTouchEnable)
{
	if (bTouchEnable)
	{
		if (m_touchListener)
			return;
		m_touchListener = EventListenerTouchOneByOne::create();
		CC_SAFE_RETAIN(m_touchListener);
		m_touchListener->setSwallowTouches(true);
		m_touchListener->onTouchBegan = CC_CALLBACK_2(CCocosRichTextNode::onTouchBegan, this);
		m_touchListener->onTouchMoved = CC_CALLBACK_2(CCocosRichTextNode::onTouchMoved, this);
		m_touchListener->onTouchEnded = CC_CALLBACK_2(CCocosRichTextNode::onTouchEnded, this);
		m_touchListener->onTouchCancelled = CC_CALLBACK_2(CCocosRichTextNode::onTouchCancelled, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(m_touchListener, this);
	}
	else
	{
		if (!m_touchListener)
			return;
		_eventDispatcher->removeEventListener(m_touchListener);
		CC_SAFE_RELEASE_NULL(m_touchListener);
	}
}

bool CCocosRichTextNode::onTouchBegan(Touch *pTouch, Event *unusedEvent)
{
	//是在我内部
	Point _touchStartPos = pTouch->getLocation();
	auto camera = Camera::getVisitingCamera();
	int nSize = m_clkEvent.size();
	for (int i = 0; i < nSize; i++)
	{
		cocos2d::Node* pClk = m_clkEvent.at(i);

		Rect rect;
		rect.size = pClk->getContentSize();
		if (isScreenPointInRect(_touchStartPos, camera, pClk->getWorldToNodeTransform(), rect, nullptr))
		{
			m_mapRevertData[CocosRichTextRevertDataDefine_TouchBeginIndex] = i;
			return true;
		}
	}
	return false;
}
void CCocosRichTextNode::onTouchMoved(Touch *touch, Event *unusedEvent)
{
}
void CCocosRichTextNode::onTouchEnded(Touch *touch, Event *unusedEvent)
{
	Value& vValue = m_mapRevertData[CocosRichTextRevertDataDefine_TouchBeginIndex];
	int nIndex = vValue.asInt();
	if (nIndex < m_clkEvent.size() && nIndex >= 0)
	{
		Point _touchStartPos = touch->getLocation();
		auto camera = Camera::getVisitingCamera();

		cocos2d::Node* pClk = m_clkEvent.at(nIndex);

		Rect rect;
		rect.size = pClk->getContentSize();
		if (isScreenPointInRect(_touchStartPos, camera, pClk->getWorldToNodeTransform(), rect, nullptr))
		{
			TouchCocosRichText(touch);
		}
	}
}
void CCocosRichTextNode::onTouchCancelled(Touch *touch, Event *unusedEvent)
{
	m_mapRevertData.erase(CocosRichTextRevertDataDefine_TouchBeginIndex);
}

cocos2d::Value& CCocosRichTextNode::GetNodeRevertValue(int nKey)
{
	return m_mapRevertData[nKey];
}

void CCocosRichTextNode::onEnter()
{
	cocos2d::Node::onEnter();
	setCascadeColorEnabled(true);
	setCascadeOpacityEnabled(true);
}
/**
* Resumes all scheduled selectors, actions and event listeners.
* This method is called internally by onEnter.
*/
void CCocosRichTextNode::resume(void)
{
	cocos2d::Node::resume();
	for (const auto &child : _children)
	{
		child->resume();
	}
}
/**
* Pauses all scheduled selectors, actions and event listeners.
* This method is called internally by onExit.
*/
void CCocosRichTextNode::pause(void)
{
	cocos2d::Node::pause();
	for (const auto &child : _children)
	{
		child->pause();
	}
}

//选中的处理
void CCocosRichTextNode::TouchCocosRichText(cocos2d::Touch* pTouch)
{
	//是在我内部
	Point _touchStartPos = pTouch->getLocation();
	auto camera = Camera::getVisitingCamera();
	int nSize = m_clkEvent.size();
	for (int i = 0; i < nSize; i++)
	{
		cocos2d::Node* pClk = m_clkEvent.at(i);

		Rect rect;
		rect.size = pClk->getContentSize();
		if (isScreenPointInRect(_touchStartPos, camera, pClk->getWorldToNodeTransform(), rect, nullptr))
		{
			//默认发送消息处理
			CCocosRichTextNode_LinkDataDefault defaultsend(pClk, pTouch);
			_eventDispatcher->dispatchCustomEvent(CCocosRichTextNode_LinkDataDefaultMsg, &defaultsend);
		}
	}
}

#define InsertTextJson(setValue, color, fontsize) \
	rapidjson::Value object(rapidjson::kObjectType);\
	object.AddMember(CocosRichJsonKey_NodeTypeKey, CocosRichTextNodeType_Text, allocator);\
	object.AddMember(CocosRichTextKey_ExtTextData, setValue, allocator);\
	rapidjson::Value textDefaultColor;\
	textDefaultColor.SetString(color.c_str(), allocator);\
	object.AddMember(CocosRichTextKey_TextColor, textDefaultColor, allocator); \
	object.AddMember(CocosRichTextKey_FontSize, fontsize, allocator);\
	arrayJson.PushBack(object, allocator);

void CCocosRichTextNode::DealWithString(const char* pShowInfo, const char* pDefaultFontName, int nEnterFontSize, const char* pDefaultFontColor)
{
	if (NULL == pShowInfo)
		return;
	rapidjson::Document writedoc;
	writedoc.SetObject();
	rapidjson::Document::AllocatorType& allocator = writedoc.GetAllocator();
	rapidjson::Value arrayJson(rapidjson::kArrayType);

	std::string strDefaultTextColor = "FFE0D5BC";
	if (pDefaultFontColor && strlen(pDefaultFontColor) > 0)
		strDefaultTextColor = pDefaultFontColor;
	int nDefaultFontSize = nEnterFontSize;

	const char* pBegin = pShowInfo;
	int nBeginPos = 0;
	int nStrLength = strlen(pShowInfo);
	const char* pEnd = pShowInfo + nStrLength;
	
	for (int i = 0; i < nStrLength; i++)
	{
		const char* pCurrentPos = pShowInfo + i;
		if (*pCurrentPos == CocosRichTextKey_TextInfoSprite)
		{
			if (i + 10 < nStrLength && memcmp(pCurrentPos + 1, CocosRichTextKey_TextColor, 9) == 0 && *(pCurrentPos + 10) == '=')
			{
				if (i + 18 < nStrLength)
				{
					if (i > nBeginPos)
					{
						rapidjson::Value setValue;
						setValue.SetString(pShowInfo + nBeginPos, i - nBeginPos, allocator);
						InsertTextJson(setValue, strDefaultTextColor, nDefaultFontSize);
					}

					strDefaultTextColor = std::string(pCurrentPos + 11, 8);

					nBeginPos = i + 19;
					i += 18;
				}
			}
			;
			if (i + 9 < nStrLength && memcmp(pCurrentPos + 1, CocosRichTextKey_FontSize, 8) == 0 && *(pCurrentPos + 9) == '=')
			{
				if (i + 11 < nStrLength)
				{
					if (i > nBeginPos)
					{
						rapidjson::Value setValue;
						setValue.SetString(pShowInfo + nBeginPos, i - nBeginPos, allocator);
						InsertTextJson(setValue, strDefaultTextColor, nDefaultFontSize);
					}
					char sz[4] = {0};
					sz[0] = *(pCurrentPos + 10);
					sz[1] = *(pCurrentPos + 11);
					nDefaultFontSize = (int)atol(sz);

					nBeginPos = i + 12;
					i += 11;
				}
			}
		}
		else if (*pCurrentPos == CocosRichTextKey_ImageSprite)
		{
			if (pCurrentPos + 1 < pEnd)
			{
				unsigned char szBuf[8] = { 0 };
				szBuf[0] = *(pCurrentPos + 1);
				if (isdigit(szBuf[0]))
				{
					int nPos = 1;
					//检查第二个
					if (pCurrentPos + 2 < pEnd)
					{
						szBuf[1] = *(pCurrentPos + 2);
						if (isdigit(szBuf[1]))
						{
							nPos = 2;
							//检查第二个
							if (pCurrentPos + 3 < pEnd)
							{
								szBuf[2] = *(pCurrentPos + 3);
								if (isdigit(szBuf[2]))
								{
									nPos = 3;
								}
							}
						}
					}

					//插入文本
					if (i > nBeginPos)
					{
						rapidjson::Value setValue;
						setValue.SetString(pShowInfo + nBeginPos, i - nBeginPos, allocator);
						InsertTextJson(setValue, strDefaultTextColor, nDefaultFontSize);
					}
					//插入图片
					szBuf[nPos] = '\0';
					rapidjson::Value object(rapidjson::kObjectType);
					object.AddMember(CocosRichJsonKey_NodeTypeKey, CocosRichTextNodeType_Img, allocator);
					object.AddMember(CocosRichJsonKey_ImageValueData, (int)atol((const char*)szBuf), allocator);
					arrayJson.PushBack(object, allocator);

					//越过nPos位
					nBeginPos = i + nPos + 1;
					i += nPos;
				}
			}
		}
		else if (*pCurrentPos == CocosRichTextKey_ExtInfoSprite)
		{
			if (i + 4 < nStrLength)
			{
				bool bLink = memcmp(pCurrentPos + 1, CocosRichTextKey_ExtLinkData, 4) == 0;
				bool bText = bLink ? false : memcmp(pCurrentPos + 1, CocosRichTextKey_ExtTextData, 4) == 0;
				bool bType = (bLink || bText) ? false : memcmp(pCurrentPos + 1, CocosRichTextKey_ExtTypeData, 4) == 0;
				if (bLink || bText || bType)
				{
					//如果是道具,查找结束符
					bool bFind = false;
					if (*(pCurrentPos + 5) != '[')
					{
						break;
					}
					const char* pFindEnd = strchr(pCurrentPos + 5, ']');
					if (NULL == pFindEnd)
					{
						break;
					}
					int nPos = pFindEnd - pCurrentPos;
					if (nPos <= 7)
					{
						break;
					}
					//插入文本
					if (i > nBeginPos)
					{
						rapidjson::Value setValue;
						setValue.SetString(pShowInfo + nBeginPos, i - nBeginPos, allocator);
						InsertTextJson(setValue, strDefaultTextColor, nDefaultFontSize);
					}

					rapidjson::Value object(rapidjson::kObjectType);
					object.AddMember(CocosRichJsonKey_NodeTypeKey, bLink ? CocosRichTextNodeType_Link : (bText ? CocosRichTextNodeType_TextType : CocosRichTextNodeType_Type), allocator);
					rapidjson::Value strLinkJson;
					strLinkJson.SetString(pCurrentPos + 6, nPos - 6, allocator);

					object.AddMember(CocosRichJsonKey_ExtRevertData, strLinkJson, allocator);
					arrayJson.PushBack(object, allocator);

					//越过4位定义+数字+结束符
					nBeginPos = i + nPos + 1;
					i += nPos;
				}
			}
		}
		else if (*pCurrentPos == '<')
		{
			if (i + 3 < nStrLength)
			{
				if (memcmp(pCurrentPos + 1, "br>", 3) == 0)
				{
					//插入文本
					if (i > nBeginPos)
					{
						rapidjson::Value setValue;
						setValue.SetString(pShowInfo + nBeginPos, i - nBeginPos, allocator);
						InsertTextJson(setValue, strDefaultTextColor, nDefaultFontSize);
					}

					//插入换行
					rapidjson::Value object(rapidjson::kObjectType);
					object.AddMember(CocosRichJsonKey_NodeTypeKey, CocosRichTextNodeType_NewLine, allocator);
					arrayJson.PushBack(object, allocator);

					//越过4位定义+数字+结束符
					nBeginPos = i + 4;
					i += 3;
				}
			}
		}
	}
	if (nBeginPos < nStrLength)
	{
		rapidjson::Value setValue;
		setValue.SetString(pShowInfo + nBeginPos, nStrLength - nBeginPos, allocator);
		InsertTextJson(setValue, strDefaultTextColor, nDefaultFontSize);
	}
	//是否是数组  
	if (arrayJson.IsArray())
	{
		for (rapidjson::SizeType i = 0; i < arrayJson.Size(); i++)
		{
			const rapidjson::Value &p = arrayJson[i];
			if (p.HasMember(CocosRichJsonKey_NodeTypeKey))
			{
				const rapidjson::Value &typekeyEnt = p[CocosRichJsonKey_NodeTypeKey];
				DealWithJson((CocosRichTextNodeType)typekeyEnt.GetInt(), p, pDefaultFontName, nDefaultFontSize, pDefaultFontColor);
			}
			else
			{
				assert(0);
			}
		}
	}
	else
	{
		assert(0);
	}
}
void CCocosRichTextNode::initDefaultString(const char* pShowInfo, const char* pDefaultFontName, int nDefaultFontSize, const char* pDefaultFontColor, bool bCenter, bool bVCenter)
{
	initString(pShowInfo, pDefaultFontName, nDefaultFontSize, pDefaultFontColor, bCenter ? cocos2d::TextHAlignment::CENTER : cocos2d::TextHAlignment::LEFT, bVCenter);
}
void CCocosRichTextNode::initString(const char* pShowInfo, const char* pDefaultFontName , int nDefaultFontSize, const char* pDefaultFontColor, cocos2d::TextHAlignment hAlignment, bool bVCenter)
{
	//清空所有的子节点
	m_clkEvent.clear();
	removeAllChildren();
	addNewLine();

	DealWithString(pShowInfo, pDefaultFontName, nDefaultFontSize, pDefaultFontColor);
	formarRenderers(hAlignment, bVCenter);
}

void CCocosRichTextNode::initJsonNode(const rapidjson::Value& jsonValue, const char* pDefaultFontName, int nDefaultFontSize, const char* pDefaultFontColor, cocos2d::TextHAlignment hAlignment, bool bVCenter)
{
	if (!jsonValue.IsObject())
	{
		assert(0);
		return;
	}
	//清空所有的子节点
	m_clkEvent.clear();
	removeAllChildren();
	addNewLine();

	//是否有此成员  
	if (!jsonValue.HasMember(CocosRichJsonKey_RootKey))
		return;
	const rapidjson::Value &pArray = jsonValue[CocosRichJsonKey_RootKey];
	//是否是数组  
	if (pArray.IsArray())
	{
		for (rapidjson::SizeType i = 0; i < pArray.Size(); i++)
		{
			const rapidjson::Value &p = pArray[i];
			if (p.HasMember(CocosRichJsonKey_NodeTypeKey))
			{
				const rapidjson::Value &typekeyEnt = p[CocosRichJsonKey_NodeTypeKey];
				DealWithJson((CocosRichTextNodeType)typekeyEnt.GetInt(), p, pDefaultFontName, nDefaultFontSize, pDefaultFontColor);
			}
			else
			{
				assert(0);
			}
		}
	}
	else
	{
		assert(0);
	}

	formarRenderers(hAlignment, bVCenter);
}
void CCocosRichTextNode::initJsonData(const char* pShowInfo, const char* pDefaultFontName, int nDefaultFontSize, const char* pDefaultFontColor, cocos2d::TextHAlignment hAlignment, bool bVCenter)
{
	if (NULL == pShowInfo)
		return;

	//清空所有的子节点
	m_clkEvent.clear();
	removeAllChildren();
	addNewLine();
	//json解析
	rapidjson::Document _doc;
	_doc.Parse<0>(pShowInfo);
	if (_doc.HasParseError())
	{
		assert(0);
		return;
	}
	if (!_doc.IsObject())
	{
		assert(0);
		return;
	}
	//是否有此成员  
	if (!_doc.HasMember(CocosRichJsonKey_RootKey))
		return;
	const rapidjson::Value &pArray = _doc[CocosRichJsonKey_RootKey];
	//是否是数组  
	if (pArray.IsArray())
	{
		for (rapidjson::SizeType i = 0; i < pArray.Size(); i++)
		{
			const rapidjson::Value &p = pArray[i];
			if (p.HasMember(CocosRichJsonKey_NodeTypeKey))
			{
				const rapidjson::Value &typekeyEnt = p[CocosRichJsonKey_NodeTypeKey];
				DealWithJson((CocosRichTextNodeType)typekeyEnt.GetInt(), p, pDefaultFontName, nDefaultFontSize, pDefaultFontColor);
			}
			else
			{
				assert(0);
			}
		}
	}
	else
	{
		assert(0);
	}

	formarRenderers(hAlignment, bVCenter);
}

void CCocosRichTextNode::formarRenderers(cocos2d::TextHAlignment hAlignment, bool bVCenter)
{
	float newContentSizeHeight = 0.0f;
	
	int nSize = _elementRenders.size();
	int nYHeight = 0;
	if (hAlignment != cocos2d::TextHAlignment::LEFT && _elementRenders.size() == 1)
	{
		//只有一行的情况才有居中
		cocos2d::Vector<cocos2d::Node*>* row = (_elementRenders[0]);

		int nSize = row->size();
		float nCalcPosX = 0.0f;
		for (ssize_t j = 0; j < nSize; j++)
		{
			Node* l = row->at(j);
			nCalcPosX += l->getContentSize().width;
		}
		m_realWidth = nCalcPosX;
		//获取剩余的x
		float fPosLocation = (_contentSize.width - nCalcPosX) / (hAlignment == cocos2d::TextHAlignment::RIGHT ? 1 : 2);
		//获取最大的y
		float fMaxY = 0.0f;
		for (ssize_t j = 0; j < nSize; j++)
		{
			cocos2d::Node* l = row->at(j);
			l->setAnchorPoint(Vec2::ZERO);
			l->setPosition(fPosLocation, nYHeight);
			this->addChild(l, 1);
			fPosLocation += l->getContentSize().width;
			fMaxY = MAX(l->getContentSize().height, fMaxY);
		}
		nYHeight += fMaxY;
	}
	else
	{
		m_realWidth = _contentSize.width;
		if (m_bSingleLine)
		{
			if (nSize > 0)
				nSize = 1;
		}
		for (int i = 0; i < nSize; i++)
		{
			//从后往前
			cocos2d::Vector<Node*>* row = (_elementRenders[nSize - i - 1]);

			float nextPosX = 0.0f;
			//获取最大的y
			float fMaxY = 0.0f;
			for (ssize_t j = 0; j < row->size(); j++)
			{
				Node* l = row->at(j);
				l->setAnchorPoint(Vec2::ZERO);
				l->setPosition(nextPosX, nYHeight);
				this->addChild(l, 1);
				nextPosX += l->getContentSize().width;
				fMaxY = MAX(l->getContentSize().height, fMaxY);
			}
			if (i != nSize - 1)
			{
				nYHeight += fMaxY + m_fLineAddMinY;
			}
			else
			{
				nYHeight += fMaxY;
			}
		}
	}
	if (bVCenter)
	{
		if (nYHeight < _contentSize.height)
		{
			//高度小于的时候才有居中需求,计算附加高度
			int nAddHeight = (_contentSize.height - nYHeight) / 2;
			for (int i = 0; i < nSize; i++)
			{
				//从后往前
				cocos2d::Vector<Node*>* row = _elementRenders[i];
				for (ssize_t j = 0; j < row->size(); j++)
				{
					Node* l = row->at(j);
					l->setPositionY(l->getPositionY() + nAddHeight);
				}
			}
		}
	}
	size_t length = _elementRenders.size();
	for (size_t i = 0; i<length; i++)
	{
		cocos2d::Vector<Node*>* l = _elementRenders[i];
		l->clear();
		delete l;
	}
	_elementRenders.clear();

	if (!bVCenter)
		this->setContentSize(cocos2d::Size(_contentSize.width, nYHeight));
	
	setCameraMask(getCameraMask());
}

//处理函数
void CCocosRichTextNode::DealWithJson(CocosRichTextNodeType keyDefine, const rapidjson::Value& p, const char* pDefaultFontName, int nDefaultFontSize, const char* pDefaultFontColor)
{
	typedef basiclib::basic_map<basiclib::CBasicString, basiclib::CBasicString>				OrderContainer;
	switch (keyDefine)
	{
	case CocosRichTextNodeType_NewLine:
		addNewLine();
		break;
	case CocosRichTextNodeType_Text:
	{
		if (p.HasMember(CocosRichTextKey_ExtTextData))
		{
			//默认颜色
			Color4B setColor(0xE0, 0xD5, 0xBC, 0xFF);
			if (p.HasMember(CocosRichTextKey_TextColor))
			{
				const rapidjson::Value &colorText = p[CocosRichTextKey_TextColor];
				unsigned long nSetColor = strtoll(colorText.GetString(), NULL, 16);
				setColor.a = (nSetColor >> 24) & 0xFF;
				setColor.r = (nSetColor >> 16) & 0xFF;
				setColor.g = (nSetColor >> 8) & 0xFF;
				setColor.b = nSetColor & 0xFF;
			}
			else if (pDefaultFontColor)
			{
				unsigned long nSetColor = strtoll(pDefaultFontColor, NULL, 16);
				setColor.a = (nSetColor >> 24) & 0xFF;
				setColor.r = (nSetColor >> 16) & 0xFF;
				setColor.g = (nSetColor >> 8) & 0xFF;
				setColor.b = nSetColor & 0xFF;
			}
			int nSetFontSize = nDefaultFontSize;
			if (p.HasMember(CocosRichTextKey_FontSize))
			{
				const rapidjson::Value &fontSize = p[CocosRichTextKey_FontSize];
				nSetFontSize = fontSize.GetInt();
			}
			Color4B setOutLineColor = setColor;
			const cocos2d::Color4B* pOutLineColor = nullptr;
			if (p.HasMember(CocosRichTextKey_OutLineColor))
			{
				const rapidjson::Value &colorText = p[CocosRichTextKey_OutLineColor];
				unsigned long nSetColor = strtoll(colorText.GetString(), NULL, 16);
				setOutLineColor.a = (nSetColor >> 24) & 0xFF;
				setOutLineColor.r = (nSetColor >> 16) & 0xFF;
				setOutLineColor.g = (nSetColor >> 8) & 0xFF;
				setOutLineColor.b = nSetColor & 0xFF;
				pOutLineColor = &setOutLineColor;
			}
			const rapidjson::Value &valueEnt = p[CocosRichTextKey_ExtTextData];
			handleTextRenderer(valueEnt.GetString(), pDefaultFontName, nSetFontSize, setColor, nullptr, pOutLineColor);
		}
	}
		break;
	case CocosRichTextNodeType_Img:
	{
		//获取img的值
		if (p.HasMember(CocosRichJsonKey_ImageValueData))
		{
			const rapidjson::Value &valueEnt = p[CocosRichJsonKey_ImageValueData];
			int nValue = valueEnt.GetInt();

			char szFileName[64] = { 0 };
			sprintf(szFileName, "ani_talkimg%d", nValue);
			CCAnimationCache *pAniCache = CCAnimationCache::getInstance();
			CCAnimation* pAnimation = pAniCache->getAnimation(szFileName);
			if (NULL == pAnimation)
			{
				pAnimation = pAniCache->getAnimation("ani_talkimg1");
			}
			if (pAnimation)
			{
				const cocos2d::Vector<AnimationFrame*>& vtFrame = pAnimation->getFrames();
				if (vtFrame.size() > 0)
				{
					AnimationFrame* pFirstFrame = vtFrame.at(0);
					cocos2d::Sprite* pSprite = cocos2d::Sprite::create();
					pSprite->setSpriteFrame(pFirstFrame->getSpriteFrame());
					pSprite->runAction(RepeatForever::create(CCAnimate::create(pAnimation)));

					handleNormalRenderer(pSprite, true, nullptr);
				}
			}
		}

	}
		break;
	case CocosRichTextNodeType_ParseText:
	{
		if (p.HasMember(CocosRichJsonKey_ParseTextData))
		{
			const char* pDealColor = pDefaultFontColor;
			if (p.HasMember(CocosRichTextKey_TextColor))
			{
				pDealColor = p[CocosRichTextKey_TextColor].GetString();
			}
			int nDefaultSize = nDefaultFontSize;
			if (p.HasMember(CocosRichTextKey_FontSize))
			{
				const rapidjson::Value &fontSize = p[CocosRichTextKey_FontSize];
				nDefaultSize = fontSize.GetInt();
			}

			const rapidjson::Value &keyvalue = p[CocosRichJsonKey_ParseTextData];
			if (keyvalue.IsString())
			{
				DealWithString(keyvalue.GetString(), pDefaultFontName, nDefaultSize, pDealColor);
			}
			else if (keyvalue.HasMember(CocosRichJsonKey_RootKey))
			{
				const rapidjson::Value& dataKey = keyvalue[CocosRichJsonKey_RootKey];
				//是否是数组  
				if (dataKey.IsArray())
				{
					for (rapidjson::SizeType i = 0; i < dataKey.Size(); i++)
					{
						const rapidjson::Value &pNext = dataKey[i];
						if (pNext.HasMember(CocosRichJsonKey_NodeTypeKey))
						{
							const rapidjson::Value &typekeyEnt = pNext[CocosRichJsonKey_NodeTypeKey];
							DealWithJson((CocosRichTextNodeType)typekeyEnt.GetInt(), pNext, pDefaultFontName, nDefaultFontSize, pDealColor);
						}
						else
						{
							assert(0);
						}
					}
				}
				else
				{
					assert(0);
				}
			}
			else
			{
				assert(0);
			}
		}
	}
		break;
	case CocosRichTextNodeType_Type:
	{
		if (p.HasMember(CocosRichJsonKey_ExtRevertData))
		{
			std::string strText;
			std::string strLinkData;
			
			const rapidjson::Value &valueEnt = p[CocosRichJsonKey_ExtRevertData];
			//默认颜色
			Color4B defaultLinkColor(0xE0, 0xD5, 0xBC, 0xFF);
			m_globalFuncForType(this, valueEnt.GetString(), pDefaultFontName, nDefaultFontSize, defaultLinkColor);
		}
	}
		break;
	case CocosRichTextNodeType_Link:
	case CocosRichTextNodeType_TextType:
	{
		if (p.HasMember(CocosRichJsonKey_ExtRevertData))
		{
			const rapidjson::Value &valueEnt = p[CocosRichJsonKey_ExtRevertData];

			OrderContainer mapOrder;
			basiclib::Basic_ParseParamString(valueEnt.GetString(), "=&", basiclib::IntoMapContainer_s<OrderContainer>(mapOrder));
			OrderContainer::iterator iterText = mapOrder.find(CocosRichTextKey_ExtTextData);
			if (iterText != mapOrder.end())
			{
				//默认颜色
				Color4B defaultLinkColor(0xE0, 0xD5, 0xBC, 0xFF);

				const char* pFontName = pDefaultFontName;
				int nFontSize = nDefaultFontSize;
				OrderContainer::iterator iterFontSize = mapOrder.find(CocosRichTextKey_FontSize);
				if (iterFontSize != mapOrder.end())
				{
					nFontSize = atol(iterFontSize->second.c_str());
				}
				const char* pLinkData = nullptr;
				OrderContainer::iterator iterLinkData = mapOrder.find(CocosRichTextKey_ExtLinkData);
				if (iterLinkData != mapOrder.end())
				{
					pLinkData = iterLinkData->second.c_str();
					//默认link的颜色
					defaultLinkColor.set(0x00, 0xf1, 0x0b, 0xFF);
				}
				Color4B setColor = defaultLinkColor;
				OrderContainer::iterator iterTextColor = mapOrder.find(CocosRichTextKey_TextColor);
				if (iterTextColor != mapOrder.end())
				{
					unsigned long nSetColor = strtoll(iterTextColor->second.c_str(), NULL, 16);
					setColor.a = (nSetColor >> 24) & 0xFF;
					setColor.r = (nSetColor >> 16) & 0xFF;
					setColor.g = (nSetColor >> 8) & 0xFF;
					setColor.b = nSetColor & 0xFF;
				}
				Color4B setOutLineColor = defaultLinkColor;
				const cocos2d::Color4B* pOutLineColor = nullptr;
				OrderContainer::iterator iterOutLineColor = mapOrder.find(CocosRichTextKey_OutLineColor);
				if (iterOutLineColor != mapOrder.end())
				{
					unsigned long nSetColor = strtoll(iterOutLineColor->second.c_str(), NULL, 16);
					setOutLineColor.a = (nSetColor >> 24) & 0xFF;
					setOutLineColor.r = (nSetColor >> 16) & 0xFF;
					setOutLineColor.g = (nSetColor >> 8) & 0xFF;
					setOutLineColor.b = nSetColor & 0xFF;
					pOutLineColor = &setOutLineColor;
				}

				handleTextRenderer(iterText->second.c_str(), pFontName, nFontSize, setColor, pLinkData, pOutLineColor);
			}
		}
		
	}
		break;
	default:
		assert(0);
		break;
	}
}

void CCocosRichTextNode::addNewLine()
{
	_leftSpaceWidth = _contentSize.width;
	_elementRenders.push_back(new cocos2d::Vector<cocos2d::Node*>());
}

void CCocosRichTextNode::handleTextRenderer(const std::string& strText, const char* pDefaultFontName, int nDefaultFontSize, const cocos2d::Color4B& fontColor, const char* pLinkData, const cocos2d::Color4B* pOutLineColor)
{
	cocos2d::Label* pText = nullptr;
	
	if (pDefaultFontName && strlen(pDefaultFontName) > 0 && FileUtils::getInstance()->isFileExist(pDefaultFontName))
	{
		pText = Label::createWithTTF(strText.c_str(), pDefaultFontName, nDefaultFontSize);
	}
	else
	{
		pText = Label::createWithSystemFont(strText.c_str(), "Helvetica", nDefaultFontSize);
	}

	pText->setTextColor(fontColor);
	float textRendererWidth = pText->getContentSize().width;
	_leftSpaceWidth -= textRendererWidth;
	if (_leftSpaceWidth < 0.0f)
	{
		float overstepPercent = (-_leftSpaceWidth) / textRendererWidth;
		
		size_t stringLength = StringUtils::getCharacterCountInUTF8String(strText);
		int leftLength = stringLength * (1.0f - overstepPercent);
		//The minimum cut length is 1, otherwise will cause the infinite loop.
		if (0 >= leftLength) 
			leftLength = 1;
		std::string leftWords = cocos2d::ui::Helper::getSubStringOfUTF8String(strText, 0, leftLength);
		std::string cutWords = cocos2d::ui::Helper::getSubStringOfUTF8String(strText, leftLength, stringLength - leftLength);
		if (leftLength > 0)
		{
			cocos2d::Label* pLeftText = nullptr;
			if (pDefaultFontName && FileUtils::getInstance()->isFileExist(pDefaultFontName))
			{
				pLeftText = Label::createWithTTF(leftWords, pDefaultFontName, nDefaultFontSize);
			}
			else
			{
				pLeftText = Label::createWithSystemFont(leftWords, "Helvetica", nDefaultFontSize);
			}
			float leftTextWidth = pLeftText->getContentSize().width;
			if (leftLength > 1 && leftTextWidth > _leftSpaceWidth + textRendererWidth)
			{
				//这个时候需要做处理把多余的部分给后面的处理
				float fLeftPercent = (_leftSpaceWidth + textRendererWidth) / leftTextWidth;
				stringLength = StringUtils::getCharacterCountInUTF8String(leftWords);
				leftLength = stringLength * fLeftPercent;
				if (leftLength <= 0)
					leftLength = 1;

				cutWords = ui::Helper::getSubStringOfUTF8String(leftWords, leftLength, stringLength - leftLength) + cutWords;
				leftWords = ui::Helper::getSubStringOfUTF8String(leftWords, 0, leftLength);
				if (leftLength > 0)
				{
					if (pDefaultFontName && FileUtils::getInstance()->isFileExist(pDefaultFontName))
					{
						pLeftText = Label::createWithTTF(leftWords, pDefaultFontName, nDefaultFontSize);
					}
					else
					{
						pLeftText = Label::createWithSystemFont(leftWords, "Helvetica", nDefaultFontSize);
					}
				}
			}

			//默认颜色
			pLeftText->setTextColor(fontColor);
			if (pOutLineColor)
			{
				pLeftText->enableOutline(*pOutLineColor, 1);
			}
			handleNormalRenderer(pLeftText, false, pLinkData);
		}

		addNewLine();
		handleTextRenderer(cutWords, pDefaultFontName, nDefaultFontSize, fontColor, pLinkData, pOutLineColor);
	}
	else
	{
		if (pOutLineColor)
		{
			pText->enableOutline(*pOutLineColor, 1);
		}
		handleNormalRenderer(pText, false, pLinkData);
	}
}

void CCocosRichTextNode::handleNormalRenderer(Node* renderer, bool bCheckLength, const char* pLinkData)
{
	//加入之后判断是否有link信息
	if (pLinkData)
	{
		renderer->setUserObject(cocos2d::CCString::create(pLinkData));
		m_clkEvent.pushBack(renderer);
	}
	if (bCheckLength)
	{
		Size imgSize = renderer->getContentSize();
		_leftSpaceWidth -= imgSize.width;
		if (_leftSpaceWidth < 0.0f)
		{
			addNewLine();
			pushToContainer(renderer);
			_leftSpaceWidth -= imgSize.width;
		}
		else
		{
			pushToContainer(renderer);
		}
	}
	else
	{
		pushToContainer(renderer);
	}
}

void CCocosRichTextNode::pushToContainer(cocos2d::Node* renderer)
{
	if (_elementRenders.size() <= 0)
	{
		assert(0);
		return;
	}

	_elementRenders[_elementRenders.size() - 1]->pushBack(renderer);
}

////////////////////////////////////////////////////////////////////////////////////////////
CCocosRichTextNodeForCocos::CCocosRichTextNodeForCocos()
{
	m_nDefaultFontSize = 20;
	m_bCenter = cocos2d::TextHAlignment::LEFT;
	m_bVCenter = false;
	m_bDirty = false;
	m_bJson = false;
}
CCocosRichTextNodeForCocos::~CCocosRichTextNodeForCocos()
{

}
std::string& CCocosRichTextNodeForCocos::GetDefaultFontName()
{
	return m_strDefaultFontName;
}
void CCocosRichTextNodeForCocos::SetDefaultFontName(const char* pFontName)
{
	m_strDefaultFontName = pFontName;
	m_bDirty = true;
}

int CCocosRichTextNodeForCocos::GetDefaultFontSize()
{
	return m_nDefaultFontSize;
}
void CCocosRichTextNodeForCocos::SetDefaultFontSize(int nFontSize)
{
	m_nDefaultFontSize = nFontSize;
	m_bDirty = true;
}

std::string& CCocosRichTextNodeForCocos::GetDefaultFontColor()
{
	return m_pstrDefaultFontColor;
}
void CCocosRichTextNodeForCocos::SetDefaultFontColor(const char* pColor)
{
	m_pstrDefaultFontColor = pColor;
	m_bDirty = true;
}
bool CCocosRichTextNodeForCocos::GetBHCenter()
{
	return m_bCenter == cocos2d::TextHAlignment::CENTER;
}
void CCocosRichTextNodeForCocos::SetBHCenter(bool bCenter)
{
	m_bCenter = bCenter ? cocos2d::TextHAlignment::CENTER : cocos2d::TextHAlignment::LEFT;
	m_bDirty = true;
}
cocos2d::TextHAlignment CCocosRichTextNodeForCocos::GetHorizontalAlignment()
{
	return m_bCenter;
}
void CCocosRichTextNodeForCocos::SetHorizontalAlignment(cocos2d::TextHAlignment hAlignment)
{
	m_bCenter = hAlignment;
	m_bDirty = true;
}

bool CCocosRichTextNodeForCocos::GetBVCenter()
{
	return m_bVCenter;
}
void CCocosRichTextNodeForCocos::SetBVCenter(bool bCenter)
{
	m_bVCenter = bCenter;
	m_bDirty = true;
}
std::string& CCocosRichTextNodeForCocos::GetDataText()
{
	return m_strDatatext;
}
void CCocosRichTextNodeForCocos::SetDataText(const char* pDataText, bool bUpdate, bool bJson)
{
	m_bJson = bJson;
	m_strDatatext = pDataText;
	m_bDirty = true;
	if (bUpdate)
	{
		if (m_bJson)
			initJsonData(m_strDatatext.c_str(), m_strDefaultFontName.c_str(), m_nDefaultFontSize, m_pstrDefaultFontColor.c_str(), m_bCenter, m_bVCenter);
		else
			initString(m_strDatatext.c_str(), m_strDefaultFontName.c_str(), m_nDefaultFontSize, m_pstrDefaultFontColor.c_str(), m_bCenter, m_bVCenter);
		m_bDirty = false;
	}
}
//设置是否单行显示
void CCocosRichTextNodeForCocos::SetSingleLine(bool bSingle)
{
	m_bSingleLine = bSingle;
	m_bDirty = true;
}

void CCocosRichTextNodeForCocos::visit(cocos2d::Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
	if (m_bDirty)
	{
		if (m_bJson)
			initJsonData(m_strDatatext.c_str(), m_strDefaultFontName.c_str(), m_nDefaultFontSize, m_pstrDefaultFontColor.c_str(), m_bCenter, m_bVCenter);
		else
			initString(m_strDatatext.c_str(), m_strDefaultFontName.c_str(), m_nDefaultFontSize, m_pstrDefaultFontColor.c_str(), m_bCenter, m_bVCenter);
		m_bDirty = false;
	}
	return CCocosRichTextNode::visit(renderer, parentTransform, parentFlags);
}

//设置换行间隔
void CCocosRichTextNodeForCocos::SetLineAddMinY(float fYAddLine)
{
	m_fLineAddMinY = fYAddLine;
	m_bDirty = true;
}
