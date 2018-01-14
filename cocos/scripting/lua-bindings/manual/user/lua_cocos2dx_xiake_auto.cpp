#include "lua_cocos2dx_xiake_auto.hpp"
#include "user/dylistview.h"
#include "user/cocosrichtext.h"
#include "user/AnimatePacker3.h"
#include "user/cocosnodenorelease.h"
#include "user/CCSpriteFrameCache_XiaKe.h"
#include "user/CLikeWidget.h"
#include "user/CSTMXMap_XiaKe.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "scripting/lua-bindings/manual/CCLuaValue.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"

int lua_cocos2dx_xiake_CDyListViewLoadLayout_SelectItem(lua_State* tolua_S)
{
    int argc = 0;
    CDyListViewLoadLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CDyListViewLoadLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListViewLoadLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_SelectItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::ui::ListView* arg0;
        cocos2d::Touch* arg1;

        ok &= luaval_to_object<cocos2d::ui::ListView>(tolua_S, 2, "ccui.ListView",&arg0, "CDyListViewLoadLayout:SelectItem");

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 3, "cc.Touch",&arg1, "CDyListViewLoadLayout:SelectItem");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_SelectItem'", nullptr);
            return 0;
        }
        cobj->SelectItem(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListViewLoadLayout:SelectItem",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_SelectItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CDyListViewLoadLayout_NoInView(lua_State* tolua_S)
{
    int argc = 0;
    CDyListViewLoadLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CDyListViewLoadLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListViewLoadLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_NoInView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_NoInView'", nullptr);
            return 0;
        }
        cobj->NoInView();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListViewLoadLayout:NoInView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_NoInView'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CDyListViewLoadLayout_UnSelectItem(lua_State* tolua_S)
{
    int argc = 0;
    CDyListViewLoadLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CDyListViewLoadLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListViewLoadLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_UnSelectItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::ui::ListView* arg0;
        cocos2d::Touch* arg1;

        ok &= luaval_to_object<cocos2d::ui::ListView>(tolua_S, 2, "ccui.ListView",&arg0, "CDyListViewLoadLayout:UnSelectItem");

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 3, "cc.Touch",&arg1, "CDyListViewLoadLayout:UnSelectItem");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_UnSelectItem'", nullptr);
            return 0;
        }
        cobj->UnSelectItem(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListViewLoadLayout:UnSelectItem",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_UnSelectItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CDyListViewLoadLayout_SetDirty(lua_State* tolua_S)
{
    int argc = 0;
    CDyListViewLoadLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CDyListViewLoadLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListViewLoadLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_SetDirty'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CDyListViewLoadLayout:SetDirty");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_SetDirty'", nullptr);
            return 0;
        }
        cobj->SetDirty(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListViewLoadLayout:SetDirty",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_SetDirty'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CDyListViewLoadLayout_GetCreateNode(lua_State* tolua_S)
{
    int argc = 0;
    CDyListViewLoadLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CDyListViewLoadLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListViewLoadLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_GetCreateNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_GetCreateNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->GetCreateNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListViewLoadLayout:GetCreateNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_GetCreateNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CDyListViewLoadLayout_InitLayout(lua_State* tolua_S)
{
    int argc = 0;
    CDyListViewLoadLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CDyListViewLoadLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListViewLoadLayout*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_InitLayout'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ui::ListView* arg0;

        ok &= luaval_to_object<cocos2d::ui::ListView>(tolua_S, 2, "ccui.ListView",&arg0, "CDyListViewLoadLayout:InitLayout");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_InitLayout'", nullptr);
            return 0;
        }
        cobj->InitLayout(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListViewLoadLayout:InitLayout",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_InitLayout'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CDyListViewLoadLayout_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CDyListViewLoadLayout",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_create'", nullptr);
            return 0;
        }
        CDyListViewLoadLayout* ret = CDyListViewLoadLayout::create();
        object_to_luaval<CDyListViewLoadLayout>(tolua_S, "CDyListViewLoadLayout",(CDyListViewLoadLayout*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CDyListViewLoadLayout:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_xiake_CDyListViewLoadLayout_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CDyListViewLoadLayout* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_constructor'", nullptr);
            return 0;
        }
        cobj = new CDyListViewLoadLayout();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CDyListViewLoadLayout");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListViewLoadLayout:CDyListViewLoadLayout",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_constructor'.",&tolua_err);
#endif

    return 0;
}


int lua_cocos2dx_xiake_CDyListViewLoadLayout_bindCreateFunc(lua_State* tolua_S){
    int argc = 0;
    CDyListViewLoadLayout* cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if(!tolua_isusertype(tolua_S, 1, "CDyListViewLoadLayout", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListViewLoadLayout*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if(!cobj){
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_bindCreateFunc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;
    if(argc == 1){
#if COCOS2D_DEBUG >= 1
        if(!toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, &tolua_err)){
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = toluafix_ref_function(tolua_S, 2, 0);
        cocos2d::ScriptHandlerMgr::getInstance()->addCustomHandler((void*)cobj, handler);

        cobj->bindCreateFunc([=](CDyListViewLoadLayout* pLayout, cocos2d::Node* pNode)->cocos2d::Node*{
            cocos2d::Node* pRet = nullptr;
            LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
            stack->pushObject(pLayout, "xiake.CDyListViewLoadLayout");
            if(pNode){
                stack->pushObject(pNode, "cc.Node");
                stack->executeFunctionByHandler(handler, 2);
            }
            else{
                stack->pushNil();
                stack->executeFunction(handler, 2, 1, [&pRet](lua_State* L, int nNumber)->void{
                    pRet = static_cast<Node*>(tolua_tousertype(L, -1, nullptr));
                });
            }
            stack->clean();
            return pRet;
        });
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListViewLoadLayout:bindCreateFunc", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
                tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_bindCreateFunc'.", &tolua_err);
#endif
    return 0;
}


int lua_cocos2dx_xiake_CDyListViewLoadLayout_BindSelectChangeItemCallback(lua_State* tolua_S){
    int argc = 0;
    CDyListViewLoadLayout* cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if(!tolua_isusertype(tolua_S, 1, "CDyListViewLoadLayout", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListViewLoadLayout*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if(!cobj){
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_BindSelectChangeItemCallback'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;
    if(argc == 1){
#if COCOS2D_DEBUG >= 1
        if(!toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, &tolua_err)){
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = toluafix_ref_function(tolua_S, 2, 0);
        cocos2d::ScriptHandlerMgr::getInstance()->addCustomHandler((void*)cobj, handler);

        cobj->BindSelectChangeItemCallback([=](cocos2d::Node* pNode, cocos2d::Touch* pTouch, bool bSelect)->void{
            LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
            stack->pushObject(pNode, "cc.Node");
            stack->pushObject(pTouch, "cc.Touch");
            stack->pushBoolean(bSelect);
            stack->executeFunctionByHandler(handler, 3);
            stack->clean();
        });
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListViewLoadLayout:BindSelectChangeItemCallback", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
                tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_xiake_CDyListViewLoadLayout_BindSelectChangeItemCallback'.", &tolua_err);
#endif

    return 0;
}


int lua_cocos2dx_xiake_CDyListView_ReLoadListViewItems(lua_State* tolua_S){
    int argc = 0;
    CDyListView* cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if(!tolua_isusertype(tolua_S, 1, "CDyListView", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListView*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if(!cobj){
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListView_ReLoadListViewItems'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;
    if(argc == 1){
#if COCOS2D_DEBUG >= 1
        if(!toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, &tolua_err)){
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = toluafix_ref_function(tolua_S, 2, 0);
        cocos2d::ScriptHandlerMgr::getInstance()->addCustomHandler((void*)cobj, handler);

        cobj->ReLoadListViewItems([=](cocos2d::ui::ListView* pList)->void{
            LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
            stack->pushObject(pList, "cc.ListView");
            stack->executeFunctionByHandler(handler, 1);
            stack->clean();
        });
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListView:ReLoadListViewItems", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
                tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_xiake_CDyListView_ReLoadListViewItems'.", &tolua_err);
#endif

                return 0;
}

int lua_cocos2dx_xiake_CDyListView_BindMessageCallbackFunc(lua_State* tolua_S){
    int argc = 0;
    CDyListView* cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if(!tolua_isusertype(tolua_S, 1, "CDyListView", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListView*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if(!cobj){
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListView_BindMessageCallbackFunc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;
    if(argc == 1){
#if COCOS2D_DEBUG >= 1
        if(!toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, &tolua_err)){
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = toluafix_ref_function(tolua_S, 2, 0);
        cocos2d::ScriptHandlerMgr::getInstance()->addCustomHandler((void*)cobj, handler);

        cobj->BindMessageCallbackFunc([=](cocos2d::ui::ListView* pList, int nKey, int nValue)->void{
            LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
            stack->pushObject(pList, "cc.ListView");
            stack->pushInt(nKey);
            stack->pushInt(nValue);
            stack->executeFunctionByHandler(handler, 3);
            stack->clean();
        });
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListView:lua_cocos2dx_xiake_CDyListView_BindMessageCallbackFunc", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
                tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_xiake_CDyListView_BindMessageCallbackFunc'.", &tolua_err);
#endif

                return 0;
}

int lua_cocos2dx_xiake_CDyListView_BindSelectItemChangeFunc(lua_State* tolua_S){
    int argc = 0;
    CDyListView* cobj = nullptr;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if(!tolua_isusertype(tolua_S, 1, "CDyListView", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListView*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
    if(!cobj){
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListView_BindSelectItemChangeFunc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;
    if(argc == 1){
#if COCOS2D_DEBUG >= 1
        if(!toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, &tolua_err)){
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = toluafix_ref_function(tolua_S, 2, 0);
        cocos2d::ScriptHandlerMgr::getInstance()->addCustomHandler((void*)cobj, handler);

        cobj->BindSelectItemChangeFunc([=](cocos2d::ui::ListView* pList, ssize_t sIndex, cocos2d::Touch* pTouch)->void{
            LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
            stack->pushObject(pList, "cc.ListView");
            stack->pushInt(sIndex);
            stack->pushObject(pTouch, "cc.Touch");
            stack->executeFunctionByHandler(handler, 3);
            stack->clean();
        });
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListView:BindSelectItemChangeFunc", argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
                tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_xiake_CDyListView_BindSelectItemChangeFunc'.", &tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_xiake_CDyListViewLoadLayout_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CDyListViewLoadLayout)");
    return 0;
}

int lua_register_cocos2dx_xiake_CDyListViewLoadLayout(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CDyListViewLoadLayout");
    tolua_cclass(tolua_S,"CDyListViewLoadLayout","CDyListViewLoadLayout","ccui.Widget",nullptr);

    tolua_beginmodule(tolua_S,"CDyListViewLoadLayout");
        tolua_function(tolua_S,"new",lua_cocos2dx_xiake_CDyListViewLoadLayout_constructor);
        tolua_function(tolua_S,"SelectItem",lua_cocos2dx_xiake_CDyListViewLoadLayout_SelectItem);
        tolua_function(tolua_S,"NoInView",lua_cocos2dx_xiake_CDyListViewLoadLayout_NoInView);
        tolua_function(tolua_S,"UnSelectItem",lua_cocos2dx_xiake_CDyListViewLoadLayout_UnSelectItem);
        tolua_function(tolua_S,"SetDirty",lua_cocos2dx_xiake_CDyListViewLoadLayout_SetDirty);
        tolua_function(tolua_S,"GetCreateNode",lua_cocos2dx_xiake_CDyListViewLoadLayout_GetCreateNode);
        tolua_function(tolua_S,"InitLayout",lua_cocos2dx_xiake_CDyListViewLoadLayout_InitLayout);
        tolua_function(tolua_S,"create", lua_cocos2dx_xiake_CDyListViewLoadLayout_create);
        tolua_function(tolua_S, "bindCreateFunc", lua_cocos2dx_xiake_CDyListViewLoadLayout_bindCreateFunc);
        tolua_function(tolua_S, "BindSelectChangeItemCallback", lua_cocos2dx_xiake_CDyListViewLoadLayout_BindSelectChangeItemCallback);
        tolua_function(tolua_S, "ReLoadListViewItems", lua_cocos2dx_xiake_CDyListView_ReLoadListViewItems);
        tolua_function(tolua_S, "BindSelectItemChangeFunc", lua_cocos2dx_xiake_CDyListView_BindSelectItemChangeFunc);
        tolua_function(tolua_S, "BindMessageCallbackFunc", lua_cocos2dx_xiake_CDyListView_BindMessageCallbackFunc);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CDyListViewLoadLayout).name();
    g_luaType[typeName] = "CDyListViewLoadLayout";
    g_typeCast["CDyListViewLoadLayout"] = "CDyListViewLoadLayout";
    return 1;
}

int lua_cocos2dx_xiake_CDyListView_SetCurSelectItem(lua_State* tolua_S)
{
    int argc = 0;
    CDyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CDyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListView_SetCurSelectItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ui::Widget* arg0;

        ok &= luaval_to_object<cocos2d::ui::Widget>(tolua_S, 2, "ccui.Widget",&arg0, "CDyListView:SetCurSelectItem");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListView_SetCurSelectItem'", nullptr);
            return 0;
        }
        cobj->SetCurSelectItem(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListView:SetCurSelectItem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListView_SetCurSelectItem'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CDyListView_SetCurSelectIndex(lua_State* tolua_S)
{
    int argc = 0;
    CDyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CDyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListView_SetCurSelectIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CDyListView:SetCurSelectIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListView_SetCurSelectIndex'", nullptr);
            return 0;
        }
        cobj->SetCurSelectIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListView:SetCurSelectIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListView_SetCurSelectIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CDyListView_SetInnerDyFixLocation(lua_State* tolua_S)
{
    int argc = 0;
    CDyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CDyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListView_SetInnerDyFixLocation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CDyListView:SetInnerDyFixLocation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListView_SetInnerDyFixLocation'", nullptr);
            return 0;
        }
        cobj->SetInnerDyFixLocation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListView:SetInnerDyFixLocation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListView_SetInnerDyFixLocation'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CDyListView_GetRealInnerHeight(lua_State* tolua_S)
{
    int argc = 0;
    CDyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CDyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListView_GetRealInnerHeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListView_GetRealInnerHeight'", nullptr);
            return 0;
        }
        double ret = cobj->GetRealInnerHeight();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListView:GetRealInnerHeight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListView_GetRealInnerHeight'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CDyListView_NextFPSReCalcShowView(lua_State* tolua_S)
{
    int argc = 0;
    CDyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CDyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListView_NextFPSReCalcShowView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListView_NextFPSReCalcShowView'", nullptr);
            return 0;
        }
        cobj->NextFPSReCalcShowView();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListView:NextFPSReCalcShowView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListView_NextFPSReCalcShowView'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CDyListView_RemoveDyListViewItems(lua_State* tolua_S)
{
    int argc = 0;
    CDyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CDyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListView_RemoveDyListViewItems'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListView_RemoveDyListViewItems'", nullptr);
            return 0;
        }
        cobj->RemoveDyListViewItems();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListView:RemoveDyListViewItems",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListView_RemoveDyListViewItems'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CDyListView_ChangeItemPosition(lua_State* tolua_S)
{
    int argc = 0;
    CDyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CDyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListView_ChangeItemPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::ui::Widget* arg0;
        int arg1;

        ok &= luaval_to_object<cocos2d::ui::Widget>(tolua_S, 2, "ccui.Widget",&arg0, "CDyListView:ChangeItemPosition");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CDyListView:ChangeItemPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListView_ChangeItemPosition'", nullptr);
            return 0;
        }
        cobj->ChangeItemPosition(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListView:ChangeItemPosition",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListView_ChangeItemPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CDyListView_DeleteListViewRow(lua_State* tolua_S)
{
    int argc = 0;
    CDyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CDyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CDyListView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CDyListView_DeleteListViewRow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "CDyListView:DeleteListViewRow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListView_DeleteListViewRow'", nullptr);
            return 0;
        }
        cobj->DeleteListViewRow(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListView:DeleteListViewRow",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListView_DeleteListViewRow'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CDyListView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CDyListView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListView_create'", nullptr);
            return 0;
        }
        CDyListView* ret = CDyListView::create();
        object_to_luaval<CDyListView>(tolua_S, "CDyListView",(CDyListView*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CDyListView:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_xiake_CDyListView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CDyListView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CDyListView_constructor'", nullptr);
            return 0;
        }
        cobj = new CDyListView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CDyListView");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CDyListView:CDyListView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CDyListView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_xiake_CDyListView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CDyListView)");
    return 0;
}

int lua_register_cocos2dx_xiake_CDyListView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CDyListView");
    tolua_cclass(tolua_S,"CDyListView","CDyListView","ccui.ListView",nullptr);

    tolua_beginmodule(tolua_S,"CDyListView");
        tolua_function(tolua_S,"new",lua_cocos2dx_xiake_CDyListView_constructor);
        tolua_function(tolua_S,"SetCurSelectItem",lua_cocos2dx_xiake_CDyListView_SetCurSelectItem);
        tolua_function(tolua_S,"SetCurSelectIndex",lua_cocos2dx_xiake_CDyListView_SetCurSelectIndex);
        tolua_function(tolua_S,"SetInnerDyFixLocation",lua_cocos2dx_xiake_CDyListView_SetInnerDyFixLocation);
        tolua_function(tolua_S,"GetRealInnerHeight",lua_cocos2dx_xiake_CDyListView_GetRealInnerHeight);
        tolua_function(tolua_S,"NextFPSReCalcShowView",lua_cocos2dx_xiake_CDyListView_NextFPSReCalcShowView);
        tolua_function(tolua_S,"RemoveDyListViewItems",lua_cocos2dx_xiake_CDyListView_RemoveDyListViewItems);
        tolua_function(tolua_S,"ChangeItemPosition",lua_cocos2dx_xiake_CDyListView_ChangeItemPosition);
        tolua_function(tolua_S,"DeleteListViewRow",lua_cocos2dx_xiake_CDyListView_DeleteListViewRow);
        tolua_function(tolua_S,"create", lua_cocos2dx_xiake_CDyListView_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CDyListView).name();
    g_luaType[typeName] = "CDyListView";
    g_typeCast["CDyListView"] = "CDyListView";
    return 1;
}

int lua_cocos2dx_xiake_CCocosRichTextNodeClkNotify_GetTouch(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeClkNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeClkNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeClkNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeClkNotify_GetTouch'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeClkNotify_GetTouch'", nullptr);
            return 0;
        }
        cocos2d::Touch* ret = cobj->GetTouch();
        object_to_luaval<cocos2d::Touch>(tolua_S, "cc.Touch",(cocos2d::Touch*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeClkNotify:GetTouch",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeClkNotify_GetTouch'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeClkNotify_GetClkNode(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeClkNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeClkNotify",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeClkNotify*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeClkNotify_GetClkNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeClkNotify_GetClkNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->GetClkNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeClkNotify:GetClkNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeClkNotify_GetClkNode'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeClkNotify_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeClkNotify* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Node* arg0;
        cocos2d::Touch* arg1;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "CCocosRichTextNodeClkNotify:CCocosRichTextNodeClkNotify");

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 3, "cc.Touch",&arg1, "CCocosRichTextNodeClkNotify:CCocosRichTextNodeClkNotify");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeClkNotify_constructor'", nullptr);
            return 0;
        }
        cobj = new CCocosRichTextNodeClkNotify(arg0, arg1);
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CCocosRichTextNodeClkNotify");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeClkNotify:CCocosRichTextNodeClkNotify",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeClkNotify_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_xiake_CCocosRichTextNodeClkNotify_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCocosRichTextNodeClkNotify)");
    return 0;
}

int lua_register_cocos2dx_xiake_CCocosRichTextNodeClkNotify(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CCocosRichTextNodeClkNotify");
    tolua_cclass(tolua_S,"CCocosRichTextNodeClkNotify","CCocosRichTextNodeClkNotify","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CCocosRichTextNodeClkNotify");
        tolua_function(tolua_S,"new",lua_cocos2dx_xiake_CCocosRichTextNodeClkNotify_constructor);
        tolua_function(tolua_S,"GetTouch",lua_cocos2dx_xiake_CCocosRichTextNodeClkNotify_GetTouch);
        tolua_function(tolua_S,"GetClkNode",lua_cocos2dx_xiake_CCocosRichTextNodeClkNotify_GetClkNode);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CCocosRichTextNodeClkNotify).name();
    g_luaType[typeName] = "CCocosRichTextNodeClkNotify";
    g_typeCast["CCocosRichTextNodeClkNotify"] = "CCocosRichTextNodeClkNotify";
    return 1;
}

int lua_cocos2dx_xiake_CCocosRichTextNode_initJsonData(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNode_initJsonData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        const char* arg0;
        int arg1;
        int arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CCocosRichTextNode:initJsonData"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_int32(tolua_S, 3, (int *)&arg1, "CCocosRichTextNode:initJsonData");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "CCocosRichTextNode:initJsonData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNode_initJsonData'", nullptr);
            return 0;
        }
        cobj->initJsonData(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNode:initJsonData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNode_initJsonData'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_xiake_CCocosRichTextNode_SetTouchEnable(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNode_SetTouchEnable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CCocosRichTextNode:SetTouchEnable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNode_SetTouchEnable'", nullptr);
            return 0;
        }
        cobj->SetTouchEnable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNode:SetTouchEnable",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNode_SetTouchEnable'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_xiake_CCocosRichTextNode_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CCocosRichTextNode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNode_create'", nullptr);
            return 0;
        }
        CCocosRichTextNode* ret = CCocosRichTextNode::create();
        object_to_luaval<CCocosRichTextNode>(tolua_S, "CCocosRichTextNode",(CCocosRichTextNode*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CCocosRichTextNode:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNode_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNode_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNode_constructor'", nullptr);
            return 0;
        }
        cobj = new CCocosRichTextNode();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CCocosRichTextNode");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNode:CCocosRichTextNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNode_constructor'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_xiake_RegisterStyleConfig(lua_State* tolua_S){
    int argc = 0;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if(!tolua_isusertable(tolua_S, 1, "CCocosRichTextNode", 0, &tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if(argc == 3){
        int     arg0;
        int     arg1;
        bool    arg2;

        ok &= luaval_to_int32(tolua_S, 2, &arg0, "CCocosRichTextNode:RegisterStyleConfig");
        if(!ok){
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_xiake_RegisterStyleConfig'", nullptr);
            return 0;
        }
        ok &= luaval_to_int32(tolua_S, 3, &arg1, "CCocosRichTextNode:RegisterStyleConfig");
        if(!ok){
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_xiake_RegisterStyleConfig'", nullptr);
            return 0;
        }
        ok &= luaval_to_boolean(tolua_S, 4, &arg2, "CCocosRichTextNode:RegisterStyleConfig");
        if(!ok){
            tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_xiake_RegisterStyleConfig'", nullptr);
            return 0;
        }
        CocosRichTextStyleConfig config((cocos2d::TextHAlignment)arg1, arg2);
        CCocosRichTextNode::RegisterStyleConfig(arg0, config);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CCocosRichTextNode:lua_cocos2dx_xiake_RegisterStyleConfig", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
                tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_xiake_RegisterStyleConfig'.", &tolua_err);
#endif
    return 0;
}

int lua_cocos2dx_xiake_RegisterFontConfig(lua_State* tolua_S){
    int argc = 0;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if(!tolua_isusertable(tolua_S, 1, "CCocosRichTextNode", 0, &tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if(argc == 6){
        int     arg0;
        const char* arg1;
        int     arg2;
        cocos2d::Color4B    arg3;
        bool    arg4;
        cocos2d::Color4B    arg5;
        ok &= luaval_to_int32(tolua_S, 2, &arg0, "CCocosRichTextNode:RegisterFontConfig");
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "CCocosRichTextNodeForCocos:RegisterFontConfig"); arg1 = arg1_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 4, &arg2, "CCocosRichTextNode:RegisterFontConfig");
        ok &= luaval_to_color4b(tolua_S, 5, &arg3, "CCocosRichTextNode:RegisterFontConfig");
        ok &= luaval_to_boolean(tolua_S, 6, &arg4, "CCocosRichTextNode:RegisterStyleConfig");
        ok &= luaval_to_color4b(tolua_S, 7, &arg5, "CCocosRichTextNode:RegisterFontConfig");
        if(!ok){
            tolua_error(tolua_S, "invalid arguments in function 'RegisterFontConfig'", nullptr);
            return 0;
        }
        CocosRichTextFontConfig config(arg1, arg2, arg3, arg4, arg5);
        CCocosRichTextNode::RegisterFontConfig(arg0, config);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CCocosRichTextNode:RegisterFontConfig", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
                tolua_error(tolua_S, "#ferror in function 'RegisterFontConfig'.", &tolua_err);
#endif
                return 0;
}


int lua_cocos2dx_xiake_SetAnimationFormat(lua_State* tolua_S){
    int argc = 0;
    bool ok = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if(!tolua_isusertable(tolua_S, 1, "CCocosRichTextNode", 0, &tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if(argc == 1){
        const char* arg0;
       
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CCocosRichTextNodeForCocos:SetAnimationFormat"); arg0 = arg0_tmp.c_str();
        if(!ok){
            tolua_error(tolua_S, "invalid arguments in function 'SetAnimationFormat'", nullptr);
            return 0;
        }
        CCocosRichTextNode::SetAnimationFormat(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CCocosRichTextNode:SetAnimationFormat", argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
                tolua_error(tolua_S, "#ferror in function 'SetAnimationFormat'.", &tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_xiake_CCocosRichTextNode_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCocosRichTextNode)");
    return 0;
}

int lua_register_cocos2dx_xiake_CCocosRichTextNode(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CCocosRichTextNode");
    tolua_cclass(tolua_S,"CCocosRichTextNode","CCocosRichTextNode","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"CCocosRichTextNode");
        tolua_function(tolua_S,"new",lua_cocos2dx_xiake_CCocosRichTextNode_constructor);
        tolua_function(tolua_S,"initJsonData",lua_cocos2dx_xiake_CCocosRichTextNode_initJsonData);
        tolua_function(tolua_S,"SetTouchEnable",lua_cocos2dx_xiake_CCocosRichTextNode_SetTouchEnable);
        tolua_function(tolua_S,"create", lua_cocos2dx_xiake_CCocosRichTextNode_create);
        tolua_function(tolua_S, "RegisterStyleConfig", lua_cocos2dx_xiake_RegisterStyleConfig);
        tolua_function(tolua_S, "RegisterFontConfig", lua_cocos2dx_xiake_RegisterFontConfig);
        tolua_function(tolua_S, "SetAnimationFormat", lua_cocos2dx_xiake_SetAnimationFormat);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CCocosRichTextNode).name();
    g_luaType[typeName] = "CCocosRichTextNode";
    g_typeCast["CCocosRichTextNode"] = "CCocosRichTextNode";
    return 1;
}

int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetFontSize(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CCocosRichTextNodeForCocos:SetDefaultFontSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetFontSize'", nullptr);
            return 0;
        }
        cobj->SetFontSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:SetDefaultFontSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetBHCenter(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetBHCenter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetBHCenter'", nullptr);
            return 0;
        }
        bool ret = cobj->GetBHCenter();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:GetBHCenter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetBHCenter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetBVCenter(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetBVCenter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetBVCenter'", nullptr);
            return 0;
        }
        bool ret = cobj->GetBVCenter();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:GetBVCenter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetBVCenter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetFontSize(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetFontSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetFontSize'", nullptr);
            return 0;
        }
        int ret = cobj->GetFontSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:GetDefaultFontSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetFontSize'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetSingleLine(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetSingleLine'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CCocosRichTextNodeForCocos:SetSingleLine");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetSingleLine'", nullptr);
            return 0;
        }
        cobj->SetSingleLine(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:SetSingleLine",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetSingleLine'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_visit(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_visit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        cocos2d::Mat4 arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0, "CCocosRichTextNodeForCocos:visit");

        ok &= luaval_to_mat4(tolua_S, 3, &arg1, "CCocosRichTextNodeForCocos:visit");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "CCocosRichTextNodeForCocos:visit");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_visit'", nullptr);
            return 0;
        }
        cobj->visit(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:visit",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_visit'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetDefaultFontName(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetDefaultFontName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CCocosRichTextNodeForCocos:SetDefaultFontName"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetDefaultFontName'", nullptr);
            return 0;
        }
        cobj->SetFontName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:SetDefaultFontName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetDefaultFontName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetHorizontalAlignment(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetHorizontalAlignment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetHorizontalAlignment'", nullptr);
            return 0;
        }
        int ret = (int)cobj->GetHorizontalAlignment();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:GetHorizontalAlignment",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetHorizontalAlignment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetBHCenter(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetBHCenter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CCocosRichTextNodeForCocos:SetBHCenter");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetBHCenter'", nullptr);
            return 0;
        }
        cobj->SetBHCenter(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:SetBHCenter",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetBHCenter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetHorizontalAlignment(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetHorizontalAlignment'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextHAlignment arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CCocosRichTextNodeForCocos:SetHorizontalAlignment");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetHorizontalAlignment'", nullptr);
            return 0;
        }
        cobj->SetHorizontalAlignment(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:SetHorizontalAlignment",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetHorizontalAlignment'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetDefaultFontColor(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetDefaultFontColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetDefaultFontColor'", nullptr);
            return 0;
        }
        std::string& ret = cobj->GetFontColor();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:GetDefaultFontColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetDefaultFontColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetLineAddMinY(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetLineAddMinY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetLineAddMinY'", nullptr);
            return 0;
        }
        double ret = cobj->GetLineAddMinY();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:GetLineAddMinY",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetLineAddMinY'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetRealContentWidth(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetRealContentWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetRealContentWidth'", nullptr);
            return 0;
        }
        double ret = cobj->GetRealContentWidth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:GetRealContentWidth",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetRealContentWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetDefaultFontColor(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetDefaultFontColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CCocosRichTextNodeForCocos:SetDefaultFontColor"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetDefaultFontColor'", nullptr);
            return 0;
        }
        cobj->SetFontColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:SetDefaultFontColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetDefaultFontColor'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetBVCenter(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetBVCenter'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CCocosRichTextNodeForCocos:SetBVCenter");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetBVCenter'", nullptr);
            return 0;
        }
        cobj->SetBVCenter(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:SetBVCenter",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetBVCenter'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetDataText(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetDataText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetDataText'", nullptr);
            return 0;
        }
        std::string& ret = cobj->GetDataText();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:GetDataText",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetDataText'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetLineAddMinY(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetLineAddMinY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "CCocosRichTextNodeForCocos:SetLineAddMinY");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetLineAddMinY'", nullptr);
            return 0;
        }
        cobj->SetLineAddMinY(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:SetLineAddMinY",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetLineAddMinY'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetDataText(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetDataText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CCocosRichTextNodeForCocos:SetDataText"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetDataText'", nullptr);
            return 0;
        }
        cobj->SetDataText(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        const char* arg0;
        bool arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CCocosRichTextNodeForCocos:SetDataText"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "CCocosRichTextNodeForCocos:SetDataText");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetDataText'", nullptr);
            return 0;
        }
        cobj->SetDataText(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:SetDataText",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetDataText'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetDefaultFontName(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCocosRichTextNodeForCocos*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetDefaultFontName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetDefaultFontName'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->GetFontName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:GetDefaultFontName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetDefaultFontName'.",&tolua_err);
#endif

    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CCocosRichTextNodeForCocos",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_create'", nullptr);
            return 0;
        }
        CCocosRichTextNodeForCocos* ret = CCocosRichTextNodeForCocos::create();
        object_to_luaval<CCocosRichTextNodeForCocos>(tolua_S, "CCocosRichTextNodeForCocos",(CCocosRichTextNodeForCocos*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CCocosRichTextNodeForCocos:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CCocosRichTextNodeForCocos* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_constructor'", nullptr);
            return 0;
        }
        cobj = new CCocosRichTextNodeForCocos();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CCocosRichTextNodeForCocos");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCocosRichTextNodeForCocos:CCocosRichTextNodeForCocos",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCocosRichTextNodeForCocos)");
    return 0;
}

int lua_register_cocos2dx_xiake_CCocosRichTextNodeForCocos(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CCocosRichTextNodeForCocos");
    tolua_cclass(tolua_S,"CCocosRichTextNodeForCocos","CCocosRichTextNodeForCocos","CCocosRichTextNode",nullptr);

    tolua_beginmodule(tolua_S,"CCocosRichTextNodeForCocos");
        tolua_function(tolua_S,"new",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_constructor);
        tolua_function(tolua_S,"SetFontSize", lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetFontSize);
        tolua_function(tolua_S,"GetBHCenter",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetBHCenter);
        tolua_function(tolua_S,"GetBVCenter",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetBVCenter);
        tolua_function(tolua_S,"GetFontSize", lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetFontSize);
        tolua_function(tolua_S,"SetSingleLine",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetSingleLine);
        tolua_function(tolua_S,"visit",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_visit);
        tolua_function(tolua_S,"SetDefaultFontName",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetDefaultFontName);
        tolua_function(tolua_S,"GetHorizontalAlignment",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetHorizontalAlignment);
        tolua_function(tolua_S,"SetBHCenter",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetBHCenter);
        tolua_function(tolua_S,"SetHorizontalAlignment",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetHorizontalAlignment);
        tolua_function(tolua_S,"GetDefaultFontColor",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetDefaultFontColor);
        tolua_function(tolua_S,"GetLineAddMinY",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetLineAddMinY);
        tolua_function(tolua_S,"GetRealContentWidth",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetRealContentWidth);
        tolua_function(tolua_S,"SetDefaultFontColor",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetDefaultFontColor);
        tolua_function(tolua_S,"SetBVCenter",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetBVCenter);
        tolua_function(tolua_S,"GetDataText",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetDataText);
        tolua_function(tolua_S,"SetLineAddMinY",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetLineAddMinY);
        tolua_function(tolua_S,"SetDataText",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_SetDataText);
        tolua_function(tolua_S,"GetDefaultFontName",lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_GetDefaultFontName);
        tolua_function(tolua_S,"create", lua_cocos2dx_xiake_CCocosRichTextNodeForCocos_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CCocosRichTextNodeForCocos).name();
    g_luaType[typeName] = "CCocosRichTextNodeForCocos";
    g_typeCast["CCocosRichTextNodeForCocos"] = "CCocosRichTextNodeForCocos";
    return 1;
}

int lua_cocos2dx_xiake_CNodeNoRelease_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CNodeNoRelease",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CNodeNoRelease_create'", nullptr);
            return 0;
        }
        CNodeNoRelease* ret = CNodeNoRelease::create();
        object_to_luaval<CNodeNoRelease>(tolua_S, "CNodeNoRelease",(CNodeNoRelease*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CNodeNoRelease:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CNodeNoRelease_create'.",&tolua_err);
#endif
    return 0;
}
int lua_cocos2dx_xiake_CNodeNoRelease_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CNodeNoRelease* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_xiake_CNodeNoRelease_constructor'", nullptr);
            return 0;
        }
        cobj = new CNodeNoRelease();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CNodeNoRelease");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNodeNoRelease:CNodeNoRelease",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_xiake_CNodeNoRelease_constructor'.",&tolua_err);
#endif
    return 0;
}

