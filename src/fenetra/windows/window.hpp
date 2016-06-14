///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: window.hpp
///
/// Author: $author$
///   Date: 6/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _FENETRA_WINDOWS_WINDOW_HPP
#define _FENETRA_WINDOWS_WINDOW_HPP

#include "fenetra/windows/message_target.hpp"

#define FENETRA_WINDOWS_DEFAULT_WINDOW_STYLE \
    WS_VISIBLE | WS_OVERLAPPED | WS_THICKFRAME | \
    WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX

#define FENETRA_WINDOWS_DEFAULT_WINDOW_EXSTYLE 0

namespace fenetra {
namespace windows {

typedef message_target window_implements;
typedef hwnd window_extends;
///////////////////////////////////////////////////////////////////////
///  Class: windowt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = window_implements, class TExtends = window_extends>
class _EXPORT_CLASS windowt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Extends::attached_t attached_t;
    typedef typename Extends::unattached_t unattached_t;
    enum { unattached = typename Extends::unattached };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    windowt
    (HINSTANCE instance = 0, HWND detached = 0, bool is_created = false)
    : Extends(instance, detached, is_created) {
    }
    virtual ~windowt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create
    (HINSTANCE hInstance, LPCSTR className, 
     LPCSTR windowName = NULL, HWND hParentWnd = NULL_HANDLE, 
     HMENU hMenu = NULL_HANDLE, DWORD style = FENETRA_WINDOWS_DEFAULT_WINDOW_STYLE,
     DWORD exStyle = FENETRA_WINDOWS_DEFAULT_WINDOW_EXSTYLE, 
     int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, 
     int width = CW_USEDEFAULT, int height = CW_USEDEFAULT,
     LPVOID lParam = NULL) {
        bool isSuccess = create
        (exStyle, className, windowName, style, 
         x,y, width,height, hParentWnd, hMenu, hInstance, lParam);
        return isSuccess;
    }
    virtual bool create
    (DWORD exStyle, LPCSTR className, LPCSTR windowName, DWORD style, 
     int x, int y, int width, int height, HWND hParentWnd, HMENU hMenu, 
     HINSTANCE hInstance, LPVOID lParam) {
        HWND detached = 0;
        if ((detached = create_attached
            (exStyle, className, windowName, style, 
             x, y, width, height, hParentWnd, hMenu, hInstance, 
             (lParam)?(lParam):((message_target*)(this))))) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual bool destroy() {
        bool isSuccess = true;
        bool wasDestroyed = this->was_destroyed();
        HWND detached = 0;
        if ((detached = this->detach())) {
            if (!(wasDestroyed)) {
                isSuccess = destroy_detached(detached);
            }
        }
        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual HWND create_attached
    (HINSTANCE hInstance, LPCSTR className, 
     LPCSTR windowName = NULL, HWND hParentWnd = NULL_HANDLE, 
     HMENU hMenu = NULL_HANDLE, DWORD style = FENETRA_WINDOWS_DEFAULT_WINDOW_STYLE,
     DWORD exStyle = FENETRA_WINDOWS_DEFAULT_WINDOW_EXSTYLE, 
     int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, 
     int width = CW_USEDEFAULT, int height = CW_USEDEFAULT,
     LPVOID lParam = NULL) {
        HWND detached = create_attached
        (exStyle, className, windowName, style, 
         x,y, width,height, hParentWnd, hMenu, hInstance, lParam);
        return detached;
    }
    virtual HWND create_attached
    (DWORD exStyle, LPCSTR className, LPCSTR windowName, DWORD style, 
     int x, int y, int width, int height, HWND hParentWnd, HMENU hMenu, 
     HINSTANCE hInstance, LPVOID lParam) {
        HWND detached = NULL;
        if ((this->destroyed())) {
            if ((detached = create_detached
                (exStyle, className, windowName, style, 
                 x, y, width, height, hParentWnd, hMenu, hInstance, 
                 (lParam)?(lParam):((message_target*)(this))))) {
                this->attach(detached);
                this->attach_instance(hInstance);
            }
        }
        return detached;
    }
    virtual HWND create_detached
    (DWORD exStyle, LPCSTR className, LPCSTR windowName, DWORD style, 
     int x, int y, int width, int height, HWND hParentWnd, HMENU hMenu, 
     HINSTANCE hInstance, LPVOID lParam) const {
        HWND detached = NULL;
        if (!(NULL != (detached = CreateWindowExA
            (exStyle, className, windowName, style, 
             x, y, width, height, hParentWnd, hMenu, hInstance, lParam)))) {
            DWORD dwError = GetLastError();
            FENETRA_LOG_ERROR("...failed " << dwError << " on CreateWindowExA()"); 
        }
        return detached;
    }
    virtual bool destroy_detached(HWND detached) const {
        bool isSuccess = false;
        if ((detached)) {
            if (!(isSuccess = (FALSE != DestroyWindow(detached)))) {
                DWORD dwError = GetLastError();
                FENETRA_LOG_ERROR("...failed " << dwError << " on DestroyWindow()"); 
            }
        }
        return isSuccess;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Show(int nCmdShow = SW_SHOWNORMAL) {
        HWND hWnd = 0;
        if ((hWnd = this->attached_to())) {
            if ((ShowWindow(hWnd, nCmdShow))) {
                return true;
            }
        }
        return false;
    }
    virtual bool Hide(int nCmdShow = SW_HIDE) {
        return Show(nCmdShow);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Invalidate(bool eraseBackground = true) {
        HWND hWnd = 0;
        if ((hWnd = this->attached_to())) {
            if ((InvalidateRect(hWnd, NULL, eraseBackground))) {
                return true;
            }
        }
        return false;
    }
    virtual bool Validate() {
        HWND hWnd = 0;
        if ((hWnd = this->attached_to())) {
            if ((ValidateRect(hWnd, NULL))) {
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetSize(int width, int height) {
        HWND hWnd = 0;
        if ((hWnd = this->attached_to())) {
            RECT rect;
            if ((GetWindowRect(hWnd, &rect))) {
                HWND hWndParent = 0;
                if ((hWndParent = GetParent(hWnd))) {
                    POINT p;
                    p.x = rect.left;
                    p.y = rect.top;
                    if ((ScreenToClient(hWndParent, &p))) {
                        rect.left = p.y;
                        rect.top = p.y;
                    } else {
                        return false;
                    }
                }
                if ((SetWindowPos(hWnd, NULL, rect.left,rect.top, width,height, 0))) {
                    return true;
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual LRESULT on_WM_NCDESTROY_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        this->was_destroyed();
        return lResult;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef windowt<> window;

} // namespace windows 
} // namespace fenetra 

#endif // _FENETRA_WINDOWS_WINDOW_HPP 
