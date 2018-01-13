cc.exports.Global_XMStringDefine = {

}
cc.exports.Global_XMStringServerDefine = {
}
function Global_XMStringDefine:GetErrorID(errid)
    local err = self[errid]
    if err == nil then
        err = string.format("error msg no find client %s ", tostring(errid))
        BasicLogEventError(err)
    end
    return err
end

function Global_XMStringServerDefine:GetErrorID(errid)
    local err = self[errid]
    if err == nil then
        err = string.format("error msg no find server %x ", errid)
        BasicLogEventError(err)
    end
    return err
end

return Global_XMStringDefine