static int lua_cocos2dx_xiake_CNodeNoRelease_finalize(lua_State* tolua_S){
    printf("luabindings: finalizing LUA object (CNodeNoRelease)");
    return 0;
}

int lua_register_cocos2dx_xiake_CNodeNoRelease(lua_State* tolua_S){
    tolua_usertype(tolua_S,"CNodeNoRelease");
    tolua_cclass(tolua_S,"CNodeNoRelease","CNodeNoRelease","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"CNodeNoRelease");
        tolua_function(tolua_S,"new",lua_cocos2dx_xiake_CNodeNoRelease_constructor);
        tolua_function(tolua_S,"create", lua_cocos2dx_xiake_CNodeNoRelease_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CNodeNoRelease).name();
    g_luaType[typeName] = "CNodeNoRelease";
    g_typeCast["CNodeNoRelease"] = "CNodeNoRelease";
    return 1;
}


int lua_register_cocos2dx_xiake_AnimatePacker3(lua_State* tolua_S){
    tolua_usertype(tolua_S, "AnimatePacker3");
    tolua_cclass(tolua_S, "AnimatePacker3", "AnimatePacker3", "", nullptr);

    tolua_beginmodule(tolua_S, "AnimatePacker3");
    tolua_function(tolua_S, "GetInstance", [](lua_State* tolua_S)->int{
        AnimatePacker3* cobj = AnimatePacker3::GetInstance();
        object_to_luaval<AnimatePacker3>(tolua_S, "AnimatePacker3", cobj);
        return 1;
    });
    tolua_function(tolua_S, "loadAnimations", [](lua_State* tolua_S)->int{
        int argc = 0;
        AnimatePacker3* cobj = nullptr;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;

        if(!tolua_isusertype(tolua_S, 1, "AnimatePacker3", 0, &tolua_err)) goto tolua_lerror;
#endif

        cobj = (AnimatePacker3*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
        if(!cobj){
            tolua_error(tolua_S, "invalid 'cobj' in function 'loadAnimations'", nullptr);
            return 0;
        }
#endif

        argc = lua_gettop(tolua_S) - 1;
        if(argc == 1){
            const char* arg0;

            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "AnimatePacker3:loadAnimations"); arg0 = arg0_tmp.c_str();
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'loadAnimations'", nullptr);
                return 0;
            }
            cobj->loadAnimations(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "loadAnimations", argc, 0);
        return 0;

#if COCOS2D_DEBUG >= 1
        tolua_lerror:
                    tolua_error(tolua_S, "#ferror in function 'loadAnimations'.", &tolua_err);
#endif
        return 0;
    });
    tolua_function(tolua_S, "getAnimate", [](lua_State* tolua_S)->int{
        int argc = 0;
        AnimatePacker3* cobj = nullptr;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;

        if(!tolua_isusertype(tolua_S, 1, "AnimatePacker3", 0, &tolua_err)) goto tolua_lerror;
#endif

        cobj = (AnimatePacker3*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
        if(!cobj){
            tolua_error(tolua_S, "invalid 'cobj' in function 'getAnimate'", nullptr);
            return 0;
        }
#endif

        argc = lua_gettop(tolua_S) - 1;
        if(argc == 1){
            const char* arg0;

            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "AnimatePacker3:getAnimate"); arg0 = arg0_tmp.c_str();
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'getAnimate'", nullptr);
                return 0;
            }
            cocos2d::Animate* pRet = cobj->getAnimate(arg0);
            object_to_luaval<cocos2d::Animate>(tolua_S, "cc.Animate", pRet);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "getAnimate", argc, 0);
        return 0;

#if COCOS2D_DEBUG >= 1
        tolua_lerror:
                    tolua_error(tolua_S, "#ferror in function 'getAnimate'.", &tolua_err);
#endif
        return 0;
    });
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(AnimatePacker3).name();
    g_luaType[typeName] = "AnimatePacker3";
    g_typeCast["AnimatePacker3"] = "AnimatePacker3";
    return 1;
}

