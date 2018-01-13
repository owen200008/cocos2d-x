local ViewBase = {}

function ViewBase:ctor(app, name, bindnode, csbFileName, bVisibleSize)
  self.app_ = app
  self.name_ = name
  self.ScheduleArray = {}

  -- check CSB resource file
  if csbFileName then
        self:createResoueceNode(csbFileName, bindnode)
        self.RESOURCE_FILENAME = csbFileName
  else
        local res = rawget(self.class, "RESOURCE_FILENAME")
        if res == nil then
          res = self.RESOURCE_FILENAME
        end
        if res or bindnode then
            self:createResoueceNode(res, bindnode, bVisibleSize)
        end
  end
    
  self.resourceNode_:enableNodeEvents()
  self.resourceNode_._viewBaseBind = self;

  self:createsourceinfobind()

  if self.onCreate then self:onCreate() end

  self.resourceNode_.onEnterCallback_ = function()
        local resblock = rawget(self.class, "BLOCKLAYER")
        if resblock then
            self:OnEnableClick(true)
        end
        if self.onViewEnter then
            self:onViewEnter()
        end
  end
  self.resourceNode_.onEnterTransitionFinishCallback_ = function()
        if self.onViewEnterTransitionFinish then
            self:onViewEnterTransitionFinish()
        end
  end
  self.resourceNode_.onExitCallback_= function()
      self.app_:RemoveAllNodeDispatch(self)
	    self.resourceNode_:getEventDispatcher():removeEventListenersForTarget(self.resourceNode_)
        if self.ScheduleArray then
            local scheduler = cc.Director:getInstance():getScheduler()
            for schedulefunc, scheduleid in pairs(self.ScheduleArray) do
                scheduler:unscheduleScriptEntry(scheduleid)
            end
        end
        if self.onViewExit then
            self:onViewExit()
        end
        self.resourceNode_._viewBaseBind = nil
  end
  self.resourceNode_.onDestroyCallback_ = function()
        if self.onViewNodeDestroy then
            self:onViewNodeDestroy()
        end
  end
end

-----------------------------------------------------------------
function ViewBase:getApp()
    return self.app_
end

function ViewBase:getName()
    return self.name_
end

function ViewBase:getResourceNode()
    return self.resourceNode_
end
-----------------------------------------------------------------
--clk enable
function ViewBase:OnEnableClick(bEnable)
    if bEnable then
        if self.blocklayer_listenblock then
            return
        end
        self.blocklayer_listenblock = cc.EventListenerTouchOneByOne:create()
        self.blocklayer_listenblock:setSwallowTouches(true)
        self.blocklayer_listenblock:registerScriptHandler(HandleMethod(self, self.OnViewBaseTouchBegin),cc.Handler.EVENT_TOUCH_BEGAN )
        self.blocklayer_listenblock:registerScriptHandler(HandleMethod(self, self.OnViewBaseTouchMove),cc.Handler.EVENT_TOUCH_MOVED )
        self.blocklayer_listenblock:registerScriptHandler(HandleMethod(self, self.OnViewBaseTouchEnded),cc.Handler.EVENT_TOUCH_ENDED )
        self:AddListenForNode(self.blocklayer_listenblock)
    else
        if self.blocklayer_listenblock then
            self:RemoveListenForNode(self.blocklayer_listenblock)
            self.blocklayer_listenblock = nil
        end
    end    
end

function ViewBase:OnViewBaseTouchBegin(touch, event)
    if self.onViewTouchBegin then
        return self:onViewTouchBegin(touch, event)
    end
    local resblock = rawget(self.class, "NOHITCLOSELAYER")
    if resblock then
        local locationInNode = self.resourceNode_:convertToNodeSpace(touch:getLocation())
        local s = self.resourceNode_:getContentSize()
        local rect = cc.rect(0, 0, s.width, s.height)
        
        if cc.rectContainsPoint(rect, locationInNode) then
            if self.OnHitBeforeReturnTrueCallback then
                self:OnHitBeforeReturnTrueCallback()
            end
            return true
        end
        if self.OnNoHitBeforeCloseCallback then
            self:OnNoHitBeforeCloseCallback()
        end
		self:OnTouchCloseBtn()
        return rawget(self.class, "NOHITCLOSELAYERRETURNTYPE") or false
	end
    
	return true
end
function ViewBase:OnViewBaseTouchMove(touch, event)
    if self.onViewTouchMove then
        self:onViewTouchMove(touch, event)
    end
end
function ViewBase:OnViewBaseTouchEnded(touch, event)
    if self.onViewTouchEnded then
        self:onViewTouchEnded(touch, event)
    end
end
-----------------------------------------------------------------
--close
function ViewBase:BindOnCloseCallbackFuncBefore(func)
    self.m_pCloseCallback = func
