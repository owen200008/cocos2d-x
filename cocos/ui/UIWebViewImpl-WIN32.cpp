/****************************************************************************
 Copyright (c) 2014-2017 Chukong Technologies Inc.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

#include "ui/UIWebView.h"
#include "platform/CCGLView.h"
#include "base/CCDirector.h"
#include "platform/CCFileUtils.h"

#include "UIWebViewImpl-WIN32.h"
#include "renderer/CCRenderer.h"
//void JScallback(Evas_Object* o, const char* result_value, void* user_data)
//{
//}
static bool g_win32WebKitInit = false;
// 回调：创建新的页面，比如说调用了 window.open 或者点击了 <a target="_blank" .../>
wkeWebView HandleCreateView(wkeWebView webWindow, void* param, wkeNavigationType navType, const wkeString url, const wkeWindowFeatures* features){
    wkeWebView newWindow = wkeCreateWebWindow(WKE_WINDOW_TYPE_CONTROL, NULL, features->x, features->y, features->width, features->height);
    wkeShowWindow(newWindow, true);
    return newWindow;
}

namespace cocos2d {
    namespace experimental {
        namespace ui{

            WebViewImpl::WebViewImpl(WebView *webView) : _webView(webView) {
                if(false == g_win32WebKitInit){
                    wkeInitialize();
                    g_win32WebKitInit = true;
                }
                m_hView = Director::getInstance()->getOpenGLView()->getWin32Window();
                m_pixels = nullptr;
                m_hBitmap = nullptr;
                m_hDC = CreateCompatibleDC(0);
                m_pImplWebView = wkeCreateWebView();
                wkeSetUserKeyValue(m_pImplWebView, "CocosWebView", this);
                wkeSetHandle(m_pImplWebView, m_hView);
            }

            WebViewImpl::~WebViewImpl() {
                if(m_hBitmap)
                    DeleteObject(m_hBitmap);
                if(m_hDC)
                    DeleteDC(m_hDC);
                if(m_pImplWebView)
                    wkeDestroyWebView(m_pImplWebView);
            }

            void WebViewImpl::loadData(const Data &data, const std::string &MIMEType, const std::string &encoding, const std::string &baseURL) {
                const char* contents = nullptr;
                size_t contents_size = 0;
                char* mime_type = (char*)MIMEType.c_str();
                char* encode = (char*)encoding.c_str();
                char* base_uri = (char*)baseURL.c_str();
                //ewk_view_contents_set(_ewkView, contents, contents_size, mime_type, encode, base_uri);
            }

            void WebViewImpl::loadHTMLString(const std::string &string, const std::string &baseURL) {
                const char* contents = string.c_str();
                size_t contents_size = string.length();
                char* mime_type = (char*)baseURL.c_str();
                char* encoding = nullptr;
                char* base_uri = nullptr;//(char*)baseURL.c_str();
                wkeLoadHTML(m_pImplWebView, mime_type);
            }

            void WebViewImpl::loadURL(const std::string &url) {
                const char* urlchar = url.c_str();
                wkeLoadURL(m_pImplWebView, urlchar);
            }

            void WebViewImpl::loadURL(const std::string &url, bool cleanCachedData) {
                this->loadURL(url);
            }

            void WebViewImpl::loadFile(const std::string &fileName) {
                auto fileUtiles = FileUtils::getInstance();
                auto fileFullPath = fileUtiles->fullPathForFilename(fileName);
                auto contentsString = fileUtiles->getStringFromFile(fileFullPath);
                loadHTMLString(contentsString, "text/html");
            }

            void WebViewImpl::stopLoading() {
                //ewk_view_stop(_ewkView);
            }

            void WebViewImpl::reload() {
                //ewk_view_reload(_ewkView);
            }

            bool WebViewImpl::canGoBack() {
                return true;
                //return ewk_view_back_possible(_ewkView);
            }

            bool WebViewImpl::canGoForward() {
                return true;
                //return ewk_view_forward_possible(_ewkView);
            }

            void WebViewImpl::goBack() {
                //ewk_view_back(_ewkView);
            }

            void WebViewImpl::goForward() {
                //ewk_view_forward(_ewkView);
            }

            void WebViewImpl::setJavascriptInterfaceScheme(const std::string &scheme) {
            }

            void WebViewImpl::evaluateJS(const std::string &js) {
                const char* script = js.c_str();
                //Eina_Bool ret = ewk_view_script_execute(_ewkView, script, JScallback, this);
            }

            void WebViewImpl::setScalesPageToFit(const bool scalesPageToFit) {
            }
            void WebViewImpl::createBitmap(){
                auto directorInstance = cocos2d::Director::getInstance();
                auto glView = directorInstance->getOpenGLView();
                auto frameSize = glView->getFrameSize();
                auto winSize = directorInstance->getWinSize();

                auto leftBottom = this->_webView->convertToWorldSpace(cocos2d::Point::ZERO);
                auto rightTop = this->_webView->convertToWorldSpace(cocos2d::Point(this->_webView->getContentSize().width, this->_webView->getContentSize().height));

                wkeResize(m_pImplWebView, (rightTop.x - leftBottom.x) * glView->getScaleX(), (rightTop.y - leftBottom.y) * glView->getScaleY());

                BITMAPINFO bi;
                memset(&bi, 0, sizeof(bi));
                bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
                bi.bmiHeader.biWidth = int((rightTop.x - leftBottom.x) * glView->getScaleX());
                bi.bmiHeader.biHeight = -int((rightTop.y - leftBottom.y) * glView->getScaleY());
                bi.bmiHeader.biPlanes = 1;
                bi.bmiHeader.biBitCount = 32;
                bi.bmiHeader.biCompression = BI_RGB;
  
                HBITMAP hbmp = ::CreateDIBSection(0, &bi, DIB_RGB_COLORS, &m_pixels, NULL, 0);
  
                SelectObject(m_hDC, hbmp);
  
                if (m_hBitmap)
                  DeleteObject(m_hBitmap);
 
                m_hBitmap = hbmp;
            }
            void WebViewImpl::onDraw(const Mat4& transform, bool /*transformUpdated*/){
                if(m_pixels){
                    wkePaint(m_pImplWebView, m_pixels, 0);

                    HDC hDC = GetDC(m_hView);
                    BitBlt(hDC, 0, 0, wkeGetWidth(m_pImplWebView), wkeGetHeight(m_pImplWebView), m_hDC, 0, 0, SRCCOPY);
                    ReleaseDC(m_hView, hDC);
                }
            }
            void WebViewImpl::draw(cocos2d::Renderer *renderer, cocos2d::Mat4 const &transform, int flags) {
                // Don't do calculate the culling if the transform was not updated
                bool transformUpdated = flags & cocos2d::Node::FLAGS_TRANSFORM_DIRTY;
                if (transformUpdated) {
                    createBitmap();
                    /*HWND pHwnd = Director::getInstance()->getOpenGLView()->getWin32Window();
                    PAINTSTRUCT ps = { 0 };
                    HDC hdc = ::BeginPaint(pHwnd, &ps);

                    RECT rcClip = ps.rcPaint;

                    RECT rcClient;
                    ::GetClientRect(pHwnd, &rcClient);

                    RECT rcInvalid = rcClient;
                    if(rcClip.right != rcClip.left && rcClip.bottom != rcClip.top)
                        ::IntersectRect(&rcInvalid, &rcClip, &rcClient);

                    int srcX = rcInvalid.left - rcClient.left;
                    int srcY = rcInvalid.top - rcClient.top;
                    int destX = rcInvalid.left;
                    int destY = rcInvalid.top;
                    int width = rcInvalid.right - rcInvalid.left;
                    int height = rcInvalid.bottom - rcInvalid.top;

                    if(0 != width && 0 != height)
                        ::BitBlt(hdc, destX, destY, width, height, wkeGetViewDC(m_pImplWebView), srcX, srcY, SRCCOPY);

                    ::EndPaint(pHwnd, &ps);*/
                }

                _customCommand.init(_webView->getGlobalZOrder(), transform, flags);
                _customCommand.func = CC_CALLBACK_0(WebViewImpl::onDraw, this, transform, transformUpdated);
                renderer->addCommand(&_customCommand);
            }

            void WebViewImpl::setVisible(bool visible) {
                //wkeShowWindow(m_pImplWebView, visible);
            }

            void WebViewImpl::setBounces(bool bounces) {
                // empty function as this was mainly a fix for iOS
            }

            void WebViewImpl::setOpacityWebView(float opacity){
                //TODO
            }
        
            float WebViewImpl::getOpacityWebView() const{
                //TODO
                return 0.0f;
            }
        
            void WebViewImpl::setBackgroundTransparent(){
                //TODO
            }
        } // namespace ui
    } // namespace experimental
} //namespace cocos2d

#endif // #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