int lua_register_cocos2dx_xiake_SpriteFrameCache_XiaKe(lua_State* tolua_S){
    tolua_usertype(tolua_S, "SpriteFrameCache_XiaKe");
    tolua_cclass(tolua_S, "SpriteFrameCache_XiaKe", "SpriteFrameCache_XiaKe", "cc.SpriteFrameCache", nullptr);

    tolua_beginmodule(tolua_S, "SpriteFrameCache_XiaKe");
    tolua_function(tolua_S, "getInstanceXiaKe", [](lua_State* tolua_S)->int{
        SpriteFrameCache_XiaKe* cobj = SpriteFrameCache_XiaKe::getInstanceXiaKe();
        object_to_luaval<SpriteFrameCache_XiaKe>(tolua_S, "SpriteFrameCache_XiaKe", cobj);
        return 1;
    });
    tolua_function(tolua_S, "addSpriteFramesWithPlistFile", [](lua_State* tolua_S)->int{
        int argc = 0;
        SpriteFrameCache_XiaKe* cobj = nullptr;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;

        if(!tolua_isusertype(tolua_S, 1, "SpriteFrameCache_XiaKe", 0, &tolua_err)) goto tolua_lerror;
#endif

        cobj = (SpriteFrameCache_XiaKe*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
        if(!cobj){
            tolua_error(tolua_S, "invalid 'cobj' in function 'addSpriteFramesWithPlistFile'", nullptr);
            return 0;
        }
#endif

        argc = lua_gettop(tolua_S) - 1;
        if(argc == 2){
            std::string arg0;
            bool arg1;

            ok &= luaval_to_std_string(tolua_S, 2, &arg0, "addSpriteFramesWithPlistFile");
            ok &= luaval_to_boolean(tolua_S, 3, &arg1, "addSpriteFramesWithPlistFile");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_TMXObjectGroup_getProperty'", nullptr);
                return 0;
            }
            Texture2D* pRet = cobj->addSpriteFramesWithPlistFile(arg0, arg1);
            object_to_luaval<cocos2d::Texture2D>(tolua_S, "cc.Texture2D", (cocos2d::Texture2D*)pRet);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "loadAnimations", argc, 0);
        return 0;

#if COCOS2D_DEBUG >= 1
        tolua_lerror:
                    tolua_error(tolua_S, "#ferror in function 'loadAnimations'.", &tolua_err);
#endif
                    return 0;
    });

    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SpriteFrameCache_XiaKe).name();
    g_luaType[typeName] = "SpriteFrameCache_XiaKe";
    g_typeCast["SpriteFrameCache_XiaKe"] = "SpriteFrameCache_XiaKe";
    return 1;
}

