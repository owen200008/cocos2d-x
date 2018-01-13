cc.exports.LuaUserDefaultCFG = {}

function LuaUserDefaultCFG:Init()
  self.m_userDefault = cc.UserDefault:getInstance()
  --加载账号
  self.m_autoUserAccount = {}
  local userDefault = self.m_userDefault
  local userAccount = userDefault:getStringForKey("username")
  local userPhoneNumber = userDefault:getStringForKey("phoneNumber")
  if (userAccount ~= nil and userAccount:len() > 0) or (userPhoneNumber ~= nil and userPhoneNumber:len() > 0) then
    self.m_autoUserAccount.m_userAccount = userAccount
    self.m_autoUserAccount.m_userpwd = userDefault:getStringForKey("userpwd")
    self.m_autoUserAccount.m_usertype = userDefault:getIntegerForKey("usertype")
    self.m_autoUserAccount.m_strToken = userDefault:getStringForKey("token")
    self.m_autoUserAccount.m_nDefaultGameID = userDefault:getIntegerForKey("defaultgameid")
    self.m_autoUserAccount.m_nDefaultNickName = userDefault:getStringForKey("defaultnickname")
    self.m_autoUserAccount.m_phoneNumber = userPhoneNumber
    self:ParseToken()
  end
end

function LuaUserDefaultCFG:IsValidAccount()
  return self.m_autoUserAccount.m_userAccount ~= nil
end

function LuaUserDefaultCFG:IsValidToken()
  if self.m_autoUserAccount.m_strToken and self.m_token then
    return true
  end
  return false
end

function LuaUserDefaultCFG:ParseToken()
  if self.m_autoUserAccount.m_strToken and self.m_autoUserAccount.m_strToken:len() > 0 then
    self.m_token = LUA_NetManager:ParseByProtocal(self.m_autoUserAccount.m_strToken, "XKTokenClient", true)
    local crc32Value = Basic_crc32(Basic_MD5(self.m_autoUserAccount.m_userAccount))
    if self.m_token == nil or self.m_token.m_preData == nil or self.m_token.m_preData.m_nAccountCRC32 ~= crc32Value then
      self.m_autoUserAccount.m_strToken = nil
      self.m_token = nil
    end
  end
end

function LuaUserDefaultCFG:YouKeAccountUpdate(strAccont, strPwd)
  local userDefault = self.m_userDefault
  userDefault:setStringForKey("username", strAccont)
  userDefault:setStringForKey("userpwd", strPwd)
  userDefault:setIntegerForKey("usertype", 1)
  userDefault:setStringForKey("token", "")
  self.m_autoUserAccount.m_userAccount = strAccont
  self.m_autoUserAccount.m_userpwd = strPwd
  self.m_autoUserAccount.m_usertype = 1
  self.m_autoUserAccount.m_strToken = nil
  self.m_token = nil
end

function LuaUserDefaultCFG:UpdatePhoneNumber(phoneNumber)
  local userDefault = self.m_userDefault
  userDefault:setStringForKey("phoneNumber", phoneNumber)
end

function LuaUserDefaultCFG:TokenUpdate(strToken)
    local userDefault = self.m_userDefault
    userDefault:setStringForKey("token", strToken)
    self.m_autoUserAccount.m_strToken = strToken
    self:ParseToken()
end
function LuaUserDefaultCFG:ResetToken()
  self.m_autoUserAccount.m_strToken = nil
  self.m_token = nil
end

function LuaUserDefaultCFG:GetDefaultPhoneNumber()
  if self.m_autoUserAccount.m_phoneNumber then
    return self.m_autoUserAccount.m_phoneNumber
  end
  return ""
end

function LuaUserDefaultCFG:GetDefaultGameID()
  if self.m_autoUserAccount.m_nDefaultGameID then
    return self.m_autoUserAccount.m_nDefaultGameID
  end
  return 0
end
function LuaUserDefaultCFG:SetDefaultGameID(nGameID)
  if nGameID == self.m_autoUserAccount.m_nDefaultGameID then
    return
  end
  self.m_autoUserAccount.m_nDefaultGameID = nGameID
  local userDefault = self.m_userDefault
  userDefault:setIntegerForKey("defaultgameid", nGameID)
end

function LuaUserDefaultCFG:GetDefaultNickName()
  if self.m_autoUserAccount.m_nDefaultNickName and self.m_autoUserAccount.m_nDefaultNickName:len() > 0 then
    return self.m_autoUserAccount.m_nDefaultNickName
  end
  return nil
end
function LuaUserDefaultCFG:SetDefaultNickName(nickname)
  if nickname == self.m_autoUserAccount.m_nDefaultNickName then
    return
  end
  self.m_autoUserAccount.m_nDefaultNickName = nickname
  local userDefault = self.m_userDefault
  userDefault:setStringForKey("defaultnickname", nickname)
end

function LuaUserDefaultCFG:CreateLoginPacket()
  local packet = {m_strAccount = self.m_autoUserAccount.m_userAccount, m_strPwd = self.m_autoUserAccount.m_userpwd, m_cLoginType = self.m_autoUserAccount.m_usertype}
  return packet
end

function LuaUserDefaultCFG:CreateTokenPacket()
  local packet = {m_smToken = self.m_autoUserAccount.m_strToken}
  return packet
end

return LuaUserDefaultCFG