require "app.data.luadatapool"
cc.enable_global()
local socket = require "socket"
cc.disable_global()

function LuaDataPool:SetResVersion(version) self.m_resversion = version end
function LuaDataPool:GetResVersion()
  if self.m_resversion == nil then
    self.m_resversion = "1.0.0.0"
  end
  return self.m_resversion
end

--设置数据库接口
function LuaDataPool:SetSystemConfig(key, value, typevalue)
  m_systemconfig[key] = G_SQLITE_OPER:LoadValueByValueType(tostring(value), typevalue)
  G_SQLITE_OPER:UpdateOrInsertConfig(key, value, typevalue)
end

--sysconfig
function LuaDataPool:GetSysConfigByKey(key, defaultvalue) 
  if m_systemconfig[key] ~= nil then
    return m_systemconfig[key]
  end
  return defaultvalue
end

--是否调试
function LuaDataPool:SetTiaoShiState(bEnable, strAddress)
  m_systemconfig[G_SYSTEMCONFIG_TYPEDEFINE.G_SYSTEMCONFIG_TYPEDEFINE_TiaoShiEnable] = bEnable
  m_systemconfig[G_SYSTEMCONFIG_TYPEDEFINE.G_SYSTEMCONFIG_TYPEDEFINE_TiaoShiAddress] = strAddress
  self:SetSystemConfig(G_SYSTEMCONFIG_TYPEDEFINE.G_SYSTEMCONFIG_TYPEDEFINE_TiaoShiEnable, bEnable, 2)
  self:SetSystemConfig(G_SYSTEMCONFIG_TYPEDEFINE.G_SYSTEMCONFIG_TYPEDEFINE_TiaoShiAddress, strAddress, 0)
end

--计算整数数字显示
function LuaDataPool:ShowTextByNumber(nNumber)
  if nNumber < 10000 then
    return tostring(nNumber)
  elseif nNumber < 10000000 then
    if nNumber % 10000 == 0 then
      return string.format(Global_XMStringDefine:GetErrorID(33), math.floor(nNumber / 10000))
    else
      return string.format(Global_XMStringDefine:GetErrorID(34), nNumber / 10000)
    end
  elseif nNumber < 100000000 then
    if nNumber % 10000 == 0 then
      return string.format(Global_XMStringDefine:GetErrorID(33), math.floor(nNumber / 10000))
    else
      return string.format(Global_XMStringDefine:GetErrorID(35), nNumber / 10000)
    end
  elseif nNumber < 100000000000 then
    if nNumber % 100000000 == 0 then
      return string.format(Global_XMStringDefine:GetErrorID(36), math.floor(nNumber / 100000000))
    else
      return string.format(Global_XMStringDefine:GetErrorID(37), nNumber / 100000000)
    end
  elseif nNumber < 1000000000000 then
    if nNumber % 100000000 == 0 then
      return string.format(Global_XMStringDefine:GetErrorID(36), math.floor(nNumber / 100000000))
    else
      return string.format(Global_XMStringDefine:GetErrorID(38), nNumber / 100000000)
    end
  end
  return string.format(Global_XMStringDefine:GetErrorID(39), math.floor(nNumber / 1000000000000))
end

--播放音效
function LuaDataPool:Play2DSound(nIndex, loop, volume)
  local soundinfo = G_MusicFile[nIndex]
  if soundinfo then
    loop = loop or soundinfo.default_loop
    volume = volume or soundinfo.default_vol
    if LuaDataPool:GetSysConfigByKey(G_SYSTEMCONFIG_TYPEDEFINE.G_SYSTEMCONFIG_TYPEDEFINE_OpenSound, true) then
      ccexp.AudioEngine:play2d(soundinfo.file, loop, volume)
    end
  end
end

return LuaDataPool