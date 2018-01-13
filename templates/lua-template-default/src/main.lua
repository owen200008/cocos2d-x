--视图句柄
g_Director = cc.Director:getInstance()
--保存文件操作句柄
g_FileUtils = cc.FileUtils:getInstance()
--资源缓存句柄
g_SpriteFrameCache = SpriteFrameCache_XiaKe:getInstanceXiaKe()
--资源目录
g_resourcePath = ProjectLua.GetProjectResourcePath()
--执行目录
g_strModulePath = BasicGetModulePath()
--导出错误消息
g_exportLogError = function(msg)
    BasicLogEventError(msg)
end
--获取更新目录
function GetUpdatePath()
    return g_resourcePath
end
--获取资源目录
function GetResourcePath()
    return g_resourcePath
end
--获取日志目录
function GetLogPath()
  return g_resourcePath.."log/"
end

--回调self
function HandleMethod(obj, method)
    return function(...)
        return method(obj, ...)
    end
end

--第一次进来加载的view
g_firstLoadView = "login"
--主view
g_mainLoadView = "login"
--更新完成重新加载lua文件
g_reloadfile="main"

g_FileUtils:setPopupNotify(false)
require "config"
require "cocos.init"

require "app.data.luadatapoolinterface"
require "app.data.luanetmgr"
require "app.data.stringdefine"

cc.enable_global()
if m_pSqliteConfigDB == nil then
  m_pSqliteConfigDB = CCQLite3DB.new()
  if m_pSqliteConfigDB:Open(GetResourcePath().."configdata.sdata", "czq(cbx&cfy)cjw*zhy%zyl$gys!cgmd", 32) == false then
    local errorInfo = m_pSqliteConfigDB:GetLastError()
    BasicLogEventError(errorInfo)
  end
end
m_systemconfig=G_SQLITE_OPER:LoadSystemConfig()

if LuaDataPool:GetSysConfigByKey(G_SYSTEMCONFIG_TYPEDEFINE.G_SYSTEMCONFIG_TYPEDEFINE_TiaoShiEnable, G_SYSTEMCONFIG_Default_TiaoShiEnable) then
  local tiaoshiaddress = LuaDataPool:GetSysConfigByKey(G_SYSTEMCONFIG_TYPEDEFINE.G_SYSTEMCONFIG_TYPEDEFINE_TiaoShiAddress, G_SYSTEMCONFIG_Default_TiaoShiAddress)
  require("mobdebug").start(tiaoshiaddress)
  require("mobdebug").coro()
end
cc.disable_global()

--连接地址
cc.exports.G_ConnectServerAddress="fantiejia.com:1443"

local function main()
    --check程序是否更新
    if cc.exports.m_bIsUpdateFinish == nil then
      ProjectLua.CheckUpdateExeP()
    end

    math.randomseed(tostring(os.time()):reverse():sub(1, 7))
    --把resource目录加到搜索目录,优先从resource搜索
    g_FileUtils:addSearchPath(GetResourcePath(), true)

    cc.exports.GlobalAppBaseRetain=nil
    g_Director:setProjection(kCCDirectorProjection2D)
    
    ProjectLua.StartFirstInitData()
    LuaDataPool:InitLuaDataPool()
    cc.exports.GlobalAppBaseRetain=require("app.MyApp"):create()
    cc.exports.GlobalWinSizeRetain=g_Director:getWinSize()
    LuaDataPool:SetCppVersion(ProjectLua.GetProjectVersionCpp())
    if g_firstLoadView then
      GlobalAppBaseRetain:run(g_firstLoadView)
      g_firstLoadView = nil
    else
      GlobalAppBaseRetain:run(g_mainLoadView)
    end
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    g_exportLogError(msg)
    print(msg)
end
