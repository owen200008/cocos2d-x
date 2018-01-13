require "app.data.inc.luaontimermgr"

local unpack = table.unpack or unpack

cc.exports.CoroutineContextMgr = {}
CoroutineContextMgr.m_Context = {}
CoroutineContextMgr.m_autoKey = 0
LuaOnTimerMgr:AddTimer(1.0, function()
      CoroutineContextMgr:OnTimer()
    end)
function CoroutineContextMgr:OnTimer()
    local localtime = os.time()
    local vtWakeupContext = {}
    for key, context in pairs(self.m_Context) do
      --只检查第一个
      if context.m_timeout and context.m_timeout > 0 then
          if localtime > context.m_timeout then
            --超时
            table.insert(vtWakeupContext, key)
          end
      end
    end
    for _,valueskey in pairs(vtWakeupContext) do
      self:WakeUpKey(valueskey, nil, false)
    end
end

function CoroutineContextMgr:WakeUpKey(key, resumeName, success, ...)
  local context = self.m_Context[key]
  if context then
    if coroutine.running() == context.m_co then
      context.m_mapResumeName[resumeName] = { ... }
    else
      if context.m_strWaitName == resumeName or resumeName == nil then
        context.m_timeout = nil
        return true, coroutine.resume(context.m_co, success, ...)
      else
        context.m_mapResumeName[resumeName] = { ... }
      end
    end
  end
  return false
end

function CoroutineContextMgr:CreateCo(key, func, deadFunc)
  local co = coroutine.create(function(nKey)
        xpcall(func, __G__TRACKBACK__, nKey)
        if deadFunc then
          xpcall(deadFunc, __G__TRACKBACK__)
        end
        self.m_Context[key] = nil
      end)
  self.m_Context[key] = {m_co = co, m_mapResumeName = {}}
  return coroutine.resume(co, key)
end

function CoroutineContextMgr:CreateCoAutoKey(func, deadFunc)
  self.m_autoKey = self.m_autoKey + 1
  return self:CreateCo(self.m_autoKey % 0xFFFFFFFF, func, deadFunc)
end

function CoroutineContextMgr:WaitCo(key, waitname, nTimeOut, ...)
  local context = self.m_Context[key]
  if context.m_mapResumeName[waitname] then
    local tableRet = context.m_mapResumeName[waitname]
    context.m_mapResumeName[waitname] = nil
    if tableRet ~= nil then
      return true, unpack(tableRet)
    end
    return true
  end
  context.m_strWaitName = waitname
  if nTimeOut and nTimeOut > 0 then
    context.m_timeout = os.time() + nTimeOut
  end
  return coroutine.yield(key, ...)
end

function CoroutineContextMgr:WaitCoWithFunc(key, waitname, nTimeOut, func, nTimes)
  for i = 1, nTimes do
    if func() then
      return true
    end
    local wakeupSuccess = self:WaitCo(key, waitname)
    if wakeupSuccess == false then
      return false
    end
  end
  return false
end

return CoroutineContextMgr