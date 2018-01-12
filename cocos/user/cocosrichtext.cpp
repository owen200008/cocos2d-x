#include "cocosrichtext.h"
#include "ui/UIHelper.h"

using namespace cocos2d;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static CocosRichTextStyleConfig m_defaultStyleConfig;
static CocosRichTextFontConfig m_defaultFontConfig;
MapCocosRichTextStyleConfig                         CCocosRichTextNode::m_mapStyleConfig;
MapCocosRichTextFontConfig                          CCocosRichTextNode::m_mapFontConfig;
std::function<void(int, char*)>                     CCocosRichTextNode::m_funcGetAnimation;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cocos2d::Label* CocosRichTextFontConfig::CreateLabelByConfig(const std::string& text, int nDefaultFontSize){
    int nFontSize = nDefaultFontSize;
    nFontSize = nFontSize > 0 ? nFontSize : m_nFontSize;
    if(m_funcCreateLabel == nullptr){
        if(m_strFontName.length() > 0 && FileUtils::getInstance()->isFileExist(m_strFontName)){
            m_funcCreateLabel = [&](const std::string& text, int nFontSize)->cocos2d::Label*{
                return Label::createWithTTF(text, m_strFontName, nFontSize);
            };
        }
        else{
            m_funcCreateLabel = [&](const std::string& text, int nFontSize)->cocos2d::Label*{
                return Label::createWithSystemFont(text, "Helvetica", nFontSize);
            };
        }
    }
    cocos2d::Label* pRet = m_funcCreateLabel(text, nFontSize);
    if(pRet){
        pRet->setTextColor(m_fontColor);
        if(m_bOutlineColor){
            pRet->enableOutline(m_outlineColor, 1);
        }
    }
    return pRet;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CCocosRichTextNode::RegisterStyleConfig(int nIndex, CocosRichTextStyleConfig& config){
    m_mapStyleConfig[nIndex] = config;
}
void CCocosRichTextNode::RegisterFontConfig(int nIndex, CocosRichTextFontConfig& config){
    m_mapFontConfig[nIndex] = config;
}
CocosRichTextStyleConfig* CCocosRichTextNode::GetStyleConfig(int nIndex){
    auto iter = m_mapStyleConfig.find(nIndex);
    if(iter != m_mapStyleConfig.end())
        return &iter->second;
    return &m_defaultStyleConfig;
}
CocosRichTextFontConfig* CCocosRichTextNode::GetFontConfig(int nIndex){
    auto iter = m_mapFontConfig.find(nIndex);
    if(iter != m_mapFontConfig.end())
        return &iter->second;
    return &m_defaultFontConfig;
}
void CCocosRichTextNode::BindGetAnimationFunc(const std::function<void(int, char*)>& func){
    m_funcGetAnimation = func;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CCocosRichTextNode::CCocosRichTextNode(){
    m_touchListener = nullptr;
    _leftSpaceWidth = 0.0f;
    m_bSingleLine = false;
    m_realWidth = 0;
    m_fLineAddMinY = 0.0f;
    m_nTouchIndex = -1;
    m_nFontChoose = -1;
    m_nStyleChoose = -1;
}

CCocosRichTextNode::~CCocosRichTextNode(){
	//clean up _touchListener
    if(m_touchListener){
        _eventDispatcher->removeEventListener(m_touchListener);
        CC_SAFE_RELEASE_NULL(m_touchListener);
    }
	_elementRenders.clear();
}

void CCocosRichTextNode::SetTouchEnable(bool bTouchEnable){
	if (bTouchEnable){
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
	else{
		if (!m_touchListener)
			return;
		_eventDispatcher->removeEventListener(m_touchListener);
		CC_SAFE_RELEASE_NULL(m_touchListener);
	}
}

//! 根据touch获取选中的index
int16_t CCocosRichTextNode::GetTouchNodeIndex(cocos2d::Touch* pTouch){
    int16_t nRet = -1;
    Point _touchStartPos = pTouch->getLocation();
    auto camera = Camera::getVisitingCamera();
    int16_t nSize = (int16_t)m_clkEvent.size();
    for(int16_t i = 0; i < nSize; i++){
        cocos2d::Node* pClk = m_clkEvent.at(i);
        Rect rect;
        rect.size = pClk->getContentSize();
        if(isScreenPointInRect(_touchStartPos, camera, pClk->getWorldToNodeTransform(), rect, nullptr)){
            nRet = i;
            break;
        }
    }
    return nRet;
}
//! 验证是否是这个index
bool CCocosRichTextNode::IsTouchIndexNode(cocos2d::Touch* pTouch, int16_t nIndex){
    if(nIndex < m_clkEvent.size() && nIndex >= 0){
        Point _touchStartPos = pTouch->getLocation();
        auto camera = Camera::getVisitingCamera();
        cocos2d::Node* pClk = m_clkEvent.at(nIndex);
        Rect rect;
        rect.size = pClk->getContentSize();
        if(isScreenPointInRect(_touchStartPos, camera, pClk->getWorldToNodeTransform(), rect, nullptr)){
            return true;
        }
    }
    return false;
}

bool CCocosRichTextNode::onTouchBegan(Touch *pTouch, Event *unusedEvent){
    m_nTouchIndex = GetTouchNodeIndex(pTouch);
    if(m_nTouchIndex >= 0)
        return true;
    return false;
}

void CCocosRichTextNode::onTouchMoved(Touch *touch, Event *unusedEvent){
}

void CCocosRichTextNode::onTouchEnded(Touch *pTouch, Event *unusedEvent){
    if(IsTouchIndexNode(pTouch, m_nTouchIndex)){
        CCocosRichTextNodeClkNotify defaultsend(m_clkEvent.at(m_nTouchIndex), pTouch);
        _eventDispatcher->dispatchCustomEvent(CCocosRichTextNode_ClkNodeMsg, &defaultsend);
    }
    m_nTouchIndex = -1;
}

void CCocosRichTextNode::onTouchCancelled(Touch *touch, Event *unusedEvent){
    m_nTouchIndex = -1;
}

void CCocosRichTextNode::onEnter(){
	cocos2d::Node::onEnter();
	setCascadeColorEnabled(true);
	setCascadeOpacityEnabled(true);
}
/**
* Resumes all scheduled selectors, actions and event listeners.
* This method is called internally by onEnter.
*/
void CCocosRichTextNode::resume(void){
	cocos2d::Node::resume();
	for (const auto &child : _children){
		child->resume();
	}
}

/**
* Pauses all scheduled selectors, actions and event listeners.
* This method is called internally by onExit.
*/
void CCocosRichTextNode::pause(void){
	cocos2d::Node::pause();
	for (const auto &child : _children){
		child->pause();
	}
}

void CCocosRichTextNode::initJsonNode(const rapidjson::Value& jsonValue, int nFontIndex, int nStyleIndex){
    if (!jsonValue.IsObject()){
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
    if(!pArray.IsArray()){
        assert(0);
        return;
    }
    m_nFontChoose = nFontIndex;
    m_nStyleChoose = nStyleIndex;
    for(rapidjson::SizeType i = 0; i < pArray.Size(); i++){
        const rapidjson::Value &p = pArray[i];
        if(!p.HasMember(CocosRichJsonKey_NodeTypeKey)){
            assert(0);
            continue;
        }
        DealWithJson((CocosRichTextNodeType)p[CocosRichJsonKey_NodeTypeKey].GetInt(), p, GetFontConfig(nFontIndex));
    }
    formatRenderers(GetStyleConfig(nStyleIndex));
}
void CCocosRichTextNode::initJsonData(const char* pShowInfo, int nFontIndex, int nStyleIndex){
	if (NULL == pShowInfo)
		return;

	//json解析
	rapidjson::Document _doc;
	_doc.Parse<0>(pShowInfo);
	if (_doc.HasParseError()){
		assert(0);
		return;
	}
	if (!_doc.IsObject()){
		assert(0);
		return;
	}
    initJsonNode(_doc, nFontIndex, nStyleIndex);
}

void CCocosRichTextNode::formatRenderers(CocosRichTextStyleConfig* pCofingStyle){
	float newContentSizeHeight = 0.0f;
	
	int nSize = _elementRenders.size();
	int nYHeight = 0;
	if (pCofingStyle->m_hAlignment != cocos2d::TextHAlignment::LEFT && _elementRenders.size() == 1){
		//只有一行的情况才有居中
		cocos2d::Vector<cocos2d::Node*>* row = (_elementRenders[0]);

		int nSize = row->size();
		float nCalcPosX = 0.0f;
		for (ssize_t j = 0; j < nSize; j++){
			Node* l = row->at(j);
			nCalcPosX += l->getContentSize().width;
		}
		m_realWidth = nCalcPosX;
		//获取剩余的x
		float fPosLocation = (_contentSize.width - nCalcPosX) / (pCofingStyle->m_hAlignment == cocos2d::TextHAlignment::RIGHT ? 1 : 2);
		//获取最大的y
		float fMaxY = 0.0f;
		for (ssize_t j = 0; j < nSize; j++){
			cocos2d::Node* l = row->at(j);
			l->setAnchorPoint(Vec2::ZERO);
			l->setPosition(fPosLocation, nYHeight);
			this->addChild(l, 1);
			fPosLocation += l->getContentSize().width;
			fMaxY = MAX(l->getContentSize().height, fMaxY);
		}
		nYHeight += fMaxY;
	}
	else{
		m_realWidth = _contentSize.width;
		if (m_bSingleLine){
			if (nSize > 0)
				nSize = 1;
		}
		for (int i = 0; i < nSize; i++){
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
	if (pCofingStyle->m_bVCenter){
		if (nYHeight < _contentSize.height){
			//高度小于的时候才有居中需求,计算附加高度
			int nAddHeight = (_contentSize.height - nYHeight) / 2;
			for (int i = 0; i < nSize; i++){
				//从后往前
				cocos2d::Vector<Node*>* row = _elementRenders[i];
				for (ssize_t j = 0; j < row->size(); j++){
					Node* l = row->at(j);
					l->setPositionY(l->getPositionY() + nAddHeight);
				}
			}
		}
	}
	size_t length = _elementRenders.size();
	for (size_t i = 0; i<length; i++){
		cocos2d::Vector<Node*>* l = _elementRenders[i];
		l->clear();
		delete l;
	}
	_elementRenders.clear();

	if (!pCofingStyle->m_bVCenter)
		this->setContentSize(cocos2d::Size(_contentSize.width, nYHeight));
	setCameraMask(getCameraMask());
}

//处理函数
void CCocosRichTextNode::DealWithJson(CocosRichTextNodeType keyDefine, const rapidjson::Value& p, CocosRichTextFontConfig* pConfigFont){
	switch (keyDefine)
	{
	case CocosRichTextNodeType_NewLine:
		addNewLine();
		break;
    case CocosRichTextNodeType_Text:
    {
		if (p.HasMember(CocosRichJsonKey_Text)){
            const char* pLinkData = nullptr;
            //获取文本
            const rapidjson::Value &valueEnt = p[CocosRichJsonKey_Text];
            if(p.HasMember(CocosRichJsonKey_Text_Type)){
                pConfigFont = GetFontConfig(p[CocosRichJsonKey_Text_Type].GetInt());
            }
            if(p.HasMember(CocosRichJsonKey_Text_Type)){
                pLinkData = p[CocosRichJsonKey_Text_Link].GetString();
            }
            
            if(p.HasMember(CocosRichJsonKey_Text_BG)){
                drawBGTextRender(valueEnt.GetString(), pConfigFont, p[CocosRichJsonKey_Text_BG].GetString(), pLinkData);
            }
            else{
                drawTextRender(valueEnt.GetString(), pConfigFont, pLinkData);
            }
		}
        break;
    }
	case CocosRichTextNodeType_Img:
    {
		if (p.HasMember(CocosRichJsonKey_ImageValueData)){
            //获取img的值
			int nValue = p[CocosRichJsonKey_ImageValueData].GetInt();
			char szFileName[256] = { 0 };
            if(m_funcGetAnimation != nullptr){
                m_funcGetAnimation(nValue, szFileName);
                AnimationCache *pAniCache = AnimationCache::getInstance();
                Animation* pAnimation = pAniCache->getAnimation(szFileName);
                if(nullptr == pAnimation){
                    assert(0);
                    break;
                }
                const cocos2d::Vector<AnimationFrame*>& vtFrame = pAnimation->getFrames();
                if(vtFrame.size() > 0){
                    AnimationFrame* pFirstFrame = vtFrame.at(0);
                    cocos2d::Sprite* pSprite = cocos2d::Sprite::create();
                    pSprite->setSpriteFrame(pFirstFrame->getSpriteFrame());
                    pSprite->runAction(RepeatForever::create(CCAnimate::create(pAnimation)));
                    pushTextRender(pSprite, true, nullptr);
                }
            }
		}
        break;
	}
	case CocosRichTextNodeType_ParseText:
	{
		if (p.HasMember(CocosRichJsonKey_ParseTextData)){
			const rapidjson::Value &keyvalue = p[CocosRichJsonKey_ParseTextData];
            if(!keyvalue.HasMember(CocosRichJsonKey_RootKey)){
                assert(0);
                break;
            }
            const rapidjson::Value& dataKey = keyvalue[CocosRichJsonKey_RootKey];
            //是否是数组  
            if(!dataKey.IsArray()){
                assert(0);
                break;
            }
            for(rapidjson::SizeType i = 0; i < dataKey.Size(); i++){
                const rapidjson::Value &pNext = dataKey[i];
                if(pNext.HasMember(CocosRichJsonKey_NodeTypeKey)){
                    const rapidjson::Value &typekeyEnt = pNext[CocosRichJsonKey_NodeTypeKey];
                    DealWithJson((CocosRichTextNodeType)typekeyEnt.GetInt(), pNext, pConfigFont);
                }
                else{
                    assert(0);
                }
			}
		}
        break;
	}
	case CocosRichTextNodeType_Type:
	{
		if (p.HasMember(CocosRichJsonKey_ExtRevertData)){
			std::string strText;
			std::string strLinkData;
			
			const rapidjson::Value &valueEnt = p[CocosRichJsonKey_ExtRevertData];
            //目前不做处理，还不需要扩展
		}
        break;
	}
	default:
		assert(0);
		break;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//绘制相关
void CCocosRichTextNode::addNewLine(){
	_leftSpaceWidth = _contentSize.width;
	_elementRenders.push_back(new cocos2d::Vector<cocos2d::Node*>());
}

//! 绘制文本
void CCocosRichTextNode::drawTextRender(const std::string& strText, CocosRichTextFontConfig* pConfigFont, const char* pLinkData){
    cocos2d::Label* pText = pConfigFont->CreateLabelByConfig(strText, 0);
    float textRendererWidth = pText->getContentSize().width;
    _leftSpaceWidth -= textRendererWidth;
    if(_leftSpaceWidth < 0.0f){
        float overstepPercent = (-_leftSpaceWidth) / textRendererWidth;
        size_t stringLength = StringUtils::getCharacterCountInUTF8String(strText);
        int leftLength = stringLength * (1.0f - overstepPercent);
        //The minimum cut length is 1, otherwise will cause the infinite loop.
        if(0 >= leftLength)
            leftLength = 1;
        std::string leftWords = cocos2d::ui::Helper::getSubStringOfUTF8String(strText, 0, leftLength);
        std::string cutWords = cocos2d::ui::Helper::getSubStringOfUTF8String(strText, leftLength, stringLength - leftLength);
        cocos2d::Label* pLeftText = pConfigFont->CreateLabelByConfig(leftWords, 0);
        float leftTextWidth = pLeftText->getContentSize().width;
        if(leftLength > 1 && leftTextWidth > _leftSpaceWidth + textRendererWidth){
            //这个时候需要做处理把多余的部分给后面的处理
            float fLeftPercent = (_leftSpaceWidth + textRendererWidth) / leftTextWidth;
            stringLength = StringUtils::getCharacterCountInUTF8String(leftWords);
            leftLength = stringLength * fLeftPercent;
            if(leftLength <= 0)
                leftLength = 1;
            cutWords = ui::Helper::getSubStringOfUTF8String(leftWords, leftLength, stringLength - leftLength) + cutWords;
            leftWords = ui::Helper::getSubStringOfUTF8String(leftWords, 0, leftLength);
            pLeftText = pConfigFont->CreateLabelByConfig(leftWords, 0);
        }
        pushTextRender(pLeftText, false, pLinkData);
        addNewLine();
        drawTextRender(cutWords, pConfigFont, pLinkData);
    }
    else{
        pushTextRender(pText, false, pLinkData);
    }
}

void CCocosRichTextNode::drawBGTextRender(const std::string& strText, CocosRichTextFontConfig* pConfigFont, const char* pBG, const char* pLinkData){
    cocos2d::SpriteFrame* pSpriteFrame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(pBG);
    if(nullptr == pSpriteFrame){
        assert(0);
        return;
    }
    cocos2d::Sprite* pImage = cocos2d::Sprite::createWithSpriteFrame(pSpriteFrame);
    cocos2d::Label* pLabel = pConfigFont->CreateLabelByConfig(strText, 0);
    pLabel->setHorizontalAlignment(TextHAlignment::CENTER);
    pLabel->setAnchorPoint(cocos2d::Vec2(0.5f, 0.5f));
    cocos2d::Vec2 vLastPos = pImage->getContentSize() / 2;
    pLabel->setPosition(vLastPos);
    pImage->addChild(pLabel);
    pushTextRender(pImage, true, pLinkData);
}

void CCocosRichTextNode::pushTextRender(Node* renderer, bool bCheckLength, const char* pLinkData){
	//加入之后判断是否有link信息
	if (pLinkData){
		renderer->setUserObject(cocos2d::CCString::create(pLinkData));
		m_clkEvent.pushBack(renderer);
	}
	if (bCheckLength){
		Size imgSize = renderer->getContentSize();
		_leftSpaceWidth -= imgSize.width;
		if (_leftSpaceWidth < 0.0f){
			addNewLine();
			pushToContainer(renderer);
			_leftSpaceWidth -= imgSize.width;
		}
		else{
			pushToContainer(renderer);
		}
	}
	else{
		pushToContainer(renderer);
	}
}

void CCocosRichTextNode::pushToContainer(cocos2d::Node* renderer){
    auto size = _elementRenders.size();
	if (size <= 0){
		assert(0);
		return;
	}
	_elementRenders[size - 1]->pushBack(renderer);
}
////////////////////////////////////////////////////////////////////////////////////////////
CCocosRichTextNodeForCocos::CCocosRichTextNodeForCocos(){
	m_bDirty = false;
}
CCocosRichTextNodeForCocos::~CCocosRichTextNodeForCocos(){
}

void CCocosRichTextNodeForCocos::visit(cocos2d::Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags){
	if (m_bDirty){
        initJsonData(m_strDatatext.c_str(), -1, -1);
		m_bDirty = false;
	}
	return CCocosRichTextNode::visit(renderer, parentTransform, parentFlags);
}

//设置换行间隔
void CCocosRichTextNodeForCocos::SetLineAddMinY(float fYAddLine){
	m_fLineAddMinY = fYAddLine;
	m_bDirty = true;
}
