cc.exports.LuaOnTimerMgr = {
    m_mapFuncRef = {},
    m_mapIDToFunc = {}
  }

------------------------------------------------------------------------------------------
LuaOnTimerMgr.m_scheduler = g_Director:getScheduler()
function LuaOnTimerMgr:AddTimer(tick, func)
  local scheduleid = self.m_scheduler:scheduleScriptFunc(function(nTick)
      local status, returnfunc = xpcall(func, __G__TRACKBACK__)
      if status == nil or (status and returnfunc) then
        if self.m_mapFuncRef[func] then
          for _, values in ipairs(self.m_mapFuncRef[func]) do
            if nTick == values.m_tick then
              self:DelTimer(values.m_id)
              break
            end
          end
        end
      end
    end, tick, false)
  if self.m_mapFuncRef[func] == nil then
    self.m_mapFuncRef[func] = {}
  end
  table.insert(self.m_mapFuncRef[func], {m_tick=tick,m_id=scheduleid})
  self.m_mapIDToFunc[scheduleid] = func
  return scheduleid
end

function LuaOnTimerMgr:DelTimer(scheduleid)
  local func = self.m_mapIDToFunc[scheduleid]
  if func and self.m_mapFuncRef[func] then
    for index, values in ipairs(self.m_mapFuncRef[func]) do
      if scheduleid == values.m_id then
        self.m_mapIDToFunc[scheduleid] = nil
        table.remove(self.m_mapFuncRef[func], index)
        self.m_scheduler:unscheduleScriptEntry(scheduleid)
      end
    end
  end
end
------------------------------------------------------------------------------------------

function LuaOnTimerMgr:AddTimeOut(tick, func)
  self:AddTimer(tick, function()
        func()
        return true
      end)
end

function LuaOnTimerMgr:DelayWakeUp(tick, nKey, strResumeName)
  self:AddTimeOut(tick, function()
        CoroutineContextMgr:WakeUpKey(nKey, strResumeName, true)
      end)
end


