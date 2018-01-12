#ifndef XIAKE_CSTMXMAP_H
#define XIAKE_CSTMXMAP_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
////////////////////////////////////////////////////////////////////////////////////////////////////
//地图管理
struct MapTMXCache{
    std::map<std::string, std::string>		m_mapRes;
};
typedef std::map<std::string, MapTMXCache>	    MapTMXConfig;
////////////////////////////////////////////////////////////////////////////////////////////////////
class CMapTMXCache{
public:
    static CMapTMXCache* GetInstance();

protected:
    CMapTMXCache();
    virtual ~CMapTMXCache();

    //! bind read resourceset func
    bool InitMapTMXCache(const std::function<bool(const char* pMapName, std::string& strResourceset)>& func);

    //! create map
    cocos2d::experimental::TMXTiledMap* GetTMXMap(const char* pFileName);

    //! 加载单个纹理
    cocos2d::Texture2D* GetTexture2DCacheByFiles(const char* pListFiles, bool bAddCache = false);

    //! 预加载纹理,','分割
    void PreLoadTexture2DCache(const char* pFiles, bool bAddCache);
protected:
    std::function<bool(const char* pMapName, std::string& strResourceset)> m_readFunc;
    ////////////////////////////////////////////////////////////////////
    //客户端缓存的管理
    MapTMXConfig        m_MapConfig;
};


#endif