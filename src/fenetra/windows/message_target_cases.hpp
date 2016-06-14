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
///   File: message_target_cases.hpp
///
/// Author: $author$
///   Date: 6/13/2016
///////////////////////////////////////////////////////////////////////
#ifndef _FENETRA_WINDOWS_MESSAGE_TARGET_HPP
#include "fenetra/windows/hwnd.hpp"

namespace fenetra {
namespace windows {

typedef hwnd_implements message_target_implements;
///////////////////////////////////////////////////////////////////////
///  Class: message_targett
///////////////////////////////////////////////////////////////////////
template <class TImplements = message_target_implements>
class _EXPORT_CLASS message_targett: virtual public message_target_implements {
public:
    typedef message_target_implements Implements;

    virtual LRESULT on_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        switch(msg) {
#endif // _FENETRA_WINDOWS_MESSAGE_TARGET_HPP 

           case WM_NCCREATE:
                lResult = on_WM_NCCREATE_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCDESTROY:
                lResult = on_WM_NCDESTROY_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_CREATE:
                lResult = on_WM_CREATE_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_DESTROY:
                lResult = on_WM_DESTROY_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_PAINT:
                lResult = on_WM_PAINT_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_PAINTICON:
                lResult = on_WM_PAINTICON_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_ERASEBKGND:
                lResult = on_WM_ERASEBKGND_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_ICONERASEBKGND:
                lResult = on_WM_ICONERASEBKGND_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_SHOWWINDOW:
                lResult = on_WM_SHOWWINDOW_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_CLOSE:
                lResult = on_WM_CLOSE_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_MOVE:
                lResult = on_WM_MOVE_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_SIZE:
                lResult = on_WM_SIZE_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_ACTIVATE:
                lResult = on_WM_ACTIVATE_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_ENABLE:
                lResult = on_WM_ENABLE_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_SETFOCUS:
                lResult = on_WM_SETFOCUS_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_KILLFOCUS:
                lResult = on_WM_KILLFOCUS_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_QUERYOPEN:
                lResult = on_WM_QUERYOPEN_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_COMMAND:
                lResult = on_WM_COMMAND_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_QUIT:
                lResult = on_WM_QUIT_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NOTIFY:
                lResult = on_WM_NOTIFY_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_PARENTNOTIFY:
                lResult = on_WM_PARENTNOTIFY_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_DROPFILES:
                lResult = on_WM_DROPFILES_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_QUERYDRAGICON:
                lResult = on_WM_QUERYDRAGICON_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCPAINT:
                lResult = on_WM_NCPAINT_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCACTIVATE:
                lResult = on_WM_NCACTIVATE_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCCALCSIZE:
                lResult = on_WM_NCCALCSIZE_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCHITTEST:
                lResult = on_WM_NCHITTEST_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_MOUSEMOVE:
                lResult = on_WM_MOUSEMOVE_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_MOUSEHOVER:
                lResult = on_WM_MOUSEHOVER_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_MOUSELEAVE:
                lResult = on_WM_MOUSELEAVE_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_LBUTTONDOWN:
                lResult = on_WM_LBUTTONDOWN_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_LBUTTONUP:
                lResult = on_WM_LBUTTONUP_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_LBUTTONDBLCLK:
                lResult = on_WM_LBUTTONDBLCLK_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_RBUTTONDOWN:
                lResult = on_WM_RBUTTONDOWN_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_RBUTTONUP:
                lResult = on_WM_RBUTTONUP_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_RBUTTONDBLCLK:
                lResult = on_WM_RBUTTONDBLCLK_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_MBUTTONDOWN:
                lResult = on_WM_MBUTTONDOWN_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_MBUTTONUP:
                lResult = on_WM_MBUTTONUP_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_MBUTTONDBLCLK:
                lResult = on_WM_MBUTTONDBLCLK_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_XBUTTONDOWN:
                lResult = on_WM_XBUTTONDOWN_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_XBUTTONUP:
                lResult = on_WM_XBUTTONUP_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_XBUTTONDBLCLK:
                lResult = on_WM_XBUTTONDBLCLK_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_MOUSEWHEEL:
                lResult = on_WM_MOUSEWHEEL_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCMOUSEMOVE:
                lResult = on_WM_NCMOUSEMOVE_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCMOUSEHOVER:
                lResult = on_WM_NCMOUSEHOVER_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCMOUSELEAVE:
                lResult = on_WM_NCMOUSELEAVE_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCLBUTTONDOWN:
                lResult = on_WM_NCLBUTTONDOWN_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCLBUTTONUP:
                lResult = on_WM_NCLBUTTONUP_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCLBUTTONDBLCLK:
                lResult = on_WM_NCLBUTTONDBLCLK_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCRBUTTONDOWN:
                lResult = on_WM_NCRBUTTONDOWN_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCRBUTTONUP:
                lResult = on_WM_NCRBUTTONUP_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCRBUTTONDBLCLK:
                lResult = on_WM_NCRBUTTONDBLCLK_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCMBUTTONDOWN:
                lResult = on_WM_NCMBUTTONDOWN_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCMBUTTONUP:
                lResult = on_WM_NCMBUTTONUP_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCMBUTTONDBLCLK:
                lResult = on_WM_NCMBUTTONDBLCLK_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCXBUTTONDOWN:
                lResult = on_WM_NCXBUTTONDOWN_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCXBUTTONUP:
                lResult = on_WM_NCXBUTTONUP_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_NCXBUTTONDBLCLK:
                lResult = on_WM_NCXBUTTONDBLCLK_message
                (hWnd, msg, wParam, lParam);
                break;

           case WM_USER:
                lResult = on_WM_USER_message
                (hWnd, msg, wParam, lParam);
                break;

           default:
                lResult = on_message_default
                (hWnd, msg, wParam, lParam);
                break;

#ifndef _FENETRA_WINDOWS_MESSAGE_TARGET_HPP
        }
        return lResult;
    }
};

} // namespace windows 
} // namespace fenetra 

#endif // _FENETRA_WINDOWS_MESSAGE_TARGET_HPP 
