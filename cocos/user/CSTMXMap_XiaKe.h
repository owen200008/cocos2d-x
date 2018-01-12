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
protected:
    CMapTMXCache();
    virtual ~CMapTMXCache();
protected:
    std::function<bool(const char* pMapName, std::string& strResourceset)> m_readFunc;
    ////////////////////////////////////////////////////////////////////
    //�ͻ��˻���Ĺ���
    MapTMXConfig        m_MapConfig;
};


#endif