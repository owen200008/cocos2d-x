#ifndef XIAKE_CSTMXMAP_H
#define XIAKE_CSTMXMAP_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
////////////////////////////////////////////////////////////////////////////////////////////////////
//��ͼ����
struct CC_DLL MapTMXCache{
    std::map<std::string, std::string>		m_mapRes;
};
typedef std::map<std::string, MapTMXCache>	    MapTMXConfig;
////////////////////////////////////////////////////////////////////////////////////////////////////
class CC_DLL CMapTMXCache{
public:
    static CMapTMXCache* GetInstance();

    //! bind read resourceset func "|="�ָ� 
    void InitMapTMXCache(const std::function<bool(const char* pMapName, std::string& strResourceset)>& func);

    //! create map
    cocos2d::experimental::TMXTiledMap* GetTMXMap(const char* pFileName);

    //! ���ص�������
    cocos2d::Texture2D* GetTexture2DCacheByFiles(const char* pListFiles, bool bAddCache = false);

    //! Ԥ��������,','�ָ�
    void PreLoadTexture2DCache(const char* pFiles, bool bAddCache);

    //! �����1��һ��
    void OnTimer(int nTick);
public:
    //! ���ڵ�����noupdate Component
    static void AddNoUpdateCompent(cocos2d::Node* pNode, cocos2d::Component* pComponent);

    //! �����ӳ��ͷŵĽڵ�
    void AddClearNode(cocos2d::Node* pNode);
    void AddClearNodeChilds(cocos2d::Node* pNode);
    void AddClearNodeChildsListView(cocos2d::ui::ListView* pListView);
    void AddClearNodeChildsPageView(cocos2d::ui::PageView* pPageView);

    //! ����node��ʾ״̬
    void SetNodeNormalState(cocos2d::Node* pNode, bool bNormal);
    bool IsNodeNormalState(cocos2d::Node* pNode);

    //! �ṩ�����������ô�С
    void AddContentWidthHeight(cocos2d::Node* pNode, float fAddWidth, float fAddHeight);
protected:
    CMapTMXCache();
    virtual ~CMapTMXCache();

protected:
    std::function<bool(const char* pMapName, std::string& strResourceset)> m_readFunc;
    ////////////////////////////////////////////////////////////////////
    //�ͻ��˻���Ĺ���
    MapTMXConfig        m_MapConfig;

    //��ʱ����Ľڵ�
    cocos2d::Vector<cocos2d::Node*>				m_vtRetainChild;
    cocos2d::Vector<cocos2d::Node*>				m_vtNewAddRetainChild;
};


#endif