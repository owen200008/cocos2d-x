
local AppBase = class("AppBase")

function AppBase:ctor(configs)
    self.configs_ = {
        viewsRoot  = "app.views",
        modelsRoot = "app.models",
        defaultSceneName = "MainScene",
        lastSceneName = "",
    }

    for k, v in pairs(configs or {}) do
        self.configs_[k] = v
    end

    if type(self.configs_.viewsRoot) ~= "table" then
        self.configs_.viewsRoot = {self.configs_.viewsRoot}
    end
    if type(self.configs_.modelsRoot) ~= "table" then
        self.configs_.modelsRoot = {self.configs_.modelsRoot}
    end

    if DEBUG > 1 then
        dump(self.configs_, "AppBase configs")
    end

    if CC_SHOW_FPS then
        cc.Director:getInstance():setDisplayStats(true)
    else
        cc.Director:getInstance():setDisplayStats(false)
    end

    -- event
    self.m_dispatch = {}
    self.m_dispatchmsgmap = {}
    
    -- event
    self:onCreate()
end

function AppBase:run(initSceneName)
    initSceneName = initSceneName or self.configs_.defaultSceneName
    self:enterScene(initSceneName)
end

function AppBase:enterScene(sceneName, transition, time, more)
    local view = self:createView(sceneName)
    view:showWithScene(transition, time, more)
    return view
end

function AppBase:createView(name, resCSBFileName, bVisibleSize)
    for _, root in ipairs(self.configs_.viewsRoot) do
        local packageName = string.format("%s.%s", root, name)
        local status, view = xpcall(function()
                return require(packageName)
            end, __G__TRACKBACK__)

        local t = type(view)
        if status and (t == "table" or t == "userdata") then
            return view:create(self, name, nil, resCSBFileName, bVisibleSize)
        end
    end
    error(string.format("AppBase:createView() - not found view \"%s\" in search paths \"%s\"",
        name, table.concat(self.configs_.viewsRoot, ",")), 0)
end


function AppBase:createViewWithExistNode(name, bindnode)
    for _, root in ipairs(self.configs_.viewsRoot) do
        local packageName = string.format("%s.%s", root, name)
        local status, view = xpcall(function()
                return require(packageName)
            end, __G__TRACKBACK__)
        local t = type(view)
        if status and (t == "table" or t == "userdata") then
            return view:create(self, name, bindnode, nil)
        end
    end
    error(string.format("AppBase:createViewWithExistNode() - not found view \"%s\" in search paths \"%s\"",
        name, table.concat(self.configs_.viewsRoot, ",")), 0)
end

function AppBase:CloseGame()
    os.exit(0)
end

function AppBase:onCreate()
end


function AppBase:AddNodeDisPatch(viewbase, eventmsg, method)
    if self.m_dispatch[viewbase] == nil then
        self.m_dispatch[viewbase] = {}
    end
    self.m_dispatch[viewbase][eventmsg] = method

    if self.m_dispatchmsgmap[eventmsg] == nil then
        self.m_dispatchmsgmap[eventmsg] = {}
    end
    self.m_dispatchmsgmap[eventmsg][viewbase] = method
end
function AppBase:RmoveNodeDispatch(viewbase, eventmsg)
    if self.m_dispatch[viewbase] then
        self.m_dispatch[viewbase][eventmsg] = nil
    end
    if self.m_dispatchmsgmap[eventmsg] then
        self.m_dispatchmsgmap[eventmsg][viewbase] = nil
    end
end
function AppBase:RemoveAllNodeDispatch(viewbase)
    if self.m_dispatch[viewbase] then
        for key, value in pairs(self.m_dispatch[viewbase]) do
            self.m_dispatchmsgmap[key][viewbase] = nil
        end
        self.m_dispatch[viewbase] = nil
    end
end
function AppBase:DispatchMsg(eventmsg, userData)
    local sendcount = 0
    if self.m_dispatchmsgmap[eventmsg] then
        for key, value in pairs(self.m_dispatchmsgmap[eventmsg]) do
            value(userData)
            sendcount = sendcount + 1
        end
    end
    return sendcount
end
function AppBase:DispatchNodeMsg(viewbase, eventmsg, userData)
    if self.m_dispatch[viewbase] then
        if self.m_dispatch[viewbase][eventmsg] then
            local func = self.m_dispatch[viewbase][eventmsg]
            func(userData)
        end
    end
end

return AppBase
