cc.exports.G_SQLITE_OPER = {}
------------------------------------------------------------------------------------------
cc.exports.G_SYSTEMCONFIG_TYPEDEFINE={
  G_SYSTEMCONFIG_TYPEDEFINE_TiaoShiEnable = 1,      --开启调试
  G_SYSTEMCONFIG_TYPEDEFINE_TiaoShiAddress = 2,     --调试地址
}
cc.exports.G_SYSTEMCONFIG_Default_TiaoShiEnable = true
cc.exports.G_SYSTEMCONFIG_Default_TiaoShiAddress = "127.0.0.1"

--系统设置初始化
function G_SQLITE_OPER:LoadValueByValueType(value, systemvaluetype)
  if systemvaluetype == 1 then
    return tonumber(value)
  elseif systemvaluetype == 2 then
    return value == "true"
  end
  return value
end
function G_SQLITE_OPER:LoadSystemConfig()
  local systemConfig = {}
  local sql = "select * from systemconfig"
  local data = m_pSqliteConfigDB:QueryTotalData(sql)
  if data then
    for key, value in pairs(data) do
      local systemvalue = value["systemvalue"]
      local systemvaluetype = tonumber(value["valuetype"])
      systemConfig[tonumber(value["systemtype"])] = self:LoadValueByValueType(systemvalue, systemvaluetype)
    end
  end
  return systemConfig
end

function G_SQLITE_OPER:UpdateOrInsertConfig(systemtype, value, valuetype)
  local sql = string.format("update systemconfig set systemvalue = '%s', valuetype = %d where systemtype = %d", tostring(value), valuetype, systemtype)
  local retData = m_pSqliteConfigDB:ExecSQL(sql)
  if retData > 0 then
    return
  end
  sql = string.format("insert into systemconfig(systemtype, systemvalue, valuetype) values(%d, '%s', %d)", systemtype, tostring(value), valuetype)
  m_pSqliteConfigDB:ExecSQL(sql)
end
----------------------------------------------------------------------------------------------------------------------------------------------------------------
--重置所有数据
function G_SQLITE_OPER:DropAllData()
  local sql = "delete from systemconfig"
  m_pSqliteConfigDB:ExecSQL(sql)
end

return G_SQLITE_OPER
