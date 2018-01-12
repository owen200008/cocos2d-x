#ifndef COCOS_RICHTEXTNODE_H
#define COCOS_RICHTEXTNODE_H

#include "cocos2d.h"
#include "cocos-ext.h"
///////////////////////////////////////////////////////////////////////////////////////////

#define CocosRichTextKey_TextInfoSprite	'@'				//��ʽ@textcolor=FFE0D5BC@fontsize=24
#define CocosRichTextKey_TextColor		"textcolor"
#define CocosRichTextKey_FontSize		"fontsize"
#define CocosRichTextKey_OutLineColor	"outlinecolor"

#define CocosRichTextKey_ImageSprite	'#'
#define CocosRichTextKey_ExtInfoSprite	'!'				
#define CocosRichTextKey_ExtLinkData	"link"			//��ʽ&link[text=123&link=content&fontsize=24&textcolor=ffffffff]
#define CocosRichTextKey_ExtTextData	"text"
#define CocosRichTextKey_ExtTypeData	"type"

#define CocosRichJsonKey_RootKey		"data"
#define CocosRichJsonKey_NodeTypeKey	"typekey"
#define CocosRichJsonKey_ParseTextData	"keyvalue"
#define CocosRichJsonKey_ExtRevertData	"extdata"
#define CocosRichJsonKey_ImageValueData	"imgvalue"

enum CocosRichTextNodeType
{
	CocosRichTextNodeType_NewLine = 0,
	CocosRichTextNodeType_Text = 1,
	CocosRichTextNodeType_Img = 2,
	CocosRichTextNodeType_ParseText = 3,
	CocosRichTextNodeType_Type = 4,
	CocosRichTextNodeType_Link = 100,
	CocosRichTextNodeType_TextType = 101,
};

class CCocosRichTextNode_LinkDataDefault : public cocos2d::Ref
{
public:
	cocos2d::Node*	m_pClkNode;
	cocos2d::Touch* m_pTouch;
	CCocosRichTextNode_LinkDataDefault(cocos2d::Node* pClkNode, cocos2d::Touch* pTouch)
	{
		m_pClkNode = pClkNode;
		m_pTouch = pTouch;
	}
	cocos2d::Touch* GetTouch(){ return m_pTouch; }
	cocos2d::Node* GetClkNode(){ return m_pClkNode; }
};

enum CocosRichTextRevertDataDefine
{
	CocosRichTextRevertDataDefine_TouchBeginIndex = 1000,
};
#define CCocosRichTextNode_LinkDataDefaultMsg "CCocosRichTextNode_LinkDataDefaultMsg"

class CCocosRichTextNode;
typedef std::function<void(CCocosRichTextNode*, const char* pExtText, const char* pdefaultFontName, int ndefaultFontSize, const cocos2d::Color4B& defaultcolor)> GlobalCocosRichTextTypeCallback;
class CCocosRichTextNode : public cocos2d::Node
{
public:
	CCocosRichTextNode();
	virtual ~CCocosRichTextNode();

	CREATE_FUNC(CCocosRichTextNode);
	//��type��ȫ�ִ���ص�
	static void BindReaderTypeCallback(const GlobalCocosRichTextTypeCallback& callback);

	cocos2d::Value& GetNodeRevertValue(int nKey);
	//�¼��ڲ�����
	void SetTouchEnable(bool bTouchEnable);