int lua_register_cocos2dx_xiake_CLikeWidget(lua_State* tolua_S){
    tolua_usertype(tolua_S, "CLikeWidget");
    tolua_cclass(tolua_S, "CLikeWidget", "CLikeWidget", "ccui.Widget", nullptr);

    tolua_beginmodule(tolua_S, "CLikeWidget");
    tolua_function(tolua_S, "new", [](lua_State* tolua_S)->int{
        int argc = 0;
        CLikeWidget* cobj = nullptr;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;
#endif
        argc = lua_gettop(tolua_S) - 1;
        if(argc == 0){
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_xiake_CNodeNoRelease_constructor'", nullptr);
                return 0;
            }
            cobj = new CLikeWidget();
            cobj->autorelease();
            int ID = (int)cobj->_ID;
            int* luaID = &cobj->_luaID;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, "CNodeNoRelease");
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CNodeNoRelease:CNodeNoRelease", argc, 0);
        return 0;

#if COCOS2D_DEBUG >= 1
        tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_xiake_CNodeNoRelease_constructor'.", &tolua_err);
#endif
        return 0;
    });
    tolua_function(tolua_S, "create", [](lua_State* tolua_S)->int{
        int argc = 0;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
        if(!tolua_isusertable(tolua_S, 1, "CNodeNoRelease", 0, &tolua_err)) goto tolua_lerror;
#endif

        argc = lua_gettop(tolua_S) - 1;

        if(argc == 0){
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_xiake_CNodeNoRelease_create'", nullptr);
                return 0;
            }
            CLikeWidget* ret = CLikeWidget::create();
            object_to_luaval<CLikeWidget>(tolua_S, "CNodeNoRelease", (CLikeWidget*)ret);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CNodeNoRelease:create", argc, 0);
        return 0;
#if COCOS2D_DEBUG >= 1
        tolua_lerror:
                    tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_xiake_CNodeNoRelease_create'.", &tolua_err);
#endif
        return 0;
    });
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CLikeWidget).name();
    g_luaType[typeName] = "CLikeWidget";
    g_typeCast["CLikeWidget"] = "CLikeWidget";
    return 1;
}


