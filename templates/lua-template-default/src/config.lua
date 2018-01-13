
-- 0 - disable debug info, 1 - less debug info, 2 - verbose debug info
DEBUG = 2

-- use framework, will disable all deprecated API, false - use legacy API
CC_USE_FRAMEWORK = true

-- show FPS on screen
CC_SHOW_FPS = true

-- disable create unexpected global variable
CC_DISABLE_GLOBAL = true

-- for module display
CC_DESIGN_RESOLUTION = {
    width = 1366,
    height = 768,
    autoscale = "FIXED_HEIGHT",
    callback = function(framesize)
        if cc.Application:getInstance():getTargetPlatform() == cc.PLATFORM_OS_WINDOWS then
          local view = cc.Director:getInstance():getOpenGLView()
            if view ~= nil then
              framesize.width = width
              framesize.height = height
              view:setFrameSize(framesize.width, framesize.height)
            end
        end
        local ratio = framesize.width / framesize.height
        if ratio <= 1.776 then
            -- iPad 768*1024(1536*2048) is 4:3 screen
            return {autoscale = "FIXED_WIDTH"}
        end
    end
}
