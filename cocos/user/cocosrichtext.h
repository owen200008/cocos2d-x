#ifndef COCOS_RICHTEXTNODE_H
#define COCOS_RICHTEXTNODE_H

#include "cocos2d.h"
#include "cocos-ext.h"
///////////////////////////////////////////////////////////////////////////////////////////
#define CocosRichJsonKey_RootKey		"data"
#define CocosRichJsonKey_NodeTypeKey	"typekey"

#define CocosRichJsonKey_Text           "text"              //1    
#define CocosRichJsonKey_Text_Type      "texttype"
#define CocosRichJsonKey_Text_Link      "textlink"
#define CocosRichJsonKey_Text_BG        "textbg"
#define CocosRichJsonKey_ImageValueData	"imgvalue"          //2
#define CocosRichJsonKey_ParseTextData	"keyvalue"          //3
#define CocosRichJsonKey_ExtRevertData	"extdata"           //4

enum CocosRichTextNodeType{
	CocosRichTextNodeType_NewLine = 0,
	CocosRichTextNodeType_Text = 1,
	CocosRichTextNodeType_Img = 2,
	CocosRichTextNodeType_ParseText = 3,
	CocosRichTextNodeType_Type = 4,
};
//////////////////////////////////////////////////////////////////////////////////////////////
//读取默认的配置
struct CC_DLL CocosRichTextFontConfig{
    CocosRichTextFontConfig(){
        m_nFontSize = 20;
        m_bOutlineColor = false;
        m_fontColor = cocos2d::Color4B::BLACK;
    }
    CocosRichTextFontConfig(const char* pDefaultFontName, int nDefaultFontSize, cocos2d::Color4B& defaultFontColor, bool bOutlineColor, cocos2d::Color4B& outlineColor){
        m_strFontName = pDefaultFontName;
        m_nFontSize = nDefaultFontSize;
        m_fontColor = defaultFontColor;
        m_bOutlineColor = m_bOutlineColor;
        m_outlineColor = outlineColor;
    }
    cocos2d::Label* CreateLabelByConfig(const std::string& text, int nDefaultFontSize);

    const std::string& GetFontName(){ return m_strFontName; }
    void SetFontName(const char* pFontName){
        m_strFontName = pFontName;
        m_funcCreateLabel = nullptr;
    }
    int GetFontSize(){ return m_nFontSize; }
    void SetFontSize(int nSize){
        m_nFontSize = nSize;
    }
    const cocos2d::Color4B& GetFontColor(){ return m_fontColor; }
    void SetFontColor(cocos2d::Color4B& color){
        m_fontColor = color;
    }
    bool GetDrawOutlineColor(){ return m_bOutlineColor; }
    void SetDrawOutlineColor(bool bSet){
        m_bOutlineColor = true;
    }
    const cocos2d::Color4B& GetOutlineColor(){ return m_outlineColor; }
    void SetOutlineColor(cocos2d::Color4B& color){
        m_outlineColor = color;
    }
protected:
    std::function<cocos2d::Label*(const std::string&, int)>  m_funcCreateLabel;

    std::string             m_strFontName;
    int                     m_nFontSize;
    cocos2d::Color4B        m_fontColor;
    bool                    m_bOutlineColor;
    cocos2d::Color4B        m_outlineColor;
};
typedef std::map<int, CocosRichTextFontConfig> MapCocosRichTextFontConfig;

struct CC_DLL CocosRichTextStyleConfig{
    cocos2d::TextHAlignment m_hAlignment;
    bool                    m_bVCenter;
    CocosRichTextStyleConfig(){
        m_hAlignment = cocos2d::TextHAlignment::LEFT;
        m_bVCenter = false;
    }
    CocosRichTextStyleConfig(cocos2d::TextHAlignment hAlignment, bool bVCenter){
        m_hAlignment = hAlignment;
        m_bVCenter = bVCenter;
    }
};
typedef std::map<int, CocosRichTextStyleConfig> MapCocosRichTextStyleConfig;
//////////////////////////////////////////////////////////////////////////////////////////////
//! 点击通知
#define CCocosRichTextNode_ClkNodeMsg "CCocosRichTextNode_ClkNodeMsg"

