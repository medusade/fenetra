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
///   File: message_target.hpp
///
/// Author: $author$
///   Date: 6/13/2016
///////////////////////////////////////////////////////////////////////
#ifndef _FENETRA_WINDOWS_MESSAGE_TARGET_HPP
#define _FENETRA_WINDOWS_MESSAGE_TARGET_HPP

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
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
#include "fenetra/windows/message_target_members.hpp"
    virtual LRESULT on_message
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        switch(msg) {
#include "fenetra/windows/message_target_cases.hpp"
        }
        return lResult;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static LRESULT CALLBACK WindowProc
    (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        LRESULT lResult = 0;
        message_targett* window;

        if (!(window = (message_targett*)(GetWindowLongPtr(hWnd, GWL_USERDATA)))) {
            if ((WM_NCCREATE == (msg))) {
                CREATESTRUCT* cs;
                if ((cs = (CREATESTRUCT*)(lParam))) {
                    if ((window = (message_targett*)(cs->lpCreateParams))) {
                        if (!(window->attached_to())) window->attach(hWnd);
                        if (!(window->attached_to_instance())) window->attach_instance(cs->hInstance);
                        SetWindowLongPtr(hWnd, GWL_USERDATA, (LONG_PTR)(window));
                    }
                }
            }
        }
        if ((window)) {
            lResult = window->on_message(hWnd, msg, wParam, lParam);
        } else {
            lResult = ::DefWindowProc(hWnd, msg, wParam, lParam);
        }
        return lResult;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef message_targett<> message_target;

} // namespace windows 
} // namespace fenetra 

#endif // _FENETRA_WINDOWS_MESSAGE_TARGET_HPP 