int lua_register_cocos2dx_xiake_CMapTMXCache(lua_State* tolua_S){
    tolua_usertype(tolua_S, "CMapTMXCache");
    tolua_cclass(tolua_S, "CMapTMXCache", "CMapTMXCache", "", nullptr);

    tolua_beginmodule(tolua_S, "CMapTMXCache");
    tolua_function(tolua_S, "GetInstance", [](lua_State* tolua_S)->int{
        CMapTMXCache* cobj = CMapTMXCache::GetInstance();
        object_to_luaval<CMapTMXCache>(tolua_S, "CMapTMXCache", cobj);
        return 1;
    });
    tolua_function(tolua_S, "InitMapTMXCache", [](lua_State* tolua_S)->int{
        int argc = 0;
        CMapTMXCache* cobj = nullptr;
        bool ok = true;

        cobj = (CMapTMXCache*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
        if(!cobj){
            tolua_error(tolua_S, "invalid 'cobj' in function 'InitMapTMXCache'", nullptr);
            return 0;
        }
#endif

        argc = lua_gettop(tolua_S) - 1;
        if(argc == 1){
            LUA_FUNCTION handler = toluafix_ref_function(tolua_S, 2, 0);
            cocos2d::ScriptHandlerMgr::getInstance()->addCustomHandler((void*)cobj, handler);

            cobj->InitMapTMXCache([=](const char* pMapFile, std::string& strResourceset)->bool{
                bool bRet = false;
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->pushString(pMapFile);
                stack->executeFunction(handler, 1, 2, [&strResourceset, &bRet](lua_State* L, int nNumber){
                    bRet = lua_toboolean(L, 1);
                    strResourceset = lua_tostring(L, 2);
                });
                stack->clean();
                return bRet;
            });
            lua_settop(tolua_S, 1);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "loadAnimations", argc, 0);
        return 0;
    });
    tolua_function(tolua_S, "GetTMXMap", [](lua_State* tolua_S)->int{
        int argc = 0;
        CMapTMXCache* cobj = nullptr;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;

        if(!tolua_isusertype(tolua_S, 1, "CMapTMXCache", 0, &tolua_err)) goto tolua_lerror;
#endif

        cobj = (CMapTMXCache*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
        if(!cobj){
            tolua_error(tolua_S, "invalid 'cobj' in function 'GetTMXMap'", nullptr);
            return 0;
        }
#endif

        argc = lua_gettop(tolua_S) - 1;
        if(argc == 1){
            const char* arg0;

            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMapTMXCache:GetTMXMap"); arg0 = arg0_tmp.c_str();
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'GetTMXMap'", nullptr);
                return 0;
            }
            auto pRet = cobj->GetTMXMap(arg0);
            object_to_luaval<cocos2d::experimental::TMXTiledMap>(tolua_S, "ccexp.TMXTiledMap", pRet);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "getAnimate", argc, 0);
        return 0;

#if COCOS2D_DEBUG >= 1
        tolua_lerror:
                    tolua_error(tolua_S, "#ferror in function 'getAnimate'.", &tolua_err);
#endif
                    return 0;
    });
    tolua_function(tolua_S, "GetTexture2DCacheByFiles", [](lua_State* tolua_S)->int{
        int argc = 0;
        CMapTMXCache* cobj = nullptr;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;

        if(!tolua_isusertype(tolua_S, 1, "CMapTMXCache", 0, &tolua_err)) goto tolua_lerror;
#endif

        cobj = (CMapTMXCache*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
        if(!cobj){
            tolua_error(tolua_S, "invalid 'cobj' in function 'GetTexture2DCacheByFiles'", nullptr);
            return 0;
        }
#endif

        argc = lua_gettop(tolua_S) - 1;
        if(argc == 1){
            const char* arg0;
            bool arg1;

            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMapTMXCache:GetTexture2DCacheByFiles"); arg0 = arg0_tmp.c_str();
            ok &= luaval_to_boolean(tolua_S, 3, &arg1, "GetTexture2DCacheByFiles");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'GetTMXMap'", nullptr);
                return 0;
            }
            auto pRet = cobj->GetTexture2DCacheByFiles(arg0, arg1);
            object_to_luaval<cocos2d::Texture2D>(tolua_S, "cc.Texture2D", (cocos2d::Texture2D*)pRet);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GetTexture2DCacheByFiles", argc, 0);
        return 0;

#if COCOS2D_DEBUG >= 1
        tolua_lerror:
                    tolua_error(tolua_S, "#ferror in function 'GetTexture2DCacheByFiles'.", &tolua_err);
#endif
                    return 0;
    });
    tolua_function(tolua_S, "PreLoadTexture2DCache", [](lua_State* tolua_S)->int{
        int argc = 0;
        CMapTMXCache* cobj = nullptr;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;

        if(!tolua_isusertype(tolua_S, 1, "CMapTMXCache", 0, &tolua_err)) goto tolua_lerror;
#endif

        cobj = (CMapTMXCache*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
        if(!cobj){
            tolua_error(tolua_S, "invalid 'cobj' in function 'PreLoadTexture2DCache'", nullptr);
            return 0;
        }
#endif

        argc = lua_gettop(tolua_S) - 1;
        if(argc == 1){
            const char* arg0;
            bool arg1;

            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMapTMXCache:PreLoadTexture2DCache"); arg0 = arg0_tmp.c_str();
            ok &= luaval_to_boolean(tolua_S, 3, &arg1, "PreLoadTexture2DCache");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'GetTMXMap'", nullptr);
                return 0;
            }
            cobj->PreLoadTexture2DCache(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GetTexture2DCacheByFiles", argc, 0);
        return 0;

#if COCOS2D_DEBUG >= 1
        tolua_lerror:
                    tolua_error(tolua_S, "#ferror in function 'GetTexture2DCacheByFiles'.", &tolua_err);
#endif
                    return 0;
    });
    tolua_function(tolua_S, "AddNoUpdateCompent", [](lua_State* tolua_S)->int{
        int argc = 0;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
        if(!tolua_isusertable(tolua_S, 1, "CMapTMXCache", 0, &tolua_err)) goto tolua_lerror;
#endif

        argc = lua_gettop(tolua_S) - 1;

        if(argc == 2){
            cocos2d::Node* arg0;
            cocos2d::Component* arg1;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node", &arg0, "CMapTMXCache:AddNoUpdateCompent");
            ok &= luaval_to_object<cocos2d::Component>(tolua_S, 3, "cc.Component", &arg1, "CMapTMXCache:AddNoUpdateCompent");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'AddNoUpdateCompent'", nullptr);
                return 0;
            }
            CMapTMXCache::AddNoUpdateCompent(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMapTMXCache:AddNoUpdateCompent", argc, 2);
        return 0;
#if COCOS2D_DEBUG >= 1
        tolua_lerror:
                    tolua_error(tolua_S, "#ferror in function 'AddNoUpdateCompent'.", &tolua_err);
#endif
                    return 0;
    });
    tolua_function(tolua_S, "AddClearNodeChildsListView", [](lua_State* tolua_S)->int{
        int argc = 0;
        CMapTMXCache* cobj = nullptr;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;

        if(!tolua_isusertype(tolua_S, 1, "CMapTMXCache", 0, &tolua_err)) goto tolua_lerror;
#endif

        cobj = (CMapTMXCache*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
        if(!cobj){
            tolua_error(tolua_S, "invalid 'cobj' in function 'PreLoadTexture2DCache'", nullptr);
            return 0;
        }
#endif

        argc = lua_gettop(tolua_S) - 1;
        if(argc == 1){
            cocos2d::ui::ListView* arg0;
            ok &= luaval_to_object<cocos2d::ui::ListView>(tolua_S, 2, "ccui.ListView", &arg0, "CLuaGlobalFunc:AddClearNodeChildsListView");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_xiake_CLuaGlobalFunc_AddClearNodeChildsListView'", nullptr);
                return 0;
            }
            cobj->AddClearNodeChildsListView(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CLuaGlobalFunc:AddClearNodeChildsListView", argc, 1);
        return 0;
#if COCOS2D_DEBUG >= 1
        tolua_lerror:
                    tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_xiake_CLuaGlobalFunc_AddClearNodeChildsListView'.", &tolua_err);
#endif
                    return 0;
    });
    tolua_function(tolua_S, "AddClearNodeChilds", [](lua_State* tolua_S)->int{
        int argc = 0;
        CMapTMXCache* cobj = nullptr;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;

        if(!tolua_isusertype(tolua_S, 1, "CMapTMXCache", 0, &tolua_err)) goto tolua_lerror;
#endif

        cobj = (CMapTMXCache*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
        if(!cobj){
            tolua_error(tolua_S, "invalid 'cobj' in function 'PreLoadTexture2DCache'", nullptr);
            return 0;
        }
#endif

        argc = lua_gettop(tolua_S) - 1;
        if(argc == 1){
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node", &arg0, "CLuaGlobalFunc:AddClearNodeChilds");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_xiake_CLuaGlobalFunc_AddClearNodeChilds'", nullptr);
                return 0;
            }
            cobj->AddClearNodeChilds(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CLuaGlobalFunc:AddClearNodeChildsListView", argc, 1);
        return 0;
#if COCOS2D_DEBUG >= 1
        tolua_lerror:
                    tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_xiake_CLuaGlobalFunc_AddClearNodeChildsListView'.", &tolua_err);
#endif
                    return 0;
    });
    tolua_function(tolua_S, "AddClearNode", [](lua_State* tolua_S)->int{
        int argc = 0;
        CMapTMXCache* cobj = nullptr;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;

        if(!tolua_isusertype(tolua_S, 1, "CMapTMXCache", 0, &tolua_err)) goto tolua_lerror;
#endif

        cobj = (CMapTMXCache*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
        if(!cobj){
            tolua_error(tolua_S, "invalid 'cobj' in function 'PreLoadTexture2DCache'", nullptr);
            return 0;
        }
#endif

        argc = lua_gettop(tolua_S) - 1;
        if(argc == 1){
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node", &arg0, "CLuaGlobalFunc:AddClearNode");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_xiake_CLuaGlobalFunc_AddClearNode'", nullptr);
                return 0;
            }
            cobj->AddClearNode(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CLuaGlobalFunc:AddClearNodeChildsListView", argc, 1);
        return 0;
#if COCOS2D_DEBUG >= 1
        tolua_lerror:
                    tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_xiake_CLuaGlobalFunc_AddClearNodeChildsListView'.", &tolua_err);
#endif
                    return 0;
    });
    tolua_function(tolua_S, "AddClearNode", [](lua_State* tolua_S)->int{
        int argc = 0;
        CMapTMXCache* cobj = nullptr;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;

        if(!tolua_isusertype(tolua_S, 1, "CMapTMXCache", 0, &tolua_err)) goto tolua_lerror;
#endif

        cobj = (CMapTMXCache*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
        if(!cobj){
            tolua_error(tolua_S, "invalid 'cobj' in function 'PreLoadTexture2DCache'", nullptr);
            return 0;
        }
#endif

        argc = lua_gettop(tolua_S) - 1;
        if(argc == 1){
            cocos2d::ui::PageView* arg0;
            ok &= luaval_to_object<cocos2d::ui::PageView>(tolua_S, 2, "ccui.PageView", &arg0, "CLuaGlobalFunc:AddClearNodeChildsPageView");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_xiake_CLuaGlobalFunc_AddClearNodeChildsPageView'", nullptr);
                return 0;
            }
            cobj->AddClearNodeChildsPageView(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CLuaGlobalFunc:AddClearNodeChildsListView", argc, 1);
        return 0;
#if COCOS2D_DEBUG >= 1
        tolua_lerror:
                    tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_xiake_CLuaGlobalFunc_AddClearNodeChildsListView'.", &tolua_err);
#endif
                    return 0;
    });
    tolua_function(tolua_S, "SetNodeNormalState", [](lua_State* tolua_S)->int{
        int argc = 0;
        CMapTMXCache* cobj = nullptr;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;

        if(!tolua_isusertype(tolua_S, 1, "CMapTMXCache", 0, &tolua_err)) goto tolua_lerror;
#endif

        cobj = (CMapTMXCache*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
        if(!cobj){
            tolua_error(tolua_S, "invalid 'cobj' in function 'PreLoadTexture2DCache'", nullptr);
            return 0;
        }
#endif

        argc = lua_gettop(tolua_S) - 1;
        if(argc == 2){
            cocos2d::Node* arg0;
            bool arg1;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node", &arg0, "CLuaGlobalFunc:SetNodeNormalState");
            ok &= luaval_to_boolean(tolua_S, 3, &arg1, "CLuaGlobalFunc:SetNodeNormalState");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_xiake_CLuaGlobalFunc_SetNodeNormalState'", nullptr);
                return 0;
            }
            cobj->SetNodeNormalState(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CLuaGlobalFunc:AddClearNodeChildsListView", argc, 1);
        return 0;
#if COCOS2D_DEBUG >= 1
        tolua_lerror:
                    tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_xiake_CLuaGlobalFunc_AddClearNodeChildsListView'.", &tolua_err);
#endif
                    return 0;
    });
    tolua_function(tolua_S, "IsNodeNormalState", [](lua_State* tolua_S)->int{
        int argc = 0;
        CMapTMXCache* cobj = nullptr;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;

        if(!tolua_isusertype(tolua_S, 1, "CMapTMXCache", 0, &tolua_err)) goto tolua_lerror;
#endif

        cobj = (CMapTMXCache*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
        if(!cobj){
            tolua_error(tolua_S, "invalid 'cobj' in function 'PreLoadTexture2DCache'", nullptr);
            return 0;
        }
#endif

        argc = lua_gettop(tolua_S) - 1;
        if(argc == 1){
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node", &arg0, "CLuaGlobalFunc:IsNodeNormalState");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_xiake_CLuaGlobalFunc_IsNodeNormalState'", nullptr);
                return 0;
            }
            bool ret = cobj->IsNodeNormalState(arg0);
            tolua_pushboolean(tolua_S, (bool)ret);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CLuaGlobalFunc:AddClearNodeChildsListView", argc, 1);
        return 0;
#if COCOS2D_DEBUG >= 1
        tolua_lerror:
                    tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_xiake_CLuaGlobalFunc_AddClearNodeChildsListView'.", &tolua_err);
#endif
                    return 0;
    });
    tolua_function(tolua_S, "AddContentWidthHeight", [](lua_State* tolua_S)->int{
        int argc = 0;
        CMapTMXCache* cobj = nullptr;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;

        if(!tolua_isusertype(tolua_S, 1, "CMapTMXCache", 0, &tolua_err)) goto tolua_lerror;
#endif

        cobj = (CMapTMXCache*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
        if(!cobj){
            tolua_error(tolua_S, "invalid 'cobj' in function 'PreLoadTexture2DCache'", nullptr);
            return 0;
        }
#endif

        argc = lua_gettop(tolua_S) - 1;
        if(argc == 3){
            cocos2d::Node* arg0;
            double arg1, arg2;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node", &arg0, "CLuaGlobalFunc:AddContentWidthHeight");
            ok &= luaval_to_number(tolua_S, 3, &arg1, "AddContentWidthHeight");
            ok &= luaval_to_number(tolua_S, 4, &arg2, "AddContentWidthHeight");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_xiake_CLuaGlobalFunc_IsNodeNormalState'", nullptr);
                return 0;
            }
            cobj->AddContentWidthHeight(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CLuaGlobalFunc:AddClearNodeChildsListView", argc, 1);
        return 0;
#if COCOS2D_DEBUG >= 1
        tolua_lerror:
                    tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_xiake_CLuaGlobalFunc_AddClearNodeChildsListView'.", &tolua_err);
#endif
                    return 0;
    });
    tolua_function(tolua_S, "CreateTextureByData", [](lua_State* tolua_S)->int{
        int argc = 0;
        CMapTMXCache* cobj = nullptr;
        bool ok = true;

#if COCOS2D_DEBUG >= 1
        tolua_Error tolua_err;

        if(!tolua_isusertype(tolua_S, 1, "CMapTMXCache", 0, &tolua_err)) goto tolua_lerror;
#endif

        cobj = (CMapTMXCache*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
        if(!cobj){
            tolua_error(tolua_S, "invalid 'cobj' in function 'CreateTextureByData'", nullptr);
            return 0;
        }
#endif

        argc = lua_gettop(tolua_S) - 1;
        if(argc == 2){
            const char* arg0;
            int arg1;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CMapTMXCache:CreateTextureByData"); arg0 = arg0_tmp.c_str();
            ok &= luaval_to_int32(tolua_S, 3, &arg1, "CreateTextureByData");
            if(!ok){
                tolua_error(tolua_S, "invalid arguments in function 'lua_cocos2dx_xiake_CLuaGlobalFunc_IsNodeNormalState'", nullptr);
                return 0;
            }
            auto pRet = cobj->CreateTextureByData(arg0, arg1);
            object_to_luaval<cocos2d::Texture2D>(tolua_S, "cc.Texture2D", (cocos2d::Texture2D*)pRet);
            return 1;
        }
        luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CLuaGlobalFunc:AddClearNodeChildsListView", argc, 1);
        return 0;
#if COCOS2D_DEBUG >= 1
        tolua_lerror:
                    tolua_error(tolua_S, "#ferror in function 'lua_cocos2dx_xiake_CLuaGlobalFunc_AddClearNodeChildsListView'.", &tolua_err);
#endif
                    return 0;
    });
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMapTMXCache).name();
    g_luaType[typeName] = "CMapTMXCache";
    g_typeCast["CMapTMXCache"] = "CMapTMXCache";
    return 1;
}

TOLUA_API int register_all_cocos2dx_xiake(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"xiake",0);
	tolua_beginmodule(tolua_S,"xiake");

	lua_register_cocos2dx_xiake_CNodeNoRelease(tolua_S);
	lua_register_cocos2dx_xiake_CCocosRichTextNodeClkNotify(tolua_S);
	lua_register_cocos2dx_xiake_CDyListViewLoadLayout(tolua_S);
	lua_register_cocos2dx_xiake_CDyListView(tolua_S);
	lua_register_cocos2dx_xiake_CCocosRichTextNode(tolua_S);
	lua_register_cocos2dx_xiake_CCocosRichTextNodeForCocos(tolua_S);
    lua_register_cocos2dx_xiake_AnimatePacker3(tolua_S);
    lua_register_cocos2dx_xiake_SpriteFrameCache_XiaKe(tolua_S);
    lua_register_cocos2dx_xiake_CLikeWidget(tolua_S);
    lua_register_cocos2dx_xiake_CMapTMXCache(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