end
function ViewBase:OnTouchCloseBtn(reason)
    if self.m_ontouchclosebtn_reason == nil then
      self.m_ontouchclosebtn_reason = reason
      if self.m_pCloseCallback then
        self.m_pCloseCallback(self, self.m_ontouchclosebtn_reason)
      end
      self:ScheduleForView(self.OnNextCloseSelf, 0.0)
    end
end

function ViewBase:BindOnCloseCallbackFuncAfter(func)
    self.m_pCloseCallbackAfter = func
end

function ViewBase:OnNextCloseSelf()
    self:UnScheduleForView(self.OnNextCloseSelf)
    
    self:getParent():removeChild(self.resourceNode_)
    if self.m_pCloseCallbackAfter then
        self.m_pCloseCallbackAfter(self, self.m_ontouchclosebtn_reason)
    end
end
-----------------------------------------------------------------
--cocos2d listen
function ViewBase:AddListenForNode(listen)
    local eventDispatcher = self.resourceNode_:getEventDispatcher()
    eventDispatcher:addEventListenerWithSceneGraphPriority(listen, self.resourceNode_)
end
function ViewBase:RemoveListenForNode(listen)
    local eventDispatcher = self.resourceNode_:getEventDispatcher()
    eventDispatcher:removeEventListener(listen)
end
--lua event listen
function ViewBase:AddLuaMsgListen(msg, callbackfunc)
    self.app_:AddNodeDisPatch(self, msg, callbackfunc)
end
--send event
function ViewBase:SendLuaEvent(msg, userData, secondmsg)
    if secondmsg then
        userData._luaResponseSecondMsg = secondmsg
    end
    return GlobalAppBaseRetain:DispatchMsg(msg, userData)
end
--timer
function ViewBase:HandleScheduleForViewFunc(obj, func)
    return function(...)
        local nRet = func(obj, ...)
        if nRet then
            self:UnScheduleForView(func)
        end
    end
end

function ViewBase:ScheduleForView(func, time)
    if self.ScheduleArray[func] ~= nil then
        assert(false, string.format("scheduleonce is exist"))
        return
    end
    local scheduler = cc.Director:getInstance():getScheduler()
    local scheduleid = scheduler:scheduleScriptFunc(self:HandleScheduleForViewFunc(self, func), time, false)
    self.ScheduleArray[func] = scheduleid
end
function ViewBase:UnScheduleForView(func)
    if self.ScheduleArray[func] == nil then
        return
    end
    local scheduler = cc.Director:getInstance():getScheduler()
    scheduler:unscheduleScriptEntry(self.ScheduleArray[func])
    self.ScheduleArray[func] = nil
end
function ViewBase:IsScheduleForView(func)
    return self.ScheduleArray[func] ~= nil
end
-----------------------------------------------------------------

function ViewBase:AddChildCSBFileByName(name, createCallback, pOffset, bWinCenter, cameramask, parentnode)
    local parentSize = cc.exports.GlobalWinSizeRetain
	if bWinCenter and bWinCenter == false then
		parentSize = self:getContentSize()
	end
	local view = self.app_:createView(name)
    if createCallback then
        createCallback(view)
    end
    if parentnode then
        parentnode:addChild(view:getResourceNode())
    else
	    self:addChild(view)
    end
	--м
    local contentSize = view:getContentSize()
	local vPos = cc.p((parentSize.width - contentSize.width) / 2, (parentSize.height - contentSize.height) / 2)
	if pOffset then
		vPos = cc.pAdd(vPos, pOffset)
    end
	view:setPosition(self.resourceNode_:convertToNodeSpace(vPos))

    if cameramask then
        view:setCameraMask(cameramask)
    else
        view:setCameraMask(self.resourceNode_:getCameraMask())
    end

    return view
end

function ViewBase:LoadChildCSBFileByName(name, cameramask, resCSBFileName, bVisibleSize)
    local view = self.app_:createView(name, resCSBFileName, bVisibleSize)
    if cameramask then
        view:setCameraMask(cameramask)
    else
        view:setCameraMask(self.resourceNode_:getCameraMask())
    end
    return view
end

function ViewBase:IsCSBFileLayerExist(fullname)
    local node = self:getChildByName(fullname)
    return node
end

function ViewBase:createResoueceNode(resourceFilename, bindnode, bVisibleSize)
    if self.resourceNode_ then
        self.resourceNode_:removeSelf()
        self.resourceNode_ = nil
    end
    if bindnode then
        self.resourceNode_ = bindnode
    else
        if bVisibleSize then
          self.resourceNode_ = cc.CSLoader:createNodeWithVisibleSize(resourceFilename)
        else
          self.resourceNode_ = cc.CSLoader:createNode(resourceFilename)
        end
    end

    self.m_LoadRessourceFileName = resourceFilename
    self.resourceNode_:setName(resourceFilename)
    assert(self.resourceNode_, string.format("ViewBase:createResoueceNode() - load resouce node from file \"%s\" failed", resourceFilename))
    --self:addChild(self.resourceNode_)
