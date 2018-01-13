require "app.data.luanetmgr_data"
require "app.data.inc.luaontimermgr"
require "app.data.cocos.userdefaultcfg"
cc.exports.LuaNetPool = {}

function LuaNetPool:Init()
  if self.m_bInitNet then
    return
  end
  self.m_bInitNet = true
  --初始化网络
  LUA_NetManager:Init()
  LuaUserDefaultCFG:Init()
end

return LuaNetPool