class CC_DLL CCocosRichTextNodeClkNotify : public cocos2d::Ref{
public:
	cocos2d::Node*	m_pClkNode;
	cocos2d::Touch* m_pTouch;
    CCocosRichTextNodeClkNotify(cocos2d::Node* pClkNode, cocos2d::Touch* pTouch){
		m_pClkNode = pClkNode;
		m_pTouch = pTouch;
	}
	cocos2d::Touch* GetTouch(){ return m_pTouch; }
	cocos2d::Node* GetClkNode(){ return m_pClkNode; }
};
//////////////////////////////////////////////////////////////////////////////////////////////

class CCocosRichTextNode;
typedef std::function<void(CCocosRichTextNode*, const char* pExtText, const char* pdefaultFontName, int ndefaultFontSize, const cocos2d::Color4B& defaultcolor)> GlobalCocosRichTextTypeCallback;
class CC_DLL CCocosRichTextNode : public cocos2d::Node{
public:
	CCocosRichTextNode();
	virtual ~CCocosRichTextNode();

	CREATE_FUNC(CCocosRichTextNode);

    //! 设置全局的默认配置
    static void RegisterStyleConfig(int nIndex, CocosRichTextStyleConfig& config);
    static void RegisterFontConfig(int nIndex, CocosRichTextFontConfig& config);

    //! 获取表情
    static void SetAnimationFormat(const char* pFormat);

    //!
    virtual CocosRichTextStyleConfig* GetStyleConfig(int nIndex);
    virtual CocosRichTextFontConfig* GetFontConfig(int nIndex);

    //! 事件内部驱动
    void SetTouchEnable(bool bTouchEnable);

    //! 显示
    void initJsonData(const char* pShowInfo, int nFontIndex, int nStyleIndex);
	void initJsonNode(const rapidjson::Value& jsonValue, int nFontIndex, int nStyleIndex);
protected:
    //! 解决颜色叠加问题
    virtual void onEnter();

    //! 可见区域才需要显示动画
    virtual void resume(void);
    virtual void pause(void);

    //! 点击处理
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unusedEvent);
	
    //! 根据touch获取选中的index
    int16_t GetTouchNodeIndex(cocos2d::Touch* pTouch);
    //! 验证是否是这个index
    bool IsTouchIndexNode(cocos2d::Touch* pTouch, int16_t nIndex);
protected:
    //处理函数
    void DealWithJson(CocosRichTextNodeType keyDefine, const rapidjson::Value& p, CocosRichTextFontConfig* pConfigFont);

	//! 换行
	void addNewLine();

    //! 绘制文本
    void drawTextRender(const std::string& strText, CocosRichTextFontConfig* pConfigFont, const char* pLinkData);
    void drawBGTextRender(const std::string& strText, CocosRichTextFontConfig* pConfigFont, const char* pBG, const char* pLinkData);
protected:
	void pushTextRender(Node* renderer, bool bCheckLength, const char* pLinkData);

    //! 加入到对应的队列
    void pushToContainer(cocos2d::Node* renderer);

    //! 格式化
    void formatRenderers(CocosRichTextStyleConfig* pCofingStyle);
protected:
    static MapCocosRichTextStyleConfig                      m_mapStyleConfig;
    static MapCocosRichTextFontConfig                       m_mapFontConfig;
    static std::string                                      m_animationFormat;
    //! 支持事件的节点
	cocos2d::Vector<Node*>									m_clkEvent;
    //! 所有的节点
    std::vector<cocos2d::Vector<cocos2d::Node*>*>			_elementRenders;
    //! 监听事件
    cocos2d::EventListenerTouchOneByOne*					m_touchListener;
    //! 保存一行剩余的长度
	float													_leftSpaceWidth;
    //! 单行显示
	bool													m_bSingleLine;
    //! 获取实际长度
	float													m_realWidth;
    //! 设置换行间隔
	float													m_fLineAddMinY;             
    //! 点击的控件索引
    int16_t                                                 m_nTouchIndex;
    //! 字体类型选择
    int                                                     m_nFontChoose;
    //! style选择
    int                                                     m_nStyleChoose;
};