end

function ViewBase:createsourceinfobind()
    local funcbindid;
    funcbindid = function (databind, node)
        local totalChilds = node:getChildren()
        for _, child in pairs(totalChilds) do
            local childtag = child:getTag()
            databind[childtag] = child;
            funcbindid(databind[childtag], child)
        end
    end 
    if self.resourceNode_ then
        funcbindid(self, self.resourceNode_)
    end
end


function ViewBase:showWithScene(transition, time, more)
    local scene = display.newScene(self.name_, {physics=1})
    local nomainnodeframe = rawget(self.class, "NOMAINFRAMENODESCENE")
    if nomainnodeframe == nil then
        self.CocosUI_MainNode_ = self.app_:createView("mainnode")
        self.CocosUI_MainNode_:getResourceNode():addChild(self.resourceNode_)
        local reconnectMgr = rawget(self.class, "RECONNECTMANAGER")
        if reconnectMgr ~= nil then
            self.CocosUI_MainNode_:ReconnectManager(reconnectMgr)
        end
    else
        self.CocosUI_MainNode_ = self
    end
    
    scene:addChild(self.CocosUI_MainNode_:getResourceNode())
    display.runScene(scene, transition, time, more)
    return self
end
--------------------------------------------------------------------------------------
function ViewBase:OnDelayRemoveResource()
    --ͷеĶ
	ccs.ActionTimelineCache:getInstance():purge();
	--cocos2d::CCAnimationCache::purgeSharedAnimationCache();

	cc.SpriteFrameCache:getInstance():removeUnusedSpriteFrames()
	cc.TextureCache:getInstance():removeUnusedTextures()

	--ڴеĻ
	--CResourceCache::GetResourceCache()->ClearNoUsedCache();
end
--------------------------------------------------------------------------------------
function ViewBase:GetCustomEventUserDataString(pEventCustom)
    if pEventCustom._userdata then
        return pEventCustom._userdata
    else
        return xmqxzpublic.XMQXZ_MessageStruct:GetMsgFromCustomEventToString(pEventCustom)
    end
end
-----------------------------------------------------------------------------------------
function ViewBase:setVisible(bVisible)
    return self.resourceNode_:setVisible(bVisible)
end
function ViewBase:isVisible()
    return self.resourceNode_:isVisible()
end
function ViewBase:addChild(child)
    if child.resourceNode_ then
        self.resourceNode_:addChild(child.resourceNode_)
    else
        self.resourceNode_:addChild(child)
    end
end
function ViewBase:removeChild(child)
    if child.resourceNode_ then
        self.resourceNode_:removeChild(child.resourceNode_)
    else
        self.resourceNode_:removeChild(child)
    end
end
function ViewBase:getChildByName(name)
    return self.resourceNode_:getChildByName(name)
end

function ViewBase:getPosition()
    return self.resourceNode_:getPosition()
end
function ViewBase:setPosition(vpos)
    return self.resourceNode_:setPosition(vpos)
end
function ViewBase:setPositionX(x)
    return self.resourceNode_:setPositionX(x)
end
function ViewBase:setPositionY(y)
    return self.resourceNode_:setPositionY(y)
end

function ViewBase:setUserData(userData)
    return self.resourceNode_:setUserData(userData)
end
function ViewBase:getParent()
    return self.resourceNode_:getParent()
end

function ViewBase:getContentSize()
    return self.resourceNode_:getContentSize()
end
function ViewBase:setContentSize(size)
    return self.resourceNode_:setContentSize(size)
end
function ViewBase:AddContentHeight(y)
    xmqxz.CLuaGlobalFunc:AddContentWidthHeight(self.resourceNode_, 0, y)
end

function ViewBase:getCameraMask()
    return self.resourceNode_:getCameraMask()
end
function ViewBase:setCameraMask(mask)
    return self.resourceNode_:setCameraMask(mask)
end

function ViewBase:getWorldPosition()
    return self.resourceNode_:getWorldPosition()
end
function ViewBase:convertToNodeSpace(pos)
    return self.resourceNode_:convertToNodeSpace(pos)
end

function ViewBase:retain()
    return self.resourceNode_:retain()
end
function ViewBase:release()
    return self.resourceNode_:release()
end
function ViewBase:setTag(nID)
    return self.resourceNode_:setTag(nID)
end

return ViewBase
  