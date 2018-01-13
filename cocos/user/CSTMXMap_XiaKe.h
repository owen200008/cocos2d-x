#ifndef XIAKE_CSTMXMAP_H
#define XIAKE_CSTMXMAP_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
////////////////////////////////////////////////////////////////////////////////////////////////////
//地图管理
struct CC_DLL MapTMXCache{
    std::map<std::string, std::string>		m_mapRes;
};
typedef std::map<std::string, MapTMXCache>	    MapTMXConfig;
////////////////////////////////////////////////////////////////////////////////////////////////////
class CC_DLL CMapTMXCache{
public:
    static CMapTMXCache* GetInstance();

    //! bind read resourceset func "|="分割 
    void InitMapTMXCache(const std::function<bool(const char* pMapName, std::string& strResourceset)>& func);

    //! create map
    cocos2d::experimental::TMXTiledMap* GetTMXMap(const char* pFileName);

    //! 加载单个纹理
    cocos2d::Texture2D* GetTexture2DCacheByFiles(const char* pListFiles, bool bAddCache = false);

    //! 预加载纹理,','分割
    void PreLoadTexture2DCache(const char* pFiles, bool bAddCache);

    //! 最好是1秒一次
    void OnTimer(int nTick);
public:
    //! 往节点增加noupdate Component
    static void AddNoUpdateCompent(cocos2d::Node* pNode, cocos2d::Component* pComponent);

    //! 增加延迟释放的节点
    void AddClearNode(cocos2d::Node* pNode);
    void AddClearNodeChilds(cocos2d::Node* pNode);
    void AddClearNodeChildsListView(cocos2d::ui::ListView* pListView);
    void AddClearNodeChildsPageView(cocos2d::ui::PageView* pPageView);

    //! 设置node显示状态
    void SetNodeNormalState(cocos2d::Node* pNode, bool bNormal);
    bool IsNodeNormalState(cocos2d::Node* pNode);

    //! 提供快速增加设置大小
    void AddContentWidthHeight(cocos2d::Node* pNode, float fAddWidth, float fAddHeight);
protected:
    CMapTMXCache();
    virtual ~CMapTMXCache();

protected:
    std::function<bool(const char* pMapName, std::string& strResourceset)> m_readFunc;
    ////////////////////////////////////////////////////////////////////
    //客户端缓存的管理
    MapTMXConfig        m_MapConfig;

    //定时清除的节点
    cocos2d::Vector<cocos2d::Node*>				m_vtRetainChild;
    cocos2d::Vector<cocos2d::Node*>				m_vtNewAddRetainChild;
};


#endif