	void initJsonData(const char* pShowInfo, const char* pDefaultFontName = nullptr, int nDefaultFontSize = 20, const char* pDefaultFontColor = nullptr, cocos2d::TextHAlignment hAlignment = cocos2d::TextHAlignment::LEFT, bool bVCenter = false);
	//������뷽ʽ
	void initDefaultString(const char* pShowInfo, const char* pDefaultFontName = nullptr, int nDefaultFontSize = 20, const char* pDefaultFontColor = nullptr, bool bCenter = false, bool bVCenter = false);
	void initString(const char* pShowInfo, const char* pDefaultFontName = nullptr, int nDefaultFontSize = 20, const char* pDefaultFontColor = nullptr, cocos2d::TextHAlignment hAlignment = cocos2d::TextHAlignment::LEFT, bool bVCenter = false);
	//����
	void initJsonNode(const rapidjson::Value& jsonValue, const char* pDefaultFontName = nullptr, int nDefaultFontSize = 20, const char* pDefaultFontColor = nullptr, cocos2d::TextHAlignment hAlignment = cocos2d::TextHAlignment::LEFT, bool bVCenter = false);
	//ѡ�еĴ���
	void TouchCocosRichText(cocos2d::Touch* pTouch);
protected:
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
	
protected:
	virtual void onEnter();
	virtual void resume(void);
	virtual void pause(void);
	//������
	void DealWithJson(CocosRichTextNodeType keyDefine, const rapidjson::Value& p, const char* pDefaultFontName, int nFontSize, const char* pDefaultFontColor);
public:
	//ֻ���ڻص��������
	void addNewLine();
	void handleNormalRenderer(Node* renderer, bool bCheckLength, const char* pLinkData);
	void handleTextRenderer(const std::string& strText, const char* pDefaultFontName, int nDefaultFontSize, const cocos2d::Color4B& fontColor, const char* pLinkData, const cocos2d::Color4B* pOutLineColor = nullptr);
protected:
	void pushToContainer(cocos2d::Node* renderer);
	void formarRenderers(cocos2d::TextHAlignment hAlignment, bool bVCenter = false);
	void DealWithString(const char* pShowInfo, const char* pDefaultFontName, int nDefaultFontSize, const char* pDefaultFontColor);
protected:
	cocos2d::Vector<Node*>									m_clkEvent;
	float													_leftSpaceWidth;
	std::vector<cocos2d::Vector<cocos2d::Node*>*>			_elementRenders;
	cocos2d::EventListenerTouchOneByOne*					m_touchListener;
	static GlobalCocosRichTextTypeCallback					m_globalFuncForType;
	bool													m_bSingleLine;
	float													m_realWidth;
	float													m_fLineAddMinY;
	cocos2d::ValueMapIntKey									m_mapRevertData;
};

class CCocosRichTextNodeForCocos : public CCocosRichTextNode
{
public:
	CCocosRichTextNodeForCocos();
	virtual ~CCocosRichTextNodeForCocos();

	CREATE_FUNC(CCocosRichTextNodeForCocos);

	std::string& GetDefaultFontName();
	void SetDefaultFontName(const char* pFontName);

	int GetDefaultFontSize();
	void SetDefaultFontSize(int nFontSize);

	std::string& GetDefaultFontColor();
	void SetDefaultFontColor(const char* pColor);

	bool GetBHCenter();
	void SetBHCenter(bool bCenter);
	cocos2d::TextHAlignment GetHorizontalAlignment();
	void SetHorizontalAlignment(cocos2d::TextHAlignment hAlignment);
	bool GetBVCenter();
	void SetBVCenter(bool bCenter);
	//�����Ƿ�����ʾ
	void SetSingleLine(bool bSingle);

	std::string& GetDataText();
	void SetDataText(const char* pDataText, bool bUpdate = false, bool bJson = false);
	//��ȡʵ�ʵ����ݿ��
	float GetRealContentWidth(){ return m_realWidth; }
	virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4 &parentTransform, uint32_t parentFlags);

	//���û��м��
	void SetLineAddMinY(float fYAddLine);
	float GetLineAddMinY(){ return m_fLineAddMinY; }
protected:
	std::string			m_strDefaultFontName;
	int					m_nDefaultFontSize;
	std::string			m_pstrDefaultFontColor;
	cocos2d::TextHAlignment	m_bCenter;
	bool				m_bVCenter;
	std::string			m_strDatatext;
	bool				m_bJson;
	bool				m_bDirty;
};

#endif