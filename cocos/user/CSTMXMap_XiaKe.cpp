#include "CSTMXMap_XiaKe.h"
#include "CCSpriteFrameCache_XiaKe.h"
#include "CSLoader_XiaKe.h"

template<class Functor>
void SpliteStringForCocos(const char* p, char cTok, Functor func){
    char* pAllocate = _strdup(p);
    char* pFirst = pAllocate;
    char* e = pAllocate;
    do{
        e = (char*)strchr(pFirst, cTok);
        if(e != NULL)
            *e++ = 0;
        func(pFirst);
        pFirst = e;
    } while(pFirst != NULL);
    free(pAllocate);
}

static CMapTMXCache* g_pCache = nullptr;
CMapTMXCache* CMapTMXCache::GetInstance(){
    if(g_pCache)
        return g_pCache;
    g_pCache = new CMapTMXCache();
    return g_pCache;
}

CMapTMXCache::CMapTMXCache(){

}

CMapTMXCache::~CMapTMXCache(){

}

//! bind read resourceset func
void CMapTMXCache::InitMapTMXCache(const std::function<bool(const char* pMapName, std::string& strResourceset)>& func){
    cocos2d::experimental::TMXTiledMap::bindPListCallback([&](std::string& strName, std::string& strKey, cocos2d::Texture2D*& bLocal) -> bool{
        auto iter = m_MapConfig.find(strName.c_str());
        if(iter == m_MapConfig.end()){
            return false;
        }

        auto iterKey = iter->second.m_mapRes.find(strKey.c_str());
        if(iterKey == iter->second.m_mapRes.end()){
            iterKey = iter->second.m_mapRes.find("main");
            if(iterKey == iter->second.m_mapRes.end())
                return false;
        }
        bLocal = GetTexture2DCacheByFiles(iterKey->second.c_str());
        return true;
    });
    m_readFunc = func;
    cocos2d::SpriteFrameCache::setCreateFunc([&](cocos2d::SpriteFrameCache*& pPoint, bool bCreate)->void{
        if(bCreate)
            pPoint = new cocos2d::SpriteFrameCache_XiaKe();
        else
            CC_SAFE_RELEASE_NULL(pPoint);
    });
    cocos2d::CSLoader::setCreateFunc([&](cocos2d::CSLoader*& pPoint, bool bCreate)->void{
        if(bCreate)
            pPoint = new CSLoader_XiaKe();
        else
            CC_SAFE_DELETE(pPoint);
    });
}
//! create map
cocos2d::experimental::TMXTiledMap* CMapTMXCache::GetTMXMap(const char* pFileName){
    MapTMXCache* pMapCache = nullptr;
    auto iter = m_MapConfig.find(pFileName);
    if(iter == m_MapConfig.end() && m_readFunc != nullptr){
        std::string strResourceset;
        if(m_readFunc(pFileName, strResourceset)){
            pMapCache = &(m_MapConfig[pFileName]);
            SpliteStringForCocos(strResourceset.c_str(), '|', [&](const char* pItem){
                const char* pRevertRes[2] = { 0 };
                int nIndex = 0;
                SpliteStringForCocos(pItem, '=', [&](const char* pRes){
                    if(nIndex < 2)
                        pRevertRes[nIndex] = pRes;
                    nIndex++;
                });
                if(nIndex < 2){
                    return;
                }
                pMapCache->m_mapRes[pRevertRes[0]] = pRevertRes[1];
            });
        }
    }
    else{
        pMapCache = &iter->second;
    }
    return cocos2d::experimental::TMXTiledMap::create(pFileName);
}

//! 加载单个纹理
cocos2d::Texture2D* CMapTMXCache::GetTexture2DCacheByFiles(const char* pListFiles, bool bAddCache){
    cocos2d::SpriteFrameCache_XiaKe* pCache = (cocos2d::SpriteFrameCache_XiaKe*)cocos2d::CCSpriteFrameCache::getInstance();
    cocos2d::Texture2D* pRetTexture = NULL;
    //在按&符号分割,8888,4444,5551,565
    cocos2d::Texture2D::PixelFormat defaultPixdelFormat = cocos2d::Texture2D::getDefaultAlphaPixelFormat();
    const char* pRevertRes[2] = { 0 };
    int nIndex = 0;
    SpliteStringForCocos(pListFiles, '&', [&](const char* pRes){
        if(nIndex < 2)
            pRevertRes[nIndex] = pRes;
        nIndex++;
    });
    if(nIndex > 1){
        int nModeValue = atol(pRevertRes[1]);
        if(nModeValue == 8888)
            cocos2d::Texture2D::setDefaultAlphaPixelFormat(cocos2d::Texture2D::PixelFormat::RGBA8888);
        else if(nModeValue == 4444)
            cocos2d::Texture2D::setDefaultAlphaPixelFormat(cocos2d::Texture2D::PixelFormat::RGBA4444);
        else if(nModeValue == 565)
            cocos2d::Texture2D::setDefaultAlphaPixelFormat(cocos2d::Texture2D::PixelFormat::RGB565);
        else if(nModeValue == 5551)
            cocos2d::Texture2D::setDefaultAlphaPixelFormat(cocos2d::Texture2D::PixelFormat::RGB5A1);
    }
    pRetTexture = pCache->addSpriteFramesWithPlistFile(pRevertRes[0], bAddCache);

    cocos2d::Texture2D::setDefaultAlphaPixelFormat(defaultPixdelFormat);
    return pRetTexture;
}

//! 预加载纹理
void CMapTMXCache::PreLoadTexture2DCache(const char* pFiles, bool bAddCache){
    SpliteStringForCocos(pFiles, ',', [&](const char* pItem){
        GetTexture2DCacheByFiles(pItem, bAddCache);
    });
}

//! 往节点增加noupdate Component
void CMapTMXCache::AddNoUpdateCompent(cocos2d::Node* pNode, cocos2d::Component* pComponent){
    pNode->addComponentNoUpdate(pComponent);
}

//增加延迟释放的节点
void CMapTMXCache::AddClearNode(cocos2d::Node* pNode){
    m_vtNewAddRetainChild.pushBack(pNode);
}
void CMapTMXCache::AddClearNodeChilds(cocos2d::Node* pNode){
    for(const auto &obj : pNode->getChildren()){
        m_vtNewAddRetainChild.pushBack(obj);
    }
}
void CMapTMXCache::AddClearNodeChildsListView(cocos2d::ui::ListView* pListView){
    for(const auto &obj : pListView->getItems()){
        m_vtNewAddRetainChild.pushBack(obj);
    }
    pListView->removeAllItems();
}
void CMapTMXCache::AddClearNodeChildsPageView(cocos2d::ui::PageView* pPageView){
    for(const auto &obj : pPageView->getPages()){
        m_vtNewAddRetainChild.pushBack(obj);
    }
    pPageView->removeAllPages();
}

//! 最好是1秒一次
void CMapTMXCache::OnTimer(int nTick){
    m_vtRetainChild.clear();
    std::swap(m_vtRetainChild, m_vtNewAddRetainChild);
}
