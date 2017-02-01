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
///   File: message_target_members.hpp
///
/// Author: $author$
///   Date: 6/13/2016
///////////////////////////////////////////////////////////////////////
#ifndef _FENETRA_GUI_WINDOWS_MESSAGE_TARGET_HPP

#include "fenetra/gui/windows/hwnd.hpp"

namespace fenetra {
namespace gui {
namespace windows {

typedef hwnd_implements message_target_implements;
///////////////////////////////////////////////////////////////////////
///  Class: message_targett
///////////////////////////////////////////////////////////////////////
template <class TImplements = message_target_implements>
class _EXPORT_CLASS message_targett: virtual public message_target_implements {
public:
    typedef message_target_implements Implements;
#endif // _FENETRA_GUI_WINDOWS_MESSAGE_TARGET_HPP 

    virtual LRESULT on_WM_NCCREATE_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCDESTROY_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_CREATE_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_DESTROY_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_PAINT_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_PAINTICON_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_ERASEBKGND_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_ICONERASEBKGND_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_SHOWWINDOW_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_CLOSE_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_MOVE_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_SIZE_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_ACTIVATE_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_ENABLE_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_SETFOCUS_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_KILLFOCUS_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_QUERYOPEN_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_COMMAND_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_QUIT_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NOTIFY_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_PARENTNOTIFY_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_DROPFILES_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_QUERYDRAGICON_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCPAINT_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCACTIVATE_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCCALCSIZE_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCHITTEST_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_MOUSEMOVE_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_MOUSEHOVER_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_MOUSELEAVE_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_LBUTTONDOWN_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_LBUTTONUP_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_LBUTTONDBLCLK_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_RBUTTONDOWN_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_RBUTTONUP_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_RBUTTONDBLCLK_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_MBUTTONDOWN_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_MBUTTONUP_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_MBUTTONDBLCLK_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_XBUTTONDOWN_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_XBUTTONUP_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_XBUTTONDBLCLK_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_MOUSEWHEEL_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCMOUSEMOVE_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCMOUSEHOVER_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCMOUSELEAVE_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCLBUTTONDOWN_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCLBUTTONUP_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCLBUTTONDBLCLK_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCRBUTTONDOWN_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCRBUTTONUP_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCRBUTTONDBLCLK_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCMBUTTONDOWN_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCMBUTTONUP_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCMBUTTONDBLCLK_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCXBUTTONDOWN_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCXBUTTONUP_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_NCXBUTTONDBLCLK_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }
    virtual LRESULT on_WM_USER_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = on_message_default(hWnd,msg,wParam,lParam);
        return lResult;
    }

    virtual LRESULT on_message_default
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = DefWindowProc(hWnd,msg,wParam,lParam);
        return lResult;
    }

    virtual LRESULT DefWindowProc
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        lResult = ::DefWindowProc(hWnd,msg,wParam,lParam);
        return lResult;
    }

#ifndef _FENETRA_GUI_WINDOWS_MESSAGE_TARGET_HPP
};

} // namespace windows
} // namespace gui
} // namespace fenetra 

#endif // _FENETRA_GUI_WINDOWS_MESSAGE_TARGET_HPP 