class CC_DLL CCocosRichTextNodeForCocos : public CCocosRichTextNode
{
public:
	CCocosRichTextNodeForCocos();
	virtual ~CCocosRichTextNodeForCocos();

	CREATE_FUNC(CCocosRichTextNodeForCocos);

    virtual CocosRichTextStyleConfig* GetStyleConfig(int nIndex){
        if(nIndex < 0)
            return &m_StyleConfig;
        return CCocosRichTextNode::GetStyleConfig(nIndex);
    }
    virtual CocosRichTextFontConfig* GetFontConfig(int nIndex){
        if(nIndex < 0)
            return &m_FontConfig;
        return CCocosRichTextNode::GetFontConfig(nIndex);
    }

    const std::string& GetFontName(){
        return m_FontConfig.GetFontName();
    }
    void SetFontName(const char* pFontName){
        m_FontConfig.SetFontName(pFontName);
        m_bDirty = true;
    }

    int GetFontSize(){
        return m_FontConfig.GetFontSize();
    }
    void SetFontSize(int nFontSize){
        m_FontConfig.SetFontSize(nFontSize);
        m_bDirty = true;
    }

    std::string GetFontColor(){
        char szBuf[16] = { 0 };
        std::string strRet;
        const cocos2d::Color4B& ret = m_FontConfig.GetFontColor();
        sprintf(szBuf, "%x%x%x%x", ret.a, ret.r, ret.g, ret.b);
        return szBuf;
    }
    void SetFontColor(const char* pColor){
        cocos2d::Color4B setColor;
        unsigned long nSetColor = strtoll(pColor, NULL, 16);
        setColor.a = (nSetColor >> 24) & 0xFF;
        setColor.r = (nSetColor >> 16) & 0xFF;
        setColor.g = (nSetColor >> 8) & 0xFF;
        setColor.b = nSetColor & 0xFF;
        m_FontConfig.SetFontColor(setColor);
        m_bDirty = true;
    }

    bool GetBHCenter(){
        return m_StyleConfig.m_hAlignment == cocos2d::TextHAlignment::CENTER;
    }
    void SetBHCenter(bool bCenter){
        m_StyleConfig.m_hAlignment = bCenter ? cocos2d::TextHAlignment::CENTER : cocos2d::TextHAlignment::LEFT;
        m_bDirty = true;
    }
    cocos2d::TextHAlignment GetHorizontalAlignment(){
        return m_StyleConfig.m_hAlignment;
    }
    void SetHorizontalAlignment(cocos2d::TextHAlignment hAlignment){
        m_StyleConfig.m_hAlignment = hAlignment;
        m_bDirty = true;
    }
    bool GetBVCenter(){
        return m_StyleConfig.m_bVCenter;
    }
    void SetBVCenter(bool bCenter){
        m_StyleConfig.m_bVCenter = bCenter;
        m_bDirty = true;
    }
	//设置是否单行显示
    void SetSingleLine(bool bSingle){
        m_bSingleLine = bSingle;
        m_bDirty = true;
    }

    std::string& GetDataText(){
        return m_strDatatext;
    }

    void SetDataText(const char* pDataText, bool bUpdate = false){
        m_strDatatext = "{\"data\":[{\"typekey\":1,\"text\":\"";
        m_strDatatext += pDataText;
        m_strDatatext += "\"}]}";
        m_bDirty = true;
        if(bUpdate){
            initJsonData(m_strDatatext.c_str(), -1, -1);
            m_bDirty = false;
        }
    }
    void SetDataTextJson(const char* pDataText, bool bUpdate = false){
        m_strDatatext = pDataText;
        m_bDirty = true;
        if(bUpdate){
            initJsonData(m_strDatatext.c_str(), -1, -1);
            m_bDirty = false;
        }
    }

	//获取实际的内容宽度
	float GetRealContentWidth(){ return m_realWidth; }
	virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4 &parentTransform, uint32_t parentFlags);

	//设置换行间隔
	void SetLineAddMinY(float fYAddLine);
	float GetLineAddMinY(){ return m_fLineAddMinY; }
protected:
    CocosRichTextStyleConfig    m_StyleConfig;
    CocosRichTextFontConfig     m_FontConfig;
    bool                        m_bDirty;
    std::string                 m_strDatatext;
};

#endif