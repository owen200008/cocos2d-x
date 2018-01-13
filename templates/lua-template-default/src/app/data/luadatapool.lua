require "app.data.dbset"
require "app.data.dboper"
require "app.data.inc.coroutinecontextmgr"

cc.exports.LuaDataPool = {}

cc.exports.LuaResponseMsg = {

  Lua_ResponseMessage_NetStateChange = 0xFE,        --网络切换
  Lua_ResponseMessage_NetMsg = 0xFF,                --网络消息
}

function LuaDataPool:InitLuaDataPool()
end

function LuaDataPool:ReInitLuaDataPool()
  
end

function LuaDataPool:SendLuaEvent(msg, userData, secondmsg)
    if secondmsg then
        userData._luaResponseSecondMsg = secondmsg
    end
    return GlobalAppBaseRetain:DispatchMsg(msg, userData)
end
-----------------------------------------------------------------------------------------
function LuaDataPool:InitLuaResourcePool()
end

function LuaDataPool:ReInitLuaResourcePool()
    self.m_pbzk = CPBZK.new()
    local strData = g_FileUtils:getDataFromFile("res/pbzk.txt")
    if strData then
      self.m_pbzk:ReadPBZK(strData)
    end
end

function LuaDataPool:IsContainPBZK(str)
  if self.m_pbzk then
    return self.m_pbzk:IsContainPBZK(str, str:len(), false, true)
  end
  return true
end
-----------------------------------------------------------------------------------------
--检查手机号
function LuaDataPool:CheckIsMobile(str)
  return string.match(str,"[1]%d%d%d%d%d%d%d%d%d%d") == str
end
-----------------------------------------------------------------------------------------
local function CalcRichTextHeightToScrollView_(pScrollView, pTextConrol, pEnterText)
  pTextConrol:SetDataText(pEnterText, true)
  local totalsize = pTextConrol:getContentSize()

	pScrollView:setInnerContainerSize(totalsize)
	local scroll = pScrollView:getContentSize()
	pTextConrol:setPosition(cc.p(0.0, pScrollView:getInnerContainerSize().height))
end
cc.exports.CalcRichTextHeightToScrollView=CalcRichTextHeightToScrollView_

return LuaDataPool
